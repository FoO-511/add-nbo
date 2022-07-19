#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <iostream>

#pragma once
using namespace std;

int handle_input(int argc, char*argv[]);

unsigned int ntoh(unsigned int n);

void print_format_num(unsigned int num);

void print_result(unsigned int h1, unsigned int h2, unsigned int sum);

unsigned int read_file_binary2uint(char* filepath);
