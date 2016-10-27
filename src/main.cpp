#include <iostream>
#include <fstream>  
#include "WavFunctions.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 3) {
		std::cerr << "usage:\n write_header out.pcm out.wav" << std::endl;
		return -1;
	}
	std::ifstream output_file_;
	std::ofstream write_file_;
	output_file_.open(argv[1], ios::in|ios::binary|ios::ate);
	int size = output_file_.tellg();  
	output_file_.seekg(0, ios::beg);  
	char* buffer = new char[size];  
	output_file_.read(buffer, size);  
	output_file_.close();  
	
	write_file_.open(argv[2], std::ios::binary);
	WriteHeaderWav(write_file_,16000,16,1, size/2/1);
	write_file_.write(static_cast<char *>(buffer), size);
	write_file_.close();
	
    return 0;
}
