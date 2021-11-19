/*
*	  mr.Escow
* * * * * * * * * *

1.
	�������� ��������� Person � 3 ������: �������, ���, ��������. 
	���� �������� ������ ���� ������������� ����, �.�. �� � ���� ����� ���� ��������. 
	����������� �������� ������ ������ ��� ���� ���������. 
	����� ����������� ��������� < � == (����������� tie).

2.
	�������� ��������� PhoneNumber � 4 ������:
	�         ��� ������ (����� �����)
	�         ��� ������ (����� �����)
	�         ����� (������)
	�         ���������� ����� (����� �����, ������������ ���)
	��� ���� ��������� ����������� �������� ������.  
	����������, ����� ����� �������� ��������� � �������: +7(911)1234567 12, ��� 
	7 � ��� ����� ������, 
	911 � ����� ������, 
	1234567 � �����, 
	12 � ���������� �����. 
	���� ����������� ������ ���, �� ��� �������� �� ����.  
	����� ����������� ��������� < � == (����������� tie)

3.
	�������� ����� PhoneBook, ������� ����� � ���������� ������� ����: ������� � ����� ��������. 
	����������� ����� ������ ������ ��������� �������� ���� ifstream � ����� ������, ���������� �� �����. 
	� ���� ������������ ���������� ���������� ������ �� ����� � ���������� ����������. 
	����� PhoneBook ������ ��������� ������������� �������� ������, ��� ������ ���� ������ �� ���������� � �������.
	� ������ PhoneBook ���������� ����� SortByName, ������� ������ ����������� �������� ���������� �� ������� ����� � ���������� �������. 
	���� ������� ����� �����������, �� ���������� ������ ����������� �� ������, ���� ����� ����� ���������, �� ���������� ������������ �� ���������. 
	����������� ��������������� ������� sort.

	���������� ����� SortByPhone, ������� ������ ����������� �������� ���������� �� ������� ���������. 
	����������� ��������������� ������� sort.

	���������� ����� GetPhoneNumber, ������� ��������� ������� ��������, � ���������� ������ �� ������ � PhoneNumber. 
	������ ������ ���� ������, ���� ������ ����� ���� ������� � �������� �������� � ������. 
	���� �� ������ �� ���� ������� � �������� ��������, �� � ������ ������ ���� ������ �not found�, 
	���� ���� ������� ������ ������ ��������, �� � ������ ������ ���� �found more than 1�.

	���������� ����� ChangePhoneNumber, ������� ��������� �������� � ����� ����� �������� �, 
	���� ������� ��������� �������� � ����������, �� ������ ��� ����� �������� �� �����, ����� ������ �� ������.

*/


//�������� ��������� Person � 3 ������: �������, ���, ��������.
//���� �������� ������ ���� ������������� ����, �.�.�� � ���� ����� ���� ��������.
//����������� �������� ������ ������ ��� ���� ���������.
//����� ����������� ��������� < � == (����������� tie).

#include <iostream>
#include <optional>
#include <vector>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

struct Person
{
//private:
	std::string m_F;
	std::string m_I;
	std::optional<std::string> m_O;
//public:
//	 Person(std::string F, std::string I) : m_F(F), m_I(I)
//	 {}
//	 Person(std::string F, std::string I, std::string O) : Person(F,I)
//	 {
//		 m_O = O;
//	 }

	 friend std::ostream& operator << (std::ostream& out, const Person& person)
	 {
		 if (person.m_O.has_value())
			 out << std::setw(12) << person.m_F << std::setw(1) << "" << std::setw(10) << person.m_I << "" << std::setw(15) << person.m_O.value();
		 else
			 out << std::setw(12) << person.m_F << std::setw(1) << "" << std::setw(10) << person.m_I << "" << std::setw(15);
		 return out;
	 }

	 friend bool operator < (const Person& L_person, const Person& R_person) {
		 if (R_person.m_O.has_value() && L_person.m_O.has_value())
			 return tie(L_person.m_F, L_person.m_I, L_person.m_O.value()) <
					tie(R_person.m_F, R_person.m_I, R_person.m_O.value());
		 else
			 return tie(L_person.m_F, L_person.m_I) <
					tie(R_person.m_F, R_person.m_I);
	 }

	 friend bool operator == (const Person& L_person, const Person& R_person) {
		 if (R_person.m_O.has_value() && L_person.m_O.has_value())
			 return tie(L_person.m_F, L_person.m_I, L_person.m_O.value()) ==
					tie(R_person.m_F, R_person.m_I, R_person.m_O.value());
		 else
			 return tie(L_person.m_F, L_person.m_I) ==
					tie(R_person.m_F, R_person.m_I);
	 }
};

//�������� ��������� PhoneNumber � 4 ������:
//�         ��� ������(����� �����)
//�         ��� ������(����� �����)
//�         �����(������)
//�         ���������� �����(����� �����, ������������ ���)
//��� ���� ��������� ����������� �������� ������.
//����������, ����� ����� �������� ��������� � ������� : +7(911)1234567 12, ���
//7 � ��� ����� ������,
//911 � ����� ������,
//1234567 � �����,
//12 � ���������� �����.
//���� ����������� ������ ���, �� ��� �������� �� ����.
//����� ����������� ��������� < � == (����������� tie)

struct PhoneNumber
{
//private:
	unsigned int m_country_code;
	unsigned int m_city_code;
	std::string	m_number;
	std::optional<unsigned int> m_extension_number;
//public:
//	PhoneNumber(unsigned int country_code,unsigned int city_code,std::string number)
//		:
//		m_country_code(country_code), m_city_code(city_code), m_number(number)
//	{}
//	PhoneNumber(unsigned int country_code, unsigned int city_code, std::string number, unsigned int extension_number)
//		:
//		PhoneNumber(country_code, city_code, number)
//	{
//		m_extension_number = extension_number;
//	}

	friend std::ostream& operator << (std::ostream& out, const PhoneNumber& pn)
	{
		if (pn.m_extension_number.has_value())
			out  << "+" << pn.m_country_code << "(" << pn.m_city_code << ")" << pn.m_number << "  " << pn.m_extension_number.value();
		else
			out  << "+" << pn.m_country_code << "(" << pn.m_city_code << ")" << pn.m_number;
		return out;
	}

	friend bool operator < (const PhoneNumber& L_pn, const PhoneNumber& R_pn) {
		if (L_pn.m_extension_number.has_value() && R_pn.m_extension_number.has_value())
			return tie(L_pn.m_country_code, L_pn.m_city_code, L_pn.m_number, L_pn.m_extension_number.value()) <
					tie(R_pn.m_country_code, R_pn.m_city_code, R_pn.m_number, R_pn.m_extension_number.value());
		else
			return tie(L_pn.m_country_code, L_pn.m_city_code, L_pn.m_number) <
					tie(R_pn.m_country_code, R_pn.m_city_code, R_pn.m_number);
	}

	friend bool operator == (const PhoneNumber& L_pn, const PhoneNumber& R_pn) {
		if (L_pn.m_extension_number.has_value() && R_pn.m_extension_number.has_value())
			return tie(L_pn.m_country_code, L_pn.m_city_code, L_pn.m_number, L_pn.m_extension_number.value()) ==
					tie(R_pn.m_country_code, R_pn.m_city_code, R_pn.m_number, R_pn.m_extension_number.value());
		else
			return tie(L_pn.m_country_code, L_pn.m_city_code, L_pn.m_number) ==
					tie(R_pn.m_country_code, R_pn.m_city_code, R_pn.m_number);
	}
};

//�������� ����� PhoneBook, ������� ����� � ���������� ������� ���� : ������� � ����� ��������.
//����������� ����� ������ ������ ��������� �������� ���� ifstream � ����� ������, ���������� �� �����.
//� ���� ������������ ���������� ���������� ������ �� ����� � ���������� ����������.
//����� PhoneBook ������ ��������� ������������� �������� ������, ��� ������ ���� ������ �� ���������� � �������.
// 
//� ������ PhoneBook ���������� ����� SortByName, ������� ������ ����������� �������� ���������� �� ������� ����� � ���������� �������.
//���� ������� ����� �����������, �� ���������� ������ ����������� �� ������, ���� ����� ����� ���������, �� ���������� ������������ �� ���������.
//����������� ��������������� ������� sort.
//
//���������� ����� SortByPhone, ������� ������ ����������� �������� ���������� �� ������� ���������.
//����������� ��������������� ������� sort.
//
//���������� ����� GetPhoneNumber, ������� ��������� ������� ��������, � ���������� ������ �� ������ � PhoneNumber.
//������ ������ ���� ������, ���� ������ ����� ���� ������� � �������� �������� � ������.
//���� �� ������ �� ���� ������� � �������� ��������, �� � ������ ������ ���� ������ �not found�,
//���� ���� ������� ������ ������ ��������, �� � ������ ������ ���� �found more than 1�.
//
//���������� ����� ChangePhoneNumber, ������� ��������� �������� � ����� ����� �������� �,
//���� ������� ��������� �������� � ����������, �� ������ ��� ����� �������� �� �����, ����� ������ �� ������.

class PhoneBook {
private:
	std::vector<std::pair<Person, PhoneNumber>> m_vec_phone_book;
public:
	PhoneBook(std::ifstream& file) {				
		if (file.is_open())
		{
			std::string str;
			std::istringstream ist;
			unsigned int n;
			Person p;
			PhoneNumber f;
			int count{ 0 };
			bool is_person{ 0 };
			bool is_phone_number{ 0 };
			
			while (!file.eof()) {
				str = "";
				ist.clear();
				if (count <= 6) {
					switch (count)
					{
					case 0:
						file >> p.m_F;
						break;
					case 1:
						file >> p.m_I;
						break;
					case 2:
						file >> str;
						if (str != "-")
							 p.m_O = std::make_optional(str);
						is_person = true;
						break;
					case 3:
						file >> f.m_country_code;
						break;
					case 4:
						file >> f.m_city_code;
						break;
					case 5:
						file >> f.m_number;
						break;
					case 6:
						file >> str;						
						if (str != "-") {
							ist.str(str);
							ist >> n;
							f.m_extension_number = std::make_optional(n);
						}																											
						is_phone_number = true;
						break;
					default:
						break;
					}										
				}
				count++;
				if (is_person && is_phone_number) {
					m_vec_phone_book.push_back(std::pair<Person, PhoneNumber>(p, f));
					is_person =  false;
					is_phone_number = false;
					count = 0;
					p.m_O.reset();
					f.m_extension_number.reset();
				}							
			}			
		}
		file.close();
	}

	friend void operator << (std::ostream& out,const PhoneBook& phone_book) {
		for (auto& [p, f] : phone_book.m_vec_phone_book)
			 std::cout << p << "\t" << f << std::endl;
	}

	void SortByName(){
		std::sort(m_vec_phone_book.begin(), m_vec_phone_book.end(),
			[&] (const std::pair<Person, PhoneNumber>& L, const std::pair<Person, PhoneNumber>& R) {
			return L.first < R.first;
		});
	};

	void SortByPhone() {
		std::sort(m_vec_phone_book.begin(), m_vec_phone_book.end(),
			[&](const std::pair<Person, PhoneNumber>& L, const std::pair<Person, PhoneNumber>& R) {
				return L.second < R.second;
			});
	};
};

int main() {

	std::cout << std::boolalpha;  // true and false =)

	std::ifstream file("PhoneBook.txt");
	
	PhoneBook book(file);

	std::cout << book;

	std::cout << "------SortByPhone-------" << std::endl;
	book.SortByPhone();
	std::cout << book;

	std::cout << "------SortByName--------" << std::endl;
	book.SortByName();
	std::cout << book;



	//Person person0{ "Petrov","Vasia"};
	//Person person1{ "Ivanov","Maksim","Evgenievich"};

	//std::cout << person0 << std::endl;
	//std::cout << person1 << std::endl;

	//std::cout << (person0 < person1) << std::endl;
	//std::cout << (person1 < person0) << std::endl;

	//std::cout << (person0 == person1) << std::endl;
	//std::cout << (person0 == person0) << std::endl;

	//PhoneNumber phoneNumber0{ 7,916,"1234567" };
	//PhoneNumber phoneNumber1{ 7,916,"7654321" ,123};

	//std::cout << phoneNumber0 << std::endl;
	//std::cout << phoneNumber1 << std::endl;

	//std::cout << (phoneNumber0 < phoneNumber1) << std::endl;
	//std::cout << (phoneNumber1 < phoneNumber0) << std::endl;

	//std::cout << (phoneNumber0 == phoneNumber1) << std::endl;
	//std::cout << (phoneNumber0 == phoneNumber0) << std::endl;
	
	return 0;
}