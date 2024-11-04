#include <stdio.h>
#include <stdlib.h>

#define STATIC_MOD 1000000007
#define DECIMAL_DIGITS 10

typedef long long LL;

typedef struct {
    unsigned value;
} id0;

void update(id0* id) {
    id->value = id->value ^ (id->value << 13);
    id->value = id->value ^ (id->value >> 17);
    id->value = id->value ^ (id->value << 5);
}

unsigned get(id0* id) {
    unsigned v = id->value;
    update(id);
    return v;
}

int next_int(id0* id) {
    return (int)(get(id) >> (32 - 31));
}

int next_signed(id0* id) {
    unsigned v = get(id);
    return (int)((v >> (31 - 31)) - (1 << (31)));
}

int range_max() {
    return (int)((1u << 31) - 1);
}

id0 create_id(unsigned seed) {
    id0 id;
    id.value = seed;
    update(&id);
    return id;
}

id0 create_id_default() {
    return create_id(getpid());
}

typedef struct {
    int x;
} ModInt;

int mod = STATIC_MOD;

long long mod_int_value(ModInt* m) {
    return m->x;
}

ModInt create_mod_int(int y) {
    ModInt m;
    m.x = y;
    return m;
}

ModInt create_mod_int_long(long long y) {
    ModInt m;
    m.x = (int)((mod + y % mod) % mod);
    return m;
}

ModInt add(ModInt l, ModInt r) {
    const long long x = mod_int_value(&l) + mod_int_value(&r);
    return create_mod_int((x >= mod) ? (x - mod) : x);
}

ModInt mul(ModInt l, ModInt r) {
    return create_mod_int_long(mod_int_value(&l) * mod_int_value(&r) % mod);
}

ModInt pow_mod(ModInt a, long long x) {
    ModInt ret = create_mod_int(1);
    while (x) {
        if (x & 1) {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        x >>= 1;
    }
    return ret;
}

ModInt inv(ModInt x) {
    long long a = mod_int_value(&x), b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        long long temp_a = a; a -= t * b; b = temp_a;
        long long temp_u = u; u -= t * v; v = temp_u;
    }
    return create_mod_int(u);
}

ModInt operator_minus(ModInt x) {
    return add(create_mod_int(mod), operator_minus(x));
}

ModInt operator_plus(ModInt l, ModInt r) {
    return add(l, r);
}

ModInt operator_minus_two(ModInt l, ModInt r) {
    return add(l, operator_minus(r));
}

ModInt operator_div(ModInt l, int r) {
    return mul(l, inv(create_mod_int(r)));
}

ModInt operator_div_long(ModInt l, long long r) {
    return mul(l, inv(create_mod_int_long(r)));
}

ModInt combination(int n, int k) {
    if (k < 0 || k > n) return create_mod_int(0);
    // Implement factorial and inverse_factorial logic here
    return create_mod_int(0); // Placeholder
}

int main() {
    int p, s, r;
    scanf("%d%d%d", &p, &s, &r);
    ModInt ret = create_mod_int(0);
    for (int top = r; top <= s; top++) {
        ModInt tot = create_mod_int(0);
        for (int q = 0; q < p; q++) {
            if (top * q > s - top) break;
            tot = add(tot, 
                mul(
                    combination(p - 1, q),
                    mul(
                        combination(p - q - 1, s - top - top * q), 
                        inv(create_mod_int(q + 1))
                    )
                )
            );
        }
        ret = add(ret, tot);
    }
    ret = mul(ret, inv(combination(p, s - r)));
    printf("%lld\n", mod_int_value(&ret));
    return 0;
}
