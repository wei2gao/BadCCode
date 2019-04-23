// brainfuck interpreter for up to 2048 instructions
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#define SIZE UINT_MAX
#define STACK_SIZE 1024
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	FILE *infile;
	if ((infile = fopen(argv[1],"r"),!infile))return(1);	
	char *instructions = malloc(SIZE*sizeof(char));
	if (!instructions) return 1;
	char *tape = calloc(SIZE,sizeof(char));
	if (!tape) return 1;
	char **stack = malloc(STACK_SIZE*sizeof(char*));
	if (!stack) return 1;
	char *ptr = instructions;
	char *t_idx=tape, **s_idx=stack; // tape and stack pointers
	char next;
	int size=0;
	while((fscanf(infile,"%c",&next)==1)) {
		*ptr = next;
		++ptr,++size;
	}
	ptr = instructions;
	for (int i = 0; i<size;i++) {
		char c = *(ptr+i);
		switch(c) {
		case '>':
			t_idx++;
			break;
		case '<':
			t_idx--;
			break;
		case '+':
			++*t_idx;
			break;
		case '-':
			--*t_idx;
			break;
		case '.':
			putc(*t_idx,stdout);
			break;
		case ',':
			;char c = getc(stdin);
			*t_idx = c;
			break;
		case '[':
			// FIXME: of course it's broken
			// Push index to stack
			*s_idx = t_idx;
			++s_idx;
			break;

		case ']':
			// Pop index from stack and try to set pointer to it	
			t_idx = *s_idx;
			--s_idx;
			break;
		}		
	}
	free(tape);
	free(stack);
	return 0;
error: return (free(tape),free(stack),fprintf(stderr,"Error!"),-1);
}
