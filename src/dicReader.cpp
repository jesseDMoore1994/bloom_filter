#include "dicReader.hpp"
#include <iostream>
#include <fstream>

//default constructor assigns filename to dictionary.txt
dicReader::dicReader() {this->filename = "dictionary.txt";}

//this constructor set filename to a user secified string
dicReader::dicReader(std::string const& name): filename(name) {}

//this function reads in the dictionary file
std::vector<std::string> dicReader::readDict() {
    std::ifstream dic(this->filename.c_str());
    std::vector<std::string> lines;

    //if the dictionary cannot be opened, write an error and exit
    if(!dic) {
        std::cerr << "Cannot open file: " << this->filename << "\n";
        std::cerr << "Be sure to place " << this->filename << " in current working directory.\n";
        exit(1);
    }

    //read in the dictionary file line by line, excluding blanks
    std::string tmp;
    while(std::getline(dic, tmp)) {
        if(tmp.size() > 0)
            lines.push_back(tmp);
    }

    //close the dictionary and return the lines in the file
    dic.close();
    return lines;
}

std::vector<std::string> dicReader::getDictLines() {
    //get the list of strings from the dictionary
    std::vector<std::string> sus_strings = this->readDict();
    //define a vector to store clean strings after processing for illigal characters
    std::vector<std::string> clean_strings = std::vector<std::string>();

    //this lambda function cleans potentially dirty strings, sets a variable if cleaning takes place
    bool dirty_str_detected = false;
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

    //clean each string from the dictionary
    for(std::string sus_str: sus_strings) {
        clean_strings.push_back(clean_string(sus_str));
    }

    //if there was a dirty string, warn the user
    if(dirty_str_detected)
        std::cout << "Detected at least one dirty string, input was cleaned.\n";

    //return the cleaned strings
    return clean_strings;
}
