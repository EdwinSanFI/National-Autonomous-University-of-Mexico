## Fibonacci sequence

Is the sequence of numbers where each number is the sum of the two preceding ones, starting from 0 and 1. The "F_n" is the n-th number in the sequence and the formula is:

```math
F_0 = 0
F_1 = 1

F_n = F_{n-1} + F_{n-2}
```

<p align="center">
  <img src="https://user-images.githubusercontent.com/6312342/165682339-436a19de-994d-4366-ae0a-bb533000af22.png">
</p>

For this practice you need to use the Virtual Environment to install **matplotlib** and run the code.

### Iterative Fibonacci

Goes from 0 to n and calculates the Fibonacci number for each one.

```python
def fib(n):
  f0 = 0   # O(1)
  f1 = 1   # O(1)
  if n == 0 or n == 1:
    return 1
  for _ in range(2, n+1):    # O(n)
    fn = f0 + f1    # O(1) * n
    f0 = f1    # O(1) * n
    f1 = fn    # O(1) * n
  return fn    # O(n)
```

<p align="center">
  <img src="./Fibonacci Iteractivo.png">
</p>

### Recursive Fibonacci

Time complexity: O(2^n)

```python
def fibo_recursive(n):
  if n == 0 or n == 1:
    return 1
  return fibo_recursive(n-1) + fibo_recursive(n-2) # O(n^c)
```

<p align="center">
  <img src="./Fibonacci Recursivo.png">
</p>

With this we can see that the recursive function is very slow, because it has a lot of repeated calculations and the iterative function is much faster.