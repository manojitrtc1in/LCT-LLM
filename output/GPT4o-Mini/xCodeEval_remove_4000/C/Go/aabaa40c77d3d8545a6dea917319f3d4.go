package main

import (
	"fmt"
	"math"
)

const MAXP = 1000000
const INTER = 1000

var sieve [MAXP]bool
var prime [6000]int
var primes int

func createsieve() {
	for i := 0; i < MAXP; i++ {
		sieve[i] = true
	}
	sieve[0], sieve[1] = false, false
	q := int(math.Sqrt(MAXP))
	for i := 2; i < q; i++ {
		if sieve[i] {
			for j := i * i; j < MAXP; j += i {
				sieve[j] = false
			}
		}
	}
}

func id0() {
	for i := 0; i < MAXP; i++ {
		if sieve[i] {
			prime[primes] = i
			primes++
		}
	}
}

func isprime(n int) bool {
	if n < 2 {
		return false
	}
	if n == 2 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	for i := 0; prime[i]*prime[i] <= n; i++ {
		if n%prime[i] == 0 {
			return false
		}
	}
	return true
}

