#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <stdint.h>
#pragma once
using namespace std;

int handle_input(int argc, char*argv[]);

uint32_t ntoh(uint32_t n);

void print_format_num(uint32_t num);

void print_result(uint32_t h1, uint32_t h2, uint32_t sum);

uint32_t read_file_binary2uint(char* filepath);
