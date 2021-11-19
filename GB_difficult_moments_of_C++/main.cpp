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

struct Person
{
private:
	std::string m_F;
	std::string m_I;
	std::optional<std::string> m_O;
public:
	 Person(std::string F, std::string I) : m_F(F), m_I(I)
	 {}
	 Person(std::string F, std::string I, std::string O) : Person(F,I)
	 {
		 m_O = O;
	 }

	 friend std::ostream& operator << (std::ostream& out, const Person& person)
	 {
		 if (person.m_O.has_value())
			 out << "Person: " << person.m_F << "\t" << person.m_I << "\t" << person.m_O.value();
		 else
			 out << "Person: " << person.m_F << "\t" << person.m_I;
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
private:
	unsigned int m_country_code;
	unsigned int m_city_code;
	std::string	m_number;
	std::optional<unsigned int> m_extension_number;
public:
	PhoneNumber(unsigned int country_code,unsigned int city_code,std::string number)
		:
		m_country_code(country_code), m_city_code(city_code), m_number(number)
	{}
	PhoneNumber(unsigned int country_code, unsigned int city_code, std::string number, unsigned int extension_number)
		:
		PhoneNumber(country_code, city_code, number)
	{
		m_extension_number = extension_number;
	}

	friend std::ostream& operator << (std::ostream& out, const PhoneNumber& pn)
	{
		if (pn.m_extension_number.has_value())
			out << "PhoneNumber: " << "+" << pn.m_country_code << "(" << pn.m_city_code << ")" << pn.m_number << "\t" << pn.m_extension_number.value();
		else
			out << "PhoneNumber: " << "+" << pn.m_country_code << "(" << pn.m_city_code << ")" << pn.m_number;
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

	PhoneNumber phoneNumber0{ 7,916,"1234567" };
	PhoneNumber phoneNumber1{ 7,916,"7654321" ,123};

	std::cout << phoneNumber0 << std::endl;
	std::cout << phoneNumber1 << std::endl;

	std::cout << (phoneNumber0 < phoneNumber1) << std::endl;
	std::cout << (phoneNumber1 < phoneNumber0) << std::endl;

	std::cout << (phoneNumber0 == phoneNumber1) << std::endl;
	std::cout << (phoneNumber0 == phoneNumber0) << std::endl;
	
	return 0;
}