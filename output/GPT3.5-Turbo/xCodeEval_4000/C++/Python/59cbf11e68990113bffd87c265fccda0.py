import math

def do_save(l, r):
    pt = [0] * maxn1
    MSKA = 0
    MSKB = 0
    SZ = r - l
    for i in range(l, r):
        if arr[i] == 1:
            MSKA += (1 << (i - l))
        if arr[i] == -1:
            MSKB += (1 << (i - l))
    for msk in range(1 << SZ):
        if ((MSKA & msk) != MSKA) or ((MSKB & msk) != 0) or (pa1 + bin(msk).count('1') >= maxn1):
            continue
        cnta = pa1
        cntb = pb1
        num = pre1
        for i in range(SZ):
            if (msk >> i) & 1:
                num += C[cnta][A - 1] * C[cntb][A]
                cnta += 1
            else:
                num -= C[cnta][A] * C[cntb][A - 1]
                cntb += 1
        vec[cnta][pt[cnta]] = num
        pt[cnta] += 1
    for i in range(maxn1):
        vec[i] = sorted(vec[i][:pt[i]])

def do_calc(l, r):
    MSKA = 0
    MSKB = 0
    SZ = r - l
    ans = (inf, 0)
    for i in range(l, r):
        if arr[i] == 1:
            MSKA += (1 << (i - l))
        if arr[i] == -1:
            MSKB += (1 << (i - l))
    for msk in range(1 << SZ):
        pp = bin(msk).count('1')
        cnta = n - pp
        cntb = l - cnta
        start = cnta
        num = 0
        if cnta < 0 or cntb < 0 or (MSKA & msk) != MSKA or (MSKB & msk) != 0:
            continue
        for i in range(SZ):
            if (msk >> i) & 1:
                num += C[cnta][A - 1] * C[cntb][A]
                cnta += 1
            else:
                num -= C[cnta][A] * C[cntb][A - 1]
                cntb += 1
        it = bisect_left(vec[start][:pt[start]], -num)
        cand1 = (inf, 0)
        cand2 = (inf, 0)
        if it != pt[start]:
            x = vec[start][it]
            cand1 = (num + x, bisect_right(vec[start][it:pt[start]], x) - it)
        if it != 0:
            x = vec[start][it - 1]
            cand2 = (-num - x, it - bisect_left(vec[start][:it], x))
        if cand1[0] < ans[0]:
            ans = (cand1[0], 0)
        if cand2[0] < ans[0]:
            ans = (cand2[0], 0)
        if cand1[0] == ans[0]:
            ans = (ans[0], ans[1] + cand1[1])
        if cand2[0] == ans[0]:
            ans = (ans[0], ans[1] + cand2[1])
    return ans

def solve():
    ans = (inf, 0)
    Ca = 0
    Cb = 0
    for start in range(N):
        mid = (start + 1 + N) >> 1
        if Ca < A and arr[start] != -1 and Ca + start + 1 >= A and start >= 2 * A - 1:
            pa1 = A
            pb1 = start + 1 - A
            pre1 = C[pb1][A]
            do_save(start + 1, mid)
            p = do_calc(mid, N)
            if p[0] < ans[0]:
                ans = (p[0], 0)
            if p[0] == ans[0]:
                ans = (ans[0], ans[1] + C[start - Ca - Cb][A - 1 - Ca] * p[1])
        if Cb < A and arr[start] != 1 and Cb + start + 1 >= A and start >= 2 * A - 1:
            pb1 = A
            pa1 = start + 1 - A
            pre1 = -C[pa1][A]
            do_save(start + 1, mid)
            p = do_calc(mid, N)
            if p[0] < ans[0]:
                ans = (p[0], 0)
            if p[0] == ans[0]:
                ans = (ans[0], ans[1] + C[start - Ca - Cb][A - 1 - Cb] * p[1])
        Ca += arr[start] == 1
        Cb += arr[start] == -1
    return ans

maxn1 = 31
maxn2 = 100
maxn3 = (1 << 20) + 10
inf = int(1e18)

C = [[0] * maxn2 for _ in range(maxn2)]
arr = [0] * (2 * maxn1)
A = 0
B = 0
n = 0
N = 0
pa1 = 0
pb1 = 0
pre1 = 0
opt = [[0] * maxn2 for _ in range(maxn1)]
vec = [[0] * maxn3 for _ in range(maxn1)]
pt = [0] * maxn1

opt[1][1] = 0
opt[1][2] = 1
opt[1][3] = 0
opt[1][4] = 1
opt[1][5] = 0
opt[1][6] = 1
opt[1][7] = 0
opt[1][8] = 1
opt[1][9] = 0
opt[1][10] = 1
opt[1][11] = 0
opt[1][12] = 1
opt[1][13] = 0
opt[1][14] = 1
opt[1][15] = 0
opt[1][16] = 1
opt[1][17] = 0
opt[1][18] = 1
opt[1][19] = 0
opt[1][20] = 1
opt[2][1] = 3
opt[2][2] = 0
opt[2][3] = 2
opt[2][4] = 3
opt[2][5] = 1
opt[2][6] = 0
opt[2][7] = 0
opt[2][8] = 1
opt[2][9] = 1
opt[2][10] = 0
opt[2][11] = 0
opt[2][12] = 1
opt[2][13] = 1
opt[2][14] = 0
opt[2][15] = 0
opt[2][16] = 1
opt[2][17] = 1
opt[2][18] = 0
opt[2][19] = 0
opt[2][20] = 1
opt[3][1] = 8
opt[3][2] = 20
opt[3][3] = 0
opt[3][4] = 15
opt[3][5] = 16
opt[3][6] = 0
opt[3][7] = 0
opt[3][8] = 1
opt[3][9] = 0
opt[3][10] = 0
opt[3][11] = 0
opt[3][12] = 1
opt[3][13] = 0
opt[3][14] = 0
opt[3][15] = 0
opt[3][16] = 1
opt[3][17] = 0
opt[3][18] = 0
opt[3][19] = 0
opt[3][20] = 1
opt[4][1] = 15
opt[4][2] = 75
opt[4][3] = 175
opt[4][4] = 0
opt[4][5] = 4
opt[4][6] = 0
opt[4][7] = 0
opt[4][8] = 45
opt[4][9] = 15
opt[4][10] = 1
opt[4][11] = 1
opt[4][12] = 0
opt[4][13] = 0
opt[4][14] = 0
opt[4][15] = 0
opt[4][16] = 1
opt[4][17] = 1
opt[4][18] = 1
opt[4][19] = 1
opt[4][20] = 0
opt[5][1] = 24
opt[5][2] = 189
opt[5][3] = 784
opt[5][4] = 1764
opt[5][5] = 0
opt[5][6] = 0
opt[5][7] = 60
opt[5][8] = 95
opt[5][9] = 200
opt[5][10] = 1
opt[5][11] = 14
opt[5][12] = 14
opt[5][13] = 0
opt[5][14] = 4
opt[5][15] = 0
opt[5][16] = 1
opt[5][17] = 0
opt[5][18] = 1
opt[5][19] = 0
opt[5][20] = 0
opt[6][1] = 35
opt[6][2] = 392
opt[6][3] = 2352
opt[6][4] = 8820
opt[6][5] = 19404
opt[6][6] = 0
opt[6][7] = 6600
opt[6][8] = 553
opt[6][9] = 245
opt[6][10] = 10780
opt[6][11] = 658
opt[6][12] = 126
opt[6][13] = 56
opt[6][14] = 20
opt[6][15] = 0
opt[6][16] = 5
opt[6][17] = 5
opt[6][18] = 0
opt[6][19] = 0
opt[6][20] = 0
opt[7][1] = 48
opt[7][2] = 720
opt[7][3] = 5760
opt[7][4] = 29700
opt[7][5] = 104544
opt[7][6] = 226512
opt[7][7] = 0
opt[7][8] = 15015
opt[7][9] = 40040
opt[7][10] = 0
opt[7][11] = 1440
opt[7][12] = 2028
opt[7][13] = 432
opt[7][14] = 1280
opt[7][15] = 8
opt[7][16] = 249
opt[7][17] = 8
opt[7][18] = 20
opt[7][19] = 6
opt[7][20] = 4
opt[8][1] = 63
opt[8][2] = 1215
opt[8][3] = 12375
opt[8][4] = 81675
opt[8][5] = 382239
opt[8][6] = 1288287
opt[8][7] = 2760615
opt[8][8] = 0
opt[8][9] = 1635920
opt[8][10] = 198198
opt[8][11] = 534456
opt[8][12] = 4524
opt[8][13] = 1546
opt[8][14] = 111564
opt[8][15] = 4050
opt[8][16] = 621
opt[8][17] = 3069
opt[8][18] = 5
opt[8][19] = 43
opt[8][20] = 1
opt[9][1] = 80
opt[9][2] = 1925
opt[9][3] = 24200
opt[9][4] = 196625
opt[9][5] = 1145144
opt[9][6] = 5010005
opt[9][7] = 16359200
opt[9][8] = 34763300
opt[9][9] = 0
opt[9][10] = 34606
opt[9][11] = 701350
opt[9][12] = 6651840
opt[9][13] = 78298
opt[9][14] = 429418
opt[9][15] = 872494
opt[9][16] = 1615
opt[9][17] = 352
opt[9][18] = 1155
opt[9][19] = 8580
opt[9][20] = 145
opt[10][1] = 99
opt[10][2] = 2904
opt[10][3] = 44044
opt[10][4] = 429429
opt[10][5] = 3006003
opt[10][6] = 16032016
opt[10][7] = 66745536
opt[10][8] = 212751396
opt[10][9] = 449141836
opt[10][10] = 0
opt[10][11] = 11675872
opt[10][12] = 4900324
opt[10][13] = 980474
opt[10][14] = 120143080
opt[10][15] = 47159156
opt[10][16] = 380171
opt[10][17] = 35871
opt[10][18] = 2207348
opt[10][19] = 223498
opt[10][20] = 4875
opt[11][1] = 120
opt[11][2] = 4212
opt[11][3] = 75712
opt[11][4] = 869505
opt[11][5] = 7154784
opt[11][6] = 45048640
opt[11][7] = 225059328
opt[11][8] = 901995588
opt[11][9] = 2821056160
opt[11][10] = 5924217936
opt[11][11] = 0
opt[11][12] = 1763160100
opt[11][13] = 1014736800
opt[11][14] = 96243664
opt[11][15] = 527663136
opt[11][16] = 13024737
opt[11][17] = 1152008
opt[11][18] = 27986506
opt[11][19] = 835384
opt[12][1] = 143
opt[12][2] = 5915
opt[12][3] = 124215
opt[12][4] = 1656200
opt[12][5] = 15767024
opt[12][6] = 114874032
opt[12][7] = 668144880
opt[12][8] = 3173688180
opt[12][9] = 12342120700
opt[12][10] = 38013731756
opt[12][11] = 79483257308
opt[12][12] = 0
opt[12][13] = 334424
opt[12][14] = 86230664
opt[12][15] = 401457992
opt[12][16] = 1811255769
opt[12][17] = 8782619185
opt[12][18] = 524739891
opt[13][1] = 168
opt[13][2] = 8085
opt[13][3] = 196000
opt[13][4] = 2998800
opt[13][5] = 32626944
opt[13][6] = 271211472
opt[13][7] = 1802805120
opt[13][8] = 9859090500
opt[13][9] = 44986664800
opt[13][10] = 170724392916
opt[13][11] = 519227905728
opt[13][12] = 1081724803600
opt[13][13] = 0
opt[13][14] = 5856160
opt[13][15] = 0
opt[13][16] = 208030461065
opt[13][17] = 743483832
opt[14][1] = 195
opt[14][2] = 10800
opt[14][3] = 299200
opt[14][4] = 5202000
opt[14][5] = 64047024
opt[14][6] = 600935040
opt[14][7] = 4507012800
opt[14][8] = 27887141700
opt[14][9] = 145173803500
opt[14][10] = 641087516256
opt[14][11] = 2384209771200
opt[14][12] = 7174705330000
opt[14][13] = 14901311070000
opt[14][14] = 0
opt[14][15] = 262032716400
opt[14][16] = 2131715333625
opt[15][1] = 224
opt[15][2] = 14144
opt[15][3] = 443904
opt[15][4] = 8697744
opt[15][5] = 120187008
opt[15][6] = 1261963584
opt[15][7] = 10576456704
opt[15][8] = 73167596964
opt[15][9] = 427391677504
opt[15][10] = 2136958387520
opt[15][11] = 9183622822400
opt[15][12] = 33577620944400
opt[15][13] = 100136810390400
opt[15][14] = 207426250094400
opt[15][15] = 0
opt[16][1] = 255
opt[16][2] = 18207
opt[16][3] = 642447
opt[16][4] = 14084415
opt[16][5] = 216899991
opt[16][6] = 2530499895
opt[16][7] = 23518156167
opt[16][8] = 180305863947
opt[16][9] = 1168649118175
opt[16][10] = 6511045086975
opt[16][11] = 31479019635375
opt[16][12] = 132211882468575
opt[16][13] = 476432168185575
opt[16][14] = 1409850293610375
opt[17][1] = 288
opt[17][2] = 23085
opt[17][3] = 909720
opt[17][4] = 22174425
opt[17][5] = 378261576
opt[17][6] = 4873620213
opt[17][7] = 49911657840
opt[17][8] = 421129613025
opt[17][9] = 3003942370000
opt[17][10] = 18451716007725
opt[17][11] = 98815801429800
opt[17][12] = 464342770607625
opt[18][1] = 323
opt[18][2] = 28880
opt[18][3] = 1263500
opt[18][4] = 34051325
opt[18][5] = 639970331
opt[18][6] = 9058041608
opt[18][7] = 101671895600
opt[18][8] = 938731990625
opt[18][9] = 7322109526875
opt[18][10] = 49204576020600
opt[18][11] = 288924390600300
opt[18][12] = 1496215594180125
opt[19][1] = 360
opt[19][2] = 35700
opt[19][3] = 1724800
opt[19][4] = 51137625
opt[19][5] = 1053844176
opt[19][6] = 16309493200
opt[19][7] = 199708080000
opt[19][8] = 2008002335625
opt[19][9] = 17037595575000
opt[19][10] = 124510748462100
opt[19][11] = 795771174744000
opt[20][1] = 399
opt[20][2] = 43659
opt[20][3] = 2318239
opt[20][4] = 75274584
opt[20][5] = 1693678140
opt[20][6] = 28541613100
opt[20][7] = 379694987100
opt[20][8] = 4140135724725
opt[20][9] = 38044950918975
opt[20][10] = 300900975450075

C[0][0] = 1
for i in range(1, maxn2):
    C[i][i] = C[i][0] = 1
    for j in range(1, i):
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1]

A, B = map(int, input().split())
n = A + B
N = 2 * n
s = input()
for i in range(len(s)):
    if s[i] == 'A':
        arr[i] = 1
    if s[i] == 'B':
        arr[i] = -1

p = solve()
print(p[1] if p[0] == opt[A][B] else 0)