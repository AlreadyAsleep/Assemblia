# include <iostream>// std library for console IO
# include <fstream> // std library for file IO


using namespace std;



// used to test linkage between c++ and masm
extern "C" int test_print_num()
{
	cout << 4 << endl;
	return 4;
};


// saves a character as a string
extern "C" void save_character(char* character, char* filename)
{
	ofstream file;
	//ofstream file;
	//file.open(filename);
	//file << character;
	//file.close();
};



