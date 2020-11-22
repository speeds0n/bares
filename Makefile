# Makefile BARES

all:
	@ echo 'Compiling the program'
	@ g++ -std=c++11 main.cpp src/bares.cpp src/parser.cpp -I lib/
	@ echo 'Finish in the compilation'

run:
	@ echo 'Type the expression'
	@ echo 'To finish the file type "Ctrl+c"'
	@ ./a.out

test:
	@ echo 'run the program with tests in the "entrada.txt"'
	@ ./a.out < entrada.txt

clear:
	@ rm ./a.out
	@ echo 'All files creates in the compilation were deleted'
