import sys
import random
from collections import deque

class State:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __hash__(self):
        return hash((self.x, self.y))

    def __eq__(self, other):
        return isinstance(other, State) and self.x == other.x and self.y == other.y

class D:
    def __init__(self):
        self.is_ = sys.stdin.buffer
        self.out = sys.stdout
        self.rng = random.Random(0)
        self.C = 7
        self.submit()

    def runs(self, s):
        ret = []
        run = 0
        for i in range(len(s) - 1, -1, -1):
            if i != len(s) - 1 and s[i + 1] != s[i]:
                ret.append(run)
                run = 0
            run += 1
        ret.append(run)
        return ret

    def slow(self, s, t):
        que = deque([State(s, t)])
        dist = {State(s, t): 0}

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

    def fast(self, s, t):
        ret = []
        rs = self.runs(s)
        rt = self.runs(t)
        areSame = s[0] == t[0]

        while areSame:
            p = len(rs)
            q = len(rt)
            x = -1
            y = -1

            for xx in range(4):
                if xx > p:
                    break
                for yy in range(4):
                    if yy > q:
                        break
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
                        val = self.fastDiff(nx, ny) + 1
                    else:
                        val = self.fastSame(nx, ny) + 1

                    if self.fastSame(p, q) == val:
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

            for tp in range(1, 4, 2):
                if tp > p:
                    break
                for tq in range(1, 4, 2):
                    if tq > q:
                        break

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

                    if self.fastDiff(p, q) == self.fastDiff(newP, newQ) + 1:
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

        self.out.write(f"{len(ret) // 2}\n")
        for i in range(0, len(ret), 2):
            self.out.write(f"{ret[i]} {ret[i + 1]}\n")
        return len(ret) // 2

    def submit(self):
        s = self.nextToken()
        t = self.nextToken()
        self.fast(s, t)

    def fastSame(self, x, y):
        ret = (x + y) // 2
        if (x + y) % 4 == 1 and (x == 1 or y == 1):
            ret += 1
        return ret

    def fastDiff(self, x, y):
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
            if x not in (1, 2) and y not in (1, 2) and x % 2 == 1:
                ret -= 1
        elif (x + y) % 4 == 3:
            ret = (x + y) // 2
        else:
            raise AssertionError()
        return ret

    def nextToken(self):
        b = self.skip()
        sb = []
        while not self.isTrash(b):
            sb.append(chr(b))
            b = self.readByte()
        return ''.join(sb)

    def readByte(self):
        if self.bufSz == -1:
            raise RuntimeError("Reading past EOF")
        if self.bufPtr >= self.bufSz:
            self.bufPtr = 0
            self.buf = self.is_.read(1 << 14)
            self.bufSz = len(self.buf)
            if self.bufSz <= 0:
                return -1
        ret = self.buf[self.bufPtr]
        self.bufPtr += 1
        return ret

    def isTrash(self, c):
        return c < 33 or c > 126

    def skip(self):
        b = self.readByte()
        while b != -1 and self.isTrash(b):
            b = self.readByte()
        return b

if __name__ == "__main__":
    D()
