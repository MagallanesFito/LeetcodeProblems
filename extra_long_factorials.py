def separateDigits(a):
	digits = []
	while(a>0):
		digits.append(a%10)
		a = a//10
	return digits
def extraLongFactorials(n):
	digits = []
	a = separateDigits(30)
	b = separateDigits(25)
	for i in range(len(a)):
		carry = 0
		for j in range(len(b)):
			res = b[i]*a[j]
print(separateDigits(3))
