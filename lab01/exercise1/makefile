CC = gcc
CFLAGS = -g

PROG=bin

$(PROG): ex1.c test_ex1.c
	$(CC) $(CFLAGS) -o $@ $^


.PHONY: clean
clean:
	rm -r $(PROG) $(PROG).dSYM
