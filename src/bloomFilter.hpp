#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP
#include <string>
#include <vector>
#define TABLE_SIZE 13

class bloomFilter {
    private:
        bool hash_table[TABLE_SIZE] = {};
        int getHashKey(std::string const&);
        void storeLine(std::string const&);
        void insertKeyWithLinearProbing(int);
    public:
        bloomFilter(std::vector<std::string>);
        bool isInTable(std::string const&);
};

#endif
