#pragma once
#include <stdexcept>
#include <vector>
#include "RepoExc.h"
#include "Tutorial.h"
#include <fstream>
#include <string>

using namespace std;

class Repo
{

private:
	vector<Tutorial> elem;
	string fileName;

public:
	Repo();
	Repo(const string& fileName);
	//Repo(const Repo<type>& other);
	~Repo();
	void addElement(Tutorial e);
	void removeElement(int position);
	int GetLen() const;
	int GetCap() const;
	//bool findElement(type e) const;
	bool empty() const;
	Tutorial& operator[](int position);
	//Repo<type>& operator=(const Repo<type>& other);
	vector<Tutorial> ListAll() const;

private:
	void readFile();
	void writeFile();

};

