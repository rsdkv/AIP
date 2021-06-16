#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include <vector>

int UserInput(int min, int max) {
	bool flag=false; 
	std::string input;
	while (!flag) {
		std::cin >> input;
		try
		{
			int correctInput = std::stoi(input);
			if (correctInput < min || correctInput > max) {
				throw std::exception();
			}
			return correctInput;
		}
		catch (const std::exception&)
		{
			std::cout << "¬ведите корректные данные\n";
		}
	}
	
	
}