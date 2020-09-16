#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// To compile use: gcc prime_seq.c -o fileName
// To execute use: ./fileName limit

int main(int args, char *argv[]) {
  int  limit, count;
  clock_t time;
	time = clock();

  bool isPrimo = true;
  if(args != 2){
    printf("\nError: You should add the limit number in the as execution param. e.g: ./fileName 1000\n");
    return 0;
  }

  limit = atoi(argv[1]);
  count = 0;

  for (int i=1; i<=limit; i++){
    isPrimo = true;

    for(int j=2; j<=i; j++){
      if(i % j == 0 && i != j){
        isPrimo = false;
      }
    }

    if(isPrimo){
      printf("PRIME: %d \n", i);
      count++;
    }
  }

  printf("\nTOTAL OF PRIMES: %d\n", count);
  printf("\nExecution time: %ld ms. \n",(clock() - time) / ((int)CLOCKS_PER_SEC/1000));

  return 0;
}
