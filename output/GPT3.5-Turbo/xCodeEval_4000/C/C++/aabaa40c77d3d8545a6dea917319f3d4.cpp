#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXP 20000
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

char sieve[MAXP];
int prime[6000];
int primes;

void createsieve() {
  int i, j, q;
  memset(sieve, 1, sizeof(sieve));
  q = sqrt(MAXP);
  for (sieve[0] = sieve[1] = 0, i = 2; i < q; i++)
    if (sieve[i])
      for (j = i * i; j < MAXP; j += i)
        sieve[j] = 0;
}

void genprimes() {
  int i;
  for (primes = i = 0; i < MAXP; i++)
    if (sieve[i])
      prime[primes++] = i;
}

int isprime(int n) {
  int i;
  if (n < 2)
    return 0;
  if (n == 2)
    return 1;
  if (!(n & 1))
    return 0;
  for (i = 0; prime[i] * prime[i] <= n; i++)
    if (n % prime[i] == 0)
      return 0;
  return 1;
}

#define INTER 100000
