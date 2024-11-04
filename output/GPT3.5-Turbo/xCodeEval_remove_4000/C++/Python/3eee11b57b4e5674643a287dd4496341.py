import sys
from typing import List, Tuple

def rowReduction(mat: List[int], basis: List[int]) -> None:
    for e in mat:
        for b in basis:
            e = min(e, e ^ b)
        if e:
            basis.append(e)
    basis.sort(reverse=True)

def find() -> int:
    mx = 0
    ret = -1
    for i in range(100):
        if mx < sum[i][n]:
            mx = sum[i][n]
            ret = i
    return ret

def solve(n: int, a: List[int]) -> int:
    b = [[] for _ in range(100)]
    for i in range(n):
        sum[a[i]][i + 1] += 1
        b[a[i]].append(i)
    for i in range(100):
        for j in range(n):
            sum[i][j + 1] += sum[i][j]
    i = find()
    ans = 0
    mp = [-1] * 404040
    for j in range(100):
        if i == j:
            continue
        if len(b[i]) == 0 or len(b[j]) == 0:
            continue
        x = 0
        y = 0
        now = 202020
        mp[202020] = 0
        era = []
        while True:
            if x != len(b[i]) and y != len(b[j]):
                if b[i][x] < b[j][y]:
                    tmp = (1, b[i][x])
                else:
                    tmp = (-1, b[j][y])
            elif x != len(b[i]):
                tmp = (1, b[i][x])
            elif y != len(b[j]):
                tmp = (-1, b[j][y])
            else:
                tmp = (-2, 0)
            if tmp[0] == -2:
                break
            if tmp[0] == 1:
                x += 1
            else:
                y += 1
            now += tmp[0]
            if mp[now] != -1:
                if tmp[0] == -2:
                    ans = max(ans, n - mp[now])
                else:
                    ans = max(ans, tmp[1] - mp[now])
            else:
                mp[now] = tmp[1] + 1
                era.append(now)
        for e in era:
            mp[e] = -1
    return ans

def main() -> None:
    n = int(input())
    a = list(map(int, input().split()))
    print(solve(n, a))

if __name__ == '__main__':
    main()
