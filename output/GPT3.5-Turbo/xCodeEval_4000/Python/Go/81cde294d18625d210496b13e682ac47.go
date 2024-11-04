package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i] = nextInt(scanner)
	}

	if n >= 100 {
		fmt.Println(1)
		return
	}

	ans := n * n
	cur := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cur[i] = cur[i-1] ^ l[i-1]
	}

	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			for k := j + 1; k <= n; k++ {
				if cur[j]^cur[i-1] > cur[k]^cur[j] {
					ans = min(ans, k-i-1)
				}
			}
		}
	}

	if ans == n*n {
		ans = -1
	}
	fmt.Println(ans)
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
