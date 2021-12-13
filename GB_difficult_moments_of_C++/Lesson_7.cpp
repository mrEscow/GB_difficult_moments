#pragma once
#include "Lesson_7.h"
#include <windows.h>

my::STL::vector<Students::FuLLName> g_Fio;
my::STL::vector<Students::Student> g_Students;
my::STL::vector<Students::StudentGroup> g_Grups;

Uint32 StudentsGroup::CountFileInDir(Str Path) {

	Path += "*bin";
    STD::wstring wide_string = STD::wstring(Path.begin(), Path.end());
    const wchar_t* filePath = wide_string.c_str();
	STD::wcout << filePath << endl;
    WIN32_FIND_DATAW wfd;
    HANDLE hFind = FindFirstFileW(filePath, &wfd);

    Uint32 CountFile{ 0 };
    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
            CountFile++;
        } while (NULL != FindNextFileW(hFind, &wfd));
        FindClose(hFind);
    }
    return CountFile;
}

StudentsGroup::StudentsGroup()
{

}

void StudentsGroup::Open()
{
	Uint32 CountBinFiles = CountFileInDir(PathToGroups);

	cout << "CountBinFiles: " << CountBinFiles << endl;

	for (Uint32 i = 0; i < CountBinFiles; i++)
	{
		STL::pair<Uint32,Students::StudentGroup> Pair;
		Pair.first = i;
		STD::ifstream TakeFile(PathToGroups + "Group_" + STD::to_string(i) + ".bin", STD::ios_base::binary);
		if (Pair.second.ParseFromIstream(&TakeFile)) 
			map_SG.insert(Pair);
		else
			cout << "Error!" << endl;
	}
}

void StudentsGroup::Save()
{
	for (auto [key,val] : map_SG) {
		STD::ofstream NewBitStudents(PathToGroups + "Group_" + STD::to_string(key) + ".bin", STD::ios_base::binary);
		val.SerializeToOstream(&NewBitStudents);
	}
}

double StudentsGroup::GetAverageScore(const Students::FuLLName& name)
{
	for (auto [key, val] : map_SG) {
		for (auto St : val.studs()) {
			if (ALG::tie(St.fio().name(), St.fio().surname(), St.fio().surname()) ==
				ALG::tie(name.name(), name.surname(), name.surname())) {
				return St.averagescore();
			}
		}
	}
	return 0.0;
}

std::string StudentsGroup::GetAllInfo(const Students::FuLLName& name)
{
	for (auto [key, val] : map_SG) {
		for (auto St : val.studs()) {
			if (ALG::tie(St.fio().name(), St.fio().surname(), St.fio().surname()) ==
				ALG::tie(name.name(), name.surname(), name.surname())) {

				return	"\n-----------------------\nGroup#" + STD::to_string(key) +
						"\n-----------------------\nFIO:\nName:\t\t" + 
						St.fio().name() + "\n" +
						"Surname:\t" + St.fio().surname() + "\n" +
						"Patronymic:\t" + St.fio().patronymic() + "\n" +
						"Count score:\t" + STD::to_string(St.evaluations().size()) + "\n" +
						"Average score:\t" + STD::to_string(St.averagescore()) +
						"\n-----------------------\n";
			}
		}
	}
	return "Not faund Student!";
}

std::string StudentsGroup::GetAllInfo()
{
	Str AllStudents{ 0 };
	for (auto [key, val] : map_SG) {
		for (auto St : val.studs()) {

				AllStudents += "Group#"+ STD::to_string(key) + 
				"\n-----------------------\nFIO:\nName:\t\t" +
				St.fio().name() + "\n" +
				"Surname:\t" + St.fio().surname() + "\n" +
				"Patronymic:\t" + St.fio().patronymic() + "\n" +
				"Count score:\t" + STD::to_string(St.evaluations().size()) + "\n" +
				"Average score:\t" + STD::to_string(St.averagescore()) +
				"\n-----------------------\n";
			
		}
	}
	return AllStudents;
}
//-------------------------------------------------------------------------------------------
namespace SD {

	using namespace my;

	using std::ios;
	using std::ofstream;
	using std::ifstream;

	void Serialize(Str Path, Str Data) {
		ofstream Out(Path, ios::binary);
		Out.write(Data.c_str(), Data.size());
	}

	void Deserialize(Str Path, Str& Result) {
		ifstream In(Path, ios::binary);
		Result.resize(1024);
		In.read(Result.data(), Result.size());
		Result.resize(In.gcount());
	}

	void Serialize(Str Path, Int32 Data) {
		ofstream Out(Path, ios::binary);
		Out.write(reinterpret_cast<char*>(&Data), sizeof(Data));
	}

	void Deserialize(Str Path, Int32& Result) {
		ifstream In(Path, ios::binary);
		In.read(reinterpret_cast<char*>(&Result), sizeof(Result));
	}

	void Serialize(Str Path, double Data) {
		ofstream Out(Path, ios::binary);
		Out.write(reinterpret_cast<char*>(&Data), sizeof(Data));
	}

	void Deserialize(Str Path, double& Result) {
		ifstream In(Path, ios::binary);
		In.read(reinterpret_cast<char*>(&Result), sizeof(Result));
	}
}
//-------------------------------------------------------------------------------------------
void Main();
int Lesson7() {

	{
		my::Str String{ "HELLO WORLD!" };
	}

	{
		my::cout << my::PRL::This::get_id() << my::endl;
		my::PRL::thread Thread;
	}

	{
		my::Int32 i = 2'000'000'000;
	}

	{
		using namespace my;

		STL::set<Int64> my_set{ 1,2 };

		ALG::for_each(my_set.begin(), my_set.end(),
			[](Int64 my_Int) {
				STD::cout << my_Int << STD::endl;
			});
	}

	using namespace my;  // STD, STL, ALG, PRL, ADPIT, cout, endl.

	{
		Str NewString{ "HELLO HDD and SSD!" };
	}

	{
		/*
			Conan после установки нужно поменять дирикторию запросов

			// Посмотреть список репозиториев
			conan remote list

			// Удалить старый репозиторий
			conan remote remove conan - center

			// Установить нужный репозиторий и установить ему главный приоритет
			conan remote add conancenter https ://center.conan.io --insert 0

			// Посмотреть список репозиториев
			conan remote list
		*/
	}

	{
		Car car;

		car.set_brand("Bibika");
		car.set_model("SupaPupa");
		car.set_year(2078);

		STD::cout << car.brand() << " " << car.model() << " " << car.year() << "\n";

		STD::ofstream out("car.bin", STD::ios_base::binary);

		car.SerializeToOstream(&out);
	}

	{
		Car car;

		STD::ifstream in("car.bin", STD::ios_base::binary);

		if (car.ParseFromIstream(&in)) {
			cout << car.brand() << " " << car.model() << " " << car.year() << endl;
		}
		else {
			cout << "Error!" << endl;
		}

	}

	{
		Main();
		Students::FuLLName Fio;

		Fio.set_name("Hello0");
		Fio.set_surname("World!0");
		if ((rand() % 2) == 1)
			Fio.set_patronymic("YES0");


		cout << "----------------------" << endl;

		StudentsGroup SGroup;

		SGroup.Open();

		SGroup.Save();
		cout << "----------------------" << endl;
		cout << "AverageScore: " << SGroup.GetAverageScore(Fio) << endl;
		cout << "----------------------" << endl;
		cout << "GetAllInfo(Fio): " << SGroup.GetAllInfo(Fio) << endl;
		cout << "----------------------" << endl;
		cout << "GetAllInfo(): " << SGroup.GetAllInfo() << endl;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------

void Main()
{
	using namespace my;

	Str PathToFios{ "bin//fios//" };
	Str PathToStudents{ "bin//students//" };
	Str PathToGroups{ "bin//groups//" };

	for (Uint32 i = 0; i < 3; i++)
	{
		g_Fio.clear();
		g_Students.clear();

		Students::FuLLName Fio;
		Students::FuLLName TempFio;



		Int Count{ 0 };

		Fio.set_name("Hello" + STD::to_string(i));
		Fio.set_surname("World!" + STD::to_string(i));
		if ((rand() % 2) == 1)
			Fio.set_patronymic("YES" + STD::to_string(i));

		g_Fio.push_back(Fio); 
		Fio.clear_patronymic();

		Fio.set_name("Ivan" + STD::to_string(i));
		Fio.set_surname("Petrov" + STD::to_string(i));
		if ((rand() % 2) == 1)
			Fio.set_patronymic("Andreevich" + STD::to_string(i));

		g_Fio.push_back(Fio);
		Fio.clear_patronymic();

		Fio.set_name("Sergey" + STD::to_string(i));
		Fio.set_surname("Escow" + STD::to_string(i));
		Fio.set_patronymic("Evgenevich" + STD::to_string(i));

		g_Fio.push_back(Fio);
		Fio.clear_patronymic();

		Fio.set_name("Nikita" + STD::to_string(i));
		Fio.set_surname("Mihalkov" + STD::to_string(i));
		if ((rand() % 2) == 1)
			Fio.set_patronymic("Petrovichev" + STD::to_string(i));

		g_Fio.push_back(Fio);
		Fio.clear_patronymic();

		Fio.set_name("Igor" + STD::to_string(i));
		Fio.set_surname("Igorev" + STD::to_string(i));
		if ((rand() % 2) == 1)
			Fio.set_patronymic("Igorevichev" + STD::to_string(i));

		g_Fio.push_back(Fio);
		Fio.clear_patronymic();

		for (auto fio : g_Fio) {
			STD::ofstream NewBitFIO(PathToFios + "FIO_" + STD::to_string(Count++) + ".bin", STD::ios_base::binary);
			fio.SerializeToOstream(&NewBitFIO);
		}

		Count = 0;

		for (Uint32 x = 0; x < g_Fio.size(); x++)
		{
			Students::Student Student;

			STD::ifstream in(PathToFios + "FIO_" + STD::to_string(Count++) + ".bin", STD::ios_base::binary);
			if (TempFio.ParseFromIstream(&in)) {
				Student.set_allocated_fio(&TempFio);
			}
			else {
				cout << "Error!" << endl;
			}

			for (size_t j = 0; j < 50; j++)
			{
				Student.add_evaluations(rand() % 5 + 1);
			}

			double AverageScore{ 0 };
			for (auto& Score : Student.evaluations()) {
				AverageScore += static_cast<double>(Score);
			}

			Student.set_averagescore(AverageScore / static_cast<double>(Student.evaluations().size()));
			g_Students.push_back(Student);

			cout << g_Students[x].fio().name() << endl;
			cout << "X:" << x << endl;
		}


		Count = 0;

		for (auto student : g_Students) {
			STD::ofstream NewBitStudents(PathToStudents + "Student_" + STD::to_string(Count++) + ".bin", STD::ios_base::binary);
			student.SerializeToOstream(&NewBitStudents);

		}

		Students::StudentGroup SG;

		for (size_t j = 0; j < g_Students.size(); j++)
		{
			SG.add_studs()->CopyFrom(g_Students[j]);
		}

		g_Grups.push_back(SG);
	}


	Uint32 Count{0};
	for (auto sg : g_Grups) {
		STD::ofstream NewBitStudents(PathToGroups + "Group_" + STD::to_string(Count++) + ".bin", STD::ios_base::binary);
		sg.SerializeToOstream(&NewBitStudents);
	}

	Int CountStudent{ 0 };
	for (auto sg : g_Grups) {
		cout << "Group: " << CountStudent++ << "\n";
		ALG::for_each(sg.studs().begin(), sg.studs().end(), [&CountStudent](Students::Student Student) {
			cout << "---------------------------------------\n";
			cout << "Student: " << Student.fio().name() << " " << Student.fio().surname() << " " << Student.fio().patronymic() << "\n";
			cout << "Average Score: " << Student.averagescore() << endl;
			});
		cout << "---------------------------------------\n";
	}
}