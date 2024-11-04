package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

type IntList []int

func (list IntList) Len() int {
	return len(list)
}

func (list IntList) Less(i, j int) bool {
	return list[i] < list[j]
}

func (list IntList) Swap(i, j int) {
	list[i], list[j] = list[j], list[i]
}

func (list *IntList) Add(value int) {
	*list = append(*list, value)
}

func (list IntList) Sort() {
	sort.Sort(list)
}

func (list IntList) Get(index int) int {
	return list[index]
}

func (list *IntList) Set(index, value int) {
	(*list)[index] = value
}

type IntArrayList struct {
	data []int
}

func NewIntArrayList() *IntArrayList {
	return &IntArrayList{}
}

func (list *IntArrayList) Add(value int) {
	list.data = append(list.data, value)
}

func (list *IntArrayList) Get(index int) int {
	return list.data[index]
}

func (list *IntArrayList) Set(index, value int) {
	list.data[index] = value
}

func (list *IntArrayList) Size() int {
	return len(list.data)
}

type IntComparator func(a, b int) int

type TaskC struct{}

func (solver *TaskC) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	x := in.ReadInt()
	k := in.ReadInt()
	n := in.ReadInt()
	q := in.ReadInt()
	c := make([]int, k)
	for i := 0; i < k; i++ {
		c[i] = in.ReadInt()
	}
	p := NewIntArrayList()
	w := NewIntArrayList()
	for i := 0; i < q; i++ {
		p.Add(in.ReadInt())
		w.Add(in.ReadInt())
	}
	orderBy(p, w)
	decreaseByOne(p.data)
	id := make([]int, 1<<k)
	byId := make([]int, 1<<k)
	size := 0
	for i := 0; i < (1 << k); i++ {
		if bitCount(i) == x {
			id[i] = size
			byId[size] = i
			size++
		}
	}
	baseMat := make([][]int64, size)
	for i := 0; i < size; i++ {
		baseMat[i] = make([]int64, size)
		for j := 0; j < size; j++ {
			baseMat[i][j] = 1<<63 - 1
		}
	}
	specMat := make([][][]int64, q)
	for i := 0; i < q; i++ {
		specMat[i] = make([][]int64, size)
		for j := 0; j < size; j++ {
			specMat[i][j] = make([]int64, size)
			for k := 0; k < size; k++ {
				specMat[i][j][k] = 1<<63 - 1
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
						specMat[l][id[ii]][id[ni+(1<<j)]] = int64(c[j] + w.Get(l))
					}
				}
			}
		}
	}
	current := make([][]int64, size)
	makeOne(current)
	temp := make([][]int64, size)
	temp1 := make([][]int64, size)
	temp2 := make([][]int64, size)
	start := 0
	for i := 0; i <= q; i++ {
		stop := n - x
		if i < q {
			stop = min(stop, p.Get(i))
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
		if p.Get(i) >= n-x {
			answer += int64(w.Get(i))
		}
	}
	out.PrintLine(answer)
}

func bitCount(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func makeOne(current [][]int64) {
	for i := 0; i < len(current); i++ {
		for j := 0; j < len(current); j++ {
			if i == j {
				current[i][j] = 0
			} else {
				current[i][j] = 1<<63 - 1
			}
		}
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
	for i := 0; i < len(c); i++ {
		for j := 0; j < len(c); j++ {
			c[i][j] = 1<<63 - 1
			for k := 0; k < len(c); k++ {
				if a[i][k] != 1<<63-1 && b[k][j] != 1<<63-1 {
					c[i][j] = min(c[i][j], a[i][k]+b[k][j])
				}
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

func orderBy(base, array *IntArrayList) {
	order(array, base)
}

func order(order *IntArrayList, array *IntArrayList) {
	temp := make([]int, len(*order))
	for i := 0; i < len(*order); i++ {
		temp[i] = array.Get((*order).Get(i))
	}
	for i := 0; i < len(*order); i++ {
		array.Set(i, temp[i])
	}
}

func decreaseByOne(array *IntArrayList) {
	for i := 0; i < array.Size(); i++ {
		array.Set(i, array.Get(i)-1)
	}
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(reader io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(reader)}
}

func (in *InputReader) ReadInt() int {
	var x int
	_, _ = fmt.Fscan(in.reader, &x)
	return x
}

func (in *InputReader) ReadIntArrays(arrays ...*IntArrayList) {
	for i := 0; i < arrays[0].Size(); i++ {
		for j := 0; j < len(arrays); j++ {
			arrays[j].Set(i, in.ReadInt())
		}
	}
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(writer io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(writer)}
}

func (out *OutputWriter) PrintLine(i int64) {
	_, _ = fmt.Fprintln(out.writer, i)
}

func (out *OutputWriter) Flush() {
	_ = out.writer.Flush()
}

func main() {
	input := NewInputReader(os.Stdin)
	output := NewOutputWriter(os.Stdout)
	solver := &TaskC{}
	solver.Solve(1, input, output)
	output.Flush()
}
