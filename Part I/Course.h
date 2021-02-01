#pragma once
#include <iostream>

//record
class Course
{
	Course *next;

	int ID;
	std::string name; // kurskod
	float credit; // h�gskolepo�ng
	char grade; // betyg

public:
	Course(std::string name, float Credit, char Grade, int ID);
	Course* getNext();
	void setNext(Course* next);
	int getID();
	std::string getName();
	float getCredit();
	char getGrade();
};