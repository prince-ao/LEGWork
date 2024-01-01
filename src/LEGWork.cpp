#include "LEGWork.h"

LEGWork::LEGWork(int argv, char* argc[]) {
	if(argv != 2) {
		std::cerr << "Usage: legwork <filename>" << std::endl;
		exit(1);
	}

	file = argc[1];
	translator = new Translator;
}

LEGWork::~LEGWork() {
	delete translator;
}

void LEGWork::start() {
	std::string instruction;
	std::fstream readFile(file);
	int line = 0;

	while(std::getline(readFile, instruction)) {
		++line;
		try {
			translator->translate(instruction);
			entire_file += ("\t" + instruction + "\n");
		} catch(...) {
			std::cerr << "unknown instruction error in line " << line << ": " << instruction << std::endl;
			exit(1);
		}
	}

	entire_file += "\nmov x0, #0\nmov x8, #0\nsvc 0"; // exit 0

	std::cout << entire_file << std::endl;

	std::system(("echo \"\"\"" + entire_file + "\"\"\" | as -o temp.o").c_str());
	std::system("ld temp.o && rm temp.o");
}
