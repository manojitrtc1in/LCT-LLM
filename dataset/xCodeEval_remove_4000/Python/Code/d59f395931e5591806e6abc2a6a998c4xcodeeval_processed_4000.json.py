









	





	





























n,m = map(int,input().split())
m = float(m)
mi = []
for i in range(n):
	a,b = map(float,input().split())
	mi.append((a*m)/b)
print(min(mi))
