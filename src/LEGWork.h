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
private:
	std::string file;
	Translator* translator;
	std::string entire_file = 
".text\n\
.global _start\n\n\
_start:\n\
main:\n";
};

#endif
