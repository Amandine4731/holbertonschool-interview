#!/usr/bin/python3
''' prime game '''



def isWinner(x, nums):
    ''' Helper function to calculate primes up to a maximum value using Sieve of Eratosthenes '''
    def sieve(max_num):
        is_prime = [True] * (max_num + 1)
        p = 2
        while (p * p <= max_num):
            if (is_prime[p] == True):
                for i in range(p * p, max_num + 1, p):
                    is_prime[i] = False
            p += 1
        prime_count = [0] * (max_num + 1)
        for p in range(2, max_num + 1):
            if is_prime[p]:
                prime_count[p] = 1
        for i in range(1, max_num + 1):
            prime_count[i] += prime_count[i - 1]
        return prime_count

    if x == 0:
        return None

    max_n = max(nums)
    prime_count = sieve(max_n)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
