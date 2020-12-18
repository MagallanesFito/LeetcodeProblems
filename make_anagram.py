def makeAnagram(a,b):
	print (list(a))
	print(list(b))
	print(set(list(a)) & set(list(b)))
	#return len(a) + len(b) - 2*len()

a = 'fcrxzwscanmligyxyvym'
b = 'jxwtrhvujlmrpdoqbisbwhmgpmeoke'

makeAnagram(a,b)

