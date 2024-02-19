#pragma once
#include "FileWatchList.h"
#include "Tutorial.h"

class CSV :public FileWatchList
{
public:
	CSV(const string& fileName) :FileWatchList(fileName) {};
	~CSV() {};
	void writeFile() override;
	//void displayTutorial() override;

};

