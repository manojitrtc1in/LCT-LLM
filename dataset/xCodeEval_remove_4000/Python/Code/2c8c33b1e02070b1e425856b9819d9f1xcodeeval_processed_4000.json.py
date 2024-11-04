

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

def createMatrix(rowCount, colCount, dataList):   
    mat = []
    for i in range (rowCount):
        rowList = []
        for j in range (colCount):
            if dataList[j] not in mat:
                rowList.append(dataList[j])
        mat.append(rowList)

    return mat
def isprime(n) : 
  
    if (n <= 1) :
        return False
    if (n <= 3) :
        return True
  
    
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True
    








def id5(bits): 
	n = len(bits) 

	
	
	
	
	id1 = [0 for i in range(n)] 
	id2 = [0 for i in range(n)] 

	
	flips = 0
	for i in range(0, n, 1): 
		if (bits[i] == '1'): 
			flips = flips + 1	
		id1[i] = flips
	
	
	
	flips = 0
	i = n - 1
	while(i >= 0): 
		if (bits[i] == '0'): 
			flips = flips + 1
		i = i - 1
		id2[i] = flips
	
	
	
	
	
	id4 = sys.maxsize 
	for i in range(1, n, 1): 
		if (id1[i - 1] +
			id2[i] < id4): 
			id4 = (id1[i - 1] +
						id2[i]) 
	
	return id4 



def id0(bits): 
	n = len(bits) 

	
	
	
	
	id1 = [0 for i in range(n)] 
	id2 = [0 for i in range(n)] 

	
	flips = 0
	for i in range(0, n, 1): 
		if (bits[i] == '0'): 
			flips = flips + 1	
		id1[i] = flips
	
	
	
	flips = 0
	i = n - 1
	while(i >= 0): 
		if (bits[i] == '1'): 
			flips = flips + 1
		i = i - 1
		id2[i] = flips
	
	
	
	
	
	id3 = sys.maxsize 
	for i in range(1, n, 1): 
		if (id1[i - 1] +
			id2[i] < id3): 
			id3 = (id1[i - 1] +
						id2[i]) 
	
	return id3 
def oddn(n):
    for i in range(2, n+1):
        if(i%2 != 0 and n%i == 0):
            return i
    return 3





    
    
    
        
for i in range(int(inp())):
    n = int(inp())
    a = 0
    
    if(n%2 == 0):
        a = n//2
    else:
        
        a = (n-1)//2
        
            
        
            
        
            
        
    print(a)
    
            


    
    
              






    
    
    
    
    
        
    
    

    
        
    


    


    
    
    
    
    
    



            
    






    





    
                



    
    


        
            
            
            
            





    
    



    

    















        
            
        



    



    
    








    
        

















    
                
                















     




    
    








        


        
    



    







    







    










    
    
    






 






    
    
    
    

    
    
    
    
            
    
    
        



    
    
    



    
    





    


    
            



    
        
        



    
        



    
    
            







    















    


    

