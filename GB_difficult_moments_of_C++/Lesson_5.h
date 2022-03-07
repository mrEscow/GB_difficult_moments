#pragma once
/*
* 	mr.Escow - Lesson-5
* * * * * * * * * * * * * * * */
#include "Header.h"
//-------------------------------------------------------------------------------------------
/*
	1.Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов, 
	и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его надо один раз). 
	Продемонстрировать работу функции, передав итераторы различных типов.
*/
//-------------------------------------------------------------------------------------------
template<typename IT>
void PrintUniqueStr(IT begin, IT end) {
	std::set<std::string> myset;
	for (; begin != end; ++begin) {
		myset.insert(*begin);
	}
	for (auto& str : myset) {
		std::cout << str << std::endl;
	}
}
//-------------------------------------------------------------------------------------------
/*
	2.Используя ассоциативный контейнер, напишите программу, 
	которая будет считывать данные введенные пользователем из стандартного потока ввода и разбивать их на предложения. 
	программа должна вывести пользователю все предложения, отсортировав их по длине.
*/
//-------------------------------------------------------------------------------------------
void SortUserData() {
	std::string UserData;
	std::string newData;
	std::multimap<size_t, std::string> mymultimap;

	getline(std::cin, UserData);

	newData.resize(UserData.size());
	size_t count{ 0 };

	for (size_t i = 0; i < UserData.size(); ++i)
	{
		newData[count++] = UserData[i];
		if (UserData[i] == '.' || UserData[i] == '!') {
			newData.resize(count);
			mymultimap.insert(std::pair<const size_t, std::string>(++count, newData));
			newData.clear();
			newData.resize(UserData.size());
			count = 0;
		}
	}
	for (auto& mp : mymultimap) std::cout << mp.first << " : " << mp .second << std::endl;
}
//-------------------------------------------------------------------------------------------
int Lesson5() {

	std::vector<std::string> freqs;
	std::ifstream fs("War and peace.txt");
	std::string text;
	while (fs >> text) 
		freqs.push_back(text);
	

	PrintUniqueStr(freqs.begin(), freqs.begin() + 20);

	std::cout << "---------------------\n";

	SortUserData();

	

	return 0;
}
//-------------------------------------------------------------------------------------------