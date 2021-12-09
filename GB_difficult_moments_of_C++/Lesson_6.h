#pragma once
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

//Функция делает что то
void DoSomething(int number) {
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

//Функция проверяет простое ли число
//void IsPrime(const uint64_t &val,bool &test)
bool IsPrime(const uint64_t& val)
{
	uint64_t i1, i2, i3, i4, i5, i6, i7, i8, bound;

	if (val == 0 || val == 1)
		//test = false;
		return false;

	if (val == 2 ||
		val == 3 ||
		val == 5 ||
		val == 7 ||
		val == 11 ||
		val == 13 ||
		val == 17 ||
		val == 19 ||
		val == 23 ||
		val == 29)
		//test = true;
		return true;

	if (val % 2 == 0 ||
		val % 3 == 0 ||
		val % 5 == 0 ||
		val % 7 == 0 ||
		val % 11 == 0 ||
		val % 13 == 0 ||
		val % 17 == 0 ||
		val % 19 == 0 ||
		val % 23 == 0 ||
		val % 29 == 0)
		//test = false;
		return false;

	bound = sqrt(static_cast<double>(val));

	i1 = 31; i2 = 37; i3 = 41; i4 = 43; i5 = 47; i6 = 49; i7 = 53; i8 = 59;

	while (i8 <= bound && val % i1 && val % i2 && val % i3 && val % i4 && val % i5 && val % i6 && val % i7 && val % i8)
	{
		i1 += 30; i2 += 30; i3 += 30; i4 += 30; i5 += 30; i6 += 30; i7 += 30; i8 += 30;
	}

	if (i8 <= bound ||
		i1 <= bound && val % i1 == 0 ||
		i2 <= bound && val % i2 == 0 ||
		i3 <= bound && val % i3 == 0 ||
		i4 <= bound && val % i4 == 0 ||
		i5 <= bound && val % i5 == 0 ||
		i6 <= bound && val % i6 == 0 ||
		i7 <= bound && val % i7 == 0)
		//test = false;
		return false;
	//test = true;
	return true;
}
//Функцию, возвращающая i-ое простое число
uint64_t GetPrimeNumber(uint64_t& num)
{
	register uint16_t ProgressCount{ 0 };

	register uint32_t Index;

	register uint64_t PrimeNumber{ 0 };
	
	for (Index = 0; Index <= num; )
	{
		if (IsPrime(PrimeNumber++))
			Index++;

		if (Index == 0)
		{
			system("cls");
			Pcout{} << "Progress:  " << ProgressCount << "%\n";
			Pcout{} << "Index:  " << Index << "%\n";
		}

		if (ProgressCount != 100 && Index == num / (100 - ProgressCount)) {
			system("cls");
			Pcout{} << "Progress:  " << ProgressCount << "%\n";
			ProgressCount++;
		}

		if (ProgressCount == 100)
		{
			PrimeNumber--;
			system("cls");
			Pcout{} << "Progress:  " << ProgressCount << "%\n";
			break;
		}
	}

		num = PrimeNumber;
	return PrimeNumber;
}
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

std::vector<int> G_VECTOR_SACHEN;
//Функция добавляющая случайное число в вектор с периодичностью 1 раз в секунду
void PUSH_RAND_INT(const bool& stop)
{
	while (!stop)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));

		uint32_t RandUint = rand() % 1'0000'000;
		G_VECTOR_SACHEN.push_back(RandUint);

		std::cout << "PUSH:  " << RandUint << "\n";
	}

}
//функция, которая находит наибольшее число и удаляет из вектора с периодичностью 1 раз в 0.5 секунд
void POP_MAX_INT(const bool& stop)
{
	while (!stop)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		if (!G_VECTOR_SACHEN.empty())
		{
			std::sort(G_VECTOR_SACHEN.begin(), G_VECTOR_SACHEN.end());

			std::cout << "POP:  " << G_VECTOR_SACHEN.back() << "\n";

			G_VECTOR_SACHEN.pop_back();
		}
	}

}
//-------------------------------------------------------------------------------------------
int Lesson6() {
	Pcout{} << "--------------\n";
	{
		std::thread Thread1(DoSomething, 1);
		std::thread Thread2(DoSomething, 2);
		std::thread Thread3(DoSomething, 3);
		Thread1.join();
		Thread2.join();
		Thread3.join();
	}
	Pcout{} << "--------------\n";
	{
		uint64_t RESULT{ 1'000'000 };

		std::thread Thread(GetPrimeNumber, std::ref(RESULT));

		Thread.join();

		Pcout{} << "RESULT:\t" << RESULT << std::endl;
	}
	Pcout{} << "--------------\n";
	{
		bool Stop{false};

		std::thread WhiteMaster(PUSH_RAND_INT, std::ref(Stop));
		WhiteMaster.detach();

		std::thread BlackPilferer(POP_MAX_INT, std::ref(Stop));
		BlackPilferer.detach();

		std::cin >> Stop;

	}
	Pcout{} << "--------------\n";
	return 0;
}
//-------------------------------------------------------------------------------------------