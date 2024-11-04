#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000

typedef struct {
    int x;
    int y;
    int z;
} pa3;

typedef struct {
    int x;
    int y;
    int z;
    int w;
} pa4;

typedef struct {
    int x;
    int y;
} pa2;

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int gcd(int v, int b) {
    if (v == 0) return b;
    if (b == 0) return v;
    if (v > b) return gcd(b, v);
    if (v == b) return b;
    if (b % v == 0) return v;
    return gcd(v, b % v);
}

int extgcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int d = extgcd(b, a % b, y, x);
    *y -= a / b * (*x);
    return d;
}

pa2 operator+(const pa2 l, const pa2 r) {
    pa2 res;
    res.x = l.x + r.x;
    res.y = l.y + r.y;
    return res;
}

pa2 operator-(const pa2 l, const pa2 r) {
    pa2 res;
    res.x = l.x - r.x;
    res.y = l.y - r.y;
    return res;
}

typedef struct {
    int beki;
    int cor;
    int **vec;
    int *lo;
} Sparsetable_min;

void shoki1(Sparsetable_min *st) {
    int i, j;
    st->vec = (int **)malloc((st->beki + 1) * sizeof(int *));
    for (i = 0; i <= st->beki; i++) {
        st->vec[i] = (int *)malloc(st->cor * sizeof(int));
    }
    st->lo = (int *)malloc((st->cor + 1) * sizeof(int));
    st->lo[0] = -1;
    for (i = 1; i <= st->cor; i++) {
        st->lo[i] = st->lo[i >> 1] + 1;
    }
}

void shoki2(Sparsetable_min *st) {
    int i, j;
    for (i = 1; i <= st->beki; i++) {
        for (j = 0; j < st->cor; j++) {
            if ((j + (1 << (i - 1))) < st->cor) {
                st->vec[i][j] = min(st->vec[i - 1][j], st->vec[i - 1][j + (1 << (i - 1))]);
            } else {
                st->vec[i][j] = st->vec[i - 1][j];
            }
        }
    }
}

int rangemin(Sparsetable_min *st, int i, int j) {
    int haba = st->lo[j - i];
    return min(st->vec[haba][i], st->vec[haba][j - (1 << haba)]);
}

typedef struct {
    char *STR;
    int *S;
    int *SL;
    pa3 *haba;
    int *SA;
    int *rank;
    int *LCP;
    int mojisu;
    int len;
} SAIS;

void make_suffix_array_string(SAIS *ss, char *str) {
    int i, j, cnt = 1;
    ss->STR = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(ss->STR, str);
    ss->mojisu = 0;
    ss->S = (int *)malloc((strlen(str) + 1) * sizeof(int));
    ss->SL = (int *)malloc((strlen(str) + 1) * sizeof(int));
    ss->haba = (pa3 *)malloc((strlen(str) + 1) * sizeof(pa3));
    ss->SA = (int *)malloc((strlen(str) + 1) * sizeof(int));
    ss->rank = (int *)malloc((strlen(str) + 1) * sizeof(int));
    ss->LCP = (int *)malloc((strlen(str) + 1) * sizeof(int));
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '1') {
            ss->S[i] = cnt;
        } else {
            ss->S[i] = cnt;
            cnt++;
        }
    }
    ss->mojisu = cnt;
    ss->S[strlen(str)] = 0;
    ss->len = strlen(str);
    for (i = ss->len - 1; i >= 0; i--) {
        if (i == ss->len - 1) {
            ss->SL[i] = 1;
        } else {
            if (ss->S[i] < ss->S[i + 1]) {
                ss->SL[i] = 1;
            } else if (ss->S[i] > ss->S[i + 1]) {
                ss->SL[i] = 0;
            } else {
                ss->SL[i] = ss->SL[i + 1];
            }
        }
    }
    int LMS_num = 0;
    int *LMS = (int *)malloc((strlen(str) + 1) * sizeof(int));
    int *LMS_id = (int *)malloc((strlen(str) + 1) * sizeof(int));
    int rt = 0;
    for (i = 1; i < ss->len; i++) {
        if (ss->SL[i - 1] == 0 && ss->SL[i] == 1) {
            LMS[LMS_num] = i;
            LMS_id[i] = rt;
            LMS_num++;
            rt++;
        }
    }
    for (i = 0; i < LMS_num - 1; i++) {
        ss->SL[LMS[i]] = -(LMS[i + 1] - LMS[i] + 1);
    }
    ss->SL[ss->len - 1] = -1;
    int *pos = (int *)malloc((ss->mojisu + 1) * sizeof(int));
    for (i = 0; i < ss->mojisu; i++) {
        pos[i] = 0;
    }
    for (i = 0; i < ss->len; i++) {
        ss->SA[ss->haba[ss->S[i]].y - pos[ss->S[i]]] = i;
        pos[ss->S[i]]++;
    }
    induced_sort(ss->SA, ss->len, ss->mojisu);
    induced_sort(ss->SA, ss->len, ss->mojisu);
    pa2 *lms_sub_order = (pa2 *)malloc((LMS_num + 1) * sizeof(pa2));
    int mae_ind;
    for (i = 0; i < ss->len; i++) {
        if (ss->SL[ss->SA[i]] < 0) {
            if (i == 0) {
                lms_sub_order[i].x = ss->SA[i];
                lms_sub_order[i].y = 1;
            } else if (lms_sub_order[i - 1].y == 1) {
                lms_sub_order[i].x = ss->SA[i];
                lms_sub_order[i].y = 2;
            } else if (ss->SL[ss->SA[mae_ind]] != ss->SL[ss->SA[i]]) {
                lms_sub_order[i].x = ss->SA[i];
                lms_sub_order[i].y = lms_sub_order[i - 1].y + 1;
            } else {
                int lmslen = -ss->SL[ss->SA[mae_ind]];
                int bo = 1;
                for (j = 0; j < lmslen; j++) {
                    if (ss->S[ss->SA[mae_ind] + j] != ss->S[ss->SA[i] + j]) {
                        bo = 0;
                        break;
                    }
                }
                if (bo) {
                    lms_sub_order[i].x = ss->SA[i];
                    lms_sub_order[i].y = lms_sub_order[i - 1].y;
                } else {
                    lms_sub_order[i].x = ss->SA[i];
                    lms_sub_order[i].y = lms_sub_order[i - 1].y + 1;
                }
            }
            mae_ind = i;
        }
    }
    int *rec = (int *)malloc(LMS_num * sizeof(int));
    for (i = 0; i < LMS_num; i++) {
        rec[LMS_id[lms_sub_order[i].x]] = lms_sub_order[i].y;
    }
    SAIS ss_naibu;
    ss_naibu.S = rec;
    ss_naibu.len = LMS_num;
    make_suffix_array_saiki(&ss_naibu, lms_sub_order[LMS_num - 1].y);
    for (i = LMS_num; i > 0; i--) {
        ss->SA[ss->haba[ss->S[LMS[i]]].y - pos[ss->S[LMS[i]]]] = LMS[i];
        pos[ss->S[LMS[i]]]++;
    }
    induced_sort(ss->SA, ss->len, ss->mojisu);
    for (i = 0; i < ss->len; i++) {
        ss->rank[ss->SA[i]] = i;
    }
}

void make_suffix_array_saiki(SAIS *ss, int *ve, int max_valu) {
    int i, j;
    ss->S = ve;
    ss->mojisu = max_valu + 1;
    make_suffix_array_naibu(ss);
}

void make_suffix_array_naibu(SAIS *ss) {
    int i, j;
    int cnt = ss->mojisu;
    ss->len = ss->len;
    ss->haba = (pa3 *)malloc((ss->len + 1) * sizeof(pa3));
    ss->SA = (int *)malloc((ss->len + 1) * sizeof(int));
    ss->rank = (int *)malloc((ss->len + 1) * sizeof(int));
    ss->LCP = (int *)malloc((ss->len + 1) * sizeof(int));
    int *kosuu = (int *)malloc((cnt + 1) * sizeof(int));
    for (i = 0; i < cnt; i++) {
        kosuu[i] = 0;
    }
    for (i = 0; i < ss->len; i++) {
        kosuu[ss->S[i]]++;
    }
    ss->haba[0].x = 0;
    ss->haba[0].y = 0;
    for (i = 1; i < cnt; i++) {
        ss->haba[i].x = ss->haba[i - 1].y + 1;
        ss->haba[i].y = ss->haba[i - 1].y + kosuu[i];
    }
    ss->SL = (int *)malloc((ss->len + 1) * sizeof(int));
    for (i = ss->len - 1; i >= 0; i--) {
        if (i == ss->len - 1) {
            ss->SL[i] = 1;
        } else {
            if (ss->S[i] < ss->S[i + 1]) {
                ss->SL[i] = 1;
            } else if (ss->S[i] > ss->S[i + 1]) {
                ss->SL[i] = 0;
            } else {
                ss->SL[i] = ss->SL[i + 1];
            }
        }
    }
    int LMS_num = 0;
    int *LMS = (int *)malloc((ss->len + 1) * sizeof(int));
    int *LMS_id = (int *)malloc((ss->len + 1) * sizeof(int));
    int rt = 0;
    for (i = 1; i < ss->len; i++) {
        if (ss->SL[i - 1] == 0 && ss->SL[i] == 1) {
            LMS[LMS_num] = i;
            LMS_id[i] = rt;
            LMS_num++;
            rt++;
        }
    }
    for (i = 0; i < LMS_num - 1; i++) {
        ss->SL[LMS[i]] = -(LMS[i + 1] - LMS[i] + 1);
    }
    ss->SL[ss->len - 1] = -1;
    int *pos = (int *)malloc((ss->mojisu + 1) * sizeof(int));
    for (i = 0; i < ss->mojisu; i++) {
        pos[i] = 0;
    }
    for (i = 0; i < ss->len; i++) {
        ss->SA[ss->haba[ss->S[i]].y - pos[ss->S[i]]] = i;
        pos[ss->S[i]]++;
    }
    induced_sort(ss->SA, ss->len, ss->mojisu);
    induced_sort(ss->SA, ss->len, ss->mojisu);
    pa2 *lms_sub_order = (pa2 *)malloc((LMS_num + 1) * sizeof(pa2));
    int mae_ind;
    for (i = 0; i < ss->len; i++) {
        if (ss->SL[ss->SA[i]] < 0) {
            if (i == 0) {
                lms_sub_order[i].x = ss->SA[i];
                lms_sub_order[i].y = 1;
            } else if (lms_sub_order[i - 1].y == 1) {
                lms_sub_order[i].x = ss->SA[i];
                lms_sub_order[i].y = 2;
            } else if (ss->SL[ss->SA[mae_ind]] != ss->SL[ss->SA[i]]) {
                lms_sub_order[i].x = ss->SA[i];
                lms_sub_order[i].y = lms_sub_order[i - 1].y + 1;
            } else {
                int lmslen = -ss->SL[ss->SA[mae_ind]];
                int bo = 1;
                for (j = 0; j < lmslen; j++) {
                    if (ss->S[ss->SA[mae_ind] + j] != ss->S[ss->SA[i] + j]) {
                        bo = 0;
                        break;
                    }
                }
                if (bo) {
                    lms_sub_order[i].x = ss->SA[i];
                    lms_sub_order[i].y = lms_sub_order[i - 1].y;
                } else {
                    lms_sub_order[i].x = ss->SA[i];
                    lms_sub_order[i].y = lms_sub_order[i - 1].y + 1;
                }
            }
            mae_ind = i;
        }
    }
    int *rec = (int *)malloc(LMS_num * sizeof(int));
    for (i = 0; i < LMS_num; i++) {
        rec[LMS_id[lms_sub_order[i].x]] = lms_sub_order[i].y;
    }
    SAIS ss_naibu;
    ss_naibu.S = rec;
    ss_naibu.len = LMS_num;
    make_suffix_array_saiki(&ss_naibu, rec, lms_sub_order[LMS_num - 1].y);
    for (i = LMS_num; i > 0; i--) {
        ss->SA[ss->haba[ss->S[LMS[i]]].y - pos[ss->S[LMS[i]]]] = LMS[i];
        pos[ss->S[LMS[i]]]++;
    }
    induced_sort(ss->SA, ss->len, ss->mojisu);
    for (i = 0; i < ss->len; i++) {
        ss->rank[ss->SA[i]] = i;
    }
}

void induced_sort(int *ve, int len, int cnt) {
    int i, j;
    int *ue = (int *)malloc((cnt + 1) * sizeof(int));
    for (i = 0; i < cnt; i++) {
        ue[i] = 0;
    }
    for (i = 0; i < len; i++) {
        if (ve[i] == -1) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
        if (ve[i] == 0) continue;
