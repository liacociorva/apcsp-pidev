all: mastermind computer_mastermind player_mastermind

mastermind: mastermind.o playerGame.o computerGame.o helper_functions.o
	gcc -o mastermind mastermind.o playerGame.o computerGame.o helper_functions.o

computer_mastermind: computer_mastermind.o computerGame.o helper_functions.o
	gcc -o computer_mastermind computerGame.o computer_mastermind.o helper_functions.o

player_mastermind: player_mastermind.o playerGame.o helper_functions.o
	gcc -o player_mastermind playerGame.o player_mastermind.o helper_functions.o

mastermind.o: mastermind.c
	gcc -c mastermind.c

player_mastermind.o: player_mastermind.c
	gcc -c player_mastermind.c

playerGame.o: playerGame.c
	gcc -c playerGame.c

computer_mastermind.o: computer_mastermind.c
	gcc -c computer_mastermind.c

computerGame.o: computerGame.c
	gcc -c computerGame.c

helper_functions.o: helper_functions.c
	gcc -c helper_functions.c

clean: 
	rm mastermind.o computer_mastermind.o player_mastermind.o playerGame.o computerGame.o helper_functions.o
