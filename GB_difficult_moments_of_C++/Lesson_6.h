﻿#pragma once
/*
* 	mr.Escow - Lesson-6
* * * * * * * * * * * * * * * */
#include "Header.h"
//-------------------------------------------------------------------------------------------
/*
	1.Создайте потокобезопасную оболочку для объекта cout. 
	Назовите ее pcout. 
	Необходимо, чтобы несколько потоков могли обращаться к pcout и информация выводилась в консоль. 
	Продемонстрируйте работу pcout.
*/
//-------------------------------------------------------------------------------------------
class Pcout : public std::ostringstream
{
public:
	Pcout() = default;

	~Pcout()
	{
		std::lock_guard<std::mutex> guard(m_lock);
		std::cout << this->str();
	}

private:
	static std::mutex m_lock;
};

std::mutex Pcout::m_lock;

void doSomething(int number) {
	Pcout{} << "start thread " << number << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Pcout{} << "stop thread " << number << std::endl;
}

//-------------------------------------------------------------------------------------------
/*
	2.Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое число равно 15485863). 
	Вычисления реализовать во вторичном потоке. В консоли отображать прогресс вычисления. 
*/
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
/*
	3.Промоделировать следующую ситуацию. 
	Есть два человека (2 потока): хозяин и вор. 
	Хозяин приносит домой вещи (функция добавляющая случайное число в вектор с периодичностью 1 раз в секунду). 
	При этом у каждой вещи есть своя ценность. 
	Вор забирает вещи (функция, которая находит наибольшее число и удаляет из вектора с периодичностью 1 раз в 0.5 секунд), 
	каждый раз забирает вещь с наибольшей ценностью. 
*/
//-------------------------------------------------------------------------------------------
int Lesson6() {
	Pcout{} << "--------------\n";
	{
		std::thread th1(doSomething, 1);
		std::thread th2(doSomething, 2);
		std::thread th3(doSomething, 3);
		th1.join();
		th2.join();
		th3.join();
	}
	Pcout{} << "--------------\n";
	{

	}
	Pcout{} << "--------------\n";
	{

	}
	Pcout{} << "--------------\n";
	return 0;
}
//-------------------------------------------------------------------------------------------