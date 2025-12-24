#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_STRING_SIZE 256

// int putchar(int chr) {printf("%c  %i\n", chr, chr);return 0;} // DEBuG

int main(int argc, char** argv) {
	int cols;
	if(argc == 1 || (cols = atoi(argv[1])) < 1) cols = 80;

	int chr;
	int current_column = 0;
	int cw_size = DEFAULT_STRING_SIZE;
	int cw_used = 0;
	int cw_cols = 0; // Similar to cw_used, without counting escape sequences.
	int in_escape = 0;
	char* current_word = malloc(cw_size * sizeof(char));
	if(current_word == NULL) exit(1);

	// while((chr = getchar()) != EOF) putchar(chr); // DEBUG
	while((chr = getchar()) != EOF) {
		if(chr == 27 && !in_escape) in_escape = 1;
		else if(chr == 109 && in_escape) in_escape = 0;

		if (chr == ' ' || chr == '\n') {
			current_column += cw_cols + 1;
			if(current_column > cols) {
				putchar('\n');
				current_column = cw_cols + 1;
			}
			for(int i = 0; i < cw_used; i++) putchar(current_word[i]);
			putchar(chr);
			cw_used = 0;
			cw_cols = 0;
			if(chr == '\n') current_column = 0;
		}
		else {
			// Push character to current_word
			if(cw_size == cw_used) { // i.e. current_word is full
				cw_size *= 2;
				current_word = realloc(current_word, cw_size * sizeof(char));
				if(current_word == NULL) exit(1);
			}
			current_word[cw_used] = chr;
			cw_used++;
			if(!in_escape) cw_cols++;
		}
	}
}
