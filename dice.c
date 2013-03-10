#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dice.h"

void getHelp() {

printf("\n\t************ HELP ***************\t\n\n");
printf("Make sure the program is in the same folder as the files die1.txt and die2.txt\n");
printf("\nFollow the menu, it should be self explanatory\n");
printf("\n\t************ HELP ***************\t\n\n");

}

void loadDice() {

  FILE *die1 = NULL;
  FILE *die2 = NULL;
  int die1LEN = 0;
  int die2LEN = 0;
  char *die1Bytes = NULL;
  char *die2Bytes = NULL;

/* Die 1 open and checks */

  if ((die1 = fopen("die1.txt", "r")) == NULL) {
    printf("\nError: Cannot read file die1.txt!\n");
    exit(1);
  }

  fseek(die1, 0, SEEK_END);
  die1LEN = ftell(die1);

  if ((die1Bytes = malloc(die1LEN * sizeof(char) + 1)) == NULL) {
    printf("\nFailed to allocate memory for die1.\n");
    fclose(die1);
    exit(1);
  }

  fseek(die1, SEEK_SET, 0);
  fread(die1Bytes, sizeof(char), die1LEN, die1);
  die1Bytes[die1LEN + 1] = '\0';

  //printf("File1:\n%s\n\n", die1Bytes);


/* die2 open and checks */
  /* Check to see if we can open die2 */
  if ((die2 = fopen("die2.txt", "r")) == NULL) {
    printf("\nError: Cannot read file die2.txt!\n");
    exit(1);
  }

  fseek(die2, 0, SEEK_END);
  die2LEN = ftell(die2);

if ((die2Bytes = malloc(die2LEN * sizeof(char) + 1)) == NULL) {
    printf("\nFailed to allocate memory for die2.\n");
    fclose(die2);
    exit(1);
  }

  fseek(die2, SEEK_SET, 0);
  fread(die2Bytes, sizeof(char), die2LEN, die2);
  die2Bytes[die2LEN + 1] = '\0';

  //printf("File2:\n%s\n\n", die2Bytes);

  printf("\n\n*** Dice Loaded! ***\n\n");


}

int main(void) {

    char selection[2];
    int flag = 0;
    int val;
    
    do {
        printf("\n\t\t***THINGAMAJIGGER***\t\t\n\n");
     
        printf("\t1. Load Dice\t\n");
        printf("\t2. Roll Dice\t\n");
        printf("\t3. Help\t\n");
        printf("\t4. Quit\t\n");
        printf("\nEnter a selection: ");
        
        /* Get a single char and return */
        fgets(selection, 3, stdin);
        sscanf(selection,"%d",&val);

        switch(val) {
            
        case 1:
            loadDice(); 
            flag = 0;
            break;
            
        case 2:
           /* diceRoll */ 
            flag = 0;
            break;

        case 3:    
            getHelp();
            break;

        case 4:
            printf("\nExiting!\n");
            flag = 1;
            exit(0);
            break;
            
        default:
            printf("\n\nError: Invalid Selection\n");
            flag = 0;
            /* Flushing stdin of \n and other stuff */
            fflush(stdin);
            break;
        }  

    } while(!flag);  

  return 0;

}
