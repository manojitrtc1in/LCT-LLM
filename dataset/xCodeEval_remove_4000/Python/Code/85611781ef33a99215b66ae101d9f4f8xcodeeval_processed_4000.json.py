def mingrid():
    for _ in range(int(input())):
        n = int(input())
        segcost = input().split()
        minodd = int(segcost[0])
        mineven = int(segcost[1])
        sumodd = minodd
        id2 = mineven
        codd = 1
        ceven = 1
        res = sumodd + minodd * (n - codd) + id2 + mineven * (n - ceven)
        for i in range(2, n):
            now = int(segcost[i])
            if (i + 1) % 2:  
                minodd = min(minodd, now)
                sumodd += now
                codd += 1
            else:
                mineven = min(mineven, now)
                id2 += now
                ceven += 1
            res = min(res, sumodd + minodd * (n - codd) + id2 + mineven * (n - ceven))
        print(res)





def id6():
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
            id3 = 0
            for i in range(length):
                nowi = int(l[i])
                id3 = max(id3, nowi)
                if id3 > mod and mod:
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




def id9():
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
        id5 = collections.deque()
        for i in range(num - 1):
            a, b = int(l[i]), int(l[i + 1])
            if gcf(a, b) == 1:
                id5.append((i, i + 1))
        if gcf(int(l[-1]), int(l[0])) == 1:
            id5.append((num - 1, 0))
        ans = dict()
        while id5 and len(ans) != num:
            a, b = id5.popleft()
            if a + 1 in ans or b + 1 in ans:
                continue
            ans[b + 1] = True
            if id5:
                if id5[0][0] == b:
                    id5.popleft()
            if b == num - 1:
                n = nextsong(0)
                if gcf(int(l[a]), int(l[n])) == 1:
                    id5.append((a, n))
            else:
                n = nextsong(b + 1)
                if gcf(int(l[a]), int(l[n])) == 1:
                    id5.append((a, n))
        print(len(ans), *ans.keys(), sep=' ')




def id4():
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




def id8():
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





def id7():
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







def id0():
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





def id1():
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
id1()



