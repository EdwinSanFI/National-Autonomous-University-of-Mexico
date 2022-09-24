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


```python
def fib(n):
    """Return the n-th number in the Fibonacci sequence."""
    pass
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