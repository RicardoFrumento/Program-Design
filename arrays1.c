/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 4
   This program reads an array of integers and uses a function to find, if there is a zero among the integers, and split the array on the zero.
*/
#include <stdio.h>

/* compute
   The function uses one pointer to arrays of integers, and one integer to return a integer. The first pointer runs through the array checking if there are any zeros on it.
   Assuming it finds one, the function returns the index of the zero.
   *a is the pointer that is used to run through the array
   n is the length of the array
   If there are zeros the function returns i, which is the current index that the pointer is assigned
*/
int compute(int *a, int n){
	int i;

    	for(i=0;i<n;i++){
        	if(*(a+i)==0){
            	return i;
        	}
    	}
    	return 0;
}

int main(){

    	int n, i, j, k; //Declaring the variables to use on the loops and the one used to store the length of the array

    	printf("Enter the length of the array: "); //Asks for the length of the array
    	scanf("%d", &n);
	printf("\n");
    	int a[n]; //Declares the array after the user input

    	printf("Enter the elements of the array: "); //Asks for the elements of the array using a for loop to go through every index
    	for(i=0;i<n;i++){
        	scanf("%d", &a[i]);
    	}
	printf("\n");

    	printf("Array 1: ");

    	for(j=0;j<compute(a, n);j++){ //Uses the function compute as the upper limit for printing the original array, this excludes the index corresponding to zero
        	printf("%d ", a[j]);
    	}
    	printf("\nArray 2: ");

    	for(k=compute(a, n)+1;k<n;k++){ //Uses the function compute plus one as the lower limit for printing the original array, this excludes the index corresponding to zero
        	printf("%d ", a[k]);
    	}
    	printf("\n");
    	return 0;
}
