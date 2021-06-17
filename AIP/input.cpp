/*� ������ ����� ������������� ������� ��� �������� ������ ������������

*/
#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include <vector>


int UserInput(int min, int max) {

	// ���� ��� ������ �� �����
	bool flag = false;

	//���� �����������
	std::string input;

	// ��������� ��, ��� ���� ������������, ���� �� �� ������ ���������� ������
	while (!flag) {
		getline(std::cin, input);
		/*������������� try catch, � ������� �������� ��������� ���������� ���� �����������
		���� ������ �������� ������ � ������ �����, ��������� �������� ��� � ���������������, ����� ,
		������ ������������ ������ ������ ���������� ������
		*/
		try
		{
			int correctInput = std::stoi(input); // ������� �������� ������ � ���� � ������� stoi

			// ��������� ��������� ������������� ����� �� �������������� ������� ��� ���������
			if (correctInput < min || correctInput > max) {
				throw std::exception();
			}
			return correctInput;
		}
		catch (const std::exception&) // ����� exception 
		{
			std::cout << "������� ���������� ������\n"; // ������ ������ ������ ������
		}
	}
}


std::string UserInputText() {

	// ���� ��� ������ �� �����
	bool flag = false;

	//���� �����������
	std::string input;

	// ��������� ��, ��� ���� ������������, ���� �� �� ������ ���������� ������
	while (!flag) {

		// ��������� ��� ���� ������������
		getline(std::cin, input);

		/*������������� try catch, � ������� �������� ��������� ���������� ���� �����������
		���� ������ �������� ������� ������ �� ������� ���������, ��������� �������� ��� � ���������������, ����� ,
		������ ������������ ������ ������ ���������� ������
		*/
		try
		{
			// �������� ������ �� ������ � ��������� ������ ������ ������� ��� � ���� ���� 
			for (int i = 0; i < input.length(); i++)
			{
				if ((int)input[i] > 125 || (int)input[i] < 32)
				{
					throw std::exception();
				}
			}
			return input;
		}
		catch (const std::exception&) // ����� exception 
		{
			std::cout << "������� ���������� ����� \n"; // ������ ������ ������ ������
		}
	}
}
