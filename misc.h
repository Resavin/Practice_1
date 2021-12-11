#pragma once

enum {
	NAME_SIZE = 99,
	SIZE = 99,
	GROUP_SIZE = 20
};

struct  student
{
	char name[NAME_SIZE]{ "ярослав  рылов" };
	char group[GROUP_SIZE]{ "»ук4-12б" };
	char year[5]{ "2000" };
	char mark[5]{ "1234" };
	float avgMark{};
};
void input_from_bin(student flist[], int size);

void txt_to_bin(int n);

int charToInt(char a[]);

bool isLarger(char a[], char b[]);

void swap_int(int& a, int& b);

void swap_char(char& a, char& b);

void bubble(student flist[], int size);

student input(int i, student flist[]);