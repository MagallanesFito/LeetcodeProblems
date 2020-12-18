parent  = {}
max_sum = {}

def find(x):
	if parent[x] == x:
		return x
	else:
		parent[x] = find(parent[x])
	return parent[x]
def union(x,y):
	xActual = find(x)
	yActual = find(y)

	if(not xActual == yActual):
		if(max_sum[xActual] < max_sum[yActual]):
			max_sum[yActual] = max_sum[yActual] + max_sum[xActual]
			parent[xActual] = yActual
		else:
			max_sum[xActual] = max_sum[xActual] + max_sum[yActual]
			parent[yActual] = xActual
class node: 
	def __init__(self,data):
		self.data = data
		self.next = None

node1 = node(10)
node2 = node(11)
node3 = node(12)
node4 = node(13)
node5 = node(20)
node6 = node(11)
node7 = node(15)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5
node5.next = node6
node6.next = node7
node7.next = node1

start = node3
current = start.next

while(not current == start):
	parent[current.data] = current.data
	max_sum[current.data] = current.data
	current_data = current.data
	#print(current.data)
	current = current.next
	next_data = current.data
	if(next_data - current_data == 1):
		print(str(current_data) + ' ,,, '+str(next_data))
#print(current.data)
parent[current.data] = current.data