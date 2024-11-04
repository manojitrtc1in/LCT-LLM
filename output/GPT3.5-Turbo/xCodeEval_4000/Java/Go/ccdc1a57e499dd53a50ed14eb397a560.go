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
		in.buf = make([]byte, 1024)
		n, _ := in.reader.Read(in.buf)
		if n == 0 {
			return 0
		}
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
	writer *bufio.Writer
}

func NewOutputWriter() *OutputWriter {
	return &OutputWriter{}
}

func (out *OutputWriter) print(args ...interface{}) {
	for _, arg := range args {
		out.writer.WriteString(fmt.Sprint(arg))
	}
}

func (out *OutputWriter) println(args ...interface{}) {
	out.print(args...)
	out.writer.WriteByte('\n')
}

func (out *OutputWriter) flush() {
	out.writer.Flush()
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
	orderV, orderC           []int
	tree                     *IntervalTree
	mapper                   map[int]int
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
	for i := 0; i < n; i++ {
		task.orderV[i] = i
	}
	for i := 0; i < m; i++ {
		task.orderC[i] = i
	}
	task.L = in.readIntArray(n)
	task.R = in.readIntArray(n)
	task.A = in.readIntArray(m)
	task.B = in.readIntArray(m)
	task.C = in.readIntArray(m)
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
	out.println(ret)
	if ret > 0 {
		out.println(task.best[aux]+1, aux+1)
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
			y := int(aux % int64(n))
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
	task := &Task{}
	task.solve(1, in, out)
	out.flush()
}
