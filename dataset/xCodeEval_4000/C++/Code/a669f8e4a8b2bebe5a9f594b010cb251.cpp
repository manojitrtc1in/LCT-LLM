#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAXN = 1000010;
const int LOG_MAXN = 22;
const unsigned int EMPTY = ((unsigned int)1) << (sizeof(unsigned int) * 8 - 1);

#define chr(i) ((level == 0) ? ((unsigned char *)s)[i] : ((int *)s)[i])

string text;
int N, sa[MAXN], r[MAXN], cntt[MAXN], order[MAXN], lcp[MAXN], at[MAXN],
    rmqtable[LOG_MAXN][MAXN], logtable[MAXN + 1];

void getBuckets(unsigned char *s, unsigned int *bkt, unsigned int n,
                unsigned int K, bool end) {
  unsigned int i, sum = 0;

  

  for (i = 0; i < K; i++) bkt[i] = 0;

  

  for (i = 0; i < n; i++) bkt[s[i]]++;

  for (i = 0; i < K; i++) {
    sum += bkt[i];
    bkt[i] = end ? sum - 1 : sum - bkt[i];
  }
}

void putSuffix0(unsigned int *SA, unsigned char *s, unsigned int *bkt,
                unsigned int n, unsigned int K, int n1) {
  unsigned int i, j;

  

  getBuckets(s, bkt, n, K, true);

  

  for (i = n1 - 1; i > 0; i--) {
    j = SA[i];
    SA[i] = 0;
    SA[bkt[s[j]]--] = j;
  }
  SA[0] = n - 1;  

}

void induceSAl0(unsigned int *SA, unsigned char *s, unsigned int *bkt,
                unsigned int n, unsigned int K, bool suffix) {
  unsigned int i, j;

  

  getBuckets(s, bkt, n, K, false);

  bkt[0]++;  

  for (i = 0; i < n; i++)
    if (SA[i] > 0) {
      j = SA[i] - 1;
      if (s[j] >= s[j + 1]) {
        SA[bkt[s[j]]] = j;
        bkt[s[j]]++;
        if (!suffix && i > 0) SA[i] = 0;
      }
    }
}

void induceSAs0(unsigned int *SA, unsigned char *s, unsigned int *bkt,
                unsigned int n, unsigned int K, bool suffix) {
  unsigned int i, j;

  

  getBuckets(s, bkt, n, K, true);

  for (i = n - 1; i > 0; i--)
    if (SA[i] > 0) {
      j = SA[i] - 1;
      if (s[j] <= s[j + 1] && bkt[s[j]] < i) {
        SA[bkt[s[j]]] = j;
        bkt[s[j]]--;
        if (!suffix) SA[i] = 0;
      }
    }
}

void putSubstr0(unsigned int *SA, unsigned char *s, unsigned int *bkt,
                unsigned int n, unsigned int K) {
  unsigned int i, cur_t, succ_t;

  

  getBuckets(s, bkt, n, K, true);

  

  for (i = 0; i < n; i++) SA[i] = 0;

  succ_t = 0;  

  for (i = n - 2; i > 0; i--) {
    cur_t = (s[i - 1] < s[i] || (s[i - 1] == s[i] && succ_t == 1)) ? 1 : 0;
    if (cur_t == 0 && succ_t == 1) SA[bkt[s[i]]--] = i;
    succ_t = cur_t;
  }

  

  SA[0] = n - 1;
}

void putSuffix1(int *SA, int *s, int n1) {
  int i, j, pos, cur, pre = -1;

  for (i = n1 - 1; i > 0; i--) {
    j = SA[i];
    SA[i] = EMPTY;
    cur = s[j];
    if (cur != pre) {
      pre = cur;
      pos = cur;
    }
    SA[pos--] = j;
  }
}

void induceSAl1(int *SA, int *s, int n, bool suffix) {
  int h, i, j, step = 1;

  for (i = 0; i < n; i += step) {
    step = 1;
    j = SA[i] - 1;
    if (SA[i] <= 0) continue;
    int c = s[j], c1 = s[j + 1];
    bool isL = c >= c1;
    if (!isL) continue;

    


    int d = SA[c];
    if (d >= 0) {
      

      

      

      

      int foo, bar;
      foo = SA[c];
      for (h = c - 1; SA[h] >= 0 || SA[h] == EMPTY; h--) {
        bar = SA[h];
        SA[h] = foo;
        foo = bar;
      }
      SA[h] = foo;
      if (h < i) step = 0;

      d = EMPTY;
    }

    if (d == EMPTY) {  

      if (c < n - 1 && SA[c + 1] == EMPTY) {
        SA[c] = -1;  

        SA[c + 1] = j;
      } else
        SA[c] = j;  

    } else {        

      int pos = c - d + 1;
      if (pos > n - 1 || SA[pos] != EMPTY) {
        

        

        

        

        for (h = 0; h < -d; h++) SA[c + h] = SA[c + h + 1];
        pos--;
        if (c < i) step = 0;
      } else
        SA[c]--;

      SA[pos] = j;
    }

    int c2;
    bool isL1 =
        (j + 1 < n - 1) &&
        (c1 > (c2 = s[j + 2]) || (c1 == c2 && c1 < i));  

    if ((!suffix || !isL1) && i > 0) {
      int i1 = (step == 0) ? i - 1 : i;
      SA[i1] = EMPTY;
    }
  }

  

  

  for (i = 1; i < n; i++) {
    j = SA[i];
    if (j < 0 && j != EMPTY) {  

      for (h = 0; h < -j; h++) SA[i + h] = SA[i + h + 1];
      SA[i + h] = EMPTY;
    }
  }
}

void induceSAs1(int *SA, int *s, int n, bool suffix) {
  int h, i, j, step = 1;

  for (i = n - 1; i > 0; i -= step) {
    step = 1;
    j = SA[i] - 1;
    if (SA[i] <= 0) continue;
    int c = s[j], c1 = s[j + 1];
    bool isS = (c < c1) || (c == c1 && c > i);
    if (!isS) continue;

    


    int d = SA[c];
    if (d >= 0) {
      

      

      

      

      int foo, bar;
      foo = SA[c];
      for (h = c + 1; SA[h] >= 0 || SA[h] == EMPTY; h++) {
        bar = SA[h];
        SA[h] = foo;
        foo = bar;
      }
      SA[h] = foo;
      if (h > i) step = 0;

      d = EMPTY;
    }

    if (d == EMPTY) {  

      if (SA[c - 1] == EMPTY) {
        SA[c] = -1;  

        SA[c - 1] = j;
      } else
        SA[c] = j;  

    } else {        

      int pos = c + d - 1;
      if (SA[pos] != EMPTY) {
        

        

        

        

        for (h = 0; h < -d; h++) SA[c - h] = SA[c - h - 1];
        pos++;
        if (c > i) step = 0;
      } else
        SA[c]--;

      SA[pos] = j;
    }

    if (!suffix) {
      int i1 = (step == 0) ? i + 1 : i;
      SA[i1] = EMPTY;
    }
  }

  

  

  if (!suffix)
    for (i = n - 1; i > 0; i--) {
      j = SA[i];
      if (j < 0 && j != EMPTY) {  

        for (h = 0; h < -j; h++) SA[i - h] = SA[i - h - 1];
        SA[i - h] = EMPTY;
      }
    }
}

void putSubstr1(int *SA, int *s, int n) {
  int h, i, j;

  for (i = 0; i < n; i++) SA[i] = EMPTY;

  int c, c1, t, t1;
  c1 = s[n - 2];
  t1 = 0;

  for (i = n - 2; i > 0; i--) {
    c = c1;
    t = t1;
    c1 = s[i - 1];
    t1 = c1 < c || (c1 == c && t);
    if (t && !t1) {
      if (SA[c] >= 0) {
        

        

        

        

        int foo, bar;
        foo = SA[c];

        for (h = c + 1; SA[h] >= 0; h++) {
          bar = SA[h];
          SA[h] = foo;
          foo = bar;
        }
        SA[h] = foo;

        SA[c] = EMPTY;
      }

      int d = SA[c];
      if (d == EMPTY) {  

        if (SA[c - 1] == EMPTY) {
          SA[c] = -1;  

          SA[c - 1] = i;
        } else
          SA[c] = i;  

      } else {        

        int pos = c + d - 1;
        if (SA[pos] != EMPTY) {
          

          

          

          

          for (h = 0; h < -d; h++) SA[c - h] = SA[c - h - 1];
          pos++;
        } else
          SA[c]--;

        SA[pos] = i;
      }
    }
  }

  

  

  for (i = n - 1; i > 0; i--) {
    j = SA[i];
    if (j < 0 && j != EMPTY) {  

      for (h = 0; h < -j; h++) SA[i - h] = SA[i - h - 1];
      SA[i - h] = EMPTY;
    }
  }

  

  SA[0] = n - 1;
}

unsigned int getLengthOfLMS(unsigned char *s, unsigned int n, int level,
                            unsigned int x) {
  if (x == n - 1) return 1;

  unsigned int dist, i = 1;
  while (1) {
    if (chr(x + i) < chr(x + i - 1)) break;
    i++;
  }
  while (1) {
    if (x + i > n - 1 || chr(x + i) > chr(x + i - 1)) break;
    if (x + i == n - 1 || chr(x + i) < chr(x + i - 1)) dist = i;
    i++;
  }

  return dist + 1;
}

unsigned int nameSubstr(unsigned int *SA, unsigned char *s, unsigned int *s1,
                        unsigned int n, unsigned int m, unsigned int n1,
                        int level) {
  unsigned int i, j, cur_t, succ_t;

  

  for (i = n1; i < n; i++) SA[i] = EMPTY;

  

  unsigned int name, name_ctr = 0;
  unsigned int pre_pos, pre_len = 0;
  for (i = 0; i < n1; i++) {
    bool diff = false;
    unsigned int len, pos = SA[i];

    len = getLengthOfLMS(s, n, level, pos);
    if (len != pre_len)
      diff = true;
    else
      for (unsigned int d = 0; d < len; d++)
        if (pos + d == n - 1 || pre_pos + d == n - 1 ||
            chr(pos + d) != chr(pre_pos + d)) {
          diff = true;
          break;
        }

    if (diff) {
      name = i;
      name_ctr++;
      SA[name] = 1;  

      pre_pos = pos;
      pre_len = len;
    } else
      SA[name]++;  


    SA[n1 + pos / 2] = name;
  }

  

  

  for (i = n - 1, j = m - 1; i >= n1; i--)
    if (SA[i] != EMPTY) SA[j--] = SA[i];

  

  

  

  succ_t = 1;

  for (i = n1 - 1; i > 0; i--) {
    int ch = s1[i], ch1 = s1[i - 1];
    cur_t = (ch1 < ch || (ch1 == ch && succ_t == 1)) ? 1 : 0;
    if (cur_t == 1) {
      s1[i - 1] += SA[s1[i - 1]] - 1;
    }
    succ_t = cur_t;
  }

  return name_ctr;
}

void getSAlms(unsigned int *SA, unsigned char *s, unsigned int *s1,
              unsigned int n, unsigned int n1, int level) {
  unsigned int i, j, cur_t, succ_t;

  j = n1 - 1;
  s1[j--] = n - 1;
  succ_t = 0;  

  for (i = n - 2; i > 0; i--) {
    cur_t =
        (chr(i - 1) < chr(i) || (chr(i - 1) == chr(i) && succ_t == 1)) ? 1 : 0;
    if (cur_t == 0 && succ_t == 1) s1[j--] = i;
    succ_t = cur_t;
  }

  for (i = 0; i < n1; i++) {
    SA[i] = s1[SA[i]];
  }

  

  for (i = n1; i < n; i++) SA[i] = level ? EMPTY : 0;
}

void SACA_K(unsigned char *s, unsigned int *SA, unsigned int n, unsigned int K,
            unsigned int m, int level) {

  unsigned int i;
  unsigned int *bkt = NULL;

  


  if (level == 0) {
    bkt = (unsigned int *)malloc(sizeof(int) * K);
    putSubstr0(SA, s, bkt, n, K);
    induceSAl0(SA, s, bkt, n, K, false);
    induceSAs0(SA, s, bkt, n, K, false);

  } else {
    putSubstr1((int *)SA, (int *)s, (int)n);
    induceSAl1((int *)SA, (int *)s, n, false);
    induceSAs1((int *)SA, (int *)s, n, false);
  }

  

  


  

  

  

  unsigned int n1 = 0;
  for (i = 0; i < n; i++)
    if ((!level && SA[i] > 0) || (level && ((int *)SA)[i] > 0))
      SA[n1++] = SA[i];
  unsigned int *SA1 = SA, *s1 = SA + m - n1;
  unsigned int name_ctr;
  name_ctr = nameSubstr(SA, s, s1, n, m, n1, level);
  


  

  if (name_ctr < n1)
    SACA_K((unsigned char *)s1, SA1, n1, 0, m - n1, level + 1);
  else  

    for (i = 0; i < n1; i++) SA1[s1[i]] = i;

  


  getSAlms(SA, s, s1, n, n1, level);
  if (level == 0) {
    putSuffix0(SA, s, bkt, n, K, n1);
    induceSAl0(SA, s, bkt, n, K, true);
    induceSAs0(SA, s, bkt, n, K, true);
    free(bkt);
  } else {
    putSuffix1((int *)SA, (int *)s, n1);
    induceSAl1((int *)SA, (int *)s, n, true);
    induceSAs1((int *)SA, (int *)s, n, true);
  }
}

void build() {

  

  unsigned char *s = (unsigned char *)text.c_str();
  unsigned int *SA = (unsigned int *)sa;
  SACA_K(s, SA, N, 256, N, 0);

  for (int i = 0; i < N; ++i) at[sa[i]] = i;

  

  for (int i = 0, h = 0; i < N; i++) {
    if (at[i] < N - 1) {
      for (int j = sa[at[i] + 1];
           max(i, j) + h < N && text[i + h] == text[j + h]; ++h)
        ;
      lcp[at[i]] = h;
      if (h > 0) --h;
    }
  }

  for (int i = 2; i < N + 1; ++i) logtable[i] = logtable[i >> 1] + 1;
  for (int i = 0; i < N - 1; ++i) rmqtable[0][i] = i;
  for (int k = 1; (1 << k) < N - 1; ++k)
    for (int i = 0; i + (1 << k) < N; ++i) {
      int x = rmqtable[k - 1][i];
      int y = rmqtable[k - 1][i + (1 << (k - 1))];
      rmqtable[k][i] = lcp[x] <= lcp[y] ? x : y;
    }
}

int rmq(int suffix1, int suffix2) {
  if (suffix1 == suffix2) return N - suffix1;
  int l = min(at[suffix1], at[suffix2]);
  int r = max(at[suffix1], at[suffix2]);
  int k = logtable[r - 1 - l];
  int x = rmqtable[k][l];
  int y = rmqtable[k][r - (1 << k)];
  return min(lcp[x], lcp[y]);
}

int rmq2(int suffix1, int suffix2) {
  if (suffix1 == suffix2) return N - suffix1;
  int l = min(suffix1, suffix2);
  int r = max(suffix1, suffix2);
  int k = logtable[r - 1 - l];
  int x = rmqtable[k][l];
  int y = rmqtable[k][r - (1 << k)];
  return min(lcp[x], lcp[y]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> text;
  text += '0';
  N = text.length();
  build();

  int len = 0;
  for (int i = 1; i < N; ++i) {
    int len2 = rmq2(at[i], at[0]);
    if (len2 < N - 1 - i) continue;
    int len3 = 0;
    for (int j = at[i] - 2; j < at[i] + 3; ++j)
      if (j != at[0] && j != at[i] && j > 0 && j < N)
        len3 = max(len3, rmq2(at[i], j));
    len2 = min(len2, len3);
    if (len2 >= N - 1 - i) {
      len = N - 1 - i;
      break;
    }
  }

  cout << (len > 0 ? text.substr(0, len) : "Just a legend") << '\n';

  return 0;
}