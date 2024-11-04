#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }

char a1[] = "### ..# .#. #..";
char a2[] = ".#. ### .#. ###";
char a3[] = ".#. ..# ### #..";
vector<int> px[4], py[4];
int n, m, grid[10][10], mx, res[10][10];

void solve(int x, int y, int curr) {
    

    if (y >= m) { solve(x + 1, 0, curr); return; }
    if (x >= n) {
        if (curr > mx) mx = curr, memcpy(res, grid, sizeof(res));
        return;
    }
    int i, j, k, d, tmp[10][10], nx, ny;
    int mxPossible = 0;
    for (i = y; i < m; i++) if (grid[x][i] == 0) mxPossible++;
    for (i = x; i < n; i++) for (j = 0; j < m; j++) if (grid[i][j] == 0) mxPossible++;
    mxPossible /= 5;
    if (mxPossible + curr <= mx) return;
    memcpy(tmp, grid, sizeof(tmp));
    

    for (d = 0; d < 4; d++) {
        bool canPlace = 1;
        memcpy(grid, tmp, sizeof(tmp));
        for (i = 0; i < px[d].size(); i++) {
            nx = x + px[d][i];
            ny = y + py[d][i];
            if (nx >= n or ny >= m or grid[nx][ny]) {
                

                canPlace = 0; break;
            }
            grid[nx][ny] = curr + 1;
        }
        if (canPlace) {
            solve(x, y + 1, curr + 1);
        }
    }
    

    memcpy(grid, tmp, sizeof(tmp));
    solve(x, y + 1, curr);
}

void prec(int n, int m) {
    if (n == 1 and m == 1) puts("0\n.\n\n");
    if (n == 1 and m == 2) puts("0\n..\n\n");
    if (n == 1 and m == 3) puts("0\n...\n\n");
    if (n == 1 and m == 4) puts("0\n....\n\n");
    if (n == 1 and m == 5) puts("0\n.....\n\n");
    if (n == 1 and m == 6) puts("0\n......\n\n");
    if (n == 1 and m == 7) puts("0\n.......\n\n");
    if (n == 1 and m == 8) puts("0\n........\n\n");
    if (n == 1 and m == 9) puts("0\n.........\n\n");
    if (n == 2 and m == 1) puts("0\n.\n.\n\n");
    if (n == 2 and m == 2) puts("0\n..\n..\n\n");
    if (n == 2 and m == 3) puts("0\n...\n...\n\n");
    if (n == 2 and m == 4) puts("0\n....\n....\n\n");
    if (n == 2 and m == 5) puts("0\n.....\n.....\n\n");
    if (n == 2 and m == 6) puts("0\n......\n......\n\n");
    if (n == 2 and m == 7) puts("0\n.......\n.......\n\n");
    if (n == 2 and m == 8) puts("0\n........\n........\n\n");
    if (n == 2 and m == 9) puts("0\n.........\n.........\n\n");
    if (n == 3 and m == 1) puts("0\n.\n.\n.\n\n");
    if (n == 3 and m == 2) puts("0\n..\n..\n..\n\n");
    if (n == 3 and m == 3) puts("1\nAAA\n.A.\n.A.\n\n");
    if (n == 3 and m == 4) puts("1\nAAA.\n.A..\n.A..\n\n");
    if (n == 3 and m == 5) puts("2\nAAA.B\n.ABBB\n.A..B\n\n");
    if (n == 3 and m == 6) puts("2\nAAA.B.\n.ABBB.\n.A..B.\n\n");
    if (n == 3 and m == 7) puts("3\nAAABCCC\n.A.B.C.\n.ABBBC.\n\n");
    if (n == 3 and m == 8) puts("3\nAAA.BCCC\n.ABBB.C.\n.A..B.C.\n\n");
    if (n == 3 and m == 9) puts("4\nAAABCCC.D\n.A.B.CDDD\n.ABBBC..D\n\n");
    if (n == 4 and m == 1) puts("0\n.\n.\n.\n.\n\n");
    if (n == 4 and m == 2) puts("0\n..\n..\n..\n..\n\n");
    if (n == 4 and m == 3) puts("1\nAAA\n.A.\n.A.\n...\n\n");
    if (n == 4 and m == 4) puts("2\nAAA.\n.AB.\n.AB.\n.BBB\n\n");
    if (n == 4 and m == 5) puts("2\nAAA.B\n.ABBB\n.A..B\n.....\n\n");
    if (n == 4 and m == 6) puts("3\nAAABBB\n.AC.B.\n.AC.B.\n.CCC..\n\n");
    if (n == 4 and m == 7) puts("4\nAAABBB.\n.AC.BD.\n.AC.BD.\n.CCCDDD\n\n");
    if (n == 4 and m == 8) puts("4\nAAA.BCCC\n.ABBBDC.\n.A..BDC.\n....DDD.\n\n");
    if (n == 4 and m == 9) puts("5\nAAABBBCCC\n.AD.BE.C.\n.AD.BE.C.\n.DDDEEE..\n\n");
    if (n == 5 and m == 1) puts("0\n.\n.\n.\n.\n.\n\n");
    if (n == 5 and m == 2) puts("0\n..\n..\n..\n..\n..\n\n");
    if (n == 5 and m == 3) puts("2\nAAA\n.A.\n.AB\nBBB\n..B\n\n");
    if (n == 5 and m == 4) puts("2\nAAA.\n.AB.\n.AB.\n.BBB\n....\n\n");
    if (n == 5 and m == 5) puts("4\nAAA.B\n.ABBB\nCA.DB\nCCCD.\nC.DDD\n\n");
    if (n == 5 and m == 6) puts("4\nAAA.B.\n.ABBB.\n.AC.BD\nCCCDDD\n..C..D\n\n");
    if (n == 5 and m == 7) puts("5\nAAA.B..\n.ABBBC.\nDA.EBC.\nDDDECCC\nD.EEE..\n\n");
    if (n == 5 and m == 8) puts("6\nAAA.BCCC\n.ABBBDC.\nEA.FBDC.\nEEEFDDD.\nE.FFF...\n\n");
    if (n == 5 and m == 9) puts("7\nAAA.BCCC.\n.ABBBDC..\nEA.FBDCG.\nEEEFDDDG.\nE.FFF.GGG\n\n");
    if (n == 6 and m == 1) puts("0\n.\n.\n.\n.\n.\n.\n\n");
    if (n == 6 and m == 2) puts("0\n..\n..\n..\n..\n..\n..\n\n");
    if (n == 6 and m == 3) puts("2\nAAA\n.A.\n.AB\nBBB\n..B\n...\n\n");
    if (n == 6 and m == 4) puts("3\nAAA.\n.AB.\n.AB.\nCBBB\nCCC.\nC...\n\n");
    if (n == 6 and m == 5) puts("4\nAAA.B\n.ABBB\n.AC.B\nCCCD.\n..CD.\n..DDD\n\n");
    if (n == 6 and m == 6) puts("5\nAAA.B.\n.ABBB.\n.A.CB.\nDCCCE.\nDDDCE.\nD..EEE\n\n");
    if (n == 6 and m == 7) puts("6\nAAABCCC\n.A.B.C.\nDABBBCE\nDDDFEEE\nDFFF..E\n...F...\n\n");
    if (n == 6 and m == 8) puts("7\nAAA.BCCC\n.ABBBDC.\n.AE.BDC.\nEEEFDDDG\n..EF.GGG\n..FFF..G\n\n");
    if (n == 6 and m == 9) puts("8\nAAA.BCCC.\n.ABBB.C..\n.A.DBEC..\nFDDDGEEEH\nFFFDGEHHH\nF..GGG..H\n\n");
    if (n == 7 and m == 1) puts("0\n.\n.\n.\n.\n.\n.\n.\n\n");
    if (n == 7 and m == 2) puts("0\n..\n..\n..\n..\n..\n..\n..\n\n");
    if (n == 7 and m == 3) puts("3\nAAA\n.A.\n.AB\nBBB\n.CB\n.C.\nCCC\n\n");
    if (n == 7 and m == 4) puts("4\nAAA.\n.AB.\n.AB.\nCBBB\nCCCD\nCDDD\n...D\n\n");
    if (n == 7 and m == 5) puts("5\nAAA.B\n.ABBB\n.AC.B\nCCCD.\n.ECD.\n.EDDD\nEEE..\n\n");
    if (n == 7 and m == 6) puts("6\nAAA.B.\n.ABBB.\n.AC.BD\nCCCDDD\n.EC.FD\n.EFFF.\nEEE.F.\n\n");
    if (n == 7 and m == 7) puts("8\nAAABCCC\n.A.B.C.\nDABBBCE\nDDDFEEE\nDG.F.HE\n.GFFFH.\nGGG.HHH\n\n");
    if (n == 7 and m == 8) puts("9\nAAA.BBB.\n.ACCCBD.\n.AEC.BD.\nEEECFDDD\nG.EHFFFI\nGGGHFIII\nG.HHH..I\n\n");
    if (n == 7 and m == 9) puts("10\nAAA.BC...\n.ABBBCCCD\nEA.FBCDDD\nEEEF.GGGD\nEHFFFIGJ.\n.H.IIIGJ.\nHHH..IJJJ\n\n");
    if (n == 8 and m == 1) puts("0\n.\n.\n.\n.\n.\n.\n.\n.\n\n");
    if (n == 8 and m == 2) puts("0\n..\n..\n..\n..\n..\n..\n..\n..\n\n");
    if (n == 8 and m == 3) puts("3\nAAA\n.A.\n.AB\nBBB\n.CB\n.C.\nCCC\n...\n\n");
    if (n == 8 and m == 4) puts("4\nAAA.\n.AB.\n.AB.\nCBBB\nCCCD\nCDDD\n...D\n....\n\n");
    if (n == 8 and m == 5) puts("6\nAAA.B\n.ABBB\nCA.DB\nCCCD.\nCEDDD\n.EFFF\nEEEF.\n...F.\n\n");
    if (n == 8 and m == 6) puts("7\nAAA.B.\n.ABBB.\n.AC.BD\nCCCDDD\n..CE.D\nFEEEG.\nFFFEG.\nF..GGG\n\n");
    if (n == 8 and m == 7) puts("9\nAAAB..C\n.A.BCCC\nDABBBEC\nDDDEEE.\nDFFF.EG\n.HFIGGG\n.HFIIIG\nHHHI...\n\n");
    if (n == 8 and m == 8) puts("10\nAAA.BCCC\n.ABBBDC.\nEA.FBDC.\nEEEFDDDG\nEHFFFGGG\n.HIII.JG\nHHHIJJJ.\n...I..J.\n\n");
    if (n == 8 and m == 9) puts("12\nAAABBB..C\n.AD.BECCC\n.AD.BEEEC\nFDDDGEHHH\nFFFIGGGH.\nFJ.IGK.HL\n.JIIIKLLL\nJJJ.KKK.L\n\n");
    if (n == 9 and m == 1) puts("0\n.\n.\n.\n.\n.\n.\n.\n.\n.\n\n");
    if (n == 9 and m == 2) puts("0\n..\n..\n..\n..\n..\n..\n..\n..\n..\n\n");
    if (n == 9 and m == 3) puts("4\nAAA\n.A.\n.AB\nBBB\nC.B\nCCC\nC.D\nDDD\n..D\n\n");
    if (n == 9 and m == 4) puts("5\nAAA.\n.AB.\n.AB.\nCBBB\nCCCD\nCDDD\nEEED\n.E..\n.E..\n\n");
    if (n == 9 and m == 5) puts("7\nAAA.B\n.ABBB\nCA.DB\nCCCD.\nCEDDD\n.EEEF\nGEFFF\nGGG.F\nG....\n\n");
    if (n == 9 and m == 6) puts("8\nAAA.B.\n.ABBB.\n.AC.BD\nCCCDDD\nE.CF.D\nEEEF..\nEGFFFH\n.G.HHH\nGGG..H\n\n");
    if (n == 9 and m == 7) puts("10\nAAA.B..\n.ABBBC.\n.AD.BC.\nDDDECCC\nF.DEEEG\nFFFEGGG\nFHIIIJG\n.H.I.J.\nHHHIJJJ\n\n");
    if (n == 9 and m == 8) puts("12\nAAA.BCCC\n.ABBBDC.\nEA.FBDC.\nEEEFDDDG\nEHFFFGGG\n.HHHIIIG\nJHKKKIL.\nJJJK.IL.\nJ..K.LLL\n\n");
    if (n == 9 and m == 9) puts("13\nAAA.BCCC.\n.ABBB.CD.\n.AE.BFCD.\nEEEFFFDDD\nG.E.HFIII\nGGGJHHHI.\nGK.JHL.IM\n.KJJJLMMM\nKKK.LLL.M\n\n");
}

int main () {
    int i, j, tcc, tc = 1 << 28;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) if (a1[i * 4 + j] == '#') px[i].push_back(0), py[i].push_back(j);
        for (j = 0; j < 3; j++) if (a2[i * 4 + j] == '#') px[i].push_back(1), py[i].push_back(j);
        for (j = 0; j < 3; j++) if (a3[i * 4 + j] == '#') px[i].push_back(2), py[i].push_back(j);
    }
    for (tcc = 0; tcc < tc; tcc++) {
        n = getint(), m = getint(), mx = 0;
        prec(n, m); continue;
        if (n == 9 and m == 9) {
            puts("13");
            puts("AAA.BCCC.\n.ABBB.CD.\n.AE.BFCD.\nEEEFFFDDD\nG.E.HFIII\nGGGJHHHI.\nGK.JHL.IM\n.KJJJLMMM\nKKK.LLL.M\n");
            continue;
        }
        for (n = 1; n < 10; n++) for (m = 1; m < 10; m++) {
        memset(res, 0, sizeof(res));
        memset(grid, 0, sizeof(grid));
        mx = 0;
        solve(0, 0, 0);
        printf("if (n == %d and m == %d) puts(\"%d\\n", n, m, mx);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (res[i][j] == 0) putchar('.');
                else putchar('A' + res[i][j] - 1);
            }
            printf("\\n");
        }
        printf("\\n\");\n");
        }
    }
    return 0;
}

