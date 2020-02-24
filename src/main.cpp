#include "dicReader.hpp"
#include "bloomFilter.hpp"
#include <iostream>

int main() {
    //define bloom filter object
    bloomFilter bf = bloomFilter(dicReader().getDictLines());

    //define lambda function to clean user input
    bool dirty_string_detected = false;
    auto clean_string = [&dirty_string_detected](std::string dirty_string) {
        std::string clean_string = "";
        for (char const& c: dirty_string) {
            if(c >= 'A' && c <= 'Z')
                clean_string += c;
            else
                dirty_string_detected = true;
        }
        return clean_string;
    };

    //read in user input
    std::string user_input;
    std::cout << "Enter new password: ";
    std::cin >> user_input;

    //clean user input and warn if it was dirty
    user_input = clean_string(user_input);
    if(dirty_string_detected) {
        std::cout << "Your string was dirty, cleaned to \"" << user_input << "\".\n";
        dirty_string_detected = false;
    }

    //check if the user input was in the filter
    bool new_passwd_is_in_table = bf.isInTable(user_input);

    //if the user input was found in the filter, it is invalid 
    while (new_passwd_is_in_table) {
        //prompt user of invalid password and read in another
        std::cout << "The password you entered is unacceptable, enter new password: ";
        std::cin >> user_input;

        //clean user input and warn if it was dirty
        user_input = clean_string(user_input);
        if(dirty_string_detected) {
            std::cout << "Your string was dirty, cleaned to \"" << user_input << "\".\n";
            dirty_string_detected = false;
        }

        //check if the user input was in the filter
        new_passwd_is_in_table = bf.isInTable(user_input);
    }
    
    //if we make it here, the password has been accepted
    std::cout << "Your password has been changed.\n";
}
