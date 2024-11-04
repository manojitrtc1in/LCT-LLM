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


def main():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        a[i] -= 1

    ans = 0
    fre = -1

    cnt = {}
    for e in a:
        if e in cnt:
            cnt[e] += 1
        else:
            cnt[e] = 1
    ma = max(cnt.values())
    mac = 0
    for x, y in cnt.items():
        if y == ma:
            mac += 1
            fre = x
    if mac > 1:
        ans = n

    maxv = 100
    for i in range(maxv):
        if i == fre:
            continue
        b = [0]
        for e in a:
            pb = b[-1]
            if e == fre:
                pb -= 1
            elif e == i:
                pb += 1
            b.append(pb)
        mi = [n + 1] * (2 * n + 1)
        ma = [-1] * (2 * n + 1)
        for i in range(n + 1):
            va = n + b[i]
            mi[va] = min(mi[va], i)
            ma[va] = max(ma[va], i)
        j = n + 1
        for i in range(len(mi)):
            j = min(j, mi[i])
            ans = max(ans, ma[i] - j)

    print(ans)


if __name__ == "__main__":
    main()
