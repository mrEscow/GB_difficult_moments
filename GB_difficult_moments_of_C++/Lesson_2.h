#pragma once
/*
*	  mr.Escow - Lesson-2
* * * * * * * * * * * * * * * *

1.
	Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения, 
	на которые указывают эти указатели(нужно обменивать именно сами указатели, переменные должны оставаться в тех же адресах памяти).

2.
	Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и сортирует указатели по значениям, на которые они указывают.

3.
	Подсчитайте количество гласных букв в книге “Война и мир”.Для подсчета используйте 4 способа:
		○  count_if и find
		○  count_if и цикл for
		○  цикл for и find
		○  2 цикла for
	Замерьте время каждого способа подсчета и сделайте выводы.


Справка :
	count_if - это алгоритмическая функция из STL, которая принимает 3 параметра: 
	итератор на начало, итератор на конец и унарный предикат(функцию, принимающую один параметр и возвращающую тип bool).

	find - это метод класса string, который возвращает позицию символа(строки), переданного в качестве параметра, в исходной строке.
	Если символ не найден, то метод возвращает string::npos.
*/


//Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения,
//на которые указывают эти указатели(нужно обменивать именно сами указатели, переменные должны оставаться в тех же адресах памяти).
template<class T>
void Swap(T& lhs, T& rhs) {
	T tmp;
	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

//Реализуйте шаблонную функцию SortPointers, 
//которая принимает вектор указателей и сортирует указатели по значениям, на которые они указывают.
template<class T>
void SortPointers(std::vector<T>& vec) {
	std::sort(vec.begin(), vec.end(), [](const T& lhs, const T& rhs) {
		return *lhs < *rhs;
		});
}



int Lesson2() {
	std::cout << "----------------" << std::endl;
	{
		int a = 10;
		int b = 20;

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		int* ap = &a;
		int* bp = &b;

		std::cout << *ap << std::endl;
		std::cout << *bp << std::endl;

		Swap(ap, bp);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << *ap << std::endl;
		std::cout << *bp << std::endl;
	}
	std::cout << "----------------" << std::endl;
	{
		int a = 10;
		int b = 5;
		int c = 20;
		int d = 0;
		int e = 25;
		int j = -5;
		int k = 35;
		int z = -20;

		int* ap = &a;
		int* bp = &b;
		int* cp = &c;
		int* dp = &d;
		int* ep = &e;
		int* jp = &j;
		int* kp = &z;
		int* zp = &k;

		std::vector<int*> vec;

		vec.push_back(ap);
		vec.push_back(bp);
		vec.push_back(cp);
		vec.push_back(dp);
		vec.push_back(ep);
		vec.push_back(jp);
		vec.push_back(kp);
		vec.push_back(zp);

		for (auto& v : vec)
			std::cout << *v << "  ";
		std::cout << "\n";

		SortPointers(vec);

		for (auto& v : vec)
			std::cout << *v << "  ";
		std::cout << "\n";
	}
	std::cout << "----------------" << std::endl;
	{
		//Подсчитайте количество гласных букв в книге “Война и мир”.Для подсчета используйте 4 способа:
		//○  count_if и find
		//○  count_if и цикл for
		//○  цикл for и find
		//○  2 цикла for
		//Замерьте время каждого способа подсчета и сделайте выводы.
		Timer time;
		std::vector<char> vec_book;
		char ch;
		uint16_t count_glas{ 0 };
		
		time.start("READ FILE ");
		std::ifstream file("War and peace.txt");
		if(file.is_open())
			for (;file;)
			{
				file.get(ch);
				vec_book.push_back(ch);
			}
		file.close();
		time.print();

		// 1
		
		time.start("Test_1");
		count_glas = std::count_if(vec_book.begin(), vec_book.end(), [](char ch) {
			if (ch == 'a' || 'e' || 'i' || 'o' || 'u' || 'y' || 'A' || 'E' || 'I' || 'O' || 'U' || 'Y')
				return true;
			return false;
				
		});
		time.print();
		std::cout << "count i: " << count_glas << std::endl;
		count_glas = 0;

		// 2
		//time.start("Test_2"); 
		//auto is_bool = std::find(vec_book.begin(), vec_book.end(), 'a' || 'e' || 'i' || 'o' || 'u' || 'y' || 'A' || 'E' || 'I' || 'O' || 'U' || 'Y');
		//std::cout << typeid(is_bool).name() << std::endl;
		
		//count_glas = std::count_if(vec_book.begin(), vec_book.end(), [&](char i) {			
		//	auto tmp = std::find(vec_book.begin() + count_glas, vec_book.end(), 'a' || 'e' || 'i' || 'o' || 'u' || 'y' || 'A' || 'E' || 'I' || 'O' || 'U' || 'Y');
		//	count_glas++;
		//	if (tmp == vec_book.end())
		//		return false;
		//	return true;
		//	
		//	});
		//time.print(); 
		//std::cout << "count i: " << count_glas << std::endl;
		//count_glas = 0;

		//3
		time.start("Test_3");
		for(auto& v:vec_book)
			if(v == ('a' || 'e' || 'i' || 'o' || 'u' || 'y' || 'A' || 'E' || 'I' || 'O' || 'U' || 'Y'))
				count_glas++;
		time.print();
		std::cout << "count i: " << count_glas << std::endl;
		count_glas = 0;

		//4
		time.start("Test_4");
		std::for_each(vec_book.begin(), vec_book.end(), [&count_glas](char ch) {
			if (ch == ('a' || 'e' || 'i' || 'o' || 'u' || 'y' || 'A' || 'E' || 'I' || 'O' || 'U' || 'Y')) {				
				count_glas++;
				return true;
			}
			return false;
		});
		time.print();
		std::cout << "count i: " << count_glas << std::endl;
		count_glas = 0;
	}
	std::cout << "----------------" << std::endl;
	{
		Timer time;

		std::vector<std::string> vec_book;
		std::string line;		
		std::string gls = "aeiouyAEIOUY";

		uint16_t count_glas{ 0 };

		time.start("READ FILE ");
		std::ifstream file("War and peace.txt");
		if (file.is_open())
			while(!file.eof())
			{
				std::getline(file, line);
				vec_book.push_back(line);
			}
		file.close();
		time.print();

		//5
		time.start("Test_5");
		for (auto& v : vec_book)
			for (int i = 0; i < v.size(); i++)
				for (int j = 0; j < gls.size(); j++)
					if (i == j)
						count_glas++;
		time.print();
		std::cout << "count i: " << count_glas << std::endl;
		count_glas = 0;

		//6
		time.start("Test_6");
		count_glas = std::count_if(vec_book.begin(), vec_book.end(), [](std::string str) {
			if (str == "a" || "e" || "i" || "o" || "u" || "y" || "A" || "E" || "I" || "O" || "U" || "Y")
				return true;
			return false;

			});
		time.print();
		std::cout << "count i: " << count_glas << std::endl;
		count_glas = 0;
	}
	std::cout << "----------------" << std::endl;
	return 0;
}
