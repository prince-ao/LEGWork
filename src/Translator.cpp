#include "Translator.h"

bool Translator::match(int start, int length, std::string&& match_string, std::string& instruction) {
	for(int i = 0; i < length; i++) {
		if(match_string[i] != instruction[start + i]) return false;
	}
	return true;
}

void Translator::rd_from_x_to_w(std::string& instruction) {
	for(char& c : instruction) {
		if(c == ',') break;
		if(c == 'X' || c == 'x') {
			c = 'w';
			break;
		}
	}
}

void Translator::translate(std::string& instruction) {
	switch(instruction[0]) {
		case 'A':
			if(match(1, 2, "DD", instruction)) return;
			else if(match(1, 3, "DDI", instruction)) {
				instruction.replace(0, 4, "ADD");
				return;
			}
			else if(match(1, 3, "DDS", instruction)) return;
			else if(match(1, 4, "DDIS", instruction)) {
				instruction.replace(0, 5, "ADDS");
				return;
			}
			else if(match(1, 2, "ND", instruction)) return;
			else if(match(1, 3, "NDI", instruction)) {
				instruction.replace(0, 4, "AND");
				return;
			}
			else throw -1;
		case 'S':
			if(match(1, 2, "UB", instruction)) return;
			else if(match(1, 3, "UBI", instruction)) {
				instruction.replace(0, 4, "SUB");
				return;
			}
			else if(match(1, 3, "UBS", instruction)) return;
			else if(match(1, 4, "UBIS", instruction)) {
				instruction.replace(0, 5, "SUBS");
				return;
			}
			else if(match(1, 3, "TUR", instruction)) return;
			else if(match(1, 4, "TURW", instruction)) {
				rd_from_x_to_w(instruction);
				instruction.replace(0, 5, "STUR");
				return;
			}
			else if(match(1, 4, "TURH", instruction)) {
				rd_from_x_to_w(instruction);
				return;
			}
			else if(match(1, 3, "TXR", instruction)) {
				rd_from_x_to_w(instruction);
				return;
			}
			else throw -1;
	}
}
