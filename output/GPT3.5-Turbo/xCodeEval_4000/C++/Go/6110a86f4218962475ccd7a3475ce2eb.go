package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type pair struct {
	x int
	y int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	h := readInt(scanner)
	n := readInt(scanner)
	m := readInt(scanner)
	k := readInt(scanner)

	a := make([]pair, n)
	for i := 0; i < n; i++ {
		a[i].x = readInt(scanner)
		a[i].y = readInt(scanner)
	}

	mn := make([]int, k)
	for i := 0; i < k; i++ {
		mn[i] = h + 1
	}
	mn[1] = 1

	used := make([]bool, n)
	cur := make([]pair, 0)

	add := func(x int) {
		q := make([]int, 0)
		for i := 0; i < k; i++ {
			q = append(q, i)
		}
		for len(q) > 0 {
			v := q[0]
			q = q[1:]
			if mn[v]+x < mn[(v+x)%k] {
				mn[(v+x)%k] = mn[v] + x
				q = append(q, (v+x)%k)
			}
		}
	}

	recalc := func() {
		cur = make([]pair, 0)
		for i := 0; i < n; i++ {
			if !used[i] && mn[a[i].x%k] <= a[i].x {
				cur = append(cur, pair{a[i].y, -i})
			}
		}
	}

	for i := 0; i < m; i++ {
		t := readInt(scanner)
		if t == 1 {
			x := readInt(scanner)
			add(x)
			recalc()
		} else if t == 2 {
			x := readInt(scanner)
			y := readInt(scanner)
			x--
			if mn[a[x].x%k] <= a[x].x {
				for j := 0; j < len(cur); j++ {
					if cur[j].y == -x {
						cur = append(cur[:j], cur[j+1:]...)
						break
					}
				}
			}
			a[x].y -= y
			if mn[a[x].x%k] <= a[x].x {
				cur = append(cur, pair{a[x].y, -x})
			}
		} else if len(cur) > 0 {
			fmt.Println(cur[0].x)
			used[-cur[0].y] = true
			cur = cur[1:]
		} else {
			fmt.Println(0)
		}
	}
}

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func readLong(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func readFloat(scanner *bufio.Scanner) float64 {
	scanner.Scan()
	val, _ := strconv.ParseFloat(scanner.Text(), 64)
	return val
}

func readString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func splitString(str string) []string {
	return strings.Fields(str)
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func min(a, b int) int {
	return int(math.Min(float64(a), float64(b)))
}

func max(a, b int) int {
	return int(math.Max(float64(a), float64(b)))
}
