#include "LEGWork.h"

LEGWork::LEGWork(int argv, char* argc[]) {
  parseArguments(argv, argc);

  if(arguments.help) {
    printHelp();
    exit(0);
  }else {
    file = arguments.inputFile;
    translator = new Translator;
  }
}

void LEGWork::parseArguments(int argv, char* argc[]) {
  for(int i = 1; i < argv; i++) {
    if(strcmp(argc[i], "--help") == 0 || strcmp(argc[i], "-h") == 0) {
      arguments.help = true;
    } else if(strcmp(argc[i], "-o") == 0) {
      if(i + 1 < argv) {
        arguments.outputFile = argc[i + 1];
        ++i;
      }
    } else {
      if(arguments.inputFile != "") {
        std::cerr << "Unknown argument: " << argc[i] << std::endl;
        printHelp();
        exit(1);
      }
      arguments.inputFile = argc[i];
    }
  }
}

void LEGWork::printHelp() {
  std::cout << "Usage: legwork [option...] <input_file>" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "  -h, --help" << std::endl;
  std::cout << "  -o <output_file>" << std::endl;
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
                                                    //

  const char* assemble = ("echo \"\"\"" + entire_file + "\"\"\" | as -o temp.o").c_str()
  int assembleStatusCode = std::system(assemble);
  if(assembleStatusCode != 0) {
    exit(1);
  }
  std::system("ld temp.o " + arguments.outputFile + " && rm temp.o");
}
