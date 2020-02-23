#ifndef DIC_READER_HPP
#define DIC_READER_HPP
#include <string>
#include <vector>

class dicReader {
    private:
        std::string filename;
        std::vector<std::string> readDict();
    public:
        dicReader();
        dicReader(std::string const&);
        std::vector<std::string> getDictLines();
};

#endif
