#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snake_utils.h"
#include "state.h"

/* Helper function definitions */
static char get_board_at(game_state_t* state, int x, int y);
static void set_board_at(game_state_t* state, int x, int y, char ch);
static bool is_tail(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static int incr_x(char c);
static int incr_y(char c);
static void find_head(game_state_t* state, int snum);
static char next_square(game_state_t* state, int snum);
static void update_tail(game_state_t* state, int snum);
static void update_head(game_state_t* state, int snum);

/* Helper function to get a character from the board (already implemented for you). */
static char get_board_at(game_state_t* state, int x, int y) {
  return state->board[y][x];
}

/* Helper function to set a character on the board (already implemented for you). */
static void set_board_at(game_state_t* state, int x, int y, char ch) {
  state->board[y][x] = ch;
}

/* Task 1 */
game_state_t* create_default_state() {
  game_state_t *state = malloc(sizeof(game_state_t));
  int rows = 10;
  int cols = 14;
  // x and y are the reverse of rows and cols
  state->x_size = cols;
  state->y_size = rows;
  // allocate rows
  state->board = malloc(sizeof(char*) * rows);
  unsigned i, j;
  for (i = 0; i < rows; i++) {
    // allocate cols
    state->board[i] = malloc(sizeof(char) * cols);
  }
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      state->board[i][j] = ' ';
    }
  }
  // init board
  strncpy(state->board[0], "##############", cols);
  strncpy(state->board[rows - 1], "##############", cols);
  for (i = 1; i < rows - 1; i++) {
    state->board[i][0] = '#';
    state->board[i][cols - 1] = '#';
  }
  // init fruit
  state->board[2][9] = '*';
  // init snake
  state->board[4][4] = 'd';
  state->board[4][5] = '>';
  state->num_snakes = 1; 
  state->snakes = malloc(sizeof(snake_t));
  state->snakes[0].head_x = 5;
  state->snakes[0].head_y = 4; 
  state->snakes[0].tail_x = 4;
  state->snakes[0].tail_y = 4;
  state->snakes[0].live = true;
  return state;
}

/* Task 2 */
void free_state(game_state_t* state) {
  unsigned i;
  for (i = 0; i < state->y_size; i++) {
    free(state->board[i]);
  }
  free(state->snakes);
  free(state->board);
  free(state);
  return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
  int rows = state->y_size;
  int cols = state->x_size;
  unsigned i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%c", state->board[i][j]);
    }
    fprintf(fp, "\n");
  }
  return;
}

/* Saves the current state into filename (already implemented for you). */
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */
static bool is_tail(char c) {
  // TODO: Implement this function.
  return true;
}

static bool is_snake(char c) {
  // TODO: Implement this function.
  return true;
}

static char body_to_tail(char c) {
  // TODO: Implement this function.
  return '?';
}

static int incr_x(char c) {
  // TODO: Implement this function.
  return 0;
}

static int incr_y(char c) {
  // TODO: Implement this function.
  return 0;
}

/* Task 4.2 */
static char next_square(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return '?';
}

/* Task 4.3 */
static void update_head(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return;
}

/* Task 4.4 */
static void update_tail(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: Implement this function.
  return;
}

/* Task 5 */
game_state_t* load_board(char* filename) {
  // TODO: Implement this function.
  return NULL;
}

/* Task 6.1 */
static void find_head(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  // TODO: Implement this function.
  return NULL;
}
