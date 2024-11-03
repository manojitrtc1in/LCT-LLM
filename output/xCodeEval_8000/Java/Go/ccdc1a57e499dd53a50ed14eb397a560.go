package main

import (
	"fmt"
	"math"
	"sort"
)

type InputReader struct {
	buf  []byte
	cur  int
	nums []int
}

func NewInputReader() *InputReader {
	return &InputReader{}
}

func (in *InputReader) readByte() byte {
	if in.cur == len(in.buf) {
		in.cur = 0
		buf := make([]byte, 1024)
		n, _ := os.Stdin.Read(buf)
		in.buf = buf[:n]
	}
	in.cur++
	return in.buf[in.cur-1]
}

func (in *InputReader) readInt() int {
	for {
		c := in.readByte()
		if c >= '0' && c <= '9' {
			break
		}
	}
	x := 0
	for {
		c := in.readByte()
		if c < '0' || c > '9' {
			break
		}
		x = x*10 + int(c-'0')
	}
	return x
}

func (in *InputReader) readIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = in.readInt()
	}
	return arr
}

type OutputWriter struct {
	buf []byte
}

func NewOutputWriter() *OutputWriter {
	return &OutputWriter{}
}

func (out *OutputWriter) print(a ...interface{}) {
	for _, v := range a {
		out.buf = append(out.buf, fmt.Sprint(v)...)
	}
}

func (out *OutputWriter) println(a ...interface{}) {
	out.print(a...)
	out.buf = append(out.buf, '\n')
}

func (out *OutputWriter) flush() {
	os.Stdout.Write(out.buf)
	out.buf = out.buf[:0]
}

type Pair struct {
	first  int
	second int
}

type IntervalTree struct {
	array []int
	n     int
}

func NewIntervalTree(n int) *IntervalTree {
	return &IntervalTree{
		array: make([]int, 4*n+1),
		n:     n,
	}
}

func (tree *IntervalTree) update(pos, x int) {
	tree.updateHelper(0, 0, tree.n-1, pos, x)
}

func (tree *IntervalTree) updateHelper(node, left, right, pos, x int) {
	if left == right {
		tree.array[node] = x
		return
	}
	middle := (left + right) / 2
	if pos <= middle {
		tree.updateHelper(2*node+1, left, middle, pos, x)
	} else {
		tree.updateHelper(2*node+2, middle+1, right, pos, x)
	}
	tree.array[node] = max(tree.array[2*node+1], tree.array[2*node+2])
}

func (tree *IntervalTree) query(from, to int) int {
	return tree.queryHelper(0, 0, tree.n-1, from, to)
}

func (tree *IntervalTree) queryHelper(node, left, right, from, to int) int {
	if left > to || right < from {
		return 0
	}
	if left >= from && right <= to {
		return tree.array[node]
	}
	middle := (left + right) / 2
	return max(tree.queryHelper(2*node+1, left, middle, from, to), tree.queryHelper(2*node+2, middle+1, right, from, to))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(n, m int, L, R, A, B, C []int) {
	L, R, A, B, C = append([]int{0}, L...), append([]int{math.MaxInt32}, R...), append([]int{0}, A...), append([]int{math.MaxInt32}, B...), append([]int{0}, C...)
	max, best := make([]int, m+1), make([]int, m+1)
	orderV, orderC := make([]int, n+1), make([]int, m+1)
	for i := 0; i <= n; i++ {
		orderV[i] = i
	}
	for i := 0; i <= m; i++ {
		orderC[i] = i
	}
	arr := make([]int, 2*(n+m+1))
	for i := 0; i <= n; i++ {
		arr[2*i], arr[2*i+1] = L[i], R[i]
	}
	for i := 0; i <= m; i++ {
		arr[2*(n+i)], arr[2*(n+i)+1] = A[i], B[i]
	}
	sort.Ints(arr)
	idx := 0
	mapping := make(map[int]int)
	for i := 0; i < len(arr); i++ {
		if i == 0 || arr[i] != arr[i-1] {
			mapping[arr[i]] = idx
			idx++
		}
	}
	tree := NewIntervalTree(idx)
	process1(n, m, L, R, A, B, orderV, orderC, tree, mapping, max, best)
	process2(n, m, L, R, A, B, orderV, orderC, tree, mapping, max, best)
	process3(n, m, L, R, A, B, orderV, orderC, tree, mapping, max, best)
	ret := int64(0)
	aux := -1
	for i := 0; i < m; i++ {
		x := int64(max[i] * C[i])
		if x > ret {
			ret = x
			aux = i
		}
	}
	out.println(ret)
	if ret > 0 {
		out.println(best[aux]+1, aux+1)
	}
}

func process1(n, m int, L, R, A, B, orderV, orderC []int, tree *IntervalTree, mapping map[int]int, max, best []int) {
	sort.Slice(orderV[:n], func(i, j int) bool {
		return L[orderV[i]] < L[orderV[j]]
	})
	sort.Slice(orderC[:m], func(i, j int) bool {
		return A[orderC[i]] < A[orderC[j]]
	})
	v, c, ret, idx := 0, 0, 0, -1
	for v < n || c < m {
		for v < n && (c == m || L[orderV[v]] <= A[orderC[c]]) {
			x := orderV[v]
			if R[x] > ret {
				ret = R[x]
				idx = x
			}
			v++
		}
		for c < m && (v == n || A[orderC[c]] < L[orderV[v]]) {
			x := orderC[c]
			length := min(ret, B[x]) - A[x]
			if length > max[x] {
				max[x] = length
				best[x] = idx
			}
			c++
		}
	}
}

func process2(n, m int, L, R, A, B, orderV, orderC []int, tree *IntervalTree, mapping map[int]int, max, best []int) {
	sort.Slice(orderV[:n], func(i, j int) bool {
		return R[orderV[i]] < R[orderV[j]]
	})
	sort.Slice(orderC[:m], func(i, j int) bool {
		return B[orderC[i]] < B[orderC[j]]
	})
	v, c := n-1, m-1
	for v >= 0 || c >= 0 {
		for v >= 0 && (c == -1 || R[orderV[v]] >= B[orderC[c]]) {
			x := orderV[v]
			tree.update(mapping[L[x]], int64(R[x]-L[x])*int64(n)+int64(x))
			v--
		}
		for c >= 0 && (v == -1 || B[orderC[c]] > R[orderV[v]]) {
			x := orderC[c]
			aux := tree.query(mapping[A[x]], mapping[B[x]])
			length := int(aux/n)
			y := int(aux % n)
			if length > max[x] {
				max[x] = length
				best[x] = y
			}
			c--
		}
	}
}

func process3(n, m int, L, R, A, B, orderV, orderC []int, tree *IntervalTree, mapping map[int]int, max, best []int) {
	v, c, ret, idx := n-1, m-1, math.MaxInt32, -1
	for v >= 0 || c >= 0 {
		for v >= 0 && (c == -1 || R[orderV[v]] >= B[orderC[c]]) {
			x := orderV[v]
			if L[x] < ret {
				ret = L[x]
				idx = x
			}
			v--
		}
		for c >= 0 && (v == -1 || B[orderC[c]] > R[orderV[v]]) {
			x := orderC[c]
			length := B[x] - max(ret, A[x])
			if length > max[x] {
				max[x] = length
				best[x] = idx
			}
			c--
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	in := NewInputReader()
	out := NewOutputWriter()

	n, m := in.readInt(), in.readInt()
	L := in.readIntArray(n)
	R := in.readIntArray(n)
	A := in.readIntArray(m)
	B := in.readIntArray(m)
	C := in.readIntArray(m)

	solve(n, m, L, R, A, B, C)

	out.flush()
}
