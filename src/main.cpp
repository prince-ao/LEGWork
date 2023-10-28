#include "FileReader.h"
#include "CommandLineReader.h"

#include <stdio.h>

int main(int argv, char* argc[]) {
	CommandLineReader::instance(argv, argc);

	FileReader* fileReader = new FileReader();

	char opt;
	while((opt = fileReader->getNextChar()) != -1) {
		const char as[] = {opt, '\0'};
		printf(as);
	}
}
