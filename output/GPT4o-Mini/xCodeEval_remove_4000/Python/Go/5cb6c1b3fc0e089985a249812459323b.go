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
	writer io.Writer
}

func NewFastIO(w io.Writer) *FastIO {
	return &FastIO{writer: w}
}

func (f *FastIO) ReadString() string {
	var s string
	fmt.Fscan(f.writer, &s)
	return s
}

func (f *FastIO) ReadInt() int {
	var n int
	fmt.Fscan(f.writer, &n)
	return n
}

func (f *FastIO) WriteString(s string) {
	f.buf.WriteString(s)
}

func (f *FastIO) WriteInt(n int) {
	f.buf.WriteString(fmt.Sprintf("%d", n))
}

func (f *FastIO) Flush() {
	f.writer.Write(f.buf.Bytes())
	f.buf.Reset()
}

func id9(arr []int, n int, key int) int {
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
	fastIO := NewFastIO(os.Stdout)
	defer fastIO.Flush()

	n := fastIO.ReadInt()
	k := fastIO.ReadInt()
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i] = fastIO.ReadInt() % k
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
		ind := id9(s1List, len(s1List), t)
		r := s1List[ind-1]
		rt := s1List[len(s1List)-1]
		t = ans
		ans = max((r+v)%k, (v+rt)%k)
		ans = max(ans, t)
	}

	fastIO.WriteInt(ans)
}

func max(a ...int) int {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}
