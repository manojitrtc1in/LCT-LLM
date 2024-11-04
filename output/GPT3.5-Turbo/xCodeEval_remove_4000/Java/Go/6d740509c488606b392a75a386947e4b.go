package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

var (
	mod = 998244353
	g   = 3
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n, k := readTwoInts(reader)
	allow := make([]int, 10)
	for i := 0; i < k; i++ {
		allow[readInt(reader)] = 1
	}

	p := make([]int, 10)
	for i := 0; i < 10; i++ {
		p[i] = allow[i]
	}

	m := n / 2
	last := make([]int, 10)
	copy(last, p)

	lists := make([][]int, 0)
	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, last)
		}
		proper := ceilLog(2 * len(last))
		last = expandWith(last, 0, 1<<proper)
		ntt(last, 1<<proper, false, mod, g)
		last = dotMul(last, last, last, proper)
		ntt(last, 1<<proper, true, mod, g)
		normalize(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := make([]int, len(last))
	id1(lists, prod)

	ans := 0
	for i := 0; i < len(prod); i++ {
		plus := prod[i]
		ans = plusMod(ans, mulMod(plus, plus, mod), mod)
	}

	fmt.Fprintln(writer, ans)
}

func ceilLog(x int) int {
	ans := floorLog(x)
	if 1<<ans < x {
		ans++
	}
	return ans
}

func floorLog(x int) int {
	if x < 1<<16 {
		return cache[x]
	}
	return 16 + cache[x>>16]
}

func plusMod(a, b, mod int) int {
	c := a + b
	if c >= mod {
		c -= mod
	}
	return c
}

func mulMod(a, b, mod int) int {
	return int(int64(a) * int64(b) % int64(mod))
}

func expandWith(a []int, x, len int) []int {
	n := len(a)
	if len <= n {
		return a
	}
	b := make([]int, len)
	copy(b, a)
	for i := n; i < len; i++ {
		b[i] = x
	}
	return b
}

func dotMul(a, b, c []int, m int) []int {
	n := 1 << m
	for i := 0; i < n; i++ {
		c[i] = mulMod(a[i], b[i], mod)
	}
	return c
}

func prepareReverse(r []int, b int) {
	n := 1 << b
	r[0] = 0
	for i := 1; i < n; i++ {
		r[i] = (r[i>>1] >> 1) | ((1 & i) << (b - 1))
	}
}

func dft(p []int, m int) {
	n := 1 << m

	rev := make([]int, 1<<m)
	prepareReverse(rev, m)

	for i := 0; i < n; i++ {
		if rev[i] > i {
			p[i], p[rev[i]] = p[rev[i]], p[i]
		}
	}

	w := 0
	t := 0
	for d := 0; d < m; d++ {
		w1 := wCache[d]
		s := 1 << d
		s2 := s << 1
		for i := 0; i < n; i += s2 {
			w = 1
			for j := 0; j < s; j++ {
				a := i + j
				b := a + s
				t = mulMod(w, p[b], mod)
				p[b] = plusMod(p[a], -t, mod)
				p[a] = plusMod(p[a], t, mod)
				w = mulMod(w, w1, mod)
			}
		}
	}
}

func idft(p []int, m int) {
	dft(p, m)

	n := 1 << m
	invN := invCache[m]

	p[0] = mulMod(p[0], invN, mod)
	p[n/2] = mulMod(p[n/2], invN, mod)
	for i := 1; i < n/2; i++ {
		a := p[n-i]
		p[n-i] = mulMod(p[i], invN, mod)
		p[i] = mulMod(a, invN, mod)
	}
}

func id1(lists [][]int, ans []int) {
	pqs := make(PriorityQueue, 0)
	for _, list := range lists {
		clone := make([]int, len(list))
		copy(clone, list)
		pqs = append(pqs, clone)
	}
	for len(pqs) > 1 {
		a := pqs.Pop().([]int)
		b := pqs.Pop().([]int)
		id10(a, b)
		pqs.Push(a)
	}
	last := pqs.Pop().([]int)
	copy(ans, last)
}

func id10(a, b []int) {
	rankAns := len(a) - 1 + len(b) - 1
	proper := ceilLog(rankAns + 1)
	a = expandWith(a, 0, 1<<proper)
	b = expandWith(b, 0, 1<<proper)
	dft(a, proper)
	dft(b, proper)
	dotMul(a, b, a, proper)
	idft(a, proper)
	normalize(a)
}

func ntt(a []int, n int, invert bool, mod int, root int) {
	shift := 32 - nlz(n)
	for i := 1; i < n; i++ {
		j := rev(i << shift)
		if i < j {
			a[i], a[j] = a[j], a[i]
		}
	}

	rootInv := pow(root, mod-2, mod)

	for len := 1; len < n; len <<= 1 {
		wlen := pow(root, (mod-1)/(2*len), mod)
		for i := 0; i < n; i += 2 * len {
			w := 1
			for j := 0; j < len; j++ {
				a := i + j
				b := a + len
				t := mulMod(w, a[b], mod)
				a[b] = plusMod(a[a], -t, mod)
				a[a] = plusMod(a[a], t, mod)
				w = mulMod(w, wlen, mod)
			}
		}
	}

	if invert {
		nrev := pow(n, mod-2, mod)
		for i := 0; i < n; i++ {
			a[i] = mulMod(a[i], nrev, mod)
		}
	}
}

func rev(x int) int {
	return revCache[x]
}

func pow(x, n, mod int) int {
	res := 1
	for p := x; n > 0; n >>= 1 {
		if n&1 != 0 {
			res = mulMod(res, p, mod)
		}
		p = mulMod(p, p, mod)
	}
	return res
}

func nlz(x int) int {
	return 32 - clz(x)
}

func clz(x int) int {
	if x == 0 {
		return 32
	}
	return 31 - len(fmt.Sprintf("%b", x))
}

func normalize(list []int) {
	r := len(list) - 1
	for r >= 0 && list[r] == 0 {
		r--
	}
	list = list[:r+1]
}

func readTwoInts(reader io.Reader) (int, int) {
	a, b := 0, 0
	f := 1
	for {
		c := read(reader)
		if c == '-' {
			f = -1
			break
		}
		if c >= '0' && c <= '9' {
			a = int(c - '0')
			break
		}
	}
	for {
		c := read(reader)
		if c < '0' || c > '9' {
			break
		}
		a = a*10 + int(c-'0')
	}
	a *= f
	f = 1
	for {
		c := read(reader)
		if c == '-' {
			f = -1
			break
		}
		if c >= '0' && c <= '9' {
			b = int(c - '0')
			break
		}
	}
	for {
		c := read(reader)
		if c < '0' || c > '9' {
			break
		}
		b = b*10 + int(c-'0')
	}
	b *= f
	return a, b
}

func readInt(reader io.Reader) int {
	a := 0
	f := 1
	for {
		c := read(reader)
		if c == '-' {
			f = -1
			break
		}
		if c >= '0' && c <= '9' {
			a = int(c - '0')
			break
		}
	}
	for {
		c := read(reader)
		if c < '0' || c > '9' {
			break
		}
		a = a*10 + int(c-'0')
	}
	a *= f
	return a
}

func read(reader io.Reader) byte {
	buf := make([]byte, 1)
	_, err := reader.Read(buf)
	if err != nil {
		return 0
	}
	return buf[0]
}

type PriorityQueue [][]int

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return len(pq[i]) < len(pq[j])
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.([]int)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

var (
	cache    = [1 << 16]int{}
	wCache   = [30]int{}
	invCache = [30]int{}
	revCache = [1 << 20]int{}
)

func init() {
	for i := 0; i < 1<<16; i++ {
		cache[i] = bits(i)
	}
	for i := 0; i < 30; i++ {
		wCache[i] = pow(g, (mod-1)/(1<<(i+1)), mod)
		invCache[i] = pow(1<<(i+1), mod-2, mod)
	}
	for i := 1; i < 1<<20; i++ {
		revCache[i] = (revCache[i>>1] >> 1) | ((1 & i) << 19)
	}
}

func bits(x int) int {
	if x == 0 {
		return 0
	}
	return 1 + bits(x&(x-1))
}
