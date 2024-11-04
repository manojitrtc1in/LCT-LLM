import sys
from typing import List, Tuple, Dict, Any


def get_gain(xs: List[int], l: int, r: int) -> int:
    len = len(xs) - l - r
    return xs[l + len // 2] if len % 2 else 0


def c388() -> None:
    n = int(input())
    xs = []
    for _ in range(n):
        row = list(map(int, input().split()))
        xs.append(row)

    k = sum(len(row) for row in xs)
    acc = sum(sum(row) for row in xs)

    left = [0] * n
    right = [0] * n

    left_acc = 0

    for _ in range(k):
        imax = next(i for i, row in enumerate(xs) if len(row) > left[i] + right[i])
        val = get_gain(xs[imax], left[imax], right[imax])

        for i in range(imax + 1, n):
            if len(xs[i]) > left[i] + right[i]:
                g = get_gain(xs[i], left[i], right[i])
                if g > val:
                    val = g
                    imax = i

        if _ & 1:
            right[imax] += 1
        else:
            left_acc += xs[imax][left[imax]]
            left[imax] += 1

    print(left_acc, acc - left_acc)


def c20() -> None:
    n, m = map(int, input().split())

    adj = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))

    INF = sys.maxsize
    dist = [INF] * n
    dist[0] = 0

    heap = [(0, 0)]
    while heap:
        d, u = heap[0]
        heap[0], heap[-1] = heap[-1], heap[0]
        heap.pop()

        if dist[u] == d:
            for v, w in adj[u]:
                if d + w < dist[v]:
                    dist[v] = d + w
                    heap.append((dist[v], v))
                    heapify(heap)

    if dist[n - 1] != INF:
        path = []
        u = n - 1

        while u != 0:
            path.append(u)
            for v, w in adj[u]:
                if dist[v] + w == dist[u]:
                    u = v
                    break

        path.append(0)
        print(' '.join(map(str, reversed(path))))
    else:
        print(-1)


def b319() -> int:
    n = int(input())
    xs = list(map(int, input().split()))

    m = {}
    m[xs[0]] = 0
    val = 0

    for j in range(1, n):
        if xs[j] in m:
            m[xs[j]] += 1
            next = m[xs[j]] + 1
            if next in m:
                del m[next]
            else:
                m = {k: v for k, v in m.items() if k < xs[j]}
        else:
            val = max(val, max(m.values()))
            m = {}
        m[xs[j]] = 0

    val = max(val, max(m.values()))

    return val


def b41() -> int:
    n, b = map(int, input().split())
    a = list(map(int, input().split()))

    m = [0] * n
    m[-1] = a[-1]

    for j in range(n - 2, -1, -1):
        m[j] = max(m[j + 1], a[j])

    val = b
    for j in range(n):
        val = max(val, b % a[j] + b // a[j] * m[j])

    return val


def b99() -> str:
    cards = list(input().split())

    i = min(range(len(cards)), key=cards.__getitem__)
    j = max(range(len(cards)), key=cards.__getitem__)

    if cards[i] == cards[j]:
        return "Exemplary pages."
    elif (int(cards[i][1]) + int(cards[j][1])) % 2:
        return "Unrecoverable configuration."
    else:
        v = (int(cards[j][1]) - int(cards[i][1])) // 2
        cards[i] = cards[j] = cards[i][0] + str(int(cards[i][1]) + v)
        if len(set(cards)) == 1:
            return f"{v} ml. from cup #{i + 1} to cup #{j + 1}."
        else:
            return "Unrecoverable configuration."


def b70() -> None:
    n = int(input())
    input()
    s = input()

    xs = []
    i = 0
    while i < len(s):
        while i < len(s) and s[i] == ' ':
            i += 1

        j = i
        while j < len(s) and s[j] not in ['.', '?', '!']:
            j += 1

        if j < len(s):
            j += 1

        if j > i:
            xs.append(j - i)

        i = j

    if any(x > n for x in xs):
        print("Impossible")
    else:
        k = 0
        i = 0
        while i < len(xs):
            k += 1
            len = xs[i]

            while i < len(xs) and len + xs[i] <= n:
                len += 1 + xs[i]
                i += 1

        print(k)


def a442() -> int:
    cards = list(input())

    cnt_unq_char = len(set(card[0] for card in cards))
    cnt_unq_digit = len(set(card[1] for card in cards))

    char_map = {'R': 0, 'G': 1, 'B': 2, 'Y': 3, 'W': 4}

    xs = []
    for card in cards:
        xs.append((1 << char_map[card[0]], 1 << int(card[1])))

    val = cnt_unq_char + cnt_unq_digit - 2

    for i in range(1, 1 << 6):
        icnt = bin(i).count('1')
        if icnt < val:
            for j in range(1, 1 << 6):
                jcnt = bin(j).count('1')
                if icnt + jcnt < val:
                    flag = True

                    for a in xs:
                        for b in xs:
                            if a != b:
                                u = a[0] == b[0] or icnt + 1 < cnt_unq_char and not (a[0] & i) and not (b[0] & i)
                                v = a[1] == b[1] or jcnt + 1 < cnt_unq_digit and not (a[1] & j) and not (b[1] & j)

                                if v and u:
                                    flag = False
                                    break

                    if flag:
                        val = icnt + jcnt

    return val


def main() -> None:
    print(a442())


if __name__ == "__main__":
    main()
