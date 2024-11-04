import itertools

def backtrack(i, j):
    if i == 3 and j == 0:
        for row in board:
            print(' '.join(map(str, row)))
        return True
    if j == 3:
        s = sum
        for x in range(3):
            s -= board[i][x]
        return go(s, i, j)
    if i == 3:
        s = sum
        for x in range(3):
            s -= board[x][j]
        return go(s, i, j)
    if i == 2 and j == 1:
        return go(board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3], i, j)
    if i == 2 and j == 2:
        o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1]
        if o % 2 == 0:
            return go(o // 2, i, j)
    if i == 1 and j == 0:
        for x in cou:
            if x > board[0][1]:
                break
            if go(x, i, j):
                return True
    for x in cou:
        if go(x, i, j):
            return True
    return False

def go(num, i, j):
    if num not in cou or cou[num] == 0:
        return False
    under = -1
    if i == 2:
        under = sum - board[0][j] - board[1][j] - num
        if under == num:
            if cou[num] < 2:
                return False
            cou[num] -= 1
        else:
            if under not in cou or cou[under] == 0:
                return False
            cou[under] -= 1
        board[3][j] = under
    cou[num] -= 1
    board[i][j] = num
    if j == 3:
        return backtrack(i + 1, 0)
    else:
        return backtrack(i, j + 1)
    cou[num] += 1
    if i == 2:
        cou[under] += 1
    return False

n = int(input())
nums = []
cou = {}
sum = 0
for _ in range(n * n):
    x = int(input())
    nums.append(x)
    if x in cou:
        cou[x] += 1
    else:
        cou[x] = 1
    sum += x
assert sum % n == 0
sum //= n
print(sum)
if n <= 3:
    nums.sort()
    for perm in itertools.permutations(nums):
        good = True
        for i in range(n):
            s1 = 0
            s2 = 0
            for j in range(n):
                s1 += perm[i * n + j]
                s2 += perm[j * n + i]
            if s1 != sum or s2 != sum:
                good = False
                break
        s1 = 0
        s2 = 0
        for i in range(n):
            s1 += perm[i * n + i]
            s2 += perm[i * n + n - i - 1]
        if s1 != sum or s2 != sum:
            good = False
        if good:
            for i in range(n * n):
                print(perm[i], end=' ')
                if (i + 1) % n == 0:
                    print()
            break
else:
    board = [[0] * 4 for _ in range(4)]
    backtrack(0, 0)
