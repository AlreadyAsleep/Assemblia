# include <iostream>// std library for console IO
# include <fstream> // std library for file IO

# define WRITE_SIZE 1024


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
	cout << "Saving..." << endl;
	file.open(filename, ios::trunc | ios::binary);
	file.write(character, WRITE_SIZE);
	file.close();
};



