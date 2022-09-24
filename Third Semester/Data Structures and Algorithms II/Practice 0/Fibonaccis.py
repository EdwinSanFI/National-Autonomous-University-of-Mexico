##################################
# @author: Edwin Santiago
# Obtiene la secuencia de fibonacci, el tiempo de ejecución y realiza
# graficas conforme a los datos arrojados
##################################

from time import perf_counter

import matplotlib.pyplot as plt

# X = Fibonacci number
# Y = Time of execution in seconds

x_recursive = []
y_recursive = []

x_iterative = []
y_iterative = []

"""
> The function returns the sum of the two previous numbers in the sequence

:param n: the number of fibonacci numbers to generate
:return: The nth number in the fibonacci sequence.
"""
def fibo_recursive(n):
    if n == 0 or n == 1:
        return 1
    return fibo_recursive(n-1) + fibo_recursive(n-2) # O(n^c)

# 2 + n^c = O(2 + n^c) = O(n^c)
# Exponential complexity O(n^c)

"""
It takes the sum of the previous two numbers in the sequence and returns the nth number in the
sequence

:param n: The number of the Fibonacci sequence to be calculated
:return: The nth number of the Fibonacci sequence
"""
def fib_iterativo(n):
    f0 = 0   # O(1)
    f1 = 1   # O(1)
    if n == 0 or n == 1:
        return 1
    for _ in range(2, n+1):    # O(n)
        fn = f0 + f1    # O(1) * n
        f0 = f1    # O(1) * n
        f1 = fn    # O(1) * n
    return fn    # O(n)

# 4 + 3n = O(4 + 3n) = O(n)
# Lineal Complexity O(n)

def calculate_time():
    n = 40

    print("\n**Fibonacci recursive**")
    for i in range (0, n+1):
        # Start the timer
        initial_time = perf_counter()
        fibb_rec = fibo_recursive(i)
        # Stop the timer
        final_time = perf_counter()
        tiempo = final_time - initial_time

        x_recursive.append(i)
        y_recursive.append(tiempo)

        print(f'The Fibonacci number of {i} is {fibb_rec} and took: {tiempo}[s]')
    print("\n")

    print("**Fibonacci Iterativo**")
    for i in range (0, n+1):
        initial_time = perf_counter()
        fibb_ite = fib_iterativo(i)
        final_time = perf_counter()
        tiempo = final_time - initial_time

        x_iterative.append(i)
        y_iterative.append(tiempo)

        print(f'El numero {i} de Fibo es {fibb_ite} y tardó: {tiempo}[s]')
    print("\n")

def graficar():
    # Fibonacci recursive
    plt.scatter(x_recursive, y_recursive)
    # Title of the X axis
    plt.xlabel("N")
    # Title of the Y axis
    plt.ylabel("Segundos[s]")
    # Title of the graph
    plt.title("Fibonacci recursive", fontdict={'family': 'serif', 'color': 'red', 'size': 20})
    # Add grid
    plt.grid(True)
    # Generate the image
    plt.show()

    # Fibonacci iterative
    plt.scatter(x_iterative, y_iterative)
    # Title of the X axis
    plt.xlabel("N")
    # Title of the Y axis
    plt.ylabel("Segundos[s]")
    # Title of the graph
    plt.title("Fibonacci iterative", fontdict={'family': 'serif', 'color': 'red', 'size': 20})
    # Add grid
    plt.grid(True)
    # Generate the image
    plt.show()

if __name__ == '__main__':
    calculate_time()
    graficar()