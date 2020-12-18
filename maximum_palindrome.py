fact = [1]
inverse = [1]
N = 1000000007
freq = []
letters = "abcdefghijklmnopqrstuvwxyz"
def letter_to_index(stra):
	for i in range(len(letters)):
		if letters[i] == stra:
			return i
def power_exponentiation(a,b):
	if b==0:
		return 1
	t = power_exponentiation(a,b//2)%N
	t = (t*t)%N
	if b%2 == 0:
		return t
	else:
		return (a*t)%N
def initialize(s):
	for i in range(1,len(s)+1):
		fact.append((fact[i-1]*i)%N)
		inverse.append(power_exponentiation(fact[i],N-2))
	for j in range(len(s)+1):
		freq.append([0 for i in range(26)])
	for i in range(1,len(s)+1):
		freq[i][letter_to_index(s[i-1])] = freq[i][letter_to_index(s[i-1])]+1
	for i in range(2,len(s)+1):
		for j in range(26):
			freq[i][j] = freq[i][j] + freq[i-1][j]
def answerQuery(l, r):
    # Return the answer for this query modulo 1000000007.

    odds = 0
    evens = 0
    denominator = 1
    numerator = 0
    for i in range(26):
    	value = freq[r][i] - freq[l-1][i]
    	if(value%2==1):
    		odds = odds+1
    	#considerar que en las frecuencias impares, se pueden tomar el maximo par y buscar acomodarlo, 
    	#lo que sobre, ponerlo en el centro del palindromo, ej. 
    	# a=2,b=2,c=3, acomodar a,b de la forma de los pares, y con c, tomar 2 c's y acomodarlas junto con a,b
    	#la ultima c, dejarla en el centro. 
    	evens = evens + (value//2)
    	denominator = (denominator*inverse[value//2])%N
    numerator = fact[evens]
    res = (numerator*denominator)%N
    if(odds>0):
    	res = (res*odds)%N
    return res
initialize('abab')
print(answerQuery(1,4))
