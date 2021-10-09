OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Especie.o Cjt_especies.o Cjt_clusters.o
	g++ -o program.exe program.o Especie.o Cjt_especies.o Cjt_clusters.o $(OPCIONS)
	rm *.o

Especie.o: src/Especie.cc
	g++ -c src/Especie.cc $(OPCIONS)

Cjt_clusters.o: src/Cjt_clusters.cc
	g++ -c src/Cjt_clusters.cc $(OPCIONS)

Cjt_especies.o: src/Cjt_especies.cc
	g++ -c src/Cjt_especies.cc $(OPCIONS)

program.o: src/program.cc
	g++ -c src/program.cc $(OPCIONS)
