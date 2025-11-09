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
	//базовый конкструктор
	Abonent() : fio(nullptr) {
		home_number[0] = '\0';
		work_number[0] = '\0';
		cell_number[0] = '\0';
	}
	//конструктор копирования
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
	//конкструктор нового контакта
	Abonent(const char* f, const char h[16], const char w[16], const char c[12]) {
		fio = new char[strlen(f) + 1];
		strcpy(fio, f);
		strcpy(home_number, h);
		strcpy(work_number, w);
		strcpy(cell_number, c);
	}
	//деструктор
	~Abonent() {
		delete[] fio;
	}
	//метод дебаг
	void debug_add()
	{
		if (fio) delete[] fio;
		fio = new char[100];
		strcpy(fio, "Andrey Petrov");
		strcpy(home_number, "-");
		strcpy(work_number, "+79235095964");
		strcpy(cell_number, "Info");
	}
	//метод ввода
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
	//метод редактирования
	void edit()
	{
		int user;
		cout << "Введите что хотите изменить" << endl;
		cout << "1 - ФИО" << endl;
		cout << "2 - Домашний телефон" << endl;
		cout << "3 - Рабочий телефон" << endl;
		cout << "4 - Доп. информация" << endl;
		cout << "5 - Все данные" << endl;
		cin >> user;
		switch (user) {
		case 1: {
			if (fio) delete[] fio;
			fio = new char[100];


			cin.ignore();
			cout << "Введите ФИО: ";
			cin.getline(fio, 100);
			break;
		}
		case 2: {
			cin.ignore();
			cout << "Введите номер домашнего телефона: ";
			cin.getline(home_number, 16);
			break;
		}
		case 3: {
			cin.ignore();
			cout << "Введите номер рабочего телефона: ";
			cin.getline(work_number, 16);
			break;
		}
		case 4: {
			cin.ignore();
			cout << "Введите доп информацию: ";
			cin.getline(cell_number, 12);
		}
		case 5: {
			add();
			break;
		}
		default: {
			cout << "Неверный ввод" << endl;
		}
		}
	}

	//метод вывода
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
