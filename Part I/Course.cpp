#include "Course.h"

Course::Course(std::string _name, float _credit, char _grade, int _ID)
{
	name = _name;
	credit = _credit;
	grade = _grade;
	ID = _ID;
}

Course* Course::getNext()
{
	return next;
}

void Course::setNext(Course* _next)
{
	next = _next;
}

int Course::getID()
{
	return ID;
}

std::string Course::getName()
{
	return name;
}

float Course::getCredit()
{
	return credit;
}

char Course::getGrade()
{
	return grade;
}