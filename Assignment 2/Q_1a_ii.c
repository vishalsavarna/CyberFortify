#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <time.h>

int secret;

int copy(char *str)
{
char buffer[12];
int guard;
guard=secret;
strcpy(buffer, str); 
if (guard == secret)
    return 1;
else
    exit(0);
}

int concatenation (char *str, char *buffer)
{
strcat(str, buffer);
printf("Concatenated string: ");
printf(str);
}

int main(int argc, char **argv)
{
int Num1, Num2; 
char *str, Num; 
char *buffer;

printf("Enter two positive integers "); 
scanf("%d %d", &Num1, &Num2);

str = (char *)malloc(Num1* sizeof(char)); 
buffer = (char *)malloc(Num2* sizeof(char));

srand(time(NULL)); 
secret = rand()&0xffff; //16 bits = 2 Bytes
FILE *file;

file = fopen("file", "r"); 
fread(str, sizeof(char), Num1, file); //str m likhna hai, size num1, from file
//We need to touch the file
copy(str);

gets(buffer);

Num=Num1+Num2;

if (Num<100)
{
    concatenation(str, buffer);
}

return 1;
}