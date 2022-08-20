CC = gcc
CFLAGS = -g

PROG=bin

$(PROG): linked_list.c test_linked_list.c
	$(CC) $(CFLAGS) -o $@ $^ 


.PHONY: clean
clean:
	rm -r $(PROG) $(PROG).dSYM
