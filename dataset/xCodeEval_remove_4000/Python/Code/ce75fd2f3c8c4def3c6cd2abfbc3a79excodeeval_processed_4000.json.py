import sys
import time
import os
from io import BytesIO, IOBase
import math
from random import randint
from itertools import compress
from typing import DefaultDict
from xml.etree.ElementInclude import default_loader

MOD=10**9+7
id14 = 8192
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id14))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id14))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
def print(*args, **kwargs):
    
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()
 
 
if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
def inputf(): 
    return sys.stdin.readline().rstrip("\r\n")  
 

 
def id12(): 
    return list(map(int, inputf().split()))
 
 
def get_string(): 
    return list(map(str, inputf().split()))





global maximum
 
 
def _lis(arr, n):
 
    global maximum
 
    if n == 1:
        return 1
 
    id9 = 1
 
    
    for i in range(1, n):
        res = _lis(arr, i)
        if arr[i-1] < arr[n-1] and res+1 > id9:
            id9 = res + 1

    maximum = max(maximum, id9)
 
    return id9
 
 
def LIS(arr):
 
    global maximum
 
    n = len(arr)

    maximum = 1
 

    _lis(arr, n)
 
    return maximum
 

def binary_search(data, elem):
    
    low = 0
    high = len(data) - 1
    while low <= high:
      
        middle = (low + high)//2
        if data[middle] == elem:
            return middle
            
        elif data[middle] > elem:

            high = middle - 1
        else:
            low = middle + 1

    return middle   

def upper_bound(my_list, key):
    large = len(my_list) -1
    small = 0

    while (small <= large):
        mid = (small + large) // 2
        if my_list[mid] < key:  
            small = mid + 1
        elif my_list[mid] > key:  
            large = mid - 1
        else:
            return mid
    if my_list[mid]>key:
        return mid
    else:
        return mid+1   
    



def lower_bound(my_list, key):
    large = len(my_list) -1
    small = 0

    while (small <= large):
        mid = (small + large) // 2
        if my_list[mid] < key:
            small = mid + 1
        elif my_list[mid] > key:
            large = mid - 1
        else:
            return mid
    if my_list[mid]<key:
        return mid
    else:
        return mid-1




def id11(n):
    
    sieve = bytearray([True]) * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = bytearray((n-i*i-1)//(2*i)+1)
    return [2,*compress(range(3,n,2), sieve[1:])]

def id4(n):
    
    sieve = bytearray([True]) * (n//2+1)
    for i in range(1,int(n**0.5)//2+1):
        if sieve[i]:
            sieve[2*i*(i+1)::2*i+1] = bytearray((n//2-2*i*(i+1))//(2*i+1)+1)
    return [2,*compress(range(3,n,2), sieve[1:])]

def roman_number(x):
    if x > 15999:
        return
    value = [5000, 4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbol = ["F", "MF", "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    roman = ""
    i = 0
    while x > 0:
        div = x // value[i]
        x = x % value[i]
        while div:
            roman += symbol[i]
            div -= 1
        i += 1
    return roman

def id6(a,size):
     
    id10 = a[0]   
    id7 = 0
     
    for i in range(0, size):
        id7 = id7 + a[i]
        if id7 < 0:
            id7 = 0

        elif (id10 < id7):   
            id10 = id7
             
    return id10

    


def lcm(x, y):

   if x > y:
       greater = x
   else:
       greater = y

   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm

def primeFactors(n):
    a=[]
    while n % 2 == 0:
        a.append(2)
        n = n / 2
         
    for i in range(3,int(math.sqrt(n))+1,2):
         
        while n % i== 0:
            a.append(i)
            n = n / i
             
    if n > 2:
        a.append(n)
         

def findClosest(arr, n, target):
 
    if (target <= arr[0]):
        return arr[0]
    if (target >= arr[n - 1]):
        return arr[n - 1]
 
    i = 0; j = n; mid = 0
    while (i < j):
        mid = (i + j) // 2
 
        if (arr[mid] == target):
            return arr[mid]
 
        if (target < arr[mid]) :
 
            if (mid > 0 and target > arr[mid - 1]):
                return getClosest(arr[mid - 1], arr[mid], target)
 
            j = mid
         
        else :
            if (mid < n - 1 and target < arr[mid + 1]):
                return getClosest(arr[mid], arr[mid + 1], target)
                 
            i = mid + 1
         
    return arr[mid]
 

def getClosest(val1, val2, target):
 
    if (target - val1 >= val2 - target):
        return val2
    else:
        return val1

import random
 
def id5(n):
    
    if n!=int(n):
        return False
    n=int(n)
    if n==0 or n==1 or n==4 or n==6 or n==8 or n==9:
        return False
 
    if n==2 or n==3 or n==5 or n==7:
        return True
    s = 0
    d = n-1
    while d%2==0:
        d>>=1
        s+=1
    assert(2**s * d == n-1)
 
    def id0(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True  
 
    for i in range(8):
        a = random.randrange(2, n)
        if id0(a):
            return False
 
    return True  

def LCS(s1 , s2):
    m, n = len(s1), len(s2)
    prev, cur = [0]*(n+1), [0]*(n+1)
    for i in range(1, m+1):
        for j in range(1, n+1):
            if s1[i-1] == s2[j-1]:
                cur[j] = 1 + prev[j-1]
            else:
                if cur[j-1] > prev[j]:
                    cur[j] = cur[j-1]
                else:
                    cur[j] = prev[j]
        cur, prev = prev, cur
    return prev[n]

fib_matrix = [[1,1],
              [1,0]]

def matrix_square(A, mod):
    return mat_mult(A,A,mod)


def mat_mult(A,B, mod):
  if mod is not None:
    return [[(A[0][0]*B[0][0] + A[0][1]*B[1][0])%mod, (A[0][0]*B[0][1] + A[0][1]*B[1][1])%mod],
            [(A[1][0]*B[0][0] + A[1][1]*B[1][0])%mod, (A[1][0]*B[0][1] + A[1][1]*B[1][1])%mod]]


def matrix_pow(M, power, mod):
    if power <= 0:
      return M

    powers =  list(reversed([True if i=="1" else False for i in bin(power)[2:]])) 

    matrices = [None for _ in powers]
    matrices[0] = M

    for i in range(1,len(powers)):
        matrices[i] = matrix_square(matrices[i-1], mod)


    result = None

    for matrix, power in zip(matrices, powers):
        if power:
            if result is None:
                result = matrix
            else:
                result = mat_mult(result, matrix, mod)

    return result



def multiply(T, M):
     
    a = (T[0][0] * M[0][0] + T[0][1] *
         M[1][0] + T[0][2] * M[2][0])            
    b = (T[0][0] * M[0][1] + T[0][1] *
         M[1][1] + T[0][2] * M[2][1])
    c = (T[0][0] * M[0][2] + T[0][1] *
         M[1][2] + T[0][2] * M[2][2])
    d = (T[1][0] * M[0][0] + T[1][1] *
         M[1][0] + T[1][2] * M[2][0])
    e = (T[1][0] * M[0][1] + T[1][1] *
         M[1][1] + T[1][2] * M[2][1])
    f = (T[1][0] * M[0][2] + T[1][1] *
         M[1][2] + T[1][2] * M[2][2])
    g = (T[2][0] * M[0][0] + T[2][1] *
         M[1][0] + T[2][2] * M[2][0])
    h = (T[2][0] * M[0][1] + T[2][1] *
         M[1][1] + T[2][2] * M[2][1])
    i = (T[2][0] * M[0][2] + T[2][1] *
         M[1][2] + T[2][2] * M[2][2])
             
    T[0][0] = a
    T[0][1] = b
    T[0][2] = c
    T[1][0] = d
    T[1][1] = e
    T[1][2] = f
    T[2][0] = g
    T[2][1] = h
    T[2][2] = i
 

def power(T, n):
 
    if (n == 0 or n == 1):
        return;
    M = [[ 1, 1, 1 ],
                [ 1, 0, 0 ],
                [ 0, 1, 0 ]]
 
    power(T, n // 2)
 
    multiply(T, T)
 
    if (n % 2):
        multiply(T, M)
 
def tribonacci(n):
     
    T = [[ 1, 1, 1 ],
        [1, 0, 0 ],
        [0, 1, 0 ]]
 
    if (n == 0 or n == 1):
        return 0
    else:
        power(T, n - 2)

    return T[0][0]

def id2(x1,y1,x2,y2,x3,y3):
    id13=math.sqrt((x1-x2)**2+(y1-y2)**2)
    id3=math.sqrt((x1-x3)**2+(y1-y3)**2)
    id15=math.sqrt((x2-x3)**2+(y2-y3)**2)
    if id13==0 or id3==0 or id15==0:
        return False    
    else:
        cos12=(id3**2+id15**2-id13**2)/(2*id3*id15)
        cos13=(id13**2+id15**2-id3**2)/(2*id13*id15)
        cos23=(id3**2+id13**2-id15**2)/(2*id3*id13)
        if cos12==-1 or cos12==1 or cos13==-1 or cos13==1 or cos23==-1 or cos23==1:
            return False
        else:
            return True
        

def id8(x1,y1,x2,y2,x3,y3,x4,y4):
    if id2(x1,y1,x2,y2,x4,y4)==True and id2(x1,y1,x2,y2,x3,y3)==True and id2(x1,y1,x3,y3,x4,y4)==True and id2(x2,y2,x3,y3,x4,y4)==True:
        return True
    else:
        return False


def id1(x1,x2,y1,y2):
    if x1==x2: 
        return True
    if y1==y2:
        return False
    a=(y1-y2)/(x1-x2)
    b=y1-a*x1
    return a,b


def id8(x1,y1,x2,y2,x3,y3,x4,y4):
        check=0
        if id1(x1,x2,y1,y2)==True: 
            if (x3>x1 and x4>x1) or (x3<x1 and x4<x1):
                check+=1
        elif id1(x1,x2,y1,y2)==False: 
            if (y3>y1 and y4>y1) or (y3<y1 and y4<y1):
                check+=1
        else:
            a,b=id1(x1,x2,y1,y2)
            if (a*x3+b-y3>0 and a*x4+b-y4>0) or (a*x3+b-y3<0 and a*x4+b-y4<0):
                check+=1
                
                
        if id1(x2,x3,y2,y3)==True: 
            if (x4>x2 and x1>x2) or (x4<x2 and x1<x2):
                check+=1
        elif id1(x2,x3,y2,y3)==False: 
            if (y4>y2 and y1>y2) or (y4<y2 and y1<y2):
                check+=1
        else:
            a,b=id1(x2,x3,y2,y3)
            if (a*x4+b-y4>0 and a*x1+b-y1>0) or (a*x1+b-y1<0 and a*x4+b-y4<0):
                check+=1                               
                
                
        if id1(x3,x4,y3,y4)==True: 
            if (x1>x3 and x2>x3) or (x1<x3 and x2<x3):
                check+=1
        elif id1(x3,x4,y3,y4)==False: 
            if (y1>y3 and y2>y3) or (y1<y3 and y2<y3):
                check+=1
        else:
            a,b=id1(x3,x4,y3,y4)
            if (a*x1+b-y1>0 and a*x2+b-y2>0) or (a*x1+b-y1<0 and a*x2+b-y2<0):
                check+=1               
                
                
        if id1(x4,x1,y4,y1)==True: 
            if (x2>x1 and x3>x1) or (x2<x1 and x3<x1):
                check+=1
        elif id1(x4,x1,y4,y1)==False: 
            if (y2>y1 and y3>y1) or (y2<y1 and y3<y1):
                check+=1
        else:
            a,b=id1(x4,x1,y4,y1)
            if (a*x2+b-y2>0 and a*x3+b-y3>0) or (a*x2+b-y2<0 and a*x3+b-y3<0):
                check+=1                
        
        if check==4:
            return True
        else:
            return False

 


 


testcase=int(input())
for test in range(testcase):
    n=int(input())
    a=id12()    
    res=0
    for i in range(0,n-1):
        res=max(res,a[i]*a[i+1])
    print(res)