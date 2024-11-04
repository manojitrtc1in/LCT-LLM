package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var x, k, n, q int
	fmt.Fscan(reader, &x, &k, &n, &q)
	c := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Fscan(reader, &c[i])
	}
	p := make([]int, q)
	w := make([]int, q)
	for i := 0; i < q; i++ {
		fmt.Fscan(reader, &p[i], &w[i])
	}

	baseMat := make([][]int64, 1<<k)
	for i := 0; i < (1 << k); i++ {
		baseMat[i] = make([]int64, 1<<k)
	}
	specMat := make([][][]int64, q)
	for i := 0; i < q; i++ {
		specMat[i] = make([][]int64, 1<<k)
		for j := 0; j < (1 << k); j++ {
			specMat[i][j] = make([]int64, 1<<k)
		}
	}

	id := make([]int, 1<<k)
	byID := make([]int, 1<<k)
	size := 0
	for i := 0; i < (1 << k); i++ {
		if bitCount(i) == x {
			id[i] = size
			byID[size] = i
			size++
		}
	}

	for i := 0; i < size; i++ {
		ii := byID[i]
		if (ii & 1) == 0 {
			baseMat[id[ii]][id[ii>>1]] = 0
			for j := 0; j < q; j++ {
				specMat[j][id[ii]][id[ii>>1]] = 0
			}
		} else {
			ni := ii >> 1
			for j := 0; j < k; j++ {
				if (ni>>j)&1 == 0 {
					baseMat[id[ii]][id[ni+(1<<j)]] = int64(c[j])
					for l := 0; l < q; l++ {
						specMat[l][id[ii]][id[ni+(1<<j)]] = int64(c[j] + w[l])
					}
				}
			}
		}
	}

	current := make([][]int64, size)
	for i := 0; i < size; i++ {
		current[i] = make([]int64, size)
	}
	makeOne(current)

	temp := make([][]int64, size)
	for i := 0; i < size; i++ {
		temp[i] = make([]int64, size)
	}
	temp1 := make([][]int64, size)
	for i := 0; i < size; i++ {
		temp1[i] = make([]int64, size)
	}
	temp2 := make([][]int64, size)
	for i := 0; i < size; i++ {
		temp2[i] = make([]int64, size)
	}

	start := 0
	for i := 0; i <= q; i++ {
		stop := n - x
		if i < q {
			stop = min(stop, p[i])
		}
		power(baseMat, stop-start, temp1, temp2)
		multiply(temp, current, temp1)
		if stop == n-x {
			current = temp
			break
		} else {
			multiply(current, temp, specMat[i])
			start = stop + 1
		}
	}

	answer := current[id[(1<<x)-1]][id[(1<<x)-1]]
	for i := 0; i < q; i++ {
		if p[i] >= n-x {
			answer += int64(w[i])
		}
	}

	fmt.Fprintln(writer, answer)
}

func bitCount(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func power(base [][]int64, exponent int, result, temp [][]int64) {
	if exponent == 0 {
		makeOne(result)
		return
	}
	if exponent&1 == 0 {
		power(base, exponent>>1, temp, result)
		multiply(result, temp, temp)
	} else {
		power(base, exponent-1, temp, result)
		multiply(result, temp, base)
	}
}

func multiply(c, a, b [][]int64) {
	for i := 0; i < len(c); i++ {
		for j := 0; j < len(c); j++ {
			c[i][j] = int64(1e18)
			for k := 0; k < len(c); k++ {
				if a[i][k] != int64(1e18) && b[k][j] != int64(1e18) {
					c[i][j] = min(c[i][j], a[i][k]+b[k][j])
				}
			}
		}
	}
}

func makeOne(current [][]int64) {
	for i := 0; i < len(current); i++ {
		for j := 0; j < len(current); j++ {
			if i == j {
				current[i][j] = 0
			} else {
				current[i][j] = int64(1e18)
			}
		}
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
