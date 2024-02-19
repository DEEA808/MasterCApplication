#include "RepoExc.h"

FileExc::FileExc(const std::string& msg) : message(msg)
{
}

const char* FileExc::what()
{
	return message.c_str();
}

RepoExc::RepoExc() : exception{}, message{ "" }
{
}

RepoExc::RepoExc(const std::string& msg) : message{ msg }
{
}

const char* RepoExc::what()
{
	return this->message.c_str();
}

const char* DuplicateSongException::what()
{
	return "There is another tutorial with the same title and name!";
}

const char* InexistenSongException::what()
{
	return "There are no tutorials with the given title and name!";
}
