#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#ifndef BOARD_SIZE
#define BOARD_SIZE	15
#endif 


int row (int cell)
{
	return cell / BOARD_SIZE ;
}

int col (int cell)
{
	return cell % BOARD_SIZE ;
}

int is_feasible (struct stack_t * queens) 
{
	int board[BOARD_SIZE][15] ;
	int c, r ;

	for (r = 0 ; r < BOARD_SIZE ; r++) {
		for (c = 0 ; c < BOARD_SIZE ; c++) {
			board[r][c] = 0 ;
		}
	}

	for (int i = 0 ; i < get_size(queens) ; i++) {
		int cell ;
		get_elem(queens, i, &cell) ;
		
		int r = row(cell) ;
		int c = col(cell) ;
	
		if (board[r][c] != 0) {
			return 0 ;
		}

		int x, y ;
		for (y = 0 ; y < BOARD_SIZE ; y++) {
			board[y][c] = 1 ;
		}
		for (x = 0 ; x < BOARD_SIZE ; x++) {
			board[r][x] = 1 ;
		}

		y = r + 1 ; x = c + 1 ;
		while (0 <= y && y < BOARD_SIZE && 0 <= x && x < 15) {
			board[y][x] = 1 ;
			y += 1 ; x += 1 ;
		}

		y = r + 1 ; x = c - 1 ;
		while (0 <= y && y < BOARD_SIZE && 0 <= x && x < 15) {
			board[y][x] = 1 ;
			y += 1 ; x -= 1 ;
		}

		y = r - 1 ; x = c + 1 ;
		while (0 <= y && y < BOARD_SIZE && 0 <= x && x < 15) {
			board[y][x] = 1 ;
			y -= 1 ; x += 1 ;
		}

		y = r - 1 ; x = c - 1 ;
		while (0 <= y && y < BOARD_SIZE && 0 <= x && x < 15) {
			board[y][x] = 1 ;
			y -= 1 ; x -= 1 ;
		}

	}

	return 1;
}

void print_placement (struct stack_t * queens)
{
	for (int i = 0 ; i < queens->size ; i++) {	
		int queen ;
		get_elem(queens, i, &queen) ;
		printf("[%d,%d] ", row(queen), col(queen)) ;
	}
}


int find_n_queens_with_prepositions (int N, struct stack_t * prep)
{
	struct stack_t * queens = create_stack(BOARD_SIZE) ;

	queens->capacity = prep->capacity ;
	queens->size = prep->size ;
	memcpy(queens->buffer, prep->buffer, prep->size * sizeof(int)) ;

	while (!is_empty(queens)) {
		int latest_queen ;
		top(queens, &latest_queen) ;

		if (latest_queen == BOARD_SIZE * 15) {
			pop(queens, &latest_queen) ;
			if (!is_empty(queens)) {
				pop(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
			else {
				break ;
			}
			continue ;
		}

		if (is_feasible(queens)) {
			if (get_size(queens) == N) {
			
				print_placement(queens) ;

				printf("\n") ;

				int lastest_queen ;
				pop(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
			else {
				int latest_queen ;
				top(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
		}
		else {
			int lastest_queen ;
			pop(queens, &latest_queen) ;
			push(queens, latest_queen + 1) ;
		}

	}
	delete_stack(queens) ;
}


int find_n_queens (int N)
{
	struct stack_t * queens = create_stack(BOARD_SIZE) ;

	push(queens, 0) ;
	while (!is_empty(queens)) {
		int latest_queen ;
		top(queens, &latest_queen) ;

		if (latest_queen == BOARD_SIZE * 15) {
			pop(queens, &latest_queen) ;
			if (!is_empty(queens)) {
				pop(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
			else {
				break ;
			}
			continue ;
		}

		if (is_feasible(queens)) {
			if (get_size(queens) == N) {

				print_placement(queens) ;
				printf("\n") ;

				int lastest_queen ;
				pop(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
			else {
				int latest_queen ;
				top(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
		}
		else {
			int lastest_queen ;
			pop(queens, &latest_queen) ;
			push(queens, latest_queen + 1) ;
		}

	}
	delete_stack(queens) ;
}

int main ()
{
	find_n_queens(4) ;
	return EXIT_FAILURE ;
}
