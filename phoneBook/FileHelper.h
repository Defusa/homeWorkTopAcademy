#pragma once

#include <fstream>
#include <string>
#include <map>

// <phone>|<name>

std::map<std::string, std::string> ImportFromFile(std::string path) {
    std::map<std::string, std::string> result;

    std::ifstream file;
    file.open(path);

    std::string line;
    while (getline(file, line)) {
        int position = line.find('|');
        std::string phone = line.substr(0, position);
        std::string name = line.substr(position + 1);

        result.insert(std::pair<std::string, std::string>(phone, name));
    }

    file.close();

    return result;
}

void ExportToFile(std::string path, std::map<std::string, std::string>& phoneBook) {
    std::ofstream file;
    file.open(path);

    for (auto item : phoneBook) {
        file << item.first << "|" << item.second << "\n";
    }

    file.close();
}
