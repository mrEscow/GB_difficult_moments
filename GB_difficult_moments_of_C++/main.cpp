/*
*	  mr.Escow
* * * * * * * * * *

1.
	Создайте структуру Person с 3 полями: фамилия, имя, отчество. 
	Поле отчество должно быть опционального типа, т.к. не у всех людей есть отчество. 
	Перегрузите оператор вывода данных для этой структуры. 
	Также перегрузите операторы < и == (используйте tie).

2.
	Создайте структуру PhoneNumber с 4 полями:
	·         код страны (целое число)
	·         код города (целое число)
	·         номер (строка)
	·         добавочный номер (целое число, опциональный тип)
	Для этой структуры перегрузите оператор вывода.  
	Необходимо, чтобы номер телефона выводился в формате: +7(911)1234567 12, где 
	7 – это номер страны, 
	911 – номер города, 
	1234567 – номер, 
	12 – добавочный номер. 
	Если добавочного номера нет, то его выводить не надо.  
	Также перегрузите операторы < и == (используйте tie)

3.
	Создайте класс PhoneBook, который будет в контейнере хранить пары: Человек – Номер телефона. 
	Конструктор этого класса должен принимать параметр типа ifstream – поток данных, полученных из файла. 
	В теле конструктора происходит считывание данных из файла и заполнение контейнера. 
	Класс PhoneBook должен содержать перегруженный оператор вывода, для вывода всех данных из контейнера в консоль.
	В классе PhoneBook реализуйте метод SortByName, который должен сортировать элементы контейнера по фамилии людей в алфавитном порядке. 
	Если фамилии будут одинаковыми, то сортировка должна выполняться по именам, если имена будут одинаковы, то сортировка производится по отчествам. 
	Используйте алгоритмическую функцию sort.

	Реализуйте метод SortByPhone, который должен сортировать элементы контейнера по номерам телефонов. 
	Используйте алгоритмическую функцию sort.

	Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает кортеж из строки и PhoneNumber. 
	Строка должна быть пустой, если найден ровно один человек с заданном фамилией в списке. 
	Если не найден ни один человек с заданной фамилией, то в строке должна быть запись «not found», 
	если было найдено больше одного человека, то в строке должно быть «found more than 1».

	Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и, 
	если находит заданного человека в контейнере, то меняет его номер телефона на новый, иначе ничего не делает.

*/


//Создайте структуру Person с 3 полями: фамилия, имя, отчество.
//Поле отчество должно быть опционального типа, т.к.не у всех людей есть отчество.
//Перегрузите оператор вывода данных для этой структуры.
//Также перегрузите операторы < и == (используйте tie).

#include <iostream>
#include <optional>

struct Person
{
private:
	std::string m_F;
	std::string m_I;
	std::optional<std::string> m_O;
public:
	 Person(std::string F, std::string I)
		:
		m_F(F), m_I(I)
	{}
	 Person(std::string F, std::string I, std::string O)
		 :
		 m_F(F), m_I(I), m_O(O)
	 {}

	 friend std::ostream& operator << (std::ostream& out, const Person& person)
	 {
		 if (person.m_O.has_value())
			 out << "Person: " << person.m_F << "\t" << person.m_I << "\t" << person.m_O.value();
		 else
			 out << "Person: " << person.m_F << "\t" << person.m_I;
		 return out;
	 }

	 friend bool operator < (const Person& R_person, const Person& L_person) {
		 if (R_person.m_O.has_value() && L_person.m_O.has_value())
			 return tie(R_person.m_F, R_person.m_I, R_person.m_O.value()) <
					tie(L_person.m_F, L_person.m_I, L_person.m_O.value());
		 else
			 return tie(R_person.m_F, R_person.m_I) <
					tie(L_person.m_F, L_person.m_I);
	 }

	 friend bool operator == (const Person& R_person, const Person& L_person) {
		 if (R_person.m_O.has_value() && L_person.m_O.has_value())
			 return tie(R_person.m_F, R_person.m_I, R_person.m_O.value()) ==
			 tie(L_person.m_F, L_person.m_I, L_person.m_O.value());
		 else
			 return tie(R_person.m_F, R_person.m_I) ==
			 tie(L_person.m_F, L_person.m_I);
	 }
};



int main() {


	std::cout << std::boolalpha;  // true and false =)


	Person person0{ "Petrov","Vasia"};
	Person person1{ "Ivanov","Maksim","Evgenievich"};

	std::cout << person0 << std::endl;
	std::cout << person1 << std::endl;

	std::cout << (person0 < person1) << std::endl;
	std::cout << (person1 < person0) << std::endl;

	std::cout << (person0 == person1) << std::endl;
	std::cout << (person0 == person0) << std::endl;

	return 0;
}