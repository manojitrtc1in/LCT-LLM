from sys import stdin
from collections import deque

mod = 10**9 + 7
import sys
import random

from queue import PriorityQueue
from collections import Counter as cc


from bisect import bisect_right
from bisect import bisect_left
from collections import defaultdict
from math import sqrt,factorial,gcd,log2,inf,ceil



import heapq

input = lambda : sys.stdin.readline().rstrip()
from sys import stdin, stdout
from heapq import heapify, heappush, heappop
from itertools import permutations
from math import factorial as f



def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p

import sys






































































































































































































































































































































































































































































































































































































































































































































































































































def solve(flag):
    i = 0
    while i<n:

        if s[i] == 'a':
            j = i+7
            z = s[i:j]

            if z == k:
                flag+=1


        i+=1

    return flag


t = int(input())

for _ in range(t):

    n = int(input())
    s = list(input())
    k = list('abacaba')

    i = 0
    flag = 0

    flag = solve(flag)

    if flag == 1:
        print('YES')
        for i in range(n):
            if s[i] == '?':
                s[i] = 'z'

        print(''.join(s))

    elif flag>1:
        print('NO')
    else:
      i = 0
      flag = 0
      while i<n:

        if s[i] == 'a' or s[i] == '?':
            j = i+7

            if flag == 0:
                cnt = 0
                seti = set()
                for x in range(i,min(j,n)):

                    if s[x] == k[cnt]:
                        cnt+=1
                        continue
                    elif s[x] == '?':
                        s[x] = k[cnt]
                        seti.add(x)
                        cnt+=1
                    else:
                        break


                z = s[i:j]
                z1 = solve(0)

                if z1 == 1:
                    flag += 1

                else:
                    for x in seti:
                        s[x] = '?'
            else:

                for x in range(i,min(j,n)):

                    if s[x] == '?':
                        s[x] = 'z'



        i+=1

      if flag == 1:

          flag = solve(0)
          if flag == 1:
            for i in range(n):
                if s[i] == '?':
                    s[i] = 'z'
            print('YES')
            print(''.join(s))
          else:
              print('NO')
      else:
          print('NO')







