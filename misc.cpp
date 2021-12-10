#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <fstream>
#include "misc.h"



using namespace std;
void input_from_bin(student flist[], int size) {
	ifstream fc("test.txt", ios::binary | ios::trunc);
	for (int i = 0; i < size; i++) {
		fc.read(flist[i].name, NAME_SIZE);
		fc.read(flist[i].group, GROUP_SIZE);
		fc.read(flist[i].year, 5);
		fc.read(flist[i].mark, 5);
	}
	fc.close();
}

void txt_to_bin(int n) {
	ifstream reader("test.txt");
	ofstream BinRecord("bit.dat");
	student d;
	if (reader) {
		for (int i = 0; i < n; i++) {
			reader.getline(d.name, NAME_SIZE);
			BinRecord.write(d.name, NAME_SIZE);
			reader.getline(d.group, GROUP_SIZE);
			BinRecord.write(d.group, GROUP_SIZE);
			reader.getline(d.year, 4);
			BinRecord.write(d.year, 4);
			reader.getline(d.mark, 4);
			BinRecord.write(d.mark, 4);
		}
		BinRecord.close();
		reader.close();
	}
}

int charToInt(char a[]) {
	int len = strlen(a), ia{};
	while (len > 0) {
		ia += ((int)a[strlen(a) - len] - '0') * pow(10, len - 1);
		len--;
	}
	return ia;
}

void swap_int(int& a, int& b) {
	int tmp{};
	tmp = a;
	a = b;
	b = tmp;
}

void swap_char(char& a, char& b) {
	char tmp;
	tmp = a;
	a = b;
	b = tmp;
}

bool isLarger(char a[], char b[]) {
	int len = max(strlen(a), strlen(b));
	int i{};
	while(i<len){
		if ((int)a[i] < (int)b[i])
			return true;
		else if ((int)a[i] == (int)b[i])
			i++;
		else
			return false;
	}
}

void bubble(student flist[], int size) {
	int flag{}, srt{};
	cout << endl << "������� ������ ����������:\n";
	cout << "1) ����������� �� �����\n";
	cout << "2) ����������� �� ������\n";
	cout << "3) ����������� �� ���� �����������\n";
	cout << "4) ����������� �� ����� �������\n";
	cout << " > ";
	cin >> srt;
	switch (srt) {
	case 1:
		cout << "(1=�-�, 2=�-�): ";
		cin >> flag;
		if (flag == 2) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size-1; j++) {
					if (isLarger(flist[j].name, flist[j + 1].name)) 
						swap(flist[j], flist[j + 1]);
				}
			}
			cout << "���������� ���� ���������" << endl;
		}
		else if (flag == 1) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size-1; j++) {
					if (isLarger(flist[j+1].name, flist[j].name))
						swap(flist[j], flist[j+1]);
				}
			}
			cout << "���������� ���� ���������" << endl;
		}
		else {
			cout << "������: ������� �������� �������� ����������" << endl;;
		}
		break;

	case 2:
		cout << "����������� ���������� �� ������.." << endl;
		cout << "(1=�-�, 2=�-�): ";
		cin >> flag;
		if (flag == 2) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					if ((isLarger(flist[j].group, flist[j + 1].group)))
						swap(flist[j], flist[j + 1]);
				}
			}
			cout << "���������� ���� ���������" << endl;
		}
		else if (flag == 1) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					if (isLarger(flist[j+1].group, flist[j].group))
						swap(flist[j], flist[j + 1]);
				}
			}
			cout << "���������� ���� ���������" << endl;
		}
		else {
			cout << "������: ������� �������� �������� ����������" << endl;;
		}
		break;

	case 3:
		cout << "����������� ���������� �� ���� �����������.." << endl;
		cout << "(1=�� �����������, 2=�� ��������): ";
		cin >> flag;
		if (flag == 2) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					if (isLarger(flist[j].year, flist[j + 1].year))
						swap(flist[j], flist[j + 1]);
				}
			}
			cout << "���������� ���� ���������" << endl;
		}
		else if (flag == 1) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					if (isLarger(flist[j+1].year, flist[j].year))
						swap(flist[j], flist[j + 1]);
				}
			}
			cout << "���������� ���� ���������" << endl;
		}
		else {
			cout << "������: ������� �������� �������� ����������" << endl;;
		}
		break;

	case 4:
		cout << "����������� ���������� �� ����� �������.." << endl;
		cout << "(1=�� �����������, 2=�� ��������): ";
		cin >> flag;
		if (flag == 2) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					if (isLarger(flist[j].mark, flist[j + 1].mark))
						swap(flist[j], flist[j + 1]);
				}
			}
			cout << "���������� ���� ���������" << endl;
		}
		else if (flag == 1) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1; j++) {
					if (isLarger(flist[j].mark, flist[j + 1].mark))
						swap(flist[j], flist[j + 1]);
				}
			}
			cout << "���������� ���� ���������" << endl;
		}
		else {
			cout << "������: ������� �������� �������� ����������" << endl;;
		}
		break;

	default:
		cout << "������: ������� �������� ��������. ������� � ������� ����.." << endl;
		break;
	}
}




student input(int i, student flist[]) {
	bool flag = true, check = true;

	//���
	do {
		cout  << "������� ���: ";
		//cin.clear();
		cin.ignore();
		cin.getline(flist[i].name, NAME_SIZE);
		if (strlen(flist[i].name) > NAME_SIZE) {
			cout << "������: ��� �� ����� ��������� ������ " << NAME_SIZE << " ��������" << endl;
			flag = true;
		}
		else {
			flag = false;
		}
	} while (flag == true);

	//������
	do {
		cout << "������� ������: ";
		cin.clear();
		//cin.ignore();
		//cin >> flist[i].group;
		cin.getline(flist[i].group, GROUP_SIZE);
		if (strlen(flist[i].group) > GROUP_SIZE) {
			cout << "������: �������� ������ �� ����� ��������� ������ " << GROUP_SIZE << " ��������" << endl;
			flag = true;
		}
		else
			flag = false;
	} while (flag == true);

	//���
	do {
		cout << "������� ��� �����������: ";
		//cin.clear();
		//cin.ignore();
		cin.getline(flist[i].year, 5);
		int iyear = charToInt(flist[i].year);
		if ((strlen(flist[i].year)) != 4) {
			cout << "������: ��� ����������� ������ ���� ������ � ������� [1755;2021]" << endl;
			flag = true;
		}
		char bord1[5] = "1750", bord2[5]="2021";
		if (iyear < 1755 or iyear > 2021) {
			cout << "������: ��� ����������� ������ ���� ������ � ������� [1755;2021]" << endl;
			flag = true;
		}
		else
			flag = false;
	} while (flag == true);


	//������
	do {
		cout << "������� 4 ������ ��� ��������: ";
		//cin.clear();
		//cin.ignore();
		//cin >> flist[i].mark;
		cin.getline(flist[i].mark, 5);
		check = true;
		for (int j = 0; j < 4; j++) {
			if ((((int)flist[i].mark[j] - '0') > 5) or (((int)flist[i].mark[j] - '0') < 1))
				check = false;
		}
		if ((strlen(flist[i].mark) != 4) or (check == false)) {
			cout << "������: ������ ������ ��������� ��� �������� � ���� ������� �� ������� [1;5]" << endl;
			flag = true;
			cin.clear();
			strcpy_s(flist[i].mark, " ");
		}
		else {
			flag = false;
		}
	} while (flag == true);
	flist[i].avgMark = ((int)flist[i].mark[0] - '0' + (int)flist[i].mark[1] - '0' + (int)flist[i].mark[2] - '0' + (int)flist[i].mark[3] - '0') / 4.0;
	return flist[i];
}

