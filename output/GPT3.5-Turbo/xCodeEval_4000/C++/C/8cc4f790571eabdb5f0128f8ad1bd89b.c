#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int v;
    int p;
} Pipe;

typedef enum {
    LL,
    RR,
    RL
} Direction;

typedef struct {
    int i;
    Direction d;
    long long t;
} Event;

typedef struct {
    long long n;
    long long d;
} Fraction;

typedef struct {
    int x;
    int v;
    int p;
} Pipe;

typedef struct {
    int i;
    Direction d;
    Fraction t;
} Event;

typedef struct {
    long long p[4];
    int noLL;
    int noRR;
    int noRL;
    int none;
} Node;

typedef struct {
    int x;
    int v;
    int p;
} Pipe;

typedef struct {
    int i;
    Direction d;
    Fraction t;
} Event;

typedef struct {
    long long p[4];
    int noLL;
    int noRR;
    int noRL;
    int none;
} Node;

typedef struct {
    int SZ;
    Node id;
    Node (*tt)(Node, Node);
    Node* table;
} SegmentTree;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

Fraction createFraction(long long n, long long d) {
    Fraction fraction;
    fraction.n = n;
    fraction.d = d;
    long long g = gcd(abs(fraction.n), fraction.d);
    fraction.n /= g;
    fraction.d /= g;
    return fraction;
}

Node createNode() {
    Node node;
    for (int i = 0; i < 4; i++) {
        node.p[i] = 0;
    }
    node.noLL = 0;
    node.noRR = 0;
    node.noRL = 0;
    node.none = 1;
    return node;
}

Node tt(Node a, Node b) {
    if (a.none) {
        return b;
    }
    if (b.none) {
        return a;
    }
    Node r = b;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int iF = i & 1;
            int iB = (i >> 1) & 1;
            int jF = j & 1;
            int jB = (j >> 1) & 1;
            if (a.noLL && !iB && !jF) {
                continue;
            }
            if (a.noRR && iB && jF) {
                continue;
            }
            if (a.noRL && iB && !jF) {
                continue;
            }
            r.p[iF + 2 * jB] += a.p[i] * b.p[j];
        }
    }
    return r;
}

SegmentTree createSegmentTree(int SZ, Node id, Node (*tt)(Node, Node)) {
    SegmentTree st;
    st.SZ = SZ;
    st.id = id;
    st.tt = tt;
    st.table = (Node*)malloc((2 * SZ) * sizeof(Node));
    for (int i = 0; i < 2 * SZ; i++) {
        st.table[i] = id;
    }
    return st;
}

void setLeaves(SegmentTree* st, Node (*create)(int)) {
    for (int i = 0; i < st->SZ; i++) {
        st->table[st->SZ + i] = create(i);
    }
    for (int i = st->SZ - 1; i > 0; i--) {
        st->table[i] = st->tt(st->table[2 * i], st->table[2 * i + 1]);
    }
}

void replace(SegmentTree* st, int i, Node v) {
    st->table[i + st->SZ] = v;
    for (i /= 2; i > 0; i /= 2) {
        st->table[i] = st->tt(st->table[2 * i], st->table[2 * i + 1]);
    }
}

Node query(SegmentTree* st, int i, int j) {
    Node left = st->id;
    Node right = st->id;
    for (i += st->SZ, j += st->SZ; i < j; i /= 2, j /= 2) {
        if (i & 1) {
            left = st->tt(left, st->table[i++]);
        }
        if (j & 1) {
            right = st->tt(st->table[--j], right);
        }
    }
    return st->tt(left, right);
}

void freeSegmentTree(SegmentTree* st) {
    free(st->table);
}

Fraction bestIn(Fraction x, Fraction y) {
    if (x.n < y.n) {
        return x;
    }
    if (x.n > y.n) {
        return y;
    }
    return x;
}

int main() {
    int N;
    scanf("%d", &N);
    Pipe* pipes = (Pipe*)malloc(N * sizeof(Pipe));
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &pipes[i].x, &pipes[i].v, &pipes[i].p);
    }

    Event* evs = (Event*)malloc((N - 1) * sizeof(Event));
    int evsSize = 0;

    for (int i = 0; i < N - 1; i++) {
        int dx = pipes[i + 1].x - pipes[i].x;
        int dv = pipes[i + 1].v - pipes[i].v;

        evs[evsSize].i = i;
        evs[evsSize].d = RL;
        evs[evsSize].t = createFraction(dx, pipes[i + 1].v + pipes[i].v);
        evsSize++;

        if (dv > 0) {
            evs[evsSize].i = i;
            evs[evsSize].d = LL;
            evs[evsSize].t = createFraction(dx, dv);
            evsSize++;
        }
        if (dv < 0) {
            evs[evsSize].i = i;
            evs[evsSize].d = RR;
            evs[evsSize].t = createFraction(dx, -dv);
            evsSize++;
        }
    }

    for (int i = 0; i < evsSize; i++) {
        for (int j = i + 1; j < evsSize; j++) {
            if (evs[i].t.n * evs[j].t.d > evs[j].t.n * evs[i].t.d) {
                Event temp = evs[i];
                evs[i] = evs[j];
                evs[j] = temp;
            }
        }
    }

    Node id = createNode();
    SegmentTree st = createSegmentTree(N, id, tt);
    setLeaves(&st, createNode);

    long long ans = 0;
    long long prob = 1;

    for (int i = 0; i < evsSize; i++) {
        Event e = evs[i];
        Node c = st.table[e.i];
        switch (e.d) {
            case LL:
                c.noLL = 1;
                break;
            case RR:
                c.noRR = 1;
                break;
            case RL:
                c.noRL = 1;
                break;
        }
        replace(&st, e.i, c);

        Node u = query(&st, 0, st.SZ);
        long long PROB = 0;
        for (int i = 0; i < 4; i++) {
            PROB += u.p[i];
        }
        ans += (prob - PROB) * e.t.n / e.t.d;
        prob = PROB;
    }

    printf("%lld\n", ans);

    free(pipes);
    free(evs);
    freeSegmentTree(&st);

    return 0;
}
