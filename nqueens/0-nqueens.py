#!/usr/bin/python3
""" - The N queens puzzle is the challenge
    of placing N non-attacking queens on an N×N chessboard.
    - Write a program that solves the N queens problem.
"""


import sys


def nqueens(N):
    """ N queens """

    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        N = int(N)
    except ValueError:
        print('N must be a number')
        exit(1)

    if N < 4:
        print('N must be at least 4')
        exit(1)


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    nqueens(sys.argv[1])
