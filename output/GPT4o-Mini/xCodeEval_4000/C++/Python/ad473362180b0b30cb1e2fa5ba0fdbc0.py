from collections import defaultdict

INFLL = 1e18
MAXN = int(1e5) + 100
MAXNN = int(2e4) + 100
INF = int(1e9)
mod1 = int(1e9) + 7
mod2 = int(1e9) + 21
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

    def check_ans2(n):
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
            nonlocal now
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
            was_cnt1 = 0
            was_cnt2 = 0
            for w in dp[i]:
                cnt1 = 0
                cnt2 = 0
                w_val = w
                if prev_val + 1 == w:
                    cnt1 = was_cnt1
                    cnt2 = was_cnt2
                    w_val = prev_w
                    if s[prev_val] == '0':
                        cnt1 -= 1
                    else:
                        cnt2 -= 1
                while w_val < len(s) and cnt1 < sz1 and cnt2 < sz2:
                    if s[w_val] == '0':
                        cnt1 += 1
                    else:
                        cnt2 += 1
                    w_val += 1
                if cnt1 < sz1 and cnt2 < sz2:
                    continue
                prev_val = w
                prev_w = w_val
                was_cnt1 = cnt1
                was_cnt2 = cnt2
                if cnt1 == sz1:
                    if s[w] != '0':
                        continue
                else:
                    if s[w] != '1':
                        continue
                if i + 1 == len(a):
                    y = max(y, w_val)
                dp[i + 1][w_val] = True
                while w_val < len(s):
                    if s[w_val] == '0':
                        if cnt1 + 1 < sz1:
                            cnt1 += 1
                        else:
                            break
                    else:
                        if cnt2 + 1 < sz2:
                            cnt2 += 1
                        else:
                            break
                    w_val += 1
                    dp[i + 1][w_val] = True
                    if i + 1 == len(a):
                        y = max(y, w_val)
        return y

    def check_ans1(n):
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
            nonlocal now
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
            for w in dp[i]:
                cnt1 = 0
                cnt2 = 0
                sz1 = to[0][1] - to[0][0] + 1
                sz2 = to[1][1] - to[1][0] + 1
                w_val = w
                while w_val < len(s) and cnt1 < sz1 and cnt2 < sz2:
                    if s[w_val] == '0':
                        cnt1 += 1
                    else:
                        cnt2 += 1
                    w_val += 1
                if cnt1 < sz1 and cnt2 < sz2:
                    continue
                if cnt1 == sz1:
                    if s[w] != '0':
                        continue
                else:
                    if s[w] != '1':
                        continue
                dp[i + 1][w_val] = True
                while w_val < len(s):
                    if s[w_val] == '0':
                        if cnt1 + 1 < sz1:
                            cnt1 += 1
                        else:
                            break
                    else:
                        if cnt2 + 1 < sz2:
                            cnt2 += 1
                        else:
                            break
                    w_val += 1
                    dp[i + 1][w_val] = True

        if len(dp) > 0 and s in dp[len(a)]:
            return True
        return False

    now = 0
    l, r = 1, int(1e5)
    while l <= r:
        mid = (l + r) // 2
        w = check_ans2(mid)
        if w < len(s):
            l = mid + 1
        else:
            r = mid - 1
            now = mid
    while True:
        if check_ans1(now):
            return

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    _t = 1
    while _t > 0:
        solve()
        _t -= 1
