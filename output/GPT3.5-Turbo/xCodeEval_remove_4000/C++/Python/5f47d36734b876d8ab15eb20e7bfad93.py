import itertools

cou = {}
sum = 0
n = 0
board = [[0]*4 for _ in range(4)]

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
    global sum
    global n
    if i == n and j == 0:
        for row in board:
            print(' '.join(map(str, row)))
        exit(0)
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
        for x in sorted(cou.keys()):
            if x > board[0][1]:
                break
            go(x, i, j)
        return
    for x in sorted(cou.keys()):
        go(x, i, j)

def main():
    global sum
    global n
    n = int(input())
    nums = []
    for _ in range(n * n):
        x = int(input())
        if x not in cou:
            cou[x] = 0
        cou[x] += 1
        sum += x
        nums.append(x)
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
            s1 = 0
            s2 = 0
            for i in range(n):
                s1 += perm[i * n + i]
                s2 += perm[i * n + n - i - 1]
            if s1 != sum or s2 != sum:
                good = False
            if good:
                for i in range(n):
                    print(' '.join(map(str, perm[i * n: (i + 1) * n])))
                return
    backtrack(0, 0)

if __name__ == "__main__":
    main()
