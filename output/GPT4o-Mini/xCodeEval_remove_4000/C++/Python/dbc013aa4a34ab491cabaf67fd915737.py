from collections import defaultdict
from typing import List, Tuple, Dict, Any

def id5(str: str, pat: str) -> List[int]:
    loc = []
    for i in range(len(str)):
        if str[i] in pat:
            loc.append(i)
    return loc

def id28(i: int, j: int, str: List[str], vir: str, cache: List[Dict[int, Tuple[str, str]]]) -> Tuple[str, str]:
    if i == len(str[0]) or j == len(str[1]):
        return "", ""

    if j in cache[i]:
        return cache[i][j]

    if str[0][i] != str[1][j]:
        a = id28(i + 1, j, str, vir, cache)
        b = id28(i, j + 1, str, vir, cache)

        if len(a[0]) < len(b[0]):
            a, b = b, a

        bigger(a[1], b[0], a[0], len(vir))
        bigger(a[1], b[1], a[0], len(vir))

        return cache[i][j] = a
    else:
        rest = id28(i + 1, j + 1, str, vir, cache)
        a = str[0][i] + rest[0]
        b = str[0][i] + rest[1]

        for iter in rest[0]:
            if startswith(a, vir):
                a = str[0][i] + ''.join(iter)

        for iter in rest[1]:
            if startswith(b, vir):
                b = str[0][i] + ''.join(iter)

        if startswith(a, vir):
            a = ""
        if startswith(b, vir):
            b = ""

        if len(rest[0]) < len(a):
            rest[0], a = a, rest[0]

        bigger(rest[1], a, rest[0], len(vir))

        if len(rest[0]) < len(b):
            rest[0], b = b, rest[0]

        bigger(rest[1], b, rest[0], len(vir))

        return cache[i][j] = rest

def startswith(a: str, b: str) -> bool:
    return a.startswith(b)

def bigger(a: str, b: str, first: str, length: int) -> None:
    if len(a) < len(b) + 1:
        k = idiff(first, b, length)

        if len(a) < len(b) and k != -1:
            a, b = b, a
        elif len(a) == len(b) and k < idiff(first, a, length):
            a, b = b, a

def idiff(a: str, b: str, k: int) -> int:
    n = min(len(a), len(b)) + 1
    for i in range(min(n, k) - 1):
        if a[i] != b[i]:
            return i
    return -1

def b346() -> str:
    str = input().split()
    vir = input()

    cache = [defaultdict(str) for _ in range(len(str[0]))]

    val = id28(0, 0, str, vir, cache)
    return "0" if val == "" else val

if __name__ == "__main__":
    print(b346())
