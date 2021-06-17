#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include "decoder.h"
#include "allcodersinfo.h"

/// <summary>
/// ������� �������������� ����� ���� ��������� � �������������� ���� ������������
/// </summary>
void CoderMenu() {

	// ���� ������������ �� ����� ������ "�����"
	bool flag = false;
	while (flag == false) {

		// �������� ����
		PrintMenu(2);

		// �������� ���� ������������
		int userChoice = UserInput(1, 4);

		// ��������� ����, ���� ������ ������������
		if (CoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}

/// <summary>
/// ������� �������������� ����� ���� ��������� � �������������� ���� ������������
/// </summary>
void DecoderMenu() {

	// ���� ������������ �� ����� ������ "�����"
	bool flag = false;
	while (flag == false) {

		// �������� ����
		PrintMenu(3);

		// �������� ���� ������������
		int userChoice = UserInput(1, 4);

		// ��������� ����, ���� ������ ������������
		if (DecoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}

/// <summary>
/// ������� �������������� ����� ���� ��������� � �������������� ���� ������������
/// </summary>
void AllCoders() {

	// ���� ������������ �� ����� ������ "�����"
	bool flag = false;
	while (flag == false) {

		// �������� ����
		PrintMenu(4);

		// �������� ���� ������������
		int userChoice = UserInput(1, 4);

		// ��������� ����, ���� ������ ������������
		if (CipherMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}

/// <summary>
/// ������� ������������ ���� � �������� ������ ������� � ����������� �� ���������
/// </summary>
/// <param name="userChoice"> ����� �������� ����, ������� ������ ������������ </param>
/// <returns> True ���� ������������ ����� "�����"</returns>
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
		system("cls"); // ������� ����
		AllCoders(); //���� ������ 
		return false;
	case 4:
		//�����
		return true;
	default:
		return false;
	}
}

/// <summary>
/// ������� ������������ ���� � �������� ������ ������� � ����������� �� ���������
/// </summary>
/// <param name="userChoice"> ����� �������� ����, ������� ������ ������������ </param>
/// <returns> True ���� ������������ ����� "�����"</returns>
bool CoderMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		//���� ������
		system("cls"); // ������� ����
		Caesar(); // �������� ���� ������ 
		return false;
	case 2:
		// ���� �������
		system("cls"); // ������� ����
		Vernam();
		return false;
	case 3:
		// ���� ��������
		system("cls"); // ������� ����
		Vizhner();
		return false;;
	case 4:
		system("cls"); // ������� ����
		//�����
		return true;
	default:
		return false;;
	}
}

/// <summary>
/// ������� ������������ ���� � �������� ������ ������� � ����������� �� ���������
/// </summary>
/// <param name="userChoice"> ����� �������� ����, ������� ������ ������������ </param>
/// <returns> True ���� ������������ ����� "�����"</returns>

bool DecoderMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		system("cls"); // ������� ����
		DeCaesar(); //���� ������ 
		return false;
	case 2:
		system("cls"); // ������� ����
		DeVernam(); // ���� �������
		return false;
	case 3:
		system("cls"); // ������� ����
		DeVizhener(); // ���� ��������
		return false;
	case 4:
		system("cls"); // ������� ����
		//�����
		return true;
	default:
		return false;
	}
}

/// <summary>
/// ������� ������������ ���� � �������� ������ ������� � ����������� �� ���������
/// </summary>
/// <param name="userChoice"> ����� �������� ����, ������� ������ ������������ </param>
/// <returns> True ���� ������������ ����� "�����"</returns>
bool CipherMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		system("cls"); // ������� ����
		//���� ������ 
		InfoAboutCaesar();
		return false;
	case 2:
		system("cls"); // ������� ����
		//���� ������� 
		InfoAboutVernam();
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
