#include <iostream>
#include <string>
#include <map>

void ShowAll(std::map<std::string, std::vector<int>>& classJournal) {
    for (auto item : classJournal) {
        std::cout << item.first << " : ";
        for (int i = 0; i < item.second.size(); i++) {
            std::cout << item.second[i] << " ";
        }
        std::cout << "\n";
    }
}

// TODO. Completely rebuild function, because it is BADCODE
void ShowOne(std::map<std::string, std::vector<int>>& classJournal) {
    for (auto item : classJournal) {
        std::cout << item.first << " : ";
        for (int i = 0; i < item.second.size(); i++) {
            std::cout << item.second[i] << " ";
        }
    }
}