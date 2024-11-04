from collections import defaultdict
import sys
from itertools import permutations

MOD = int(1e9 + 7)
MN = int(1e6 + 44)

def mpow(b, e):
    o = 1
    while e:
        if e & 1:
            o = o * b % MOD
        b = b * b % MOD
        e //= 2
    return o

def backtrack(i, j):
    global sum, n, board, cou
    if i == n and j == 0:
        for row in board:
            print(" ".join(f"{x:2d}" for x in row))
        sys.exit(0)
    
    if j == 3:
        s = sum
        for x in range(3):
            s -= board[i][x]
        go(s, i, j)
        return
    
    if i == 3:
        s = sum
        for x in range(3):
            s -= board[x][j]
        go(s, i, j)
        return
    
    if i == 2 and j == 1:
        go(board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3], i, j)
        return
    
    if i == 2 and j == 2:
        o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1]
        if o % 2 == 0:
            go(o // 2, i, j)
        return
    
    if i == 1 and j == 0:
        for x in cou:
            if x[0] > board[0][1]:
                break
            go(x[0], i, j)
        return
    
    for x in cou:
        go(x[0], i, j)

def go(num, i, j):
    global board, cou
    it = cou.get(num, 0)
    if it == 0:
        return
    cou[num] -= 1
    board[i][j] = num
    if j == 3:
        backtrack(i + 1, 0)
    else:
        backtrack(i, j + 1)
    cou[num] += 1

n = int(input())
cou = defaultdict(int)
sum = 0
board = [[0] * 4 for _ in range(4)]

nums = []
for _ in range(n * n):
    x = int(input())
    cou[x] += 1
    sum += x
    nums.append(x)

assert sum % n == 0
sum //= n
print(sum)

if n <= 3:
    nums.sort()
    for perm in permutations(nums):
        good = True
        for i in range(n):
            s1 = sum(perm[i * n + j] for j in range(n))
            s2 = sum(perm[j * n + i] for j in range(n))
            if s1 != sum or s2 != sum:
                good = False
                break
        
        s1 = sum(perm[i * n + i] for i in range(n))
        s2 = sum(perm[i * n + n - i - 1] for i in range(n))
        if s1 != sum or s2 != sum:
            good = False
        
        if good:
            print(" ".join(map(str, perm)))
            sys.exit(0)

backtrack(0, 0)
