#include "Scoreboard.h"
#include <iostream>
#include <regex>
#include <string>
using namespace std;

Scoreboard::Scoreboard() : score(0) {
	try {
		getFromFile();
	}
	catch (const char* msg) {
		cout << msg << endl;
		setBestScoreAndBestPlayerNameDefault();
	}
};

void Scoreboard::setBestScoreAndBestPlayerNameDefault() {
	this->bestScore = 0;
	this->bestPlayer = "Unknown";
	cout << "Best score: " << this->bestScore << endl << "Best player: " << this->bestPlayer << endl;
}

void Scoreboard::ifMatches(smatch strMatch, bool isName, bool& found) {
	if (isName == true) {
		this->bestPlayer = strMatch.str();
		found = true;
	}
	else {
		this->bestScore = stoi(strMatch.str());
		found = true;
	}
}

void Scoreboard::matches(string str, regex pattern, bool isName) {
	sregex_iterator match(str.begin(), str.end(), pattern);
	sregex_iterator lastMatch;
	bool found = false;
	while (match != lastMatch && found == false) {
		smatch strMatch = *match;
		ifMatches(strMatch, isName, found);
		match++;
	}
	if (found == false) {
		throw("\nSomething is wrong with input file.\n");
	}
}

void Scoreboard::ifBestScoreAndBestPlayerNameGood(string textLine) {
	regex regName("[A-Za-z]{2,13}");
	regex reg("(\\d){1,3}");
	try {
		matches(textLine, reg, false);
		matches(textLine, regName, true);
	}
	catch (const char* msg) {
		cout << msg << endl;
		setBestScoreAndBestPlayerNameDefault();
	}
}

void Scoreboard::getFromFile() {
	string b;
	ifstream file("score.txt");
	if (file.is_open())
	{
		if (file.peek() == EOF)
			throw("\nFile is empty.\n");
		else {
			getline(file, b);
			ifBestScoreAndBestPlayerNameGood(b);
			file.close();
		}
	}
	else
		throw("\nFile can't be open.\n");
}

void Scoreboard::saveEndFile(fstream& file) {
	file.open("score.txt", ios::_Nocreate || ios::in);
	if (!file.good()) {
		throw ("\nFile does not exists.\n");
	}
	fstream file1;
	file1.open("score.txt", ios::out);
	if (file1.good() == true)
	{
		file1 << this->score << " " << this->name;
		file1.close();
	}
	else
		throw ("\nFile can't be open.\n");
}

void Scoreboard::writeToFile() {
	if (this->score > this->bestScore) {
		try {
			fstream file;
			saveEndFile(file);
		}
		catch (const char* msg) {
			cout << msg << endl;
			fstream file;
			file.open("score.txt", ios::app);
			file << this->score << " " << this->name;
		}
	}
};

void Scoreboard::matchUserName(string _name, bool& goodName) {
	regex regName("[A-Za-z]{2,13}");
	smatch match;
	regex_search(_name, match, regName);
	if (match.empty()) {
		throw("\nWrong name! Try again.\n");
	}
	for (auto _name : match) {
		if (_name.length() != 0) {
			goodName = true;
			setName(_name);
			break;
		}
	}
}

void Scoreboard::setName(string _name) {
	this->name = _name;
	cout << "\nYour name: " << _name << endl;
};

void Scoreboard::setBestScore(int x) {
	this->bestScore = x;
};

string Scoreboard::getName() {
	return this->name;
};

int Scoreboard::getScore() {
	return this->score;
};

string Scoreboard::getBestPlayerName() {
	return this->bestPlayer;
};

int Scoreboard::getBestScore() {
	return this->bestScore;
};

void Scoreboard::addPoint() {
	this->score = this->score + 1;
};