#include "add-nbo.h"

int handle_input(int argc, char*argv[]){
	 if (argc < 3){
		 cout << "input two filepath.\n";
	 	return -1;
	 }

	 if(access(argv[1], 0) == -1){
		cout << "no such filename '"<< argv[1] << "'\n";		 
		return -1;
	 }
	 if(access(argv[2], 0) == -1){
	 	cout << "no such filename '"<< argv[2] << "'\n";
		return -1;
	 }

	 return 1;
}

unsigned int ntoh(unsigned int n){
	unsigned int b0, b1, b2, b3;
	b0 = (n & 0xff000000) >> 24;
	b1 = (n & 0x00ff0000) >> 8;
	b2 = (n & 0x0000ff00) << 8; 
	b3 = (n & 0x000000ff) << 24;
	unsigned int n1 = b0 | b1 | b2 | b3;

	return n1;
}

void print_format_num(unsigned int num){
	cout << num << "(0x" << hex << num << ")" << dec;
}

void print_result(unsigned int h1, unsigned int h2, unsigned int sum){
	print_format_num(h1);
	cout << " + ";
	print_format_num(h2);
	cout << " = ";
	print_format_num(sum);
	cout << "\n";
}

unsigned int read_file_binary2uint(char* filepath){
	unsigned int num;
	ifstream file(filepath, ios::binary);

	if(file.is_open())
	{
		file.read(reinterpret_cast<char*>(&num), sizeof(unsigned int));
		file.close();
	} else {return -1;}
	
	return num;
}

