def mingrid():
    for _ in range(int(input())):
        n = int(input())
        segcost = input().split()
        minodd = int(segcost[0])
        mineven = int(segcost[1])
        sumodd = minodd
        sumeven = mineven
        codd = 1
        ceven = 1
        res = sumodd + minodd * (n - codd) + sumeven + mineven * (n - ceven)
        for i in range(2, n):
            now = int(segcost[i])
            if (i + 1) % 2:  
                minodd = min(minodd, now)
                sumodd += now
                codd += 1
            else:
                mineven = min(mineven, now)
                sumeven += now
                ceven += 1
            res = min(res, sumodd + minodd * (n - codd) + sumeven + mineven * (n - ceven))
        print(res)





def numofpairs():
    n = (10 * 2) ** 7 + 1
    l = [False] * n
    primes = []
    for i in range(2, n):
        if not l[i]:
            for i1 in range(i + i, n, i):
                l[i1] = True
            primes.append(i)
            l[i] = True
    tol = [0, 0]
    for i in range(2, n):
        pos = 0
        t = 0
        while i:
            val = primes[pos]
            if not i:
                tol.append(t)
                break
            elif i < val:
                tol.append(t + 1)
                break
            elif not i % val:
                i //= val
            else:
                pos += 1
                t += 1
    for _ in range(int(input())):
        c, d, x = map(int, input().split())
        lim = int(math.sqrt(x)) + 1
        ans = 0
        for i in range(1, lim):
            thing = i + d
            if thing % c:
                continue
            ans += (2 ** tol[thing // c])
        print(ans)




def restoremod():
    for _ in range(int(input())):
        length = int(input()) - 1
        l = input().split()
        
        t = False
        ife = False
        for i in range(length):
            if int(l[i]) == int(l[i + 1]):
                if i > 0:
                    print(-1)
                    t = True
                    break
                else:
                    ife = True
            elif ife:
                print(-1)
                t = True
                break
        if not t:
            posc = 0
            negc = 0
            res = int(l[1]) - int(l[0])
            if res > 0:
                posc = res
            else:
                negc = res
            if not negc:
                for i in range(1, length):
                    now = int(l[i]) - int(l[i + 1])
                    if now > 0:
                        negc = now
                        break
            if not posc:
                for i in range(1, length):
                    change = int(l[i + 1]) - int(l[i])
                    if change > 0:
                        posc = change
                        break
            if posc and negc:
                mod = posc + negc
            else:
                mod = 0
            c = posc if posc else -negc
            larnum = 0
            for i in range(length):
                nowi = int(l[i])
                larnum = max(larnum, nowi)
                if larnum > mod and mod:
                    print(-1)
                    t = True
                    break
                res = int(l[i + 1]) - nowi
                if res < 0:
                    if res != -(mod - c):
                        print(-1)
                        t = True
                        break
                if res > 0:
                    if res != c:
                        t = True
                        print(-1)
                        break
            if not t:
                if mod:
                    print(mod, c, sep=' ')
                else:
                    print(mod)




def restoremod1():
    for _ in range(int(input())):
        num = int(input())
        ...


def cells():
    for _ in range(int(input())):
        row, col, num = map(int, input().split())
        nr = ((num - 1) % row)
        nc = ((num - 1) // row) + 1
        print(nr * col + nc)




def replacement():
    for _ in range(int(input())):
        l, k = map(int, input().split())
        s = input()
        left, righ = s.find('*'), s.rfind('*')
        if righ - left <= k:
            print(2 if righ != left else 1)
        else:
            pos = left
            c = 2
            while righ - pos > k:
                pos = pos + k
                while pos < l and s[pos] != '*':
                    pos -= 1
                c += 1
            print(c)




import math

import sys

input = sys.stdin.readline


def string():
    for _ in range(int(input())):
        s = input().rstrip()
        s1 = input().rstrip()
        
        
        
        maxl = 0
        p1 = [0, 0]
        p = [0, 0]
        for i in range(len(s)):
            for i1 in range(i + 1, len(s) + 1):
                pos = s1.find(s[i:i1])
                if pos == -1:
                    break
                elif (i1 - i) <= maxl:
                    continue
                elif (i1 - i) > maxl:
                    maxl = i1 - i
                    p1 = [pos, pos + maxl]
                    p = [i, i + maxl]
        print(((p[0] + len(s) - p[1]) + (p1[0] + len(s1) - p1[1])) if maxl else len(s) + len(s1))




import collections


def trans(l):
    pos = 0
    while pos < len(l) - 1:
        avg = l[pos] // (len(l) - pos - 1)
        rem = l[pos] % (len(l) - pos - 1)
        l[pos] = 0
        for i in range(pos + 1, len(l)):
            l[i] -= avg
            if l[i] < 0:
                rem += -l[i]
                l[i] = 0
        while pos + 1 < len(l) and l[pos + 1] <= rem:
            rem -= l.pop(pos + 1)
        if pos + 1 < len(l):
            l[pos + 1] -= rem
        else:
            l[0] = rem
        pos += 1
    return sum(l)



def trans1(l):
    pos = 0
    lenl = len(l)
    pos1 = pos + 1
    while pos1 < lenl and pos < lenl:
        while pos1 < lenl and l[pos] - l[pos1] >= 0:
            l[pos] -= l[pos1]
            l[pos1] = 0
            pos1 += 1
        if pos1 < lenl:
            l[pos1] -= l[pos]
            l[pos] = 0
            pos = pos1
            pos1 += 1
    return sum(l)





def main():
    for _ in range(int(input())):
        num = input()
        l = sorted(list(collections.Counter(input().split()).values()), reverse=True)
        ans = trans(l[:])
        if ans:
            print(min(ans, trans1(l)))
        else:
            print(0)





def transrep():
    for _ in range(int(input())):
        num = int(input())
        l = list(collections.Counter(input().split()).values())
        ml = max(l)
        if ml > num - ml:
            print(ml - num + ml)
        else:
            print(num % 2)





def resmod():
    def solve():
        posc = -1
        negc = 1
        num = int(input())
        l = input().split()
        ifz = False
        maxi = int(l[0])
        for i in range(num - 1):
            maxi = max(maxi, int(l[i + 1]))
            c = int(l[i + 1]) - int(l[i])
            if c == 0:
                if not i:
                    ifz = True
                    continue
                elif not ifz:
                    return -1
            elif ifz:
                return -1
            elif c < 0:
                if negc == 1:
                    negc = c
                else:
                    if negc != c:
                        return -1
            elif c > 0:
                if posc == -1:
                    posc = c
                else:
                    if posc != c:
                        return -1
        if posc == -1 or negc == 1:
            return 0
        mod = posc + -negc
        if mod <= maxi:
            return -1
        return '{0} {1}'.format(mod, posc)

    for _ in range(int(input())):
        print(solve())





def basicdep():
    def findmax(l):
        ans = 0
        res = 0
        for i, v in enumerate(l):
            if ans < v:
                res = i
                ans = v
        return [res + 1, ans]  

    def roundup(num):
        s = num / 2
        if s != int(s):
            return int(s) + 1
        return int(s)

    for _ in range(int(input())):
        days = []
        f, d = map(int, input().split())
        friends = [0] * f
        for i in range(d):
            nowfs = input().split()
            nowff = int(nowfs[1])
            friends[nowff - 1] += 1
            if int(nowfs[0]) > 1:
                days.append([nowff, int(nowfs[2])])
            else:
                days.append([nowff, []])
        maxl = findmax(friends)
        goal = roundup(d)
        if maxl[1] < goal:
            print('YES')
            print(*[i[0] for i in days], sep=' ')
        else:
            pos = 0
            while pos < d and maxl[1] > goal:
                if days[pos][0] == maxl[0] and days[pos][1]:
                    days[pos][0] = days[pos][1]
                    maxl[1] -= 1
                pos += 1
            if maxl[1] > goal:
                print('NO')
            else:
                print('YES')
                print(*[i[0] for i in days], sep=' ')





def playlist():
    def nextsong(pos):
        while pos + 1 in ans and len(ans) != num:
            pos += 1
            if pos == num:
                pos = 0
        return pos

    def gcf(n, n1):
        if not n:
            return n1
        return gcf(n1, n % n1) if n1 else n

    for _ in range(int(input())):
        num = int(input())
        l = input().split()
        deletel = collections.deque()
        for i in range(num - 1):
            a, b = int(l[i]), int(l[i + 1])
            if gcf(a, b) == 1:
                deletel.append((i, i + 1))
        if gcf(int(l[-1]), int(l[0])) == 1:
            deletel.append((num - 1, 0))
        ans = dict()
        while deletel and len(ans) != num:
            a, b = deletel.popleft()
            if a + 1 in ans or b + 1 in ans:
                continue
            ans[b + 1] = True
            if deletel:
                if deletel[0][0] == b:
                    deletel.popleft()
            if b == num - 1:
                n = nextsong(0)
                if gcf(int(l[a]), int(l[n])) == 1:
                    deletel.append((a, n))
            else:
                n = nextsong(b + 1)
                if gcf(int(l[a]), int(l[n])) == 1:
                    deletel.append((a, n))
        print(len(ans), *ans.keys(), sep=' ')




def shoesandst():
    students, laces, = map(int, input().split())
    d = collections.defaultdict(list)
    rems = set()
    for _ in range(laces):
        a, b = map(int, input().split())
        d[a].append(b)
        d[b].append(a)
        lisa = d[a]
        lisb = d[b]
        la = len(lisa)
        lb = len(lisb)
        if la == 2:
            rems.discard((a, lisa[0]))
        elif la == 1:
            rems.add((a, b))
        if lb == 2:
            rems.discard((b, lisb[0]))
        elif lb == 1:
            rems.add((b, a))
    c = 0
    nextans = set()
    while rems or nextans:
        nextans.clear()
        while rems:
            a, b = rems.pop()
            nextans.discard((a, b))
            nextans.discard((b, a))
            d[a].pop()  
            d[b].remove(a)
            lb = len(d[b])
            if not lb:
                rems.discard((b, a))
            if lb == 1:
                nextans.add((b, d[b][0]))
        rems = nextans.copy()
        c += 1
    return c



import heapq


def restoreperm():
    for _ in range(int(input())):
        length = int(input())
        maxselect = []
        minselect = []
        ansma = []
        ansmi = []
        last = 0
        for i in input().split():
            i = int(i)
            if i == last:
                ansma.append(-heapq.heappop(maxselect))
                ansmi.append(heapq.heappop(minselect))
            else:
                ansma.append(i)
                ansmi.append(i)
                for num in range(last + 1, i):
                    heapq.heappush(maxselect, -num)
                    heapq.heappush(minselect, num)
                last = i
        print(*ansmi, sep=' ')
        print(*ansma, sep=' ')




def maxthestring():
    def check(l):
        return tcharacters.issubset(l)

    for _ in range(int(input())):
        s = input().rstrip()
        tcharacters = set(s)
        lsc = len(tcharacters)
        t = ''
        ts = set()
        remainings = collections.deque(s)
        while len(t) < lsc:
            maxc = ''
            for i in range(len(remainings)):
                charac = remainings.popleft()
                if maxc < charac and charac not in ts:
                    maxn = remainings.copy()
                    maxc = charac
                if check(remainings):
                    continue
                t += maxc
                ts.add(maxc)
                break
            remainings = maxn
            tcharacters.discard(maxc)
        print(t)





def maxthestring2():
    def filout(letter, s):
        iff = False
        ans = ''
        for i in s:
            if i != letter and iff:
                ans += i
            elif i == letter:
                iff = True
        return ans

    for _ in range(int(input())):
        s = input().rstrip()
        tcharacters = set(s)
        lsc = len(tcharacters)
        ans = ''
        while lsc:
            maxc = ''
            for i in tcharacters:
                news = filout(i, s)
                if len(set(news)) == lsc - 1 and maxc < i:
                    maxc = i
                    save = news
            tcharacters.discard(maxc)
            ans += maxc
            s = save
            lsc -= 1
        print(ans)







def maxthestring3():
    for _ in range(int(input())):
        s = input().rstrip()
        lastpos = {v: i for i, v in enumerate(s)}
        queue = []
        his = set()
        for i in range(len(s)):
            nowl = s[i]
            if nowl not in his:
                if queue:
                    while queue[-1] < nowl and lastpos[queue[-1]] > i:
                        his.discard(queue.pop())
                        if not queue:
                            break
                    queue.append(nowl)
                    his.add(nowl)
                else:
                    queue.append(nowl)
                    his.add(nowl)
        print(''.join(queue))





def gcdsum():
    def calc(num):
        dsum = 0
        for i in str(nownum):
            dsum += int(i)
        return dsum

    def gcd(a, b):
        if not a:
            return b
        if not b:
            return a
        return gcd(b, a % b)

    for _ in range(int(input())):
        nownum = int(input())
        dsum = calc(nownum)
        while gcd(dsum, nownum) == 1:
            nownum += 1
            dsum = calc(nownum)
        print(nownum)




def fitbox():
    for _ in range(int(input())):
        bnum, wid = map(int, input().split())
        boxes = sorted(list(collections.Counter(input().split()).items()), key=lambda x: int(x[0]), reverse=True)
        ans = 0
        while bnum:
            nwid = wid
            for i in range(len(boxes)):
                boxes[i] = list(boxes[i])
                w, c = boxes[i]
                w = int(w)
                while nwid - w >= 0 and c:
                    nwid -= w
                    c -= 1
                    bnum -= 1
                boxes[i][1] = c
            ans += 1
        print(ans)



import sys

sys.setrecursionlimit(10000)


def reflect():
    def recur(cur, plane, dir):
        if cur == 1:
            return 1
        now = l[cur][plane][dir]
        if now != -1:
            return now
        ans = 2
        if dir:  
            if cur > 1 and plane > 1:
                ans += recur(cur - 1, plane - 1, 0) - 1
            ans %= num
            if plane < planes:
                ans += recur(cur, plane + 1, 1) - 1
            ans %= num
        else:
            if cur > 1 and plane < planes:
                ans += recur(cur - 1, plane + 1, 1) - 1
            ans %= num
            if plane > 1:
                ans += recur(cur, plane - 1, 0) - 1
            ans %= num
        l[cur][plane][dir] = ans
        return ans

    num = int(1e9 + 7)
    for _ in range(int(input())):
        planes, begin = map(int, input().split())
        l = [[[-1] * 2 for _ in range(planes + 1)] for _ in range(begin + 1)]  
        print(recur(begin, 1, 1) % num)




mod = int(1e9 + 7)


def iter_solver(N, K):
    dp = [[[-1 for _ in range(2)] for __ in range(K + 1)] for ___ in range(N + 1)]
    for i in range(1, N + 1):
        dp[i][1][0] = dp[i][1][1] = 1
    
    for k in range(2, K + 1):
        
        for n in range(N, 0, -1):
            ans = 2

            if n < N:
                ans += dp[n + 1][k][0] - 1
                ans %= mod

            if n > 1:
                ans += dp[n - 1][k - 1][1] - 1
                ans %= mod

            dp[n][k][0] = ans

        
        for n in range(1, N + 1):
            ans = 2

            if n < N:
                ans += dp[n + 1][k - 1][0] - 1
                ans %= mod

            if n > 1:
                ans += dp[n - 1][k][1] - 1
                ans %= mod

            dp[n][k][1] = ans

    return dp[1][K][0]















































def dejavu():
    for _ in range(int(input())):
        s = input().rstrip()
        l = len(s)
        temp = s + 'a'
        if temp[::-1] != temp:
            print("YES")
            print(temp)
            continue
        if l == 1:
            if s == 'a':
                print('NO')
            else:
                print('YES')
                print(s + 'a')
            continue
        for i in range(l - 1, l // 2 - 1, -1):
            d = (l - i)
            if s[d] != 'a':
                print("YES")
                print(s[:i] + 'a' + s[i:])
                break
        else:
            print('NO')





def bits():
    for _ in range(int(input())):
        num = int(input())
        a = [i for i in input()]
        c1 = a.count('1')
        b = input()
        for i in range(num - 1, -1, -1):
            if a[i] != b[i]:
                if c1 != (i + 1) - c1:
                    print('NO')
                    break
                for i1 in range(i, -1, -1):
                    if a[i1] == '1':
                        a[i1] = '0'
                    else:
                        a[i1] = '1'
            if a[i] == '1':
                c1 -= 1

        else:
            print("YES")




def bitsrec():
    def tran(s, num):
        if num % 2:
            if s == '1':
                return '0'
            return '1'
        return s

    for _ in range(int(input())):
        num = int(input())
        a = input()
        b = input()
        flips = 0
        ones = a.count('1')
        for i in range(num - 1, -1, -1):
            if tran(a[i], flips) != b[i]:
                if ones != i - ones + 1:
                    print('NO')
                    break
                flips += 1
            if tran(a[i], flips) == '1':
                ones -= 1
        else:
            print("YES")




def balance():
    for _ in range(int(input())):
        l = int(input())
        s = input()
        ans = ''
        ans1 = ''
        open = 0
        for i in range(l):
            if not i % 2:
                ans += '('
                if s[i] == '0':
                    ans1 += ')'
                    open -= 1
                else:
                    ans1 += '('
                    open += 1
            else:
                ans += ')'
                if s[i] == '0':
                    ans1 += '('
                    open += 1
                else:
                    ans1 += ')'
                    open -= 1
            if open < 0:
                print('NO')
                break
        else:
            if not open:
                print('YES')
                print(ans)
                print(ans1)
            else:
                print('NO')





def balanceres():
    for _ in range(int(input())):
        num = int(input())
        s = [i for i in input().rstrip()]
        ones = 0
        ol = []
        zl = []
        for i in range(len(s)):
            if s[i] == '1':
                ones += 1
                ol.append(i)
            else:
                zl.append(i)
        zeros = num - ones
        if zeros % 2 or ones % 2 or s[0] == '0' or s[-1] == '0':
            print('NO')
        else:
            pl = ones // 2
            for i in range(ones):
                if i >= pl:
                    s[ol[i]] = ')'
                else:
                    s[ol[i]] = '('
            diffans = s[:]
            for i in range(zeros):
                p = zl[i]
                if i % 2:
                    diffans[p] = '('
                    s[p] = ')'
                else:
                    diffans[p] = ')'
                    s[p] = '('
            print("YES")
            print(*s, sep='')
            print(*diffans, sep='')



import sys


def coloring():
    n = int(input())
    blacks = set()  
    whites = set()  
    for i1 in range(n):
        for i in range(n):
            if (i + i1) % 2:
                blacks.add((i1 + 1, i + 1))
            else:
                whites.add((i1 + 1, i + 1))
    for i in range(n * n):
        colortochoose = int(input())
        if colortochoose == 1:  
            if blacks:
                print(2, *blacks.pop())
            else:
                print(3, *whites.pop())
        elif colortochoose == 2:
            if whites:
                print(1, *whites.pop())
            else:
                print(3, *blacks.pop())
        else:
            if whites:
                print(1, *whites.pop())
            else:
                print(2, *blacks.pop())
        sys.stdout.flush()




def isratedans():
    while True:
        try:
            q = input()
        except EOFError:
            break
        print("NO")
        sys.stdout.flush()





def reflectres():
    for _ in range(int(input())):
        planes, energy = map(int, input().split())
        count = [1] * planes
        ans = 1
        energy -= 1
        dir = 1
        while energy:
            if dir:
                cur = 0
                for i in range(planes-1,-1,-1):
                    temp = cur
                    cur = (cur + count[i]) % mod
                    count[i] = temp
            else:
                cur = 0
                for i in range(planes):
                    temp = cur
                    cur = (cur + count[i] % mod)
                    count[i] = temp
            ans = (ans + cur) % mod
            dir = 1-dir
            energy -= 1
        print(ans)

reflectres()