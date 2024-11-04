#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll mod = 998244353;

ll normS(ll x){
    return (x < mod) ? x : x - mod;
}

typedef struct {
    ll v;
} ModInt;

ModInt make(ll x){
    ModInt m;
    m.v = x;
    return m;
}

ModInt operator+(ModInt a, ModInt b){
    return make(normS(a.v + b.v));
}

ModInt operator-(ModInt a, ModInt b){
    return make(normS(a.v + mod - b.v));
}

ModInt operator-(ModInt a){
    return make(normS(mod - a.v));
}

ModInt operator*(ModInt a, ModInt b){
    return make((a.v * b.v) % mod);
}

ModInt operator/(ModInt a, ModInt b){
    return a * b.inv();
}

ModInt operator+=(ModInt& a, ModInt b){
    return a = a + b;
}

ModInt operator-=(ModInt& a, ModInt b){
    return a = a - b;
}

ModInt operator*=(ModInt& a, ModInt b){
    return a = a * b;
}

ModInt operator/=(ModInt& a, ModInt b){
    return a = a / b;
}

ModInt operator++(ModInt& a, int){
    return a = a + make(1);
}

ModInt operator--(ModInt& a, int){
    return a = a - make(1);
}

ll extgcd(ll a, ll b, ll* x, ll* y){
    ll p[] = {a, 1, 0};
    ll q[] = {b, 0, 1};
    while(*q){
        ll t = *p / *q;
        for(int i = 0; i < 3; i++){
            ll temp = p[i];
            p[i] = temp - t * q[i];
            q[i] = temp;
        }
    }
    if(p[0] < 0){
        for(int i = 0; i < 3; i++){
            p[i] = -p[i];
        }
    }
    *x = p[1];
    *y = p[2];
    return p[0];
}

ModInt inv(ModInt a){
    ll x, y;
    extgcd(a.v, mod, &x, &y);
    return make(normS(x + mod));
}

ModInt pow(ModInt a, ll p){
    if(p < 0){
        return inv(a).pow(-p);
    }
    ModInt res = make(1);
    ModInt x = a;
    while(p){
        if(p & 1){
            res *= x;
        }
        x *= x;
        p >>= 1;
    }
    return res;
}

typedef ModInt mint;

int bsr(int x){
    return 31 - __builtin_clz(x);
}

typedef double D;
const D pi = acos(-1);

typedef struct {
    D real;
    D imag;
} Pc;

Pc polar(D r, D theta){
    Pc p;
    p.real = r * cos(theta);
    p.imag = r * sin(theta);
    return p;
}

void fft(int type, Pc* c, int N){
    static Pc buf[30];
    int s = bsr(N);
    if(buf[s].real == 0 && buf[s].imag == 0){
        for(int i = 0; i < N; i++){
            buf[s] = polar(1, i * 2 * pi / N);
        }
    }
    Pc a[N], b[N];
    for(int i = 0; i < N; i++){
        a[i] = c[i];
    }
    for(int i = 1; i <= s; i++){
        int W = 1 << (s - i);
        for(int y = 0; y < N / 2; y += W){
            Pc now = buf[s * y];
            if(type){
                now.imag = -now.imag;
            }
            for(int x = 0; x < W; x++){
                Pc l = a[y << 1 | x];
                Pc r = {now.real * a[y << 1 | x | W].real - now.imag * a[y << 1 | x | W].imag, now.real * a[y << 1 | x | W].imag + now.imag * a[y << 1 | x | W].real};
                b[y | x] = l;
                b[y | x | N >> 1] = r;
            }
        }
        Pc* temp = a;
        a = b;
        b = temp;
    }
    for(int i = 0; i < N; i++){
        c[i] = a[i];
    }
}

typedef struct {
    int size;
    mint* v;
} Poly;

Poly createPoly(int N){
    Poly p;
    p.size = N;
    p.v = (mint*)malloc(N * sizeof(mint));
    return p;
}

Poly shrink(Poly p){
    int newSize = p.size;
    while(newSize > 0 && p.v[newSize - 1].v == 0){
        newSize--;
    }
    if(newSize != p.size){
        mint* newV = (mint*)realloc(p.v, newSize * sizeof(mint));
        if(newV != NULL){
            p.v = newV;
            p.size = newSize;
        }
    }
    return p;
}

mint at(Poly p, int i){
    if(i < p.size){
        return p.v[i];
    }
    else{
        return make(0);
    }
}

void set(Poly* p, int i, mint x){
    if(i >= p->size && x.v == 0){
        return;
    }
    while(i >= p->size){
        p->size++;
        p->v = (mint*)realloc(p->v, p->size * sizeof(mint));
        p->v[p->size - 1] = make(0);
    }
    p->v[i] = x;
    *p = shrink(*p);
}

Poly add(Poly a, Poly b){
    int N = (a.size > b.size) ? a.size : b.size;
    Poly res = createPoly(N);
    for(int i = 0; i < N; i++){
        res.v[i] = at(a, i) + at(b, i);
    }
    return res;
}

Poly subtract(Poly a, Poly b){
    int N = (a.size > b.size) ? a.size : b.size;
    Poly res = createPoly(N);
    for(int i = 0; i < N; i++){
        res.v[i] = at(a, i) - at(b, i);
    }
    return res;
}

Poly negate(Poly p){
    int N = p.size;
    Poly res = createPoly(N);
    for(int i = 0; i < N; i++){
        res.v[i] = -at(p, i);
    }
    return res;
}

Poly multiply(Poly a, Poly b){
    int N = a.size + b.size - 1;
    int s = bsr(N);
    int size = 1 << (s + 1);
    Pc c[size];
    for(int i = 0; i < a.size; i++){
        c[i].real = a.v[i].v;
        c[i].imag = 0;
    }
    for(int i = a.size; i < size; i++){
        c[i].real = 0;
        c[i].imag = 0;
    }
    fft(0, c, size);
    for(int i = 0; i < b.size; i++){
        c[i].real *= b.v[i].v;
        c[i].imag *= b.v[i].v;
    }
    fft(1, c, size);
    Poly res = createPoly(N);
    for(int i = 0; i < N; i++){
        res.v[i] = make((ll)(c[i].real / size + 0.5));
    }
    return res;
}

Poly multiplyScalar(Poly p, mint r){
    int N = p.size;
    Poly res = createPoly(N);
    for(int i = 0; i < N; i++){
        res.v[i] = p.v[i] * r;
    }
    return res;
}

Poly divide(Poly a, Poly b){
    int N = a.size;
    return multiplyScalar(a, inv(b.v[b.size - 1]));
}

Poly modulo(Poly a, Poly b){
    return subtract(a, multiply(divide(a, b), b));
}

Poly shiftLeft(Poly p, int n){
    int N = p.size;
    Poly res = createPoly(N + n);
    for(int i = 0; i < N; i++){
        res.v[i + n] = p.v[i];
    }
    return res;
}

Poly shiftRight(Poly p, int n){
    int N = p.size;
    if(N <= n){
        return createPoly(0);
    }
    Poly res = createPoly(N - n);
    for(int i = 0; i < N - n; i++){
        res.v[i] = p.v[i + n];
    }
    return res;
}

int isEqual(Poly a, Poly b){
    if(a.size != b.size){
        return 0;
    }
    for(int i = 0; i < a.size; i++){
        if(a.v[i].v != b.v[i].v){
            return 0;
        }
    }
    return 1;
}

int isNotEqual(Poly a, Poly b){
    return !isEqual(a, b);
}

Poly multiplyNaive(Poly a, Poly b){
    int N = a.size + b.size - 1;
    Poly res = createPoly(N);
    for(int i = 0; i < a.size; i++){
        for(int j = 0; j < b.size; j++){
            res.v[i + j] += at(a, i) * at(b, j);
        }
    }
    return res;
}

Poly multiplyFFT(Poly a, Poly b){
    int N = a.size + b.size - 1;
    int s = bsr(N);
    int size = 1 << (s + 1);
    Pc c[size];
    for(int i = 0; i < a.size; i++){
        c[i].real = a.v[i].v;
        c[i].imag = 0;
    }
    for(int i = a.size; i < size; i++){
        c[i].real = 0;
        c[i].imag = 0;
    }
    fft(0, c, size);
    for(int i = 0; i < b.size; i++){
        c[i].real *= b.v[i].v;
        c[i].imag *= b.v[i].v;
    }
    fft(1, c, size);
    Poly res = createPoly(N);
    for(int i = 0; i < N; i++){
        res.v[i] = make((ll)(c[i].real / size + 0.5));
    }
    return res;
}

Poly divideFastWithInverse(Poly p, Poly inv, int B){
    return shiftRight(multiply(p, inv), B - 1);
}

Poly divideFast(Poly a, Poly b){
    if(a.size < b.size){
        return createPoly(0);
    }
    int n = a.size;
    return divideFastWithInverse(a, inv(b.v[b.size - 1]), n);
}

Poly moduloNaive(Poly a, Poly b){
    Poly x = a;
    while(x.size >= b.size){
        int N = x.size;
        int M = b.size;
        mint coef = at(x, N - 1) / at(b, M - 1);
        x = subtract(x, shiftLeft(multiply(b, coef), N - M));
    }
    return x;
}

Poly moduloFast(Poly a, Poly b){
    return subtract(a, multiply(divideFast(a, b), b));
}

Poly strip(Poly p, int n){
    int newSize = (n < p.size) ? n : p.size;
    Poly res = createPoly(newSize);
    for(int i = 0; i < newSize; i++){
        res.v[i] = p.v[i];
    }
    return res;
}

Poly reverse(Poly p, int n){
    int newSize = (n != -1) ? n : p.size;
    Poly res = createPoly(newSize);
    for(int i = 0; i < newSize; i++){
        res.v[i] = p.v[newSize - 1 - i];
    }
    return res;
}

Poly inverse(Poly p, int n){
    int N = p.size;
    if(N < 1){
        return createPoly(0);
    }
    if(n < N - 1){
        return createPoly(0);
    }
    mint coef = inv(at(p, N - 1));
    Poly a = reverse(p, -1);
    Poly g = createPoly(1);
    g.v[0] = coef;
    for(int i = 1; i + N - 2 <= n; i *= 2){
        g = multiply(g, subtract(createPoly(2), multiply(a, g)).v[0]);
    }
    return reverse(g, n + 1 - (N - 1));
}

typedef struct {
    int size;
    mint* v;
} Vector;

Vector createVector(int N){
    Vector vc;
    vc.size = N;
    vc.v = (mint*)malloc(N * sizeof(mint));
    return vc;
}

Vector multiplyNTT(Vector x, Vector y){
    int N = x.size + y.size - 1;
    int s = bsr(N);
    int size = 1 << (s + 1);
    Pc c[size];
    for(int i = 0; i < x.size; i++){
        c[i].real = x.v[i].v;
        c[i].imag = 0;
    }
    for(int i = x.size; i < size; i++){
        c[i].real = 0;
        c[i].imag = 0;
    }
    fft(0, c, size);
    for(int i = 0; i < y.size; i++){
        c[i].real *= y.v[i].v;
        c[i].imag *= y.v[i].v;
    }
    fft(1, c, size);
    Vector res = createVector(N);
    for(int i = 0; i < N; i++){
        res.v[i] = make((ll)(c[i].real / size + 0.5));
    }
    return res;
}

Vector id4(Vector x, Vector y){
    int B = 15;
    int S = x.size + y.size - 1;
    int N = 2 << bsr(S - 1);
    Vector a = createVector(N);
    Vector b = createVector(N);
    for(int t = 0; t < 2; t++){
        for(int i = 0; i < x.size; i++){
            a.v[i] = make((x.v[i].v >> (t * B)) & ((1 << B) - 1));
        }
        for(int i = 0; i < y.size; i++){
            b.v[i] = make((y.v[i].v >> (t * B)) & ((1 << B) - 1));
        }
        Vector z = multiplyNTT(a, b);
        for(int i = 0; i < S; i++){
            x.v[i] += z.v[i] << (t * B);
        }
    }
    return x;
}

Vector id3(Vector terms, int deg, int ord, int verify){
    if(ord != -1){
        int n = (deg + 1) * (ord + 1) + ord - 1;
        while(terms.size > n){
            terms.size--;
        }
    }
    int n = terms.size;
    int B = (n + 2) / (deg + 2);
    int C = B * (deg + 1);
    int R = n - (B - 1);
    Vector mat[R];
    for(int y = 0; y < R; y++){
        mat[y] = createVector(C);
        for(int b = 0; b < B; b++){
            mat[y].v[b * (deg + 1)] = terms.v[y + b];
            mint v = terms.v[y + b];
            for(int d = 1; d <= deg; d++){
                v *= y + b;
                mat[y].v[b * (deg + 1) + d] = v;
            }
        }
    }
    int rank = 0;
    for(int x = 0; x < C; x++){
        int pivot = -1;
        for(int y = rank; y < R; y++){
            if(mat[y].v[x].v != 0){
                pivot = y;
                break;
            }
        }
        if(pivot < 0){
            break;
        }
        if(pivot != rank){
            Vector temp = mat[rank];
            mat[rank] = mat[pivot];
            mat[pivot] = temp;
        }
        mint inv = mat[rank].v[x].inv();
        for(int x2 = x; x2 < C; x2++){
            mat[rank].v[x2] *= inv;
        }
        for(int y = rank + 1; y < R; y++){
            if(mat[y].v[x].v != 0){
                mint c = -mat[y].v[x];
                for(int x2 = x; x2 < C; x2++){
                    mat[y].v[x2] += c * mat[rank].v[x2];
                }
            }
        }
        rank++;
    }
    if(rank == C){
        printf("Error: Could not find a recurrence relation of order <= %d and degree <= %d.\n\n", B - 1, deg);
        exit(0);
    }
    for(int y = rank - 1; y >= 0; y--){
        if(mat[y].v[rank].v != 0){
            mat[y].v[y] = 1;
            mint c = -mat[y].v[rank];
            for(int y2 = 0; y2 < y; y2++){
                mat[y2].v[rank] += c * mat[y2].v[y];
            }
        }
    }
    int order = rank / (deg + 1);
    Vector ret[order + 1];
    for(int k = 0; k <= order; k++){
        ret[k] = createVector(deg + 1);
        for(int d = 0; d <= deg; d++){
            ret[k].v[d] = mat[k].v[d];
        }
    }
    if(verify){
        Vector extended_terms = createVector(n - 1);
        for(int i = 0; i < terms.size; i++){
            extended_terms.v[i] = terms.v[i];
        }
        for(int i = terms.size; i < n; i++){
            extended_terms.v[i] = 0;
        }
        for(int i = 0; i < n; i++){
            for(int k = 1; k <= order; k++){
                int d = i % (deg + 1);
                int y = i / (deg + 1);
                mint t = ret[k].v[d];
                mint v = extended_terms.v[i];
                for(int j = 0; j < d; j++){
                    t *= y;
                }
                extended_terms.v[i] += t * v;
            }
        }
        for(int i = 0; i < terms.size; i++){
            if(terms.v[i].v != extended_terms.v[i].v){
                printf("Error: Could not find a recurrence relation of order <= %d and degree <= %d.\n\n", B - 1, deg);
                exit(0);
            }
        }
    }
    printf("[ Found a recurrence relation ]\n");
    printf("- order %d\n", order);
    printf("- degree %d\n", deg);
    if(verify){
        int last = n - 1;
        printf("- verified up to a(%d) (number of non-trivial terms: %d)\n", last, (last + 1) - ((deg + 2) * (order + 1) - 2));
    }
    printf("{\n");
    for(int k = 0; k <= order; k++){
        printf("  {");
        for(int d = 0; d <= deg; d++){
            if(d){
                printf(", ");
            }
            printf("%d", ret[k].v[d].v);
        }
        printf("}%s\n", (k == order) ? "" : ",");
    }
    printf("}\n\n");
    return ret;
}

void id1(int n, Vector terms, int degree, int order){
    Vector coeffs[order + 1];
    for(int k = 0; k <= order; k++){
        coeffs[k] = createVector(degree + 1);
        for(int d = 0; d <= degree; d++){
            coeffs[k].v[d] = 0;
        }
    }
    coeffs[0].v[degree] = 1;
    for(int m = terms.size; m <= n; m++){
        mint s = 0;
        for(int i = 1; i <= order; i++){
            int k = m - i;
            mint t = terms.v[k];
            for(int d = 0; d <= degree; d++){
                s += t * coeffs[i].v[d];
                t *= k;
            }
        }
        mint denom = 0;
        mint mpow = 1;
        for(int d = 0; d <= degree; d++){
            denom += mpow * coeffs[0].v[d];
            mpow *= m;
        }
        terms.v[m] = -s / denom;
    }
    for(int i = 0; i < terms.size; i++){
        printf("%d %d\n", i, terms.v[i].v);
    }
    printf("\n");
}

Vector id2(int n, Vector terms, int degree, int order){
    Vector coeffs[order + 1];
    for(int k = 0; k <= order; k++){
        coeffs[k] = createVector(degree + 1);
        for(int d = 0; d <= degree; d++){
            coeffs[k].v[d] = 0;
        }
    }
    coeffs[0].v[degree] = 1;
    for(int m = terms.size; m <= n; m++){
        mint s = 0;
        for(int i = 1; i <= order; i++){
            int k = m - i;
            mint t = terms.v[k];
            for(int d = 0; d <= degree; d++){
                s += t * coeffs[i].v[d];
                t *= k;
            }
        }
        mint denom = 0;
        mint mpow = 1;
        for(int d = 0; d <= degree; d++){
            denom += mpow * coeffs[0].v[d];
            mpow *= m;
        }
        terms.v[m] = -s / denom;
    }
    return terms;
}

int main(){
    int N;
    scanf("%d", &N);
    Vector terms = createVector(N + 1);
    for(int i = 0; i <= N; i++){
        terms.v[i] = 0;
    }
    Vector res = id2(N, terms, 1, -1);
    for(int i = 0; i < res.size; i++){
        printf("%d %d\n", i, res.v[i].v);
    }
    printf("\n");
    return 0;
}
