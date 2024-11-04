package main

import (
	"bufio"
	"bytes"
	"fmt"
	"index/suffixarray"
	"log"
	"math"
	"net"
	"os"
	"path"
	"sort"
	"strconv"
	"strings"
	"time"
)





func main() {
	io := id2()
	defer io.Flush()
	for T := io.ScanUInt16(); T > 0; T-- {
		solve(&io)
	}
}
func solve(io *IO) {
	n := io.ScanInt32()
	m := io.ScanInt32()
	adj := make(map[int32]*SingleLinkedList[int32, uint32])
	for i := int32(0); i < n; i++ {
		adj[i] = id1[int32, uint32]()
	}
	for i := int32(0); i < m; i++ {
		a := io.ScanInt32() - 1
		b := io.ScanInt32() - 1
		adj[a].InsertLast(b)
		adj[b].InsertLast(a)
	}
	Nfrends := io.ScanInt32()
	friends := make([]int32, Nfrends)
	for i := int32(0); i < Nfrends; i++ {
		tmp := io.ScanInt32() - 1
		friends[i] = tmp
	}
	NfriendsWithoutCar := io.ScanUInt8()
	friendsWithoutCar := make([]int32, NfriendsWithoutCar+1)
	for i := uint8(0); i < NfriendsWithoutCar; i++ {
		tmp := io.ScanInt32() - 1
		friendsWithoutCar[i] = tmp
	}
	friendsWithoutCar[NfriendsWithoutCar] = -1
	dist := make([]int32, n)
	masks := make([]uint8, n)
	for k, _ := range dist {
		dist[k] = -1
	}
	dist[0] = 0
	dfs := NewQueue[int32, uint32]()
	dfs.Enqueue(0)
	for i := uint8(0); i < NfriendsWithoutCar; i++ {
		masks[friends[friendsWithoutCar[i]]] += 1 << i
	}

	path := make([]*Set[uint8], n)
	for i, _ := range path {
		path[i] = NewSet[uint8]()
	}
	path[0].Add(0)
	for dfs.Len() > 0 {
		tmp := dfs.Dequeue()
		next := adj[tmp].ToSlice()
		for i := 0; i < len(next); i++ {
			if dist[next[i]] == -1 {
				dist[next[i]] = dist[tmp] + 1
				dfs.Enqueue(next[i])
			}
			if dist[next[i]] == dist[tmp]+1 {
				tmp2 := path[tmp].ToSlice()
				for _, p := range tmp2 {
					path[next[i]].Add(masks[next[i]] | p)
				}
			}
		}
	}

	dp := make([]bool, 1<<NfriendsWithoutCar)
	j := 0
	dp[0] = true

	for i := int32(0); i < Nfrends; i++ {
		if i == friendsWithoutCar[j] {
			j++
			continue
		}
		dpCopy := make([]bool, len(dp))
		copy(dpCopy, dp)

		for m := uint8(0); m < 1<<NfriendsWithoutCar; m++ {
			if dp[m] {
				paths := path[friends[i]].ToSlice()
				for _, p := range paths {
					dpCopy[p|m] = true
				}
			}
		}
		dp = dpCopy

	}
	min := NfriendsWithoutCar
	for m := uint8(0); m < 1<<NfriendsWithoutCar; m++ {
		if dp[m] {
			c := uint8(0)
			for i := uint8(0); i < NfriendsWithoutCar; i++ {
				if m&(1<<i) == 0 {
					c++
				}
			}
			min = Min(min, c)
		}
	}
	io.PrintLn(min)
}






type Signed interface {
	~int | ~int8 | ~int16 | ~int32 | ~int64
}
type Unsigned interface {
	~uint | ~uint8 | ~uint16 | ~uint32 | ~uint64 | ~uintptr
}
type Integer interface {
	Signed | Unsigned
}
type Float interface {
	~float32 | ~float64
}
type Complex interface {
	~complex64 | ~complex128
}
type Ordered interface {
	Integer | Float | ~string
}

type Prioritizable[T any] interface {
	PriorTo(x T) bool 

}







type singleLinkedListNode[T comparable] struct {
	Value T
	Next  *singleLinkedListNode[T]
}

type SingleLinkedList[T comparable, IndexType Unsigned] struct {
	first  *singleLinkedListNode[T]
	last   *singleLinkedListNode[T]
	length IndexType
}

func id1[T comparable, IndexType Unsigned]() *SingleLinkedList[T, IndexType] {
	return &SingleLinkedList[T, IndexType]{
		first:  nil,
		last:   nil,
		length: 0,
	}
}
func (l *SingleLinkedList[T, I]) Len() I { return l.length }



func (l *SingleLinkedList[T, I]) First() T { return l.first.Value }



func (l *SingleLinkedList[T, I]) Last() T { return l.last.Value }

func (l *SingleLinkedList[T, I]) InsertFirst(value T) {
	if l.length == 0 {
		nodeToInsert := &singleLinkedListNode[T]{
			Value: value,
			Next:  l.first,
		}
		l.first = nodeToInsert
		l.last = nodeToInsert
	} else {
		l.first = &singleLinkedListNode[T]{
			Value: value,
			Next:  l.first,
		}
	}
	l.length++
}

func (l *SingleLinkedList[T, I]) InsertLast(value T) {
	if l.length == 0 {
		nodeToInsert := &singleLinkedListNode[T]{
			Value: value,
			Next:  l.first,
		}
		l.first = nodeToInsert
		l.last = nodeToInsert
	} else {
		l.last.Next = &singleLinkedListNode[T]{
			Value: value,
			Next:  nil,
		}
		l.last = l.last.Next
	}
	l.length++
}



func (l *SingleLinkedList[T, I]) InsertAt(index I, value T) {
	if index == 0 {
		l.InsertFirst(value)
		return
	}
	if index == l.length {
		l.InsertLast(value)
		return
	}

	n := l.first
	for index > 1 {
		n = n.Next
		index--
	}
	n.Next = &singleLinkedListNode[T]{
		Value: value,
		Next:  n.Next,
	}
	l.length++
}

func (l *SingleLinkedList[T, I]) Contains(value T) bool {
	tmp := l.first
	for i := I(0); i < l.length; i++ {
		if tmp.Value == value {
			return true
		}
		tmp = tmp.Next
	}
	return false
}
func (l *SingleLinkedList[T, I]) Clear() {
	l.first = nil
	l.last = nil
	l.length = 0
}



func (l *SingleLinkedList[T, I]) GetElementAt(index I) T {
	n := l.first
	for index > 0 {
		n = n.Next
		index--
	}
	return n.Value
}



func (l *SingleLinkedList[T, I]) SetElementAt(index I, value T) {
	n := l.first
	for index > 0 {
		n = n.Next
		index--
	}
	n.Value = value
}

func (l *SingleLinkedList[T, I]) RemoveFirst() T {
	tmp := l.first
	l.first = l.first.Next
	l.length--
	if l.length == 0 {
		l.last = nil
	}
	return tmp.Value
}
func (l *SingleLinkedList[T, I]) RemoveLast() (value T) {
	value = l.last.Value
	if l.length == 1 {
		l.first = nil
		l.last = nil
		l.length = 0
		return
	}

	tmp := l.first
	for i := I(2); i < l.length; i++ {
		tmp = tmp.Next
	}
	l.last = tmp
	return
}

func (l *SingleLinkedList[T, I]) RemoveAt(index I) T {
	if index == 0 {
		return l.RemoveFirst()
	}
	if index == l.length-1 {
		return l.RemoveLast()
	}

	tmp := l.first
	for i := I(1); i < index; i++ {
		tmp = tmp.Next
	}
	res := tmp.Next.Value
	tmp.Next = tmp.Next.Next
	return res
}

func (l *SingleLinkedList[T, I]) ToSlice() (res []T) {
	res = make([]T, 0, l.length)
	tmp := l.first
	for i := I(0); i < l.length; i++ {
		res = append(res, tmp.Value)
		tmp = tmp.Next
	}
	return
}
func (it *SingleLinkedList[T, I]) String() string {
	return "Qua:: " + fmt.Sprint(it.ToSlice())
}






type Queue[T comparable, I Unsigned] struct {
	l SingleLinkedList[T, I]
}

func NewQueue[T comparable, I Unsigned]() *Queue[T, I] {
	return &Queue[T, I]{
		l: SingleLinkedList[T, I]{
			first:  nil,
			last:   nil,
			length: 0,
		},
	}
}
func (q *Queue[T, I]) Len() I          { return q.l.length }
func (q *Queue[T, I]) Enqueue(value T) { q.l.InsertLast(value) }
func (q *Queue[T, I]) Dequeue() T      { return q.l.RemoveFirst() }
func (q *Queue[T, I]) Preview() T      { return q.l.First() }
func (q *Queue[T, I]) String() string  { return q.l.String() }






type Stack[T comparable, I Unsigned] struct {
	l SingleLinkedList[T, I]
}

func NewStack[T comparable, I Unsigned]() *Stack[T, I] {
	return &Stack[T, I]{
		l: SingleLinkedList[T, I]{
			first:  nil,
			last:   nil,
			length: 0,
		},
	}
}
func (s *Stack[T, I]) Len() I         { return s.l.length }
func (s *Stack[T, I]) Push(value T)   { s.l.InsertFirst(value) }
func (s *Stack[T, I]) Pop() T         { return s.l.RemoveFirst() }
func (s *Stack[T, I]) Preview() T     { return s.l.First() }
func (s *Stack[T, I]) String() string { return s.l.String() }








type BinaryHeap[T Prioritizable[T], I Signed] struct {
	s []T
}

func id3[T Prioritizable[T], I Signed](s []T) (h *BinaryHeap[T, I]) {
	h = &BinaryHeap[T, I]{
		s: s,
	}

	for i := (h.Len() - 2) / 2; i >= 0; i-- {
		h.heapifyDown(i)
	}
	return
}
func (h *BinaryHeap[T, I]) Len() I {
	return I(len(h.s))
}
func (h *BinaryHeap[T, I]) Push(value T) {
	h.s = append(h.s, value)
	h.heapifyUp(h.Len() - 1)
}
func (h *BinaryHeap[T, I]) Pop() (res T) {
	res = h.s[0]
	h.s[0] = h.s[h.Len()-1]
	h.s = h.s[:h.Len()-1]
	h.heapifyDown(0)
	return
}

func (h *BinaryHeap[T, I]) heapifyDown(index I) bool {
	origin := index
	for {
		j := index*2 + 2
		if j < h.Len() {
			if h.s[j-1].PriorTo(h.s[j]) {
				j--
			}
		} else {
			if j <= h.Len() && !h.s[j].PriorTo(h.s[index]) {
				h.s[j], h.s[index] = h.s[index], h.s[j]
			}
			break
		}
		if h.s[j].PriorTo(h.s[index]) {
			h.s[j], h.s[index] = h.s[index], h.s[j]
			index = j
		} else {
			break
		}
	}
	return origin != index
}
func (h *BinaryHeap[T, I]) heapifyUp(index I) {
	for {
		parent := (index - 1) / 2
		if parent == index || h.s[parent].PriorTo(h.s[index]) {
			break
		}
		h.s[index], h.s[parent] = h.s[parent], h.s[index]
		index = parent
	}
}





type Set[T comparable] struct {
	l SingleLinkedList[T, uint64]
}

func NewSet[T comparable]() *Set[T] {
	return &Set[T]{l: *id1[T, uint64]()}
}
func (s *Set[T]) Add(element T) (added bool) {
	if !s.l.Contains(element) {
		s.l.InsertLast(element)
		return true
	} else {
		return false
	}
}
func (s *Set[T]) ToSlice() (res []T) {
	return s.l.ToSlice()
}
func (s *Set[T]) String() (res []T) {
	return s.l.ToSlice()
}






func Max[T Ordered](a, b T) T {
	if a >= b {
		return a
	}
	return b
}
func Min[T Ordered](a, b T) T {
	if a <= b {
		return a
	}
	return b
}
func Abs[T Integer | Float](a T) T {
	if a < 0 {
		return -a
	}
	return a
}
func Swap[T any](a, b *T) {
	*a, *b = *b, *a
}



func GCD[T Unsigned](a, b T) T {
	if b < a {
		Swap(&a, &b)
	}
	for {
		if a == 0 {
			return b
		}
		r := (b % a)
		b = a
		a = r
	}
}



func LCM[T Unsigned](a, b T) T {
	return (a * b) / GCD(a, b)
}

func First[T any](a T, _ any) T { return a }






type IO struct {
	r *bufio.Reader
	w *bufio.Writer
}

func id2() IO {
	return IO{
		r: bufio.NewReader(os.Stdin),
		w: bufio.NewWriter(os.Stdout),
	}
}



func id0() IO {
	return IO{
		r: bufio.NewReader(First(os.Open("input.txt"))),
		w: bufio.NewWriter(First(os.OpenFile("output.txt", os.O_CREATE|os.O_RDWR|os.O_TRUNC, os.ModePerm))),
	}
}

func (io *IO) ScanInt8() (x int8)   { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanInt16() (x int16) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanInt32() (x int32) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanInt64() (x int64) { fmt.Fscan(io.r, &x); return }

func (io *IO) ScanUInt8() (x uint8)   { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanUInt16() (x uint16) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanUInt32() (x uint32) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanUInt64() (x uint64) { fmt.Fscan(io.r, &x); return }

func (io *IO) ScanFloat32() (x float32) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanFloat64() (x float64) { fmt.Fscan(io.r, &x); return }

func (io *IO) ScanString() (x string) { fmt.Fscan(io.r, &x); return }

func (io *IO) Print(x ...any)   { fmt.Fprint(io.w, x...) }
func (io *IO) PrintLn(x ...any) { fmt.Fprintln(io.w, x...) }

func (io *IO) Flush() { io.w.Flush() }






func D() {
	_ = bufio.Reader{}
	_ = bytes.Buffer{}
	_ = suffixarray.Index{}
	_ = log.Default()
	_ = math.Abs(0)
	_ = net.Dialer{}
	_ = path.ErrBadPattern
	_ = sort.Float64sAreSorted(nil)
	_ = strconv.ErrRange
	_ = strings.Builder{}
	_ = time.ANSIC
	_ = id2()
	_ = id0()
}



