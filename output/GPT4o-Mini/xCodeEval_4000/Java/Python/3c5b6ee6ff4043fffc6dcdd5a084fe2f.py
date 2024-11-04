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
        self.rand = random.Random(0)
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
        que = deque()
        que.append(State(s, t))
        dist = {State(s, t): 0}

        while que:
            st = que.popleft()
            x, y = st.x, st.y
            curD = dist[st]

            if ('a' not in x or 'b' not in x) and ('a' not in y or 'b' not in y):
                return dist[st]

            for i in range(len(x) + 1):
                for j in range(len(y) + 1):
                    x0, x1 = x[:i], x[i:]
                    y0, y1 = y[:j], y[j:]

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
            p, q = len(rs), len(rt)
            x, y = -1, -1

            for xx in range(4):
                for yy in range(4):
                    if xx <= p and yy <= q and (xx + yy > 0) and (x + y != xx + yy) and (xx % 2 != yy % 2):
                        nx = p - xx + yy - (1 if xx != p and yy != 0 else 0)
                        ny = q - yy + xx - (1 if yy != q and xx != 0 else 0)

                        if nx > 0 and ny > 0 and nx + ny != p + q:
                            val = (self.fastDiff(nx, ny) + 1) if (xx == 0 or yy == 0) and (xx + yy) % 2 == 1 else (self.fastSame(nx, ny) + 1)

                            if self.fastSame(p, q) == val:
                                x, y = xx, yy
                                break

            if (x == 0 or y == 0) and (x + y) % 2 == 1:
                areSame = False

            delS, delT = [], []
            ans1, ans2 = 0, 0

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
            p, q = len(rs), len(rt)
            x, y = -1, -1

            for tp in range(1, 4, 2):
                for tq in range(1, 4, 2):
                    if tp <= p and tq <= q:
                        newP = p - tp + tq - (1 if tp != p else 0)
                        newQ = q - tq + tp - (1 if tq != q else 0)

                        if newP > 0 and newQ > 0 and newP + newQ != p + q:
                            if self.fastDiff(p, q) == self.fastDiff(newP, newQ) + 1:
                                x, y = tp, tq
                                break

            delS, delT = [], []
            ans1, ans2 = 0, 0

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
            ret = (x + y) // 2 - (1 if x % 2 == 0 else 0)
        elif (x + y) % 4 == 1:
            ret = (x + y) // 2 + (1 if x == 1 or y == 1 else 0)
        elif (x + y) % 4 == 2:
            ret = (x + y) // 2 - (1 if x not in [1, 2] and y not in [1, 2] and x % 2 == 1 else 0)
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
