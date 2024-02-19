#pragma once
#include "Tutorial.h"
#include "Repo.h"
#include "FileWatchList.h"
#include "TutorialVal.h"
class Service
{

private:
	Repo repo;
	FileWatchList* tutorial_list;
	TutorialVal val;

public:

	Service(const Repo& repo, FileWatchList* tutorial_list, TutorialVal val);
	FileWatchList* getList() const { return tutorial_list; }
	//Service(const Service& other);
	~Service();
	void addTutorial(string const& title, string const& name, string const& duration, int likes, string const& link);
	void removeTutorial(string const& title, string const& name);
	void updateTutorial(string const& title, string const& name, string const& new_duration, int  new_likes, string const& new_link);
	//void addToList(string const& title, string const& name);
	void addToList(const Tutorial& t);
	void startWatch();
	void nextTutorial();
	void SaveTutoList();
	void openTutoList();
	//void deleteFromList(string const& title, string const& name);
	//Service& operator=(const Service& other);
	vector<Tutorial>  ListAll() const;
	//vector<Tutorial> ListTutorialList() const;
	vector<Tutorial> Filter(string const& name);
	void addStartTutorials();
	void updateLikes(string const& title, string const& name);

	Tutorial findTutorial(const string& title, const string& name) const;


};
