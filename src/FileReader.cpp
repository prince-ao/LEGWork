#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "CommandLineReader.h"
#include "FileReader.h"

FileReader::FileReader() {
	commandLineReader = CommandLineReader::instance();

	infile_fd = open((const char *)commandLineReader->getInputFile(), O_RDONLY);

	file_buffer = (char *)malloc(20 * sizeof(int));
}

char FileReader::getNextChar() {
	if(buffer_pointer == buffer_size) {
		if((buffer_size = read(infile_fd, file_buffer, 20)) < 1) {
			return -1;
		}
		buffer_pointer = 0;
	}
	return file_buffer[buffer_pointer++];
}
