#include <iostream>
#include <string>
#include <map>

void ShowAll(std::map<std::string, std::string>& phoneBook) {
    for (auto item : phoneBook) {
        std::cout << item.first << " : " << item.second << "\n";
    }
}