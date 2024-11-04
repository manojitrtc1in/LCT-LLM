package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

var (
	mod = 998244353
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)
	allow := make([]int, 10)
	for i := 0; i < k; i++ {
		var x int
		fmt.Fscan(reader, &x)
		allow[x] = 1
	}

	p := make([]int, 0)
	for _, v := range allow {
		p = append(p, v)
	}

	m := n / 2
	last := make([]int, len(p))
	copy(last, p)
	ntt := NewNTT(mod, 3)
	lists := make([][]int, 0)
	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, append([]int(nil), last...))
		}
		ntt.Pow2(last)
		Normalize(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := make([]int, 0)
	ntt.ID1(lists, prod)

	ans := 0
	for _, v := range prod {
		plus := v
		ans = (ans + modMul(plus, plus)) % mod
	}

	fmt.Fprintln(writer, ans)
}

type NTT struct {
	mod    int
	power  *Power
	g      int
	wCache []int
	inv    []int
}

func NewNTT(mod, g int) *NTT {
	ntt := new(NTT)
	ntt.mod = mod
	ntt.power = NewPower(mod)
	ntt.g = g
	ntt.wCache = make([]int, 30)
	ntt.inv = make([]int, 30)
	for i := 0; i < 30; i++ {
		s := 1 << i
		ntt.wCache[i] = ntt.power.Pow(ntt.g, (mod-1)/2/s)
		ntt.inv[i] = ntt.power.Inverse(s)
	}
	return ntt
}

func (ntt *NTT) DotMul(a, b, c []int, m int) {
	for i := 0; i < 1<<m; i++ {
		c[i] = modMul(a[i], b[i])
	}
}

func (ntt *NTT) DFT(p []int, m int) {
	n := 1 << m

	shift := 32 - bits.Len(uint(n))
	for i := 1; i < n; i++ {
		j := bits.Reverse(uint(i) << shift)
		if i < j {
			p[i], p[j] = p[j], p[i]
		}
	}

	w := 0
	t := 0
	for d := 0; d < m; d++ {
		w1 := ntt.wCache[d]
		s := 1 << d
		s2 := s << 1
		for i := 0; i < n; i += s2 {
			w = 1
			for j := 0; j < s; j++ {
				a := i + j
				b := a + s
				t = modMul(w, p[b])
				p[b] = modPlus(p[a], -t)
				p[a] = modPlus(p[a], t)
				w = modMul(w, w1)
			}
		}
	}
}

func (ntt *NTT) IDFT(p []int, m int) {
	ntt.DFT(p, m)

	n := 1 << m
	invN := ntt.inv[m]

	p[0] = modMul(p[0], invN)
	p[n/2] = modMul(p[n/2], invN)
	for i := 1; i < n/2; i++ {
		a := p[n-i]
		p[n-i] = modMul(p[i], invN)
		p[i] = modMul(a, invN)
	}
}

func (ntt *NTT) ID1(lists [][]int, ans []int) {
	pqs := make(PriorityQueue, 0)
	for _, list := range lists {
		clone := make([]int, len(list))
		copy(clone, list)
		pqs.Push(clone)
	}
	for pqs.Len() > 1 {
		a := pqs.Pop().([]int)
		b := pqs.Pop().([]int)
		ntt.ID9(a, b)
		pqs.Push(a)
	}
	last := pqs.Pop().([]int)
	ans = append(ans, last...)
}

func (ntt *NTT) Pow2(a []int) {
	rankAns := len(a) - 1
	proper := bits.Len(uint(rankAns))
	a = append(a, make([]int, 1<<proper-len(a))...)
	ntt.DFT(a, proper)
	ntt.DotMul(a, a, a, proper)
	ntt.IDFT(a, proper)
	Normalize(a)
}

func (ntt *NTT) ID9(a, b []int) {
	rankAns := len(a) - 1 + len(b) - 1
	proper := bits.Len(uint(rankAns))
	a = append(a, make([]int, 1<<proper-len(a))...)
	b = append(b, make([]int, 1<<proper-len(b))...)
	ntt.DFT(a, proper)
	ntt.DFT(b, proper)
	ntt.DotMul(a, b, a, proper)
	ntt.IDFT(a, proper)
	Normalize(a)
}

type Power struct {
	mod int
}

func NewPower(mod int) *Power {
	power := new(Power)
	power.mod = mod
	return power
}

func (power *Power) Pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := power.Pow(x, n>>1)
	r = modMul(r, r)
	if n&1 == 1 {
		r = modMul(r, x)
	}
	return r
}

func (power *Power) Inverse(x int) int {
	return power.Pow(x, power.mod-2)
}

func modMul(x, y int) int {
	return (x * y) % mod
}

func modPlus(x, y int) int {
	return (x + y) % mod
}

func Normalize(list []int) {
	r := len(list) - 1
	for r >= 0 && list[r] == 0 {
		r--
	}
	list = list[:r+1]
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
	*pq = old[:n-1]
	return item
}

func readInt(reader *bufio.Reader) int {
	var x int
	fmt.Fscan(reader, &x)
	return x
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := readInt(reader)
	k := readInt(reader)
	allow := make([]int, 10)
	for i := 0; i < k; i++ {
		allow[readInt(reader)] = 1
	}

	p := make([]int, 0)
	for _, v := range allow {
		p = append(p, v)
	}

	m := n / 2
	last := make([]int, len(p))
	copy(last, p)
	ntt := NewNTT(mod, 3)
	lists := make([][]int, 0)
	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, append([]int(nil), last...))
		}
		ntt.Pow2(last)
		Normalize(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := make([]int, 0)
	ntt.ID1(lists, prod)

	ans := 0
	for _, v := range prod {
		plus := v
		ans = (ans + modMul(plus, plus)) % mod
	}

	fmt.Fprintln(writer, ans)
}

func readInt(reader *bufio.Reader) int {
	var x int
	fmt.Fscan(reader, &x)
	return x
}
