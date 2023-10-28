#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "CommandLineReader.h"

CommandLineReader* CommandLineReader::_instance = nullptr;

CommandLineReader::CommandLineReader(int argv, char* argc[]) {
	readCommandLine(argv, argc);
}

CommandLineReader* CommandLineReader::instance(int argv, char* argc[]) {
	if(_instance == nullptr && (argv == 0 || argc == nullptr)) {
		return nullptr;
	} else if(_instance == nullptr) {
		_instance = new CommandLineReader(argv, argc);
	}
	return _instance;
}

void CommandLineReader::readCommandLine(int argv, char* argc[]) {
	if(argv != 2 && argv != 4) {
		commandLineError();
	}

	if(argv == 2) {
		const char* a = "-h";
		if(!strcmp(argc[1], a)) {
			printUsage();
			exit(0);
		}else {
			inputFile = argc[1];
		}
	}else {
		const char* a = "-o";
		if(!strcmp(argc[1], a)) {
			outputFile = argc[2];
			inputFile = argc[3];
		}else if(!strcmp(argc[2], a)){
			inputFile = argc[1];
			outputFile = argc[3];
		}else {
			commandLineError();
		}
	}
}

void CommandLineReader::commandLineError() {
	fprintf(stderr, "\e[31;1merror reading command line argument.\e[47;m\n");
	printUsage();
	exit(1);
}

void CommandLineReader::printUsage() {
	printf(
	"Usage: legw [options] file\n"
	"Options:\n"
	"  -h         Display this information.\n"
	"  -o <file>  Specify name of output file.\n"
	);
}

char* CommandLineReader::getOutputFile() const {
	return outputFile;
}

char* CommandLineReader::getInputFile() const {
	return inputFile;
}
