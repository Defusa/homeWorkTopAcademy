﻿// classJournalDefault.cpp : Defines the entry point for the application.
//

#include "classJournal.h"
#include "fileHelper.h"
#include "consoleHelper.h"
#include "marksMath.h"


int main()
{	
	std::map<std::string, std::vector<int>> result;
	std::vector<int> unitTest = {5,5,5,5,5,4,5};

	result = ImportFromFile("D:/git/homeWorkTopAcademy/classJournalDefault/classJournalDefault/classJournal.csv");
	ShowAll(result);
	
	std::cout << "\n\n\n";

	Insert(result, "Kartasheva", unitTest);
	ShowAll(result);

	std::cout << "\n\n\n";

	addMarks(result, "Goncharov", unitTest);
	ShowAll(result);

	std::cout << "\n\n\n";

	UpdateName(result, "Petrov", "Sidorchuk");
	ShowAll(result);

	std::cout << "\n\n\n";

	Delete(result, "Delete");
	ShowAll(result);

	std::cout << "\n\n\n";

	std::map < std::string, std::vector<int>> searchResult;
	searchResult = searchByName(result, "Kartasheva");
	if (searchResult.count("Error message")) {
		std::cout << "Name not found" << std::endl;
	}
	else {
		ShowAll(searchResult);
	}

	std::cout << "\n\n\n";

	double resultMark;
	resultMark = averageMark(result, "Ivanov");
	std::cout << resultMark;


	std::cout << "\n\n\n";

	std::vector<int> positions = {3,4,7};
	DeleteStudentMarks(result, "Ivanov", positions);
	ShowAll(result);

	std::cout << "\n\n\n";


	searchResult = searchByName(result, "Ivanov");
	ShowOne(searchResult);
	resultMark = averageMark(result, "Ivanov");
	std::cout << "\t Average: " << resultMark;



	ExportToFile("D:/git/homeWorkTopAcademy/classJournalDefault/classJournalDefault/classJournalResult.csv", result);

	return 0;
}
