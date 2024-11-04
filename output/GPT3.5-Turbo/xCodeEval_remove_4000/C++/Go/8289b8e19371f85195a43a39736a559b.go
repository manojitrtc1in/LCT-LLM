package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func readString() string {
	if !scanner.Scan() {
		panic("unable to read string")
	}
	return scanner.Text()
}

func readInt() int {
	s := readString()
	n, err := strconv.Atoi(s)
	if err != nil {
		panic("unable to read int")
	}
	return n
}

func readInt64() int64 {
	s := readString()
	n, err := strconv.ParseInt(s, 10, 64)
	if err != nil {
		panic("unable to read int64")
	}
	return n
}

func readFloat64() float64 {
	s := readString()
	n, err := strconv.ParseFloat(s, 64)
	if err != nil {
		panic("unable to read float64")
	}
	return n
}

func readStringSlice(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = readString()
	}
	return s
}

func readIntSlice(n int) []int {
	s := make([]int, n)
	for i := 0; i < n; i++ {
		s[i] = readInt()
	}
	return s
}

func readInt64Slice(n int) []int64 {
	s := make([]int64, n)
	for i := 0; i < n; i++ {
		s[i] = readInt64()
	}
	return s
}

func readFloat64Slice(n int) []float64 {
	s := make([]float64, n)
	for i := 0; i < n; i++ {
		s[i] = readFloat64()
	}
	return s
}

func printString(s string) {
	fmt.Fprint(writer, s)
}

func printInt(n int) {
	fmt.Fprint(writer, n)
}

func printInt64(n int64) {
	fmt.Fprint(writer, n)
}

func printFloat64(n float64) {
	fmt.Fprint(writer, n)
}

func printlnString(s string) {
	fmt.Fprintln(writer, s)
}

func printlnInt(n int) {
	fmt.Fprintln(writer, n)
}

func printlnInt64(n int64) {
	fmt.Fprintln(writer, n)
}

func printlnFloat64(n float64) {
	fmt.Fprintln(writer, n)
}

func main() {
	defer flush()

	N := readInt()
	mod := readInt()

	type mint struct {
		val int
	}

	mint.setMod := func(md int) {
		mint.mod = md
	}

	mint.getMod := func() int {
		return mint.mod
	}

	mint.add := func(a, b mint) mint {
		return mint{(a.val + b.val) % mint.getMod()}
	}

	mint.sub := func(a, b mint) mint {
		return mint{(a.val - b.val + mint.getMod()) % mint.getMod()}
	}

	mint.mul := func(a, b mint) mint {
		return mint{(a.val * b.val) % mint.getMod()}
	}

	mint.pow := func(a mint, n int64) mint {
		res := mint{1}
		for n > 0 {
			if n&1 == 1 {
				res = mint.mul(res, a)
			}
			a = mint.mul(a, a)
			n >>= 1
		}
		return res
	}

	mint.inv := func(a mint) mint {
		return mint.pow(a, int64(mint.getMod())-2)
	}

	mint.fact := func(n int) mint {
		res := mint{1}
		for i := 2; i <= n; i++ {
			res = mint.mul(res, mint{i})
		}
		return res
	}

	mint.factInv := func(n int) mint {
		res := mint.inv(mint.fact(n))
		return res
	}

	mint.C := func(n, k int) mint {
		if k < 0 || n < k {
			return mint{0}
		}
		res := mint.fact(n)
		res = mint.mul(res, mint.factInv(k))
		res = mint.mul(res, mint.factInv(n-k))
		return res
	}

	mint.CInv := func(n, k int) mint {
		if k < 0 || n < k {
			return mint{0}
		}
		res := mint.factInv(n)
		res = mint.mul(res, mint.fact(k))
		res = mint.mul(res, mint.fact(n-k))
		return res
	}

	type GroupAdd struct {
		X int
	}

	GroupAdd.op := func(x, y GroupAdd) GroupAdd {
		return GroupAdd{x + y}
	}

	GroupAdd.inverse := func(x GroupAdd) GroupAdd {
		return GroupAdd{-x}
	}

	GroupAdd.power := func(x GroupAdd, n int64) GroupAdd {
		return GroupAdd{x * n}
	}

	GroupAdd.unit := func() GroupAdd {
		return GroupAdd{0}
	}

	GroupAdd.commute := true

	type id2 struct {
		n    int
		log  int
		size int
		laz  []GroupAdd
	}

	id2.new := func(n int) id2 {
		log := 1
		for 1<<log < n {
			log++
		}
		size := 1 << log
		laz := make([]GroupAdd, size<<1)
		for i := range laz {
			laz[i] = GroupAdd.unit()
		}
		return id2{n, log, size, laz}
	}

	id2.reset := func(seg *id2) {
		for i := range seg.laz {
			seg.laz[i] = GroupAdd.unit()
		}
	}

	id2.allApply := func(seg *id2, k int, a GroupAdd) {
		seg.laz[k] = GroupAdd.op(seg.laz[k], a)
	}

	id2.get := func(seg *id2, p int) GroupAdd {
		p += seg.size
		for i := seg.log; i >= 1; i-- {
			id2.push(seg, p>>i)
		}
		return seg.laz[p]
	}

	id2.getAll := func(seg *id2) []GroupAdd {
		for i := 0; i < seg.size; i++ {
			id2.push(seg, i)
		}
		return seg.laz[seg.size : seg.size+seg.n]
	}

	id2.apply := func(seg *id2, l, r int, a GroupAdd) {
		if l == r {
			return
		}

		l += seg.size
		r += seg.size

		if !GroupAdd.commute {
			for i := seg.log; i >= 1; i-- {
				if (l>>i)<<i != l {
					id2.push(seg, l>>i)
				}
				if ((r-1)>>i)<<i != r-1 {
					id2.push(seg, (r-1)>>i)
				}
			}
		}

		{
			l2 := l
			r2 := r
			for l < r {
				if l&1 == 1 {
					id2.allApply(seg, l, a)
					l++
				}
				if r&1 == 1 {
					r--
					id2.allApply(seg, r, a)
				}
				l >>= 1
				r >>= 1
			}
			l = l2
			r = r2
		}
	}

	id2.push := func(seg *id2, k int) {
		id2.allApply(seg, 2*k, seg.laz[k])
		id2.allApply(seg, 2*k+1, seg.laz[k])
		seg.laz[k] = GroupAdd.unit()
	}

	N := N
	mod := mod

	seg := id2.new(N + 1)
	id2.apply(&seg, 1, 2, GroupAdd{1})

	for n := 1; n <= N; n++ {
		dp := id2.get(&seg, n)
		id2.apply(&seg, n+1, N+1, dp)
		z := 2
		for {
			l := n * z
			r := (n + 1) * z
			if l > N {
				break
			}
			z++
			if r > N+1 {
				r = N + 1
			}
			id2.apply(&seg, l, r, dp)
		}
	}

	res := id2.get(&seg, N)
	printlnInt(res.X)
}
