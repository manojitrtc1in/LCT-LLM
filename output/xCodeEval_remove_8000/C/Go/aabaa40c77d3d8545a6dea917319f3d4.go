package main

import (
	"fmt"
	"math"
)

const MAXP = 1000000
const INTER = 10000

var sieve [MAXP]bool
var prime [6000]int
var primes int

func createsieve() {
	var q int
	q = int(math.Sqrt(float64(MAXP)))
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

