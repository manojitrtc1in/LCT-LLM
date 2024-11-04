#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct {
    int first;
    int second;
} ii;

typedef struct {
    ii first;
    int second;
} iii;

typedef struct {
    ll first;
    ll second;
} llll;

typedef struct {
    int value;
    struct ordered_set *left;
    struct ordered_set *right;
    int height;
    int size;
} ordered_set;

ordered_set* create_ordered_set(int value) {
    ordered_set* set = (ordered_set*)malloc(sizeof(ordered_set));
    set->value = value;
    set->left = NULL;
    set->right = NULL;
    set->height = 1;
    set->size = 1;
    return set;
}

int get_height(ordered_set* set) {
    if (set == NULL) {
        return 0;
    }
    return set->height;
}

int get_size(ordered_set* set) {
    if (set == NULL) {
        return 0;
    }
    return set->size;
}

int get_balance(ordered_set* set) {
    if (set == NULL) {
        return 0;
    }
    return get_height(set->left) - get_height(set->right);
}

ordered_set* right_rotate(ordered_set* y) {
    ordered_set* x = y->left;
    ordered_set* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (get_height(y->left) > get_height(y->right) ? get_height(y->left) : get_height(y->right));
    y->size = 1 + get_size(y->left) + get_size(y->right);

    x->height = 1 + (get_height(x->left) > get_height(x->right) ? get_height(x->left) : get_height(x->right));
    x->size = 1 + get_size(x->left) + get_size(x->right);

    return x;
}

ordered_set* left_rotate(ordered_set* x) {
    ordered_set* y = x->right;
    ordered_set* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (get_height(x->left) > get_height(x->right) ? get_height(x->left) : get_height(x->right));
    x->size = 1 + get_size(x->left) + get_size(x->right);

    y->height = 1 + (get_height(y->left) > get_height(y->right) ? get_height(y->left) : get_height(y->right));
    y->size = 1 + get_size(y->left) + get_size(y->right);

    return y;
}

ordered_set* insert(ordered_set* set, int value) {
    if (set == NULL) {
        return create_ordered_set(value);
    }

    if (value < set->value) {
        set->left = insert(set->left, value);
    }
    else if (value > set->value) {
        set->right = insert(set->right, value);
    }
    else {
        return set;
    }

    set->height = 1 + (get_height(set->left) > get_height(set->right) ? get_height(set->left) : get_height(set->right));
    set->size = 1 + get_size(set->left) + get_size(set->right);

    int balance = get_balance(set);

    if (balance > 1 && value < set->left->value) {
        return right_rotate(set);
    }

    if (balance < -1 && value > set->right->value) {
        return left_rotate(set);
    }

    if (balance > 1 && value > set->left->value) {
        set->left = left_rotate(set->left);
        return right_rotate(set);
    }

    if (balance < -1 && value < set->right->value) {
        set->right = right_rotate(set->right);
        return left_rotate(set);
    }

    return set;
}

int find_kth_smallest(ordered_set* set, int k) {
    if (set == NULL || k <= 0 || k > get_size(set)) {
        return -1;
    }

    int left_size = get_size(set->left);

    if (k == left_size + 1) {
        return set->value;
    }
    else if (k <= left_size) {
        return find_kth_smallest(set->left, k);
    }
    else {
        return find_kth_smallest(set->right, k - left_size - 1);
    }
}

void print_ordered_set(ordered_set* set) {
    if (set != NULL) {
        print_ordered_set(set->left);
        printf("%d ", set->value);
        print_ordered_set(set->right);
    }
}

void yes() {
    printf("Yes\n");
}

void no() {
    printf("No\n");
}

int main() {
    ll a;
    scanf("%lld", &a);
    ll n = 1e17;
    n *= 18;
    n %= a;
    ll k = n;

    int i;
    for (i = 0; i < 44; i++) {
        n = (n + k) % a;
    }

    if (n < 0) {
        n += a;
    }
    ll c = a - n;
    ll d = c + 1e18 - 1LL;
    printf("%lld %lld", c, d);
    return 0;
}
