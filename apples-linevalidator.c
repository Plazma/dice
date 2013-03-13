#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 200

char *getvalid(const char *prompt, int (*valid)(const char*)) {
  char   buf[BUFSIZE];
  size_t idx;
  
  printf("%s", prompt);
  while(fgets(buf, sizeof buf, stdin)) {
    idx = strcspn(buf, "\n");
    
    /* line was too long */
    if(!buf[idx])
      return NULL;
    
    buf[idx] = 0;
    if(valid(buf)) {
      char *out = malloc(idx + 1);
      if(out == NULL)
        return NULL;
      return memcpy(out, buf, idx + 1);
    }
    
    printf("%s", prompt);
  }

  return NULL;
}

int valid_int(const char *line) {
  for(; *line; ++line)
    if(!isdigit(*line)) return 0;
  return 1;
}

int main() {
  char *line = getvalid("Enter a number: ", valid_int);
  
  printf("You entered: %d", strtol(line, NULL, 0));
  free(line);
  
  return 0;
}