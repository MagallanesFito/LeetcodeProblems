dp = [[-1 for i in range(250)] for i in range(250)]
def getWays(n, c):
	if n<0 or len(c)<=0:
		return 0
	if n==0:
		return 1
	if dp[n][len(c)] != -1:
		return dp[n][len(c)]
	else:
		dp[n][len(c)] = getWays(n,c[:-1]) + getWays(n-c[-1],c)
		return dp[n][len(c)]
a = [3,25,34,38,26,42,16,10,15,50,39,44,36,29,22,43,20,27,9,30,47,13,40,33]
#print(len(a))
print(getWays(222,a))