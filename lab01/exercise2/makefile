CC = gcc
CFLAGS = -g

PROG=bin

$(PROG): pwd_checker.c test_pwd_checker.c
	$(CC) $(CFLAGS) -o $@ $^


.PHONY: clean
clean:
	rm -r $(PROG) $(PROG).dSYM
