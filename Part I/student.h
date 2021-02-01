#pragma once
#include <iostream>
#include <vector>
#include "LinkedCourse.h"
#include "Course.h"

class Student
{
	Student *next;

	std::string name;
	int ID;

	std::vector<Course> vect;
	LinkedCourse ll;
public:
	Student(std::string name, int ID);
	Student* getNext();
	void setNext(Student* next);
	int getID();
	std::string getName();
	LinkedCourse& getCourseLinked();
	std::vector<Course>& getCourseVect();
	bool remove(int index, bool isArr);
};