

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
    








def id7(bits): 
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
	
	
	
	
	
	id6 = sys.maxsize 
	for i in range(1, n, 1): 
		if (id1[i - 1] +
			id2[i] < id6): 
			id6 = (id1[i - 1] +
						id2[i]) 
	
	return id6 



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
	
	
	
	
	
	id4 = sys.maxsize 
	for i in range(1, n, 1): 
		if (id1[i - 1] +
			id2[i] < id4): 
			id4 = (id1[i - 1] +
						id2[i]) 
	
	return id4 






for i in range(int(input())):
    s = input()
    a = 0
    b = 0
    for i in range(len(s)):
        if(s[i] == '0'):
            a += 1
        else:
            b += 1
    id5 = [0]*len(s)
    id3 = [0]*len(s)
    if(s[0] == '0'):
        id5[0] = 1
        id3[0] = 0
    else:
        id5[0] = 0
        id3[0] = 1
    
    
    for i in range(1,len(s)):
        if(s[i] == '0'):
            id5[i] = id5[i-1]+1
            id3[i] = id3[i-1]
        else:
            id5[i] = id5[i-1]
            id3[i] = id3[i-1]+1
    
    
    e = sys.maxsize
    for i in range(len(s)):
        e = min(e, id5[i]+(b-id3[i]))
        e = min(e, id3[i]+(a-id5[i]))
    print(e)
    
    
              






    
    
    
    
    
        
    
    

    
        
    


    


    
    
    
    
    
    



            
    






    





    
                



    
    


        
            
            
            
            





    
    



    

    















        
            
        



    



    
    








    
        

















    
                
                















     




    
    








        


        
    



    







    







    










    
    
    






 






    
    
    
    

    
    
    
    
            
    
    
        



    
    
    



    
    





    


    
            



    
        
        



    
        



    
    
            







    















    


    

