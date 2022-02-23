#include "Graffiti.h"





Graffiti::Graffiti(std::string path):_path(path), bmp_ASCII(bA(2000, std::vector<char>(2000, ' ')))
{
	bmp_info = new unsigned char[54];
	_is_filed = new char[4];
	
}

Graffiti::~Graffiti()
{
	

}

void Graffiti::print()
{
	read_bmp();
}


void Graffiti::read_bmp()
{
	
	std::ifstream fin;
	fin.open(_path, std::ios::binary);

	getHeaderData(fin);
	int padding = padding_w(bmp_w);
	unsigned char* pixelInfo = new unsigned char[padding];
	char temp;
	while (i  < bmp_h  )
	{
		fin.read((char*)pixelInfo, padding);

		for (j = 0; j < padding ; j += 3)
		{
			temp = pixelInfo[j];
			
			pixelInfo[j] = pixelInfo[j + 2];

			pixelInfo[j + 2] = temp;

			double grayScale = 0.3 * ((int)pixelInfo[j] / 256.0) + 0.6 * ((int)pixelInfo[j + 1] / 256.0) + 0.11 * ((int)pixelInfo[j + 2] / 256.0);
			
			setArray(grayScale);
			
		}
		i++;
	}
	fin.close();
	print_bmp();

	std::cout << std::endl << "Type exit to close program" << std::endl;
	return;
	

}

void Graffiti::getHeaderData(std::ifstream &fin)
{
	fin.read((char*)bmp_info, 54);
	// bmp Header
	// https://en.wikipedia.org/wiki/BMP_file_format#File_structure
	bmp_w = *(int*)&bmp_info[18];
	bmp_h = *(int*)&bmp_info[22];
	std::cout << _path << " h: " << bmp_h << " w: " << bmp_w << '\n';
	
}





int Graffiti::padding_w(int width) {
	return (((width * 3 + 3) / 4) * 4);
}




void Graffiti::setArray(double gray_scale) {
	if (gray_scale > 0.6) {
		bmp_ASCII[i][j] = 65 + (gray_scale - 0.6) * (1 * 26 / (max_grayScale - 0.6));
	}

	else if (gray_scale >= 0.3) {
		bmp_ASCII[i][j] = 97 + (gray_scale - 0.3) * (1 * 26 / 0.3);
	}

	else {
		bmp_ASCII[i][j] = 32 + (gray_scale * (1 * 16 / 0.3));
	}
}

void Graffiti::print_bmp() {
	
	for (int i = bmp_h - 1; i >= 0; i-=scale_h) {
		std::cout << "//";
		for (int j = 0; j < bmp_w * 3; j = j+=scale_w) {
			if (bmp_ASCII[i][j] == 91) // wihte
			{
				bmp_ASCII[i][j] = ' ';
			}
			std::cout << bmp_ASCII[i][j];
		}
		std::cout << std::endl;
	}
}



