all:
	g++ -o main main.cpp -Ofast -Wall -Wextra
run:
	g++ -o main main.cpp -Ofast -Wall -Wextra
	./main --default
