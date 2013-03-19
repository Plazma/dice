#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {

  FILE *die1 = NULL;
  FILE *die2 = NULL;

  int die1LEN = 0;
  int die2LEN = 0;

  char *die1BYTES = NULL;
  char *die2BYTES = NULL;

  /* Open Die 1 */

  if ((die1 = fopen("die1.txt", "r")) == NULL) {
    printf("\nError: Cannot read file die1.txt!\n");
    exit(1);
  }

  fseek(die1, 0, SEEK_END);
  die1LEN = ftell(die1);

  if ((die1BYTES = malloc(die1LEN * sizeof(char) + 1)) == NULL) {
    printf("\nFailed to allocate memory for die1.\n");
    fclose(die1);
    exit(1);
  }

  fseek(die1, SEEK_SET, 0);
  fread(die1BYTES, sizeof(char), die1LEN, die1);
  die1BYTES[die1LEN + 1] = '\0';

  /* Open Die 2 */

  if ((die2 = fopen("die2.txt", "r")) == NULL) {
    printf("\nError: Cannot read file die2.txt!\n");
    exit(1);
  }

  fseek(die2, 0, SEEK_END);
  die2LEN = ftell(die2);

  if ((die2BYTES = malloc(die2LEN * sizeof(char) + 1)) == NULL) {
    printf("\nFailed to allocate memory for die2.\n");
    fclose(die2);
    exit(1);
  }

  fseek(die2, SEEK_SET, 0);
  fread(die2BYTES, sizeof(char), die2LEN, die2);
  die2BYTES[die2LEN + 1] = '\0';

  printf("\n\n*** DICE LOADED ***!\n\n");

  return 0;

}
