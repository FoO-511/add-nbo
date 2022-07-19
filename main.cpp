#include "add-nbo.h"

int main(int argc, char*argv[]) {
	if (handle_input(argc, argv)==-1){
		return -1;
	}

	char* file1 = argv[1];
	char* file2 = argv[2];

	unsigned int n1, n2, h1, h2, sum;

	n1 = read_file_binary2uint(file1);
	n2 = read_file_binary2uint(file2);
	
	h1 = ntoh(n1);
	h2 = ntoh(n2);
	sum = h1 + h2;
	
	print_result(h1, h2, sum);
	
	return 0;
}
