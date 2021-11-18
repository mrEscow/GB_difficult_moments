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