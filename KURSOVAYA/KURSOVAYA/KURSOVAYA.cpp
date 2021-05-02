#define _CRT_SECURE_NO_WARNINGS
#define FILEPATH "file.txt"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>

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
		std::cout << "Task: " << *R << "\%\n";
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
	File() {
		
	}
	~File() {
		
	}
	void AddStudent() {
		std::ofstream fout;
		fout.open(FILEPATH, std::ios_base::app);
		for (int i = 0; i < 120; i++) fout << "=";

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
		delete session;
	}
private:
	
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
		std::cout << "[4]. - Редактировать запись о студенте\n";
		std::cout << "[5]. - Выполнить задание\n";
		std::cout << "[6]. - Выйти\n\n";
		std::cout << ">>> ";

		std::cin >> *menu_arg;
		switch (*menu_arg){
		case 1: {
			File* file = new File;
			file->AddStudent();
			delete file;
			system("pause");
			system("cls");
			hub();
		}
		case 2:

		case 3:

		case 4:

		case 5:

		case 6:
			return;
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