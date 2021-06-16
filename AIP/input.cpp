/*� ������ ����� ������������� ������� ��� �������� ������ ������������

*/
#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include <vector>
/*��� ��� ���� ������ ���� ������ � ����������� ���������, �� ������� ��������� �� ���� 2 ���������: min max �������� ��� �����

*/
int UserInput(int min, int max) {
	bool flag = false;
	std::string input; //���� �����������  
	while (!flag) {
		std::cin >> input;
		/*������������� try catch, � ������� �������� ��������� ���������� ���� �����������
		���� ������ �������� ������ � ����, ��������� �������� ��� � ���������������, ����� ,
		������ ������������ ������ ������ ���������� ������
		*/
		try
		{
			int correctInput = std::stoi(input); // ������� �������� ������ � ���� � ������� 
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
/*��������� ����� , ������� ��� ������������
* �������� ����� ������ ���� ���������, ��� ��� �� �������� � ���������, ��� ��� � ��� �� ������ �������� � ASCII
 */
std::string UserInputText() {
	bool flag = false;
	std::string input; //���� �����������  
	getline(std::cin, input);
	while (!flag) {
		getline(std::cin, input);
		
		try
		{
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