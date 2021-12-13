#pragma once
/*
* 	mr.Escow - Lesson-7
* * * * * * * * * * * * * * * */
#include "Header.h"
//-------------------------------------------------------------------------------------------
#include "MyNameSpace.h"
using namespace my;
//-------------------------------------------------------------------------------------------
namespace {
	my::Int32 i = 100;
	void f() {
		my::cout << i << my::endl;
	}
}
//-------------------------------------------------------------------------------------------
//	1.Установить библиотеку protobuf. // OK
//-------------------------------------------------------------------------------------------
#include "car.pb.h"
//-------------------------------------------------------------------------------------------
//	2.С помощью компилятора protobuf в отдельном пространстве имен сгенерировать классы
//		a.FullName с полями имя, фамилия, отчество(отчество опционально).
//		b.Student с полями полное имя, массив оценок, средний балл.
//		c.StudentsGroup с полем массив студентов. // OK
//-------------------------------------------------------------------------------------------
#include "proto/Students.pb.h"
//-------------------------------------------------------------------------------------------
//	3.Создать класс StudentsGroup, который реализует интерфейсы :
//-------------------------------------------------------------------------------------------
class IRepository {
	virtual void Open() = 0; // бинарная десериализация в файл
	virtual void Save() = 0; // бинарная сериализация в файл
};
class IMethods {
	virtual double GetAverageScore(const Students::FuLLName& name) = 0;
	virtual std::string GetAllInfo(const Students::FuLLName& name) = 0;
	virtual std::string GetAllInfo() = 0;
};
//-------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
class StudentsGroup : private IRepository, private IMethods{

	STL::map < Uint32, Students::StudentGroup> map_SG;

	Str PathToFios{ "bin//fios//" };
	Str PathToStudents{ "bin//students//" };
	Str PathToGroups{ "bin//groups//" };

	Uint32 CountFileInDir(Str Path);

public:
	StudentsGroup();

	virtual void Open() override;

	virtual void Save() override;

	virtual double GetAverageScore(const Students::FuLLName& name);

	virtual std::string GetAllInfo(const Students::FuLLName& name);

	virtual std::string GetAllInfo();
};

// GO Lesson_7.cpp
int Lesson7();