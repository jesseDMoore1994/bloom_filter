#include "dicReader.hpp"
#include <iostream>
#include <fstream>

dicReader::dicReader() {this->filename = "dictionary.txt";}

dicReader::dicReader(std::string const& name): filename(name) {}

std::vector<std::string> dicReader::readDict() {
    std::ifstream dic(this->filename.c_str());
    std::vector<std::string> lines;

    if(!dic) {
        std::cerr << "Cannot open file: " << this->filename << "\n";
        std::cerr << "Be sure to place " << this->filename << " in current working directory.\n";
        exit(1);
    }

    std::string tmp;
    while(std::getline(dic, tmp)) {
        if(tmp.size() > 0)
            lines.push_back(tmp);
    }

    dic.close();
    return lines;
}

std::vector<std::string> dicReader::getDictLines() {
    bool dirty_str_detected = false;
    std::vector<std::string> sus_strings = this->readDict();
    std::vector<std::string> clean_strings = std::vector<std::string>();

    auto clean_string = [&dirty_str_detected](std::string dirty_string) {
        std::string clean_string = "";
        for (char const& c: dirty_string) {
            if(c >= 'A' && c <= 'Z')
                clean_string += c;
            else
                dirty_str_detected = true;
        }
        return clean_string;
    };

    for(std::string sus_str: sus_strings) {
        clean_strings.push_back(clean_string(sus_str));
    }

    if(dirty_str_detected)
        std::cout << "Detected at least one dirty string, input was cleaned.\n";

    return clean_strings;
}
