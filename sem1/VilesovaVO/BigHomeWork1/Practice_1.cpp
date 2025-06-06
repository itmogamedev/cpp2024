#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

class Student {
	public:	
		int id;
		std::string surname;
		std::string name;
		std::string patr;
		double avgGrade;
		std::string specialization;
		
		Student() {		
			
		}
		Student(int id, std::string surname, std::string name, std::string patr, double avgGrade, std::string specialization) {
			this->id = id;
			this->surname = surname;
			this->name = name;
			this->patr = patr;
			this->avgGrade = avgGrade;
			this->specialization = specialization;
		}

		void GetInfo() {
			std::cout << "ID: " << id << "\nSurname: " << surname << "\nName:  " << name << "\nPatronymic: " << patr << "\nAverage grade : " << avgGrade << "\nSpecialty : " << specialization << std::endl;
		}

};

std::string path = "DBStudents.txt";
bool active = true;
std::vector <Student> DBStudents;
std::vector <Student> studentsFilter;
int idToFind;
std::string patrToFind;
std::string nameToFind;
std::string surnameToFind;
double avgGradeToFind;
std::string specializationToFind;

int newId;
std::string newSurname;
std::string newName;
std::string newPatr;
double newAvgGrade;
std::string newSpecialization;

void WriteToFile() {
	std::ofstream out;
	out.open(path);
	if (out.is_open()) {
		std::string str;
		for (Student st : DBStudents)
		{
			out << st.id << " " << st.surname << " " << st.name << " " << st.patr << " " << st.avgGrade << " " << st.specialization << "\n";
		}
	}
	out.close();
}

void ReadFromFile() {
	std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::string str;
		std::string strSplit[6];
		for (int i = 0; getline(in, str); i++)
		{
			std::stringstream s(str);
			int j = 0;
			while (s.good() && j < 6) {
				s >> strSplit[j];
				j++;
			}
			DBStudents.push_back(Student(stoi(strSplit[0]), strSplit[1], strSplit[2], strSplit[3], stod(strSplit[4]), strSplit[5]));

		}
	}
	in.close();
}

void GetInfoFiltered() {
	for (Student st : studentsFilter)
	{
		st.GetInfo();
	}
}

void GetInfoAll() {
	for (Student st : DBStudents)
	{
		st.GetInfo();
	}
}

int FIndById() {
	int index;
	auto result = find_if(DBStudents.begin(), DBStudents.end(), [](const Student & st) {
		return st.id == idToFind;
	});
	if (result == DBStudents.end()) index = -1;
	else index = result - DBStudents.begin();
	return index;
}

void FAllById() {
	copy_if(DBStudents.begin(), DBStudents.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.id == idToFind;
	});		
}

void FAllBySN() {
	copy_if(DBStudents.begin(), DBStudents.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.surname == surnameToFind;
		});
}

void FAllByN() {
	copy_if(DBStudents.begin(), DBStudents.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.name == nameToFind;
	});
}

void FAllByPatr() {
	copy_if(DBStudents.begin(), DBStudents.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.patr == patrToFind;
		});
}

void FAllByAGrade() {
	copy_if(DBStudents.begin(), DBStudents.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.avgGrade == avgGradeToFind;
	});
}

void FindAllBySpecialization() {
	copy_if(DBStudents.begin(), DBStudents.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.specialization == specializationToFind;
		});
}

int main()
{
	ReadFromFile();
	
	while (active) {
		int option;
		Select:
		std::cout << "\nITMO students database\nSelect the option:\n";
		std::cout << "1 - Add a new student to the database\n2 - Print all\n3 - Find a student by criteria\n4 - Delete a student by ID\n5 - Exit\n";
		std::cin >> option;
		switch (option)
		{
		case 1:
		StudentCreate:			
			std::cout << "Enter new student's ID: ";
			std::cin >> idToFind;
			if (FIndById() > -1) {
				cout << "Student with this ID already exists.\n";
				goto StudentCreate;
			}
			else newId = idToFind;
			std::cout << "Enter new student's surname: ";
			std::cin.ignore();
			std::getline(cin, newSurname);
			std::cout << "Enter new student's name: ";
			std::cin.ignore();
			std::getline(cin, newName);
			std::cout << "Enter new student's patronymic: ";
			std::cin.ignore();
			std::getline(cin, newPatr);
			std::cout << "Enter new student's average grade: ";
			std::cin >> newAvgGrade;
			std::cout << "Enter new student's specialty: ";
			std::cin.ignore();
			std::getline(cin, newSpecialization);
			DBStudents.push_back(Student(newId, newSurname, newName, newPatr, newAvgGrade, newSpecialization));
			WriteToFile();
			break;
		case 2:
			std::cout << "\nThe list of all students: \n";
			GetInfoAll();
			std::cout << std::endl;
			break;
		case 3:
			FindSelect:
			int crit;
			std::cout << "Select crit to find:\n";
			std::cout << "1 - ID\n2 - Surname\n3 - Name\n4 - Patronymic\n5 - Average Grade\n6 - Specialty\n7 - Go back\n";
			std::cin >> crit;
			switch (crit)
			{
				case 1:					
					std::cout << "Enter id for searching: ";
					std::cin >> idToFind;
					FAllById();
					break;
				case 2:										
					std::cout << "Enter surname for searching: ";
					std::cin.ignore();
					std::getline(cin, surnameToFind);
					FAllBySN();
					break;
				case 3:
					std::cout << "Enter name for searching: ";
					std::cin.ignore();
					std::getline(cin, nameToFind);
					FAllByN();
					break;
				case 4:
					std::cout << "Enter patronymic for searching: ";
					std::cin.ignore();
					std::getline(cin, patrToFind);
					FAllByPatr();
					break;
				case 5:
					std::cout << "Enter average grade for searching: ";
					std::cin >> avgGradeToFind;
					FAllByAGrade();
					break;
				case 6:
					std::cout << "Enter specialty for searching: ";
					std::cin.ignore();
					std::getline(cin, specializationToFind);
					FindAllBySpecialization();
					break;
					break;
				case 7:
					goto Select;
					break;
				default:
					std::cout << "There is no such a crit. Select again.\n";
					goto FindSelect;
			}
			if (!studentsFilter.empty()) GetInfoFiltered();
			else std::cout << "There are no students by this crit.\n";
			studentsFilter.clear();
			break;
		case 4:
			std::cout << "Enter the ID you want to delete: ";
			std::cin >> idToFind;
			if (FIndById() >= 0) {
				DBStudents.erase(DBStudents.begin() + FIndById());
				std::cout << "ID was deleted.\n";
				WriteToFile();
			}
			else std::cout << "ID doesn't exist.\n";
			break;
		case 5:
			active = 0;
			break;
		default:
			std::cout << "There is no such an option. Select again.\n";
			goto Select;
		}
	}
}








