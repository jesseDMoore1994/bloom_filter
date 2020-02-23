#include "dicReader.hpp"
#include "bloomFilter.hpp"
#include <iostream>

int main() {
    bloomFilter bf = bloomFilter(dicReader().getDictLines());

    std::string user_input;
    std::cout << "Enter new password: ";
    std::cin >> user_input;

    bool new_passwd_is_in_table = bf.isInTable(user_input);

    while (new_passwd_is_in_table) {
        std::cout << "The password you entered is unacceptable, enter new password: ";
        std::cin >> user_input;
        new_passwd_is_in_table = bf.isInTable(user_input);
    }

    std::cout << "Your password has been changed.\n";
}
