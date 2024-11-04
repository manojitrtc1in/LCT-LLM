package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
	"strings"
)

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(r)}
}

func (in *InputReader) ReadInt() int {
	num, _ := strconv.Atoi(in.readString())
	return num
}

func (in *InputReader) ReadLong() int64 {
	num, _ := strconv.ParseInt(in.readString(), 10, 64)
	return num
}

func (in *InputReader) ReadString() string {
	str, _ := in.reader.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *OutputWriter) Flush() {
	out.writer.Flush()
}

type Pair struct {
	first  int64
	second int64
}

type TreapSet struct {
	root         *Node
	comparator   func(a, b int64) bool
	size         int
	from, to     int64
	fromInclusive, toInclusive bool
}

type Node struct {
	key, priority int64
	left, right   *Node
	size          int
}

func NewTreapSet() *TreapSet {
	return &TreapSet{
		root:       nil,
		comparator: nil,
		size:       0,
		from:       0,
		to:         0,
		fromInclusive: false,
		toInclusive:   false,
	}
}

func NewTreapSetWithComparator(comparator func(a, b int64) bool) *TreapSet {
	return &TreapSet{
		root:       nil,
		comparator: comparator,
		size:       0,
		from:       0,
		to:         0,
		fromInclusive: false,
		toInclusive:   false,
	}
}

func (t *TreapSet) AddAll(collection []int64) bool {
	result := false
	for _, element := range collection {
		result = result || t.Add(element)
	}
	return result
}

func (t *TreapSet) Lower(k int64) int64 {
	target := t.root.Lower(k)
	if target == nil {
		return math.MinInt64
	}
	if t.Belongs(target.key) {
		return target.key
	}
	return math.MinInt64
}

func (t *TreapSet) Floor(k int64) int64 {
	target := t.root.Floor(k)
	if target == nil {
		return math.MinInt64
	}
	if t.Belongs(target.key) {
		return target.key
	}
	return math.MinInt64
}

func (t *TreapSet) Ceiling(k int64) int64 {
	target := t.root.Ceil(k)
	if target == nil {
		return math.MinInt64
	}
	if t.Belongs(target.key) {
		return target.key
	}
	return math.MinInt64
}

func (t *TreapSet) Higher(k int64) int64 {
	target := t.root.Higher(k)
	if target == nil {
		return math.MinInt64
	}
	if t.Belongs(target.key) {
		return target.key
	}
	return math.MinInt64
}

func (t *TreapSet) PollFirst() int64 {
	first := t.First()
	if first == math.MinInt64 {
		panic("Set is empty")
	}
	t.root = t.root.Erase(first)
	return first
}

func (t *TreapSet) PollLast() int64 {
	last := t.Last()
	if last == math.MinInt64 {
		panic("Set is empty")
	}
	t.root = t.root.Erase(last)
	return last
}

func (t *TreapSet) Size() int {
	if t.from == 0 && t.to == 0 {
		return t.root.Size
	}
	if t.from == 0 {
		to := t.root.Floor(t.to)
		if to == nil {
			return 0
		}
		return t.root.IndexOf(to) + 1
	}
	if t.to == 0 {
		from := t.root.Ceil(t.from)
		if from == nil {
			return 0
		}
		return t.root.Size - t.root.IndexOf(from)
	}
	from := t.root.Ceil(t.from)
	if from == nil || !t.Belongs(from.key) {
		return 0
	}
	to := t.root.Floor(t.to)
	return t.root.IndexOf(to) - t.root.IndexOf(from) + 1
}

func (t *TreapSet) IsEmpty() bool {
	return t.Size() == 0
}

func (t *TreapSet) Contains(o int64) bool {
	return t.Belongs(o) && t.root.Search(o) != nil
}

func (t *TreapSet) Iterator() *Iterator {
	return &Iterator{
		current: t.First(),
		set:     t,
	}
}

func (t *TreapSet) ToArray() []int64 {
	array := make([]int64, t.Size())
	index := 0
	for it := t.Iterator(); it.HasNext(); {
		array[index] = it.Next()
		index++
	}
	return array
}

func (t *TreapSet) Add(k int64) bool {
	if t.Contains(k) {
		return false
	}
	t.root = t.root.Insert(t.CreateNode(k))
	return true
}

func (t *TreapSet) CreateNode(k int64) *Node {
	return &Node{
		key:      k,
		priority: rnd.Int63(),
		left:     nil,
		right:    nil,
		size:     1,
	}
}

func (t *TreapSet) Remove(o int64) bool {
	if !t.Contains(o) {
		return false
	}
	t.root = t.root.Erase(o)
	return true
}

func (t *TreapSet) ContainsAll(collection []int64) bool {
	for _, o := range collection {
		if !t.Contains(o) {
			return false
		}
	}
	return true
}

func (t *TreapSet) RetainAll(collection []int64) bool {
	toRemove := make([]int64, 0)
	for it := t.Iterator(); it.HasNext(); {
		element := it.Next()
		if !contains(collection, element) {
			toRemove = append(toRemove, element)
		}
	}
	return t.RemoveAll(toRemove)
}

func (t *TreapSet) RemoveAll(collection []int64) bool {
	result := false
	for _, o := range collection {
		result = result || t.Remove(o)
	}
	return result
}

func (t *TreapSet) Clear() {
	t.RetainAll([]int64{})
}

func (t *TreapSet) DescendingSet() *TreapSet {
	panic("Not implemented")
}

func (t *TreapSet) DescendingIterator() *Iterator {
	panic("Not implemented")
}

func (t *TreapSet) SubSet(fromElement, toElement int64, fromInclusive, toInclusive bool) *TreapSet {
	return &TreapSet{
		root:           t.root,
		comparator:     t.comparator,
		size:           t.size,
		from:           fromElement,
		to:             toElement,
		fromInclusive:  fromInclusive,
		toInclusive:    toInclusive,
	}
}

func (t *TreapSet) HeadSet(toElement int64, inclusive bool) *TreapSet {
	return t.SubSet(0, toElement, true, inclusive)
}

func (t *TreapSet) TailSet(fromElement int64, inclusive bool) *TreapSet {
	return t.SubSet(fromElement, 0, inclusive, true)
}

func (t *TreapSet) Comparator() func(a, b int64) bool {
	return t.comparator
}

func (t *TreapSet) First() int64 {
	if t.IsEmpty() {
		return math.MinInt64
	}
	if t.from == 0 {
		return t.root.First().key
	}
	if t.fromInclusive {
		return t.Ceiling(t.from)
	}
	return t.Higher(t.from)
}

func (t *TreapSet) Last() int64 {
	if t.IsEmpty() {
		return math.MinInt64
	}
	if t.to == 0 {
		return t.root.Last().key
	}
	if t.toInclusive {
		return t.Floor(t.to)
	}
	return t.Lower(t.to)
}

func (t *TreapSet) Belongs(key int64) bool {
	valueFrom := compare(t.from, key)
	valueTo := compare(key, t.to)
	return (valueFrom < 0 || (valueFrom == 0 && t.fromInclusive)) &&
		(valueTo < 0 || (valueTo == 0 && t.toInclusive))
}

func compare(a, b int64) int {
	if a < b {
		return -1
	}
	if a > b {
		return 1
	}
	return 0
}

type Iterator struct {
	current int64
	set     *TreapSet
}

func (it *Iterator) HasNext() bool {
	return it.current != math.MinInt64
}

func (it *Iterator) Next() int64 {
	result := it.current
	it.current = it.set.Higher(it.current)
	return result
}

func contains(slice []int64, element int64) bool {
	for _, value := range slice {
		if value == element {
			return true
		}
	}
	return false
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)

	A := in.ReadLong()
	divides := make(map[int64][]int64)
	for i := int64(1); i*i <= A; i++ {
		if A%i == 0 {
			process(i, divides)
			if i*i != A {
				process(A/i, divides)
			}
		}
	}

	dp := make([][]int64, 2)
	dp[0] = make([]int64, len(divides))
	dp[1] = make([]int64, len(divides))

	dp[0][0] = 1
	idx := 0
	for i, div := range divides {
		idx ^= 1
		for j := range dp[idx] {
			dp[idx][j] = dp[idx^1][j]
			for _, x := range div {
				if divides[j]%x == 0 {
					dp[idx][j] += dp[idx^1][divides[j]/x]
				}
			}
		}
	}

	out.Println(dp[idx][len(divides)-1])
	out.Flush()
}
