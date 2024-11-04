
  







     
        

        





            













  


   








   
    






      







































































  





















import math

for _ in range(int(input())):

    n=int(input())

    l=list(map(int,input().split()))
    k=list(l)
    l1=set()
    
    for i in range(n):
        if l[i]==-1 :
            if( i-1>=0 and l[i-1]!=-1):
                
                l1.add(l[i-1])

            if (i+1 < n and l[i+1]!=-1):
                l1.add(l[i+1])

    l1=list(l1)
    if len(l1)>=2:

        l1.sort()
        ma=l1[0]
        mi=l1[len(l1)-1]

        avg=(ma+mi)//2

        for i in range(n):
            if l[i]==-1:
                l[i]=avg

        ma=0
        for i in range(1,n):
            if ma < abs(l[i]-l[i-1]):
                ma=abs(l[i]-l[i-1])

        print(ma,avg)
        
    elif len(l1)==1:
        ma=0
        for i in range(n):
            if l[i]==-1:
                l[i]=l1[0]
        for i in range(1,n):
            if ma<abs(l[i]-l[i-1]):
                ma=abs(l[i]-l[i-1])
        print(ma,l1[0])

    elif len(l1)==0:
        print("0","1")


