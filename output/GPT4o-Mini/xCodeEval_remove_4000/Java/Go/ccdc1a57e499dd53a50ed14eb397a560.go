package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"sort"
)

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	return &InputReader{scanner: scanner}
}

func (in *InputReader) ReadInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscan(in.scanner.Text(), &x)
	return x
}

type OutputWriter struct {
	writer io.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: w}
}

func (out *OutputWriter) PrintLine(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

type IntervalTree struct {
	array []int64
	n     int
}

func NewIntervalTree(n int) *IntervalTree {
	return &IntervalTree{array: make([]int64, 4*n), n: n}
}

func (tree *IntervalTree) Update(pos int, x int64) {
	tree.update(0, 0, tree.n-1, pos, x)
}

func (tree *IntervalTree) update(node, left, right, pos int, val int64) {
	if left == right {
		tree.array[node] = val
		return
	}
	middle := (left + right) / 2
	if pos <= middle {
		tree.update(2*node+1, left, middle, pos, val)
	} else {
		tree.update(2*node+2, middle+1, right, pos, val)
	}
	tree.array[node] = max(tree.array[2*node+1], tree.array[2*node+2])
}

func (tree *IntervalTree) Query(from, to int) int64 {
	return tree.query(0, 0, tree.n-1, from, to)
}

func (tree *IntervalTree) query(node, left, right, from, to int) int64 {
	if left > to || right < from {
		return 0
	}
	if left >= from && right <= to {
		return tree.array[node]
	}
	middle := (left + right) / 2
	return max(tree.query(2*node+1, left, middle, from, to), tree.query(2*node+2, middle+1, right, from, to))
}

type Task struct {
	L, R, A, B, C, max, best []int
	orderV, orderC          []int
	tree                    *IntervalTree
	mapIndex                map[int]int
}

func (t *Task) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	n := in.ReadInt()
	m := in.ReadInt()
	t.L = make([]int, n)
	t.R = make([]int, n)
	t.A = make([]int, m)
	t.B = make([]int, m)
	t.C = make([]int, m)
	t.max = make([]int, m)
	t.best = make([]int, m)
	t.orderV = make([]int, n)
	t.orderC = make([]int, m)

	for i := 0; i < n; i++ {
		t.L[i] = in.ReadInt()
		t.R[i] = in.ReadInt()
		t.orderV[i] = i
	}
	for i := 0; i < m; i++ {
		t.A[i] = in.ReadInt()
		t.B[i] = in.ReadInt()
		t.C[i] = in.ReadInt()
		t.orderC[i] = i
	}

	arr := make([]int, 2*(n+m))
	for i := 0; i < n; i++ {
		arr[2*i] = t.L[i]
		arr[2*i+1] = t.R[i]
	}
	for i := 0; i < m; i++ {
		arr[2*(n+i)] = t.A[i]
		arr[2*(n+i)+1] = t.B[i]
	}
	sort.Ints(arr)

	t.mapIndex = make(map[int]int)
	idx := 0
	for i := 0; i < len(arr); i++ {
		if i == 0 || arr[i] != arr[i-1] {
			t.mapIndex[arr[i]] = idx
			idx++
		}
	}
	t.tree = NewIntervalTree(len(t.mapIndex))
	t.process1(n, m, out)
	t.process2(n, m)
	t.process3(n, m)

	ret := int64(0)
	aux := -1
	for i := 0; i < m; i++ {
		x := int64(t.max[i]) * int64(t.C[i])
		if x > ret {
			ret = x
			aux = i
		}
	}
	out.PrintLine(ret)
	if ret > 0 {
		out.PrintLine(t.best[aux]+1, aux+1)
	}
}

func (t *Task) process1(n, m int, out *OutputWriter) {
	sort.Slice(t.orderV, func(i, j int) bool {
		return t.L[t.orderV[i]] < t.L[t.orderV[j]]
	})
	sort.Slice(t.orderC, func(i, j int) bool {
		return t.A[t.orderC[i]] < t.A[t.orderC[j]]
	})

	v, c, ret, idx := 0, 0, 0, -1
	for v < n || c < m {
		for v < n && (c == m || t.L[t.orderV[v]] <= t.A[t.orderC[c]]) {
			x := t.orderV[v]
			if t.R[x] > ret {
				ret = t.R[x]
				idx = x
			}
			v++
		}
		for c < m && (v == n || t.A[t.orderC[c]] < t.L[t.orderV[v]]) {
			x := t.orderC[c]
			length := min(ret, t.B[x]) - t.A[x]
			if length > t.max[x] {
				t.max[x] = length
				t.best[x] = idx
			}
			c++
		}
	}
}

func (t *Task) process2(n, m int) {
	sort.Slice(t.orderV, func(i, j int) bool {
		return t.R[t.orderV[i]] < t.R[t.orderV[j]]
	})
	sort.Slice(t.orderC, func(i, j int) bool {
		return t.B[t.orderC[i]] < t.B[t.orderC[j]]
	})

	v, c := 0, 0
	for v < n || c < m {
		for v < n && (c == m || t.R[t.orderV[v]] <= t.B[t.orderC[c]]) {
			x := t.orderV[v]
			t.tree.Update(t.mapIndex[t.L[x]], int64(t.R[x]-t.L[x])*int64(n)+int64(x))
			v++
		}
		for c < m && (v == n || t.B[t.orderC[c]] < t.R[t.orderV[v]]) {
			x := t.orderC[c]
			aux := t.tree.Query(t.mapIndex[t.A[x]], t.mapIndex[t.B[x]])
			length := int(aux/int64(n))
			y := int(aux % int64(n))
			if length > t.max[x] {
				t.max[x] = length
				t.best[x] = y
			}
			c++
		}
	}
}

func (t *Task) process3(n, m int) {
	v, c, ret, idx := n-1, m-1, math.MaxInt32, -1
	for v >= 0 || c >= 0 {
		for v >= 0 && (c == -1 || t.R[t.orderV[v]] >= t.B[t.orderC[c]]) {
			x := t.orderV[v]
			if t.L[x] < ret {
				ret = t.L[x]
				idx = x
			}
			v--
		}
		for c >= 0 && (v == -1 || t.B[t.orderC[c]] > t.R[t.orderV[v]]) {
			x := t.orderC[c]
			length := t.B[x] - max(ret, t.A[x])
			if length > t.max[x] {
				t.max[x] = length
				t.best[x] = idx
			}
			c--
		}
	}
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	solver := &Task{}
	solver.Solve(1, in, out)
}
