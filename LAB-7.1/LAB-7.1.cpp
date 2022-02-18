// LAB-7.1.cpp
// Сушинський Ігор
// Лабораторна робота №7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 18

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Random(int** x, const int rowCount, const int colCount, const int Min, const int Max); // Прототип ф-ї
void Print(int** x, const int rowCount, const int colCount); // Прототип ф-ї
void Replace(int** x, const int row1, const int row2, const int colCount); // Прототип ф-ї
void Calc(int** x, const int rowCount, const int colCount, int& S, int& k); // Прототип ф-ї

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	srand((unsigned)time(NULL));

	int Min = -12;
	int Max = 23;

	int rowCount = 7;
	int colCount = 6;

	int** x = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		x[i] = new int[colCount];

	Random(x, rowCount, colCount, Min, Max);
	Print(x, rowCount, colCount);
	Print(x, rowCount, colCount);

	int S = 0;
	int k = 0;

	Calc(x, rowCount, colCount, S, k);
	cout << "Сума = " << S << endl;
	cout << "Кiлькiсть = " << k << endl;
	Print(x, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] x[i];
	delete[] x;

	return 0;
}

void Random(int** x, const int rowCount, const int colCount, const int Min, const int Max) // Генератор рандомних чисел
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			x[i][j] = Min + rand() % (Max - Min + 1);
}

void Print(int** x, const int rowCount, const int colCount) // Форматне виведення
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << x[i][j];
		cout << endl;
	}
	cout << endl;
}

void Replace(int** x, const int row1, const int row2, const int colCount) // Ф-я заміни рядків місцями
{
	int tmp;

	for (int j = 0; j < colCount; j++)
	{
		tmp = x[row1][j];
		x[row1][j] = x[row2][j];
		x[row2][j] = tmp;
	}
}

void Calc(int** x, const int rowCount, const int colCount, int& S, int& k) // Ф-я обчислення суми та к-ті
{
	S = 0;
	k = 0;

	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (x[i][j] % 2 != 0 || !(x[i][j] < 0))
			{
				S += x[i][j];
				k++;
				x[i][j] = 0;
			}
}