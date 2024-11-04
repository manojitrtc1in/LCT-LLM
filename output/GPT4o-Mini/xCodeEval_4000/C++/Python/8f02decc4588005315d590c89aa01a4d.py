from collections import defaultdict
import sys
from itertools import permutations

MOD = int(1e9 + 7)
n = 0
sum = 0
board = [[0] * 4 for _ in range(4)]
cou = defaultdict(int)

def go(num, i, j):
    global sum
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

    cou[num] -= 1
    board[i][j] = num
    if j == 3:
        backtrack(i + 1, 0)
    else:
        backtrack(i, j + 1)
    cou[num] += 1
    if i == 2:
        cou[under] += 1

def backtrack(i, j):
    global sum
    if i == 3 and j == 0:
        for row in board[:n]:
            print(" ".join(f"{x:2d}" for x in row))
        sys.exit(0)

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

def main():
    global n, sum
    n = int(input())
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
                print("\n".join(" ".join(f"{perm[i * n + j]:2d}" for j in range(n)) for i in range(n)))
                return

    backtrack(0, 0)

if __name__ == "__main__":
    main()
