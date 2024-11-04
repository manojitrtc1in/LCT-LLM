












































from calendar import c
import itertools
import heapq
import collections
import math
from operator import inv
from random import randrange
from re import A, M, T
import re
import sys
from tabnanny import check
from tkinter import N
from turtle import left
from typing import Counter

input = sys.stdin.readline



def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return (list(s[:len(s) - 1]))


def invr():
    return (map(int, input().split()))


def inis():
    return (input().split())


def stlt():
    return list(map(str, input().split()))





















def id0(n):
    prime = [True for i in range(n + 1)]
    p = 2
    l = []
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
    for p in range(2, n + 1):
        if prime[p]:
            l.append(p)
    return l


def isPrime(n):
    prime_flag = 0

    if n > 1:
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                prime_flag = 1
                break
        if prime_flag == 0:
            return True
        else:
            return False
    else:
        return False


def gcd(a):
    x = 0
    for p in a:
        x = math.gcd(x, p)
    return x



def id6(n):
    
    i = 1
    ans = []
    while i <= math.sqrt(n):

        if (n % i == 0):

            
            if (n / i == i):
                ans.append(i)
            else:
                
                ans.append(i)
                ans.append(n // i)
        i = i + 1
    ans.sort()
    return ans


def id3(n):
    return int(n, 2)


def id5(a, n):
    s = set()
    for i in range(n):
        s.add(a[i])
    count = 0
    for i in range(n):
        for j in range(i + 1, n, 1):
            xr = a[i] ^ a[j]
            if xr in s and xr != a[i] and xr != a[j]:
                count += 1
    return int(count // 3)


def id9(n):
    a = 0
    for i in range(1, n + 1):
        j = i + 2
        if isPrime(i) and isPrime(j):
            if 2 ^ (i ^ j) == 0:
                a += 1
    return a


def id4(n):
    if (n % 2 == 0):
        return 2
    i = 3
    while (i * i <= n):
        if (n % i == 0):
            return i
        i += 2
    return n


def countOdd(L, R):
    N = (R - L) // 2

    
    if (R % 2 != 0 or L % 2 != 0):
        N += 1

    return N


def isPalindrome(s):
    return s == s[::-1]


def power(x, y, p):
    res = 1 
    x = x % p
    while (y > 0):
        if (y & 1):
            res = (res * x) % p
        y = y >> 1 
        x = (x * x) % p
         
    return res

def id2(a, n):
	
	
	
	xpoints = collections.defaultdict(lambda:0)
	ypoints = collections.defaultdict(lambda:0)
	
	for i in range(n):
		xpoints[a[i][0]] += 1
		ypoints[a[i][1]] += 1
		
	
	count = 0
	
	
	
	for i in range(n):
		if (xpoints[a[i][0]] >= 1 and
			ypoints[a[i][1]] >= 1):
			
			
			
			count += ((xpoints[a[i][0]] - 1) *
					(ypoints[a[i][1]] - 1))
			
	
	return count






 






     
    





         
 


     

 










 







         


def MEX(a):
    b = [i for i in range(0, len(a) + 1)]
    a.sort()
    for i in range(len(a)):
        if a[i] != b[i]:
            return i
            

def id8(number):

    if number == 1 or number == 0:
        return 1

    id7 = False
    id1 = number

    if number & 1 == 1:
        id1 -= 1
        
        id7 = True

    next_sum = id1
    next_multi = id1
    factorial = 1

    while next_sum >= 2:
        factorial *= next_multi
        next_sum -= 2
        next_multi += next_sum

    if id7:
        factorial *= number

    return factorial




for i in range(inp()):
    n = inp()
    a = inlt()
    key = 0
    if n % 2 == 0:
        print("YES")
    else:
        if a == sorted(a):
            for j in range(n - 1):
                if a[j] == a[j + 1]:
                    key = 1
                    break
            if key == 1:
                print("YES")
            elif key == 0:
                print("NO")
        else:
            print("YES")