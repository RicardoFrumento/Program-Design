/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 5
   This program receives from the command line series of characters and prints only the consonants in it.
*/
#include <stdio.h>

int main(int argc, char *argv[]){

    int i;

    if(argc == 1){ //Checks if there is only one input (the name of the function) in the command line
        printf("Usage: ./a.out input");
    }
    if(argc>=2){
        for(i=1;i<argc;i++){
            while(*argv[i] != '\0'){ //Runs the loop until '\n' (new line character) shows up
                if((*argv[i]>='a' && *argv[i]<='z') || (*argv[i]>='A' && *argv[i]<='Z')){ //checks if the user input is a letter
                    if(*argv[i] != 'a' && *argv[1] != 'e' && *argv[1] != 'i' && *argv[i] != 'o' &&
                    *argv[i] != 'u' && *argv[i] != 'A' && *argv[i] != 'E' && *argv[i] != 'I' &&
                        *argv[i] != 'O' && *argv[i] != 'U'){ //Checks if the user input is not a vowel
                                printf("%c", *argv[i]); //Prints the character
                    }
                }
                argv[i]++; //Increments to the next command line input
            }
        }
    }

	printf("\n");

	return 0;
}
