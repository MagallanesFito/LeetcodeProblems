def organizingContainers(container):
	capacities = [sum(x) for x in container]
	ball = []
	suma = 0
	for i in range(len(container)):
		suma = 0
		for j in range(len(container[0])):
			suma = suma+container[j][i]
		ball.append(suma)
	#print(ball)
	#print(capacities)
	if sorted(ball) == sorted(capacities):
		print("Possible")
	else:
		print("Impossible")

organizingContainers([[0,2,1],[1,1,1],[2,0,0]])