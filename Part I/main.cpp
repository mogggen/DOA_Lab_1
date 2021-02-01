#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include "student.h"
#include "LinkedStudent.h"





void ReadID(std::string topic, int& ID)
{
	std::cout << topic + " ID: ";
	std::cin >> ID;
}

//topic
void TopicName(std::string topic, std::string &name)
{
	std::cout << topic + " name: ";
	std::cin >> name;
}

void TopicName(std::string topic, float &credit)
{
	std::cout << "Course " + topic + ": ";
	std::cin >> credit;
}

void TopicName(std::string topic, char &grade)
{
	std::cout << "Course " + topic + ": ";
	std::cin >> grade;
}



// add student
void AddStudent_vect(std::vector<Student>& vect, std::string& name, uint32_t& globalstudID)
{
	vect.push_back(Student(name, ++globalstudID));
}

void AddStudent_linked(LinkedStudent& linked, std::string& name)
{
	linked.insert(new Student(name, linked.getNextID()));
}


//delete student
void DeleteStudent_vect(std::vector<Student>& vect, int& studID)
{
	int i = 0;
	bool found = false;
	for (; i < vect.size(); i++)
	{
		if (vect[i].getID() == studID)
		{
			found = true;
			break;
		}
	}
	if (!found)
		std::cout << "Student ID was not found.";
	else
	vect.erase(vect.begin() + i);
}

void DeleteStudent_linked(LinkedStudent& linked, int& studID)
{
	int i = 0;
	bool found = false;
	for (; i < linked.getSize(); i++)
	{
		if (linked.search(i)->getID() == studID)
		{
			found = true;
			break;
		}
	}
	if (!found)
		std::cout << "Student ID was not found.";
	else
		linked.remove(i);
}


//add Course to student
void AddCourse_vect(std::vector<Student>& vect, int& studID, std::string& courseName, float& courseCredit, char& courseGrade, uint32_t& globalcourID)
{
	int i = 0;
	bool foundStud = false;

	for (; i < vect.size(); i++)
	{
		if (vect[i].getID() == studID)
		{
			foundStud = true;
			Course temp = Course(courseName, courseCredit, courseGrade, ++globalcourID);
			vect[i].getCourseVect().push_back(temp);

			// setNext() is called so that when the ~Course
			// is called and the delete operation runs
			// it removes this instead of trying to remove nullptr 
			// because that throws an error. So this is a 'dummyCourse'
			temp.setNext(new Course("", 0.0f, '0', 0));
			break;
		}
	}
	if (!foundStud) std::cout << "This student ID was not found in the record." << std::endl;
}

void AddCourse_linked(LinkedStudent& linked, int& studID, std::string& courseName, float& courseCredit, char& courseGrade)
{
	int i = 0;
	bool foundStud = false;

	for (; i < linked.getSize(); i++)
	{
		if (linked.search(i)->getID() == studID)
		{
			foundStud = true;
			linked.search(i)->getCourseLinked().insert(new Course(courseName, courseCredit, courseGrade, linked.search(i)->getCourseLinked().getNextID()));
		}
	}
	if (!foundStud) std::cout << "This student ID was not found in the record." << std::endl;
}


//delete Course from student
void DeleteCourse_vect(std::vector<Student>& vect, int& studID, int&courID)
{
	bool foundStud = false;
	bool foundCour = false;
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i].getID() == studID)
		{
			foundStud = true;
			for (int j = 0; j < vect[i].getCourseVect().size(); j++)
				if (vect[i].getCourseVect()[j].getID() == courID)
				{
					foundCour = true;
					vect[i].getCourseVect().erase(vect[i].getCourseVect().begin() + j);
					return;
				}
			if (!foundCour)
				std::cout << "Course ID: no match found";
			break;
		}
	}
	if (!foundStud)
			std::cout << "Student ID was not found.";

}

void DeleteCourse_linked(LinkedStudent& linked, int& studID, int&courID)
{
	bool foundStud = false;
	bool foundCour = false;
	for (int i = 0; i < linked.getSize(); i++)
	{
		if (linked.search(i)->getID() == studID)
		{
			for (int j = 0; j < linked.search(i)->getCourseLinked().getSize(); j++)
			{
				if (linked.search(i)->getCourseLinked().search(j)->getID() == courID)
				{
					linked.search(i)->getCourseLinked().remove(j);
					return;
				}
			}
			if (!foundCour)
				std::cout << "Course ID: no match found";
			break;
		}
	}
	if (!foundStud)
		std::cout << "Student ID was not found.";
}


// print all
void PrintAll_vect(std::vector<Student>& vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << "\nStudent\nID: " << vect[i].getID();
		std::cout << "\nName: " << vect[i].getName() << std::endl;
		for (int j = 0; j < vect[i].getCourseVect().size(); j++)
		{
			std::cout << "\nCourse\n\n\tID: " << vect[i].getCourseVect()[j].getID() << std::endl;
			std::cout << "\tName: " << vect[i].getCourseVect()[j].getName() << std::endl;
			std::cout << "\tCredit: " << vect[i].getCourseVect()[j].getCredit() << std::endl;
			std::cout << "\tGrade: " << vect[i].getCourseVect()[j].getGrade() << std::endl;
		}
	}
}

void PrintAll_linked(LinkedStudent& linked)
{
	for (int i = 0; i < linked.getSize(); i++)
	{
		std::cout << "\nStudent\nID: " << linked.search(i)->getID();
		std::cout << "\nName: " << linked.search(i)->getName() << std::endl;
		for (int j = 0; j < linked.search(i)->getCourseLinked().getSize(); j++)
		{
			std::cout << "\nCourse\n\n\tID: " << linked.search(i)->getCourseLinked().search(j)->getID() << std::endl;
			std::cout << "\tName: " << linked.search(i)->getCourseLinked().search(j)->getName() << std::endl;
			std::cout << "\tCredit: " << linked.search(i)->getCourseLinked().search(j)->getCredit() << std::endl;
			std::cout << "\tGrade: " << linked.search(i)->getCourseLinked().search(j)->getGrade() << std::endl;
		}
	}
}



//Complexity
long long Cost_vect(int _case, std::vector<Student>& vect, uint32_t& globalstudID, uint32_t& globalcourID)
{
	std::cout << "\n-vector List------------------" << std::endl;
	int studID;
	int courID;

	std::string name;
	float credit;
	char grade;

	// the reason for the second switch
	// case is to not time the user input
	// as part of the operations complexity
	switch (_case)
	{
	case 1:
		TopicName("Student", name);
		break;

	case 2:
		ReadID("Student", studID);
		break;

	case 3:
		ReadID("Student", studID);
		TopicName("Course", name);
		TopicName("Credit", credit);
		TopicName("Grade", grade);
		break;

	case 4:
		ReadID("Student", studID);
		ReadID("Course", courID);
		break;
	}

	bool case7 = false;
	auto a1 = std::chrono::high_resolution_clock().now();
	switch (_case)
	{
	case 1:
		AddStudent_vect(vect, name, globalstudID);
		break;

	case 2:
		DeleteStudent_vect(vect, studID);
		break;

	case 3:
		AddCourse_vect(vect, studID, name, credit, grade, globalcourID);
		break;

	case 4:
		DeleteCourse_vect(vect, studID, courID);
		break;

	case 5:
		PrintAll_vect(vect);
		break;

	default:
		std::cout << "Pick an integer between 1-6." << std::endl;
		break;
	}
	auto a2 = std::chrono::high_resolution_clock().now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(a2 - a1).count();
	std::cout << "\nTime taken for operation: " << duration << " microseconds." << std::endl;
	std::cout << "-END--------------------------" << std::endl;
	return duration;
}

long long Cost_linked(int _case, LinkedStudent& linked)
{
	std::cout << "\n-Linked list------------------" << std::endl;
	int studID;
	int courID;

	std::string name;
	float credit;
	char grade;

	// the reason for the second switch
	// case is to not time the user input
	// as part of the operations complexity
	switch (_case)
	{
	case 1:
		TopicName("Student", name);
		break;

	case 2:
		ReadID("Student", studID);
		break;

	case 3:
		ReadID("Student", studID);
		TopicName("Course", name);
		TopicName("Credit", credit);
		TopicName("Grade", grade);
		break;

	case 4:
		ReadID("Student", studID);
		ReadID("Course", courID);
		break;
	}

	auto a1 = std::chrono::high_resolution_clock().now();
	switch (_case)
	{
	case 1:
		AddStudent_linked(linked, name);
		break;

	case 2:
		DeleteStudent_linked(linked, studID);
		break;

	case 3:
		AddCourse_linked(linked, studID, name, credit, grade);
		break;

	case 4:
		DeleteCourse_linked(linked, studID, courID);
		break;

	case 5:
		PrintAll_linked(linked);
		break;

	default:
		std::cout << "Pick an integer between 1-6." << std::endl;
		break;
	}
	auto a2 = std::chrono::high_resolution_clock().now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(a2 - a1).count();
	std::cout << "\nTime taken for operation: " << duration << " microseconds." << std::endl;
	std::cout << "-END--------------------------" << std::endl;
	return duration;
}



int main()
{
	uint32_t globalcourID = 0, globalstudID = 0;

	int choice;
	bool quit = false;
	long long runningSumLinkedList = 0;
	long long runningSumVector = 0;

	std::vector<Student> vect;
	LinkedStudent linkedList;
	
	while (!quit)
	{
		std::cout
			<< "\n\n"
			<< "1. Add student to record.\n"
			<< "2. Delete student from record.\n"
			<< "3. Add course to student.\n"
			<< "4. Delete course from student.\n"
			<< "5. Print all.\n"
			<< "6. Exit."
			<< "\n\nTime taken for all operation with:\n"
			<< "\n\tvector list: " << runningSumVector << " microseconds."
			<< "\n\tLinked list: " << runningSumLinkedList << " microseconds."
			<< "\n\nChoise: ";
			

		std::cin >> choice;
		if (choice == 6) break;
		else
		{
			runningSumVector += Cost_vect(choice, vect, globalstudID, globalcourID);
			runningSumLinkedList += Cost_linked(choice, linkedList);
		}
	}
	return 0;
}
