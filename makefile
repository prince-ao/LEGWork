bin/legwork: src/main.cpp src/Translator.cpp src/LEGWork.cpp
	sudo g++ -std=c++2a src/main.cpp src/Translator.cpp src/LEGWork.cpp -o /usr/local/bin/legwork
