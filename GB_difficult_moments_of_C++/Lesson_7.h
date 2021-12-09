#pragma once
/*
* 	mr.Escow - Lesson-7
* * * * * * * * * * * * * * * */
#include "Header.h"
//-------------------------------------------------------------------------------------------
namespace STD{

	using std::string;

	using std::ofstream;
	using std::ifstream;

	using std::ios;

	void serialize(string path, string data) {
		ofstream out(path, ios::binary);
		out.write(data.c_str(), data.size());
	}

	void deserialize(string path, string& result) {
		ifstream in(path, ios::binary);
		result.resize(1024);
		in.read(result.data(), result.size());
		result.resize(in.gcount());
	}

	void serialize(string path, int data) {
		ofstream out(path, ios::binary);
		out.write(reinterpret_cast<char*>(&data), sizeof(data));
	}
	
	void deserialize(string path, int& result) {
		ifstream in(path, ios::binary);
		in.read(reinterpret_cast<char*>(&result), sizeof(result));
	}

	using namespace std;
}

namespace {
	int i = 100;
	void f() {
		STD::cout << i << STD::endl;
	}
}
//-------------------------------------------------------------------------------------------
int Lesson7() {

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