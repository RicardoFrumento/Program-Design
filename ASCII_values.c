/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 3
   This programs creates a random number n that will be the length for an array. After that the program
   generates n random numbers that will be printed as characters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));//Seeds the function

    void generate_values(int a[], int n){//Declaration of a function that receives an array of integers and an integer to create random entries for the array
        int i;

        for(i=0;i<n;i++){
            a[i]=(rand()%94)+33;//This loop creates and places a random number for every entry on the array
        }
    }

    int length= (rand()%8)+8;//Generates a random length for the array
    int characters[length];//Declares the array AFTER the length is generated
    int j;

    generate_values(characters, length);//Calls the function

    for(j=0;j<length;j++){
        printf("%c", characters[j]);//Prints the array

    }

    return 0;
}
