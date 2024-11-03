import sys
from collections import deque

def find_substr_match(string, pattern):
    matches = []
    for i in range(len(string)):
        if string[i:i+len(pattern)] == pattern:
            matches.append(i)
    return matches

def b494():
    string, pattern = input().split()
    matches = find_substr_match(string, pattern)
    tag = [False] * len(string)
    for i in matches:
        tag[i] = True

    soln = [0] * len(string)
    cum = [0] * len(string)

    soln[0] = 1 if tag[0] else 0
    cum[0] = soln[0]

    mod = 10**9 + 7
    last = -1
    carry = 0

    for i in range(1, len(string)):
        if not tag[i]:
            soln[i] = soln[i-1] + (carry if last < i else 0)
            soln[i] %= mod
            cum[i] = (soln[i] + cum[i-1]) % mod
        else:
            last = i
            j = i - len(pattern) + 1
            soln[i] = soln[i-1] + 1 + j
            if j > 0:
                soln[i] += cum[j-1]
            soln[i] %= mod
            cum[i] = (soln[i] + cum[i-1]) % mod
            carry = (soln[i] - soln[i-1] + mod) % mod

    return (soln[-1] + mod) % mod

print(b494())
