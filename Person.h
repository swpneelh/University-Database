#ifndef PERSON_H
#define PERSON_H

#include "MyVector.h"
#include "Pair.h"
#include <iostream>

class Person {
private:
	MyVector<Pair<std::string, std::string>> contactInfo;
	std::string firstName;
	std::string lastName;
	int id;

public:
	
	Person(const std::string& first, const std::string& last, int id): firstName(first), lastName(last), id(id) {}

	virtual ~Person() {}

	virtual void displayInfo() const {
		std::cout << "First Name: " << firstName << "Last Name: " << lastName << "ID: " << id << std::endl;
	}

	virtual std::string getRole() const = 0;

	std::string getFullName() const {
		std::string fullName = firstName + " " + lastName;
		
		return fullName;
	}

	int getID() const {
		return id;
	}

	void addContactInfo(const std::string& key, const std::string& value) {
		contactInfo.push_back(Pair<std::string, std::string>(key, value));
	}

	void updateContactInfo(const MyVector<Pair<std::string, std::string>>& newInfo) {
		contactInfo = newInfo;
	}

	void displayContactInfo() const{
		for (int i = 0; i < contactInfo.getSize(); i++) {
			Pair<std::string, std::string> info = contactInfo.retrieveInfoAtIndex(i);
			std::cout << info.first << ": " << info.second << std::endl;
		}
	}
};

#endif
