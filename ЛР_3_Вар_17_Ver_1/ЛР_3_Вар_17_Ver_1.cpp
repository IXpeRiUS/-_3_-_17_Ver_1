#include <iostream>
#include <time.h>
#include <iomanip>


const int length = 8;
//srand(time(NULL));
using namespace std;
void randMatrix(int a[length][length], int length)//заполнение матрицы рандомнычи числами согласно условию задачи
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == j)
			{
				a[i][j] = 0;
			}
			else if (j == i + 1 || j == i + 2 || j == i + 3)
			{
				a[i][j] = rand() % 10 +1;
			}
			else if (j == i - 1 || j == i -2)
			{
				a[i][j] = rand() % 10 + 1;
			}
			else
			{
				a[i][j] = -1;
			}
		}
	}
}
void zeroMatrix(int x[length][length], int length)//заполнение двумерной матрицы -1
{
	for (int i = 0; i < length + 1; i++)
	{
		for (int j = 0; j < length; j++)
		{
			x[i][j] = -1;
		}
	}
	x[length][length-1] = length - 1;
}
void _0Matrix(int x[length][length], int length)//заполнение двумерной матрицы -1
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			x[i][j] = -1;
		}
	}

}

void zeroMatrix(int x[length], int length)//заполнение одномерного массива -1
{
	for (int i = 0; i < length; i++)
	{
		x[i] = -1;
	}
}
void printMatrix(int a[length][length], int length)//вывод матрицы на экран
{
	cout << "  |  ";
	for (int i = 0; i < length; i++)
	{
		cout << i + 0 << " |" << setw(3);
	}
	cout << endl << "  -----------------------------------------" << endl;
	for (int i = 0; i < length; i++)
		{
		cout << i + 0 << "| ";
		for (int j = 0; j < length; j++)
			{
				if (a[i][j] == -1)
				{
					cout <<setw(3)<<  " -- |";
				}
				else
				{
					cout <<setw(3)<< a[i][j]<<" |";
				}
			}
		cout << endl;
		}
}
void printMatrix(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void tempCopyArray(int a[length][length], int temp_array[length], int x_count) // копирование временной строки для поиска связей в ней с другими точками
{
	for (int i = 0; i < length; i++)
	{
		temp_array[i] = -1;
	}
	for (int j = x_count; j < x_count + 1; j++)
	{
		for (int i = 0; i < length; i++)
		{
			if (a[i][j] != -1)
			{
				temp_array[i] = i;
			}
		}
	}
}

void minimum(int stage[length][length], int x_count, int min[2])
{
	min[0] = 100;
	min[1] = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = x_count; j < x_count+1; j++)
		{
			if (stage[j][i] != -1)
			{
				if (min[0] > stage[j][i])
				{
					min[0] = stage[j][i];
					min[1] = i;
				}
			}
		}
	}
	
}


int main()
{
	setlocale(LC_ALL, "Ru");
	int a[length][length];//массив весов
	int x[length + 1][length];//массив 
	int temp_x[length];
	int temp_search_x;
	cout << "Вариант 17: число вершин 8, 1 связан с 2, 3, 4, ленточная, шириной 5.\n" << endl;
	randMatrix(a, length); //заполнение массива по условию задачи
	printMatrix(a, length); cout << endl; // вывод массива на печать
	zeroMatrix(x, length);// заполнение
	zeroMatrix(temp_x, length);
	int x_count = length - 1;
	temp_search_x = length - 1;
	int count_x = 7;
		///////////////////////////////////////////////////////////  x7
	for (int i = 0; i < length; i++)	//
	{														
		for (int j = 0; j < length; j++)
		{
			if (a[i][j] != -1)
			{
				x[j][i] = i;
			}
		}
	}
	printMatrix(x, 8);
	tempCopyArray(a, temp_x, temp_search_x);
	///////////////x6-0
	do
	{
		do
		{
			temp_search_x != -1;
			for (int i = 0; i < length; i++)
			{
				if (temp_x[i] != -1)
				{
					temp_search_x = temp_x[i];
					temp_x[i] = -1;
				}
				for (int j = temp_search_x; j < temp_search_x + 1; j++)	//
				{														//  x7
					for (int k = 0; k < length; k++)
					{
						if (a[k][j] != -1)
						{
							x[count_x][k] = i;
						}
					}
				}
			}
		} while (temp_search_x == -1);
		tempCopyArray(a, temp_x, count_x);				//
	count_x--;
	} while (count_x > -1);

	printMatrix(x, length);									//
	int f[length][length];
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (a[i][j] != -1)
			{
				f[i][j] = 0;
			}
			else
			{
				f[i][j] = -1;
			}
		}
	}
	int min[2]{ 0,0 };
	int stage[length][length];
	_0Matrix(stage, length);
	int ff[length][2];
	cout << "\nЭтап: " << x_count << "\n\n";
	cout<<setw(3) << "x" << x_count << " |" << "d(x"<< x_count<<", dx"<< x_count + 1<<")" << setw(25)<< "| Оптимальное решение |"<<endl;
	cout << setw(6) << " |" << "x" << x_count + 1 << "=7" << setw(9) << "f" << x_count << "(x" << x_count<<")"<<" | "<<"x" << x_count+1<<"*"<<endl;
	cout << "-----------------------------------------" << endl;
	for (int i = x_count; i < x_count+1; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (a[i][j] != -1)
			{
				stage[j][i] = a[j][i] + f[j][i];
				minimum(stage, j, min);
				cout << setw(4) << j << " | " << a[j][i] << " + " << f[j][i] << " = " << setw(2) << stage[j][i] << " | " << min[0] << setw(5) << "|" << min[1] << setw(5) << "|" << endl;
				ff[x_count][0] = min[0];
				ff[x_count][1] = min[1];
			}
		}
	}
	/// /////////////////////////////////////////////////
	x_count--;
	cout << "\nЭтап: " << x_count << "\n\n";
	cout << setw(3) << "x" << x_count << " |" << "d(x" << x_count << ", dx" << x_count + 1 << ")"<< "+"<< "f"<< x_count+1<<"(x"<< x_count+1<<")" << setw(86) << "| Оптимальное решение |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	tempCopyArray(x, temp_x, x_count);
	cout << setw(6) << " |";
	for (int i = x_count+1; i < x_count+2; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (x[i][j] != -1)
			{
				cout << "x" << x_count << "=" << j << setw(10) << "|";
			}
		}
	}
	cout <<  setw(9) << "f" << x_count << "(x" << x_count << ")" << " | " << "x" << x_count + 1 << "*" << endl;
	
	for (int i = x_count; i < x_count+1; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (x[i][j] != -1)
			{
				cout << x[i][j] << " ";
			}
			cout << endl;
			
		}
	}



























}
