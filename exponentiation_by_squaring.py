N = 7
#N = 1000000007

def exponent(x,n):
	if n == 0:
		return 1
	t = exponent(x,int(n/2))%N
	t = (t*t)%N
	if n%2==0:
		return t
	else:
		return ((x%N)*t)%N
print(exponent(2,5))
