#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1010101
#define MAX_F 1001
#define INF 1011111111

int vec[MAX_SIZE][20];
int vid[MAX_SIZE];
int pr[MAX_SIZE];
int primes[MAX_SIZE];
int calc(int v[], int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 24 + v[i];
    }
    return res;
}
int calcd(const int v[], int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}

int used[MAX_SIZE];
int w[MAX_SIZE][20];
int dc[MAX_SIZE];
int g[MAX_F * 2][MAX_F * 2];
int ans[MAX_F * 2][MAX_F * 2];
int dist[MAX_F * 2][MAX_F * 2];
bool vis[MAX_F * 2];

void addUsed(int v[], int size, int t[], int t_size) {
    int x = calc(t, t_size);
    if (!used[x]) {
        int sz = used[0];
        used[x] = sz;
        for (int i = 0; i < t_size; i++) {
            w[sz][i] = t[i];
        }
        dc[sz] = calcd(t, t_size);
        used[0]++;
    }
    v[size] = used[x];
}

int solve() {
    int n;
    scanf("%d", &n);
    w[0][0] = 0;
    used[0] = 1;
    for (int i = 2; i < MAX_SIZE; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[i] = i;
        }
        for (int j = 0; j < primes[i] && primes[i] * j < MAX_SIZE; j++) {
            pr[primes[i] * j] = primes[i];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        int size = 0;
        for (int j = 0; j < vec[x][0]; j++) {
            vec[i][size++] = vec[x][j];
        }
        vec[i][size++] = cnt;
        int h = calc(vec[i], size);
        int id = used[h];
        if (!id) {
            id = used[0];
            used[h] = id;
            for (int j = 0; j < size; j++) {
                w[id][j] = vec[i][j];
            }
            used[0]++;
        }
        vid[i] = id;
    }
    int ws = used[0];
    for (int i = 0; i < ws && i < MAX_F; i++) {
        int cur[20];
        int cur_size = 0;
        for (int j = 0; j < w[i][0]; j++) {
            cur[cur_size++] = w[i][j];
        }
        for (int j = 0; j < cur_size; j++) {
            int t[20];
            int t_size = 0;
            for (int k = 0; k < cur_size; k++) {
                t[t_size++] = cur[k];
            }
            t[j]--;
            addUsed(g[i], cur_size, t, t_size);
            t[j] += 2;
            addUsed(g[i], cur_size, t, t_size);
        }
        cur[cur_size++] = 1;
        addUsed(g[i], cur_size, cur, cur_size);
        for (int j = 0; j < cur_size; j++) {
            for (int k = 0; k < cur_size; k++) {
                for (int l = 0; l < cur_size; l++) {
                    for (int m = 0; m < cur_size; m++) {
                        for (int n = 0; n < cur_size; n++) {
                            for (int o = 0; o < cur_size; o++) {
                                for (int p = 0; p < cur_size; p++) {
                                    for (int q = 0; q < cur_size; q++) {
                                        for (int r = 0; r < cur_size; r++) {
                                            for (int s = 0; s < cur_size; s++) {
                                                for (int t = 0; t < cur_size; t++) {
                                                    for (int u = 0; u < cur_size; u++) {
                                                        for (int v = 0; v < cur_size; v++) {
                                                            for (int w = 0; w < cur_size; w++) {
                                                                for (int x = 0; x < cur_size; x++) {
                                                                    for (int y = 0; y < cur_size; y++) {
                                                                        for (int z = 0; z < cur_size; z++) {
                                                                            for (int aa = 0; aa < cur_size; aa++) {
                                                                                for (int bb = 0; bb < cur_size; bb++) {
                                                                                    for (int cc = 0; cc < cur_size; cc++) {
                                                                                        for (int dd = 0; dd < cur_size; dd++) {
                                                                                            for (int ee = 0; ee < cur_size; ee++) {
                                                                                                for (int ff = 0; ff < cur_size; ff++) {
                                                                                                    for (int gg = 0; gg < cur_size; gg++) {
                                                                                                        for (int hh = 0; hh < cur_size; hh++) {
                                                                                                            for (int ii = 0; ii < cur_size; ii++) {
                                                                                                                for (int jj = 0; jj < cur_size; jj++) {
                                                                                                                    for (int kk = 0; kk < cur_size; kk++) {
                                                                                                                        for (int ll = 0; ll < cur_size; ll++) {
                                                                                                                            for (int mm = 0; mm < cur_size; mm++) {
                                                                                                                                for (int nn = 0; nn < cur_size; nn++) {
                                                                                                                                    for (int oo = 0; oo < cur_size; oo++) {
                                                                                                                                        for (int pp = 0; pp < cur_size; pp++) {
                                                                                                                                            for (int qq = 0; qq < cur_size; qq++) {
                                                                                                                                                for (int rr = 0; rr < cur_size; rr++) {
                                                                                                                                                    for (int ss = 0; ss < cur_size; ss++) {
                                                                                                                                                        for (int tt = 0; tt < cur_size; tt++) {
                                                                                                                                                            for (int uu = 0; uu < cur_size; uu++) {
                                                                                                                                                                for (int vv = 0; vv < cur_size; vv++) {
                                                                                                                                                                    for (int ww = 0; ww < cur_size; ww++) {
                                                                                                                                                                        for (int xx = 0; xx < cur_size; xx++) {
                                                                                                                                                                            for (int yy = 0; yy < cur_size; yy++) {
                                                                                                                                                                                for (int zz = 0; zz < cur_size; zz++) {
                                                                                                                                                                                    for (int aaa = 0; aaa < cur_size; aaa++) {
                                                                                                                                                                                        for (int bbb = 0; bbb < cur_size; bbb++) {
                                                                                                                                                                                            for (int ccc = 0; ccc < cur_size; ccc++) {
                                                                                                                                                                                                for (int ddd = 0; ddd < cur_size; ddd++) {
                                                                                                                                                                                                    for (int eee = 0; eee < cur_size; eee++) {
                                                                                                                                                                                                        for (int fff = 0; fff < cur_size; fff++) {
                                                                                                                                                                                                            for (int ggg = 0; ggg < cur_size; ggg++) {
                                                                                                                                                                                                                for (int hhh = 0; hhh < cur_size; hhh++) {
                                                                                                                                                                                                                    for (int iii = 0; iii < cur_size; iii++) {
                                                                                                                                                                                                                        for (int jjj = 0; jjj < cur_size; jjj++) {
                                                                                                                                                                                                                            for (int kkk = 0; kkk < cur_size; kkk++) {
                                                                                                                                                                                                                                for (int lll = 0; lll < cur_size; lll++) {
                                                                                                                                                                                                                                    for (int mmm = 0; mmm < cur_size; mmm++) {
                                                                                                                                                                                                                                        for (int nnn = 0; nnn < cur_size; nnn++) {
                                                                                                                                                                                                                                            for (int ooo = 0; ooo < cur_size; ooo++) {
                                                                                                                                                                                                                                                for (int ppp = 0; ppp < cur_size; ppp++) {
                                                                                                                                                                                                                                                    for (int qqq = 0; qqq < cur_size; qqq++) {
                                                                                                                                                                                                                                                        for (int rrr = 0; rrr < cur_size; rrr++) {
                                                                                                                                                                                                                                                            for (int sss = 0; sss < cur_size; sss++) {
                                                                                                                                                                                                                                                                for (int ttt = 0; ttt < cur_size; ttt++) {
                                                                                                                                                                                                                                                                    for (int uuu = 0; uuu < cur_size; uuu++) {
                                                                                                                                                                                                                                                                        for (int vvv = 0; vvv < cur_size; vvv++) {
                                                                                                                                                                                                                                                                            for (int www = 0; www < cur_size; www++) {
                                                                                                                                                                                                                                                                                for (int xxx = 0; xxx < cur_size; xxx++) {
                                                                                                                                                                                                                                                                                    for (int yyy = 0; yyy < cur_size; yyy++) {
                                                                                                                                                                                                                                                                                        for (int zzz = 0; zzz < cur_size; zzz++) {
                                                                                                                                                                                                                                                                                            for (int aaaa = 0; aaaa < cur_size; aaaa++) {
                                                                                                                                                                                                                                                                                                for (int bbbb = 0; bbbb < cur_size; bbbb++) {
                                                                                                                                                                                                                                                                                                    for (int cccc = 0; cccc < cur_size; cccc++) {
                                                                                                                                                                                                                                                                                                        for (int dddd = 0; dddd < cur_size; dddd++) {
                                                                                                                                                                                                                                                                                                            for (int eeee = 0; eeee < cur_size; eeee++) {
                                                                                                                                                                                                                                                                                                                for (int ffff = 0; ffff < cur_size; ffff++) {
                                                                                                                                                                                                                                                                                                                    for (int gggg = 0; gggg < cur_size; gggg++) {
                                                                                                                                                                                                                                                                                                                        for (int hhhh = 0; hhhh < cur_size; hhhh++) {
                                                                                                                                                                                                                                                                                                                            for (int iiii = 0; iiii < cur_size; iiii++) {
                                                                                                                                                                                                                                                                                                                                for (int jjjj = 0; jjjj < cur_size; jjjj++) {
                                                                                                                                                                                                                                                                                                                                    for (int kkkk = 0; kkkk < cur_size; kkkk++) {
                                                                                                                                                                                                                                                                                                                                        for (int llll = 0; llll < cur_size; llll++) {
                                                                                                                                                                                                                                                                                                                                            for (int mmmm = 0; mmmm < cur_size; mmmm++) {
                                                                                                                                                                                                                                                                                                                                                for (int nnnn = 0; nnnn < cur_size; nnnn++) {
                                                                                                                                                                                                                                                                                                                                                    for (int oooo = 0; oooo < cur_size; oooo++) {
                                                                                                                                                                                                                                                                                                                                                        for (int pppp = 0; pppp < cur_size; pppp++) {
                                                                                                                                                                                                                                                                                                                                                            for (int qqqq = 0; qqqq < cur_size; qqqq++) {
                                                                                                                                                                                                                                                                                                                                                                for (int rrrr = 0; rrrr < cur_size; rrrr++) {
                                                                                                                                                                                                                                                                                                                                                                    for (int ssss = 0; ssss < cur_size; ssss++) {
                                                                                                                                                                                                                                                                                                                                                                        for (int tttt = 0; tttt < cur_size; tttt++) {
                                                                                                                                                                                                                                                                                                                                                                            for (int uuuu = 0; uuuu < cur_size; uuuu++) {
                                                                                                                                                                                                                                                                                                                                                                                for (int vvvv = 0; vvvv < cur_size; vvvv++) {
                                                                                                                                                                                                                                                                                                                                                                                    for (int wwww = 0; wwww < cur_size; wwww++) {
                                                                                                                                                                                                                                                                                                                                                                                        for (int xxxx = 0; xxxx < cur_size; xxxx++) {
                                                                                                                                                                                                                                                                                                                                                                                            for (int yyyy = 0; yyyy < cur_size; yyyy++) {
                                                                                                                                                                                                                                                                                                                                                                                                for (int zzzz = 0; zzzz < cur_size; zzzz++) {
                                                                                                                                                                                                                                                                                                                                                                                                    for (int aaaaa = 0; aaaaa < cur_size; aaaaa++) {
                                                                                                                                                                                                                                                                                                                                                                                                        for (int bbbbb = 0; bbbbb < cur_size; bbbbb++) {
                                                                                                                                                                                                                                                                                                                                                                                                            for (int ccccc = 0; ccccc < cur_size; ccccc++) {
                                                                                                                                                                                                                                                                                                                                                                                                                for (int ddddd = 0; ddddd < cur_size; ddddd++) {
                                                                                                                                                                                                                                                                                                                                                                                                                    for (int eeeee = 0; eeeee < cur_size; eeeee++) {
                                                                                                                                                                                                                                                                                                                                                                                                                        for (int fffff = 0; fffff < cur_size; fffff++) {
                                                                                                                                                                                                                                                                                                                                                                                                                            for (int ggggg = 0; ggggg < cur_size; ggggg++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                for (int hhhhh = 0; hhhhh < cur_size; hhhhh++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                    for (int iiiii = 0; iiiii < cur_size; iiiii++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                        for (int jjjjj = 0; jjjjj < cur_size; jjjjj++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                            for (int kkkkk = 0; kkkkk < cur_size; kkkkk++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                for (int lllll = 0; lllll < cur_size; lllll++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                    for (int mmmmm = 0; mmmmm < cur_size; mmmmm++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                        for (int nnnnn = 0; nnnnn < cur_size; nnnnn++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                            for (int ooooo = 0; ooooo < cur_size; ooooo++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                for (int ppppp = 0; ppppp < cur_size; ppppp++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                    for (int qqqqq = 0; qqqqq < cur_size; qqqqq++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                        for (int rrrrr = 0; rrrrr < cur_size; rrrrr++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            for (int sssss = 0; sssss < cur_size; sssss++) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                for (int ttttt = 0; ttttt < cur_size; ttttt++) {
