#include <iostream>
#include <stack>
#include <string>

void stack(const std::string& input, std::stack<char>& stackString);

int main() 
{
    setlocale(LC_ALL, "rus");
    std::string input;
    std::stack<char> stackString;

    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    stack(input, stackString);

    return 0;
}

void stack(const std::string& input, std::stack<char>& stackString)
{

    for (auto i = input.begin(); i != input.end(); i++)
    {
        if (*i == '{' || *i == '[' || *i == '(')
        {
            // Помещение открывающих скобок в стек
            stackString.push(*i);
        }
        else if (*i == '}' || *i == ']' || *i == ')')
        {
            if (stackString.empty())
            {
                // В случае, если стек пуст и встречена закрывающая скобка, выводится ошибка
                std::cout << "Ошибка: " << *i << " неправильная закрывающая скобка, нет соответствующей открывающей скобки!" << std::endl;
                return;
            }
            else
            {
                char top = stackString.top();
                stackString.pop();
                if ((*i == '}' && top != '{') || (*i == ']' && top != '[') || (*i == ')' && top != '('))
                {
                    // Проверка соответствия закрывающей скобки последней открывающей
                    std::cout << "Ошибка: " << *i << " неправильная закрывающая скобка, не соответствует открывающей скобке!" << std::endl;
                    return;
                }
            }
        }
    }

    if (!stackString.empty())
    {
        // В случае, если в стеке остались открывающие скобки без соответствующих закрывающих
        std::cout << "Ошибка: Одна или несколько открывающих скобок без соответствующих закрывающих!" << std::endl;
        return;
    }

    std::cout << "Расстановка скобок верна!" << std::endl;
}
