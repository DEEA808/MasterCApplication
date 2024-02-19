#include "WatchList.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "Tutorial.h"
using namespace std;
WatchList::WatchList()
{
	this->current = 0;
}

void WatchList::addTutorial(const Tutorial& t)
{
	this->tutorials.push_back(t);
}

void WatchList::deleteTutorial(int p)
{

	int i = 0;
	for (auto it = 0; it < this->tutorials.size(); it++) {
		if (it != p)
			i++;
	}
	i--;
	this->tutorials.erase(this->tutorials.begin() + i);
}

int WatchList::GetLnegth() const
{
	return int(this->tutorials.size());
}

Tutorial& WatchList::operator[](int p)
{
	return this->tutorials[p];
}

Tutorial WatchList::GetCurrent()
{
	if (this->current == this->tutorials.size())
		this->current = 0;
	return this->tutorials[this->current];
	return Tutorial{};
}

void WatchList::playy()
{
	if (this->tutorials.size() == 0)
		return;
	this->current = 0;
	Tutorial currentT = this->GetCurrent();
	//currentT.play();
}

void WatchList::next()
{
	if (this->tutorials.size() == 0)
		return;
	this->current++;
	Tutorial currentT = this->GetCurrent();
	//currentT.play();
}

bool WatchList::empty()
{
	return int(this->tutorials.size()) == 0;
}