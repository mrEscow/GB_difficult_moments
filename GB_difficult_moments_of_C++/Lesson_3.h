#pragma once
/*
* 	mr.Escow - Lesson-3
* * * * * * * * * * * * * * * *
1.
	Ќаписать функцию, добавл€ющую в конец списка вещественных чисел элемент, 
	значение которого равно среднему арифметическому всех его элементов.
2.
	—оздать класс, представл€ющий матрицу. 
	–еализовать в нем метод, вычисл€ющий определитель матрицы.
3.
	–еализовать собственный класс итератора, 
	с помощью которого можно будет проитерироватьс€ по диапазону целых чисел в цикле for-range-based.

*/

void push_back_arithmetic_mean(std::list<float> &list) {
	float arithmetic_mean{ 0 };
	for (const auto& l : list) {
		arithmetic_mean += l;
	}
	list.push_back(arithmetic_mean / static_cast<float>(list.size()));
}

int Lesson3(){

	std::list<float> list{ 4.5, 5.3, 7.2, 9.0 };

	push_back_arithmetic_mean(list);

	for (const auto& l : list) {
		std::cout << l << "  ";
	}
	std::cout << "\n";

	return 0;
}