#include <iostream>
#include "UniversityDatabase.h"
#include "Student.h"
#include "Faculty.h"

int main() {
    UniversityDatabase universityDatabase;

    int id = 122;
    std::string firstName, lastName;
    std::string department;

    while (true) {
        std::cout << "\nUniversity Database Menu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Faculty Member\n";
        std::cout << "3. Add Grades for a Student\n";
        std::cout << "4. Add Courses for a Faculty Member\n";
        std::cout << "5. Add Contact Info for a Person\n";
        std::cout << "6. Display All People\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        id++;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {

            firstName = "fName" + std::to_string(id);
            lastName = "lName" + std::to_string(id);


            // Create a new student and add it to the database
            Student* student = new Student(firstName, lastName, id);
            universityDatabase.addPerson(student);
            break;
        }
        case 2: {

            firstName = "fName" + std::to_string(id);
            firstName = "lName" + std::to_string(id);
            department = "dep" + std::to_string(id);

            // Create a new faculty member and add it to the database
            Faculty* faculty = new Faculty(firstName, lastName, id, department);
            universityDatabase.addPerson(faculty);
            break;
        }
        case 3: {
            // Add grades for a student
            int studentId;
            std::cout << "Enter student's ID: ";
            std::cin >> studentId;

            // Find the student in the database
            Student* student = static_cast<Student*>(universityDatabase.findStudentById(studentId));
            if (student) {
                // Create grades
                std::string course1 = "CSCI373";
                char course1grade = 'A';
                std::string course2 = "CSCI272";
                char course2grade = 'B';

                // Add grades for the student
                student->addGrade(course1, course1grade);
                student->addGrade(course2, course2grade);
                std::cout << "Grades added for the student.\n";
            }
            else {
                std::cout << "Student not found.\n";
            }
            break;
        }
        case 4: {
            // Add courses for a faculty member
            int facultyId;
            std::cout << "Enter faculty member's ID: ";
            std::cin >> facultyId;

            // Find the faculty member in the database
            Faculty* faculty = static_cast<Faculty*>(universityDatabase.findFacultyById(facultyId));
            if (faculty) {
                // Create Courses
                std::string course1Id = "CS373";
                std::string course1Desc = "Data Structures";
                std::string course2Id = "CS272";
                std::string course2Desc = "OOP";
                // Add courses for the faculty member
                faculty->addCourse(course1Id, course1Desc);
                faculty->addCourse(course2Id, course2Desc);
                std::cout << "Courses added for the faculty member.\n";
            }
            else {
                std::cout << "Faculty member not found.\n";
            }
            break;
        }
        case 5: {
            // Add contact info for a person
            int personId;
            std::cout << "Enter person's ID: ";
            std::cin >> personId;

            // Find the person in the database
            Person* person = universityDatabase.findPersonById(personId);
            if (person) {

                // Create contact info
                std::string phoneKey = "Phone";
                std::string phoneNumber = "+1 929 783";
                std::string emailKey = "email";
                std::string emailAddress = "email@jjay.cuny.edu";

                // Add contact info for the person
                person->addContactInfo(phoneKey, phoneNumber);
                person->addContactInfo(emailKey, emailAddress);
                std::cout << "Contact info added for the person.\n";
            }
            else {
                std::cout << "Person not found.\n";
            }
            break;
        }
        case 6:
            // Display information for all people in the database
            universityDatabase.displayAllPeopleInfo();
            break;
        case 7:
            // Exit the program
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}