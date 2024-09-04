/*
Examine the provided C code, which consists of multiple functions. Your objective is to identify the functions which are vulnerable, explain the reasons for their vulnerability, and justify why the remaining functions are not susceptible. Describe a potential attack approach exploiting the vulnerable functions and propose mitigation strategies to address these vulnerabilities.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int secret;

int copy(char *str)
{
	char buffer[12];
	int guard;
	guard = secret;
	strcpy(buffer, str);    
	//strncpy(buffer, str, Num1);
	//buffer[Num1]='\0'; //Ensure the destination string is null terminated           
	if(guard == secret)
		return 1;
	else
		exit(0);	
}

int concatenation(char *str, char *buffer){

	strcat(str, buffer);  
 	printf("Concatenated string:");
 	//printf(str);
 	printf("%s",str);

}

int main(int argc, char **argv)
{
	int Num1, Num2;
	char *str,Num;
	char *buffer;
	
	printf("Enter two positive integers ");
	scanf("%d %d", &Num1, &Num2);
	
	str = (char *)malloc(Num1*sizeof(char));
	buffer = (char *)malloc(Num2*sizeof(char)); 
	
	srand(time(NULL));
	secret = rand()&0xffff;
	FILE *file;
	
	file = fopen("file", "r");
	fread(str, sizeof(char), Num1, file);
	copy(str);
		
	gets(buffer);
	//fgets(buffer, Num2, stdin);
	         
	
	Num=Num1+Num2; 
	
	if(Num < 100)
		concatenation(str,buffer);
	
	return 1;
}

