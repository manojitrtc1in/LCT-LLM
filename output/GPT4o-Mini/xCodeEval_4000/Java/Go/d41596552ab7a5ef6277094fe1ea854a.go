package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var x, k, n, q int
	fmt.Fscan(in, &x, &k, &n, &q)
	c := readIntArray(in, k)
	p := make([]int, q)
	w := make([]int, q)
	readIntArrays(in, p, w)

	orderBy(p, w)
	decreaseByOne(p)

	id := make([]int, 1<<k)
	for i := range id {
		id[i] = -1
	}
	byId := make([]int, 0)
	size := 0
	for i := 0; i < (1 << k); i++ {
		if bitCount(i) == x {
			id[i] = size
			byId = append(byId, i)
			size++
		}
	}

	baseMat := make([][]int64, size)
	for i := range baseMat {
		baseMat[i] = make([]int64, size)
		fill(baseMat[i], math.MaxInt64)
	}
	specMat := make([][][]int64, q)
	for i := range specMat {
		specMat[i] = make([][]int64, size)
		for j := range specMat[i] {
			specMat[i][j] = make([]int64, size)
			fill(specMat[i][j], math.MaxInt64)
		}
	}

	for i := 0; i < size; i++ {
		ii := byId[i]
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
						specMat[l][id[ii]][id[ni+(1<<j)]] = int64(c[j]) + specMat[l][id[ii]][id[ni+(1<<j)]]
					}
				}
			}
		}
	}

	current := make([][]int64, size)
	for i := range current {
		current[i] = make([]int64, size)
	}
	makeOne(current)

	temp := make([][]int64, size)
	for i := range temp {
		temp[i] = make([]int64, size)
	}
	temp1 := make([][]int64, size)
	for i := range temp1 {
		temp1[i] = make([]int64, size)
	}
	temp2 := make([][]int64, size)
	for i := range temp2 {
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
			answer += w[i]
		}
	}
	fmt.Fprintln(out, answer)
}

func readIntArray(in io.Reader, size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		fmt.Fscan(in, &arr[i])
	}
	return arr
}

func readIntArrays(in io.Reader, arrays ...[]int) {
	for i := 0; i < len(arrays[0]); i++ {
		for j := range arrays {
			fmt.Fscan(in, &arrays[j][i])
		}
	}
}

func orderBy(base []int, arrays ...[]int) {
	order := order(base)
	orderArray(order, base)
	for _, array := range arrays {
		orderArray(order, array)
	}
}

func order(base []int) []int {
	order := make([]int, len(base))
	for i := range order {
		order[i] = i
	}
	sort(order, base)
	return order
}

func sort(order []int, base []int) {
	// Implement sorting logic here
}

func orderArray(order []int, array []int) {
	temp := make([]int, len(order))
	for i, v := range order {
		temp[i] = array[v]
	}
	copy(array, temp)
}

func decreaseByOne(arrays ...[]int) {
	for _, array := range arrays {
		for i := range array {
			array[i]--
		}
	}
}

func bitCount(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func fill(array []int64, value int64) {
	for i := range array {
		array[i] = value
	}
}

func makeOne(current [][]int64) {
	fill(current, math.MaxInt64)
	for i := range current {
		current[i][i] = 0
	}
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
	for i := range c {
		for j := range c[i] {
			c[i][j] = math.MaxInt64
			for k := range c {
				if a[i][k] != math.MaxInt64 && b[k][j] != math.MaxInt64 {
					c[i][j] = min(c[i][j], a[i][k]+b[k][j])
				}
			}
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
