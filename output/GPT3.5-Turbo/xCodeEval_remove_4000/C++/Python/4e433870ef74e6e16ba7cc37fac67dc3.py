def trinary(first, last, comp):
    assert first < last
    dist = last - first
    while dist > 2:
        left = first + dist // 3
        right = first + dist * 2 // 3
        if comp(left, right):
            last = right
            dist = dist * 2 // 3
        else:
            first = left
            dist -= dist // 3
    if dist > 1 and comp(first + 1, first):
        first += 1
    return first


def trinary_float(first, last, eps, comp):
    assert first < last
    while last - first > eps:
        left = (first * 2 + last) / 3
        right = (first + last * 2) / 3
        if comp(left, right):
            last = right
        else:
            first = left
    return first


def main():
    n, k = map(int, input().split())
    c = []
    pf = []
    for _ in range(n):
        v = int(input())
        if v < 0:
            c.append(-v)
        else:
            pf.append(v)

    pf.sort(reverse=True)
    ini = 0
    base = 0
    for e in pf:
        base += ini
        ini += e

    c.sort(reverse=True)

    if k == 0:
        for e in reversed(c):
            base += ini
            ini -= e
        print(base)
        return

    cs = [0] * (len(c) + 1)
    for i in range(len(c)):
        cs[i + 1] = cs[i] + (i // (k + 1) * c[i])
    sf = [0] * (len(c) + 1)
    sf2 = [0] * (len(c) + 1)
    for i in range(len(c) - 1, -1, -1):
        sf[i] = sf[i + 1] + c[i]
        sf2[i] = sf2[i + 1] + c[i] * i

    ans = -1e18
    for j in range(len(c) + 1):
        if j * (k + 1) < len(c):
            continue
        cd = (len(c) - j) // k
        tp = j - cd
        now = ini * j
        now -= sf2[len(c) - tp] + sf[tp] * (cd - (len(c) - tp))
        now -= cs[len(c) - tp]
        ans = max(ans, now)

    ans += base
    print(ans)


if __name__ == "__main__":
    main()
