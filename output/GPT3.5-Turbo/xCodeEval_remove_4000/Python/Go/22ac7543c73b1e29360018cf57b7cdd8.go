package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var mod int = 1000000007

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n, m := nextInt(scanner), nextInt(scanner)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i] = nextInt(scanner)
	}

	t := make([][2]int, m)
	for i := 0; i < m; i++ {
		a, b := nextInt(scanner), nextInt(scanner)
		t[i] = [2]int{a, b}
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i][0] < t[j][0]
	})

	check := func(x int) bool {
		now := x
		c := sum(l)
		cur := 0
		last := 0
		ld := make(map[int]int)
		for i := 0; i < len(t); i++ {
			if t[i][0] <= x {
				ld[t[i][1]] = i
			}
		}
		for i := 0; i < m; i++ {
			if ld[t[i][1]] != i {
				continue
			}
			if t[i][0] > x {
				break
			}
			cur += t[i][0] - last
			rt := min(cur, l[t[i][1]-1])
			cur -= rt
			now -= rt
			c -= rt
			last = t[i][0]
		}
		if now >= 2*c {
			return true
		}
		return false
	}

	st := 1
	end := 2 * sum(l)
	ans := end
	for st <= end {
		mid := (st + end) / 2
		if check(mid) == true {
			ans = mid
			end = mid - 1
		} else {
			st = mid + 1
		}
	}
	fmt.Println(ans)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func sum(arr []int) int {
	s := 0
	for _, num := range arr {
		s += num
	}
	return s
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
