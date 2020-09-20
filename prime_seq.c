#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[]) {
  int  limit;

  if(args != 2){
    printf("\nError: You should add the limit number as execution param. e.g: ./file_name 1000\n");
    return 0;
  }

  limit = atoi(argv[1]);

  for (int i=2; i<=limit; i++){
    int is_prime = 1;

    for(int j=2; j<=i/2; j++){
      if(i % j == 0){
        is_prime = 0;
        break;
      }
    }

    if(is_prime){
      printf("\nPRIME %d", i);
    }
  }
  return 0;
}
