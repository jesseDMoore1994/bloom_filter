#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP
#include <string>
#include <vector>
#define TABLE_SIZE 13

class bloomFilter {
    private:
        //define a hash table
        bool hash_table[TABLE_SIZE] = {};
        //function to get a hash key from a string
        int getHashKey(std::string const&);
        //function to read in a line to the hash table
        void storeLine(std::string const&);
        //function to insert a key into the table using linear probing 
        void insertKeyWithLinearProbing(int);
    public:
        //constructor
        bloomFilter(std::vector<std::string>);
        //function to check if a string is in the table
        bool isInTable(std::string const&);
};

#endif
