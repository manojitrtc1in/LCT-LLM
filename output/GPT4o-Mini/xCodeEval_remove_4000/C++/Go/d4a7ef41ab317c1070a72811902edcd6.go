package main

import (
	"fmt"
	"math/bits"
)

type Bitset struct {
	n    int
	data []uint32
}

func NewBitset(N int) *Bitset {
	n := (N + 31) / 32
	return &Bitset{
		n:    n,
		data: make([]uint32, n),
	}
}

func (b *Bitset) Set() {
	for i := range b.data {
		b.data[i] = 0xFFFFFFFF
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
	b.data[pos>>5] &^= 1 << (pos & 31)
}

func (b *Bitset) Flip(pos int) {
	b.data[pos>>5] ^= 1 << (pos & 31)
}

func (b *Bitset) Test(pos int) bool {
	return (b.data[pos>>5]>>(pos&31))&1 != 0
}

func (b *Bitset) Or(other *Bitset) {
	for i := 0; i < b.n; i++ {
		b.data[i] |= other.data[i]
	}
}

func (b *Bitset) And(other *Bitset) {
	for i := 0; i < b.n; i++ {
		b.data[i] &= other.data[i]
	}
}

func (b *Bitset) Xor(other *Bitset) {
	for i := 0; i < b.n; i++ {
		b.data[i] ^= other.data[i]
	}
}

func (b *Bitset) ShiftLeft(shift int) {
	full := shift >> 5
	if full >= b.n {
		b.Reset()
		return
	}
	if full > 0 {
		copy(b.data[full:], b.data[:b.n-full])
		for i := 0; i < full; i++ {
			b.data[i] = 0
		}
	}
	shift &= 31
	if shift > 0 {
		for i := b.n - 1; i >= 1; i-- {
			b.data[i] = (b.data[i] << shift) | (b.data[i-1] >> (32 - shift))
		}
		b.data[0] <<= shift
	}
}

func (b *Bitset) ShiftRight(shift int) {
	full := shift >> 5
	if full >= b.n {
		b.Reset()
		return
	}
	if full > 0 {
		copy(b.data[:b.n-full], b.data[full:])
		for i := b.n - full; i < b.n; i++ {
			b.data[i] = 0
		}
	}
	shift &= 31
	if shift > 0 {
		for i := 0; i < b.n-1; i++ {
			b.data[i] = (b.data[i] >> shift) | ((b.data[i+1] & ((1 << shift) - 1)) << (32 - shift))
		}
		b.data[b.n-1] >>= shift
	}
}

func (b *Bitset) Count() int {
	count := 0
	for _, v := range b.data {
		count += bits.OnesCount32(v)
	}
	return count
}

func (b *Bitset) None() bool {
	for _, v := range b.data {
		if v != 0 {
			return false
		}
	}
	return true
}

func (b *Bitset) Any() bool {
	return !b.None()
}

type IG struct {
	good [2004]*Bitset
	bad  [2004]*Bitset
	bv   [2004]bool
}

func NewIG() *IG {
	ig := &IG{}
	for i := 0; i < 2004; i++ {
		ig.good[i] = NewBitset(1004)
		ig.bad[i] = NewBitset(1004)
	}
	return ig
}

func (ig *IG) AddImplication(a, b int) {
	if b < 1004 {
		ig.good[a].SetPos(b)
	} else {
		ig.bad[a].SetPos(b - 1004)
	}
}

func (ig *IG) Add(a, b int) {
	ig.AddImplication(-a, b)
	ig.AddImplication(-b, a)
}

func (ig *IG) TransitiveClosure() {
	for i := 0; i < 2004; i++ {
		if i < 1004 {
			ig.good[i].SetPos(i)
		} else {
			ig.bad[i].SetPos(i - 1004)
		}
	}
	for mid := 0; mid < 2004; mid++ {
		for i := 0; i < 2004; i++ {
			ok := false
			if mid < 1004 {
				if ig.good[i].Test(mid) {
					ok = true
				}
			} else {
				if ig.bad[i].Test(mid - 1004) {
					ok = true
				}
			}
			if ok {
				ig.good[i].Or(ig.good[mid])
				ig.bad[i].Or(ig.bad[mid])
			}
		}
	}
	for i := 0; i < 2004; i++ {
		if i < 1004 {
			if ig.bad[i].Test(i) {
				ig.bv[i] = true
			}
		} else {
			if ig.good[i].Test(i - 1004) {
				ig.bv[i] = true
			}
		}
	}
}

func (ig *IG) HasSolution() bool {
	for i := 0; i < 1004; i++ {
		if ig.bad[i].Test(i) && ig.good[i+1004].Test(i) {
			return false
		}
	}
	return true
}

func (ig *IG) Select(v int) bool {
	t := v
	if ig.bv[t] {
		return false
	}
	k := 0
	sof := make([]int, 1004)
	sof[k] = v
	k++
	ok := true
	for i := 0; i < 1004; i++ {
		if ig.good[t].Test(i) {
			if ig.bv[i] {
				ok = false
				break
			}
			if !ig.bv[i] {
				ig.bv[i] = true
				sof[k] = i
				k++
			}
		}
		if ig.bad[t].Test(i) {
			if !ig.bv[i] {
				ok = false
				break
			}
			if !ig.bv[i] {
				ig.bv[i] = false
				sof[k] = i
				k++
			}
		}
	}
	if !ok {
		for i := 0; i < k; i++ {
			ig.bv[sof[i]] = false
		}
		return false
	}
	return true
}

func (ig *IG) PrintSolutionAndDie(f1, f2 int) {
	num := make([]int, 1004)
	for i := range num {
		num[i] = -1
	}
	if f1 != -1 {
		if f1 < 1004 {
			num[f1] = 1
		} else {
			f1 -= 1004
			num[f1] = 0
		}
		ig.Select(f1)
	}
	if f2 != -1 {
		if num[f2] == -1 {
			if f2 < 1004 {
				num[f2] = 1
			} else {
				f2 -= 1004
				num[f2] = 0
			}
			ig.Select(f2)
		}
	}
	for i := 0; i < 1004; i++ {
		if num[i] != -1 {
			continue
		}
		num[i] = 0
		if !ig.Select(i) {
			num[i] = 1
			ig.Select(i)
		}
	}
	for i := 0; i < 1004; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(num[i])
	}
	fmt.Println()
}

func (ig *IG) CheckBad(v1, v2 int) bool {
	t := ig.good[v1].Or(ig.good[v2]).And(ig.bad[v1].Or(ig.bad[v2]))
	return t.Any()
}

func main() {
	var n, m1, m2 int
	fmt.Scan(&n, &m1, &m2)

	g1 := NewIG()
	g2 := NewIG()

	cl1 := make([][2]int, m1)
	cl2 := make([][2]int, m2)

	for i := 0; i < m1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		cl1[i] = [2]int{a, b}
		g1.Add(a, b)
	}
	for i := 0; i < m2; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		cl2[i] = [2]int{a, b}
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

	used := make([][]bool, 2002)
	for i := range used {
		used[i] = make([]bool, 2002)
	}

	solve := func(cl1, cl2 [][2]int, g1, g2 *IG, m1, m2 int) {
		for i := 0; i < m1; i++ {
			v1 := g1.GetNum(cl1[i][0])
			v2 := g1.GetNum(cl1[i][1])
			v1 = g1.Neg(v1)
			v2 = g1.Neg(v2)
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

	solve(cl1, cl2, g1, g2, m1, m2)
	solve(cl2, cl1, g2, g1, m2, m1)
	fmt.Println("SIMILAR")
}
