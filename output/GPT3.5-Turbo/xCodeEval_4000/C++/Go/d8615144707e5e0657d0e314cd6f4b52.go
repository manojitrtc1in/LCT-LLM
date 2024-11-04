package main

import (
	"fmt"
)

type Bitset struct {
	data []uint32
}

func NewBitset(n int) *Bitset {
	data := make([]uint32, (n+31)/32)
	return &Bitset{data: data}
}

func (b *Bitset) Set() {
	for i := 0; i < len(b.data); i++ {
		b.data[i] = 0xFFFFFFFF
	}
}

func (b *Bitset) SetPos(pos int) {
	index := pos / 32
	offset := pos % 32
	b.data[index] |= 1 << offset
}

func (b *Bitset) Reset() {
	for i := 0; i < len(b.data); i++ {
		b.data[i] = 0
	}
}

func (b *Bitset) ResetPos(pos int) {
	index := pos / 32
	offset := pos % 32
	b.data[index] &= ^(1 << offset)
}

func (b *Bitset) FlipPos(pos int) {
	index := pos / 32
	offset := pos % 32
	b.data[index] ^= 1 << offset
}

func (b *Bitset) TestPos(pos int) bool {
	index := pos / 32
	offset := pos % 32
	return (b.data[index]>>offset)&1 == 1
}

func (b *Bitset) Or(other *Bitset) *Bitset {
	result := NewBitset(len(b.data) * 32)
	for i := 0; i < len(b.data); i++ {
		result.data[i] = b.data[i] | other.data[i]
	}
	return result
}

func (b *Bitset) And(other *Bitset) *Bitset {
	result := NewBitset(len(b.data) * 32)
	for i := 0; i < len(b.data); i++ {
		result.data[i] = b.data[i] & other.data[i]
	}
	return result
}

func (b *Bitset) Xor(other *Bitset) *Bitset {
	result := NewBitset(len(b.data) * 32)
	for i := 0; i < len(b.data); i++ {
		result.data[i] = b.data[i] ^ other.data[i]
	}
	return result
}

func (b *Bitset) ShiftLeft(shift int) *Bitset {
	result := NewBitset(len(b.data) * 32)
	full := shift / 32
	if full >= len(b.data) {
		result.Reset()
		return result
	}
	if full > 0 {
		copy(result.data[full:], b.data)
	}
	shift %= 32
	if shift > 0 {
		for i := len(result.data) - 1; i > 0; i-- {
			result.data[i] = (result.data[i] << shift) | (result.data[i-1] >> (32 - shift))
		}
		result.data[0] <<= shift
	}
	return result
}

func (b *Bitset) ShiftRight(shift int) *Bitset {
	result := NewBitset(len(b.data) * 32)
	full := shift / 32
	if full >= len(b.data) {
		result.Reset()
		return result
	}
	if full > 0 {
		copy(result.data, b.data[full:])
	}
	shift %= 32
	if shift > 0 {
		for i := 0; i < len(result.data)-1; i++ {
			result.data[i] = (result.data[i] >> shift) | (result.data[i+1] << (32 - shift))
		}
		result.data[len(result.data)-1] >>= shift
	}
	return result
}

func (b *Bitset) Count() int {
	count := 0
	for _, val := range b.data {
		count += popcount(val)
	}
	return count
}

func (b *Bitset) None() bool {
	for _, val := range b.data {
		if val != 0 {
			return false
		}
	}
	return true
}

func (b *Bitset) Any() bool {
	for _, val := range b.data {
		if val != 0 {
			return true
		}
	}
	return false
}

func (b *Bitset) Popcount(val uint32) int {
	count := 0
	for val > 0 {
		count++
		val &= val - 1
	}
	return count
}

func popcount(val uint32) int {
	count := 0
	for val > 0 {
		count++
		val &= val - 1
	}
	return count
}

type IG struct {
	good []Bitset
	bad  []Bitset
	bv   []bool
}

func NewIG(n int) *IG {
	good := make([]Bitset, 2*n)
	bad := make([]Bitset, 2*n)
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
				ig.good[i] = *ig.good[i].Or(&ig.good[mid])
				ig.bad[i] = *ig.bad[i].Or(&ig.bad[mid])
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
	t := ig.good[v].Or(&ig.good[ig.neg(v)]).And(ig.bad[v].Or(&ig.bad[ig.neg(v)]))
	if t.Any() {
		return false
	}
	k := 0
	sof := make([]int, 2*n)
	ok := true
	for i := 0; i < n; i++ {
		if ig.good[v].TestPos(i) {
			if ig.num[i] == 0 {
				ok = false
				break
			}
			if ig.num[i] == -1 {
				ig.num[i] = 1
				sof[k] = i
				k++
			}
		}
		if ig.bad[v].TestPos(i) {
			if ig.num[i] == 1 {
				ok = false
				break
			}
			if ig.num[i] == -1 {
				ig.num[i] = 0
				sof[k] = i
				k++
			}
		}
	}

	if !ok {
		for i := 0; i < k; i++ {
			ig.num[sof[i]] = -1
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
}

func (ig *IG) GetNum(a int) int {
	if a > 0 {
		return a - 1
	}
	a = -a
	return n + a - 1
}

func (ig *IG) neg(a int) int {
	if a < n {
		return a + n
	}
	return a - n
}

func main() {
	var n, m1, m2 int
	fmt.Scan(&n, &m1, &m2)

	g1 := NewIG(n)
	g2 := NewIG(n)

	for i := 0; i < m1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g1.Add(a, b)
	}

	for i := 0; i < m2; i++ {
		var a, b int
		fmt.Scan(&a, &b)
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
		return
	}

	if !r2 {
		g1.PrintSolutionAndDie(-1, -1)
		return
	}

	used := make([][]bool, 2*n)
	for i := 0; i < 2*n; i++ {
		used[i] = make([]bool, 2*n)
	}

	cl1 := make([][2]int, m1)
	cl2 := make([][2]int, m2)

	for i := 0; i < m1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		cl1[i] = [2]int{a, b}
		used[g1.GetNum(a)][g1.GetNum(b)] = true
	}

	for i := 0; i < m2; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		cl2[i] = [2]int{a, b}
		used[g2.GetNum(a)][g2.GetNum(b)] = true
	}

	solve(cl1, cl2, g1, g2, m1, m2, used)
	solve(cl2, cl1, g2, g1, m2, m1, used)

	fmt.Println("SIMILAR")
}

func solve(cl1, cl2 [][2]int, g1, g2 *IG, m1, m2 int, used [][]bool) {
	for i := 0; i < m1; i++ {
		v1 := g1.GetNum(cl1[i][0])
		v2 := g1.GetNum(cl1[i][1])
		v1 = g1.neg(v1)
		v2 = g1.neg(v2)
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
		if g2.checkBad(v1, v2) {
			continue
		}
		g2.PrintSolutionAndDie(v1, v2)
	}
}
