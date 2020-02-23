#include "bloomFilter.hpp"
#include <iostream>
#include <fstream>

bloomFilter::bloomFilter(std::vector<std::string> lines) {
   for(std::string line: lines) {
        this->storeLine(line);
   }
}

int bloomFilter::getHashKey(std::string const& line) {
    int char_sum = 0;
    for (char const& c: line) {
        char_sum += c;
    }
    return char_sum % TABLE_SIZE;
}

void bloomFilter::insertKeyWithLinearProbing(int key) {
    while(this->hash_table[key]) {
        if(key < TABLE_SIZE-1)
            key++;
        else
            key = 0;
    }
    this->hash_table[key] = true;
}

void bloomFilter::storeLine(std::string const& line) {
    int hash_key = this->getHashKey(line);
    this->insertKeyWithLinearProbing(hash_key);
}

bool bloomFilter::isInTable(std::string const& line) {
    int hash_key = this->getHashKey(line);
    return this->hash_table[hash_key];
}
