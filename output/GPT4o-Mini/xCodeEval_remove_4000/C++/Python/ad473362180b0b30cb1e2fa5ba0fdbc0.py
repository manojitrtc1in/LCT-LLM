from collections import defaultdict
import sys

INFLL = 10**18
MAXN = 10**5 + 100
MAXNN = 2 * 10**4 + 100
INF = 10**9
mod1 = 10**9 + 7
mod2 = 10**9 + 21

a = []
pref = [[0] * 2 for _ in range(MAXN)]
ha = [0] * MAXNN
haa_0 = [0] * MAXNN
haa_1 = [0] * MAXNN

def ms(l, r):
    if r <= l:
        return
    mid = (l + r + 1) // 2 - 1
    ms(l, mid)
    ms(mid + 1, r)
    a.append(((l, mid), (mid + 1, r)))

ss = ""
p = []

def mss(l, r):
    global ss
    if r <= l:
        return
    mid = (l + r + 1) // 2 - 1
    mss(l, mid)
    mss(mid + 1, r)
    i, j = l, mid + 1
    b = [0] * (r - l + 1)

    now = 0
    while i <= mid and j <= r:
        if p[i] < p[j]:
            ss += '0'
            b[now] = p[i]
            now += 1
            i += 1
        else:
            ss += '1'
            b[now] = p[j]
            now += 1
            j += 1
    while i <= mid:
        b[now] = p[i]
        now += 1
        i += 1
    while j <= r:
        b[now] = p[j]
        now += 1
        j += 1
    for i in range(l, r + 1):
        p[i] = b[i - l]

def solve():
    global ss, p
    s = input().strip()
    s = s[::-1]
    for i in range(1, len(s) + 1):
        if s[i - 1] == '0':
            pref[i][0] = pref[i - 1][0] + 1
            pref[i][1] = pref[i - 1][1]
        else:
            pref[i][1] = pref[i - 1][1] + 1
            pref[i][0] = pref[i - 1][0]

    def id3(n):
        global a
        a.clear()
        ms(0, n - 1)
        a.reverse()
        ans = [0] * n
        now = 0

        def does_zero(ff):
            nonlocal now
            cur = 1
            cnt1 = 0
            cnt2 = 0
            to = a[0]
            sz1 = to[0][1] - to[0][0] + 1
            sz2 = to[1][1] - to[1][0] + 1
            cnt1 = 0
            cnt2 = 0
            now = ff
            for i in range(now - 1, -1, -1):
                u = s[i]
                if u == '0':
                    ans[cnt1] = cur
                    cnt1 += 1
                else:
                    ans[sz1 + cnt2] = cur
                    cnt2 += 1
                cur += 1
            while cnt1 < sz1:
                ans[cnt1] = cur
                cnt1 += 1
                cur += 1
            while cnt2 < sz2:
                ans[sz1 + cnt2] = cur
                cnt2 += 1
                cur += 1

        def does(delta, _):
            to = a[_]
            cnt1 = 0
            cnt2 = 0
            sz1 = to[0][1] - to[0][0] + 1
            sz2 = to[1][1] - to[1][0] + 1
            was = now
            fir = [0] * sz1
            sec = [0] * sz2
            cnt1 = 0
            cnt2 = 0
            f = to[0][0]
            now += delta
            for i in range(now - 1, was - 1, -1):
                if s[i] == '0':
                    fir[cnt1] = ans[f]
                    cnt1 += 1
                else:
                    sec[cnt2] = ans[f]
                    cnt2 += 1
                f += 1
            assert cnt1 == sz1 or cnt2 == sz2
            assert cnt1 < sz1 or cnt2 < sz2
            while cnt1 < sz1:
                fir[cnt1] = ans[f]
                cnt1 += 1
                f += 1
            while cnt2 < sz2:
                sec[cnt2] = ans[f]
                cnt2 += 1
                f += 1
            for i in range(to[0][0], to[0][1] + 1):
                ans[i] = fir[i - to[0][0]]
            for i in range(to[1][0], to[1][1] + 1):
                ans[i] = sec[i - to[1][0]]

        dp = [defaultdict(bool) for _ in range(len(a) + 1)]
        dp[0][0] = True
        y = -INF
        for i in range(len(a)):
            if not dp[i]:
                break
            to = a[i]
            sz1 = to[0][1] - to[0][0] + 1
            sz2 = to[1][1] - to[1][0] + 1
            prev_val = -123
            prev_w = -1
            id2 = 0
            id0 = 0
            for w, _ in dp[i].items():
                cnt1 = 0
                cnt2 = 0
                w = w
                if prev_val + 1 == w:
                    cnt1 = id2
                    cnt2 = id0
                    w = prev_w
                    if s[prev_val] == '0':
                        cnt1 -= 1
                    else:
                        cnt2 -= 1
                while w < len(s) and cnt1 < sz1 and cnt2 < sz2:
                    if s[w] == '0':
                        cnt1 += 1
                    else:
                        cnt2 += 1
                    w += 1
                if cnt1 < sz1 and cnt2 < sz2:
                    continue
                prev_val = w
                prev_w = w
                id2 = cnt1
                id0 = cnt2
                if cnt1 == sz1:
                    if s[w] != '0':
                        continue
                else:
                    if s[w] != '1':
                        continue
                if i + 1 == len(a):
                    y = max(y, w)
                dp[i + 1][w] = True
                while w < len(s):
                    if s[w] == '0':
                        if cnt1 + 1 < sz1:
                            cnt1 += 1
                        else:
                            break
                    else:
                        if cnt2 + 1 < sz2:
                            cnt2 += 1
                        else:
                            break
                    w += 1
                    dp[i + 1][w] = True
                    if i + 1 == len(a):
                        y = max(y, w)

        return y

    def id1(n):
        global a
        a.clear()
        ms(0, n - 1)
        a.reverse()
        ans = [0] * n
        now = 0

        def does_zero(ff):
            nonlocal now
            cur = 1
            cnt1 = 0
            cnt2 = 0
            to = a[0]
            sz1 = to[0][1] - to[0][0] + 1
            sz2 = to[1][1] - to[1][0] + 1
            cnt1 = 0
            cnt2 = 0
            now = ff
            for i in range(now - 1, -1, -1):
                u = s[i]
                if u == '0':
                    ans[cnt1] = cur
                    cnt1 += 1
                else:
                    ans[sz1 + cnt2] = cur
                    cnt2 += 1
                cur += 1
            while cnt1 < sz1:
                ans[cnt1] = cur
                cnt1 += 1
                cur += 1
            while cnt2 < sz2:
                ans[sz1 + cnt2] = cur
                cnt2 += 1
                cur += 1

        def does(delta, _):
            to = a[_]
            cnt1 = 0
            cnt2 = 0
            sz1 = to[0][1] - to[0][0] + 1
            sz2 = to[1][1] - to[1][0] + 1
            was = now
            fir = [0] * sz1
            sec = [0] * sz2
            cnt1 = 0
            cnt2 = 0
            f = to[0][0]
            now += delta
            for i in range(now - 1, was - 1, -1):
                if s[i] == '0':
                    fir[cnt1] = ans[f]
                    cnt1 += 1
                else:
                    sec[cnt2] = ans[f]
                    cnt2 += 1
                f += 1
            assert cnt1 == sz1 or cnt2 == sz2
            assert cnt1 < sz1 or cnt2 < sz2
            while cnt1 < sz1:
                fir[cnt1] = ans[f]
                cnt1 += 1
                f += 1
            while cnt2 < sz2:
                sec[cnt2] = ans[f]
                cnt2 += 1
                f += 1
            for i in range(to[0][0], to[0][1] + 1):
                ans[i] = fir[i - to[0][0]]
            for i in range(to[1][0], to[1][1] + 1):
                ans[i] = sec[i - to[1][0]]

        dp = [defaultdict(bool) for _ in range(len(a) + 1)]
        dp[0][0] = True
        for i in range(len(a)):
            if not dp[i]:
                break
            to = a[i]
            for w, _ in dp[i].items():
                cnt1 = 0
                cnt2 = 0
                sz1 = to[0][1] - to[0][0] + 1
                sz2 = to[1][1] - to[1][0] + 1
                w = w
                while w < len(s) and cnt1 < sz1 and cnt2 < sz2:
                    if s[w] == '0':
                        cnt1 += 1
                    else:
                        cnt2 += 1
                    w += 1
                if cnt1 < sz1 and cnt2 < sz2:
                    continue
                if cnt1 == sz1:
                    if s[w] != '0':
                        continue
                else:
                    if s[w] != '1':
                        continue
                dp[i + 1][w] = True
                while w < len(s):
                    if s[w] == '0':
                        if cnt1 + 1 < sz1:
                            cnt1 += 1
                        else:
                            break
                    else:
                        if cnt2 + 1 < sz2:
                            cnt2 += 1
                        else:
                            break
                    w += 1
                    dp[i + 1][w] = True

        if len(dp) > 0 and s not in dp[len(a)]:
            return False

        dp = [defaultdict(bool) for _ in range(len(a) + 1)]
        from_map = [defaultdict(int) for _ in range(len(a) + 1)]
        dp[0][0] = True
        for i in range(len(a)):
            if not dp[i]:
                break
            to = a[i]
            for w, _ in dp[i].items():
                cnt1 = 0
                cnt2 = 0
                sz1 = to[0][1] - to[0][0] + 1
                sz2 = to[1][1] - to[1][0] + 1
                w = w
                while w < len(s) and cnt1 < sz1 and cnt2 < sz2:
                    if s[w] == '0':
                        cnt1 += 1
                    else:
                        cnt2 += 1
                    w += 1
                if cnt1 < sz1 and cnt2 < sz2:
                    continue
                if cnt1 == sz1:
                    if s[w] != '0':
                        continue
                else:
                    if s[w] != '1':
                        continue
                dp[i + 1][w] = True
                from_map[i + 1][w] = w
                while w < len(s):
                    if s[w] == '0':
                        if cnt1 + 1 < sz1:
                            cnt1 += 1
                        else:
                            break
                    else:
                        if cnt2 + 1 < sz2:
                            cnt2 += 1
                        else:
                            break
                    w += 1
                    dp[i + 1][w] = True
                    from_map[i + 1][w] = w

        if len(dp) > 0 and s not in dp[len(a)]:
            return False

        x = []
        now = 0
        ha = len(s)
        for j in range(len(a), 0, -1):
            f = from_map[j][ha]
            x.append(ha - f)
            ha = f
        x.reverse()
        does_zero(x[0])
        assert len(x) == len(a)
        for ii in range(1, len(x)):
            does(x[ii], ii)
        print(n)
        print(" ".join(map(str, ans)))
        return True

    now = 0
    l = 1
    r = 10**5
    while l <= r:
        mid = (l + r) // 2
        w = id3(mid)
        if w < len(s):
            l = mid + 1
        else:
            r = mid - 1
            now = mid
    while True:
        if id1(now):
            return

if __name__ == "__main__":
    input = sys.stdin.read
    solve()
