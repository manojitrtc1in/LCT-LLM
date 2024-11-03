package main

import (
	"fmt"
	"math"
	"sort"
)

type InputReader struct {
	stream []byte
	index  int
}

func NewInputReader(stream []byte) *InputReader {
	return &InputReader{stream: stream}
}

func (in *InputReader) read() byte {
	if in.index >= len(in.stream) {
		return 0
	}
	in.index++
	return in.stream[in.index-1]
}

func (in *InputReader) readInt() int {
	c := in.read()
	for isWhitespace(c) {
		c = in.read()
	}
	sgn := 1
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := 0
	for !isWhitespace(c) {
		if c < '0' || c > '9' {
			panic("Invalid input")
		}
		res *= 10
		res += int(c - '0')
		c = in.read()
	}
	return res * sgn
}

func isWhitespace(c byte) bool {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == 0
}

type OutputWriter struct {
	stream []byte
}

func NewOutputWriter() *OutputWriter {
	return &OutputWriter{}
}

func (out *OutputWriter) print(args ...interface{}) {
	for _, arg := range args {
		switch v := arg.(type) {
		case int:
			out.stream = append(out.stream, []byte(fmt.Sprintf("%d", v))...)
		case string:
			out.stream = append(out.stream, []byte(v)...)
		case []byte:
			out.stream = append(out.stream, v...)
		}
	}
}

func (out *OutputWriter) println(args ...interface{}) {
	out.print(args...)
	out.stream = append(out.stream, '\n')
}

func (out *OutputWriter) flush() {
	fmt.Print(string(out.stream))
	out.stream = out.stream[:0]
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
	tree.updateUtil(0, 0, tree.n-1, pos, x)
}

func (tree *IntervalTree) updateUtil(node, left, right, pos, x int) {
	if left == right {
		tree.array[node] = x
		return
	}
	mid := (left + right) / 2
	if pos <= mid {
		tree.updateUtil(2*node+1, left, mid, pos, x)
	} else {
		tree.updateUtil(2*node+2, mid+1, right, pos, x)
	}
	tree.array[node] = max(tree.array[2*node+1], tree.array[2*node+2])
}

func (tree *IntervalTree) query(from, to int) int {
	return tree.queryUtil(0, 0, tree.n-1, from, to)
}

func (tree *IntervalTree) queryUtil(node, left, right, from, to int) int {
	if left > to || right < from {
		return 0
	}
	if left >= from && right <= to {
		return tree.array[node]
	}
	mid := (left + right) / 2
	return max(tree.queryUtil(2*node+1, left, mid, from, to), tree.queryUtil(2*node+2, mid+1, right, from, to))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(n, m int, L, R, A, B, C []int) int64 {
	idx := 0
	flag := n == 200000 && m == 200000
	max := make([]int, m)
	best := make([]int, m)
	orderV := make([]int, n)
	orderC := make([]int, m)
	tree := NewIntervalTree(len(L) + len(A))
	mp := make(map[int]int)

	for i := 0; i < n; i++ {
		orderV[i] = i
	}
	for i := 0; i < m; i++ {
		orderC[i] = i
	}

	arr := make([]int, 2*(n+m))
	for i := 0; i < n; i++ {
		arr[2*i] = L[i]
		arr[2*i+1] = R[i]
	}
	for i := 0; i < m; i++ {
		arr[2*(n+i)] = A[i]
		arr[2*(n+i)+1] = B[i]
	}

	sort.Ints(arr)

	for i := 0; i < len(arr); i++ {
		if i == 0 || arr[i] != arr[i-1] {
			mp[arr[i]] = idx
			idx++
		}
	}

	for i := 0; i < n; i++ {
		L[i] = mp[L[i]]
		R[i] = mp[R[i]]
	}

	for i := 0; i < m; i++ {
		A[i] = mp[A[i]]
		B[i] = mp[B[i]]
	}

	process1(n, m, L, R, A, B, max, best, orderV, orderC, tree)
	process2(n, m, L, R, A, B, max, best, orderV, orderC, tree)
	process3(n, m, L, R, A, B, max, best, orderV, orderC, tree)

	ret := int64(0)
	aux := -1
	for i := 0; i < m; i++ {
		x := int64(max[i] * C[i])
		if x > ret {
			ret = x
			aux = i
		}
	}

	return ret
}

func process1(n, m int, L, R, A, B, max, best, orderV, orderC []int, tree *IntervalTree) {
	sort.Slice(orderV, func(i, j int) bool {
		return L[orderV[i]] < L[orderV[j]]
	})
	sort.Slice(orderC, func(i, j int) bool {
		return A[orderC[i]] < A[orderC[j]]
	})

	v, c, ret, idx, x := 0, 0, 0, -1, 0
	for v < n || c < m {
		for v < n && (c == m || L[orderV[v]] <= A[orderC[c]]) {
			x = orderV[v]
			if R[x] > ret {
				ret = R[x]
				idx = x
			}
			v++
		}
		for c < m && (v == n || A[orderC[c]] < L[orderV[v]]) {
			x = orderC[c]
			length := int(math.Min(float64(ret), float64(B[x]))) - A[x]
			if length > max[x] {
				max[x] = length
				best[x] = idx
			}
			c++
		}
	}
}

func process2(n, m int, L, R, A, B, max, best, orderV, orderC []int, tree *IntervalTree) {
	sort.Slice(orderV, func(i, j int) bool {
		return R[orderV[i]] < R[orderV[j]]
	})
	sort.Slice(orderC, func(i, j int) bool {
		return B[orderC[i]] < B[orderC[j]]
	})

	v, c := 0, 0
	for v < n || c < m {
		for v < n && (c == m || R[orderV[v]] <= B[orderC[c]]) {
			x := orderV[v]
			tree.update(L[x], int64(R[x])*int64(n)+int64(x))
			v++
		}
		for c < m && (v == n || B[orderC[c]] < R[orderV[v]]) {
			x := orderC[c]
			aux := tree.query(A[x], B[x])
			length := int(aux/n)
			y := int(aux % n)
			if length > max[x] {
				max[x] = length
				best[x] = y
			}
			c++
		}
	}
}

func process3(n, m int, L, R, A, B, max, best, orderV, orderC []int) {
	v, c, ret, idx, x := n-1, m-1, math.MaxInt32, -1, 0
	for v >= 0 || c >= 0 {
		for v >= 0 && (c == -1 || R[orderV[v]] >= B[orderC[c]]) {
			x = orderV[v]
			if L[x] < ret {
				ret = L[x]
				idx = x
			}
			v--
		}
		for c >= 0 && (v == -1 || B[orderC[c]] > R[orderV[v]]) {
			x = orderC[c]
			length := B[x] - int(math.Max(float64(ret), float64(A[x])))
			if length > max[x] {
				max[x] = length
				best[x] = idx
			}
			c--
		}
	}
}

func main() {
	in := NewInputReader([]byte{})
	out := NewOutputWriter()

	n := in.readInt()
	m := in.readInt()
	L := make([]int, n)
	R := make([]int, n)
	A := make([]int, m)
	B := make([]int, m)
	C := make([]int, m)
	for i := 0; i < n; i++ {
		L[i] = in.readInt()
		R[i] = in.readInt()
	}
	for i := 0; i < m; i++ {
		A[i] = in.readInt()
		B[i] = in.readInt()
		C[i] = in.readInt()
	}

	result := solve(n, m, L, R, A, B, C)
	out.println(result)
	out.flush()
}
