class Sparsetable_min:
    def __init__(self):
        self.beki = 19
        self.cor = 1 << self.beki
        self.vec = [[0] * self.cor for _ in range(self.beki + 1)]
        self.lo = [-1] + [0] * self.cor
        for i in range(1, self.cor + 1):
            self.lo[i] = self.lo[i >> 1] + 1
    
    def shoki1(self):
        self.vec = [[0] * self.cor for _ in range(self.beki + 1)]
        self.lo = [-1] + [0] * self.cor
        for i in range(1, self.cor + 1):
            self.lo[i] = self.lo[i >> 1] + 1
    
    def shoki2(self):
        for i in range(1, self.beki + 1):
            for j in range(self.cor):
                if j + (1 << (i - 1)) < self.cor:
                    self.vec[i][j] = min(self.vec[i - 1][j], self.vec[i - 1][j + (1 << (i - 1))])
                else:
                    self.vec[i][j] = self.vec[i - 1][j]
    
    def rangemin(self, i, j):
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
        self.mojisu = 0
        self.len = 0
    
    def make_suffix_array_string(self, string):
        self.STR = string
        setc = set(string)
        mapc = {}
        cnt = 1
        for c in setc:
            mapc[c] = cnt
            cnt += 1
        self.S = [mapc[c] for c in string]
        self.mojisu = cnt
        self.S.append(0)
        self.make_suffix_array_naibu()
    
    def make_suffix_array_saiki(self, ve, max_valu):
        self.S = ve
        self.S.append(0)
        self.mojisu = max_valu + 1
        self.make_suffix_array_naibu()
    
    def make_suffix_array_naibu(self):
        cnt = self.mojisu
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
        
        LMS_num = 0
        LMS = []
        LMS_id = [0] * self.len
        rt = 0
        for i in range(1, self.len):
            if self.SL[i - 1] == 0 and self.SL[i] == 1:
                LMS.append(i)
                LMS_id[i] = rt
                LMS_num += 1
                rt += 1
        
        for i in range(LMS_num - 1):
            self.SL[LMS[i]] = -(LMS[i + 1] - LMS[i] + 1)
        self.SL[self.len - 1] = -1
        
        self.SA = [-1] * self.len
        pos = [0] * cnt
        for c in range(self.len):
            if self.SL[c] < 0:
                self.SA[self.haba[self.S[c]][1] - pos[self.S[c]]] = c
                pos[self.S[c]] += 1
        
        self.induced_sort(self.SA, self.len, cnt)
        
        lms_sub_order = []
        mae_ind = 0
        for i in range(self.len):
            if self.SL[self.SA[i]] < 0:
                if i == 0:
                    lms_sub_order.append((self.SA[i], 1))
                elif lms_sub_order[-1][1] == 1:
                    lms_sub_order.append((self.SA[i], 2))
                elif self.SL[self.SA[mae_ind]] != self.SL[self.SA[i]]:
                    lms_sub_order.append((self.SA[i], lms_sub_order[-1][1] + 1))
                else:
                    lmslen = -self.SL[self.SA[mae_ind]]
                    bo = True
                    for j in range(lmslen):
                        if self.S[self.SA[mae_ind] + j] != self.S[self.SA[i] + j]:
                            bo = False
                            break
                    if bo:
                        lms_sub_order.append((self.SA[i], lms_sub_order[-1][1]))
                    else:
                        lms_sub_order.append((self.SA[i], lms_sub_order[-1][1] + 1))
                mae_ind = i
        
        rec = [0] * len(LMS)
        for i in range(LMS_num):
            rec[LMS_id[lms_sub_order[i][0]]] = lms_sub_order[i][1]
        
        ss_naibu = SAIS()
        ss_naibu.make_suffix_array_saiki(rec, lms_sub_order[-1][1])
        
        for i in range(LMS_num, 0, -1):
            c = LMS[ss_naibu.SA[i]]
            self.SA[self.haba[self.S[c]][1] - pos[self.S[c]]] = c
            pos[self.S[c]] += 1
        
        self.induced_sort(self.SA, self.len, cnt)
        self.rank = [0] * self.len
        for i in range(self.len):
            self.rank[self.SA[i]] = i
    
    def induced_sort(self, ve, length, cnt):
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
    
    def lower_bound(self, p):
        m = len(p)
        ue, si = self.len, 0
        while ue - si > 1:
            me = (ue + si) // 2
            if self.STR.compare(self.SA[me], m, p) < 0:
                si = me
            else:
                ue = me
        return ue
    
    def exist(self, p):
        l = len(p)
        id = self.lower_bound(p)
        return self.STR.compare(self.SA[id], l, p) == 0
    
    def range(self, p):
        return (self.lower_bound(p), self.lower_bound(p + '{'))


def main():
    n = int(input())
    s = input()
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
                t += 'b'
            else:
                t += 'a'
    m = len(t)
    if m == 0:
        e = int(input())
        for _ in range(e):
            print("Yes")
        return
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
    q = int(input())
    for _ in range(q):
        l1, l2, p = map(int, input().split())
        l1 -= 1
        l2 -= 1
        r1 = l1 + p
        r2 = l2 + p
        if ve[r1] - ve[l1] != ve[r2] - ve[l2]:
            print("No")
            continue
        if l1 % 2 == l2 % 2:
            if ve[r1] == ve[l1] or ve[r1] == ve[r2]:
                print("Yes")
                continue
            e1 = ss.rank[ve[l1]]
            e2 = ss.rank[ve[l2]]
            if e1 > e2:
                e1, e2 = e2, e1
            if sm.rangemin(e1, e2) >= ve[r1] - ve[l1]:
                print("Yes")
            else:
                print("No")
        else:
            if ve[r1] == ve[l1]:
                print("Yes")
                continue
            if ve[r1] == ve[r2]:
                print("No")
                continue
            e1 = ss.rank[ve[l1]]
            e2 = ss.rank[ve[l2] + m]
            if e1 > e2:
                e1, e2 = e2, e1
            if sm.rangemin(e1, e2) >= ve[r1] - ve[l1]:
                print("Yes")
            else:
                print("No")


if __name__ == "__main__":
    main()
