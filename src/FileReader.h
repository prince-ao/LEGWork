#pragma once
#ifndef FILEREADER_H
#define FILEREADER_H

#include "CommandLineReader.h"

class FileReader {
public:
	FileReader();
	char getNextChar();
private:
	CommandLineReader* commandLineReader = nullptr;
	int infile_fd;
	int buffer_size = 0;
	int buffer_pointer = 0;
	char* file_buffer;
};

#endif
