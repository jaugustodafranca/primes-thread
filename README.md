# primes-thread

## Subject Parallel and Distributed Computing (INE5645) at Federal University of Santa Catarina.

Compare performance to find primes numbers between sequential and parallel (multi threads) code using C.

## Instructions
Compile sequential:
```c
gcc prime_seq.c -o prime_seq
```
Execute:
```c
./prime_seq [limit]
```

Compile parallel:
```c
gcc prime_parallel.c -o prime_parallel
```
Execute:
```c
./prime_parallel [limit] [threads]
```


| Parameters | Type | Description  |
| :-----: |:-----:| ----- |
| limit     | int | The code will check all the primes numbers until the limit |
| threads     | int | Number of thread to execute in parallel  |
