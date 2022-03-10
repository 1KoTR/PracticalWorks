#include "Complex.h"

using namespace std;

void Clear()
{
	system("cls");
}
void Pause()
{
	system("pause");
}

void Debug(const Complex& num1, const Complex& num2)
{
	cout << "\tnum1 = " << num1 << endl;
	cout << "\tnum2 = " << num2 << endl;
	cout << endl;
}
double CreateNumber()
{
	double number = 0;
	cout << "\tВведите число number : ";
	cin >> number;
	cout << endl;
	
	return number;
}

#pragma region MenuItems

void Menu_1(Complex& num1, Complex& num2)
{
	cout << "\tВведите (через пробел) реальную и мнимую части num1 : ";
	cin >> num1;
	cout << "\tВведите (через пробел) реальную и мнимую части num2 : ";
	cin >> num2;
}
void Menu_2(const Complex& num1, const Complex& num2)
{
	double number = CreateNumber();

	Debug(num1, num2);
	
	cout << "\tnum1 + number = " << num1 + number << endl;
	cout << "\tnumber + num2 = " << number + num2 << endl;
	cout << "\tnum1 + num2 = " << num1 + num2 << endl;

	Pause();
}
void Menu_3(const Complex& num1, const Complex& num2)
{
	double number = CreateNumber();

	Debug(num1, num2);

	cout << "\tnum1 * number = " << num1 * number << endl;
	cout << "\tnumber * num2 = " << number * num2 << endl;
	cout << "\tnum1 * num2 = " << num1 * num2 << endl;

	Pause();
}
void Menu_4(Complex& num1, Complex& num2)
{
	double number = CreateNumber();

	Debug(num1, num2);

	num1 -= number;
	cout << "\tnum1 -= number : num1 = " << num1 << endl;
	num2 -= num1;
	cout << "\tnum2 -= num1 : num2 = " << num2 << endl;

	Pause();
}
void Menu_5(Complex& num1, Complex& num2)
{
	double number = CreateNumber();

	Debug(num1, num2);

	num1.Pow(number);
	cout << "\tnum1 в степени " << number << " : num1 = " << num1 << endl;
	num2.Pow(-number);
	cout << "\tnum2 в степени -" << number << " : num2 = " << num2 << endl;

	Pause();
}
void Menu_6(const Complex& num1, const Complex& num2)
{
	Debug(num1, num2);

	cout << "\tnum1 >= num2 : " << (num1 >= num2 ? "Да" : "Нет") << endl;

	Pause();
}
void Menu_7(Complex& num1, Complex& num2)
{
	num1.SetIsAllSignsVisible(!num1.GetIsAllSignsVisible());
	num2.SetIsAllSignsVisible(!num2.GetIsAllSignsVisible());
}

#pragma endregion

int main()
{
	setlocale(LC_ALL, "Russian");

	Complex num1, num2;

	char menu = ' ';
	while (menu != '0')
	{
		Clear();
		Debug(num1, num2);
		cout << "\t\tМеню" << endl;;
		cout << "\t[1] : Ввод" << endl;
		cout << "\t[2] : Сумма" << endl;
		cout << "\t[3] : Умножение" << endl;
		cout << "\t[4] : Уменьшение" << endl;
		cout << "\t[5] : Возведение в степень" << endl;
		cout << "\t[6] : Сравнение" << endl;
		cout << "\t[7] : Показать/Убрать скрытые знаки" << endl;
		cout << "\t[0] : Выход" << endl;
		cout << endl;
		cout << "\t\t[0-6] : ";
		
		menu = getchar();

		Clear();
		switch (menu)
		{
		case '1':
			Menu_1(num1, num2);
			break;
		case '2':
			Menu_2(num1, num2);
			break;
		case '3':
			Menu_3(num1, num2);
			break;
		case '4':
			Menu_4(num1, num2);
			break;
		case '5':
			Menu_5(num1, num2);
			break;
		case '6':
			Menu_6(num1, num2);
			break;
		case '7':
			Menu_7(num1, num2);
			break;
		}
	}

	return 0;
}