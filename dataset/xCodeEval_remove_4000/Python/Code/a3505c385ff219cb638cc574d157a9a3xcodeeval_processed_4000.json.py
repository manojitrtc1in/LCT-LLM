










	





	

 
















































































 

x = int(input())
j = 0
r =[]
l = []
for i in range(x):
    y = [int(i) for i in list(input().split())]
    if y[0]<0:
        l.append(y)
    else:
        r.append(y)
r = sorted(r)
l = sorted(l, reverse = True)

j = 0

d =1 if len(r)>=len(l) else -1
while((d == 1 and len(r)>0) or (d==-1 and len(l)>0)):
    if d ==1:
        j += r[0][1]
        r = r[1:]
        d = -1
    else:
        j += l[0][1]
        l = l[1:]
        d = 1
print(j)
