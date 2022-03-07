#pragma once
#include "Header.h"
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

		using std::tie;

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

		namespace This {

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