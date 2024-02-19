#pragma once
#include "FileWatchList.h"

class HTML :public FileWatchList
{
public:
	HTML(const string& fileName) :FileWatchList(fileName) {};
	~HTML() {};
	void writeFile() override;
	//void displayTutorial() override;
};

