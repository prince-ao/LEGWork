#pragma once
#ifndef COMMANDLINEREADER_H
#define COMMANDLINEREADER_H

class CommandLineReader {
public:
	static CommandLineReader* instance(int argv = 0, char* argc[] = nullptr);
	char* getOutputFile() const;
	char* getInputFile() const;
protected:
	CommandLineReader(int argv, char* argc[]);
private:
	void readCommandLine(int argv, char* argc[]);
	void printUsage();
	void commandLineError();
	static CommandLineReader* _instance;
	char* inputFile = nullptr;
	char* outputFile = nullptr;
};

#endif
