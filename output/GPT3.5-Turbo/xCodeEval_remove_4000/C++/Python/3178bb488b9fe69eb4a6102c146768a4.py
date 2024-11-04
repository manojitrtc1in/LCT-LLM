from collections import deque
from typing import List, Tuple, Set

def dfs1(x: int, y: int, d: int, siz: List[int], dep: List[int], graf: List[List[int]]) -> None:
    siz[x] = 1
    dep[x] = d
    for v in graf[x]:
        if v != y:
            dfs1(v, x, d + 1, siz, dep, graf)

def dfs2(x: int, y: int, d: int, ava: deque, ans: List[Tuple[Tuple[int, int], int]], graf: List[List[int]]) -> None:
    t = ava.popleft()
    print("pop", t)
    assert t > d
    ans.append(((x, y), t - d))
    print(x, y, d, ans[-1])
    for v in graf[x]:
        if v != y:
            dfs2(v, x, t, ava, ans, graf)

def dfs3(x: int, y: int, d: int, seen: Set[int], graf2: List[List[Tuple[int, int]]]) -> None:
    seen.add(d)
    for e in graf2[x]:
        if e[0] != y:
            dfs3(e[0], x, d + e[1], seen, graf2)

def test_ans(ans: List[Tuple[Tuple[int, int], int]], n: int, graf2: List[List[Tuple[int, int]]], seen: Set[int]) -> None:
    for x in ans:
        graf2[x[0][0]].append((x[0][1], x[1]))
        graf2[x[0][1]].append((x[0][0], x[1]))
    for i in range(1, n):
        dfs3(i, -1, 0, seen, graf2)
    print(seen)
    for i in range(1, n * n * 2 // 9):
        assert i in seen

def main() -> None:
    n = int(input())
    if n == 1:
        return
    print(n * n * 2 // 9)
    graf = [[] for _ in range(nax)]
    siz = [0] * nax
    dep = [0] * nax
    ans = []
    ava = deque()
    seen = set()
    graf2 = [[] for _ in range(nax)]
    for _ in range(n - 1):
        a, b = map(int, input().split())
        graf[a].append(b)
        graf[b].append(a)
    dfs1(1, -1, 0, siz, dep, graf)
    M = n * 2 // 3
    for i in range(1, n):
        sizes = [(1, i)]
        p = -1
        for v in graf[i]:
            if dep[v] == dep[i] + 1:
                sizes.append((siz[v], v))
            else:
                p = v
        if i != 1:
            sizes.append((n - siz[i], p))
        print(i, sizes)
        good = True
        for x in sizes:
            if x[0] > M:
                good = False
        if good:
            v1, v2 = [], []
            sizes.sort(reverse=True)
            sum1, sum2 = 0, 0
            whme = 0
            print(sizes)
            for c in sizes:
                if sum1 + c[0] > M:
                    v2.append(c)
                    sum2 += c[0]
                    if c[1] == i:
                        whme = 2
                else:
                    v1.append(c)
                    sum1 += c[0]
                    if c[1] == i:
                        whme = 1
                assert sum1 <= M and sum2 <= M
                print(sum1, sum2)
            assert sum1 * sum2 >= n * n * 2 // 9
            assert whme != 0
            if whme == 2:
                print("swap")
                v1, v2 = v2, v1
                sum1, sum2 = sum2, sum1
            for j in range(1, sum1):
                ava.append(j)
            print(ava)
            print(v1, v2)
            for x in v1:
                if x[1] != i:
                    dfs2(x[1], i, 0, ava, ans, graf)
            assert not ava
            for j in range(sum2):
                ava.append(1 + j * sum1)
            print(ava)
            for x in v2:
                dfs2(x[1], i, 0, ava, ans, graf)
            assert not ava
            for x in ans:
                print(x[0][0], x[0][1], x[1])
            test_ans(ans, n, graf2, seen)

if __name__ == "__main__":
    main()
