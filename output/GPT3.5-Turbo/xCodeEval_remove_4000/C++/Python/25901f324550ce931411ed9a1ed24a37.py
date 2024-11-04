import sys
from typing import List, Tuple

class Sparsetable_min:
    def __init__(self):
        self.vec = []
        self.lo = []
    
    def shoki1(self):
        self.vec = [[0] * cor for _ in range(beki + 1)]
        self.lo = [-1] + [0] * cor
        for i in range(1, cor + 1):
            self.lo[i] = self.lo[i >> 1] + 1
    
    def shoki2(self):
        for i in range(1, beki + 1):
            for j in range(cor):
                if j + (1 << (i - 1)) < cor:
                    self.vec[i][j] = min(self.vec[i - 1][j], self.vec[i - 1][j + (1 << (i - 1))])
                else:
                    self.vec[i][j] = self.vec[i - 1][j]
    
    def rangemin(self, i: int, j: int) -> int:
        haba = self.lo[j - i]
        return min(self.vec[haba][i], self.vec[haba][j - (1 << haba)])

class SAIS:
    def __init__(self):
        self.STR = ""
        self.S = []
        self.SL = []
        self.haba = []
        self.SA = []
        self.rank = []
        self.LCP = []
        self.id3 = 0
        self.len = 0
    
    def make_suffix_array_string(self, s: str):
        self.STR = s
        setc = set(s)
        mapc = {}
        cnt = 1
        for c in setc:
            mapc[c] = cnt
            cnt += 1
        self.S = [mapc[c] for c in s] + [0]
        self.id3 = cnt
        self.make_suffix_array_naibu()
    
    def make_suffix_array_saiki(self, ve: List[int], id0: int):
        self.S = ve + [0]
        self.id3 = id0 + 1
        self.make_suffix_array_naibu()
    
    def make_suffix_array_naibu(self):
        cnt = self.id3
        self.len = len(self.S)
        kosuu = [0] * cnt
        for c in self.S:
            kosuu[c] += 1
        
        self.haba.append((0, 0))
        for i in range(1, cnt):
            self.haba.append((self.haba[-1][1] + 1, self.haba[-1][1] + kosuu[i]))
        
        self.SL = [0] * self.len
        for i in range(self.len - 1, -1, -1):
            if i == self.len - 1:
                self.SL[i] = 1
            else:
                if self.S[i] < self.S[i + 1]:
                    self.SL[i] = 1
                elif self.S[i] > self.S[i + 1]:
                    self.SL[i] = 0
                else:
                    self.SL[i] = self.SL[i + 1]
        
        id7 = 0
        LMS = []
        id6 = [0] * self.len
        rt = 0
        for i in range(1, self.len):
            if self.SL[i - 1] == 0 and self.SL[i] == 1:
                LMS.append(i)
                id6[i] = rt
                id7 += 1
                rt += 1
        for i in range(id7 - 1):
            self.SL[LMS[i]] = -(LMS[i + 1] - LMS[i] + 1)
        self.SL[self.len - 1] = -1
        
        self.SA = [-1] * self.len
        pos = [0] * cnt
        for c in self.S:
            if self.SL[c] < 0:
                self.SA[self.haba[self.S[c]][1] - pos[self.S[c]]] = c
                pos[self.S[c]] += 1
        
        self.induced_sort(self.SA, self.len, cnt)
        
        ind1 = []
        ind2 = 0
        for i in range(self.len):
            if self.SL[self.SA[i]] < 0:
                if i == 0:
                    ind1.append((self.SA[i], 1))
                elif ind1[-1][1] == 1:
                    ind1.append((self.SA[i], 2))
                elif self.SL[self.SA[ind2]] != self.SL[self.SA[i]]:
                    ind1.append((self.SA[i], ind1[-1][1] + 1))
                else:
                    id5 = -self.SL[self.SA[ind2]]
                    bo = True
                    for j in range(id5):
                        if self.S[self.SA[ind2] + j] != self.S[self.SA[i] + j]:
                            bo = False
                            break
                    if bo:
                        ind1.append((self.SA[i], ind1[-1][1]))
                    else:
                        ind1.append((self.SA[i], ind1[-1][1] + 1))
                ind2 = i
        
        pos = [0] * cnt
        for i in range(self.len):
            self.SA[i] = -1
        if id7 == ind1[-1][1]:
            for i in range(id7 - 1, -1, -1):
                c = ind1[i][0]
                self.SA[self.haba[self.S[c]][1] - pos[self.S[c]]] = c
                pos[self.S[c]] += 1
        else:
            rec = [0] * len(LMS)
            for i in range(id7):
                rec[id6[ind1[i][0]]] = ind1[i][1]
            id4 = SAIS()
            id4.make_suffix_array_saiki(rec, ind1[-1][1])
            for i in range(id7, 0, -1):
                c = LMS[id4.SA[i]]
                self.SA[self.haba[self.S[c]][1] - pos[self.S[c]]] = c
                pos[self.S[c]] += 1
        
        self.induced_sort(self.SA, self.len, cnt)
        self.rank = [0] * self.len
        for i in range(self.len):
            self.rank[self.SA[i]] = i
    
    def induced_sort(self, ve: List[int], length: int, cnt: int):
        ue = [0] * cnt
        for i in range(length):
            if ve[i] == -1:
                continue
            if ve[i] == 0:
                continue
            if self.SL[ve[i] - 1] == 0:
                ve[self.haba[self.S[ve[i] - 1]][0] + ue[self.S[ve[i] - 1]]] = ve[i] - 1
                ue[self.S[ve[i] - 1]] += 1
            if self.SL[ve[i]] < 0 and i > 0:
                ve[i] = -1
        ue = [0] * cnt
        for i in range(length - 1, -1, -1):
            if ve[i] == -1:
                continue
            if ve[i] == 0:
                continue
            if self.SL[ve[i] - 1] != 0:
                ve[self.haba[self.S[ve[i] - 1]][1] - ue[self.S[ve[i] - 1]]] = ve[i] - 1
                ue[self.S[ve[i] - 1]] += 1
        for v in ve:
            if v == -1:
                assert False
    
    def make_lcp(self):
        self.LCP = [0] * self.len
        h = 0
        self.LCP[0] = 0
        for i in range(self.len - 1):
            j = self.SA[self.rank[i] - 1]
            if h > 0:
                h -= 1
            while j + h < self.len - 1 and i + h < self.len - 1:
                if self.S[j + h] != self.S[i + h]:
                    break
                h += 1
            self.LCP[self.rank[i] - 1] = h
    
    def lower_bound(self, p: str) -> int:
        m = len(p)
        ue, si = self.len, 0
        while ue - si > 1:
            me = (ue + si) // 2
            if self.STR.compare(self.SA[me], m, p) < 0:
                si = me
            else:
                ue = me
        return ue
    
    def exist(self, p: str) -> bool:
        l = len(p)
        id = self.lower_bound(p)
        return self.STR.compare(self.SA[id], l, p) == 0
    
    def range(self, p: str) -> Tuple[int, int]:
        return self.lower_bound(p), self.lower_bound(p + '{')

def solve(n: int, s: str, queries: List[Tuple[int, int, int]]) -> List[str]:
    ve = [0] * n
    cnt = 0
    t = ""
    for i in range(n):
        if s[i] == '1':
            ve[i] = cnt
        else:
            ve[i] = cnt
            cnt += 1
            if i % 2 == 1:
                t += "b"
            else:
                t += "a"
    m = len(t)
    if m == 0:
        return ["Yes"] * len(queries)
    for i in range(m):
        t += chr(ord('a') ^ ord('b') ^ ord(t[i]))
    
    ve.append(cnt)
    ss = SAIS()
    ss.make_suffix_array_string(t)
    ss.make_lcp()
    sm = Sparsetable_min()
    sm.shoki1()
    for i in range(len(ss.LCP)):
        sm.vec[0][i] = ss.LCP[i]
    sm.shoki2()
    
    res = []
    for l1, l2, p in queries:
        l1 -= 1
        l2 -= 1
        r1 = l1 + p
        r2 = l2 + p
        if ve[r1] - ve[l1] != ve[r2] - ve[l2]:
            res.append("No")
            continue
        if l1 % 2 == l2 % 2:
            if ve[r1] == ve[l1] or ve[r1] == ve[r2]:
                res.append("Yes")
                continue
            e1 = ss.rank[ve[l1]]
            e2 = ss.rank[ve[l2]]
            if e1 > e2:
                e1, e2 = e2, e1
            if sm.rangemin(e1, e2) >= ve[r1] - ve[l1]:
                res.append("Yes")
            else:
                res.append("No")
        else:
            if ve[r1] == ve[l1]:
                res.append("Yes")
                continue
            if ve[r1] == ve[r2]:
                res.append("No")
                continue
            e1 = ss.rank[ve[l1]]
            e2 = ss.rank[ve[l2] + m]
            if e1 > e2:
                e1, e2 = e2, e1
            if sm.rangemin(e1, e2) >= ve[r1] - ve[l1]:
                res.append("Yes")
            else:
                res.append("No")
    return res

def from_input_string(input_string: str) -> Tuple[int, str, List[Tuple[int, int, int]]]:
    lines = input_string.strip().split("\n")
    n = int(lines[0])
    s = lines[1]
    queries = []
    for line in lines[2:]:
        l1, l2, p = map(int, line.split())
        queries.append((l1, l2, p))
    return n, s, queries

def to_input_string(inputs: Tuple[int, str, List[Tuple[int, int, int]]]) -> str:
    n, s, queries = inputs
    res = []
    res.append(str(n))
    res.append(s)
    for query in queries:
        res.append(" ".join(str(x) for x in query))
    return "\n".join(res)

def from_output_string(output_string: str) -> List[str]:
    return output_string.strip().split("\n")

def to_output_string(output: List[str]) -> str:
    return "\n".join(output)
    
