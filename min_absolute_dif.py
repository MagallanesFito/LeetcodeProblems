arr = [3,-7,0]
cur_min = min(arr)
arr2 = [cur_min + e for e in arr]
# 3,0,-7
arr.sort(reverse=True)
difs = []
for i in range(len(arr)-1):
	curr_dif = arr[i] - arr[i+1]
	difs.append(curr_dif)
print(min(difs))