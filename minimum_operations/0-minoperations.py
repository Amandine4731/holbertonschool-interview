#!/usr/bin/python3
'''
    - Single character --> only copy and past
    = calculate the fewest number of operations needed.
    - Prototype: def minOperations(n)
    - Returns an integer
    - If n is impossible to achieve, return 0
'''


def minOperations(n):
    if n <= 1:
        return 0

    numberOperations = 0
    sum = 2

    while sum <= n:
        while n % sum == 0:
            numberOperations += sum
            n //= sum
        sum += 1

    return numberOperations
