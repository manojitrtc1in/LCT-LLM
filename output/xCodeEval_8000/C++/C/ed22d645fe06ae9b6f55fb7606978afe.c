#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUF_SIZE 109

typedef struct {
    int val;
} bignum;

bignum add(bignum a, bignum b) {
    bignum res;
    res.val = a.val + b.val;
    return res;
}

bignum subtract(bignum a, bignum b) {
    bignum res;
    res.val = a.val - b.val;
    return res;
}

bignum multiply(bignum a, bignum b) {
    bignum res;
