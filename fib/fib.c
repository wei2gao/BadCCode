#include <stdio.h>

int main() {

	unsigned long long a=0,b=1,c=(printf("1\n"),0),d;
	for(d=0;d<50;(c=a+b,printf("%llu\n",c),a=b,b=c,d+=c/c));
	return 0;
}
