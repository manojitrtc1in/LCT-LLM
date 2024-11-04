def main():
    n = int(input())
    a = list(map(int, input().split()))
    a = [x - 1 for x in a]

    ans = 0
    fre = -1

    cnt = {}
    for e in a:
        cnt[e] = cnt.get(e, 0) + 1

    ma = max(cnt.values())
    mac = sum(1 for y in cnt.values() if y == ma)
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
