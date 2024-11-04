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
	l := make([][]int, n)
	for i := 0; i < n; i++ {
		l[i] = make([]int, 5)
		for j := 0; j < 5; j++ {
			l[i][j] = nextInt(scanner)
		}
	}

	if n >= 50 {
		fmt.Println(0)
		return
	}
	if n <= 2 {
		fmt.Println(n)
		for i := 0; i < n; i++ {
			fmt.Println(i + 1)
		}
		return
	}

	er := make(map[int]bool)
	for i := 0; i < n; i++ {
		f := 0
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				if i == j || i == k || j == k {
					continue
				}
				w := 0
				for d := 0; d < 5; d++ {
					w += (l[i][d] - l[j][d]) * (l[i][d] - l[k][d])
				}
				if w > 0 {
					f = 1
					break
				}
			}
			if f == 1 {
				break
			}
		}
		if f == 0 {
			er[i+1] = true
		}
	}

	fmt.Println(len(er))
	for k := range er {
		fmt.Println(k)
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
