#pragma once

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <fstream>



using bA = std::vector<std::vector<char>>;



class Graffiti 
{
public:
	Graffiti(std::string path);
	~Graffiti();
	void print();
	

private: 
	int bmp_w = 0;
	int bmp_h = 0;
	unsigned char* bmp_info;
	char* _is_filed;
	int i = 0, j = 0;
	unsigned char scale_h = 2, scale_w = 6;
	std::string _path = "";
	double max_grayScale = 0.3 * (255.0 / 256.0) + 0.6 * (255.0 / 256.0) + 0.11 * (255.0 / 256.0);
	bA bmp_ASCII;
	void read_bmp();
	void getHeaderData(std::ifstream& fin);
	int padding_w(int width);
	void setArray(double gray_scale);
	void print_bmp();

};
