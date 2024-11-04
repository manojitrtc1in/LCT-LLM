import sys
from collections import deque

class State:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __hash__(self):
        return hash((self.x, self.y))

    def __eq__(self, other):
        return (self.x, self.y) == (other.x, other.y)

def runs(s):
    ret = []
    run = 0
    for i in range(len(s) - 1, -1, -1):
        if i != len(s) - 1 and s[i + 1] != s[i]:
            ret.append(run)
            run = 0
        run += 1
    ret.append(run)
    return ret

def slow(s, t):
    que = deque()
    que.append(State(s, t))
    dist = {}
    dist[State(s, t)] = 0

    while que:
        st = que.popleft()
        x = st.x
        y = st.y
        curD = dist[st]

        if ('a' not in x or 'b' not in x) and ('a' not in y or 'b' not in y):
            return dist[st]

        for i in range(len(x) + 1):
            for j in range(len(y) + 1):
                x0 = x[:i]
                x1 = x[i:]
                y0 = y[:j]
                y1 = y[j:]
                nx = y0 + x1
                ny = x0 + y1
                nst = State(nx, ny)
                if nst not in dist:
                    dist[nst] = curD + 1
                    que.append(nst)

    raise AssertionError()

def fast(s, t):
    ret = []
    rs = runs(s)
    rt = runs(t)
    areSame = s[0] == t[0]

    while areSame:
        p = len(rs)
        q = len(rt)
        x = -1
        y = -1

        for xx in range(0, min(3, p) + 1):
            for yy in range(0, min(3, q) + 1):
                if xx + yy == 0 or x + y == xx + yy:
                    continue
                if xx % 2 == yy % 2:
                    continue
                nx = p - xx + yy
                if xx != p and yy != 0:
                    nx -= 1
                ny = q - yy + xx
                if yy != q and xx != 0:
                    ny -= 1
                if nx == 0 or ny == 0:
                    continue
                if nx + ny == p + q:
                    continue
                if (xx == 0 or yy == 0) and (xx + yy) % 2 == 1:
                    val = fastDiff(nx, ny) + 1
                else:
                    val = fastSame(nx, ny) + 1
                if fastSame(p, q) == val:
                    x = xx
                    y = yy
                    break

        if (x == 0 or y == 0) and (x + y) % 2 == 1:
            areSame = False

        delS = []
        delT = []
        ans1 = 0
        ans2 = 0

        for i in range(x):
            delta = rs.pop()
            ans1 += delta
            delS.append(delta)

        for i in range(y):
            delta = rt.pop()
            ans2 += delta
            delT.append(delta)

        ret.append(ans1)
        ret.append(ans2)

        delS.reverse()
        delT.reverse()

        for i in range(x):
            if i == 0 and rt:
                rt[-1] += delS[i]
            else:
                rt.append(delS[i])

        for i in range(y):
            if i == 0 and rs:
                rs[-1] += delT[i]
            else:
                rs.append(delT[i])

    while len(rs) > 1 or len(rt) > 1:
        p = len(rs)
        q = len(rt)
        x = -1
        y = -1

        for tp in range(1, min(3, p) + 1, 2):
            for tq in range(1, min(3, q) + 1, 2):
                newP = p - tp + tq
                if tp != p:
                    newP -= 1
                newQ = q - tq + tp
                if tq != q:
                    newQ -= 1
                if newP == 0 or newQ == 0:
                    continue
                if newP + newQ == p + q:
                    continue
                if fastDiff(p, q) == fastDiff(newP, newQ) + 1:
                    x = tp
                    y = tq
                    break

        delS = []
        delT = []
        ans1 = 0
        ans2 = 0

        for i in range(x):
            delta = rs.pop()
            ans1 += delta
            delS.append(delta)

        for i in range(y):
            delta = rt.pop()
            ans2 += delta
            delT.append(delta)

        ret.append(ans1)
        ret.append(ans2)

        delS.reverse()
        delT.reverse()

        for i in range(x):
            if i == 0 and rt:
                rt[-1] += delS[i]
            else:
                rt.append(delS[i])

        for i in range(y):
            if i == 0 and rs:
                rs[-1] += delT[i]
            else:
                rs.append(delT[i])

    print(len(ret) // 2)
    for i in range(0, len(ret), 2):
        print(ret[i], ret[i + 1])
    return len(ret) // 2

def fastSame(x, y):
    ret = (x + y) // 2
    if (x + y) % 4 == 1 and (x == 1 or y == 1):
        ret += 1
    return ret

def fastDiff(x, y):
    if x == 1 and y == 1:
        return 0
    if (x + y) % 4 == 0:
        ret = (x + y) // 2
        if x % 2 == 0:
            ret -= 1
    elif (x + y) % 4 == 1:
        ret = (x + y) // 2
        if x == 1 or y == 1:
            ret += 1
    elif (x + y) % 4 == 2:
        ret = (x + y) // 2
        if x != 1 and x != 2 and y != 1 and y != 2 and x % 2 == 1:
            ret -= 1
    elif (x + y) % 4 == 3:
        ret = (x + y) // 2
    else:
        raise AssertionError()
    return ret

def main():
    s = input().strip()
    t = input().strip()
    fast(s, t)

if __name__ == "__main__":
    main()
