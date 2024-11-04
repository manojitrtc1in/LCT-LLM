import sys
from collections import defaultdict
from itertools import permutations

MOD = 10**9 + 7
n = int(sys.stdin.readline().strip())
cou = defaultdict(int)
sum_nums = 0
board = [[0] * 4 for _ in range(4)]

def go(num, i, j):
    if num not in cou or cou[num] == 0:
        return
    cou[num] -= 1
    board[i][j] = num
    if j == 3:
        backtrack(i + 1, 0)
    else:
        backtrack(i, j + 1)
    cou[num] += 1

def backtrack(i, j):
    if i == n and j == 0:
        for row in board[:n]:
            print(" ".join(f"{x:2d}" for x in row[:n]))
        sys.exit(0)
    
    if j == 3:
        s = sum_nums
        for x in range(3):
            s -= board[i][x]
        if i == 0 and s < board[0][0]:
            return
        go(s, i, j)
        return
    
    if i == 3:
        s = sum_nums
        for x in range(3):
            s -= board[x][j]
        go(s, i, j)
        return
    
    if i == 2 and j == 1:
        v = board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3]
        if v >= board[0][0]:
            go(v, i, j)
        return
    
    if i == 2 and j == 2:
        o = board[0][3] + board[1][3] + sum_nums - board[2][0] - board[2][1] - board[0][0] - board[1][1]
        if o % 2 == 0 and o // 2 >= board[0][0]:
            go(o // 2, i, j)
        return
    
    limit = -float('inf')
    if (i == 0 and j == 2) or ((i == 1 or i == 2) and (j == 0)):
        limit = board[0][1]
    elif (i == j or i + j == 3) and (i or j):
        limit = board[0][0]
    
    for x in cou:
        if x >= limit:
            go(x, i, j)

sum_nums = 0
nums = []

for _ in range(n * n):
    x = int(sys.stdin.readline().strip())
    cou[x] += 1
    sum_nums += x
    nums.append(x)

assert sum_nums % n == 0
sum_nums //= n
print(sum_nums)

if n <= 3:
    nums.sort()
    for perm in permutations(nums):
        good = True
        for i in range(n):
            s1 = sum(perm[i * n + j] for j in range(n))
            s2 = sum(perm[j * n + i] for j in range(n))
            if s1 != sum_nums or s2 != sum_nums:
                good = False
                break
        
        s1 = sum(perm[i * n + i] for i in range(n))
        s2 = sum(perm[i * n + n - i - 1] for i in range(n))
        if s1 != sum_nums or s2 != sum_nums:
            good = False
        
        if good:
            print(" ".join(str(x) for x in perm))
            sys.exit(0)

backtrack(0, 0)
