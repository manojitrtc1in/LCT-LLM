package main

import (
	"fmt"
	"math"
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
	if in.cur >= len(in.buf) {
		in.cur = 0
		in.buf = make([]byte, 1024)
		n, _ := os.Stdin.Read(in.buf)
		if n == 0 {
			return 0
		}
	}
	in.cur++
	return in.buf[in.cur-1]
}

func (in *InputReader) readInt() int {
	c := in.readByte()
	for c <= ' ' {
		c = in.readByte()
	}
	sign := 1
	if c == '-' {
		sign = -1
		c = in.readByte()
	}
	num := 0
	for c >= '0' && c <= '9' {
		num = num*10 + int(c-'0')
		c = in.readByte()
	}
	return num * sign
}

func (in *InputReader) readString() string {
	c := in.readByte()
	for c <= ' ' {
		c = in.readByte()
	}
	buf := make([]byte, 0)
	for c > ' ' {
		buf = append(buf, c)
		c = in.readByte()
	}
	return string(buf)
}

type OutputWriter struct {
	buf []byte
	cur int
}

func NewOutputWriter() *OutputWriter {
	return &OutputWriter{}
}

func (out *OutputWriter) writeByte(c byte) {
	if out.cur >= len(out.buf) {
		out.cur = 0
		out.buf = make([]byte, 1024)
	}
	out.buf[out.cur] = c
	out.cur++
}

func (out *OutputWriter) writeString(s string) {
	for i := 0; i < len(s); i++ {
		out.writeByte(s[i])
	}
}

func (out *OutputWriter) flush() {
	os.Stdout.Write(out.buf[:out.cur])
	out.cur = 0
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
	tree.updateNode(0, 0, tree.n-1, pos, x)
}

func (tree *IntervalTree) updateNode(node, left, right, pos, x int) {
	if left == right {
		tree.array[node] = x
		return
	}
	middle := (left + right) / 2
	if pos <= middle {
		tree.updateNode(2*node+1, left, middle, pos, x)
	} else {
		tree.updateNode(2*node+2, middle+1, right, pos, x)
	}
	tree.array[node] = max(tree.array[2*node+1], tree.array[2*node+2])
}

func (tree *IntervalTree) query(from, to int) int {
	return tree.queryNode(0, 0, tree.n-1, from, to)
}

func (tree *IntervalTree) queryNode(node, left, right, from, to int) int {
	if left > to || right < from {
		return 0
	}
	if left >= from && right <= to {
		return tree.array[node]
	}
	middle := (left + right) / 2
	return max(tree.queryNode(2*node+1, left, middle, from, to), tree.queryNode(2*node+2, middle+1, right, from, to))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Task struct {
	L, R, A, B, C, max, best []int
	orderV, orderC          []int
	tree                    *IntervalTree
	mapper                  map[int]int
}

func (task *Task) solve(testNumber int, in *InputReader, out *OutputWriter) {
	n := in.readInt()
	m := in.readInt()
	idx := 0
	flag := n == 200000 && m == 200000
	task.L = make([]int, n)
	task.R = make([]int, n)
	task.A = make([]int, m)
	task.B = make([]int, m)
	task.C = make([]int, m)
	task.max = make([]int, m)
	task.best = make([]int, m)
	task.orderV = make([]int, n)
	task.orderC = make([]int, m)
	IOUtils_id12(in, task.L, task.R)
	IOUtils_id12(in, task.A, task.B, task.C)
	for i := 0; i < n; i++ {
		task.orderV[i] = i
	}
	for i := 0; i < m; i++ {
		task.orderC[i] = i
	}
	arr := make([]int, 2*(n+m))
	for i := 0; i < n; i++ {
		arr[2*i] = task.L[i]
		arr[2*i+1] = task.R[i]
	}
	for i := 0; i < m; i++ {
		arr[2*(n+i)] = task.A[i]
		arr[2*(n+i)+1] = task.B[i]
	}
	sort.Ints(arr)
	task.mapper = make(map[int]int)
	for i := 0; i < len(arr); i++ {
		if i == 0 || arr[i] != arr[i-1] {
			task.mapper[arr[i]] = idx
			idx++
		}
	}
	task.tree = NewIntervalTree(len(task.mapper))
	task.process1(n, m, out)
	task.process2(n, m)
	task.process3(n, m)
	ret := int64(0)
	aux := -1
	for i := 0; i < m; i++ {
		x := int64(task.max[i]) * int64(task.C[i])
		if x > ret {
			ret = x
			aux = i
		}
	}
	out.printLine(ret)
	if ret > 0 {
		out.printLine(task.best[aux]+1, aux+1)
	}
}

func (task *Task) process1(n, m int, out *OutputWriter) {
	sort.Slice(task.orderV, func(i, j int) bool {
		return task.L[task.orderV[i]] < task.L[task.orderV[j]]
	})
	sort.Slice(task.orderC, func(i, j int) bool {
		return task.A[task.orderC[i]] < task.A[task.orderC[j]]
	})
	v := 0
	c := 0
	ret := 0
	idx := -1
	x := 0
	for v < n || c < m {
		for v < n && (c == m || task.L[task.orderV[v]] <= task.A[task.orderC[c]]) {
			x = task.orderV[v]
			if task.R[x] > ret {
				ret = task.R[x]
				idx = x
			}
			v++
		}
		for c < m && (v == n || task.A[task.orderC[c]] < task.L[task.orderV[v]]) {
			x = task.orderC[c]
			length := int(math.Min(float64(ret), float64(task.B[x]))) - task.A[x]
			if length > task.max[x] {
				task.max[x] = length
				task.best[x] = idx
			}
			c++
		}
	}
}

func (task *Task) process2(n, m int) {
	sort.Slice(task.orderV, func(i, j int) bool {
		return task.R[task.orderV[i]] < task.R[task.orderV[j]]
	})
	sort.Slice(task.orderC, func(i, j int) bool {
		return task.B[task.orderC[i]] < task.B[task.orderC[j]]
	})
	v := 0
	c := 0
	for v < n || c < m {
		for v < n && (c == m || task.R[task.orderV[v]] <= task.B[task.orderC[c]]) {
			x := task.orderV[v]
			task.tree.update(task.mapper[task.L[x]], int64(task.R[x]-task.L[x])*int64(n)+int64(x))
			v++
		}
		for c < m && (v == n || task.B[task.orderC[c]] < task.R[task.orderV[v]]) {
			x := task.orderC[c]
			aux := task.tree.query(task.mapper[task.A[x]], task.mapper[task.B[x]])
			length := int(aux/n)
			y := int(aux % n)
			if length > task.max[x] {
				task.max[x] = length
				task.best[x] = y
			}
			c++
		}
	}
}

func (task *Task) process3(n, m int) {
	v := n - 1
	c := m - 1
	ret := math.MaxInt32
	idx := -1
	x := 0
	for v >= 0 || c >= 0 {
		for v >= 0 && (c == -1 || task.R[task.orderV[v]] >= task.B[task.orderC[c]]) {
			x = task.orderV[v]
			if task.L[x] < ret {
				ret = task.L[x]
				idx = x
			}
			v--
		}
		for c >= 0 && (v == -1 || task.B[task.orderC[c]] > task.R[task.orderV[v]]) {
			x = task.orderC[c]
			length := task.B[x] - int(math.Max(float64(ret), float64(task.A[x])))
			if length > task.max[x] {
				task.max[x] = length
				task.best[x] = idx
			}
			c--
		}
	}
}

func main() {
	in := NewInputReader()
	out := NewOutputWriter()
	defer out.flush()
	task := &Task{}
	task.solve(1, in, out)
}

func IOUtils_id12(in *InputReader, arrays ...[]int) {
	for i := 0; i < len(arrays[0]); i++ {
		for j := 0; j < len(arrays); j++ {
			arrays[j][i] = in.readInt()
		}
	}
}
