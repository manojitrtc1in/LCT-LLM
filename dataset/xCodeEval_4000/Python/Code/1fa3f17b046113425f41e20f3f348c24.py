

import math
import os
import sys

from sys import *
from decimal import *
from io import BytesIO, IOBase
from itertools import accumulate,combinations,permutations,combinations_with_replacement,product
from collections import *


M = 10 ** 9 + 7
import heapq


if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip


BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
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
    """Prints the values to a stream, or to sys.stdout by default."""
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


def inp(): return sys.stdin.readline().rstrip("\r\n")  


def out(var): sys.stdout.write(str(var))  


def lis(): return list(map(int, inp().split()))


def stringlis(): return list(map(str, inp().split()))


def sep(): return map(int, inp().split())


def strsep(): return map(str, inp().split())


def fsep(): return map(float, inp().split())


def inpu(): return int(inp())




def regularbracket(t):
    p = 0
    for i in t:
        if i == "(":
            p += 1
        else:
            p -= 1
        if p < 0:
            return False
    else:
        if p > 0:
            return False
        else:
            return True

def binarySearchcount(arr, n, key):
    left = 0
    right = n - 1
    count = 0
    while (left <= right):
        mid = int((right + left) / 2)
        
        
        if (arr[mid] <= key):
            count = mid + 1
            left = mid + 1
        
        else:
            right = mid - 1
    return count


def binarySearch(arr, n, key):
    left = 0
    right = n - 1
    while (left <= right):
        mid = ((right + left) // 2)
        if arr[mid]==key:
            return mid
        if (arr[mid] <= key):
            left = mid + 1
        
        else:
            right = mid - 1
    return -1

def ternarysearch(arr,n,key):
    l,r=0,n-1
    while(l<=r):
        mid = (-l+r)//3 + l
        mid2 = mid + (-l+r)//3
        if arr[mid]==key:
            return mid
        if arr[mid2]==key:
            return mid2
        if arr[mid]>key:
            r=mid-1
        elif arr[mid2]<key:
            l=mid2+1
        else:
            l=mid+1
            r=mid2-1
    return -1

def reverse1(string):
    pp = ""
    for i in string[::-1]:
        pp += i
    if pp == string:
        return True
    return False



def reverse2(list1):
    l = []
    for i in list1[::-1]:
        l.append(i)
    if l == list1:
        return True
    return False


def mex(list1):
    
    p = max(list1) + 1
    for i in range(len(list1)):
        if list1[i] != i:
            p = i
            break
    return p


def sumofdigits(n):
    n = str(n)
    s1 = 0
    for i in n:
        s1 += int(i)
    return s1


def perfect_square(n):
    s = math.sqrt(n)
    if s == int(s):
        return True
    return False


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


def soretd(s):
    for i in range(1, len(s)):
        if s[i - 1] > s[i]:
            return False
    return True




def countRhombi(h, w):
    ct = 0
    for i in range(2, h + 1, 2):
        for j in range(2, w + 1, 2):
            ct += (h - i + 1) * (w - j + 1)
    return ct


def countrhombi2(h, w):
    return ((h * h) // 4) * ((w * w) // 4)



def binpow(a, b):
    if b == 0:
        return 1
    else:
        res = binpow(a, b // 2)
    if b % 2 != 0:
        return res * res * a
    else:
        return res * res



def binpowmodulus(a, b, M):
    if b==1:
        return a%M
    if b==0:
        return 1
    if b%2==0:
        ans=binpowmodulus(a,b//2,M)
        return (ans*ans)%(M)
    else:
        ans=binpowmodulus(a,(b-1)//2,M)
        return ((ans*a)%M * ans)%M

def coprime_to_n(n):
    result = n
    i = 2
    while (i * i <= n):
        if (n % i == 0):
            while (n % i == 0):
                n //= i
            result -= result // i
        i += 1
    if (n > 1):
        result -= result // n
    return result


def luckynumwithequalnumberoffourandseven(x,n,a):
    if x >= n and str(x).count("4") == str(x).count("7"):
        a.append(x)
    else:
        if x < 1e12:
            luckynumwithequalnumberoffourandseven(x * 10 + 4,n,a)
            luckynumwithequalnumberoffourandseven(x * 10 + 7,n,a)
    return a

def luckynum(x,l,r,a):
    if x>=l and x<=r:
        a.append(x)
    if x>r:
        a.append(x)
        return a
    if x < 1e10:
            luckynum(x * 10 + 4, l,r,a)
            luckynum(x * 10 + 7, l,r,a)
    return a

def luckynuber(x, n, a):
    p = set(str(x))
    if len(p) <= 2:
        a.append(x)
    if x < n:
        luckynuber(x + 1, n, a)
    return a




def interact(type, x):
    if type == "r":
        inp = input()
        return inp.strip()
    else:
        print(x, flush=True)



def findTrailingZeros(n):
    
    count = 0

    
    
    while (n >= 5):
        n //= 5
        count += n

    return count




def mergeSort(arr):
    if len(arr) > 1:

        
        mid = len(arr) // 2

        
        L = arr[:mid]

        
        R = arr[mid:]

        
        mergeSort(L)

        
        mergeSort(R)

        i = j = k = 0

        
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1



res = set()
def solven(p, l, a, b, n):  
    if p > n or l > 10:
        return
    if p > 0:
        res.add(p)
    solven(p * 10 + a, l + 1, a, b, n)
    solven(p * 10 + b, l + 1, a, b, n)



"""
n = int(input())
for a in range(0, 10):
    for b in range(0, a):
        solve(0, 0)
print(len(res))
"""





def subsetsUtil(A, subset, index, d):
    print(*subset)
    s = sum(subset)
    d.append(s)
    for i in range(index, len(A)):
        
        subset.append(A[i])

        
        subsetsUtil(A, subset, i + 1, d)

        
        
        subset.pop(-1)
    return d


def subsetSums(arr, l, r, d, sum=0):
    if l > r:
        d.append(sum)
        return
    subsetSums(arr, l + 1, r, d, sum + arr[l])

    
    subsetSums(arr, l + 1, r, d, sum)
    return d


def print_factors(x):
    factors = []
    for i in range(1, x + 1):
        if x % i == 0:
            factors.append(i)
    return (factors)



def calc(X, d, ans, D):
    
    if len(X) == 0:
        return

    i = X.index(max(X))
    ans[D[max(X)]] = d

    Y = X[:i]
    Z = X[i + 1:]

    calc(Y, d + 1, ans, D)
    calc(Z, d + 1, ans, D)




def factorization(n, l):
    c = n
    if prime(n) == True:
        l.append(n)
        return l
    for i in range(2, c):
        if n == 1:
            break
        while n % i == 0:
            l.append(i)
            n = n // i
    return l



def good(b):
    l = []
    i = 0
    while (len(b) != 0):
        if b[i] < b[len(b) - 1 - i]:
            l.append(b[i])
            b.remove(b[i])
        else:
            l.append(b[len(b) - 1 - i])
            b.remove(b[len(b) - 1 - i])
    if l == sorted(l):
        
        return True
    return False




def generate(st, s):
    if len(s) == 0:
        return

    
    if s not in st:
        st.add(s)

        
        
        for i in range(len(s)):
            t = list(s).copy()
            t.remove(s[i])
            t = ''.join(t)
            generate(st, t)
    return


def largestincreasingsubsequence(A):
    l = [1]*len(A)
    sub=[]
    for i in range(1,len(l)):
        for k in range(i):
            if A[k]<A[i]:
                sub.append(l[k])
        l[i]=1+max(sub,default=0)
    return max(l,default=0)


def findOR(nums, N):
    
    
    prefix_sum = 0
    
    
    result = 0
    
    for i in range(N):
        
        
        result |= nums[i]
        
        prefix_sum += nums[i]
        
        
        result |= prefix_sum
    
    return result

def OR(a, n):
    ans = a[0]
    for i in range(1, n):
        ans |= a[i]
        
    return ans

def toString(List):
    return ''.join(List)





def permute(a, l, r,p):
    if l == r:
        p.append(toString(a))
    else:
        for i in range(l, r + 1):
            a[l], a[i] = a[i], a[l]
            permute(a, l + 1, r,p)
            a[l], a[i] = a[i], a[l]  


def squareRoot(number, precision):
    start = 0
    end, ans = number, 1
    
    
    while (start <= end):
        mid = int((start + end) / 2)
        if (mid * mid == number):
            ans = mid
            break

        
        
        if (mid * mid < number):
            start = mid + 1
        
        
        else:
            end = mid - 1
    
    
    increment = 0.1
    for i in range(0, precision):
        while (ans * ans <= number):
            ans += increment
        
        ans = ans - increment
        increment = increment / 10
    return ans

def countRectangles(l, w):
    squareSide = math.gcd(l, w)
    return int((l * w) / (squareSide * squareSide))





def count_same_digit(L, R):
    tmp = 0
    ans = 0
    n = int(math.log10(R) + 1)
    for i in range(0, n):
        
        tmp = tmp * 10 + 1
        for j in range(1, 10):

            if (L <= (tmp * j) and (tmp * j) <= R):
                
                
                ans += 1
    return ans

def findCrossOver(arr, low, high, x):
    
    if (arr[high] <= x):  
        return high
    if (arr[low] > x):  
        return low
    
    mid = (low + high) // 2
    if (arr[mid] <= x and arr[mid + 1] > x):
        return mid
    if (arr[mid] < x):
        return findCrossOver(arr, mid + 1, high, x)
    return findCrossOver(arr, low, mid - 1, x)
def Kclosest(arr, x, k, n,ans):
    
    l = findCrossOver(arr, 0, n - 1, x)
    r = l + 1
    count = 0
    if (arr[l] == x):
        l -= 1
    
    while (l >= 0 and r < n and count < k):
        if (x - arr[l] < arr[r] - x):
            ans.append(arr[l])
            l -= 1
        else:
            ans.append(arr[r])
            r += 1
        count += 1
    while (count < k and l >= 0):
        ans.append(arr[l])
        l -= 1
        count += 1
    while (count < k and r < n):
        ans.append(arr[r])
        r += 1
        count += 1
    return ans


def calcSum(arr, n, k):
    
    l=[]
    sum=0
    
    
    for i in range(k):
        sum += arr[i]

    
    l.append(sum)

    
    
    
    for i in range(k, n):
        
        
        
        
        sum = (sum - arr[i - k]) + arr[i]

        
        l.append(sum)

    return l

"""
def dfs(root,nodeVal,nodeConnection,visited):
    leftVal = nodeVal[root][0]
    rightVal = nodeVal[root][1]
    solution = []
    if nodeConnection[root]:
        visited.add(root)
        for i in nodeConnection[root]:
            if i not in visited:
                solution.append(dfs(i,nodeVal,nodeConnection,visited))
        
        leftMax = 0
        rightMax = 0
        for i in solution:
            l, r = i
            leftMax += max(abs(leftVal - l[0]) + l[1], abs(leftVal - r[0]) + r[1])
            rightMax += max(abs(rightVal - l[0]) + l[1], abs(rightVal - r[0]) + r[1])
        
        return ((leftVal, leftMax), (rightVal, rightMax))
    else:
        
        return ((leftVal, 0), (rightVal, 0))
"""
"""
def luckynumber(x,n,a):
    if x >0:
        a.append(x)
    if x>10**9:
        return a
    else:
        if x < 1e12:
            luckynumber(x * 10 + 4,n,a)
            luckynumber(x * 10 + 7,n,a)
def lcm(a,b):
    return (a*b)//math.gcd(a,b)

def query1(l, r):
    if l >= r:
        return -1
    print('?', l + 1, r + 1)
    sys.stdout.flush()
    return int(input()) - 1
def answer(p):
    print('!', p + 1)
    sys.stdout.flush()
    exit()


"""
import math
MAX = 10**5
prefix = [0] * (MAX + 1)
def buildPrefix():
    prime = [1] * (MAX + 1)
    p = 2
    while (p * p <= MAX):
        if (prime[p] == 1):
            i = p * 2
            while (i <= MAX):
                prime[i] = 0
                i += p
        p += 1
    for p in range(2, MAX + 1):
        prefix[p] = prefix[p - 1]
        if (prime[p] == 1):
            prefix[p] += 1
def query(L, R):
    return prefix[R] - prefix[L - 1]
buildPrefix()

def maxSubArraySum(a, size):
    max_so_far = a[0]
    curr_max = a[0]
    for i in range(1, size):
        curr_max = max(a[i], curr_max + a[i])
        max_so_far = max(max_so_far, curr_max)
    return max_so_far

def solve(n,k):
    if n==1 and k==1:
        return 0
    mid=(2**(n-1))//2
    if k<=mid:
        return solve(n-1,k)
    else:
        return solve(n-1,k-(mid))==0


def solvr(s,p):
    if len(s)==0:
        print(p,end=" ")
        return
    op1=p
    op2=p+s[0]
    s=s[1:]
    solvr(s,op1)
    solvr(s,op2)
    return

def paranthesis(n,m,ans,l):
    if n==0 and m==0:
        print(ans)
        return
    if n!=0:
        op1=ans+"("
        paranthesis(n-1,m,op1,l)
    if m>n:
        op2=ans+")"
        paranthesis(n,m-1,op2,l)
"""
class node:
    def __init__(self,data):
        self.data=data
        self.next=None
class linkedlis:
    def __init__(self):
        self.head=None
    def printlis(self):
        temp=self.head
        while(temp):
            print(temp.data,end=" ")
            temp=temp.next
    def pushfirst(self,new_data):
        new_node=node(new_data)
        new_node.next=self.head
        self.head=new_node
    def pushmid(self,previous_node,new_data):
        new_node=node(new_data)
        if previous_node==None:
            print("call pushfirst function if it is the the start otherwise raise an error.")
        new_node.next=previous_node.next
        previous_node.next=new_node
    def pushlast(self,new_data):
        new_node=node(new_data)
        if self.head==None:
            self.head=new_node
            return
        last=self.head
        while(last.next!=None):
            last=last.next
        last.next=new_node
    def delete_node(self,key):
        pass
if __name__ == '__main__':
    l=linkedlis()
    l.head= node(1)
    p = node(2)
    pp = node(4)
    l.head.next = p
    p.next = pp
    
    l.pushmid(p, 3)
    l.pushlast(5)
    l.pushfirst(0)
    
    
"""
"""
def main():
        n=1000
        l=[12]*1000
        sum=12*100
        dp=[[False]*(sum+1) for i in range(n+1)]
        for i in range(n+1):
            dp[i][0]=True
        for i in range(1,n+1):
            for j in range(1,sum+1):
                if j<l[i-1]:
                    dp[i][j]=dp[i-1][j]
                else:
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-l[i-1]]
        print(dp[n][sum])
if __name__ == '__main__':
    main()
"""
"""
def largestSubset(a, n):
    dp = [0 for i in range(n)]
    dp[n - 1] = 1
    for i in range(n - 2, -1, -1):
        mxm = 0
        for j in range(i + 1, n):
            if a[j] % a[i] == 0 or a[i] % a[j] == 0:
                mxm = max(mxm, dp[j])
        dp[i] = 1 + mxm
    
    return max(dp)
a = [4,6,12]
n = len(a)
print(largestSubset(a, n))
"""
"""
def rse(arr,n):
    stack=[]
    ans=[]
    for i in range(n-1,-1,-1):
        if len(stack)==0:
            ans.append(n)
        else:
            while(len(stack)!=0):
                if stack[-1][0]>=arr[i]:
                    stack.pop()
                else:
                    break
            if len(stack)==0:
                ans.append(n)
            else:
                ans.append(stack[-1][1])
        stack.append([arr[i],i])
    ans.reverse()
    return ans
def lse(arr,n):
    stack=[]
    ans=[]
    for i in range(n):
        if len(stack)==0:
            ans.append(-1)
        else:
            while(len(stack)!=0):
                if stack[-1][0]>=arr[i]:
                    stack.pop()
                else:
                    break
            if len(stack)==0:
                ans.append(-1)
            else:
                ans.append(stack[-1][1])
        stack.append([arr[i],i])
    return ans
"""
"""
def lcs(s,r):
    rr=len(r)
    ss=len(s)
    l=[[0]*(rr+1) for i in range(ss+1)]
    for i in range(ss+1):
        for j in range(rr+1):
            if i==0 and j==0:
                l[i][j]=0
            elif s[i-1]==r[j-1]:
                l[i][j]=l[i-1][j-1]+1
            else:
                l[i][j] =max(l[i-1][j],l[i][j-1])
    return l[ss][rr]
"""
def factor(x):
    a=0
    if x==1:
        return 0
    
    if x%2==0:
        while(x%2==0):
            a+=1
            x//=2
    i=3
    c=int(math.sqrt(x))+1
    while(x>1 and i<c):
        if x%i==0:
            a+=1
            x//=i
        else:
            i+=2
    if x>1:
        a+=1
    return a
def main():
    t=1
    t=int(input())
    for _ in range(t):
        a,b,k=sep()
        if k==1:
            if a!=b and (a%b==0 or b%a==0):
                print("YES")
            else:
                print("NO")
            continue
        cnta=factor(a)
        cntb=factor(b)
       
        if cnta+cntb>=k:
            print("YES")
        else:
            print("NO")
if __name__ == '__main__':
    main()
