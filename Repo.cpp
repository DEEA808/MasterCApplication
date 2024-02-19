#include "Repo.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Repo::Repo() = default;

Repo::Repo(const string& fileName)
{
	this->fileName = fileName;
	this->readFile();
}


Repo::~Repo() = default;

void Repo::addElement(Tutorial t)
{
	this->elem.push_back(t);
	this->writeFile();
}

void Repo::removeElement(int position)
{
	int i = 0;
	for (auto it = 0; it < this->elem.size(); it++) {
		if (it != position)
			i++;
	}
	i--;
	this->elem.erase(next(this->elem.begin()+i));
}

int Repo::GetLen() const
{
	return this->elem.size();
}

int Repo::GetCap() const
{
	return this->elem.capacity();
}

bool Repo::empty() const
{
	return this->elem.empty();
}

vector<Tutorial> Repo::ListAll() const
{
	vector<Tutorial> iter;

	for (auto it = this->elem.begin(); it != this->elem.end(); it++)
		iter.push_back(*it);
	return iter;
}

void Repo::readFile()
{
	ifstream file(this->fileName);

	if (!file.is_open()) {

		throw FileExc("The file could not be opened!");
	}


	Tutorial t;
	while (file >> t)
		this->elem.push_back(t);

	file.close();
}

void Repo::writeFile()
{
	ofstream file(this->fileName);
	if (!file.is_open())
		throw FileExc("The file could not be opened!");
	Tutorial t;
	for (auto t : this->elem)
	{
		file << t << endl;
	}

	file.close();
}

Tutorial& Repo::operator[](int position)
{
	return this->elem[position];
}