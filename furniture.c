/* Ricardo Digiovanni Frumento U25167829
   COP3514 Project 1
   This program has an array of arrays where each row represents a furniture and every column the information about it.
   The program shows a menu with options and then asks for two entries from the user, the furniture selected the number of months rented.
   There is a check to see if both are valid and if they are not an error message is displayed. If they are the program displays the amount due.
*/
#include<stdio.h>

int main(void){

	int database[5][3] = {{20, 12, 100},
			{15, 10, 80},
			{25, 8, 105},
			{10, 5, 50},
                     	{25, 10, 120}}; //Database. First Column: Initial rent; Second Column: Monthly rent; Third Column: Max annual value

    	int furSele; //Furniture Selection
    	int monRen; //Months Rented
    	int amoDue; //Amount Due
    
	printf("Please select from the following menu: 1. Sofa, 2. Loveseat, 3. 4 Post Bed, 4. Dresser, 5. Kitchen Table\n");
    	printf("Enter furniture selection: "); //Displays the menu and asks for the furniture selection
	scanf("%d", &furSele);
	
    	if(0<furSele && 6>furSele){ //Checks if furniture selection is valid

		printf("Enter months rented: ");//Asks for the months rented
		scanf("%d", &monRen);

        	if(monRen>0){ //Checks if months rented is valid

			furSele--; //Arrays in C start at 0 and our menu starts at 1
			monRen--; //The first month has a different value from the rest that is why it is deducted one here
            		amoDue = database[furSele][0]+(monRen)*database[furSele][1]; //Finds how much is due

            		if(amoDue>database[furSele][2]){ //Checks if the amount due is not over the maximum value per year
                		monRen++; //Recreates the value of months rented entered
				amoDue = (monRen/12)*database[furSele][2]+(monRen%12)*database[furSele][1]; //Finds the new value for amount due
            		}

            		printf("Amount due ($): %d\n", amoDue); //Prints what is owned
        	}
        	else{
            		printf("Invalid input. Enter a positive number for months rented.\n"); //Error message for the months rented
        	}
    	}
	else{
        	printf("Invalid input. The input should be in the range of 1 to 5.\n"); //Error message for the furniture selection
    	}

    	return 0;
}
