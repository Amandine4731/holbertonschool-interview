def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize a list for storing the minimum coins needed for each amount
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Base case: no coins are needed to make 0 amount

    # Iterate over all amounts from 1 to total
    for amount in range(1, total + 1):
        # Check each coin
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    # If dp[total] is still infinity, return -1 (it means we can't make the total with given coins)
    return dp[total] if dp[total] != float('inf') else -1

# Test the function with the given examples
print(makeChange([1, 2, 25], 37))  # Output: 7
print(makeChange([1256, 54, 48, 16, 102], 1453))  # Output: -1
