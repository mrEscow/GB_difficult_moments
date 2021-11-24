#pragma once
/*
* 	mr.Escow - Lesson-3
* * * * * * * * * * * * * * * */

//	1.Написать функцию, добавляющую в конец списка вещественных чисел элемент,
//	значение которого равно среднему арифметическому всех его элементов.
void push_back_arithmetic_mean(std::list<float> &list) {
	float arithmetic{ 0 };
	for (const auto& l : list) {
		arithmetic += l;
	}
	list.push_back(arithmetic / static_cast<float>(list.size()));
}

//	2.Создать класс, представляющий матрицу.
//	Реализовать в нем метод, вычисляющий определитель матрицы.
class Matrix {
	size_t n;
	int** matrix;
	int determinant;
	void CreateMatrix(size_t n) {

		matrix = new int* [n];
		for (size_t i = 0; i < n; ++i)
			matrix[i] = new int[n];

		srand(time(NULL));

		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				matrix[i][j] = rand() % 10 -5;
			}
		}
	}

	int CreateDeterminant(size_t n, int** matrix) {
		if (n == 1)
			return matrix[0][0];
		else if (n == 2) {
			return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
		}
		else if (n >= 3) {
			int** new_matrix;
			new_matrix = new int* [n - 1];
			for (size_t i = 0; i < n - 1; ++i)
				new_matrix[i] = new int[n - 1];

			int det{ 0 };
			int a, b;

			for (size_t j = 0; j < n; j++) {
				a = 0;
				for (size_t k = 1; k < n; k++) {
					b = 0;
					for (size_t s = 0; s < n; s++)
						if (s != j) {
							new_matrix[a][b] = matrix[k][s];
							b++;
						}
					a++;
				}
				det += std::pow(-1, j + 2) * matrix[0][j] * CreateDeterminant(n - 1, new_matrix);
			}

			for (size_t i = 0; i < n - 1; ++i)
				delete new_matrix[i];
			delete[]new_matrix;

			return det;
		}
	}



public:
	Matrix(size_t n) {
		this->n = n;
		if (n > 0) {			
			CreateMatrix(n);
			determinant = CreateDeterminant(n, matrix);
		}
			
	};

	void Print() {
		if(n > 0)
			for (size_t i = 0; i < n; ++i) {
				for (size_t j = 0; j < n; ++j)
					std::cout << matrix[i][j] << "  ";
				std::cout << "\n";
			}
		
	}

	size_t GetN() {
		return n;
	}

	int** GetMatrix() {
		return matrix;
	}

	int GetDeterminant() {
		return determinant;
	}

	~Matrix() {
		for (size_t i = 0; i < n; ++i)
			delete matrix[i];
		delete[]matrix;
	}
};

//	3.Реализовать собственный класс итератора,
//	с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for - range - based.
class MyIterator {

};

int Lesson3(){

	//std::list<float> list{ 4.5, 5.3, 7.2, 9.0 };

	//push_back_arithmetic_mean(list);

	//for (const auto& l : list) {
	//	std::cout << l << "  ";
	//}
	//std::cout << "\n";

	//Matrix m1(5);
	//m1.Print();
	//std::cout << "Determinant: " << m1.GetDeterminant() << std::endl;

	return 0;
}