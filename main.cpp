#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "Abonent.h"

using std::cout;
using std::cin;
using std::endl;

size_t count = 0;


Abonent abonents[256];

//functions:
//add
//delAb
//editAb
//findAb
//printAll
//save
//load

void printAll()
{
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			cout << "Порядковый номер: " << i + 1 << endl;
			abonents[i].print();
		}
	}
	else {
		cout << endl;
		cout << "Не найденно" << endl;
		cout << endl;
	}
}

void del(Abonent* a, int index)
{
	index--;
	for (int i = index; i < count - 1; i++) {
		a[i] = a[i + 1];
	}
	count--;
	cout << "Успешно!" << endl;
}

void find(Abonent* a, const char* info)
{
	int user;
	cout << "По какому признаку искать" << endl;
	cout << "1 - ФИО" << endl;
	cout << "2 - Домашний телефон" << endl;
	cout << "3 - Рабочий телефон" << endl;
	cin >> user;

	switch (user) {
	case 1: {
		int j = 0;
		for (int i = 0; i < count; i++) {
			if (strcmp(a[i].fio, info) == false) {
				cout << "Порядковый номер : " << i + 1 << endl;
				a[i].print();
				j++;
			}
		}
		if (j < 1) {
			cout << "Не найдено" << endl;
		}
		break;
	}
	case 2: {
		int j = 0;
		for (int i = 0; i < count; i++) {
			if (strcmp(a[i].home_number, info) == false) {
				cout << "Порядковый номер : " << i + 1 << endl;
				a[i].print();
				j++;
			}
		}
		if (j < 1) {
			cout << "Не найдено" << endl;
		}
		break;
	}
	case 3: {
		int j = 0;
		for (int i = 0; i < count; i++) {
			if (strcmp(a[i].work_number, info) == false) {
				cout << "Порядковый номер : " << i + 1 << endl;
				a[i].print();
				j++;
			}
		}
		if (j < 1) {
			cout << "Не найдено" << endl;
		}
		break;
	}
	default: {
		cout << "Ошибка" << endl;
		break;
	}
	}
}

void save(Abonent* a, size_t& count)
{
	FILE* abonent = fopen("Abonent.txt", "w");
	FILE* Count = fopen("Count.txt", "w");

	if (Count) {
		fprintf(Count, "%d", count);
	}
	else {
		cout << "Файл не открыт." << endl;
	}

	if (abonent) {
		for (int i = 0; i < count; i++) {
			fprintf(abonent, "%s, %s, %s, %s", a[i].fio, a[i].home_number, a[i].work_number, a[i].cell_number);
			fprintf(abonent, "%s", ",");
			fprintf(abonent, "%s" "\n");
		}
	}
	else {
		cout << "Файл не открыт." << endl;
	}
	fclose(abonent);
	fclose(Count);
}

void load(Abonent* a, size_t& count)
{
	FILE* abonent = fopen("Abonent.txt", "r");
	FILE* Count = fopen("Count.txt", "r");

	if (Count) {
		fscanf(Count, "%d", &count);
	}
	else {
		cout << "Файл не открыт." << endl;
		return;
	}

	char tmp_f[256];
	char tmp_h[16];
	char tmp_w[16];
	char tmp_c[20];

	if (abonent) {
		for (int i = 0; i < count; i++) {
			fscanf(abonent, "%255[^,],%15[^,],%15[^,],%19[^,], ", tmp_f, tmp_h, tmp_w, tmp_c);
			delete[]a[i].fio;
			a[i].fio = new char[strlen(tmp_f) + 1];
			strcpy(a[i].fio, tmp_f);
			strcpy(a[i].home_number, tmp_h);
			strcpy(a[i].work_number, tmp_w);
			strcpy(a[i].cell_number, tmp_c);
		}
	}
	else {
		cout << "Файл не открыт." << endl;
	}
	fclose(abonent);
	fclose(Count);
}

int main() {
	setlocale(0, "");

	int user{};

	load(abonents, count);

	while (true) {
		cout << "Выберите действие" << endl;
		cout << "1 - Добавить контакт" << endl;
		cout << "2 - Удалить контакт" << endl;
		cout << "3 - Редактировать контак" << endl;
		cout << "4 - Список всех контактов" << endl;
		cout << "5 - Найти контакт" << endl;
		cout << "0 - Выход" << endl;
		cin >> user;
		switch (user) {
		case 0: {
			return 0;
			break;
		}
		case 1: {
			abonents[count].add();
			count++;
			save(abonents, count);
			break;
		}
		case 2: {
			cout << "Введите порядковый номер контакта: ";
			cin >> user;
			del(abonents, user);
			save(abonents, count);
			break;
		}
		case 3: {
			cout << "Введите порядковый номер контакта: ";
			cin >> user;
			abonents[user - 1].edit();
			save(abonents, count);
			break;
		}
		case 4: {
			printAll();
			break;
		}
		case 5: {
			char info[256];
			cin.ignore();
			cin.getline(info, 256);
			find(abonents, info);
			break;
		}
		default: {
			cout << "Неверный выбор." << endl;
		}
		}
	}

	return 1;
}
