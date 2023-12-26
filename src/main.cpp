#include "LEGWork.h"

int main(int argv, char* argc[]) {
	LEGWork* legwork = new LEGWork(argv, argc);

	legwork->start();

	delete legwork;

	return 0;
}
