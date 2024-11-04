from collections import defaultdict
from itertools import permutations

MOD = int(1e9 + 7)
MN = int(1e6 + 44)

def mark_stack(*args):
    pass  # Placeholder for the stack marking function

def print_stack():
    pass  # Placeholder for the stack printing function

def go(num, i, j):
    global board, sum, cou
    mark_stack(num, i, j)
    if num not in cou or cou[num] == 0:
        return
    under = -1
    if i == 2:
        under = sum - board[0][j] - board[1][j] - num
        if under == num:
            if cou[num] < 2:
                return
            cou[num] -= 1
        else:
            if under not in cou or cou[under] == 0:
                return
            cou[under] -= 1
        board[3][j] = under
    mark_stack(under)
    cou[num] -= 1
    board[i][j] = num
    if j == 3:
        backtrack(i + 1, 0)
    else:
        backtrack(i, j + 1)
    cou[num] += 1
    if i == 2:
        assert under in cou
        cou[under] += 1

def backtrack(i, j):
    global board, sum, cou
    mark_stack(i, j, board)
    if i == 3 and j == 0:
        for row in board:
            print(" ".join(f"{x:2d}" for x in row))
        print_stack()
        exit(0)
    if j == 3:
        s = sum
        for x in range(3):
            s -= board[i][x]
        go(s, i, j)
        return
    if i == 3:
        assert False
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
            if x > board[0][1]:
                break
            go(x, i, j)
        return
    for x in cou:
        go(x, i, j)

n = int(input())
cou = defaultdict(int)
sum = 0
board = [[0] * 4 for _ in range(4)]

for _ in range(n * n):
    x = int(input())
    cou[x] += 1
    sum += x

assert sum % n == 0
sum //= n
print(sum)

if n <= 3:
    nums = sorted(cou.keys())
    for perm in permutations(nums):
        good = True
        for i in range(n):
            s1 = sum(perm[i * n + j] for j in range(n))
            s2 = sum(perm[j * n + i] for j in range(n))
            if s1 != sum or s2 != sum:
                good = False
        s1 = sum(perm[i * n + i] for i in range(n))
        s2 = sum(perm[i * n + n - i - 1] for i in range(n))
        if s1 != sum or s2 != sum:
            good = False
        if good:
            print(" ".join(str(x) for x in perm))
            exit(0)

backtrack(0, 0)
