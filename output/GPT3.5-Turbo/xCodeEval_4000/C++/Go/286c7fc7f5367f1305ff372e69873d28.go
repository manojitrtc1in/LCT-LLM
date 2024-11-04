package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt64(scanner)
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	d := make([]int, n)
	for i := 0; i < n; i++ {
		c := a[i]
		for j := int64(2); j*j <= c; j++ {
			for c%j == 0 {
				d[i]++
				c /= j
			}
		}
		if c != 1 {
			d[i]++
		}
	}

	infty := int(^uint(0) >> 1)
	reachable := make([]int, 1<<n)
	for i := 0; i < len(reachable); i++ {
		reachable[i] = infty
	}
	reachable[0] = 0

	for i := 0; i < n; i++ {
		for j := 0; j < (1 << i); j++ {
			rem := a[i]
			good := true
			for k := 0; k < i; k++ {
				if (j>>k)&1 == 1 {
					if rem%a[k] != 0 {
						good = false
						break
					}
					rem /= a[k]
				}
			}
			qty := 0
			for c := int64(2); c*c <= rem; c++ {
				for rem%c == 0 {
					qty++
					rem /= c
				}
			}
			if rem != 1 {
				qty++
			}
			lim := 0
			if i != 0 {
				lim = 1 << (i - 1)
			}
			if good {
				for k := 0; k < (1 << i); k++ {
					if (j&k) == 0 && reachable[j+k] != infty && j+k >= lim {
						if reachable[(1<<i)+k] > reachable[j+k]+qty+boolToInt(d[i] != 1) {
							reachable[(1<<i)+k] = reachable[j+k] + qty + boolToInt(d[i] != 1)
						}
					}
				}
			}
		}
	}

	answer := infty
	for i := (1 << (n - 1)); i < (1 << n); i++ {
		if reachable[i] != 0 {
			if answer > reachable[i]+boolToInt(popcount(i) != 1) {
				answer = reachable[i] + boolToInt(popcount(i) != 1)
			}
		}
	}

	fmt.Println(answer)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func nextInt64(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func popcount(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}
