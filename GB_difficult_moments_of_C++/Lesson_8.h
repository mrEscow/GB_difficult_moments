#pragma once
/*
* 	mr.Escow - Lesson-8
* * * * * * * * * * * * * * * */
#include "Header.h"
//-------------------------------------------------------------------------------------------
#include "MyNameSpace.h"
using namespace my;
//-------------------------------------------------------------------------------------------
//	1.Установить фреймворк Google Test.	OK
#include "gtest/gtest.h"
//-------------------------------------------------------------------------------------------
//	2.Добавить unit-тесты в проект домашнего задания из первого урока. OK
class TestPhoneBook : public testing::Test {
protected:
    void SetUp() override {

        std::ifstream file("PhoneBook.txt");
        PB = new PhoneBook(file);
    }
    void TearDown() override {
        delete PB;
    }
    PhoneBook* PB;
};
TEST_F(TestPhoneBook, GetPhoneNumber) {

    PhoneNumber number{ 7, 366, "7508887", std::nullopt };
    std::pair<std::string, PhoneNumber> PairTest("", number);

    ASSERT_EQ(PB->GetPhoneNumber("Ivanov"), PairTest); // ==
    ASSERT_NE(PB->GetPhoneNumber("Petrov"), PairTest); // !=

    ASSERT_LT(PB->GetPhoneNumber("Ivanov").second.m_city_code, 916); // <
    ASSERT_LE(PB->GetPhoneNumber("Ivanov").second.m_city_code, 366); // <=
    ASSERT_GT(PB->GetPhoneNumber("Ivanov").second.m_city_code, 350); // >
    ASSERT_GE(PB->GetPhoneNumber("Ivanov").second.m_city_code, 366); // >=

    ASSERT_STREQ(PB->GetPhoneNumber("Ivanov").first.c_str(), ""); // str == str
    ASSERT_STRNE(PB->GetPhoneNumber("Ivanov").first.c_str(), "A"); // str != str

    Str TestString{ "NoT FoUnD" };
    Str TestString2{ "not found" };

    ASSERT_STRCASEEQ(PB->GetPhoneNumber("Petrov").first.c_str(), TestString.c_str()); // str == StR
    ASSERT_STRCASENE(PB->GetPhoneNumber("Petrov").first.c_str(), TestString2.c_str()); // str == str // error

    //ASSERT_THROW(PB->GetPhoneNumber("Ivanov"), exception_type);
    ASSERT_ANY_THROW(PB->GetPhoneNumber("Ivanov")); // has_exception // error
    ASSERT_NO_THROW(PB->GetPhoneNumber("Ivanov")); // !has_exception

}
TEST_F(TestPhoneBook, ChangePhoneNumber) {
    PB->ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", std::nullopt });

    ASSERT_EQ(PB->GetPhoneNumber("Kotov").second.m_country_code, 7);
    ASSERT_EQ(PB->GetPhoneNumber("Kotov").second.m_city_code, 123);
    ASSERT_EQ(PB->GetPhoneNumber("Kotov").second.m_number, "15344458");
    ASSERT_EQ(PB->GetPhoneNumber("Kotov").second.m_extension_number, std::nullopt);

    PB->ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 1, 916, "5555555", 123 });

    ASSERT_EQ(PB->GetPhoneNumber("Kotov").second.m_country_code, 1);
    ASSERT_EQ(PB->GetPhoneNumber("Kotov").second.m_city_code, 916);
    ASSERT_EQ(PB->GetPhoneNumber("Kotov").second.m_number, "5555555");
    ASSERT_EQ(PB->GetPhoneNumber("Kotov").second.m_extension_number, 123);

}
TEST_F(TestPhoneBook, Sort) {

    PB->SortByName();
    cout << PB << endl; // error

    PB->SortByPhone();
    cout << PB << endl; // error
}
int Lesson8() {

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}