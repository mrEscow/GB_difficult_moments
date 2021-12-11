#pragma once
/*
* 	mr.Escow - Lesson-7
* * * * * * * * * * * * * * * */
#include "Header.h"
//-------------------------------------------------------------------------------------------
#include "Lesson_1.h"
//-------------------------------------------------------------------------------------------
namespace my {

	using std::cout;
	using std::endl;

	typedef std::string Str;

	typedef int32_t Int;
	typedef int32_t Int32;

	typedef uint32_t Uint;
	typedef uint32_t Uint32;

	typedef int64_t Lint;
	typedef int64_t Int64;

	typedef uint64_t Luint;
	typedef uint64_t Uint64;

	//	std
	namespace STD {

		using namespace std;
	}
	//	stl
	namespace STL {

		using std::variant;
		using std::optional;
		using std::function;

		using std::forward_list;
		using std::array;

		using std::tuple;
		using std::pair;

		using std::vector;
		using std::deque;
		using std::list;

		using std::set;
		using std::multiset;
		using std::map;
		using std::multimap;

		using std::unordered_set;
		using std::unordered_multiset;
		using std::unordered_map;
		using std::unordered_multimap;

		using std::hash;

		using std::stack;
		using std::priority_queue;
	}
	//	algotitms
	namespace ALG {

		using std::for_each;

		using std::find;
		using std::find_if;

		using std::adjacent_find;

		using std::count;
		using std::count_if;

		using std::mismatch;
		using std::equal;

		using std::search;

		using std::copy;
		using std::copy_backward;

		using std::fill;
		using std::fill_n;

		using std::generate;

		using std::partition;
		using std::stable_partition;

		//using std::random_shuffle;

		using std::remove;

		using std::replace;

		using std::rotate;

		using std::swap_ranges;

		using std::transform;

		using std::unique;

		using std::accumulate;

		using std::partial_sum;

		using std::adjacent_difference;

		using std::inner_product;

		using std::sort;
		//using std::раrtial_sort;
		using std::stable_sort;

		using std::nth_element;

		using std::binary_search;

		using std::lower_bound;
		using std::upper_bound;

		using std::merge;

		using std::clamp;

		using std::sample;

		//using std::from_instream;
		using std::next_permutation;
	}

	//	Адаптеры итераторов
	namespace ADPIT {

		using std::ostream_iterator;
		using std::istream_iterator;

		using std::front_inserter;
		using std::back_inserter;

	}
	// paralells
	namespace PRL {

		namespace THIS {

			using std::this_thread::get_id;
			using std::this_thread::sleep_for;
			using std::this_thread::sleep_until;
			using std::this_thread::yield;
		}


		using std::thread;

		using std::mutex;
		using std::timed_mutex;
		using std::recursive_mutex;
		using std::shared_mutex;

		using std::lock_guard;
		using std::scoped_lock;
		using std::unique_lock;
		using std::shared_lock;

		using std::once_flag;

		namespace ALG {

			using std::async;

			namespace launch {

				using std::launch::async;
				using std::launch::deferred;
			}


			using std::execution::par;

			using std::execution::parallel_policy;
			using std::execution::parallel_policy;
			using std::execution::parallel_unsequenced_policy;

		}
	}
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
namespace {
	my::Int32 i = 100;
	void f() {
		my::cout << i << my::endl;
	}
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//	1.Установить библиотеку protobuf. // OK
//-------------------------------------------------------------------------------------------
#include "car.pb.h"
//-------------------------------------------------------------------------------------------
//	2.С помощью компилятора protobuf в отдельном пространстве имен сгенерировать классы
//		a.FullName с полями имя, фамилия, отчество(отчество опционально).
//		b.Student с полями полное имя, массив оценок, средний балл.
//		c.StudentsGroup с полем массив студентов.
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//	3.Создать класс StudentsGroup, который реализует интерфейсы :
//-------------------------------------------------------------------------------------------
class IRepository {
	virtual void Open() = 0; // бинарная десериализация в файл
	virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
	virtual double GetAverageScore(const FullName& name) = 0;
	virtual std::string GetAllInfo(const FullName& name) = 0;
	virtual std::string GetAllInfo() = 0;
};
//-------------------------------------------------------------------------------------------
class StudentsGroup {

};
//-------------------------------------------------------------------------------------------
int Lesson7() {

	{
		my::Str String{"HELLO WORLD!"};
	}

	{
		my::cout << my::PRL::THIS::get_id() << my::endl;
		my::PRL::thread Thread; 
	}

	{
		my::Int32 i = -2'000'000'000;

		my::cout << i << my::endl;
		f();
		my::cout << i << my::endl;
		f();
	}

	{
		using namespace my;

		STL::set<Int64> my_set{ 1,2 };

		ALG::for_each(my_set.begin(), my_set.end(),
			[](Int64 my_Int) {
				cout << my_Int << endl;
			});
	}

	{
		using namespace SD;
		
		Str String{ "HELLO WORLD!" };

		Str Path1{ "data1.bin" };
		{
			Serialize(Path1, String);
			Str Result;
			Deserialize(Path1, Result);
			cout << Result << endl;
		}

		Str Path2{ "data2.bin" };
		{
			Serialize(Path2, 802'464'397);
			Int Result;
			Deserialize(Path2, Result);
			cout << Result << endl;
		}

		Str Path3{ "data3.bin" };
		{
			double Number = 1.234567890;
			cout << Number << endl;
			Serialize(Path3, Number);
			double Result;
			Deserialize(Path3, Result);
			cout << Result << endl;
		}
	}

	using namespace my;

	{
		Str NewString{"GOODBYE WORLD!"};
	}

	{
		/*
			Conan для винды установщик старый и после установки нужно поменять дирикторию запросов

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

	return 0;
}
//-------------------------------------------------------------------------------------------