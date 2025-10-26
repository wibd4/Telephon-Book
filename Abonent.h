#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

class Abonent {
	char* fio;
	char home_number[16];
	char work_number[16];
	char cell_number[12];
public:
	Abonent() : fio(nullptr) {
		home_number[0] = '\0';
		work_number[0] = '\0';
		cell_number[0] = '\0';
	}

	Abonent(const Abonent& other) {
		if (other.fio) {
			fio = new char[strlen(other.fio) + 1];
			strcpy(fio, other.fio);
		}
		else {
			fio = nullptr;
		}
		strcpy(home_number, other.home_number);
		strcpy(work_number, other.work_number);
		strcpy(cell_number, other.cell_number);
	}

	Abonent(const char* f, const char h[16], const char w[16], const char c[12]) {
		fio = new char[strlen(f) + 1];
		strcpy(fio, f);
		strcpy(home_number, h);
		strcpy(work_number, w);
		strcpy(cell_number, c);
	}

	~Abonent() {
		delete[] fio;
	}

	void debug_add()
	{
		if (fio) delete[] fio;
		fio = new char[100];
		strcpy(fio, "Andrey Petrov");
		strcpy(home_number, "-");
		strcpy(work_number, "89567828531");
		strcpy(cell_number, "Info");
	}

	void add()
	{
		if (fio) delete[] fio;
		fio = new char[100];


		cin.ignore();
		cout << "Введите ФИО: ";
		cin.getline(fio, 100);

		cout << "Введите номер домашнего телефона: ";
		cin.getline(home_number, 16);

		cout << "Введите номер рабочего телефона: ";
		cin.getline(work_number, 16);

		cout << "Введите доп информацию: ";
		cin.getline(cell_number, 12);

		cout << endl;
	}

	void print() {
		cout << "Имя: " << fio << endl;
		cout << "Домашний телефон: " << home_number << endl;
		cout << "Рабочий телефон: " << work_number << endl;
		cout << "Доп. информация: " << cell_number << endl;
		cout << endl;
	}

	Abonent& operator=(const Abonent& other) {
		strcpy(fio, other.fio);
		strcpy(home_number, other.home_number);
		strcpy(work_number, other.work_number);
		strcpy(cell_number, other.cell_number);

		return *this;
	}

	bool operator==(const Abonent& other) {
		return strcmp(fio, other.fio);
	}

	friend void find(Abonent* a, const char* info);
	friend void save(Abonent* a, size_t& count);
	friend void load(Abonent* a, size_t& count);
};
