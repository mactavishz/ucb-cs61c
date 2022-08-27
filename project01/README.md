# 61C Spring 2022 Project 1: Snake

Spec: [https://cs61c.org/sp22/projects/proj1/](https://cs61c.org/sp22/projects/proj1/)

## Testing and debugging

### run unit tests

```bash
make run-unit-tests
```

### debug unit tests with CGDB

```bash
make debug-unit-tests
```

### check for memory leaks

```bash
make valgrind-unit-tests
```

### run integration tests

```bash
make run-integration-tests
```

### debug integration tests

```bash
# replace TESTNAME with one of the test names in the `tests` folder
# - 1-simple
# - 2-direction
# - 3-tail
# - 4-food
# - 5-wall
# - 6-small
# - 7-large
# - 8-multisnake
# - 9-everything
cgdb --args ./snake -i tests/TESTNAME-in.snk -o tests/TESTNAME-out.snk
```

