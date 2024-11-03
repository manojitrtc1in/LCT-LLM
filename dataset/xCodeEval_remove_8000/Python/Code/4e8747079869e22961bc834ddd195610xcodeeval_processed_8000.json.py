

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


import statistics 
from statistics import mode 


 
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
def id5(List): 
    id0 = Counter(List) 
    return id0.most_common(1)[0][0]
def most_common(List): 
    return(mode(List))

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
    

import collections








def id7(bits): 
	n = len(bits) 

	
	
	
	
	id2 = [0 for i in range(n)] 
	id3 = [0 for i in range(n)] 

	
	flips = 0
	for i in range(0, n, 1): 
		if (bits[i] == '1'): 
			flips = flips + 1	
		id2[i] = flips
	
	
	
	flips = 0
	i = n - 1
	while(i >= 0): 
		if (bits[i] == '0'): 
			flips = flips + 1
		i = i - 1
		id3[i] = flips
	
	
	
	
	
	id6 = sys.maxsize 
	for i in range(1, n, 1): 
		if (id2[i - 1] +
			id3[i] < id6): 
			id6 = (id2[i - 1] +
						id3[i]) 
	
	return id6 



def id1(bits): 
	n = len(bits) 

	
	
	
	
	id2 = [0 for i in range(n)] 
	id3 = [0 for i in range(n)] 

	
	flips = 0
	for i in range(0, n, 1): 
		if (bits[i] == '0'): 
			flips = flips + 1	
		id2[i] = flips
	
	
	
	flips = 0
	i = n - 1
	while(i >= 0): 
		if (bits[i] == '1'): 
			flips = flips + 1
		i = i - 1
		id3[i] = flips
	
	
	
	
	
	id4 = sys.maxsize 
	for i in range(1, n, 1): 
		if (id2[i - 1] +
			id3[i] < id4): 
			id4 = (id2[i - 1] +
						id3[i]) 
	
	return id4 
def oddn(n):
    for i in range(2, n+1):
        if(i%2 != 0 and n%i == 0):
            return i
    return 3




def memoized(*args):
    if args in stored_results:
        
        return stored_results[args]
    else:
        
        result = stored_results[args] = fn(*args)
        return result
    return memoized

























    



















import operator






    

open_list = ["("]
close_list = [")"]
def check(myStr): 
    stack = []
    e = 0
    for i in myStr: 
        if i in open_list: 
            stack.append(i) 
        elif i in close_list: 
            pos = close_list.index(i) 
            if ((len(stack) > 0)): 
                
                stack.pop()
                e += 1
            
             
    
     
    
     
    return e


    
for i in range(int(input())):
    n = int(input())
    s = input()
    b = check(s)
    c = 0
    
    if(b == n//2):
        c = 0
    else:
        c = (n-2*b)//2
    print(c)
    
    
    
    

                
            
    
        


    
        
                






        
    


    


    









    

    
            


    
    
              






    
    
    
    
    
        
    
    

    
        
    


    


    
    
    
    
    
    



            
    






    





    
                



    
    


        
            
            
            
            





    
    



    

    















        
            
        



    



    
    








    
        

















    
                
                















     




    
    








        


        
    



    







    







    










    
    
    






 






    
    
    
    

    
    
    
    
            
    
    
        



    
    
    



    
    





    


    
            



    
        
        



    
        



    
    
            







    















    


    

