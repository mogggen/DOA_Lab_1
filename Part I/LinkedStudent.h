#pragma once
#include "student.h"

class LinkedStudent
{
	Student *head;
	int ID;
public:
	LinkedStudent();

	uint32_t getNextID();

	void insert(Student *student);

	bool remove(int pos);

	Student *search(int pos);

	int getSize();
};