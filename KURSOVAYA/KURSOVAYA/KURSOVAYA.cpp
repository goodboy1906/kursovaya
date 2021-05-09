#define _CRT_SECURE_NO_WARNINGS
#define FILEPATH "file.txt"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <string>

class Program {
public:
	void print(int a) {
		std::cout << a;
	}
	void print(char a) {
		std::cout << a;
	}
	void print(std::string a) {
		std::cout << a;
	}
};

class Student : Program {
public:
	friend class File;
	Student() {
		surname = new char[31]();
		name = new char[31]();
		middlename = new char[31]();
		faculty = new char[31]();
		department = new char[31]();
		group = new char[31]();
		student_status = new char[31]();
		gender = new char[2]();
		day = new int(0);
		month = new int(0);
		year = new int(0);
		year_entrance = new int(0);
	}
	~Student() {
		delete surname;
		delete name;
		delete middlename;
		delete faculty;
		delete department;
		delete group;
		delete student_status;
		delete gender;
		delete day;
		delete month;
		delete year;
		delete year_entrance;
	}
	void set() {
		set_surname();
		set_name();
		set_middlename();
		set_birth();
		set_gender();
		set_year_entrance();
		set_faculty();
		set_department();
		set_group();
		set_student_status();
	}
	void set_surname() {
		print("Введите фамилию [30] >>> ");
		std::cin >> surname;
		std::cin.clear();
	}
	void set_name() {
		print("Введите имя [30] >>> ");
		std::cin >> name;
		std::cin.clear();
	}
	void set_middlename() {
		print("Введите отчество [30] >>> ");
		std::cin >> middlename;
		std::cin.clear();
	}
	void set_birth() {
		print("Введите дату рождения (dd mm yyyy) >>> ");
		std::cin >> *day;
		std::cin >> *month;
		std::cin >> *year;
		if ((*day > 31) || (*day < 1) || (*month > 12) || (*month < 1) || (*year > 2004) || (*year < 1900)) {
			print("Вы ввели некорректные данные :(\n");
			*day = 0;
			*month = 0;
			*year = 0;
			std::cin.clear();
			set_birth();
		}
		std::cin.clear();
	}
	void set_gender() {
		print("Введите пол [M/F] >>> ");
		std::cin >> gender;
		if (*gender != 'M' && *gender != 'F') {
			print("Существует только два гендера :(\n");
			std::cin.clear();
			set_gender();
		}
		std::cin.clear();
	}
	void set_year_entrance() {
		print("Введите год поступления (yyyy) >>> ");
		std::cin >> *year_entrance;
		if (*year_entrance < *year) {
			print("Год поступления не может быть меньше года рождения!\n");
			*year_entrance = 0;
			std::cin.clear();
			set_year_entrance();
		}
		std::cin.clear();
	}
	void set_faculty() {
		print("Введите факультет [30] >>> ");
		std::cin >> faculty;
		std::cin.clear();
	}
	void set_department() {
		print("Введите кафедру [30] >>> ");
		std::cin >> department;
		std::cin.clear();
	}
	void set_group() {
		print("Введите группу [30] >>> ");
		std::cin >> group;
		std::cin.clear();
	}
	void set_student_status() {
		print("Введите номер зачетной книжки [30] >>> ");
		std::cin >> student_status;
		std::cin.clear();
	}
	void get() {
		for (int i = 0; i < 120; i++) std::cout << "=";
		get_surname();
		get_name();
		get_middlename();
		get_birth();
		get_gender();
		get_year_entrance();
		get_faculty();
		get_department();
		get_group();
		get_student_status();
		for (int i = 0; i < 120; i++) std::cout << "=";
	}
	void get_surname() {
		print("Фамилия: ");
		std::cout << surname << std::endl;
	}
	void get_name() {
		print("Имя: ");
		std::cout << name << std::endl;
	}
	void get_middlename() {
		print("Отчество: ");
		std::cout << middlename << std::endl;
	}
	void get_birth() {
		print("Дата рождения: ");
		std::cout << *day << '.' << *month << '.' << *year << std::endl;
	}
	void get_gender() {
		print("Пол: ");
		std::cout << gender << std::endl;
	}
	void get_year_entrance() {
		print("Год поступления: ");
		std::cout << *year_entrance << std::endl;
	}
	void get_faculty() {
		print("Факультет: ");
		std::cout << faculty << std::endl;
	}
	void get_department() {
		print("Кафедра: ");
		std::cout << department << std::endl;
	}
	void get_group() {
		print("Группа: ");
		std::cout << group << std::endl;
	}
	void get_student_status() {
		print("Номер зачетной книжки: ");
		std::cout << student_status << std::endl;
	}
	
private:
	char* surname = nullptr;
	char* name = nullptr; 
	char* middlename = nullptr;
	char* faculty = nullptr;
	char* department = nullptr;
	char* group = nullptr;
	char* student_status = nullptr;
	char* gender = nullptr;
	int* day = nullptr;
	int* month = nullptr;
	int* year = nullptr;
	int* year_entrance = nullptr;
};

class Session : Program {
public:
	friend class File;
	Session() {
		session_counter = new int;
		subject_counter = new int;
		mark = new int* [9];
		subject = new std::string* [9];
		for (int count = 0; count < 9; count++) {
			mark[count] = new int [10];
		}
		for (int count = 0; count < 9; count++) {
			subject[count] = new std::string [10];
		}
		R = new double;
	}
	~Session() {
		delete session_counter;
		delete subject_counter;
		for (int count = 0; count < 2; count++) {
			delete[]mark[count];
		}
		for (int count = 0; count < 2; count++) {
			delete[]subject[count];
		}
	}
	void set_session_counter() {
		print("Введите количество сессий (2 - 9) >>> ");
		std::cin >> *session_counter;
		if (*session_counter > 9 || *session_counter < 2) {
			print("Введите корректные данные!");
			std::cin.clear();
			set_session_counter();
		}
		std::cin.clear();
	}
	void set_subject_counter() {
		print("Введите количество предметов в ");
		print("сессии (1 - 10) >>> ");
		std::cin >> *subject_counter;
		if (*subject_counter > 10 || *subject_counter < 1) {
			print("Введите корректные данные!");
			std::cin.clear();
			set_subject_counter();
		}
		std::cin.clear();
	}
	void set_subject() {
		for (int count_row = 0; count_row < *session_counter; count_row++) {
			for (int count_column = 0; count_column < *subject_counter; count_column++) {
				do {
					std::cout << "Введите название " << count_column + 1 << "-го предмета " << count_row + 1 << "-й сессии [20] (Название_предмета) >>> ";
					std::cin >> subject[count_row][count_column];
					if (subject[count_row][count_column].length() > 20) {
						print("Название предмета слишком длинное!\n");
						std::cin.clear();
						continue;
					}
					if (subject[count_row][count_column].length() < 2) {
						print("Название предмета слишком короткое!\n");
						std::cin.clear();
						continue;
					}
				} while (subject[count_row][count_column].length() > 20 || subject[count_row][count_column].length() < 2);
				do {
					std::cout << "Введите оценку " << count_column + 1 << "-го предмета " << count_row + 1 << "-й сессии (2 - 5) >>> ";
					std::cin >> mark[count_row][count_column];

					if (mark[count_row][count_column] != 5 && mark[count_row][count_column] != 4 && mark[count_row][count_column] != 3 && mark[count_row][count_column] != 2) {
						print("Такой оценки нет!\n");
						std::cin.sync();
						std::cin.clear();
						continue;
					}
				} while (mark[count_row][count_column] > 5.0 || mark[count_row][count_column] < 2.0);
			}
		}
	}
	void set_task() {
		double r = 0;
		double count = *subject_counter;
		for (int count_row = 0; count_row < 2; count_row++) {
			for (int count_column = 0; count_column < *subject_counter; count_column++) {
				if (mark[count_row][count_column] == 3) {
					r++;
				}
			}
		}
		r /= (2.0 * count);
		r *= 100;
		*R = r;
	}
	void set() {
		set_session_counter();
		set_subject_counter();
		set_subject();
		set_task();
	}
	void get() {
		for (int i = 0; i < 120; i++) std::cout << "=";
		for (int count_row = 0; count_row < 2; count_row++) {
			for (int count_column = 0; count_column < *subject_counter; count_column++) {
				std::cout << subject[count_row][count_column] << ' ';
				std::cout << mark[count_row][count_column] << '\t';
			}
			std::cout << '\n';
		}
		std::cout << "Task: " << *R << "%\n";
		for (int i = 0; i < 120; i++) std::cout << "=";
	}
	
private:
	int* session_counter = nullptr;
	int* subject_counter = nullptr;
	int** mark;
	double* R;
	std::string** subject;
};

class File : public Program {
public:
	void AddStudent() {
		std::ofstream fout;
		fout.open(FILEPATH, std::ios_base::app);

		Student* student = new Student;
		student->set();
		student->get();
		
		fout << "\nНОМЕР ЗАЧЕТКИ:\n";
		fout << student->student_status;
		fout << "\nФАМИЛИЯ:\n";
		fout << student->surname;
		fout << "\nИМЯ:\n";
		fout << student->name;
		fout << "\nОТЧЕСТВО:\n";
		fout << student->middlename;
		fout << "\nДЕНЬ:\n";
		fout << *student->day;
		fout << "\nМЕСЯЦ:\n";
		fout << *student->month;
		fout << "\nГОД:\n";
		fout << *student->year;
		fout << "\nПОЛ:\n";
		fout << student->gender;
		fout << "\nГОД_ПОСТУПЛЕНИЯ:\n";
		fout << *student->year_entrance;
		fout << "\nФАКУЛЬТЕТ:\n";
		fout << student->faculty;
		fout << "\nКАФЕДРА:\n";
		fout << student->department;
		fout << "\nГРУППА:\n";
		fout << student->group;
		delete student;

		Session* session = new Session;
		session->set();
		session->get();
		fout << "\nTASK:\n";
		fout << *session->R;
		fout << "\nСЕССИЯ:\n";
		for (int count_row = 0; count_row < *session->session_counter; count_row++) {
			fout << count_row + 1 << "_СЕМЕСТР:\n";
			for (int count_column = 0; count_column < *session->subject_counter; count_column++) {
				fout << session->subject[count_row][count_column] << " - " << session->mark[count_row][count_column] << '\n';
			}
		}
		for (int i = 0; i < 120; i++) fout << "=";
		delete session;
		fout.close();
	}
	void FindStudent() {
		std::ifstream fin;
		fin.open(FILEPATH, std::ios_base::in);
		std::string book_num, book_num_check;
		print("Введите номер зачетной книжки >>> ");
		std::cin >> book_num;
		while (getline(fin, book_num_check)) {
			if (book_num == book_num_check) {
				break;
			}
		}
		while (getline(fin, book_num_check)) {
			print(book_num_check);
			print("\n");
			if (book_num_check == "========================================================================================================================") {
				break;
			}
		}
		fin.close();
	}
	void DeleteStudent() {
		int num_start = 0;
		int num_end = 0;
		std::ifstream fin;
		fin.open(FILEPATH, std::ios_base::in);
		std::string book_num, book_num_check;
		print("Введите номер зачетной книжки >>> ");
		std::cin >> book_num;
		while (getline(fin, book_num_check)) {
			num_start++;
			if (book_num == book_num_check) {
				break;
			}
		}
		num_start -= 2;
		while (getline(fin, book_num_check)) {
			num_end++;
			if (book_num_check == "========================================================================================================================") {
				break;
			}
		}
		num_end += num_start;
		fin.close();

		int counter = 0;
		std::string str;
		std::ofstream fout;
		std::ifstream fcopy;
		fout.open("file_copy.txt", std::ios_base::app);
		fcopy.open(FILEPATH, std::ios_base::in);
		while (getline(fcopy, str)) {
			if (counter == num_start) break;
			fout << str << std::endl;
			counter++;
		}
		while (getline(fcopy, str)) {
			if (counter == num_end) break;
			counter++;
		}
		while (getline(fcopy, str)) {
			fout << str << std::endl;
		}
		fout.close();
		fcopy.close();
		remove(FILEPATH);
		char oldfilename[] = "file_copy.txt";                   
		char newfilename[] = FILEPATH;                   
		if (rename(oldfilename, newfilename) == 0) std::cout << "Запись удалена!\n\n";
		else std::cout << "Ошибка!\n";
	}
	void ChangeHub() {
		
		
		std::ifstream fin;
		fin.open(FILEPATH, std::ios_base::in);
		std::string book_num, book_num_check;
		print("Введите номер зачетной книжки >>> ");
		std::cin >> book_num;
		while (getline(fin, book_num_check)) {
			if (book_num == book_num_check) {
				break;
			}
		}
		while (getline(fin, book_num_check)) {
			print(book_num_check);
			print("\n");
			if (book_num_check == "========================================================================================================================") {
				break;
			}
		}
		fin.close();

		print("\n");
		for (int i = 0; i < 120; i++) std::cout << "=";
		print("\n");

		int* hub_arg = new int;
		print(" [1]. - Изменить фамилию\n");
		print(" [2]. - Изменить имя\n");
		print(" [3]. - Изменить отчество\n");
		print(" [4]. - Изменить дату рождения\n");
		print(" [5]. - Изменить пол\n");
		print(" [6]. - Изменить год поступления\n");
		print(" [7]. - Изменить факультет\n");
		print(" [8]. - Изменить кафедру\n");
		print(" [9]. - Изменить группу\n");
		print("[10]. - Изменить номер зачетной книжки\n");
		print("[11]. - Редактировать сессию\n");
		print("[12]. - Выйти\n\n>>> ");
		std::cin >> *hub_arg;

		Student* student = new Student;
		switch (*hub_arg) {
		case 1: {
			student->set_surname();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 1;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << student->surname << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Фамилия изменена!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}	
		case 2: {
			student->set_name();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 3;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << student->name << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Имя изменено!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 3: {
			student->set_middlename();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 5;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << student->middlename << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Отчество изменено!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 4: {
			student->set_birth();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 7;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << *student->day << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "";
			else std::cout << "Ошибка!\n";
			
			num = 0;
			std::ifstream _fin;
			_fin.open(FILEPATH, std::ios_base::in);
			while (getline(_fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 9;
			_fin.close();

			counter = 0;
			std::string _str;
			std::ofstream _fout;
			std::ifstream _fcopy;
			_fout.open("file_copy.txt", std::ios_base::app);
			_fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(_fcopy, _str)) {
				if (counter == num) break;
				_fout << _str << std::endl;
				counter++;
			}
			_fout << *student->month << std::endl;
			while (getline(_fcopy, _str)) {
				_fout << _str << std::endl;
			}
			_fout.close();
			_fcopy.close();
			remove(FILEPATH);
			char _oldfilename[] = "file_copy.txt";
			char _newfilename[] = FILEPATH;
			if (rename(_oldfilename, _newfilename) == 0) std::cout << "";
			else std::cout << "Ошибка!\n";

			num = 0;
			std::ifstream __fin;
			__fin.open(FILEPATH, std::ios_base::in);
			while (getline(__fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 11;
			__fin.close();

			counter = 0;
			std::string __str;
			std::ofstream __fout;
			std::ifstream __fcopy;
			__fout.open("file_copy.txt", std::ios_base::app);
			__fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(__fcopy, __str)) {
				if (counter == num) break;
				__fout << __str << std::endl;
				counter++;
			}
			__fout << *student->year << std::endl;
			while (getline(__fcopy, __str)) {
				__fout << __str << std::endl;
			}
			__fout.close();
			__fcopy.close();
			remove(FILEPATH);
			char __oldfilename[] = "file_copy.txt";
			char __newfilename[] = FILEPATH;
			if (rename(__oldfilename, __newfilename) == 0) std::cout << "Дата рождения изменена!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 5: {
			student->set_gender();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 13;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << student->gender << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Пол изменен!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 6: {
			student->set_year_entrance();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 15;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << *student->year_entrance << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Год поступления изменен!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 7: {
			student->set_faculty();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 17;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << student->faculty << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Факультет изменен!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 8: {
			student->set_department();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 19;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << student->department << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Кафедра изменена!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 9: {
			student->set_group();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 21;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << student->group << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Группа изменена!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 10: {
			student->set_student_status();
			int num = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num -= 1;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			fout << student->student_status << std::endl;
			while (getline(fcopy, str)) {
				fout << str << std::endl;
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Номер зачетной книжки изменен!\n\n";
			else std::cout << "Ошибка!\n";
			delete student;
			break;
		}
		case 11: {
			delete student;
			Session* session = new Session;
			session->set();
			session->get();
			int num = 0;
			int num_end = 0;
			std::ifstream fin;
			fin.open(FILEPATH, std::ios_base::in);
			while (getline(fin, book_num_check)) {
				num++;
				if (book_num == book_num_check) {
					break;
				}
			}
			num += 22;
			fin.close();

			int counter = 0;
			std::string str;
			std::ofstream fout;
			std::ifstream fcopy;
			fout.open("file_copy.txt", std::ios_base::app);
			fcopy.open(FILEPATH, std::ios_base::in);
			while (getline(fcopy, str)) {
				if (counter == num) break;
				fout << str << std::endl;
				counter++;
			}
			while (getline(fcopy, str)) {
				if (str == "========================================================================================================================") {
					fout << "TASK:\n";
					fout << *session->R;
					fout << "\nСЕССИЯ:\n";
					for (int count_row = 0; count_row < *session->session_counter; count_row++) {
						fout << count_row + 1 << "_СЕМЕСТР:\n";
						for (int count_column = 0; count_column < *session->subject_counter; count_column++) {
							fout << session->subject[count_row][count_column] << " - " << session->mark[count_row][count_column] << '\n';
						}
					}
					fout << "========================================================================================================================\n";
					while (getline(fcopy, str)) {
						fout << str << std::endl;
					}
					break;
				}
			}
			fout.close();
			fcopy.close();
			remove(FILEPATH);
			char oldfilename[] = "file_copy.txt";
			char newfilename[] = FILEPATH;
			if (rename(oldfilename, newfilename) == 0) std::cout << "Сессия отредактирована!\n\n";
			else std::cout << "Ошибка!\n";
			delete session;
			break;
		}
		case 12: {
			delete student;
			break;
		}
		default:
			system("cls");
			ChangeHub();
		}
		return;
	}
};

class Menu : Program {
public:
	Menu() {
		menu_arg = new int;
		hub();
	}
	~Menu() {
		delete menu_arg;
		parting();
	}
	void hub() {
		std::cout << "Welcome!\n\n";
		for (int i = 0; i < 120; i++) std::cout << "=";
		std::cout << "\n\n";
		std::cout << "[1]. - Добавить студента\n";
		std::cout << "[2]. - Найти студента\n";
		std::cout << "[3]. - Удалить студента\n";
		std::cout << "[4]. - Изменить запись о студенте\n";
		std::cout << "[5]. - Выполнить задание\n";
		std::cout << "[6]. - Выйти\n\n>>> ";

		std::cin >> *menu_arg;
		switch (*menu_arg){
		case 1: {
			File* file = new File;
			file->AddStudent();
			delete file;
			system("pause");
			system("cls");
			hub();
			break;
		}
		case 2: {
			File* file = new File;
			file->FindStudent();
			delete file;
			system("pause");
			system("cls");
			hub();
			break;
		}
		case 3: {
			File* file = new File;
			file->DeleteStudent();
			delete file;
			system("pause");
			system("cls");
			hub();
			break;
		}
		case 4: {
			File* file = new File;
			file->ChangeHub();
			delete file;
			system("pause");
			system("cls");
			hub();
			break;
		}
		case 5: {

		}
		case 6: {
			return;
		}
		default:
			system("cls");
			hub();
			break;
		}
	}
	void parting() {
		system("cls");
		std::cout << "\nGoodbye!\n";
	}
private:
	int* menu_arg;
};

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu* obj = new Menu;
	delete obj;
	return 0;
}