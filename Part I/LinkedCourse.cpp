#include "LinkedCourse.h"

LinkedCourse::LinkedCourse()
{
	head = nullptr;
}

uint32_t LinkedCourse::getNextID()
{
	return ++ID;
}

void LinkedCourse::insert(Course *course)
{
	if (getSize() == 0)
	{
		head = course;
		return;
	}
	search(getSize() - 1)->setNext(course);
}

bool LinkedCourse::remove(int pos)
{
	if (pos < 0 || pos >= getSize()) return false;
	//first
	Course* temp = search(pos);
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
		//last
		else
			search(pos - 1)->setNext(nullptr);
	}
	delete temp;
	return true;
}

Course* LinkedCourse::search(int pos)
{
	if (head == nullptr) return nullptr;
	Course* current = head;
	int i = 0;
	while (current != nullptr)
	{
		if (i == pos) return current;
		current = current->getNext();
		i++;
	}
	return nullptr;
}

int LinkedCourse::getSize()
{
	if (head == nullptr) return 0;
	Course* current = head;
	int i = 0;
	while (current != nullptr)
	{
		current = current->getNext();
		i++;
	}
	return i;
}