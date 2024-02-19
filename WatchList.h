#pragma once
#include <vector>
#include "Tutorial.h"

class WatchList
{
protected:
	vector<Tutorial> tutorials;
	int current;
public:
	WatchList();
	void addTutorial(const Tutorial& t);
	void deleteTutorial(int p);
	int GetLnegth() const;
	Tutorial& operator[](int p);
	Tutorial GetCurrent();
	void playy();
	void next();
	bool empty();
	virtual ~WatchList() {}

};
