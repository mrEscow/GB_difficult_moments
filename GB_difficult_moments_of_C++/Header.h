#pragma once

/*
	Итераторы:

	Итераторы представляют собой “указателеобразные” объекты,
	которые алгоритмы STL используют для обхода последовательности объектов,
	хранящихся в контейнере.

	Итераторы занимают центральное место в STL благодаря их роли посредников между контейнерами и обобщенными алгоритмами.

	Они позволяют создавать обобщенные алгоритмы без учета того,
	как именно хранятся последовательности данных,
	а контейнеры — без необходимости написания большого количества исходного текста работающих с ними алгоритмов.

	В STL все итераторы разделены на пять категорий:
													входные,
													выходные,
													однонаправленные,
													двунаправленные,
													произвольного доступа.
*/
#include <iostream>

#include <fstream>
#include <istream>
#include <string>
#include <sstream>

#include <iomanip>

#include <algorithm>

#include <optional>

#include <vector>
#include <deque>
#include <list>

#include <variant>
#include <numeric>

#include <map>
#include <set>

#include <iterator>

#include <future>

#include <unordered_set>
#include <stack>
#include <queue>

#include <chrono>

#include <thread>
#include <mutex>
#include <shared_mutex>

#include <execution>

#include <cassert>