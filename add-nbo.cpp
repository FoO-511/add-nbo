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

uint32_t ntoh(uint32_t n){
	uint32_t b0, b1, b2, b3;
	b0 = (n & 0xff000000) >> 24;
	b1 = (n & 0x00ff0000) >> 8;
	b2 = (n & 0x0000ff00) << 8; 
	b3 = (n & 0x000000ff) << 24;
	uint32_t n1 = b0 | b1 | b2 | b3;

return n1;
}

void print_format_num(uint32_t num){
	cout << num << "(0x" << hex << num << ")" << dec;
}

void print_result(uint32_t h1, uint32_t h2, uint32_t sum){
	print_format_num(h1);
	cout << " + ";
	print_format_num(h2);
	cout << " = ";
	print_format_num(sum);
	cout << "\n";
}

uint32_t read_file_binary2uint(char* filepath){
	FILE* fp = NULL;
	uint32_t num;
	fp = fopen(filepath, "rb");
	
	if (fp == NULL)
	{
		fprintf(stderr, "err\n");
		return 1;
	}

	fread(&num, sizeof(uint32_t), 1,fp);
	fclose(fp);

	return num;
}

