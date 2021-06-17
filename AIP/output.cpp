#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include <vector>

/// <summary>
/// ������� �������� � ���� ��� ���� � ���� ������� �����, ��� �� 0 ����� ����� ���������, � �� 1..n �������� ����
/// </summary>
/// <param name="xMenu"> ����� ����, ������� �� ����� �������� </param>
/// <returns> ������ ����� ���� </returns>
std::vector<std::string> GetMenu(int xMenu) {

	// ������� ����
	std::vector<std::string> mainMenu = { "��� �� ������ �������?\n"  , "����������� �����\n" , "������������ �����\n" ,
						"���������� ��� ��������� ����������\n" , "�����\n" };

	// ���� ������ ������ ����������
	std::vector<std::string> coderMenu = { "�������� ������� ���������� \n"  , "���� ������ \n" , "���� ������� \n" ,
						"���� �������\n" , "�����\n" };

	// ���� ������ ������ ����������
	std::vector<std::string> decoderMenu = { "�������� ������� ������������ \n"  , "���� ������ \n" ,"���� ������� \n",
						"���� �������\n" , "�����\n" };

	// ���� ������ ������ ���������� ��� ������ ���������� � ���
	std::vector<std::string> AllCodersMenu = { "�������� ���������� � ������� ������ ��������� \n"  , "���� ������ \n" ,"���� ������� \n",
						"���� �������\n" , "�����\n" };

	// ���������� ������ ��� ����
	switch (xMenu)
	{
	case 1:
		system("cls"); // ������� ����
		return mainMenu;
	case 2:
		system("cls"); // ������� ����
		return coderMenu;
	case 3:
		system("cls"); // ������� ����
		return decoderMenu;
	case 4:
		system("cls"); // ������� ����
		return AllCodersMenu;
	default:
		system("cls"); // ������� ����
		return mainMenu;
	}

}

/// <summary>
/// ������� ���������� ���� � �������
/// </summary>
/// <param name="xMenu"> ����� ����, ������� �� ����� ������� </param>
void PrintMenu(int xMenu) {

	// ������ ����� ����
	std::vector<std::string> menuOutput = GetMenu(xMenu);

	// ����� ��������� ����
	std::cout << menuOutput[0];

	// �������� ������ �� ������� �������� ���� � �������� ��� ����� � �����
	for (int i = 1; i < menuOutput.size(); i++)
	{
		std::cout << i << ") " << menuOutput[i];
	}
}

