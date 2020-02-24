#include "bloomFilter.hpp"
#include <iostream>
#include <fstream>

// this constructor takes in a vector of strings
bloomFilter::bloomFilter(std::vector<std::string> lines) {
    // for each line passed in, store it in the hash table
    for(std::string line: lines) {
         this->storeLine(line);
    }
}

//this function takes a line and computes a hash value for it
int bloomFilter::getHashKey(std::string const& line) {

    //add all the characters in the string together
    int char_sum = 0;
    for (char const& c: line) {
        char_sum += c;
    }

    //return the sum modulus with the table size
    return char_sum % TABLE_SIZE;
}

//this function takes a hash key and inserts it without collision
void bloomFilter::insertKeyWithLinearProbing(int key) {
    // while the hash table spot for the key is occupied
    while(this->hash_table[key]) {
        //move to the next spot
        if(key < TABLE_SIZE-1)
            key++;
        else //unless we are at the end of the array, in which case wrap around
            key = 0;
    }

    //set the key value in the table
    this->hash_table[key] = true;
}

//this function stores a line into the hash table
void bloomFilter::storeLine(std::string const& line) {
    //get the hash key for the input string
    int hash_key = this->getHashKey(line);
    //insert the key into the table with linear probing for collision mitigation
    this->insertKeyWithLinearProbing(hash_key);
}

//this function checks if a given string is in the table
bool bloomFilter::isInTable(std::string const& line) {
    //hash the value and return if it is present or not
    int hash_key = this->getHashKey(line);
    return this->hash_table[hash_key];
}
