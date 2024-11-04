package main

import (
	"fmt"
	"math/big"
	"sort"
)

type Fraction struct {
	a, b int64
}

func (f Fraction) Less(rhs Fraction) bool {
	return f.a*rhs.b < rhs.a*f.b
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func solve() {
	var n, w int64
	fmt.Scan(&n, &w)
	FI := make([][2]Fraction, n)

	for i := int64(0); i < n; i++ {
		var a, b int64
		fmt.Scan(&a, &b)
		Left := Fraction{-a, b - w}
		Right := Fraction{-a, b + w}

		hoge := gcd(abs(Left.a), abs(Left.b))
		Left.a /= hoge
		Left.b /= hoge

		hoge = gcd(abs(Right.a), abs(Right.b))
		Right.a /= hoge
		Right.b /= hoge

		if Left.b < 0 {
			Left.a *= -1
			Left.b *= -1
		}
		if Right.b < 0 {
			Right.a *= -1
			Right.b *= -1
		}
		Right.a *= -1
		FI[i] = [2]Fraction{Left, Right}
	}

	sort.Slice(FI, func(i, j int) bool {
		return FI[i][0].Less(FI[j][0])
	})

	ans := int64(0)
	zip := NewCompressor()
	seg := NewSegmentTree(2 * n)

	for _, pair := range FI {
		pair[1].a *= -1
		zip.Add(pair[1])
	}

	zip.Exec()

	for _, pair := range FI {
		hoge := zip.Fetch()
		ans += seg.Query(hoge, 2*n)
		tmp := seg.Get(hoge)
		seg.Update(hoge, tmp+1)
	}

	fmt.Println(ans)
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

type Compressor struct {
	isZipped bool
	zipper   map[Fraction]int64
	unzipper map[int64]Fraction
	fetcher  []Fraction
}

func NewCompressor() *Compressor {
	return &Compressor{
		isZipped: false,
		zipper:   make(map[Fraction]int64),
		unzipper: make(map[int64]Fraction),
		fetcher:  []Fraction{},
	}
}

func (c *Compressor) Add(now Fraction) {
	if c.isZipped {
		panic("Already zipped")
	}
	c.zipper[now] = 1
	c.fetcher = append(c.fetcher, now)
}

func (c *Compressor) Exec() {
	if c.isZipped {
		panic("Already zipped")
	}
	cnt := int64(0)
	for k := range c.zipper {
		c.zipper[k] = cnt
		c.unzipper[cnt] = k
		cnt++
	}
	c.isZipped = true
}

func (c *Compressor) Fetch() int64 {
	if !c.isZipped {
		panic("Not zipped")
	}
	hoge := c.fetcher[0]
	c.fetcher = c.fetcher[1:]
	return c.zipper[hoge]
}

func (c *Compressor) Zip(now Fraction) int64 {
	if !c.isZipped {
		panic("Not zipped")
	}
	return c.zipper[now]
}

func (c *Compressor) Unzip(a int64) Fraction {
	if !c.isZipped {
		panic("Not zipped")
	}
	return c.unzipper[a]
}

type SegmentTree struct {
	data []int64
	size int64
}

func NewSegmentTree(n int64) *SegmentTree {
	size := int64(1)
	for size < n {
		size <<= 1
	}
	data := make([]int64, 2*size)
	return &SegmentTree{data: data, size: size}
}

func (st *SegmentTree) Update(k, x int64) {
	st.data[k+st.size] = x
	for k >>= 1; k > 0; k >>= 1 {
		st.data[k] = st.data[2*k] + st.data[2*k+1]
	}
}

func (st *SegmentTree) Query(a, b int64) int64 {
	L, R := int64(0), int64(0)
	for a += st.size; a < b+st.size; a >>= 1 {
		if a&1 != 0 {
			L += st.data[a]
			a++
		}
	}
	for b += st.size; a < b; b >>= 1 {
		if b&1 != 0 {
			R += st.data[b-1]
			b--
		}
	}
	return L + R
}

func (st *SegmentTree) Get(k int64) int64 {
	return st.data[k+st.size]
}

func main() {
	solve()
}
