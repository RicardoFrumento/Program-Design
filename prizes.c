/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 1
   This program has an array with the possible prizes. The program asks if the user wants to play. If it does a random number is generated and the corresponding entry
   on the array is displayed. If the entry is a prize the program ends, if the entry is 'Play Again' the program asks if the user wants to play and the process repeats
   itself, if the entry is 'Star' a message saying the user won 4000 coins appears and then asks if it wants to play again.
   If the user decides to not play a message is displayed 'Thank you for playing'.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void){
    srand(time(NULL)); //Seeds the function rand()

    int choice=-1; //Initializes the variable responsible for the while loop
    int num; //Initializes the variable used in rand()
    char prizes[12][20] = {"Pizza", "Shirt", "Sweater", "Raspberry", "Brown Sugar", "Star", "Butter",
                            "Apple", "Blackberry Jelly", "Strawberry Cake", "Bacon", "Play Again"}; //Initializes the array of prizes

    while(choice){
        printf("Would you like to play? (press 1 to play or 0 to quit)? "); //Asks the user input
        scanf("%d", &choice);
        if(choice==0){ //Checks if it is zero and ends the loop
            printf("Thank you for playing\n");
            break;
        }
        num = (rand()%12); //Generates a ramdom number between 0 and 11
	if(strcmp(prizes[num], "Star") == 0){ //Checks if the string on the entry corresponding to the num variable is 'Star'
            printf("%s\n", prizes[num]);
            printf("Congratulations! You have won 4000 coins\n");
        }
        else if(strcmp(prizes[num], "Play Again") == 0){ //Checks if the string on the entry corresponding to the num variable is 'Play Again'
            printf("%s\n", prizes[num]);
        }
        else{ //Prints the prize
           printf("%s\n", prizes[num]);
           choice=0;
        }
    }

    return 0;
}
