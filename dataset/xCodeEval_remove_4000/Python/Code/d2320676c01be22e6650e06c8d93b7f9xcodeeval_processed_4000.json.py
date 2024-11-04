import time,math as mt,bisect as bs,sys
from sys import stdin,stdout
from collections import deque
from fractions import Fraction
from collections import Counter
from collections import OrderedDict
pi=3.14159265358979323846264338327950
def II(): 
    return int(stdin.readline())
def IP(): 
    return map(int,stdin.readline().split())
def L(): 
    return list(map(int,stdin.readline().split()))
def P(x): 
    return stdout.write(str(x)+"\n")
def PI(x,y): 
    return stdout.write(str(x)+" "+str(y)+"\n")
def lcm(a,b): 
    return (a*b)//gcd(a,b)
def gcd(a,b): 
    if a==0:
        return b
    elif b==0:
        return a
    if a>b:
        return gcd(a%b,b)
    else:
        return gcd(a,b%a)
def bfs(adj,v): 
    visited=[False]*(v+1)
    q=deque()
    while q:
        pass
def setBit(n):
    count=0
    while n!=0:
        n=n&(n-1)
        count+=1
    return count

def readTree(n,e): 
    adj=[set() for i in range(n+1)]
    for i in range(e):
        u1,u2=IP()
        adj[u1].add(u2)
    return adj
def sieve():
    li=[True]*(10**3+5)
    li[0],li[1]=False,False
    for i in range(2,len(li),1):
        if li[i]==True:
            for j in range(i*i,len(li),i):
                li[j]=False
    prime,cur=[0]*200,0
    for i in range(10**3+5):
        if li[i]==True:
            prime[cur]=i
            cur+=1
    return prime
def SPF():
    mx=(10**7+1)
    spf=[mx]*(mx)
    spf[1]=1
    for i in range(2,mx):
        if spf[i]==mx:
            spf[i]=i
            for j in range(i*i,mx,i):
                if i<spf[j]:
                    spf[j]=i
    return spf
def prime(n,d):
    while n!=1:
        d[spf[n]]=d.get(spf[n],0)+1
        n=n//spf[n]
    return

mod = 998244353
inf = 10000000000000000
def solve():
    n=II()
    li=[[0 for j in range(n)] for i in range(n)]
    a=II()
    if a==1 or a==3:
        li[0][0]=2
        print(2,1,1,flush=True)
        fill=False
        fill_value=-1
        for i in range(n**2-1):
            a=II()
            if fill:
                for j in range(n):
                    pos=-2
                    for k in range(n):
                        if li[j][k]==0:
                            if fill_value==2:
                                if a==1 or a==2:
                                    print(3,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=3
                                    break
                                else:
                                    print(1,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=1
                                    break
                            else:
                                if a==1 or a==3:
                                    print(2,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=2
                                    break
                                else:
                                    print(1,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=1
                                    break
                    if pos!=-2:
                        break
            else:
                if a==1 or a==3:
                    for j in range(n):
                        pos=-2
                        if j%2==0:
                            for k in range(0,n,2):
                                if li[j][k]==0:
                                    print(2,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=2
                                    break
                        else:
                            for k in range(1,n,2):
                                if li[j][k]==0:
                                    print(2,j+1,k+1,flush=True)
                                    li[j][k]=2
                                    pos=k
                                    break
                        if j==n-1 and (pos+1)>=(n-1):
                            fill=True
                            fill_value=2
                        if pos!=-2:
                            break
                else:
                    for j in range(n):
                        pos=-2
                        if j%2:
                            for k in range(0,n,2):
                                if li[j][k]==0:
                                    print(3,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=3
                                    break
                        else:
                            for k in range(1,n,2):
                                if li[j][k]==0:
                                    print(3,j+1,k+1,flush=True)
                                    li[j][k]=3
                                    pos=k
                                    break
                        if j==n-1 and (pos+1)>=(n-1):
                            fill=True
                            fill_value=3
                        if pos!=-2:
                            break
    else:
        li[0][0]=1
        print(1,1,1,flush=True)
        fill=False
        fill_value=-1
        for i in range(n**2-1):
            a=II()
            if fill:
                for j in range(n):
                    pos=-2
                    for k in range(n):
                        if li[j][k]==0:
                            if fill_value==1:
                                if a==1 or a==2:
                                    print(3,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=3
                                    break
                                else:
                                    print(2,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=2
                                    break
                            else:
                                if a==1 or a==3:
                                    print(2,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=2
                                    break
                                else:
                                    print(1,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=1
                                    break
                    if pos!=-2:
                        break
            else:
                if a==2 or a==3:
                    for j in range(n):
                        pos=-2
                        if j%2==0:
                            for k in range(0,n,2):
                                if li[j][k]==0:
                                    print(1,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=1
                                    break
                        else:
                            for k in range(1,n,2):
                                if li[j][k]==0:
                                    print(1,j+1,k+1,flush=True)
                                    li[j][k]=1
                                    pos=k
                                    break
                        if j==n-1 and (pos+1)>=(n-1):
                            fill=True
                            fill_value=1
                        if pos!=-2:
                            break
                else:
                    for j in range(n):
                        pos=-2
                        if j%2:
                            for k in range(0,n,2):
                                if li[j][k]==0:
                                    print(3,j+1,k+1,flush=True)
                                    pos=k
                                    li[j][k]=3
                                    break
                        else:
                            for k in range(1,n,2):
                                if li[j][k]==0:
                                    print(3,j+1,k+1,flush=True)
                                    li[j][k]=3
                                    pos=k
                                    break
                        if j==n-1 and (pos+1)>=(n-1):
                            fill=True
                            fill_value=3
                        if pos!=-2:
                            break
    return

t=1
for i in range(t):
    solve()

    
   
  
 
       
      





































































