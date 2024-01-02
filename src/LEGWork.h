#pragma once
#ifndef LEGWORK_H
#define LEGWORK_H

#include "Common.h"
#include "Translator.h"

class LEGWork {
public:
	LEGWork(int argv, char* argc[]);
	~LEGWork();

	void start();
  void parseArguments(int argv, char* argc[]);
  void printHelp();
private:
  struct CommnadlineArguments {
    bool help{};
    std::string_view outputFile{"a.out"};
    std::string_view inputFile{""};
  } arguments;
	std::string file;
	Translator* translator;
	std::string entire_file =
".text\n\
.global _start\n\n\
_start:\n\
main:\n";
};

#endif
