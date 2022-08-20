CC = gcc
CFLAGS = -g

PROG=bin

$(PROG): ll_cycle.c test_ll_cycle.c
	$(CC) $(CFLAGS) -o $@ $^


.PHONY: clean
clean:
	rm -r $(PROG) $(PROG).dSYM
