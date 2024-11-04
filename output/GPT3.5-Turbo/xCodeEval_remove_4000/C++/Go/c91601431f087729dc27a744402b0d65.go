package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Point struct {
	x, y int
}

func solve() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	p := make([]Point, n)
	for i := 0; i < n; i++ {
		p[i].x = nextInt(scanner)
		p[i].y = nextInt(scanner)
	}

	cur := 0
	for i := 0; i < n; i++ {
		if p[i].x < p[cur].x || (p[i].x == p[cur].x && p[i].y < p[cur].y) {
			cur = i
		}
	}

	s := nextString(scanner)
	s += "R"
	ans := []int{cur}
	used := make([]bool, n)

	for i := 0; i+1 < n; i++ {
		used[cur] = true
		zero := p[cur]
		a := make([]Point, n)
		for j := 0; j < n; j++ {
			a[j].x = p[j].x - zero.x
			a[j].y = p[j].y - zero.y
		}

		idx := -1
		for j := 0; j < n; j++ {
			if !used[j] {
				if idx == -1 {
					idx = j
				} else {
					if s[i] == 'R' && a[j].x*a[idx].y < a[idx].x*a[j].y {
						idx = j
					}
					if s[i] == 'L' && a[idx].x*a[j].y < a[j].x*a[idx].y {
						idx = j
					}
				}
			}
		}

		cur = idx
		ans = append(ans, cur)
	}

	for _, x := range ans {
		fmt.Printf("%d ", x+1)
	}
	fmt.Println()

	return 0
}

func main() {
	solve()
}

func nextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
