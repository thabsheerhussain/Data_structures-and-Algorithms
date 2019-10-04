# Implementation of Matrix Chain Multiplication in Python
# Time Complexity: O(n^3)
# Space Complexity: O(n^2)

from math import inf

def matrixChain(arr):
	n = len(arr)
	dp = [[0]*n for i in range(n)]
	# dp[i, j] = Minimum number of scalar multiplications needed to multiply arr[i..j]

	# chain length
	for length in range(2, n):
		for l in range(1, n-length+1):
			r = l + length - 1
			dp[l][r] = inf
			for c in range(l, r):
				# cost of left cut + cost of right cut + cost of merging
				cost = dp[l][c] + dp[c+1][r] + arr[l-1]*arr[c]*arr[r]
				dp[l][r] = min(dp[l][r], cost)
	return dp[1][n-1]
