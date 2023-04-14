#pragma once

#include <fstream>
#include <string>
#include <map>
#include <vector>


// <name>|<marks>

std::map<std::string, std::vector<int>> ImportFromFile(std::string path) {
    std::map<std::string, std::vector<int>> result;

    std::ifstream file;
    file.open(path);

    std::string line;
    while (getline(file, line)) {
        std::vector<int> marks;
        int position = line.find('-');
        std::string studentName = line.substr(0, position);
        std::string marksLine = line.substr(position + 1);

        size_t pos = 0;
        while (pos < marksLine.size()) {
            size_t commaPos = marksLine.find(",", pos);
            if (commaPos == std::string::npos) {
                commaPos = marksLine.length();
            }
            std::string numberString = marksLine.substr(pos, commaPos - pos);
            int number = std::stoi(numberString);
            marks.push_back(number);
            pos = commaPos + 1;
        }

        result.insert(std::pair<std::string, std::vector<int>>(studentName, marks));
    }

    file.close();

    return result;
}

void ExportToFile(std::string path, std::map<std::string, std::vector<int>>& classJournal) {
    std::ofstream file;
    file.open(path);

    for (auto item : classJournal) {
        file << item.first << "-";
        for (int i = 0; i < item.second.size() - 1; i++) {
            file << item.second[i] << ",";
        }
        file << item.second[item.second.size() - 1];
        file << "\n";
    }

    file.close();
}
