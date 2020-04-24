 
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o Especie.o Cjt_especies.o
	g++ -o main.exe Especie.o Cjt_especies.o main.o $(OPCIONS)
	rm *.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

Cjt_especies.o: Cjt_especies.cc Cjt_especies.hh
	g++ -c Cjt_especies.cc $(OPCIONS)

Especie.o: Especie.cc Especie.hh
	g++ -c Especie.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe