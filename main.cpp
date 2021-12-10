#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <fstream>
#include "misc.h"


using namespace std;

enum {
	INPUT = 1,
	INPUT_FROM_TXT,
	INPUT_FROM_BIN,
	OUTPUT,
	WHAT,
	REQUEST,
	OUTPUT_TO_TXT,
	TXT_TO_BIN,
	ADD,
	EDIT,
	DEL,
	SORT,
	EXIT = 0
};

int inp{}, truesize{2};
student list[SIZE];
int minI{}, minMark{}, maxName{ 19 }, maxGroup{ 7 };
char edit[2]{};
bool flag = true;
fstream fs;



int main() {
	system("chcp 1251 && cls");
	do {
		cout << endl << "   МЕНЮ" << endl << "  " << endl;
		cout << " "<<INPUT << "|  Ввод данных с клавиатуры" << endl;
		cout << " "<<INPUT_FROM_TXT << "|  Ввод данных из текстового файла" << endl;
		cout << " "<<INPUT_FROM_BIN << "|  Ввод данных из бинарного файла" << endl;
		cout << " "<<OUTPUT << "|  Вывод данных на экран" << endl;
		cout <<" "<< WHAT << "|  Вывод данных в файл" << endl;
		cout << " "<<REQUEST << "   Выполнение запроса" << endl;
		cout << " "<<OUTPUT_TO_TXT << "   Перевод в текстовый файл" << endl;
		cout << " "<<TXT_TO_BIN << "   Перевод текстового файла в бинарный" << endl;
		cout << " "<<ADD << "|  Добавление записи" << endl;
		cout << EDIT << "|  Изменение записи" << endl;
		cout << DEL << "|  Удаление записи" << endl;
		cout << SORT << "|  Cортировка" << endl;
		cout <<" " << EXIT << "|  Выход" << endl;
		cout << endl<< "__> ";
		cin >> inp;
		switch (inp) {
		case INPUT:
			for (int i = 0; i < truesize; i++) {
				cout << "Ввод данных студента " << i + 1 << endl;
				list[i] = input(i, list);
				cout << endl;
			}
			break;

		case OUTPUT:
			for (int i{}; i < truesize; i++) {
				if (strlen(list[i].name) > maxName)
					maxName = strlen(list[i].name);
				if (strlen(list[i].group) > maxGroup)
					maxGroup = strlen(list[i].group);
			}
			cout << endl << endl << "  " << "|Список студентов " << endl << "  |" << endl;
			cout << " #|" << setw(maxName + 1) << "имя|" << setw(maxGroup + 1) << "группа|" << setw(5 + 1) << "год|" << setw(9) << "оценки|" << endl;
			for (int i{}; i < truesize; i++) {
				cout << setw(2) << i + 1 << '|' << setw(19) << list[i].name << '|' << setw(maxGroup) << list[i].group << '|' << setw(5) << list[i].year << '|';
				for (int j{}; j < 4; j++)
					cout << setw(2) << list[i].mark[j];
				cout << '|' << endl;
			}
			break;



		case REQUEST:
			cout << endl << "Студент с минимальным средним баллом: ";
			for (int i{}; i < truesize; i++) {
				if (list[i].avgMark < minMark) {
					minMark = list[i].avgMark;
					minI = i;
				}
			}
			cout << list[minI].name << endl;
			break;


		case SORT:
			bubble(list, truesize);
			break;

		case EDIT:
			do {
				cout << "Выберите номер записи для изменения (1-" << truesize << "): ";
				cin >> edit;
				int iedit = charToInt(edit)-1;
				if (iedit >= truesize or iedit <= 0) {
					cout << "Ошибка, номер записи должен быть числом в отрезке [1;" << truesize << ']';
					flag = true;
				}
				else {
					flag = false;
					list[iedit] = input(iedit, list);
				}
			} while (flag == true);
			cout << "Запись была удалена" << endl;
			break;

		case DEL:
			do {
				if (truesize == 1) {
					cout << "Ошибка: невозможно удалить последнюю запись" << endl;
					break;
				}
				cout << "Выберите номер записи для удаления (1-" << truesize << "): ";
				cin >> edit;
				int iedit = charToInt(edit)-1;
				if (iedit > truesize or iedit < 0) {
					cout << "Ошибка, номер записи должен быть числом в отрезке [1;" << truesize << ']';
					flag = true;
				}
				else {
					flag = false;
					for (int i = iedit; iedit < truesize-2; i++) 
						swap(list[i], list[i + 1]);
					truesize--;
				}
			} while (flag == true);
			break;

		case ADD:
			if(truesize == SIZE)
				cout << "Ошибка: количество записей не может превышать " << SIZE << endl;
			truesize++;
			list[truesize] = input(truesize-1, list);
			cout << "Новая запись была добавлена" << endl;
			break;
			

		case WHAT:
			fs.open("table.txt", fstream::in | fstream::out | fstream::trunc);
			fs << endl << endl << "  " << "|Список студентов " << endl << "  |" << endl;
			fs << " #|" << setw(maxName + 1) << "имя|" << setw(maxGroup + 1) << "группа|" << setw(5 + 1) << "год|" << setw(9) << "оценки|" << endl;
			for (int i{}; i < truesize; i++) {
				fs << setw(2) << i + 1 << '|' << setw(19) << list[i].name << '|' << setw(maxGroup) << list[i].group << '|' << setw(5) << list[i].year << '|';
				for (int j{}; j < 4; j++)
					fs << setw(2) << list[i].mark[j];
				fs << '|' << endl;
			}
			fs.close();
			cout << "Данные были экспортированы в текстовый файл в виде таблицы" << endl;
			break;

		case OUTPUT_TO_TXT:
			fs.open("test.txt", fstream::in | fstream::out | fstream::trunc);
			for (int i = 0; i < truesize; i++) 
				fs << list[i].name << endl << list[i].group << endl << list[i].year << endl << list[i].mark << endl;
			
			fs.close();
			cout << "Данные были экспортированы в текстовый файл" << endl;
			break;

		case INPUT_FROM_TXT:
			fs.open("test.txt", fstream::in | fstream::out);
			for (int i = 0; i < truesize; i++) {
				fs.getline(list[i].name, NAME_SIZE);
				fs.getline(list[i].group, GROUP_SIZE);
				fs.getline(list[i].year, 5);
				fs.getline(list[i].mark, 5);
			}
			fs.close();
			cout << "Данные были импортированы из текстового файла" << endl;
			break;

		case INPUT_FROM_BIN:
			input_from_bin(list, truesize);
			cout << "Данные были импортированы из бинарного файла" << endl;
			break;

		case TXT_TO_BIN:
			txt_to_bin(truesize);
			cout << "Данные из текстового файла были экспортированы в бинарный" << endl;
			break;

		case EXIT:
			cout << "Выход из программы.. " << endl;
			break;
		default:
			cout << "Ошибка: вы ввели неверное значение" << endl;
			break;
		}
	} while (inp);
	return 0;
}