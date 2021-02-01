#include "LinkedStudent.h"

LinkedStudent::LinkedStudent()
{
	head = nullptr;
}

uint32_t LinkedStudent::getNextID()
{
	return ++ID;
}

void LinkedStudent::insert(Student *student)
{
	if (getSize() == 0)
	{
		head = student;
		return;
	}
	search(getSize() - 1)->setNext(student);
}

bool LinkedStudent::remove(int pos)
{
	if (pos < 0 || pos >= getSize()) return false;
	//first
	Student* temp = search(pos);
	if (pos == 0)
	{
		head = search(pos + 1);
		delete temp;
		return true;
	}
	
	if (pos - 1 > 0)
	{
		//middle
		if (pos != getSize() - 1)
			search(pos - 1)->setNext(search(pos + 1));
		else
			search(pos - 1)->setNext(nullptr);
	}
	delete temp;
	return true;
}

Student* LinkedStudent::search(int pos)
{
	if (head == nullptr) return nullptr;
	Student* current = head;
	int i = 0;
	while (current != nullptr)
	{
		if (i == pos) return current;
		current = current->getNext();
		i++;
	}
	return nullptr;
}

int LinkedStudent::getSize()
{
	if (head == nullptr) return 0;
	Student* current = head;
	int i = 0;
	while (current != nullptr)
	{
		current = current->getNext();
		i++;
	}
	return i;
}