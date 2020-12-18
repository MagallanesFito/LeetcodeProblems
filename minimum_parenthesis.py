class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
    	S_ = []
    	L = []
    	for i in range(len(s)):
    		if s[i] == '(':
    			S_.append(i)
    		elif(s[i] == ')'):
    			if len(S_) == 0:
    				L.append(i)
    			else:
    				S_.pop()
    	while(len(S_) > 0):
    		L.append(S_.pop())
    	for index in L:
    		next_=  index+1
    		s = s[0:index] + s[next_:]
    	return s
sol = Solution()
print(sol.minRemoveToMakeValid('))(('))