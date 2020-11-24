/***********************************************************
 * Ricardo Frumento U25167829                              *  
 * Project 10                                              *
 * This programs creates an ordered array of structures and*
 *  can add and delete elements. The new elements are      *
 *  included in the correct order.                         *
 **********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLASS_LEN 100
#define NAME_LEN 30
#define EMAIL_LEN 50

struct request{
	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];;

	struct request *next;
};

struct request *add(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *wait_list = NULL;
  printf("Operation Code: a for adding to the ordered list,"
	  " p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': wait_list = add(wait_list);
		break;
      case 'p': printList(wait_list);
                break;
      case 'q': clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/***********************************************************
 * add: This functions receives a pointer to an ordered    *
 * array of structures and adds one element in the correct *
 * position.                                               *
 **********************************************************/
struct request *add(struct request *list){

    char email[EMAIL_LEN+1];
    char class[CLASS_LEN+1];
    char fName[NAME_LEN+1];
    char lName[NAME_LEN+1];

    struct request *info1, *info2, *newRequest;

    printf("Enter email: "); //Requesting user input for the new element
    read_line(email,EMAIL_LEN+1);
    printf("Enter class: ");
    read_line(class,CLASS_LEN+1);
    printf("Enter first name: ");
    read_line(fName,NAME_LEN+1);
    printf("Enter last name: ");
    read_line(lName, NAME_LEN+1);

    for(info2 = list, info1 = NULL; info2 != NULL; info1 = info2, info2 = info2->next){ //Runs through the liked list
        if(strcmp(info2->class,class) > 0){ //Checks the class of two elements
            break;
        }
        if(strcmp(info2->class,class) == 0){
            if(strcmp(info2->last,lName) > 0){ //Checks the last name of two elements
                    break;
                }
        }
    }

    if(info2 != NULL && info1 != NULL){ //If the new element should be added between elements
            newRequest = malloc(sizeof(struct request)); //Allocating memory for the new node

            if(newRequest == NULL){
                printf("Operation did not work\n");
                return list;
            }

            strcpy(newRequest->email,email);
            strcpy(newRequest->class,class);
            strcpy(newRequest->first,fName);
            strcpy(newRequest->last,lName);
            newRequest->next = info2;
            info1->next = newRequest;
            return list;
    }
    else if(info2 == NULL && info1 == NULL){ //If the list is empty
            newRequest = malloc(sizeof(struct request)); //Allocating memory for the new node

            if(newRequest == NULL){
                printf("Operation did not work\n");
                return list;
            }

            strcpy(newRequest->email,email);
            strcpy(newRequest->class,class);
            strcpy(newRequest->first,fName);
            strcpy(newRequest->last,lName);
            newRequest->next = NULL;
            list = newRequest;
            return list;
    }
    else if(info2 != NULL && info1 == NULL){ //If the element should be added at the end of the ordered array
            newRequest = malloc(sizeof(struct request)); //Allocating memory for the new node

            if(newRequest == NULL){
                printf("Operation did not work\n");
                return list;
            }

            strcpy(newRequest->email,email);
            strcpy(newRequest->class,class);
            strcpy(newRequest->first,fName);
            strcpy(newRequest->last,lName);
            newRequest->next = info2;
            list = newRequest;
            return list;
    }
    else{ //If there is one element 
            newRequest = malloc(sizeof(struct request)); //Allocating memory for the new node

            if(newRequest == NULL){
                printf("Operation did not work\n");
                return list;
            }

            strcpy(newRequest->email,email);
            strcpy(newRequest->class,class);
            strcpy(newRequest->first,fName);
            strcpy(newRequest->last,lName);
            newRequest->next = info2;
            info1->next = newRequest;
            return list;
    }
}


/**********************************************************
 * printList: print the data  in the linked list passed   *
 * in as parameter                                        *
 **********************************************************/


void printList(struct request *list){

  struct request *p;

  printf("\nEmail\t\t\t\t\t\tFirst Name\tLast Name\t\t"
         "class\n");
  for (p =list; p != NULL; p = p->next)
    printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,
           p->class);

}

/*************************************************************
 * clearList: release the memory in the linked list passed   *
 * in as parameter                                           *
 *************************************************************/


void clearList(struct request *list)
{


  struct request *p;

  while(list!=NULL)
  {
         p = list;
         list = list->next;
         if(p!=NULL)
            free(p);
  }


}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;

   }
   str[i] = '\0';
   return i;
}
