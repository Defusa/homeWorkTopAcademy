#pragma once

#include <string>
#include <map>
#include <vector>
#include <algorithm>

//std::map<std::string, std::vector<int>> result;


// Works as intended
void Insert(std::map<std::string, std::vector<int>>& classJournal, std::string name, std::vector<int> marks) {  
    classJournal.insert(std::pair<std::string, std::vector<int>>(name, marks));
}

    
// Works as intended
void addMarks(std::map<std::string, std::vector<int>>& classJournal, std::string name, std::vector<int> marks) {
    if (classJournal.find(name) != classJournal.end()) {
        classJournal[name].insert(classJournal[name].end(), marks.begin(), marks.end());
    }
}

// Works as intended
void UpdateName(std::map<std::string, std::vector<int>>& classJournal, std::string name, std::string newName) {
    if (classJournal.find(name) != classJournal.end()) {
        std::vector tmpMarks = classJournal[name];
        classJournal.erase(name);
        classJournal[newName] = tmpMarks;
    }
}

// Works as intended
void Delete(std::map<std::string, std::vector<int>>& classJournal, std::string name) {
    classJournal.erase(name);
}

// Works as intended
std::map<std::string, std::vector<int>> searchByName(std::map<std::string, std::vector<int>>& classJournal, std::string name) {
    std::map<std::string, std::vector<int>> searchResults;
    if (classJournal.find(name) != classJournal.end()) {
        searchResults[name] = classJournal[name];
    }
    else {
        searchResults["Error message"] = { 0 };
    }
    return searchResults;
}


//Chat GPT solution
//Work as intended with risks of getting out of vector range. I think better way is to validate positions before using the function.
//Or we can make very strange function with 
//1) changing values at positions to smth, that cant be our marks. 
//2) rebuild vector and delete out of our range numbers without looking for position
void DeleteStudentMarks(std::map<std::string, std::vector<int>>& classJournal, std::string name, const std::vector<int>& positions) {
    auto it = classJournal.find(name);
    if (it != classJournal.end()) {
        std::vector<int>& marks = it->second;
        std::vector<int> newMarks;
        newMarks.reserve(marks.size() - positions.size());

        int j = 0;
        for (int i = 0; i < marks.size(); ++i) {
            if (j < positions.size() && i == positions[j]) {
                ++j;
            }
            else {
                newMarks.push_back(marks[i]);
            }
        }

        marks = newMarks;
    }
}

