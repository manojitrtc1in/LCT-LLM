from math import acos
from collections import deque
from itertools import permutations, combinations
from functools import reduce
from operator import add, mul, sub
from bisect import bisect_left, bisect_right
from heapq import heapify, heappop, heappush
from sys import stdin, stdout
from copy import deepcopy
from random import randint, shuffle
from time import time
from typing import List, Tuple, Dict, Any, Union

class InfInt:
    def __init__(self, val: Union[int, str] = 0):
        if isinstance(val, int):
            self.val = [abs(val)]
            self.pos = val >= 0
        elif isinstance(val, str):
            self.val = []
            self.pos = True
            if val[0] == '-':
                self.pos = False
                val = val[1:]
            for i in range(len(val), 0, -9):
                if i < 9:
                    self.val.append(int(val[:i]))
                else:
                    self.val.append(int(val[i-9:i]))
    
    def __str__(self) -> str:
        if not self.pos:
            return '-' + ''.join([str(x).zfill(9) for x in self.val[::-1]])
        else:
            return ''.join([str(x).zfill(9) for x in self.val[::-1]])
    
    def __add__(self, other: 'InfInt') -> 'InfInt':
        if self.pos and other.pos:
            return InfInt(str(self)) + InfInt(str(other))
        elif self.pos and not other.pos:
            return InfInt(str(self)) - InfInt(str(-other))
        elif not self.pos and other.pos:
            return InfInt(str(other)) - InfInt(str(-self))
        else:
            return -InfInt(str(-self)) - InfInt(str(-other))
    
    def __sub__(self, other: 'InfInt') -> 'InfInt':
        if self.pos and other.pos:
            if self >= other:
                return InfInt(str(self)) - InfInt(str(other))
            else:
                return -(InfInt(str(other)) - InfInt(str(self)))
        elif self.pos and not other.pos:
            return InfInt(str(self)) + InfInt(str(-other))
        elif not self.pos and other.pos:
            return InfInt(str(-other)) + InfInt(str(self))
        else:
            return InfInt(str(-self)) - InfInt(str(-other))
    
    def __mul__(self, other: 'InfInt') -> 'InfInt':
        if self.pos and other.pos:
            return InfInt(str(self)) * InfInt(str(other))
        elif self.pos and not other.pos:
            return -(InfInt(str(self)) * InfInt(str(-other)))
        elif not self.pos and other.pos:
            return -(InfInt(str(-self)) * InfInt(str(other)))
        else:
            return InfInt(str(-self)) * InfInt(str(-other))
    
    def __eq__(self, other: 'InfInt') -> bool:
        return str(self) == str(other)
    
    def __lt__(self, other: 'InfInt') -> bool:
        if self.pos and not other.pos:
            return False
        elif not self.pos and other.pos:
            return True
        elif self.pos and other.pos:
            if len(self.val) > len(other.val):
                return False
            elif len(self.val) < len(other.val):
                return True
            else:
                for i in range(len(self.val)-1, -1, -1):
                    if self.val[i] > other.val[i]:
                        return False
                    elif self.val[i] < other.val[i]:
                        return True
                return False
        else:
            if len(self.val) > len(other.val):
                return True
            elif len(self.val) < len(other.val):
                return False
            else:
                for i in range(len(self.val)-1, -1, -1):
                    if self.val[i] > other.val[i]:
                        return True
                    elif self.val[i] < other.val[i]:
                        return False
                return False
    
    def __le__(self, other: 'InfInt') -> bool:
        return self == other or self < other
    
    def __gt__(self, other: 'InfInt') -> bool:
        return not (self <= other)
    
    def __ge__(self, other: 'InfInt') -> bool:
        return not (self < other)
    
    def __abs__(self) -> 'InfInt':
        return InfInt(str(self))
    
    def __neg__(self) -> 'InfInt':
        return InfInt('-' + str(self))
    
    def __bool__(self) -> bool:
        return self.val != [0]
    
    def __int__(self) -> int:
        return int(str(self))
    
    def __add__(self, other: Union[int, str]) -> 'InfInt':
        return self + InfInt(other)
    
    def __sub__(self, other: Union[int, str]) -> 'InfInt':
        return self - InfInt(other)
    
    def __mul__(self, other: Union[int, str]) -> 'InfInt':
        return self * InfInt(other)
    
    def __eq__(self, other: Union[int, str]) -> bool:
        return self == InfInt(other)
    
    def __lt__(self, other: Union[int, str]) -> bool:
        return self < InfInt(other)
    
    def __le__(self, other: Union[int, str]) -> bool:
        return self <= InfInt(other)
    
    def __gt__(self, other: Union[int, str]) -> bool:
        return self > InfInt(other)
    
    def __ge__(self, other: Union[int, str]) -> bool:
        return self >= InfInt(other)
    
    def __abs__(self) -> 'InfInt':
        return abs(self)
    
    def __neg__(self) -> 'InfInt':
        return -self
    
    def __bool__(self) -> bool:
        return bool(self)
    
    def __int__(self) -> int:
        return int(self)

def alpha(n: int) -> InfInt:
    cnt, res = 10, 1
    for i in range(min(n, 11)):
        res *= cnt
        cnt = max(cnt-1, 0)
    return res

def beta(n: int) -> InfInt:
    cnt, res = 9, 9
    for i in range(min(n-1, 11)):
        res *= cnt
        cnt = max(cnt-1, 0)
    return res

def power(n: InfInt, p: int) -> InfInt:
    if p <= 0:
        return 1
    x = power(n, p//2)
    if p % 2 == 1:
        return x * x * n
    else:
        return x * x

s = input().strip()

leading = s[0]

if leading.isdigit():
    lead = False

bits = [False] * 30
cnt = 0

for c in s:
    if c.isalpha():
        bits[ord(c) - ord('A')] = True
    elif c == '?':
        cnt += 1

if not lead:
    res = alpha(bits.count(True)) * power(10, cnt)
else:
    if leading == '?':
        res = alpha(bits.count(True)) * power(10, cnt-1) * 9
    else:
        res = beta(bits.count(True)) * power(10, cnt)

print(res)
