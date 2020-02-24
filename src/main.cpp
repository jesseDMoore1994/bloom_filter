#include "dicReader.hpp"
#include "bloomFilter.hpp"
#include <iostream>

int main() {
    bloomFilter bf = bloomFilter(dicReader().getDictLines());
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

    std::string user_input;
    std::cout << "Enter new password: ";
    std::cin >> user_input;
    user_input = clean_string(user_input);
    if(dirty_string_detected) {
        std::cout << "Your string was dirty, cleaned to \"" << user_input << "\".\n";
        dirty_string_detected = false;
    }

    bool new_passwd_is_in_table = bf.isInTable(user_input);

    while (new_passwd_is_in_table) {
        std::cout << "The password you entered is unacceptable, enter new password: ";
        std::cin >> user_input;
        user_input = clean_string(user_input);
        if(dirty_string_detected) {
            std::cout << "Your string was dirty, cleaned to \"" << user_input << "\".\n";
            dirty_string_detected = false;
        }
        new_passwd_is_in_table = bf.isInTable(user_input);
    }

    std::cout << "Your password has been changed.\n";
}
