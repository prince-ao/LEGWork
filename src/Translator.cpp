#include "Translator.h"

bool Translator::match(int start, int length, std::string&& match_string, std::string& instruction) {
	for(int i = 0; i < length; i++) {
		if(match_string[i] != instruction[start + i]) return false;
	}
	if(instruction[start + length] != ' ') return false;
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
			break;
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
			break;
		case 'L':
			if(match(1, 3, "DUR", instruction)) return;
			else if(match(1, 5, "DURSW", instruction)) return;
			else if(match(1, 3, "DRH", instruction)) return;
			else if(match(1, 3, "DRB", instruction)) return;
			else if(match(1, 3, "DXR", instruction)) return;
			else if(match(1, 3, "DXR", instruction)) return;
			else if(match(1, 2, "SL", instruction)) return;
			else if(match(1, 2, "SR", instruction)) return;
			else throw -1;
			break;
		case 'M':
			if(match(1, 3, "OVZ", instruction)) return;
			else if(match(1, 3, "OVK", instruction)) return;
			else throw -1;
			break;
		case 'O':
			if(match(1, 2, "RR", instruction)) return;
			else if(match(1, 2, "RRI", instruction)) {
				instruction.replace(0, 4, "ORR");
			}
			else throw -1;
			break;
		case 'E':
			if(match(1, 2, "OR", instruction)) return;
			else if(match(1, 3, "ORI", instruction)) {
				instruction.replace(0, 4, "EOR");
			}
			else throw -1;
			break;
		case 'C':
			if(match(1, 2, "BZ", instruction)) return;
			else if(match(1, 3, "BNZ", instruction)) return;
			else throw -1;
			break;
		case 'B':
			if(match(1, 0, "", instruction)) return;
      else if(match(1, 1, "R", instruction)) return;
      else if(match(1, 1, "L", instruction)) return;
      else if(match(1, 3, ".EQ", instruction)) return;
      else if(match(1, 3, ".NE", instruction)) return;
      else if(match(1, 3, ".MI", instruction)) return;
      else if(match(1, 3, ".PL", instruction)) return;
      else if(match(1, 3, ".VS", instruction)) return;
      else if(match(1, 3, ".VC", instruction)) return;
      else if(match(1, 3, ".HI", instruction)) return;
      else if(match(1, 3, ".HS", instruction)) return;
      else if(match(1, 3, ".LS", instruction)) return;
      else if(match(1, 3, ".GE", instruction)) return;
      else if(match(1, 3, ".LT", instruction)) return;
      else if(match(1, 3, ".LO", instruction)) return;
      else if(match(1, 3, ".GT", instruction)) return;
      else if(match(1, 3, ".LE", instruction)) return;
			else throw -1;
			break;
    default: throw -1;
	}
}
