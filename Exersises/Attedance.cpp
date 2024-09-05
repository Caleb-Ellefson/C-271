#include <iostream>
#include <string>

int total_students;
float students_attended;
int students = (total_students - students_attended);
std::string class_name;

//75%

int main (){

	std::cout << "What is the name of the class? " << std::endl;
	std::getline (std::cin, class_name);

	std::cout << "How many studets are here today? " << std::endl;
	std::cin >> students_attended;

	std::cout << "How many students are  enrolled " << std::endl;
	std::cin >> total_students; 

	double percentage = (students_attended / total_students) * 100;

	std::cout << "Hi Prof. Hairi the attendance rate today is %" << percentage << "." << std::endl;
	return 1;
}