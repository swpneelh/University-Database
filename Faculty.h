#ifndef FACULTY_H
#define FACULTY_H

class Faculty : public Person {
private:
	MyVector<Pair<std::string, std::string>> courseInfo;
	std::string department;

public:
	Faculty(const std::string& first, const std::string& last, int id, const std::string& department):
	Person(first, last, id), department(department) {}
	~Faculty(){}

	void displayInfo() const override {
		Person::displayInfo();
		for (int i = 0; i < courseInfo.getSize(); i++) {
			Pair<std::string, std::string> info = courseInfo.retrieveInfoAtIndex(i);
			std::cout << info.first << ": " << info.second << std::endl;
		}
	}

	std::string getRole() const override {
		return "Faculty";
	}

	void addCourse(const std::string& courseID, const std::string& description) {
		courseInfo.push_back(Pair<std::string, std::string>(courseID, description));
	}
};
#endif