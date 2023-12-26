#pragma once
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Common.h"

class Translator {
public:
	void translate(std::string& instruction);
private:
	bool match(int start, int length, std::string&& match_string, std::string& instruction);
	void rd_from_x_to_w(std::string& instruction);
};

#endif
