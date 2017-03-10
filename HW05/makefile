all: main

main: comp
	./exe examp.txt 0	
comp: 
	g++ _mainTester.cpp CPU.cpp CPUProgram.cpp Computer.cpp Memory.cpp -o exe -std=c++11
clean:
	rm *-o exe
