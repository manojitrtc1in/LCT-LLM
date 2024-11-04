package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
	"sort"
)

const mod = 1e9 + 7
const mod1 = 998244353

type FastIO struct {
	buf    bytes.Buffer
	reader io.Reader
	writer io.Writer
}

func NewFastIO(r io.Reader, w io.Writer) *FastIO {
	return &FastIO{reader: r, writer: w}
}

func (f *FastIO) ReadInt() int {
	var x int
	fmt.Fscan(f.reader, &x)
	return x
}

func (f *FastIO) ReadInts(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = f.ReadInt()
	}
	return arr
}

func (f *FastIO) WriteInt(x int) {
	fmt.Fprint(f.writer, x)
}

func binarySearchCount(arr []int, n, key int) int {
	left, right := 0, n-1
	count := 0

	for left <= right {
		mid := (right + left) / 2
		if arr[mid] <= key {
			count = mid + 1
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return count
}

func main() {
	fastIO := NewFastIO(os.Stdin, os.Stdout)

	n, k := fastIO.ReadInt(), fastIO.ReadInt()
	l := fastIO.ReadInts(n)

	for i := 0; i < n; i++ {
		l[i] = l[i] % k
	}

	if n == 1 {
		fastIO.WriteInt(l[0])
		return
	}

	l1 := l[:n/2]
	l2 := l[n/2:]

	s := make(map[int]struct{})
	s1 := make(map[int]struct{})
	s2 := make(map[int]struct{})

	for _, v := range l1 {
		for j := range s {
			s2[(j+v)%k] = struct{}{}
		}
		s[v] = struct{}{}
		for j := range s2 {
			s[j] = struct{}{}
		}
		s2 = make(map[int]struct{})
	}

	for _, v := range l2 {
		for j := range s1 {
			s2[(j+v)%k] = struct{}{}
		}
		s1[v] = struct{}{}
		for j := range s2 {
			s1[j] = struct{}{}
		}
		s2 = make(map[int]struct{})
	}

	sList := make([]int, 0, len(s))
	for k := range s {
		sList = append(sList, k)
	}
	sort.Ints(sList)

	s1List := make([]int, 0, len(s1))
	for k := range s1 {
		s1List = append(s1List, k)
	}
	sort.Ints(s1List)

	ans := max(max(sList...), max(s1List...))

	for _, v := range sList {
		t := k - 1 - v
		ind := binarySearchCount(s1List, len(s1List), t)
		r := s1List[ind-1]
		rt := s1List[len(s1List)-1]
		t = ans
		ans = max((r+v)%k, (v+rt)%k)
		ans = max(ans, t)
	}

	fastIO.WriteInt(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
