Autor: Mateus Ferreira Silva <ferreiramateus201306@gmail.com>

O programa exhausting_sort.cpp foi feito em c++ para compilar ele é necessário ter o g++ instalado na máquina.

Para instalar o g++:
	sudo apt install g++

Para compilar e gerar um executável genérico:
	g++ exhausting_sort.cpp

Agora para executar esse executável genérico:
	./a.out

Ou se preferir:
	Compila e gera um código objeto:
		g++ -c exhausting_sort.cpp
	Linka o código objeto e cria um executável:
		g++ -o prog exhausting_sort.o
	Para executar:
		./prog

#Notas:

O programa lê a entrada de um arquivo chamado data.txt que deve estar no mesmo diretório.

A saída de dados é feita na saída padrão.