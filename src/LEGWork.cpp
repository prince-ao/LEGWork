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

	while(std::getline(readFile, instruction)) {
		try {
			translator->translate(instruction);
			entire_file += ("\t" + instruction + "\n");
		} catch(...) {
			std::cerr << "unknown instruction error: " << instruction << std::endl;
			exit(1);
		}
	}

	std::cout << entire_file << std::endl;

	std::system(("echo \"\"\"" + entire_file + "\"\"\" | as -o temp.o").c_str());
	std::system("ld temp.o && rm temp.o");
}
