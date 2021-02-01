#include "student.h"

Student::Student(std::string _name, int _ID)
{
	name = _name;
	ID = _ID;
}

Student* Student::getNext()
{
	return next;
}

void Student::setNext(Student* _next)
{
	next = _next;
}

int Student::getID()
{
	return ID;
}

std::string Student::getName()
{
	return name;
}

LinkedCourse& Student::getCourseLinked()
{
	return ll;
}

std::vector<Course>& Student::getCourseVect()
{
	return vect;
}

bool Student::remove(int index, bool isArr)
{
	if (isArr)
	{
		if (index < 0 || index >= vect.size()) return false;
		vect.erase(vect.begin() + index);
	}
	else
	{
		if (index < 0 || index >= ll.getSize()) return false;
		ll.remove(index);
	}
	return true;
}