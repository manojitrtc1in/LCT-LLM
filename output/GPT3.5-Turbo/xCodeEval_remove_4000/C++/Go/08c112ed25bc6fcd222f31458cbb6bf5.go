package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const INF = int(1e9)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	a := make([]int, n+2)
	for i := 1; i <= n; i++ {
		a[i] = nextInt(scanner)
	}
	a[0] = -INF
	a[n+1] = INF + INF

	ans := INF
	for i := 1; i <= n; i++ {
		s := a[i]
		for j := 2; j <= 50 && i+j-1 <= n; j++ {
			s ^= a[i+j-1]
			z := 0
			for r := 0; r < 50 && i+j+r <= n+1; r++ {
				z ^= a[i+j+r]
				if a[i-1] > s || s > z {
					ans = min(ans, j+r)
					break
				}
			}
		}
	}

	if ans == INF {
		ans = 0
	}
	fmt.Println(ans - 1)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
