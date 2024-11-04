package main

import (
	"fmt"
	"math"
	"sort"
)

type InputReader struct {
	data []int
	index int
}

func NewInputReader() *InputReader {
	var n int
	fmt.Scan(&n)
	data := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&data[i])
	}
	return &InputReader{data: data}
}

func (ir *InputReader) ReadInt() int {
	val := ir.data[ir.index]
	ir.index++
	return val
}

type OutputWriter struct{}

func (ow *OutputWriter) PrintLine(i int64) {
	fmt.Println(i)
}

type TaskC struct{}

func (t *TaskC) Solve(ir *InputReader, ow *OutputWriter) {
	x := ir.ReadInt()
	k := ir.ReadInt()
	n := ir.ReadInt()
	q := ir.ReadInt()
	c := make([]int, k)
	for i := 0; i < k; i++ {
		c[i] = ir.ReadInt()
	}
	p := make([]int, q)
	w := make([]int, q)
	for i := 0; i < q; i++ {
		p[i] = ir.ReadInt()
		w[i] = ir.ReadInt()
	}
	orderBy(p, w)

	id := make([]int, 1<<k)
	byId := make([]int, 0)
	size := 0
	for i := 0; i < (1 << k); i++ {
		if countBits(i) == x {
			id[i] = size
			byId = append(byId, i)
			size++
		}
	}

	baseMat := make([][]int64, size)
	for i := range baseMat {
		baseMat[i] = make([]int64, size)
		for j := range baseMat[i] {
			baseMat[i][j] = math.MaxInt64
		}
	}
	specMat := make([][][]int64, q)
	for i := range specMat {
		specMat[i] = make([][]int64, size)
		for j := range specMat[i] {
			specMat[i][j] = make([]int64, size)
			for k := range specMat[i][j] {
				specMat[i][j][k] = math.MaxInt64
			}
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
						specMat[l][id[ii]][id[ni+(1<<j)]] = int64(c[j]) + int64(w[l])
					}
				}
			}
		}
	}

	current := make([][]int64, size)
	for i := range current {
		current[i] = make([]int64, size)
		for j := range current[i] {
			current[i][j] = math.MaxInt64
		}
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
			answer += int64(w[i])
		}
	}
	ow.PrintLine(answer)
}

func countBits(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func makeOne(current [][]int64) {
	for i := range current {
		for j := range current[i] {
			current[i][j] = math.MaxInt64
		}
		current[i][i] = 0
	}
}

func power(base [][]int64, exponent int, result, temp [][]int64) {
	if exponent == 0 {
		makeOne(result)
		return
	}
	if exponent%2 == 0 {
		power(base, exponent/2, temp, result)
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

func orderBy(p, w []int) {
	type pair struct {
		first, second int
	}
	pairs := make([]pair, len(p))
	for i := range p {
		pairs[i] = pair{p[i], w[i]}
	}
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].first < pairs[j].first
	})
	for i := range pairs {
		p[i] = pairs[i].first
		w[i] = pairs[i].second
	}
}

func main() {
	ir := NewInputReader()
	ow := &OutputWriter{}
	solver := &TaskC{}
	solver.Solve(ir, ow)
}
