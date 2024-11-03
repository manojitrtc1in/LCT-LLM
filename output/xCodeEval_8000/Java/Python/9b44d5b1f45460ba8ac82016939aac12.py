import sys
from typing import List, Tuple

def add(p1: int, p2: int, c1: int, c2: int, count: int, result: List[List[List[List[int]]]]) -> None:
    if p1 >= 0 and p2 >= 0 and c1 >= 0 and c2 >= 0 and count > 0:
        if p1 < len(result) and p2 < len(result[p1]) and c1 < len(result[p1][p2]) and c2 < len(result[p1][p2][c1]):
            result[p1][p2][c1][c2] += count

def add_previous(p1: int, p2: int, c1: int, c2: int, count: int, result: List[List[List[List[int]]]]) -> None:
    add(p1 - 1, p2, c1, c2, p1 * count, result)
    add(p1 + 1, p2 - 1, c1, c2, p2 * count, result)

def next(d: int, count: int, p1: int, p2: int, c1: int, c2: int, result: List[List[List[List[int]]]]) -> None:
    if p1 == 0 and p2 == 0:
        if d == 2:
            add_previous(c1, c2, 1, 0, count, result)
        else:
            add_previous(c1, c2, 0, 1, count, result)
    
    if d == 2:
        add_previous(p1, p2, c1 + 1, c2, count, result)
        add_previous(p1, p2, c1 - 1, c2, c1 * count, result)
        add_previous(p1, p2, c1 + 1, c2 - 1, c2 * count, result)
    else:
        add_previous(p1, p2, c1, c2 + 1, count, result)
        add_previous(p1, p2, c1, c2, c1 * count, result)
        add_previous(p1, p2, c1 + 2, c2 - 1, c2 * count, result)
        add_previous(p1, p2, c1 - 2, c2, c1 * (c1 - 1) // 2 * count, result)
        add_previous(p1, p2, c1, c2 - 1, c1 * c2 * count, result)
        add_previous(p1, p2, c1 + 2, c2 - 2, c2 * (c2 - 1) // 2 * count, result)

def solve(d: List[int]) -> int:
    count = [[[[0 for _ in range(len(d) // 2 + 1)] for _ in range(len(d) // 2 + 1)] for _ in range(len(d) // 2 + 1)] for _ in range(len(d) // 2 + 1)]
    if d[0] == 2:
        if d[1] == 2:
            count[1][0][1][0] = 1
        else:
            count[1][0][0][1] = 1
    else:
        if d[1] == 2:
            count[0][1][1][0] = 1
        else:
            count[0][1][0][1] = 1
    for u in range(2, len(d)):
        count_next = [[[[0 for _ in range(len(d) // 2 + 1)] for _ in range(len(d) // 2 + 1)] for _ in range(len(d) // 2 + 1)] for _ in range(len(d) // 2 + 1)]
        for p1 in range(len(d) // 2 + 1):
            for p2 in range(len(d) // 2 + 1):
                for c1 in range(len(d) // 2 + 1):
                    for c2 in range(len(d) // 2 + 1):
                        next(d[u], count[p1][p2][c1][c2] % 1000000007, p1, p2, c1, c2, count_next)
        count = count_next
    return count[0][0][0][0] % 1000000007

def main() -> None:
    n = int(input())
    d = list(map(int, input().split()))
    print(solve(d))

if __name__ == "__main__":
    main()
