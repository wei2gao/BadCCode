#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#define SIZE UINT_MAX/16
#define STACK_SIZE 1024
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	FILE *infile;
	if ((infile = fopen(argv[1],"r"),!infile))return(1);	
	char *instructions = malloc(SIZE*sizeof(char));
	if (!instructions) return 1;
	int *tape = calloc(SIZE,sizeof(int));
	if (!tape) return 1;
	char **stack = malloc(STACK_SIZE*sizeof(char*));
	if (!stack) return 1;
	char *ptr = instructions;
	int *t_idx=tape;
	char **s_idx=stack; // tape and stack pointers
	char next;
	int size=0;
	while((fscanf(infile,"%c",&next)==1)) {
		*ptr = next;
		++ptr,++size;
	}
	ptr = instructions;
	while(ptr) {
		//printf("%c",c);
		//printf("%d",(int)*t_idx);
		switch(*ptr) {
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
			*s_idx = ptr;
			++s_idx;
			break;

		case ']':
			if (*t_idx==0) {
				--s_idx; // pop value but pointer increment as normal
				break;
			}
			ptr = *(s_idx-1);
			// FIXME: breaks on nested loops 
			break;

		}	
		if (*ptr=='\0') break; // halt when end of instructions reached
		// TODO: make index increment less stupid
		++ptr;
	}
	free(tape);
	free(stack);
	return 0;
error: return (free(tape),free(stack),fprintf(stderr,"Error!"),-1);
}
