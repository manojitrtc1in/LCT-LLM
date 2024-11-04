package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read input
	n := nextInt(scanner)
	v := make([]int, n)
	for i := 0; i < n; i++ {
		v[i] = nextInt(scanner)
	}

	// Process the input
	if n == 1 {
		fmt.Println(0)
	} else {
		q := make([]int, n)
		qq := make([]int, n)
		mx := struct{ count, index int }{}
		for i := 0; i < n; i++ {
			q[v[i]]++
			if q[v[i]] > mx.count {
				mx.count = q[v[i]]
				mx.index = v[i]
			}
		}
		p := mx.index
		u := make([][]int, n+1)
		for i := 0; i < n; i++ {
			if i != p {
				u[q[i]] = append(u[q[i]], i)
			}
		}
		uu := make([]int, 0)
		for i := n; i >= 0; i-- {
			if len(u[i]) > 0 {
				uu = append(uu, i)
			}
		}
		last := 0
		leftmost := make([][]int, n)
		for i := 0; i < n; i++ {
			leftmost[i] = make([]int, q[i]+1)
			leftmost[i][0] = 0
		}
		ans := 0
		for y := 0; y < int(math.Min(float64(n), 100)); y++ {
			if y != p {
				g := make([]int, n+1)
				b := 0
				for i := 0; i < n; i++ {
					if v[i] == p {
						ans = max(ans, i-g[len(g)-b-1]-1)
						if b > 0 {
							b--
						} else {
							g = append(g, i)
						}
					} else if v[i] == y {
						b++
					}
				}
				ans = max(ans, n-g[len(g)-b-1]-1)
			}
		}

		// Print the result
		fmt.Println(ans)
	}
}

// Helper function to read the next integer from the scanner
func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
