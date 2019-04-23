// Read a file of numbers and print their sum
#include <stdio.h>
#include <stdlib.h>
int main() {FILE*i;int s=0,n,S;
if((i=fopen("num.txt","r"),i==NULL))return(!i);
for(;;)if(S=fscanf(i,"%d",&n),s+=(S==1)?(n):(0),S!=1)break; 
return(printf("%d\n",s),fclose(i),0);}
