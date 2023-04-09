#pragma once

#include <string>
#include <map>

void Insert(std::map<std::string, std::string>& phoneBook, std::string phone, std::string name) {
    phoneBook.insert(std::pair<std::string, std::string>(phone, name));
}

void UpdateName(std::map<std::string, std::string>& phoneBook, std::string phone, std::string name) {
    if (phoneBook.find(phone) != phoneBook.end()) {
        phoneBook[phone] = name;
    }
}

void UpdatePhone(std::map<std::string, std::string>& phoneBook, std::string phone, std::string newPhone) {
    if (phoneBook.find(phone) != phoneBook.end()) {
        std::string tempName = phoneBook[phone];
        phoneBook.erase(phone);
        phoneBook[newPhone] = tempName;
    }
}

void Delete(std::map<std::string, std::string>& phoneBook, std::string phone) {
    phoneBook.erase(phone);
}

std::string FindByPhone(std::map<std::string, std::string>& phoneBook, std::string phone) {
    if (phoneBook.find(phone) != phoneBook.end()) {
        return phoneBook[phone];
    }
    else {
        return "Phone not found";
    }
    
}

std::map<std::string, std::string> FindByName(std::map<std::string, std::string>& phoneBook, std::string name) {
    std::map<std::string, std::string> result;

    for (auto item : phoneBook) {
        if (item.second == name) {
            result.insert(item);
        }
    }

    return result;
}