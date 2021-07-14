all: CLI CORE clean
CLI: Cli.o
	gcc -o CLI Cli.o
CORE: Core.o
	gcc -o CORE Core.o
Cli.o: Cli.c
	gcc -c Cli.c
Core.o: Core.c
	gcc -c Core.c

clean: 
	rm *.o
