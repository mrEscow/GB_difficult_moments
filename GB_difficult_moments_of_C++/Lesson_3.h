#pragma once
/*
* 	mr.Escow - Lesson-3
* * * * * * * * * * * * * * * *
1.
	�������� �������, ����������� � ����� ������ ������������ ����� �������, 
	�������� �������� ����� �������� ��������������� ���� ��� ���������.
2.
	������� �����, �������������� �������. 
	����������� � ��� �����, ����������� ������������ �������.
3.
	����������� ����������� ����� ���������, 
	� ������� �������� ����� ����� ���������������� �� ��������� ����� ����� � ����� for-range-based.

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