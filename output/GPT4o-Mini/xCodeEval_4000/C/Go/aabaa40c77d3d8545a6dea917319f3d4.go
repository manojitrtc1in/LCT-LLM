package main

import (
	"fmt"
	"math"
)

const MAXP = 20000
const INTER = 100000

var sieve [MAXP]bool
var prime [6000]int
var primes int

