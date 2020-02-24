#ifndef DIC_READER_HPP
#define DIC_READER_HPP
#include <string>
#include <vector>

class dicReader {
    private:
        //filename for dictionary
        std::string filename;
        //function to read all the lines from the dictionary
        std::vector<std::string> readDict();
    public:
        //constructors
        dicReader();
        dicReader(std::string const&);

        //return all the lines from the dictionary
        std::vector<std::string> getDictLines();
};

#endif
