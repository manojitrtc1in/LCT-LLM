package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

var (
	mod int = 998244353
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

	p := make([]int, 10)
	for i := 0; i < 10; i++ {
		p[i] = allow[i]
	}

	m := n / 2
	last := make([]int, len(p))
	copy(last, p)

	lists := make([][]int, 0)
	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, last)
		}
		proper := ceilLog2(2 * len(last))
		last = expandWith(last, 0, 1<<proper)
		ntt(last, 1<<proper, false)
		dotMul(last, last, last, proper)
		ntt(last, 1<<proper, true)
		normalize(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := make([]int, len(last))
	mulByPQ(lists, prod)

	ans := 0
	for i := 0; i < len(prod); i++ {
		plus := prod[i]
		ans = plusMod(ans, mulMod(plus, plus))
	}

	fmt.Fprintln(writer, ans)
}

func ceilLog2(x int) int {
	bits := 0
	for (1 << (bits + 1)) <= x {
		bits++
	}
	return bits
}

func expandWith(a []int, x, len int) []int {
	n := len(a)
	if n >= len {
		return a
	}
	b := make([]int, len)
	copy(b, a)
	for i := n; i < len; i++ {
		b[i] = x
	}
	return b
}

func ntt(p []int, n int, invert bool) {
	shift := 32 - numberOfTrailingZeros(n)
	for i := 1; i < n; i++ {
		j := reverse(i << shift)
		if i < j {
			p[i], p[j] = p[j], p[i]
		}
	}

	root := 3
	rootInv := pow(root, mod-2)
	for len := 1; len < n; len <<= 1 {
		wlen := pow(root, (mod-1)/(2*len))
		if invert {
			wlen = pow(rootInv, (mod-1)/(2*len))
		}
		for i := 0; i < n; i += 2 * len {
			w := 1
			for j := 0; j < len; j++ {
				u := p[i+j]
				v := mulMod(p[i+j+len], w)
				p[i+j] = plusMod(u, v)
				p[i+j+len] = plusMod(u, -v)
				w = mulMod(w, wlen)
			}
		}
	}

	if invert {
		invN := pow(n, mod-2)
		for i := 0; i < n; i++ {
			p[i] = mulMod(p[i], invN)
		}
	}
}

func reverse(x int) int {
	const BITS int = 16
	const LIMIT int = 1 << BITS
	const MASK int = LIMIT - 1
	return (reverseBits[x&MASK]<<BITS-BITS) | reverseBits[(x>>BITS)&MASK]
}

var reverseBits = [LIMIT]int{
	0x0000, 0x8000, 0x4000, 0xc000, 0x2000, 0xa000, 0x6000, 0xe000,
	0x1000, 0x9000, 0x5000, 0xd000, 0x3000, 0xb000, 0x7000, 0xf000,
	0x0800, 0x8800, 0x4800, 0xc800, 0x2800, 0xa800, 0x6800, 0xe800,
	0x1800, 0x9800, 0x5800, 0xd800, 0x3800, 0xb800, 0x7800, 0xf800,
	0x0400, 0x8400, 0x4400, 0xc400, 0x2400, 0xa400, 0x6400, 0xe400,
	0x1400, 0x9400, 0x5400, 0xd400, 0x3400, 0xb400, 0x7400, 0xf400,
	0x0c00, 0x8c00, 0x4c00, 0xcc00, 0x2c00, 0xac00, 0x6c00, 0xec00,
	0x1c00, 0x9c00, 0x5c00, 0xdc00, 0x3c00, 0xbc00, 0x7c00, 0xfc00,
	0x0200, 0x8200, 0x4200, 0xc200, 0x2200, 0xa200, 0x6200, 0xe200,
	0x1200, 0x9200, 0x5200, 0xd200, 0x3200, 0xb200, 0x7200, 0xf200,
	0x0a00, 0x8a00, 0x4a00, 0xca00, 0x2a00, 0xaa00, 0x6a00, 0xea00,
	0x1a00, 0x9a00, 0x5a00, 0xda00, 0x3a00, 0xba00, 0x7a00, 0xfa00,
	0x0600, 0x8600, 0x4600, 0xc600, 0x2600, 0xa600, 0x6600, 0xe600,
	0x1600, 0x9600, 0x5600, 0xd600, 0x3600, 0xb600, 0x7600, 0xf600,
	0x0e00, 0x8e00, 0x4e00, 0xce00, 0x2e00, 0xae00, 0x6e00, 0xee00,
	0x1e00, 0x9e00, 0x5e00, 0xde00, 0x3e00, 0xbe00, 0x7e00, 0xfe00,
	0x0100, 0x8100, 0x4100, 0xc100, 0x2100, 0xa100, 0x6100, 0xe100,
	0x1100, 0x9100, 0x5100, 0xd100, 0x3100, 0xb100, 0x7100, 0xf100,
	0x0900, 0x8900, 0x4900, 0xc900, 0x2900, 0xa900, 0x6900, 0xe900,
	0x1900, 0x9900, 0x5900, 0xd900, 0x3900, 0xb900, 0x7900, 0xf900,
	0x0500, 0x8500, 0x4500, 0xc500, 0x2500, 0xa500, 0x6500, 0xe500,
	0x1500, 0x9500, 0x5500, 0xd500, 0x3500, 0xb500, 0x7500, 0xf500,
	0x0d00, 0x8d00, 0x4d00, 0xcd00, 0x2d00, 0xad00, 0x6d00, 0xed00,
	0x1d00, 0x9d00, 0x5d00, 0xdd00, 0x3d00, 0xbd00, 0x7d00, 0xfd00,
	0x0300, 0x8300, 0x4300, 0xc300, 0x2300, 0xa300, 0x6300, 0xe300,
	0x1300, 0x9300, 0x5300, 0xd300, 0x3300, 0xb300, 0x7300, 0xf300,
	0x0b00, 0x8b00, 0x4b00, 0xcb00, 0x2b00, 0xab00, 0x6b00, 0xeb00,
	0x1b00, 0x9b00, 0x5b00, 0xdb00, 0x3b00, 0xbb00, 0x7b00, 0xfb00,
	0x0700, 0x8700, 0x4700, 0xc700, 0x2700, 0xa700, 0x6700, 0xe700,
	0x1700, 0x9700, 0x5700, 0xd700, 0x3700, 0xb700, 0x7700, 0xf700,
	0x0f00, 0x8f00, 0x4f00, 0xcf00, 0x2f00, 0xaf00, 0x6f00, 0xef00,
	0x1f00, 0x9f00, 0x5f00, 0xdf00, 0x3f00, 0xbf00, 0x7f00, 0xff00,
}

func numberOfTrailingZeros(x int) int {
	if x == 0 {
		return 32
	}
	var n int
	for (x & 1) == 0 {
		x >>= 1
		n++
	}
	return n
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := pow(x, n>>1)
	r = mulMod(r, r)
	if n&1 == 1 {
		r = mulMod(r, x)
	}
	return r
}

func mulMod(x, y int) int {
	return (x * y) % mod
}

func plusMod(x, y int) int {
	return (x + y) % mod
}

func dotMul(a, b, c []int, m int) {
	n := 1 << m
	for i := 0; i < n; i++ {
		c[i] = mulMod(a[i], b[i])
	}
}

func normalize(list []int) {
	rank := len(list) - 1
	for rank >= 0 && list[rank] == 0 {
		rank--
	}
	list = list[:rank+1]
}

func mulByPQ(lists [][]int, ans []int) {
	pqs := make(PriorityQueue, 0)
	for _, list := range lists {
		clone := make([]int, len(list))
		copy(clone, list)
		pqs.Push(clone)
	}
	for len(pqs) > 1 {
		a := pqs.Pop().([]int)
		b := pqs.Pop().([]int)
		multiplyAndStoreAnswerIntoA(a, b)
		pqs.Push(a)
	}
	last := pqs.Pop().([]int)
	copy(ans, last)
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

func multiplyAndStoreAnswerIntoA(a, b []int) {
	rankAns := len(a) - 1 + len(b) - 1
	proper := ceilLog2(rankAns + 1)
	a = expandWith(a, 0, 1<<proper)
	b = expandWith(b, 0, 1<<proper)
	ntt(a, 1<<proper, false)
	ntt(b, 1<<proper, false)
	dotMul(a, b, a, proper)
	ntt(a, 1<<proper, true)
	normalize(a)
}

func readInt(reader *bufio.Reader) int {
	var x int
	fmt.Fscan(reader, &x)
	return x
}

func readInts(reader *bufio.Reader, n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}
	return a
}

func writeInt(writer io.Writer, x int) {
	fmt.Fprintln(writer, x)
}

func writeInts(writer io.Writer, a []int) {
	for _, x := range a {
		fmt.Fprint(writer, x, " ")
	}
	fmt.Fprintln(writer)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := readInt(reader)
	k := readInt(reader)
	allow := readInts(reader, k)

	p := make([]int, 10)
	for i := 0; i < k; i++ {
		p[allow[i]] = 1
	}

	m := n / 2
	last := make([]int, len(p))
	copy(last, p)

	lists := make([][]int, 0)
	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, last)
		}
		proper := ceilLog2(2 * len(last))
		last = expandWith(last, 0, 1<<proper)
		ntt(last, 1<<proper, false)
		dotMul(last, last, last, proper)
		ntt(last, 1<<proper, true)
		normalize(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := make([]int, len(last))
	mulByPQ(lists, prod)

	ans := 0
	for i := 0; i < len(prod); i++ {
		plus := prod[i]
		ans = plusMod(ans, mulMod(plus, plus))
	}

	writeInt(writer, ans)
}
