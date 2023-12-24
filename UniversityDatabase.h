#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "MyVector.h"
#include "Student.h"
#include "Faculty.h"
class UniversityDatabase {
private:
	MyVector<Person*> people;

public:
	void addPerson(Person* person) {
		people.push_back(person);
	}

	Person* findPersonById(int id) const {
		for (int i = 0; i < people.getSize(); i++) {
			if (people.retrieveInfoAtIndex(i)->getID() == id) {
				return people.retrieveInfoAtIndex(i);
			}
		}
		return nullptr;
	}

	Student* findStudentById(int id) const {
		for (int i = 0; i < people.getSize(); i++) {
			Student* student = static_cast<Student*>(people.retrieveInfoAtIndex(i));
			if (student && student->getID() == id) {
				return student;
			}
		}
		return nullptr;
	}

	Faculty* findFacultyById(int id) const {
		for (int i = 0; i < people.getSize(); i++) {
			Faculty* faculty = static_cast<Faculty*>(people.retrieveInfoAtIndex(i));
			if (faculty && faculty->getID() == id) {
				return faculty;
			}
		}
		return nullptr;
	}

	void displayAllPeopleInfo() const {
		for (int i = 0; i < people.getSize(); i++) {
			Student* displayInfo();
			
		}

		for (int j = 0; j < people.getSize(); j++) {
			Faculty* displayInfo();

		}

	}
};
#endif