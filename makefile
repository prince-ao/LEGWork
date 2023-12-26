test: bin/legwork tests/hello.s
	./bin/legwork tests/hello.s

bin/legwork: src/main.cpp src/Translator.cpp src/LEGWork.cpp
	g++ src/main.cpp src/Translator.cpp src/LEGWork.cpp -o bin/legwork
