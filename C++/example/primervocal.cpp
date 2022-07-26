#include <iostream>
#include <string>

void vocal(std::string text, int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if (text[i] == 'a')
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			std::cout << "^\nEl primer vocal es A";
			break;
		}
		else if (text[i] == 'e')
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			std::cout << "^\nl primer vocal es E";
			break;
		}
		else if (text[i] == 'i')
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			std::cout << "^\nEl primer vocal es I";
			break;
		}
		else if (text[i] == 'o')
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			std::cout << "^\nEl primer vocal es O";
			break;
		}
		else if (text[i] == 'u')
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << " ";
			}
			std::cout << "^\nEl primer vocal es U";
			break;
		}
	}
}

int main()
{
	std::string text;
	int tam;

	std::cout << "Ingresa una palabra:\n";
	std::cin >> text;
	tam = text.size();

	vocal(text, tam);
	std::cout << "\n";

	return 0;
}