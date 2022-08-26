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
  switch (c) {
    case 'w':
      break;
    case 'a':
      break;
    case 's':
      break;
    case 'd':
      break;
    default:
      return false;
  }
  return true;
}

static bool is_snake(char c) {
  bool flag = true; 
  switch (c) {
    case '^':
      break;
    case '<':
      break;
    case '>':
      break;
    case 'v':
      break;
    case 'x':
      break;
    default:
      flag = false;
      break;
  }
  return flag || is_tail(c);
}

static char body_to_tail(char c) {
  switch (c) {
    case '^':
      return 'w';
    case '<':
      return 'a';
    case '>':
      return 'd';
    case 'v':
      return 's';
    default:
      break;
  }
  return '?';
}

static int incr_x(char c) {
  if (c == '>' || c == 'd') {
    return 1;
  } else if (c == '<' || c == 'a') {
    return -1;
  } else {
    return 0;
  }
}

static int incr_y(char c) {
  if (c == 'v' || c == 's') {
    return 1;
  } else if (c == '^' || c == 'w') {
    return -1;
  } else {
    return 0;
  }
}

/* Task 4.2 */
static char next_square(game_state_t* state, int snum) {
  snake_t snake = state->snakes[snum];
  char head = get_board_at(state, snake.head_x, snake.head_y);
  char next_cell = get_board_at(state, snake.head_x + incr_x(head), snake.head_y + incr_y(head));
  return next_cell;
}

/* Task 4.3 */
static void update_head(game_state_t* state, int snum) {
  snake_t *snake = &state->snakes[snum];
  char head = get_board_at(state, snake->head_x, snake->head_y);
  snake->head_x += incr_x(head);
  snake->head_y += incr_y(head);
  set_board_at(state, snake->head_x, snake->head_y, head);
  return;
}

/* Task 4.4 */
static void update_tail(game_state_t* state, int snum) {
  snake_t *snake = &state->snakes[snum];
  char tail = get_board_at(state, snake->tail_x, snake->tail_y);
  // clear old tail on the board
  set_board_at(state, snake->tail_x, snake->tail_y, ' ');
  // calculate new pos for the new tail
  snake->tail_x += incr_x(tail);
  snake->tail_y += incr_y(tail);
  // get the current char at the new tail pos
  char body_next_to_tail = get_board_at(state, snake->tail_x, snake->tail_y);
  char new_tail = body_to_tail(body_next_to_tail);
  // set new tail on the board
  set_board_at(state, snake->tail_x, snake->tail_y, new_tail);
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  unsigned i;
  for (i = 0; i < state->num_snakes; i++) {
    snake_t *snake = &state->snakes[i];
    char head = get_board_at(state, snake->head_x, snake->head_y);
    char new_head = get_board_at(state, snake->head_x + incr_x(head), snake->head_y + incr_y(head));
    // hit the wall
    if (new_head == '#' || is_snake(new_head)) {
      set_board_at(state, snake->head_x, snake->head_y, 'x');
      snake->live = false;
    } else if (new_head == '*') { // get a fruit
      update_head(state, i);
      add_food(state);
    } else {
      update_head(state, i);
      update_tail(state, i);
    }
  }
  return;
}

/* Task 5 */
/* This function doesn't check the validity of the content */
game_state_t* load_board(char* filename) {
  FILE* f = fopen(filename, "r");
  game_state_t *state = malloc(sizeof(game_state_t));
  int count = 0, default_cols = 16, cols = 0, rows = 0;
  int ch;
  char *buf = malloc(sizeof(char) * default_cols);
  while ((ch = fgetc(f)) != '\n') {
    if (cols >= default_cols) {
      default_cols *= 2;
      buf = realloc(buf, sizeof(char) * default_cols);
    }
    buf[cols] = ch;
    cols++;
  }
  rows = 1;
  while ((ch = fgetc(f)) != EOF) {
    if (ch == '\n') {
      rows++;
    }
  }
  free(buf);
  // reset file position indicator
  rewind(f);
  int i, j;
  state->board = malloc(rows * sizeof(char *));
  state->x_size = cols;
  state->y_size = rows;
  for (i = 0; i < rows; i++) {
    state->board[i] = malloc(cols * sizeof(char));
    for (j = 0; j < cols; j++) {
      state->board[i][j] = fgetc(f);
    }
    // remove newline character
    fgetc(f);
  }
  fclose(f);
  return state;
}

/* Task 6.1 */
static void find_head(game_state_t* state, int snum) {
  snake_t *snake = &state->snakes[snum];
  int x = snake->tail_x;
  int y = snake->tail_y;
  char ch = state->board[y][x];
  while (true) {
    int move_y = incr_y(ch);
    int move_x = incr_x(ch);
    if ((ch = state->board[y + move_y][x + move_x]) == ' ') {
      break;
    }
    x += move_x;
    y += move_y;
  }
  snake->head_x = x;
  snake->head_y = y;
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  int rows = state->y_size;
  int cols = state->x_size;
  int i, j;
  state->num_snakes = 0;
  // find the number of snakes
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (is_tail(state->board[i][j])) {
        state->num_snakes++;
      }
    }
  }

  state->snakes = malloc(sizeof(snake_t) * state->num_snakes);
  int snum = 0;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (is_tail(state->board[i][j])) {
        state->snakes[snum].tail_x = j;
        state->snakes[snum].tail_y = i;
        find_head(state, snum);
        snum++;
      }
    }
  }
  return state;
}
