package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	M, _ := strconv.Atoi(scanner.Text())

	K := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		K[i], _ = strconv.Atoi(scanner.Text())
	}

	vv := make([][]int, 4*e5+1)
	for i := 0; i < M; i++ {
		scanner.Scan()
		D, _ := strconv.Atoi(scanner.Text())

		scanner.Scan()
		T, _ := strconv.Atoi(scanner.Text())

		vv[D-1] = append(vv[D-1], T-1)
	}

	ok := 2 * sum(K)
	ng := sum(K) - 1

	for ok-ng > 1 {
		k := (ok + ng) >> 1
		v := make([]int, k)
		b := make([]bool, N)

		for i := k - 1; i >= 0; i-- {
			for _, j := range vv[i] {
				if !b[j] {
					b[j] = true
					v[i] += K[j]
				}
			}
		}

		t := 0
		s := sum(K)

		for i := 0; i < k; i++ {
			t++
			m := min(t, v[i])
			t -= m
			s -= m
		}

		if t >= s*2 {
			ok = k
		} else {
			ng = k
		}
	}

	fmt.Println(ok)
}

func sum(a []int) int {
	s := 0
	for _, e := range a {
		s += e
	}
	return s
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
