#include <iostream>
#include <string>
#include <Windows.h>
#include <cctype>

using namespace std;

int main()
{
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		
		string Word;
		const char Letters[32] = {'а', 'я', 'у', 'е', 'о', 'ю', 'ё', 'и', 'э', 'ы', 'i', 'a', 'e', 'o', 'u', 'y', 'I', 'A', 'E', 'O', 'U', 'Y', 'А', 'Я', 'У', 'Е', 'О', 'Ю', 'Ё', 'И', 'Э', 'Ы'};
		const char NegativeSymbols[37] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ',', '.', '/', ';', ':', '<', '>', '?', '+', '=', '-', '_', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '|', ' \ ', '`', '~', ' '};
		unsigned int num_of_word;
		string total_result;
		bool total_flag = false;
		
		cout << "Введите текст: " << endl;
		getline(cin, Word);
		cout << "Вы ввели слово: " << Word << endl;

		cout << "Введите порядковый номер буквы слова: " << endl;
		cin >> num_of_word;

		int num_of_word_total = num_of_word - 1;

		if (num_of_word_total > Word.length())
		{
			throw ("Порядковый номер не может быть больше длины вашего предложения!");
		}

		for (int index = 0; index < 37; ++index)
		{
			if (Word[num_of_word_total] == NegativeSymbols[index])
			{
				throw ("Выбранный Вами символ не является буквой!");
				break;
			}
		}
		
		if (cin.fail())
		{
			throw ("Ошибка! Порядковый номер должен быть положительным целым числом!");
		}

		if (num_of_word_total > Word.length())
		{
			throw ("Ошибка! Вы ввели порядковый номер больший чем длина слова!");
		}

		for (int index = 0; index < 32; ++index)
		{
			if (Word[num_of_word_total] == Letters[index])
			{
				total_flag = true;
			}
		}

		if (total_flag)
		{
			total_result = "гласная буква";
		}
		else
		{
			total_result = "согласная буква";
		}

		cout << Word[num_of_word_total] << " - " << total_result << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	
	return 0;
}