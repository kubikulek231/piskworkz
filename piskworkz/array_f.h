#pragma once
// defines a "fake" 2d array of rows*cols size
// uses local variables: rows, cols
int* define_arr(int value, int rows, int cols);

// prints out array into a block
// uses local variables: rows, cols
void print_arr(int* arr, int rows, int cols);

// edits value of given array element (rows, cols)
// uses local variables: cols
void edit_arr_val(int* arr, int r, int c, int newval, int cols);

// gets value of given array element (rows, cols)
// uses local variables: cols
int get_arr_val(int* arr, int r, int c, int cols);

// gets value of given array element (rows, cols)
// uses local variables: cols, rows
void print_board(int* arr, int cols, int rows);
