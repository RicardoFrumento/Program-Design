/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 5
   This program reads a string of characters and prints only the characters between the first two '*'.
*/
#include <stdio.h>

int read_line(char *str, int n); //Prototype of 'read_line' function

int search (char *s1, char *s2); //Prototype of 'search' function

int main (){

    int num; //Declaring variables. 'num' will be the size of the array between the '*' charcters
    int check; // Check will hold 1 if the input array has two '*' and 0 otherwise
    int max = 1000; //Max size of the input string
    char str1[max]; //Declaring input string

    printf("Enter input: \n");
    num = read_line(str1, max); //Calling 'reaf_line' function

    char str2[num]; //Declaring the string the will hold the characters between the first two '*'

    check = search(str1, str2); //Calls the function 'search'

    if(check == 1){
        printf("Output: %s\n", str2); //Prints the string with the characters between the first two '*'
    }
    else{
        printf("Output: Two * characters not found\n");
    }

    return 0;
}

/* read_line
   The function uses one pointer to an array of chars and one integer representing the maximum possible number of characters
   *str is the pointer that is used to run through the array
   n is the maximum length of the array
   i is the size of the string
*/
int read_line(char *str, int n){
    int ch, i=0;
    while((ch = getchar())!= '\n'){ //Checks when the '\n' is pressed, ending the string
        if(i < n){ //Checks if the maximum size has been reached
            *str++= ch; //Runs trough the string adding the characters
            i++;
        }
    }
    *str = '\0'; //Used to show the end of the string
    return i; //Returns the size of the string
}

/* search
   The function uses two pointers to arrays of characters. The first pointer runs through the input array checking
   for the end of the line character. If the character is '*' the counter is incremented by one and all the characters are added to the second array.
   *s1 is the pointer that is used to run through the input array
   *s2 is the pointer used to update the array with the characters between the first two '*'
   The function returns 1 if the input array contains two '*' and returns 0 otherwise
*/
int search(char *s1, char *s2){
    int count = 0; //Initializes the counter of '*' characters
    while(*s1 != '\0'){ //Checks for the end of array character
        if(count == 1){ //If one '*' character has been found the all the characters that follow are added to the second string
            *s2++= *s1;
        }
        else if(count == 2){ //If two '*' characters were found the function removes the last '*' and breaks the loop
            break;
        }
        if(*s1 == '*'){ //Checks if the first array has '*' character
            count++;
        }
        s1++;
    }
    if(count == 2){
         *--s2 = '\0'; //Removes the '*' character and adds the end of line character
        return 1;
    }
    else{
        return 0;
    }
}
