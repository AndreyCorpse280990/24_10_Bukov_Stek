#include <iostream>
#include <stack>
#include <string>

// stack-based function for string validation
void stack(const std::string &input)
{
	std::string text = input;
	if (!text.empty())
	{
		if (text.find("{") && text.find("[") && text.find("("))
		{

		}
	}
	else
	{
		std::cout << "Строка пустая" << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::string input;
	
}
