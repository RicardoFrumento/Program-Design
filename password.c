/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 3
   This program evaluates an array with random generated entries and displays if it would be a strong password or not
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));

    void generate_values(int a[], int n){//Defines the function to create the array entries, it receives an array of integers and an integer
        int i;

        for(i=0;i<n;i++){
            a[i]=(rand()%94)+33;//Creates and places a random number for every entry on the array
        }
    }

    int is_strong_password(int a[], int n){//Defines the function that will check if the password is strong. It receives an array of integers and an integer
        int i;
        int strength;
        int upperCase=0, lowerCase=0, digit=0, specialChar=0;//Initializes the values for every kind of character possible

        for(i=0;i<n;i++){
            if((a[i]>=33 &&a[i]<=47) || (a[i]>=58 && a[i]<=64) || (a[i]>=91 && a[i]<=96) || (a[i]>=123 && a[i]<=126)){//Checks if the array has special characters
                specialChar = 1;
            }
            else if(a[i]>=48 && a[i]<=57){//Checks if the array has a number
                digit = 1;
            }
            else if(a[i]>=65 && a[i]<=90){//Checks if the array has an upper case letter
                upperCase = 1;
            }
            else if(a[i]>=97 && a[i]<=122){//Checks if the array has an lower case letter
                lowerCase = 1;
            }

            if(a[i]==60 || a[i]==62){//checks if the array has the forbidden characters '<' and '>'
                strength=0;
                break;
            }
        }
        strength = specialChar+digit+lowerCase+upperCase;//Adds all the check  values
        if(strength==4){
            return 1;
        }
        else{
            return 0;
        }
    }

    int length= (rand()%8)+8;//Declares a random number that is going to be the length of the array
    int characters[length];//Declares an array AFTER the length is created
    int check;
    int j;

    generate_values(characters, length);//Calls the function to populate the array with random numbers

    for(j=0;j<length;j++){
        printf("%c", characters[j]);//Prints the array

    }

    check = is_strong_password(characters, length);//Calls the function to check if the array is a strong pasword

    if(check){//Checks if check is 1 or 0
        printf("\nA strong password\n");
    }
    else{
        printf("\nNOT a strong password\n");
    }

    return 0;
}
