#include "Service.h"
#include <exception>
using namespace std;
Service::Service(const Repo& repo, FileWatchList* tutorial_list, TutorialVal val)
{
	this->repo = repo;
	this->tutorial_list = tutorial_list;
	this->val = val;
}

/*Service::Service(const Service& other)
{
	this->repo = other.repo;
}*/

Service::~Service() = default;


Tutorial Service::findTutorial(const string& title, const string& name) const
{
	vector<Tutorial> iter = this->repo.ListAll();
	for (auto t : iter)
	{
		if (t.GetTitle() == title && t.GetName() == name)
			return t;
	}

	throw exception();
}

void Service::addTutorial(string const& title, string const& name, string const& duration, int likes, string const& link)
{
	int found = 0;
	for (int index = 0; index < this->repo.GetLen(); index++)
	{
		Tutorial& tutorial = this->repo[index];
		if (tutorial.GetTitle() == title) {
			if (tutorial.GetName() == name) {
				found = 1;
			}
		}

	}
	if (found == 1)
		throw exception("This totorial already exist!");
	Tutorial t(title, name, duration, likes, link);
	this->val.val(t);
	this->repo.addElement(t);
}

void Service::removeTutorial(string const& title, string const& name)
{
	int found = 0;
	for (int index = 0; index < this->repo.GetLen(); index++)
	{
		Tutorial& tutorial = this->repo[index];
		if (tutorial.GetTitle() == title) {
			if (tutorial.GetName() == name) {
				this->repo.removeElement(index);
				found = 1;
			}
		}

	}
	if (found == 0)
		throw exception("This totorial does not exist!");
}

void Service::updateTutorial(string const& title, string const& name, string const& new_duration, int  new_likes, string const& new_link)
{
	int found = 0;
	for (int index = 0; index < this->repo.GetLen(); index++)
	{
		Tutorial& tutorial = this->repo[index];
		if (tutorial.GetTitle() == title) {
			if (tutorial.GetName() == name) {
				tutorial.SetDuration(new_duration);
				tutorial.SetLikes(new_likes);
				tutorial.SetLink(new_link);
				found = 1;
			}
			this->val.val(tutorial);
		}
	}
	if (found == 0)
		throw exception("This totorial does not exist!");

}


void Service::updateLikes(string const& title, string const& name)
{
	int new_likes;
	for (int index = 0; index < this->repo.GetLen(); index++)
	{
		Tutorial& tutorial = this->repo[index];
		if (tutorial.GetTitle() == title) {
			if (tutorial.GetName() == name) {
				new_likes = tutorial.GetLikes();
				new_likes++;
				tutorial.SetLikes(new_likes);
			}
		}

	}


}
void Service::addToList(const Tutorial& t)
{
	this->tutorial_list->addTutorial(t);
}

void Service::startWatch()
{
	if (this->tutorial_list == nullptr)
		return;
	this->tutorial_list->playy();
}

void Service::nextTutorial()
{
	if (this->tutorial_list == nullptr)
		return;
	this->tutorial_list->next();
}

void Service::SaveTutoList()
{
	if (this->tutorial_list == nullptr)
		return;
	this->tutorial_list->writeFile();
}

void Service::openTutoList()
{
	if (this->tutorial_list == nullptr)
		return;
	//this->tutorial_list->displayTutorial();
}
/*void Service::addToList(string const& title, string const& name)
{
	int found = 0;
	for (int index = 0; index < this->tutorial_list.GetLen(); index++)
	{
		Tutorial& tutorial = this->tutorial_list[index];
		if (tutorial.GetTitle() == title) {
			if (tutorial.GetName() == name) {
				found = 1;
			}
		}

	}
	if (found == 1)
		throw exception("This totorial already exist!");
	found = 0;
	for (int index = 0; index < this->repo.GetLen(); index++)
	{
		Tutorial& tutorial = this->repo[index];
		if (tutorial.GetTitle() == title) {
			if (tutorial.GetName() == name)
			{
				this->tutorial_list.addElement(tutorial);
				found = 1;
			}
		}
	}
	if (found == 0)
	{
		throw exception("This tutorial does not exist!");
	}

}

void Service::deleteFromList(string const& title, string const& name)
{
	int found = 0;
	for (int index = 0; index < this->tutorial_list.GetLen(); index++)
	{
		Tutorial& tutorial = this->tutorial_list[index];
		if (tutorial.GetTitle() == title)
		{
			if (tutorial.GetName() == name)
			{
				found = 1;
				this->tutorial_list.removeElement(index);
			}
		}
	}
	if (found == 0)
		throw exception("This tutorial does not exist!");
}
*/

vector<Tutorial> Service::ListAll() const
{
	return this->repo.ListAll();
}

/*vector<Tutorial> Service::ListTutorialList() const
{
	return this->tutorial_list.ListAll();
}
*/

vector<Tutorial> Service::Filter(string const& name)
{
	vector<Tutorial> filter_list;
	for (int index = 0; index < this->repo.GetLen(); index++)
	{
		Tutorial t = this->repo[index];
		if (t.GetName() == name)
		{
			filter_list.push_back(t);
		}
	}
	return filter_list;
}

/*Service& Service::operator=(const Service& other)
{
	if (this == &other)
		return *this;

	this->repo = other.repo;
	return *this;
}*/

void Service::addStartTutorials()
{
	string l1 = "https://www.youtube.com/watch?v=gXZt4P97UW4";
	this->addTutorial("Java Introduction", "Jakob Jenkov", "13:43", 502, l1);
	string l2 = "https://www.youtube.com/watch?v=0dR-YAFFg6I";
	this->addTutorial("Java HashMap", "Bro code", "13:04", 2000, l2);
	string l3 = "https://www.youtube.com/watch?v=kqtD5dpn9C8";
	this->addTutorial("Python Beginners", "Mosh", "60:05", 27000, l3);
	string l4 = "https://www.youtube.com/watch?v=8yjkWGRlUmY";
	this->addTutorial("Classes", "CS Dojo", "19:50", 28000, l4);
	string l5 = "https://www.youtube.com/watch?v=pgBk8HC7jbU";
	this->addTutorial("Java Constructors", "John", "7:37", 7500, l5);
	string l6 = "https://www.youtube.com/watch?v=7S_tz1z_5bA";
	this->addTutorial("SQL", "Mosh", "60:00", 203000, l6);
	string l7 = "https://www.youtube.com/watch?v=Zp5MuPOtsSY";
	this->addTutorial("Control Flow Python", "Mosh", "16:07", 3800, l7);
	string l8 = "https://www.youtube.com/watch?v=wN0x9eZLix4";
	this->addTutorial("OOP", "CodeCamp", "90:00", 50000, l8);
	string l9 = "https://www.youtube.com/watch?v=zuegQmMdy8M";
	this->addTutorial("Pointers", "CodeCamp", "120:00", 63000, l9);
	string l10 = "https://www.youtube.com/watch?v=XIrOM9oP3pA";
	this->addTutorial("Python AI", "Clever programmer", "120:00", 36000, l10);
}