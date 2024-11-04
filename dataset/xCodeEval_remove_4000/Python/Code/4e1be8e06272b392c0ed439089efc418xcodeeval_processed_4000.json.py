

from fractions import Fraction
import sys
import bisect
import heapq
from math import *
from collections import Counter as counter  
from itertools import combinations as comb 
from itertools import permutations as permutate
from bisect import bisect_left as bl


from bisect import bisect_right as br
from bisect import bisect


 


 
mod = 1000000007
def inp(): return sys.stdin.readline().strip() 
def out(var): sys.stdout.write(str(var))  
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
def graph(vertex): return [[] for i in range(0,vertex+1)]
def zerolist(n): return [0]*n
def nextline(): out("\n")  
def testcase(t):
    for p in range(t):
        solve()
def printlist(a) :
    for p in range(0,len(a)):
        out(str(a[p]) + ' ')
def lcm(a,b): return (a*b)//gcd(a,b)
def power(a,b):
    ans = 1
    while(b>0):
        if(b%2==1):
            ans*=a
        a*=a
        b//=2
    return ans



    
            




for i in range(int(inp())):
    n = int(inp())
    a = list(map(int, inp().split()))
    o = 0
    e = 0
    b = 0
    if(n%2 == 0):
        for i in range(n):
            if(a[i]%2 == 0):
                e += 1
            else:
                o += 1
        
        if(e == o):
            for i in range(n):
                if((a[i]%2 == 0 and i%2 == 0)or (a[i]%2 != 0 and i%2 != 0)):
                   pass
                else:
                   b += 1
        else:
            b = -1
    else:
        for i in range(n):
            if(a[i]%2 == 0):
                e += 1
            else:
                o += 1
        
        if(e%2 != o%2 and e-o==1):
            if(n > 1 and e>=1 and o>=1):
                for i in range(n):
                    if((a[i]%2 == 0 and i%2 == 0)or (a[i]%2 != 0 and i%2 != 0)):
                       pass
                    else:
                       b += 1
            elif(n == 1 and e == 1):
                b = 0
            else:
                b = -1
        else:
            b = -1
    if(b<0):
        print(b)
    else:
        print(b//2)
        
            
            
            
            





    
    



    

    















        
            
        



    



    
    








    
        

















    
                
                















     




    
    








        


        
    



    







    







    










    
    
    






 






    
    
    
    

    
    
    
    
            
    
    
        



    
    
    



    
    





    


    
            



    
        
        



    
        



    
    
            







    















    


    

