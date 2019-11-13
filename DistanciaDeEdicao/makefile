all:    main.c TAD_de.c
	gcc main.c -o EXEC TAD_de.c

run:	EXEC
	./EXEC 

debug:	EXEC
	valgrind ./EXEC