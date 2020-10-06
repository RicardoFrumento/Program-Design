/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 1
   This program reads an series of characters until the user presses the enter key and prints only the consonants in it.
*/
#include <stdio.h>

int main(void){

	char userInput; //Initializes the variable that holds the user input

	while((userInput=getchar())!= '\n'){ //Checks if the user input is not '\n' (new line character
		if((userInput>='a' && userInput<='z') || (userInput>='A' && userInput<='Z')){ //checks if the user input is a letter
			if(userInput != 'a' && userInput != 'e' && userInput != 'i' && userInput != 'o' &&
			userInput != 'u' && userInput != 'A' && userInput != 'E' && userInput != 'I' &&
		     	userInput != 'O' && userInput != 'U'){ //Checks if the user input is not a vowel
                		printf("%c", userInput); //Prints the user input
			}
		}
	}
	printf("\n");
    return 0;
}
