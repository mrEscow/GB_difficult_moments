#pragma once
/*
* 	mr.Escow - Lesson-7
* * * * * * * * * * * * * * * */
#include "Header.h"


//-------------------------------------------------------------------------------------------
//	std
namespace STD{

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

	using std::rotate;

	using std::swap_ranges;

	using std::transform;

	using std::unique;

	using std::accumulate;

	using std::partial_sum;

	using std::adjacent_difference;

	using std::inner_product;

	using std::sort;
	//using std::��rtial_sort;
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

//	�������� ����������
namespace ADPIT{

	using std::ostream_iterator;
	using std::istream_iterator;

	using std::front_inserter;
	using std::back_inserter;

}
namespace PRL{

	namespace THIS{

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
		using std::execution::par;

		using std::execution::parallel_policy;
		using std::execution::parallel_policy;
		using std::execution::parallel_unsequenced_policy;

	}

	namespace AL{

		using std::launch::async;
		using std::launch::deferred;
	}
}
//-------------------------------------------------------------------------------------------
namespace STR {
	typedef std::string str;
}
namespace my {
	using namespace STR;

	using std::ios;
	using std::ofstream;
	using std::ifstream;

	void serialize(str path, str data) {
		ofstream out(path, ios::binary);
		out.write(data.c_str(), data.size());
	}

	void deserialize(str path, str& result) {
		ifstream in(path, ios::binary);
		result.resize(1024);
		in.read(result.data(), result.size());
		result.resize(in.gcount());
	}

	void serialize(str path, int data) {
		ofstream out(path, ios::binary);
		out.write(reinterpret_cast<char*>(&data), sizeof(data));
	}

	void deserialize(str path, int& result) {
		ifstream in(path, ios::binary);
		in.read(reinterpret_cast<char*>(&result), sizeof(result));
	}
}
//-------------------------------------------------------------------------------------------
namespace {
	int i = 100;
	void f() {
		STD::cout << i << STD::endl;
	}
}
//-------------------------------------------------------------------------------------------
int Lesson7() {
	{
		my::str String{"HELLO WORLD!"};
	}
	{
		STD::cout << PRL::THIS::get_id() << STD::endl;
		PRL::thread Thread; 
	}
	{
		int i = 10;

		STD::cout << i << STD::endl;
		f();
		STD::cout << i << STD::endl;
		f();
	}

	{
		STD::serialize("data1.bin", "Hello world!");
		STD::string result;
		STD::deserialize("data1.bin", result);
		STD::cout << result << STD::endl;
	}

	{
		STD::serialize("data2.bin", 802'464'397);
		int result;
		STD::deserialize("data2.bin", result);
		STD::cout << result << STD::endl;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------