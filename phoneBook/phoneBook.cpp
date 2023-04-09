#include "FileHelper.h"
#include "ConsoleHelper.h"
#include "PhoneBook.h"


int main() {
    auto phoneBook = ImportFromFile("D:/git/homeWorkTopAcademy/phoneBook/export.psv");
    //ShowAll(phoneBook);
    //std::cout << " --- \n by Phone " << "\n";

    //std::string result = FindByPhone(phoneBook, "8-954-888-25-71");
    //std::cout << result << " --- \n by Phone " << "\n";

    //FindByPhone(phoneBook, "8-800-555-35-35");
    //std::cout << " --- \n by Phone" << "\n";

    //FindByPhone(phoneBook, "aasdadsasd");
    //std::cout << " --- \n by name: " << "\n";

    std::map<std::string, std::string> result = FindByName(phoneBook, "Petrov");
    ShowAll(result);

    //ShowAll(phoneBook);
    //std::cout << " --- " << "\n";


    return 0;
}
