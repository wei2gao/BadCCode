// Find the minimum and maximum value in an input file of numbers
#include <stdio.h>
#include <limits.h>
#define max INT_MAX
#define min INT_MIN
int main(int argc, char **argv) {
	FILE*f;int n,m=max,M=min;
	if (f=fopen(argv[1],"r"),!f)return(!f);
	for(;(fscanf(f,"%d",&n)==1);m=(n<m)?n:m,M=(n>M)?n:M);
	return(printf("max:%d min:%d\n",M,m),fclose(f),0);
}	
