#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
// очень большая домашка прям жесть капецблин страшно увага опасность
 class student{
 public:
	std::string name, surname, patronymic, speciality, id, score;
	student(std::string id, std::string name, std::string surname, std::string patronymic,std::string score, std::string speciality) {
		 this->id = id;
		 this->name = name;
		 this->surname = surname;
		 this->patronymic = patronymic;
		 this->score = score;
		 this->speciality = speciality;

	 };

};
 //функция проверки критерия
	 bool isRight(std::string toSplit, std::string criteria) {
		 int prev = 0;// вспомогательная чтоб вести отсчёт слов
		 for (int i = 0; i < toSplit.length(); i++) {
			 if (toSplit[i] == ' ') {
				 if (toSplit.substr(prev, i - prev) == criteria) {
					 return 1;
				 }
				 else {
					 prev = i + 1;
				 }
			 }
		 }
		 if ((toSplit.substr(prev, toSplit.length()) == criteria)) {
			 return 1;
		 }
		 else {
			 return 0;
		 }

	 }
//функция количества слов в строке
	 int countWords(std::string ToCount) {
		 int counter = 0;
		 for (int i = 0; i < ToCount.length(); i++) {

			 if (ToCount[i] == ' ') {
				 counter++;
			 };
		 };
		 counter++;
		 return counter;
	 };
	 class dataBase {
	 private:

	 public:
		 void add() {
			 std::cin.ignore();
			 std::string name, surname, patronymic, speciality, id, score;
			 std::cout << "you've desided to add a student to a database, if you don't want anymore type 'quit' whenever possible" << '\n';
			 std::cout << "input new student id:" << '\n';
			 std::cin.clear();
			 std::cin >> id;
			 if (id == "quit") {
				 return;
			 }
			 std::string line;
			 //проверяем нет ли совпадающего id
			 std::ifstream in("database.txt");
			 if (in.is_open())
			 {
				 while (std::getline(in, line)) {
					 std::getline(in, line);
					 if (line.substr(0,line.find(" "))==id) {
						 while (line.substr(0, line.find(" ")) == id) {
							 std::cout << "this id already exists, choose another one" << '\n';
							 std::cin >> id;
							 if (id == "quit") {	 
								 return;
							 }
						 }
					 }
				 }
			 }in.close();

			 std::cout << '\n';
			 std::cout << "input his/her/thier/zier name:" << '\n';
			 std::cin >> name;
			 std::cout << '\n';
			 if (name == "quit") {
				 return;
			 }
			 std::cout << "input surname:" << '\n';
			 std::cin >> surname;
			 std::cout << '\n';
			 if (surname == "quit") {
				 return;
			 }
			 std::cout << "input patronymic:" << '\n';
			 std::cin >> patronymic;
			 std::cout << '\n';
			 if (patronymic == "quit") {
				 return;
			 }
			 std::cout << "input the average score:" << '\n';
			 std::cin >> score;
			 std::cout << '\n';
			 if (score == "quit") {
				 return;
			 }
			 std::cout << "input speciality:" << '\n';
			 std::cin >> speciality;
			 std::cout << '\n';
			 if (speciality == "quit") {
				 return;
			 }
			 student newStudent(id, name, surname, patronymic, score, speciality);
			 std::ofstream out;
			 out.open("database.txt", std::ios::app);
			 if (out.is_open()) {
				 out << newStudent.id << " " << newStudent.surname << " " << newStudent.name << " " << newStudent.patronymic << " " << newStudent.speciality << " " << newStudent.score << '\n';
				 std::cout << "student "<< newStudent.surname << " " << newStudent.name << " " << newStudent.patronymic <<" succesfully added!" << '\n';
			 }
			 out.close();
		 };
		 void allInfo() {
			 std::string line;
			 std::ifstream in("database.txt");
			 if (in.is_open())
			 {
				 while (std::getline(in, line))
				 {
					 std::cout << line << '\n';
				 }
			 }
			 in.close();
		 }
		 void deleteStudent() {
			 std::cout << "input the id to delete( or 'quit' to stop deleting)" << '\n';
			 std::string targetID;
			 getline(std::cin, targetID);
			 if (targetID == "quit") {
				 return;
			 }
			 std::string line;
			 int IDcount=0;
			 int outputcount = 0;
			 std::ifstream in("database.txt");
			 std::ofstream out;
			 out.open("temporary.txt", std::ios::app);
			 while (std::getline(in, line)){
				 IDcount++;
				 if (line.substr(0,line.find(" "))!=targetID){
				 outputcount++;
				 out << line<<'\n';
				 bool IDnotFound = 0;
				 }
				 else {
				 }
			 }
			 out.close();
			 in.close();
			 if (IDcount==outputcount) {
				 std::cout << "no such id in the database"<<'\n';
				 std::remove("temporary.txt");
			 }
			 else {
				 std::cout << "the student "<<targetID<<" successfully deleted"<<'\n';
				 char oldname[] = "temporary.txt";
				 char newname[] = "database.txt";
				 std::remove("database.txt");
				 std::rename("temporary.txt", "database.txt");
			 }
			 
		 }
		 void search() {
			 std::cout << "input desired characteristics(up to 6) or input 'quit' to stop the search" << '\n';
			 std::string criteria;
			 std::cin.clear();
			 std::getline(std::cin, criteria);
			 if (criteria == "quit") {
				 return;
			 }
			 if (countWords(criteria) > 6 or (countWords(criteria)-1) == criteria.length()) {// если больше 6 характ. или введены одни пробелы
				 while (countWords(criteria) > 6 or (countWords(criteria)-1) == criteria.length()) {
					 std::cout << "invalid input, try again or input 'quit' to stop the search" << '\n';
					 // почему то здесь cin ignore  не нужен
					 getline(std::cin, criteria);
					 if (criteria == "quit") {
						 return;
					 }
				 }
			 }
			 int prev = 0;//ну да третий раз тот же код, ну не хочет c++ массив символов через функцию возвращать
			 int ind = 0;
			 std::string criteriaList[6] = { " " ," " ," " ," " ," " ," " };
			 for (int i = 0; i < criteria.length(); i++) {
				 if (criteria[i] == ' ') {
					 criteriaList[ind] = criteria.substr(prev, i - prev);
					 prev = i + 1;
					 ind++;
				 }
			 }criteriaList[ind] = criteria.substr(prev, criteria.length());
			 std::string line;
			 std::ifstream in("database.txt");
			 if (in.is_open()) {
				 std::cout << "results:" << '\n';
				 bool flagtoNothing = 1;//на случай если ничего не найдётся
				 bool flagtoEverything = 1;// проверка на совпадение всех параметров
				 std::string line;
				 while (std::getline(in, line)) {
					 for (int i = 0; i < 6; i++) {
						 bool a = criteriaList[i] != " ";
						 if (i == 0)
							 //std::cout << "in cycle i=" << isRight(line, criteriaList[i]) << a << criteriaList[i]<< '\n';
							 if (not(isRight(line, criteriaList[i])) and criteriaList[i] != " ") {// проверяем что подходит под параметр и не является " "
								 flagtoEverything = 0;
								 break;
							 }
					 }
					 if (flagtoEverything) {
						 std::cout << line << '\n';
						 flagtoNothing = 0;
					 }
				 }
				 if (flagtoNothing) {
					 std::cout << "None" << '\n';

				 };
			 };
			 in.close();
		 };
	 };
		 int main() {
			 dataBase db;
			 while (1) {
				 std::cout << '\n';
				 std::cout << "choose an option:" 
					 << '\n' << "add student" 
					 << '\n' << "delete student" 
					 << '\n' << "find student" 
					 << '\n' << "see whole database" 
				     << '\n'<<"P.S. you can always type 'quit' to stop current process(typing 'quit' now will close the programm)" << '\n';
				 std::string useroption;
				 getline(std::cin,useroption);
				 //std::cin.clear();
				 //std::cin.ignore();
				 //std::cin.sync();
				 if (useroption=="add student" or useroption=="add") {//(чёртов switch не ест string, костыли наше всё)
					 db.add();
				 }
				 else if (useroption=="delete student" or useroption=="delete"){
					 db.deleteStudent();
				 }
				 else if (useroption=="find student" or useroption=="find"){
					 db.search();
				 }
				 else if (useroption=="see whole database" or useroption=="see"){
					 db.allInfo();
				 }
				 else if (useroption == "quit") {
					 exit(0);
				 }
				 else{
					 std::cout << "unknown command, please try again" << '\n';
				 }
				 };
			 return 0;
		 };
			 