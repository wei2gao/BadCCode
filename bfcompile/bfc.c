#include <stdio.h>
#include <stdlib.h>
#define PR fprintf

int main(int argc, char **argv) {
	if (argc != 3) return 1;
	FILE *f1,*f2;
	if (f1 = fopen(argv[1],"r"),!f1)return(1);
	if (f2 = fopen(argv[2],"w"),!f2)return(1);
	PR(f2,"#include <stdio.h>\n#include<stdlib.h>\nint main(){\n");
	PR(f2,"int *tape = calloc(65536,sizeof(int));if(!tape) return 1;int *ptr = tape;");
	char next_instr;
	while (fscanf(f1,"%c",&next_instr) == 1) {
		switch(next_instr) {
		case '+':
			PR(f2,"++*ptr;");
			break;
		case '-':
			PR(f2,"--*ptr;");
			break;
		case '>':
			PR(f2,"++ptr;");
			break;
		case '<':	
			PR(f2,"--ptr;");
			break;
		case '.':
			PR(f2,"putc(*ptr,stdout);");
			break;
		case ',':
			PR(f2,"*ptr = getc(stdin);");
			break;
		case '[':
			PR(f2,"while(*ptr!=0){");
			break;
		case ']':
			PR(f2,"}\n");
			break;
		}
		if (next_instr == '\0') break;
	}
	PR(f2,"free(tape);return 0;\n}");
	fclose(f2);
	fclose(f1);

	return 0;	
}
