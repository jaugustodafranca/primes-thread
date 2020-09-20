#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_args {
    int thread;
    int arg1;
    int arg2;
};

void *start_thread(void * arguments){
  struct thread_args *args = arguments;
  int thread = args -> thread;
  int arg1 = args -> arg1;
  int arg2 = args -> arg2;


  for (int i=arg1; i<=arg2; i++){
    int is_prime = 1;

    for(int j=2; j<=i/2; j++){
      if(i % j == 0){
        is_prime = 0;
        break;
      }
    }
    if(is_prime && i != 1){
      printf("THREAD: %d FOUND PRIME: %d\n", thread, i);
    }
  }

  return NULL;
}

int main(int args, char *argv[]) {
  int  limit, num_thread;
  if(args < 3){
    printf("\nError: You should add the limit number and the number of threads as execution params. e.g: ./file_name 1000 4\n");
    return 0;
  }


  limit = atoi(argv[1]);
  num_thread = atoi(argv[2]);
  int ratio = (limit/num_thread);
  pthread_t threads[num_thread];
  struct thread_args threads_structs[num_thread];

  for(int i=0; i<num_thread; i++){
    threads_structs[i].thread = i+1;
    threads_structs[i].arg1 = i*ratio+1;

    if(i == num_thread-1){
      threads_structs[i].arg2 = limit;
    }else{
      threads_structs[i].arg2 = (i+1)*ratio;
    }
    pthread_create(&threads[i], NULL, start_thread, (void *)&threads_structs[i]);
  }

  for(int j=0; j<num_thread; j++){
    pthread_join(threads[j], NULL);
  }

  pthread_exit(NULL);
  return 0;
}
