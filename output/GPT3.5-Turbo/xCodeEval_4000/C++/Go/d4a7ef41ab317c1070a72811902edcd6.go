package main

import (
	"bufio"
	"fmt"
	"os"
)

type Bitset struct {
	data []uint32
}

func NewBitset(n int) *Bitset {
	data := make([]uint32, (n+31)/32)
	return &Bitset{data: data}
}

func (b *Bitset) Set() {
	for i := range b.data {
		b.data[i] = ^uint32(0)
	}
}

func (b *Bitset) SetPos(pos int) {
	b.data[pos>>5] |= 1 << (pos & 31)
}

func (b *Bitset) Reset() {
	for i := range b.data {
		b.data[i] = 0
	}
}

func (b *Bitset) ResetPos(pos int) {
	b.data[pos>>5] &= ^(1 << (pos & 31))
}

func (b *Bitset) FlipPos(pos int) {
	b.data[pos>>5] ^= 1 << (pos & 31)
}

func (b *Bitset) TestPos(pos int) bool {
	return (b.data[pos>>5]>>(pos&31))&1 == 1
}

func (b *Bitset) Or(other *Bitset) {
	for i := range b.data {
		b.data[i] |= other.data[i]
	}
}

func (b *Bitset) And(other *Bitset) {
	for i := range b.data {
		b.data[i] &= other.data[i]
	}
}

func (b *Bitset) Xor(other *Bitset) {
	for i := range b.data {
		b.data[i] ^= other.data[i]
	}
}

func (b *Bitset) ShiftLeft(shift int) {
	full := shift >> 5
	if full >= len(b.data) {
		b.Reset()
		return
	}
	if full > 0 {
		copy(b.data[full:], b.data)
		for i := 0; i < full; i++ {
			b.data[i] = 0
		}
	}

	shift &= 31
	if shift > 0 {
		for i := len(b.data) - 1; i >= 1; i-- {
			b.data[i] = (b.data[i] << shift) | (b.data[i-1] >> (32 - shift))
		}
		b.data[0] <<= shift
	}
}

func (b *Bitset) ShiftRight(shift int) {
	full := shift >> 5
	if full >= len(b.data) {
		b.Reset()
		return
	}
	if full > 0 {
		copy(b.data, b.data[full:])
		for i := len(b.data) - full; i < len(b.data); i++ {
			b.data[i] = 0
		}
	}

	shift &= 31
	if shift > 0 {
		u := (1 << shift) - 1
		for i := 0; i < len(b.data)-1; i++ {
			b.data[i] = (b.data[i] >> shift) | ((b.data[i+1] & u) << (32 - shift))
		}
		b.data[len(b.data)-1] >>= shift
	}
}

func (b *Bitset) Count() int {
	count := 0
	for _, d := range b.data {
		count += popcount(d)
	}
	return count
}

func (b *Bitset) None() bool {
	for _, d := range b.data {
		if d != 0 {
			return false
		}
	}
	return true
}

func (b *Bitset) Any() bool {
	return !b.None()
}

func (b *Bitset) Popcount() int {
	count := 0
	for _, d := range b.data {
		count += popcount(d)
	}
	return count
}

func (b *Bitset) Ctz() int {
	for i, d := range b.data {
		if d != 0 {
			return i*32 + ctz(d)
		}
	}
	return len(b.data) * 32
}

func (b *Bitset) Clz() int {
	for i := len(b.data) - 1; i >= 0; i-- {
		if b.data[i] != 0 {
			return i*32 + clz(b.data[i]) - (32 - len(b.data)*32)
		}
	}
	return 0
}

func (b *Bitset) Equal(other *Bitset) bool {
	for i := range b.data {
		if b.data[i] != other.data[i] {
			return false
		}
	}
	return true
}

func (b *Bitset) LessThan(other *Bitset) bool {
	for i := range b.data {
		if b.data[i] != other.data[i] {
			return b.data[i] < other.data[i]
		}
	}
	return false
}

func (b *Bitset) GreaterThan(other *Bitset) bool {
	for i := range b.data {
		if b.data[i] != other.data[i] {
			return b.data[i] > other.data[i]
		}
	}
	return false
}

func (b *Bitset) LessThanOrEqual(other *Bitset) bool {
	return !b.GreaterThan(other)
}

func (b *Bitset) GreaterThanOrEqual(other *Bitset) bool {
	return !b.LessThan(other)
}

func popcount(x uint32) int {
	x -= (x >> 1) & 0x55555555
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
	x = (x + (x >> 4)) & 0x0f0f0f0f
	x += x >> 8
	x += x >> 16
	return int(x & 0x0000003f)
}

func ctz(x uint32) int {
	if x == 0 {
		return 32
	}
	return popcount((x & -x) - 1)
}

func clz(x uint32) int {
	if x == 0 {
		return 32
	}
	x |= x >> 1
	x |= x >> 2
	x |= x >> 4
	x |= x >> 8
	x |= x >> 16
	return 32 - popcount(x)
}

type IG struct {
	good, bad []*Bitset
	bv       []bool
}

func NewIG(n int) *IG {
	good := make([]*Bitset, 2*n)
	bad := make([]*Bitset, 2*n)
	for i := range good {
		good[i] = NewBitset(2 * n)
		bad[i] = NewBitset(2 * n)
	}
	bv := make([]bool, 2*n)
	return &IG{good: good, bad: bad, bv: bv}
}

func (ig *IG) AddImplication(a, b int) {
	a = ig.GetNum(a)
	b = ig.GetNum(b)
	if b < n {
		ig.good[a].SetPos(b)
	} else {
		ig.bad[a].SetPos(b - n)
	}
}

func (ig *IG) Add(a, b int) {
	ig.AddImplication(-a, b)
	ig.AddImplication(-b, a)
}

func (ig *IG) TransitiveClosure() {
	for i := 0; i < 2*n; i++ {
		if i < n {
			ig.good[i].SetPos(i)
		} else {
			ig.bad[i].SetPos(i - n)
		}
	}

	for mid := 0; mid < 2*n; mid++ {
		for i := 0; i < 2*n; i++ {
			ok := false
			if mid < n {
				if ig.good[i].TestPos(mid) {
					ok = true
				}
			} else {
				if ig.bad[i].TestPos(mid - n) {
					ok = true
				}
			}
			if ok {
				ig.good[i].Or(ig.good[mid])
				ig.bad[i].Or(ig.bad[mid])
			}
		}
	}

	for i := 0; i < 2*n; i++ {
		if i < n {
			if ig.bad[i].TestPos(i) && ig.good[i+n].TestPos(i) {
				return false
			}
		} else {
			if ig.good[i].TestPos(i-n) && ig.bad[i].TestPos(i-n) {
				return false
			}
		}
	}

	for i := 0; i < 2*n; i++ {
		if ig.bv[i] {
			continue
		}
		if i < n {
			if ig.good[i].TestPos(i) {
				ig.bv[i] = true
			}
		} else {
			if ig.bad[i].TestPos(i-n) {
				ig.bv[i] = true
			}
		}
	}

	for i := 0; i < 2*n; i++ {
		if !ig.bv[i] {
			continue
		}
		for j := 0; j < 2*n; j++ {
			if !ig.bv[j] {
				continue
			}
			if j < n {
				if ig.good[i].TestPos(j) {
					ig.bv[i] = true
				}
			} else {
				if ig.bad[i].TestPos(j-n) {
					ig.bv[i] = true
				}
			}
		}
	}

	return true
}

func (ig *IG) HasSolution() bool {
	for i := 0; i < n; i++ {
		if ig.bad[i].TestPos(i) && ig.good[i+n].TestPos(i) {
			return false
		}
	}
	return true
}

func (ig *IG) Select(v int) bool {
	t := v
	if ig.num[v] == 0 {
		t += n
	}
	if ig.bv[t] {
		return false
	}
	k := 0
	ig.sof[k] = v
	ok := true
	for i := 0; i < n; i++ {
		if ig.good[t].TestPos(i) {
			if ig.num[i] == 0 {
				ok = false
				break
			}
			if ig.num[i] == -1 {
				ig.num[i] = 1
				ig.sof[k] = i
				k++
			}
		}
		if ig.bad[t].TestPos(i) {
			if ig.num[i] == 1 {
				ok = false
				break
			}
			if ig.num[i] == -1 {
				ig.num[i] = 0
				ig.sof[k] = i
				k++
			}
		}
	}
	if !ok {
		for i := 0; i < k; i++ {
			ig.num[ig.sof[i]] = -1
		}
		return false
	}
	return true
}

func (ig *IG) PrintSolutionAndDie(f1, f2 int) {
	for i := 0; i < n; i++ {
		ig.num[i] = -1
	}
	if f1 != -1 {
		if f1 < n {
			ig.num[f1] = 1
		} else {
			f1 -= n
			ig.num[f1] = 0
		}
		ig.Select(f1)
	}
	if f2 != -1 {
		if ig.num[f2%n] == -1 {
			if f2 < n {
				ig.num[f2] = 1
			} else {
				f2 -= n
				ig.num[f2] = 0
			}
			ig.Select(f2)
		}
	}
	for i := 0; i < n; i++ {
		if ig.num[i] == -1 {
			ig.num[i] = 0
			if !ig.Select(i) {
				ig.num[i] = 1
				ig.Select(i)
			}
		}
	}
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(ig.num[i])
	}
	fmt.Println()
	os.Exit(0)
}

func (ig *IG) CheckBad(v1, v2 int) bool {
	t := ig.good[v1].Or(ig.good[v2])
	t.And(ig.bad[v1].Or(ig.bad[v2]))
	return t.Any()
}

func GetNum(a int) int {
	if a > 0 {
		return a - 1
	}
	a = -a
	return n + a - 1
}

func Neg(a int) int {
	if a < n {
		return a + n
	}
	return a - n
}

var n, m1, m2 int
var g1, g2 *IG
var cl1, cl2 [][]int
var used [][]bool

func solve(cl1, cl2 [][]int, g1, g2 *IG, m1, m2 int) {
	for i := 0; i < m1; i++ {
		v1 := GetNum(cl1[i][0])
		v2 := GetNum(cl1[i][1])
		v1 = Neg(v1)
		v2 = Neg(v2)
		if v1 > v2 {
			v1, v2 = v2, v1
		}
		if used[v1][v2] {
			continue
		}
		used[v1][v2] = true

		if g2.bv[v1] || g2.bv[v2] {
			continue
		}
		if g2.CheckBad(v1, v2) {
			continue
		}
		g2.PrintSolutionAndDie(v1, v2)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n = atoi(scanner.Bytes())
	scanner.Scan()
	m1 = atoi(scanner.Bytes())
	scanner.Scan()
	m2 = atoi(scanner.Bytes())

	g1 = NewIG(n)
	g2 = NewIG(n)

	cl1 = make([][]int, m1)
	cl2 = make([][]int, m2)
	for i := 0; i < m1; i++ {
		scanner.Scan()
		a := atoi(scanner.Bytes())
		scanner.Scan()
		b := atoi(scanner.Bytes())
		cl1[i] = []int{a, b}
		g1.Add(a, b)
	}
	for i := 0; i < m2; i++ {
		scanner.Scan()
		a := atoi(scanner.Bytes())
		scanner.Scan()
		b := atoi(scanner.Bytes())
		cl2[i] = []int{a, b}
		g2.Add(a, b)
	}

	g1.TransitiveClosure()
	g2.TransitiveClosure()

	r1 := g1.HasSolution()
	r2 := g2.HasSolution()
	if !r1 && !r2 {
		fmt.Println("SIMILAR")
		return
	}
	if !r1 {
		g2.PrintSolutionAndDie(-1, -1)
	}
	if !r2 {
		g1.PrintSolutionAndDie(-1, -1)
	}
	used = make([][]bool, 2*n)
	for i := range used {
		used[i] = make([]bool, 2*n)
	}
	solve(cl1, cl2, g1, g2, m1, m2)
	solve(cl2, cl1, g2, g1, m2, m1)
	fmt.Println("SIMILAR")
}

func atoi(b []byte) int {
	neg := false
	if b[0] == '-' {
		neg = true
		b = b[1:]
	}
	n := 0
	for _, c := range b {
		n = n*10 + int(c-'0')
	}
	if neg {
		return -n
	}
	return n
}
