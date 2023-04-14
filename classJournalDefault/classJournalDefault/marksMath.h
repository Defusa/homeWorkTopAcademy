#pragma once

#include <string>
#include <map>
#include <vector>
#include <cmath>

//Works as intended
double averageMark(std::map <std::string, std::vector<int>>& classJournal, std::string studentName) {
	if (classJournal.find(studentName) != classJournal.end()) {
		double sum = 0;
		for (int value : classJournal[studentName]) {
			sum += value;
		}
		return std::round(sum / classJournal[studentName].size() * 100) / 100;
	}
}

