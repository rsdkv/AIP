#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include "decoder.h"

void CoderMenu() {
	bool flag = false;
	while (flag == false) {
		PrintMenu(2);
		int userChoice = UserInput(1, 4);
		if (CoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}

void DecoderMenu() {
	bool flag = false;
	while (flag == false) {
		PrintMenu(3);
		int userChoice = UserInput(1, 4);
		if (DecoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}
void AllCoders() {
	bool flag = false;
	while (flag == false) {
		PrintMenu(4);
		int userChoice = UserInput(1, 4);
		if (DecoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}



bool MainMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		//���� ���������� ������ 
		system("cls"); // ������� ����
		CoderMenu();
		return false;
	case 2:
		system("cls"); // ������� ����
		DecoderMenu();//���� ������������ ������ 
		return false;
	case 3:
		//���� ������ 
		return false;
	case 4:
		//�����
		return true;
	default:
		return false;
	}
}
bool CoderMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		//���� ������ 
		std::cout<< "���� ������\n";
		system("cls"); // ������� ����
		Caesar(); // �������� ���� ������ 
		return false;
	case 2:
		system("cls"); // ������� ����
		Vernam();
		return false;
	case 3:
		system("cls"); // ������� ����
		//������ ���� 
		return false;;
	case 4:
		system("cls"); // ������� ����
		//�����
		return true;
	default:
		return false;;
	}
}

bool DecoderMenuNavigator(int userChoice){
	switch (userChoice)
	{
	case 1:
		system("cls"); // ������� ����
		DeCaesar(); //���� ������ 
		std::cout << "���� ������\n";
		return false;
	case 2:
		system("cls"); // ������� ����
		DeVernam();
		return false;
	case 3:
		system("cls"); // ������� ����
		//������ ���� 
		return false;
	case 4:
		system("cls"); // ������� ����
		//�����
		return true;
	default:
		return false;
	}
}
bool CipherMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		system("cls"); // ������� ����
		//���� ������ 
		std::cout << "���� ������\n";
		return false;
	case 2:
		system("cls"); // ������� ����
		//������ ���� 
		return false;
	case 3:
		system("cls"); // ������� ����
		//������ ���� 
		return false;
	case 4:
		system("cls"); // ������� ����
		//�����
		return true;
	default:
		return false;
	}
}
