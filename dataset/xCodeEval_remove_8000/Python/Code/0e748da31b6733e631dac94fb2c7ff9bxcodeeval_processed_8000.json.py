
from typing import List





























































































































































































































































































































































import math
from math import gcd
for _ in range(int(input())):
    a=list(map(int,input().split()))
    if a.count(0)>0:
        if a.count(0)==1:
            print(1)
        else:
            print(0)
    else:
        id0=gcd(a[0], a[1])
        id1=gcd(a[2], a[3])
        a[0]//=id0
        a[1]//=id0
        a[2]//=id1
        a[3]//=id1
        
        k=(a[0]*a[3])%(a[1]*a[2])
        l=(a[1]*a[2])%(a[0]*a[3])
        
        if (a[0]*a[3])==(a[2]*a[1]):
            print(0)
        elif k==0 or l==0:
            print(1)
        else:
            print(2)

