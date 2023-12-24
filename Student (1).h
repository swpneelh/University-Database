#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
class Student : public Person {
private: 
	MyVector<Pair<std::string, char>> grades;
	

public:
	Student(const std::string& first, const std::string& last,int id):Person(first, last, id){}

	~Student() {}

	void displayInfo() const override{
		Person::displayInfo();
		for (int i = 0; i < grades.getSize(); i++) {
			Pair<std::string, char> grade = grades.retrieveInfoAtIndex(i);
			std::cout << grade.first << ": " << grade.second << std::endl;
		}
	}

	std::string getRole() const override{
		return "Student";
	}

	void addGrade(const std::string& course, char grade) {
		grades.push_back(Pair<std::string, char>(course, grade));
	}

    double getAverageGrade() const {
        if (grades.getSize() == 0) {

            return 0.0;
        }

        double totalGrade = 0.0;
        for (int i = 0; i < grades.getSize(); i++) {
            Pair<std::string, char> grade = grades.retrieveInfoAtIndex(i);

            switch (grade.second) {
            case 'A':
                totalGrade += 4.0;
                break;
            case 'B':
                totalGrade += 3.0;
                break;
            case 'C':
                totalGrade += 2.0;
                break;
            case 'D':
                totalGrade += 1.0;
                break;
            case 'F':
                totalGrade += 0.0;
                break;
            default:
                totalGrade += 0.0;
                break;
            }
        }

        return totalGrade / grades.getSize();
    }



};
#endif 