CC = gcc
CFLAGS = -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations-Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -Wextra -Werror -Wpedantic
PROG = push_pop
STACK = stack_status
OBJECTS = push_pop.o stack_status.o
LOGNAME = idawkins
all: $(PROG)

$(PROG): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROG) $(PROG).o $(STACK).o

$(STACK): $(STACK).o
	$(CC) $(CFLAGS) -o $(STACK) $(STACK).o

$(PROG).o: $(PROG).c
	$(CC) $(CFLAGS) -c $(PROG).c

$(STACK).o: $(STACK).c
	$(CC) $(CFLAGS) -c $(STACK).c

clean:
	rm -f push_pop push_pop.o stack_status stack_status.o

tar:
	tar cvfz lab4-${LOGNAME}.tar.gz *.[ch] ?akefile

