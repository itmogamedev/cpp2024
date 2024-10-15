#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Student {
	public:	
		int id;
		string name;
		double avgGrade;
		string specialty;
		
		Student() {
			id = 0;
			name = specialty = "";
			avgGrade = 0;
		}
		Student(int id, string name, double avgGrade, string specialty) {
			this->id = id;
			this->name = name;
			this->avgGrade = avgGrade;
			this->specialty = specialty;
		}

		void GetInfo() {
			cout << id << ".\t" << name << "\t" << avgGrade << "\t" << specialty << "\n";
		}

};

bool run = true;
const int maxListSize = 100;
vector <Student> studentsList;
vector <Student> studentsFilter;
int idToFind;
string nameToFind;
double avgGradeToFind;
string specialtyToFind;

void GetInfoAll() {
	for (Student st : studentsList)
	{
		st.GetInfo();
	}
}

void GetInfoFiltered() {
	for (Student st : studentsFilter)
	{
		st.GetInfo();
	}
}

int FindIndexById() {
	int index;
	auto result = find_if(studentsList.begin(), studentsList.end(), [](const Student & st) {
		return st.id == idToFind;
	});
	if (result == studentsList.end()) index = -1;
	else index = result - studentsList.begin();
	return index;
}

void FindAllById() {
	copy_if(studentsList.begin(), studentsList.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.id == idToFind;
	});		
}

void FindAllByName() {
	copy_if(studentsList.begin(), studentsList.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.name == nameToFind;
	});
}

void FindAllByAvgGrade() {
	copy_if(studentsList.begin(), studentsList.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.avgGrade == avgGradeToFind;
	});
}

void FindAllBySpecialty() {
	copy_if(studentsList.begin(), studentsList.end(), back_inserter(studentsFilter), [](const Student& st) {
		return st.specialty == specialtyToFind;
		});
}

int main()
{
	studentsList.push_back(Student(111, "Ivanov Ivan Ivanovich", 4.5, "Gamedev"));
	studentsList.push_back(Student(222, "Fedorov Fedor Fedorovich", 4.5, "Design"));
	studentsList.push_back(Student(333, "Petrov Petr Petrovich", 4.5, "Math"));
	studentsList.push_back(Student(228, "Dolboeb", 4.5, "Gamedev"));
	
	while (run) {
		int option;
		Select:
		cout << "\nITMO students database\nSelect the option:\n";
		cout << "1 - Add a new student to the database\n2 - Print all\n3 - Find a student by criteria\n4 - Delete a student by ID\n";
		cin >> option;
		switch (option)
		{
		case 1:
			//
			break;
		case 2:
			cout << "\nThe list of all students: \n";
			GetInfoAll();
			cout << endl;
			break;
		case 3:
			FindSelect:
			int criteria;
			cout << "Select criteria to find a student:\n";
			cout << "1 - ID\n2 - Name\n3 - Average Grade\n4 - Specialty\n";
			cin >> criteria;
			switch (criteria)
			{
				case 1:					
					cout << "Enter student's id for searching: ";
					cin >> idToFind;
					FindAllById();
					break;
				case 2:
					cout << "Enter student's name for searching: ";
					cin >> nameToFind;
					FindAllByName();
					break;
				case 3:
					cout << "Enter student's average grade for searching: ";
					cin >> avgGradeToFind;
					FindAllByAvgGrade();
					break;
				case 4:
					cout << "Enter student's specialty for searching: ";
					cin >> specialtyToFind;
					FindAllBySpecialty();
					break;
				default:
					cout << "There is no such a criteria. Please, select again.\n";
					goto FindSelect;
			}
			if (!studentsFilter.empty()) GetInfoFiltered();
			else cout << "There are no students by this criteria.\n";
			studentsFilter.clear();
			break;
		case 4:
			cout << "Enter the ID of a student you want to delete: ";
			cin >> idToFind;
			if (FindIndexById() >= 0) {
				studentsList.erase(studentsList.begin() + FindIndexById());				
				cout << "Student by this ID was deleted.\n";
			}
			else cout << "Student with this ID doesn't exist.\n";
			break;
		default:
			cout << "There is no such an option. Please, select again.\n";
			goto Select;
		}
	}
}








