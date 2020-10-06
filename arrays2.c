/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 4
   This program uses a function to look for groups of three consecutive integers on an array
*/
#include <stdio.h>

/* search_three
   The function uses two pointers to arrays of integers, one pointer to an integer, and one integer to return a integer. The first pointer runs through the array checking
   if the next two number are the same, if they are it updates the value of the second pointer to array so it shows which number has three consecutive.
   *a1 is the pointer that is used to run through the array with the integers
   *a2 is the pointer used to update the array with the numbers that have three consecutive
   n is the length of the array
   *num_three is the pointer used to update the amount of numbers that have three consecutive
   The function has no return value because it updates directly in the main function
*/

void search_three(int *a1, int *a2, int n, int *num_three){
    	int i, c=0;
    	for(i=0;i<n-2;i++){
        	if(*a1==*(a1+1)&&*a1==*(a1+2)){
            		*(a2++)=*(a1);
        		c++;
		}
        	a1++;
    	}
    	*num_three = c;
}

int main(){

    	int n, i, j; //Declaring the variables used for the length and on the loops

    	printf("Enter the length of the array: "); //Asks for the length of the array
    	scanf("%d", &n);
	printf("\n");

    	int arr1[n], arr2[n]; //Declares two arrays with the same length, one to store the integers and one to store the ones that have three consecutive

    	int numberOfThree;

    	printf("Enter the elements of the array: "); //Asks for the elements of the array
    	for(i=0;i<n;i++){
        	scanf("%d", &arr1[i]);
    	}
	printf("\n");

    	search_three(arr1, arr2, n, &numberOfThree); //Calls the function

    	if(numberOfThree==0){ //Checks if the updates number of integers with consecutive is zero
        	printf("The array does NOT contain identical consecutive elements\n");
    	}
    	else{ //If it is not zero it prints how many there are
        	printf("The array contains %d of three identical consecutive elements: ", numberOfThree);

            for(j=0;j<numberOfThree;j++){ //Prints the update values of the second array that contain the integer with consecutive on the original array
                printf("%d ", arr2[j]);
            }
    	}

    	printf("\n");

    	return 0;
}
