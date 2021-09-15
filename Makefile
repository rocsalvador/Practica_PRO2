OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Especie.o Cjt_especies.o Cjt_clusters.o
	g++ -o program.exe program.o Especie.o Cjt_especies.o Cjt_clusters.o $(OPCIONS)
	rm *.o

Especie.o: src/Especie.cc src/Especie.hh
	g++ -c src/Especie.cc $(OPCIONS)

Cjt_clusters.o: src/Cjt_clusters.cc src/Cjt_clusters.hh
	g++ -c src/Cjt_clusters.cc $(OPCIONS)

Cjt_especies.o: src/Cjt_especies.cc src/Cjt_especies.hh src/Cjt_clusters.hh
	g++ -c src/Cjt_especies.cc $(OPCIONS)

program.o: src/program.cc src/Cjt_especies.hh src/Cjt_clusters.hh
	g++ -c src/program.cc $(OPCIONS)
