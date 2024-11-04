from queue import PriorityQueue
from collections import deque,OrderedDict,defaultdict,Counter
from heapq import heappop, heappush, heapify
import sys
import time
import os
from io import BytesIO, IOBase
import math
from random import randint
from itertools import compress


MOD=10**9+7
id9 = 8192
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id9))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id9))
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
 

 
def id8(): 
    return list(map(int, inputf().split()))
 
 
def get_string(): 
    return list(map(str, inputf().split()))





global maximum
 
 
def _lis(arr, n):
 
    global maximum
 
    if n == 1:
        return 1
 
    id5 = 1
 
    
    for i in range(1, n):
        res = _lis(arr, i)
        if arr[i-1] < arr[n-1] and res+1 > id5:
            id5 = res + 1

    maximum = max(maximum, id5)
 
    return id5
 
 
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




def id7(n):
    
    sieve = bytearray([True]) * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = bytearray((n-i*i-1)//(2*i)+1)
    return [2,*compress(range(3,n,2), sieve[1:])]

def id1(n):
    
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

def id3(a,size):
     
    id6 = a[0]   
    id4 = 0
     
    for i in range(0, size):
        id4 = id4 + a[i]
        if id4 < 0:
            id4 = 0

        elif (id6 < id4):   
            id6 = id4
             
    return id6

    


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
 
def id2(n):
    
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






 



from types import GeneratorType
 
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    if not stack:
                        break
                    stack.pop()
                    to = stack[-1].send(to)
            return  to
 
    return wrappedfunc



def memoize(func):
    
    memos = {}
    def wrapper(x):
        if x not in memos:
            memos[x] = func(x)
        return memos[x]
    return wrapper



class Node:
    def __init__(self,start,end):
        self.start = start
        self.end = end
        self.total = 0
        self.max = 0
        self.min = 0
        self.left = None
        self.right = None

class SegmentTree:
    def __init__(self,mang,n):
        self.a=mang
        self.N=n
        self.INF_MIN=-10**9
        self.INF_MAX=10**9
        def buildTree(mang,l,r):
            
            
            if l>r:
                return None
            
            
            if l==r:
                n=Node(l,r)
                n.total=mang[l]
                n.max=mang[l]
                n.min=mang[l]
                return n
            
            mid = (l+r)//2

            root=Node(l,r)
            
            
            root.left=buildTree(mang,l,mid)
            root.right=buildTree(mang,mid+1,r)
            
            
            
            root.total=root.left.total+root.right.total
            root.max=max(root.left.max,root.right.max)
            root.min=min(root.left.min,root.right.min)
            
            return root
        self.root=buildTree(mang,0,n-1)
    
    def updateNode(self,i,val):
        def updateVal(root,i,val):
            
            
            
            if root.start==root.end:
                root.total=val
                root.max=val
                root.min=val
                return root
            
            mid = (root.start+root.end)//2
            
            
            if i<=mid:
                updateVal(root.left,i,val)
            
            else:
                updateVal(root.right,i,val)
            
            
            root.total=root.left.total+root.right.total
            root.max=max(root.left.max,root.right.max)
            root.min=min(root.left.min,root.right.min)
            
            return root
        return updateVal(self.root,i,val)
    
    def updateRange(self,u,v,val):  
        
        
        def updateVal(root,u,v,val):
            if u>root.end or v<root.start:
                return
            
            
            
            if root.start==root.end:
                root.total+=val
                root.max+=val
                root.min+=val
                return root
            
            mid = (root.start+root.end)//2
            updateVal(root.left,u,mid,val)
            updateVal(root.right,mid+1,v,val)          
            
            
            root.total=root.left.total+root.right.total
            root.max=max(root.left.max,root.right.max)
            root.min=min(root.left.min,root.right.min)
            
            return root
        return updateVal(self.root,u,v,val)
    
    def sumRange(self,i,j):
        def rangeSum(root,i,j):
            
            
            if root.start ==i and root.end==j:
                return root.total
            
            mid = (root.start+root.end)//2
            
            
            
            if j<=mid:
                return rangeSum(root.left,i,j)
            
            
            
            elif i>=mid+1:
                return rangeSum(root.right,i,j)
            
            
            
            else:
                return rangeSum(root.left,i,mid)+rangeSum(root.right,mid+1,j)
            
        return rangeSum(self.root,i,j)
    
    def getMax(self,l,r):   
        def getValue(root,l,r):
            if l>root.end or r<root.start:
                
                return self.INF_MIN
            if root.start==l and root.end==r:
                return root.max
            
            mid=(root.start+root.end)//2
            
            
            
            
            
            return max(getValue(root.left,l,mid),getValue(root.right,mid+1,r))
        return getValue(self.root,l,r)
           
    def getMin(self,l,r):   
        def getValue(root,l,r):
            if l>root.end or r<root.start:
                return self.INF_MAX
            if root.start==l and root.end==r:
                return root.min
            
            mid=(root.start+root.end)//2
            
            
            
            
            
            return min(getValue(root.left,l,mid),getValue(root.right,mid+1,r))
        return getValue(self.root,l,r)
t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    b = input()
    khac = True
    for i in range(n):
        if a[i] != b[i]:
            pass
        else:
            khac = False
            break
    if a == b:

        num1 = 0
        num0 = 0
        id10 = []
        for i in range(n):
            if a[i] == '1':
                num1 += 1
                id10.append(i+1)
            else:
                num0 += 1
        print("YES")
        if num1 % 2 == 0:
            print(num1)
            for num in id10:
                print(num, num)
        else:
            print(num1+3)
            for num in id10:
                print(num, num)
            print(1, n)
            print(1, 1)
            print(2, n)
    elif khac == True:
        num1 = 0
        num0 = 0
        id10 = []
        for i in range(n):
            if a[i] == '1':
                num1 += 1
                id10.append(i+1)
            else:
                num0 += 1
        print("YES")
        if num1 % 2 == 1:
            print(num1)
            for num in id10:
                print(num, num)
        else:
            print(num1+3)
            for num in id10:
                print(num, num)
            print(1, n)
            print(1, 1)
            print(2, n)
    else:
        print("NO")
