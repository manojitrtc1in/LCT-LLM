package main

import (
	"fmt"
	"math"
	"sort"
)

type xyPoint struct {
	x, y float64
}

type xyCircle struct {
	center xyPoint
	radius float64
}

func cartesianDist(a, b xyPoint) float64 {
	d := a.x - b.x
	e := a.y - b.y
	return math.Sqrt(d*d + e*e)
}

func triangleArea(a, b, c xyPoint) float64 {
	h := math.Abs(newLine(a, b).orthDist(c))
	e := cartesianDist(a, b)
	return h * e
}

type xyLine struct {
	m_slope     float64
	m_intercept float64
	m_normfac   float64
	m_vertical  bool
	m_xcross    float64
}

func newLine(a, b xyPoint) xyLine {
	if a.x == b.x {
		return xyLine{m_vertical: true, m_xcross: a.x}
	}
	slope := (b.y - a.y) / (b.x - a.x)
	intercept := a.y - slope*a.x
	normfac := math.Sqrt(slope*slope + 1.0)
	return xyLine{m_slope: slope, m_intercept: intercept, m_normfac: normfac}
}

func (l xyLine) orthDist(o xyPoint) float64 {
	if l.m_vertical {
		return o.x - l.m_xcross
	}
	return (l.m_slope*o.x - o.y + l.m_intercept) / l.m_normfac
}

func getPrimes(n int) []int {
	primes := []int{}
	for k := 2; k <= n; k++ {
		if isPseudoPrime(k) {
			primes = append(primes, k)
		}
	}
	return primes
}

func isPseudoPrime(a int) bool {
	p := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
		79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
		163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
		241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331,
		337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421,
		431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509,
		521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
		617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709,
		719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821,
		823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919,
		929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}

	if a < p[len(p)-1]+1 {
		for _, prime := range p {
			if a == prime {
				return true
			}
		}
	}

	for _, prime := range p {
		if a%prime == 0 {
			return false
		}
	}

	return true
}

func mini(n int, vals ...int) int {
	res := vals[0]
	for _, val := range vals {
		if val < res {
			res = val
		}
	}
	return res
}

func sched(i int, m []int, rev [][]int, deps []int, load [][]int) int {
	val := 0
	var unload []int

	for n := len(m); n > 0; i = (i + 1) % 3 {
		val++
		for len(load[i]) > 0 {
			n -= len(load[i])
			unload = load[i]
			load[i] = []int{}

			for _, j := range unload {
				for _, k := range rev[j] {
					deps[k]--
					if deps[k] == 0 {
						load[m[k]] = append(load[m[k]], k)
					}
				}
			}
		}
	}

	return val - 1
}

func a213() int {
	var m []int
	var n int
	fmt.Scan(&n)
	m = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&m[i])
		m[i]--
	}

	deps := make([]int, n)
	rev := make([][]int, n)
	for j := 0; j < n; j++ {
		var xs []int
		fmt.Scan(&xs)
		deps[j] = len(xs)
		for _, i := range xs {
			rev[i-1] = append(rev[i-1], j)
		}
	}

	load := make([][]int, 3)
	for j := 0; j < n; j++ {
		if deps[j] == 0 {
			load[m[j]] = append(load[m[j]], j)
		}
	}

	return mini(3, sched(0, m, rev, deps, load), sched(1, m, rev, deps, load), sched(2, m, rev, deps, load)) + n
}

func main() {
	fmt.Println(a213())
}
