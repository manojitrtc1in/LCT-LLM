package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func scanInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func scanInt64() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}

func print(a ...interface{}) {
	fmt.Fprint(writer, a...)
}

func println(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}

type modint struct {
	val int
}

func newModint(x int) modint {
	return modint{x}
}

func (a modint) add(b modint) modint {
	return modint{(a.val + b.val) % mod}
}

func (a modint) sub(b modint) modint {
	return modint{(a.val - b.val + mod) % mod}
}

func (a modint) mul(b modint) modint {
	return modint{(a.val * b.val) % mod}
}

func (a modint) pow(n int64) modint {
	res := modint{1}
	for n > 0 {
		if n&1 == 1 {
			res = res.mul(a)
		}
		a = a.mul(a)
		n >>= 1
	}
	return res
}

func (a modint) inv() modint {
	return a.pow(int64(mod - 2))
}

func (a modint) div(b modint) modint {
	return a.mul(b.inv())
}

func (a modint) equal(b modint) bool {
	return a.val == b.val
}

type id2 struct {
	n    int
	log  int
	size int
	laz  []modint
}

func newID2(n int) *id2 {
	log := 1
	for (1 << log) < n {
		log++
	}
	size := 1 << log
	laz := make([]modint, size<<1)
	for i := range laz {
		laz[i] = newModint(0)
	}
	return &id2{n, log, size, laz}
}

func (seg *id2) reset() {
	for i := range seg.laz {
		seg.laz[i] = newModint(0)
	}
}

func (seg *id2) allApply(k int, a modint) {
	seg.laz[k] = seg.laz[k].add(a)
}

func (seg *id2) get(p int) modint {
	p += seg.size
	for i := seg.log; i >= 1; i-- {
		seg.push(p >> i)
	}
	return seg.laz[p]
}

func (seg *id2) getAll() []modint {
	for i := 0; i < seg.size; i++ {
		seg.push(i)
	}
	return seg.laz[seg.size : seg.size+seg.n]
}

func (seg *id2) apply(l, r int, a modint) {
	if l == r {
		return
	}

	l += seg.size
	r += seg.size

	if true {
		for i := seg.log; i >= 1; i-- {
			if ((l >> i) << i) != l {
				seg.push(l >> i)
			}
			if ((r >> i) << i) != r {
				seg.push((r - 1) >> i)
			}
		}
	}

	{
		l2, r2 := l, r
		for l < r {
			if l&1 == 1 {
				seg.allApply(l, a)
				l++
			}
			if r&1 == 1 {
				r--
				seg.allApply(r, a)
			}
			l >>= 1
			r >>= 1
		}
		l = l2
		r = r2
	}
}

func (seg *id2) push(k int) {
	seg.allApply(2*k, seg.laz[k])
	seg.allApply(2*k+1, seg.laz[k])
	seg.laz[k] = newModint(0)
}

type groupAdd struct{}

func (groupAdd) op(x, y modint) modint {
	return x.add(y)
}

func (groupAdd) inverse(x modint) modint {
	return newModint(-x.val)
}

func (groupAdd) power(x modint, n int64) modint {
	return x.mul(newModint(int(n)))
}

func (groupAdd) unit() modint {
	return newModint(0)
}

func (groupAdd) commute() bool {
	return true
}

const mod = 1000000007

func solve() {
	N := scanInt()
	id2 := newID2(N + 1)

	dp := make([]modint, N+1)
	dp[1] = newModint(1)
	for n := 1; n <= N; n++ {
		dp[n] = dp[n].add(id2.get(n))
		id2.apply(n+1, N+1, dp[n])
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
			id2.apply(l, r, dp[n])
		}
	}

	println(dp[N].val)
}

func main() {
	initIO()

	T := 1
	for i := 0; i < T; i++ {
		solve()
	}

	flush()
}
