package main

import (
	"fmt"
	"math/rand"
	"time"
)

type lli int64

func ctoi(c rune) int {
	if c >= '0' && c <= '9' {
		return int(c - '0')
	}
	return -1
}

func alphabetPos(c rune) int {
	if c >= 'a' && c <= 'z' {
		return int(c - 'a')
	}
	return -1
}

func id6(c rune) int {
	if c >= 'A' && c <= 'Z' {
		return int(c - 'A')
	}
	return -1
}

func split(str string, ch rune) []string {
	var result []string
	first := 0
	last := 0

	for {
		last = first
		for last < len(str) && rune(str[last]) != ch {
			last++
		}
		result = append(result, str[first:last])
		if last >= len(str) {
			break
		}
		first = last + 1
	}
	return result
}

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	if a%b == 0 {
		return b
	}
	return gcd(b, a%b)
}

func gcdLong(a, b lli) lli {
	if a < b {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	if a%b == 0 {
		return b
	}
	return gcdLong(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func lcmLong(a, b lli) lli {
	return a * b / gcdLong(a, b)
}

func powFast(x, nPower, modulus lli) lli {
	if nPower == 0 {
		return 1
	}
	if nPower%2 == 0 {
		return powFast((x*x)%modulus, nPower/2, modulus)
	}
	return (x * powFast(x, nPower-1, modulus)) % modulus
}

type CombinationTable struct {
	val [][]lli
}

func NewCombinationTable(size int) *CombinationTable {
	ct := &CombinationTable{
		val: make([][]lli, size+1),
	}
	for i := range ct.val {
		ct.val[i] = make([]lli, size+1)
	}
	for i := 0; i <= size; i++ {
		for j := 0; j <= i; j++ {
			if j == 0 || j == i {
				ct.val[i][j] = 1
			} else {
				ct.val[i][j] = ct.val[i-1][j-1] + ct.val[i-1][j]
			}
		}
	}
	return ct
}

func printVector(h []int, verbose bool) {
	L := len(h)
	for i := 0; i < L; i++ {
		if verbose {
			fmt.Printf("%d", h[i])
		} else {
			fmt.Print(h[i])
		}
		if i != L-1 {
			if verbose {
				fmt.Print(" ")
			} else {
				fmt.Print(" ")
			}
		} else {
			if verbose {
				fmt.Println()
			} else {
				fmt.Println()
			}
		}
	}
}

func printVectorLong(h []lli, verbose bool) {
	L := len(h)
	for i := 0; i < L; i++ {
		if verbose {
			fmt.Printf("%d", h[i])
		} else {
			fmt.Print(h[i])
		}
		if i != L-1 {
			if verbose {
				fmt.Print(" ")
			} else {
				fmt.Print(" ")
			}
		} else {
			if verbose {
				fmt.Println()
			} else {
				fmt.Println()
			}
		}
	}
}

func id7(h [][]int, verbose bool) {
	Ly := len(h)
	for i := 0; i < Ly; i++ {
		Lx := len(h[i])
		for j := 0; j < Lx; j++ {
			if verbose {
				fmt.Printf("%d", h[i][j])
			} else {
				fmt.Print(h[i][j])
			}
			if j != Lx-1 {
				if verbose {
					fmt.Print(" ")
				} else {
					fmt.Print(" ")
				}
			} else {
				if verbose {
					fmt.Println()
				} else {
					fmt.Println()
				}
			}
		}
	}
}

func id7Long(h [][]lli, verbose bool) {
	Ly := len(h)
	for i := 0; i < Ly; i++ {
		Lx := len(h[i])
		for j := 0; j < Lx; j++ {
			if verbose {
				fmt.Printf("%d", h[i][j])
			} else {
				fmt.Print(h[i][j])
			}
			if j != Lx-1 {
				if verbose {
					fmt.Print(" ")
				} else {
					fmt.Print(" ")
				}
			} else {
				if verbose {
					fmt.Println()
				} else {
					fmt.Println()
				}
			}
		}
	}
}

func id7String(h []string, verbose bool) {
	Ly := len(h)
	for i := 0; i < Ly; i++ {
		Lx := len(h[i])
		for j := 0; j < Lx; j++ {
			if verbose {
				fmt.Printf("%c", h[i][j])
			} else {
				fmt.Print(h[i][j])
			}
		}
		if verbose {
			fmt.Println()
		} else {
			fmt.Println()
		}
	}
}

func printBinary(val int, numDigit int, verbose bool) {
	for k := numDigit - 1; k >= 0; k-- {
		if verbose {
			fmt.Printf("%d", (val>>k)&1)
		} else {
			fmt.Print((val >> k) & 1)
		}
	}
	if verbose {
		fmt.Println()
	} else {
		fmt.Println()
	}
}

func printBinaryLong(val lli, numDigit int, verbose bool) {
	for k := numDigit - 1; k >= 0; k-- {
		if verbose {
			fmt.Printf("%d", (val>>k)&1)
		} else {
			fmt.Print((val >> k) & 1)
		}
	}
	if verbose {
		fmt.Println()
	} else {
		fmt.Println()
	}
}

type SegmentTree struct {
	n    int
	node []lli
	id0  lli
}

func NewSegmentTree(v []lli, id3 lli) *SegmentTree {
	sz := len(v)
	n := 1
	for n < sz {
		n <<= 1
	}
	node := make([]lli, 2*n-1)
	for i := 0; i < sz; i++ {
		node[i+n-1] = v[i]
	}
	for i := n - 2; i >= 0; i-- {
		node[i] = min(node[2*i+1], node[2*i+2])
	}
	return &SegmentTree{n: n, node: node, id0: id3}
}

func (st *SegmentTree) update(x int, val lli) {
	x += (st.n - 1)
	st.node[x] = val
	for x > 0 {
		x = (x - 1) / 2
		st.node[x] = min(st.node[2*x+1], st.node[2*x+2])
	}
}

func (st *SegmentTree) getMin(a, b int, k, l, r int) lli {
	if r < 0 {
		r = st.n
	}
	if r <= a || b <= l {
		return st.id0
	}
	if a <= l && r <= b {
		return st.node[k]
	}
	vl := st.getMin(a, b, 2*k+1, l, (l+r)/2)
	vr := st.getMin(a, b, 2*k+2, (l+r)/2, r)
	return min(vl, vr)
}

type id1 struct {
	size_ int
	data  []lli
}

func NewId1(sz int, id2 lli) *id1 {
	data := make([]lli, sz+1)
	for i := range data {
		data[i] = id2
	}
	return &id1{size_: sz, data: data}
}

func (i *id1) sum(idx int) lli {
	if idx <= 0 {
		return 0
	}
	if idx > i.size_ {
		idx = i.size_
	}
	sm := lli(0)
	for idx > 0 {
		sm += i.data[idx]
		idx -= idx & -idx
	}
	return sm
}

func (i *id1) add(idx int, x lli) {
	if idx < 0 || idx >= i.size_ {
		return
	}
	idx++
	for idx <= i.size_ {
		i.data[idx] += x
		idx += idx & -idx
	}
}

type RollingHash struct {
	hash     []lli
	basePow  []lli
	base     lli
	modulus  lli
	id5     lli
	MASK30   lli
	MASK31   lli
	BASE_MIN lli
}

func NewRollingHash(S string, base_ lli, id4 lli) *RollingHash {
	id5 := (1 << 61) - 1
	MASK30 := (1 << 30) - 1
	MASK31 := (1 << 31) - 1
	BASE_MIN := int64(1e7)

	rh := &RollingHash{
		id5:     id5,
		MASK30:  MASK30,
		MASK31:  MASK31,
		BASE_MIN: BASE_MIN,
	}
	if id4 > 0 {
		rh.modulus = id4
	} else {
		rh.modulus = id5
	}
	if base_ > 0 {
		rh.base = base_
	} else {
		rand.Seed(time.Now().UnixNano())
		rh.base = rand.Int63n(id5-BASE_MIN) + BASE_MIN
	}
	if len(S) > 0 {
		rh.initialize(S)
	}
	return rh
}

func (rh *RollingHash) initialize(S string) {
	N := len(S)
	s := make([]int, N)
	for i := 0; i < N; i++ {
		s[i] = int(S[i])
	}
	rh.initializeInt(s)
}

func (rh *RollingHash) initializeInt(S []int) {
	hash := make([]lli, len(S)+1)
	basePow := make([]lli, len(S)+1)
	hash[0] = 0
	basePow[0] = 1

	if rh.modulus == rh.id5 {
		for i := 1; i <= len(S); i++ {
			hash[i] = rh.Modulus2Pow61m1(rh.Multiple2Pow61m1(hash[i-1], rh.base) + lli(S[i-1]))
			basePow[i] = rh.Multiple2Pow61m1(basePow[i-1], rh.base)
		}
	} else {
		for i := 1; i <= len(S); i++ {
			hash[i] = (hash[i-1]*rh.base + lli(S[i-1])) % rh.modulus
			basePow[i] = (basePow[i-1] * rh.base) % rh.modulus
		}
	}
	rh.hash = hash
	rh.basePow = basePow
}

func (rh *RollingHash) Modulus2Pow61m1(val lli) lli {
	val = (val & rh.id5) + (val >> 61)
	if rh.id5 < val {
		val -= rh.id5
	}
	return val
}

func (rh *RollingHash) Multiple2Pow61m1(a, b lli) lli {
	au := a >> 31
	ad := a & rh.MASK31
	bu := b >> 31
	bd := b & rh.MASK31

	mid := ad * bu + au * bd
	midu := mid >> 30
	midd := mid & rh.MASK30

	return rh.Modulus2Pow61m1(((au * bu) << 1) + midu + (midd << 31) + ad*bd)
}

func (rh *RollingHash) between(a, b int) lli {
	if rh.modulus == rh.id5 {
		return rh.Modulus2Pow61m1(rh.modulus + rh.hash[b] - rh.Multiple2Pow61m1(rh.hash[a], rh.basePow[b-a]))
	}
	return (rh.modulus + rh.hash[b] - (rh.hash[a] * rh.basePow[b-a]) % rh.modulus) % rh.modulus
}

func main() {
	var N int
	fmt.Scan(&N)
	a := make([]lli, N)
	mp := make(map[lli]int)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
		mp[a[i]]++
	}
	b := make([]lli, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&b[i])
	}

	var vs []lli
	for elem, count := range mp {
		if count > 1 {
			vs = append(vs, elem)
		}
	}

	ans := lli(0)
	for i := 0; i < N; i++ {
		isok := false
		for _, elem := range vs {
			if (elem & a[i]) == a[i] {
				isok = true
				break
			}
		}
		if isok {
			ans += b[i]
		}
	}

	fmt.Println(ans)
}
