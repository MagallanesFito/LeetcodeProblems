def commonChild(s1, s2):
	m = len(s1)
	n = len(s2)
	dp = [[0]*(n+1) for i in range(2)]
	print(dp)

	for i in range(m):
		bi = i&1
		for j in range(n+1):
			if i==j:
				dp[bi][j] = 0
			if s1[i] == s2[j-1]:
				dp[bi][j] = dp[1-bi][j-1] + 1
			else:
				dp[bi][j] = max(dp[1-bi][j],dp[bi][j-1])
	return dp[bi][n]



s1 = "HARRY"
print(commonChild("HARRY","SALLY"))