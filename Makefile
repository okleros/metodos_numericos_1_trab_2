all:
	g++ -o main main.cpp -Ofast -Wall -Wextra -Werror
run:
	g++ -o main main.cpp -Ofast -Wall -Wextra -Werror
	./main --default
