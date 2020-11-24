/*********************************************
 * Ricardo Frumento U25167829                *
 * Project 10                                *
 * Thie program reads a file with several    *
 * anials and creates two files, one for dogs*
 * and one for cats, both sorted by age      *
 ********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct animal { //Defining the structure that will hold all the animals's information
    char name[100]; //Array of characters to hold the name
    char species[100]; //Array of characters to hold the species
    char gender[100]; //Array of characters to hold the gender
    int age; // Integer to hold the age
    float weight; // Float to hold the weight
};

int comparison(const void *element1, const void *element2); //Prototype of the comparison function used in qsort

int main(){
    char nameInput[100]; //Buffer to hold the source file name
    struct animal listOfAnimal[200]; //Initializing the array to hold the structure elements
    char lineInput[10000]; //Buffer to hold one line of the file
    int i=0; //Integer used to hold the total amount of animals
    int j;
    FILE *filePointerInput; //Declaring pointers to the files used on the program
    FILE *filePointerOutput1;
    FILE *filePointerOutput2;

    printf("Enter the file name: "); //Asks for the source file name
    fgets(nameInput, 100, stdin);
    printf("\n");
    strtok(nameInput, "\n"); //Removes the new line character from the source file name

    filePointerInput = fopen(nameInput, "r"); //Opens the file to be used
    filePointerOutput1 = fopen("sorted_dogs.txt", "w"); //Creates the files to store the desired information
    filePointerOutput2 = fopen("sorted_cats.txt", "w");

    if(filePointerInput != NULL){ //Checks if the file opened correctly
        while(fgets(lineInput, 10000, filePointerInput)!=NULL){ //Reads one line and moves to the next until the buffer is empty
	    sscanf(lineInput, "%s %s %s %i %f", listOfAnimal[i].name, listOfAnimal[i].species, listOfAnimal[i].gender, &listOfAnimal[i].age, &listOfAnimal[i].weight);
	    //stores the information on one element of the array of structures
            i++; //Counts how many animals there is
        }
    }
    else{
        printf("The file did not open correctly!\n"); //Error message displayed if the file did not exist or opened incorrectly
    }

    qsort(listOfAnimal, i, sizeof(struct animal), comparison); //Calling the qsort function to sort the animals

    for(j=0;j<i;j++){ //Loop to create and specific animals one each line
        if(strcmp(listOfAnimal[j].species,"dog")==0){ //Checks if the animal is a dog
            fprintf(filePointerOutput1, "%-20s%6s%10i%10.2f\n", listOfAnimal[j].name, listOfAnimal[j].gender, listOfAnimal[j].age, listOfAnimal[j].weight);
            //Prints the desired information to the file
        }
        if(strcmp(listOfAnimal[j].species,"cat")==0){ //Checks if the animal is a cat
            fprintf(filePointerOutput2, "%-20s%6s%10i%10.2f\n", listOfAnimal[j].name, listOfAnimal[j].gender, listOfAnimal[j].age, listOfAnimal[j].weight);
            //Prints the desired information to the file
        }
    }

    fclose(filePointerInput); //Closes the three files used
    fclose(filePointerOutput1);
    fclose(filePointerOutput2);

    return 0;
}

/***************************************************
 * comparison: This function compares two structs  *
 * and gives the result for the qsort function     *
 * A negative number, zero or positive number will *
 * have different effects                          *
 **************************************************/
int comparison(const void *element1, const void *element2){
    return ((struct animal*)element1)->age - ((struct animal*)element2)->age;
}
