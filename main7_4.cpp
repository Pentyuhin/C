#include <iostream>

#include <windows.h>

using namespace std;

const int m = 2;
const int n = 2;
const int r = 2;

void first_matrix(int arr[][n], int m, int n);
void second_matrix(int arr[][r], int n, int r);
void multiply_matrices(int mat1[][n], int mat2[][r], int result[][r]);


void print_matrix(int arr[][n], int rows, int cols);
void print_array_one(int arr[m][n]);
void print_array_two(int arr[n][r]);
void print_result(int arr[m][r]);

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int array_one[m][n] = {0};
	int array_two[n][r] = {0};
	int result[m][r] = {0};

	cout << "Введите первую матрицу (размер " << m << "x" << n << "):\n";

	first_matrix(array_one, m, n);

	cout << "Введите вторую матрицу (размер " << n << "x" << r << "):\n";

	second_matrix(array_two, n, r);
	
	multiply_matrices(array_one, array_two, result);

	print_array_one(array_one);
	
	print_array_two(array_two);
	
	print_result(result);
	
	
	return 0;
}

void first_matrix(int arr[][n], int m, int n)
{
	for (int row = 0; row < m; row++)
	{
		cout << "Введите " << n << " значения для " << row + 1 << "-й строки (через пробелы): ";

		for (int column = 0; column < n; column++)
		{
			cin >> arr[row][column];

		}

	}
}


void second_matrix(int arr[][r], int n, int r)
{
	for (int row = 0; row < n; row++)
	{
		cout << "Введите " << r << " значения для " << row + 1 << "-й строки (через пробелы): ";

		for (int column = 0; column < r; column++)
		{
			cin >> arr[row][column];
		}
	}

}


void multiply_matrices(int mat1[][n], int mat2[][r], int result[][r]) 
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < r; j++) {
			result[i][j] = 0;
			for (int k = 0; k < n; k++) {
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}


void print_matrix(int arr[][n], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void print_array_one(int arr[m][n]) {
	cout << "Первая матрица:\n";
	print_matrix(arr, m, n);
	cout << endl;
}

void print_array_two(int arr[n][r]) {
	cout << "УМНОЖИТЬ\n\n";
	cout << "Вторая матрица:\n";
	print_matrix(arr, n, r);
	cout << endl;
}

void print_result(int arr[m][r]) {
	cout << "Результат умножения матриц:\n";
	print_matrix(arr, m, r);
}