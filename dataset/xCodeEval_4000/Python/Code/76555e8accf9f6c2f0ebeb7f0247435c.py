a,b= map(int, input().split())
c= [0]*a
for i in range(b):
    d, e, f = map(int, input().split())
    c[d-1] += f






























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    c[e-1] -= f
g= 0
for i in c:
    if i > 0:
        g+= i
print(g)