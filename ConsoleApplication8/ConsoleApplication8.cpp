#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;

string fileLine() {
	ifstream File;
	File.open("Lab4_test.txt");
	if (!File.is_open())
	{
		cout << "Открыть файл не удалось! \n";
	}
	string output;
	getline(File, output);
	File.close();
	return output;
}

bool existDigits(string& word) {
	for (char c : word) {
		if (isdigit(c)) {
			return true;
		}
	}
	return false;
}

string removeWordsDigits(const string& word) {
	stringstream stream(word);
	string sentence;
	string result;

	while (stream >> sentence) {
		if (!existDigits(sentence)) {
			result += sentence + " ";
		}
	}

	if (!result.empty()) {
		result.pop_back();
	}

	return result;
}

void stringLength(string& word) {
	stringstream stream(word);
	string sentence;

	while (stream >> sentence) {
		cout << sentence.length() << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Выберите команду:\n"
		"[1]Считать строчку с клавиатуры\n"
		"[2]Считать строчку с файла\n"
		"Команда: ";

	int choise;
	string strok, strok2;
	cin >> choise;

	system("cls");
	cout << "Первое задание: Выбран ввод номер: " << choise << endl;

	switch (choise) {
	case(1):
		cin.ignore();
		getline(cin, strok);
		break;
	case(2):
		strok2 = fileLine();
		break;
	}
	cout << "\n";

	string input;

	if (choise == 1) {
		input = strok;
	}
	else {
		input = strok2;
	}
	string output;
	string result;

	bool prevSpace = false;
	bool firstSymbol = true;
	bool previousPunct = false;

	for (char c : input) {

		if (c == ' ') {
			if (!prevSpace) {
				output += c;
				prevSpace = true;
			}
		}
		else {
			if (firstSymbol) {
				if (islower(input[0])) {
					output += (input[0] - 32);
					firstSymbol = false;
				}
				else {
					output += c;
					firstSymbol = false;
				}
			}
			else {
				output += tolower(c);
				prevSpace = false;
			}
		}
	}

	for (char c : output) {
		if (ispunct(c)) {
			if (!previousPunct) {
				result += c;
				previousPunct = true;
			}
		}
		else {
			result += c;
			previousPunct = false;
		}
	}

	cout << "Второе задание: Редактирование строки\n";

	cout << result << endl << endl;

	cout << "Третье задание: Вывод слов последовательности, не содержащих в своей записи чисел\n";

	string result_3 = removeWordsDigits(result);

	cout << result_3 << endl;

	cout << "\nЧетвертое задание: Вывод длины каждого слова изначальной последовательности\n";

	stringLength(input);

	cout << endl;

	return 0;
}


