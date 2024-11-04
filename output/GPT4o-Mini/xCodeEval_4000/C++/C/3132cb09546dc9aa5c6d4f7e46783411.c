#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} pi;

typedef struct {
    pi *data;
    size_t size;
    size_t capacity;
} vector_pi;

typedef struct {
    ll *data;
    size_t size;
    size_t capacity;
} vector_ll;

typedef struct {
    ll *parent;
    ll *size;
    ll n;
} SNM;

pi zero = { -1, -1 };

void cinArr(vector_ll *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        scanf("%lld", &arr->data[i]);
    }
}

void cinMatr(vector_ll *matr, size_t n, size_t m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            scanf("%lld", &matr->data[i * m + j]);
        }
    }
}

vector_pi create_vector_pi(size_t capacity) {
    vector_pi v;
    v.data = (pi *)malloc(capacity * sizeof(pi));
    v.size = 0;
    v.capacity = capacity;
    return v;
}

void push_back_vector_pi(vector_pi *v, pi value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (pi *)realloc(v->data, v->capacity * sizeof(pi));
    }
    v->data[v->size++] = value;
}

void free_vector_pi(vector_pi *v) {
    free(v->data);
}

void free_vector_ll(vector_ll *v) {
    free(v->data);
}

ll gcd(ll a, ll b) {
    if (a < b) {
        ll temp = a;
        a = b;
        b = temp;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll nok(ll a, ll b) {
    ll nnod = gcd(a, b);
    return a / nnod * b;
}

ll divup(ll a, ll b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

SNM create_snm(ll n) {
    SNM snm;
    snm.parent = (ll *)malloc(n * sizeof(ll));
    snm.size = (ll *)malloc(n * sizeof(ll));
    snm.n = n;
    for (ll i = 0; i < n; i++) {
        snm.parent[i] = i;
        snm.size[i] = 1;
    }
    return snm;
}

void free_snm(SNM *snm) {
    free(snm->parent);
    free(snm->size);
}

ll find_set(SNM *snm, ll v) {
    if (v == snm->parent[v])
        return v;
    ll ans = find_set(snm, snm->parent[v]);
    snm->parent[v] = ans;
    return ans;
}

void union_sets(SNM *snm, ll a, ll b) {
    a = find_set(snm, a);
    b = find_set(snm, b);
    if (a != b) {
        snm->parent[b] = a;
        snm->size[a] += snm->size[b];
    }
}

ll getSize(SNM *snm, ll v) {
    v = find_set(snm, v);
    return snm->size[v];
}

bool chec(ll day, vector_pi *pr, vector_ll *arr) {
    vector_pi bue = create_vector_pi(arr->size);
    ll sum = 0;
    for (size_t i = 0; i < arr->size; i++) {
        pi p;
        p.first = i;
        p.second = -day;
        bool found = false;
        for (size_t j = 0; j < pr->size; j++) {
            if (pr->data[j].first == i) {
                found = true;
                sum += arr->data[i];
                push_back_vector_pi(&bue, (pi){-pr->data[j].second, i});
                break;
            }
        }
        if (!found) {
            sum += arr->data[i];
        }
    }
    // Sort bue based on first element
    for (size_t i = 0; i < bue.size - 1; i++) {
        for (size_t j = 0; j < bue.size - i - 1; j++) {
            if (bue.data[j].first > bue.data[j + 1].first) {
                pi temp = bue.data[j];
                bue.data[j] = bue.data[j + 1];
                bue.data[j + 1] = temp;
            }
        }
    }

    ll moneyDelete = 0;
    for (size_t i = 0; i < bue.size; i++) {
        ll money = bue.data[i].first - moneyDelete;
        ll need = arr->data[bue.data[i].second];
        if (need <= money) {
            moneyDelete += need;
        } else {
            moneyDelete += money;
            sum += need - money;
        }
    }
    free_vector_pi(&bue);
    return (moneyDelete + sum * 2 <= day);
}

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    vector_ll arr;
    arr.data = (ll *)malloc(n * sizeof(ll));
    arr.size = n;
    arr.capacity = n;
    cinArr(&arr);
    
    vector_pi pr = create_vector_pi(m);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        push_back_vector_pi(&pr, (pi){b - 1, -a});
    }

    ll l = 0;
    ll r = 1e18;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (chec(mid, &pr, &arr)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", l);

    free(arr.data);
    free_vector_pi(&pr);
    return 0;
}
