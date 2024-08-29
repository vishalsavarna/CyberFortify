#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void Function1 (char *input, int num) {
printf("Entered number: %d\n", num); 
printf("Your input: ");
printf(input);
printf("\n");

int result = num * 2;
printf("Result of num* 2: %d\n", result);
}

void Function2 (const char *message) 
{ 
printf("The Function Output: %s\n", message); 
int len = strlen(message);
printf("Length of message: %d\n", len);
}

void Function3 (char *input1, char *input2) 
{
printf("Your inputs: %s, %s\n", input1, input2); 
printf("Input1: ");
printf(input1); 
printf("\n");
printf("Input2: ");
printf(input2);
printf("\n");

int areEqual = strcmp(input1, input2); 
    if (areEqual == 0) 
    {printf("Inputs are equal.\n");} 
    else {printf("Inputs are not equal.\n");}
}
void Function4(const char *name, int age) 
{ 
    printf("Name: %s, Age: %d\n", name, age); 
    if (age >= 18) {printf("%s is an adult.\n", name);} 
    else { printf("%s is a minor.\n", name); }
}

void Function5 (char *input) 
{ 
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "Received: %s", input); 
    printf("Formatted: %s\n", buffer); 
    char reversed [100];
    int len = strlen(input);
    for (int i = 0; i < len; i++) { reversed[i] = input[len - i - 1];}
    reversed[len] = '\0';
    printf("Reversed input: %s\n", reversed);
}

int main() {
char userProvidedInput[100];
char fixedMessage[] = "This is a safe fixed message."; 
int number = 42;
printf("Please enter a message: "); 
scanf("%99s", userProvidedInput);
Function1(userProvidedInput, number);
Function2(fixedMessage);
Function3 (userProvidedInput, fixedMessage);
Function4("Alice", 28);
printf("Please enter a message: "); 
scanf("%99s", userProvidedInput); 
Function5(userProvidedInput);
return 0;
}
