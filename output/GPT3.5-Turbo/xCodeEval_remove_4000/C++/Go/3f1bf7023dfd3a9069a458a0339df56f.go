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
	index := pos >> 5
	bit := pos & 31
	b.data[index] |= 1 << bit
}

func (b *Bitset) Reset() {
	for i := 0; i < len(b.data); i++ {
		b.data[i] = 0
	}
}

func (b *Bitset) ResetPos(pos int) {
	index := pos >> 5
	bit := pos & 31
	b.data[index] &= ^(1 << bit)
}

func (b *Bitset) FlipPos(pos int) {
	index := pos >> 5
	bit := pos & 31
	b.data[index] ^= 1 << bit
}

func (b *Bitset) TestPos(pos int) bool {
	index := pos >> 5
	bit := pos & 31
	return (b.data[index]>>bit)&1 == 1
}

func (b *Bitset) Or(other *Bitset) *Bitset {
	res := NewBitset(len(b.data) * 32)
	for i := 0; i < len(b.data); i++ {
		res.data[i] = b.data[i] | other.data[i]
	}
	return res
}

func (b *Bitset) And(other *Bitset) *Bitset {
	res := NewBitset(len(b.data) * 32)
	for i := 0; i < len(b.data); i++ {
		res.data[i] = b.data[i] & other.data[i]
	}
	return res
}

func (b *Bitset) Xor(other *Bitset) *Bitset {
	res := NewBitset(len(b.data) * 32)
	for i := 0; i < len(b.data); i++ {
		res.data[i] = b.data[i] ^ other.data[i]
	}
	return res
}

func (b *Bitset) ShiftLeft(shift int) *Bitset {
	res := NewBitset(len(b.data) * 32)
	full := shift >> 5
	if full >= len(b.data) {
		res.Reset()
		return res
	}
	if full > 0 {
		copy(res.data[full:], b.data[:len(b.data)-full])
	}
	shift &= 31
	if shift > 0 {
		for i := len(b.data) - 1; i >= 1; i-- {
			res.data[i] = (b.data[i] << shift) | (b.data[i-1] >> (32 - shift))
		}
		res.data[0] = b.data[0] << shift
	}
	return res
}

func (b *Bitset) ShiftRight(shift int) *Bitset {
	res := NewBitset(len(b.data) * 32)
	full := shift >> 5
	if full >= len(b.data) {
		res.Reset()
		return res
	}
	if full > 0 {
		copy(res.data, b.data[full:])
	}
	shift &= 31
	if shift > 0 {
		u := (1 << shift) - 1
		for i := 0; i < len(b.data)-1; i++ {
			res.data[i] = (b.data[i] >> shift) | ((b.data[i+1] & u) << (32 - shift))
		}
		res.data[len(b.data)-1] = b.data[len(b.data)-1] >> shift
	}
	return res
}

func (b *Bitset) Count() int {
	count := 0
	for i := 0; i < len(b.data); i++ {
		count += popcount(b.data[i])
	}
	return count
}

func (b *Bitset) None() bool {
	for i := 0; i < len(b.data); i++ {
		if b.data[i] != 0 {
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
	for i := 0; i < len(b.data); i++ {
		count += popcount(b.data[i])
	}
	return count
}

func (b *Bitset) Ctz() int {
	for i := 0; i < len(b.data); i++ {
		if b.data[i] != 0 {
			return ctz(b.data[i]) + i*32
		}
	}
	return len(b.data) * 32
}

func (b *Bitset) Clz() int {
	for i := len(b.data) - 1; i >= 0; i-- {
		if b.data[i] != 0 {
			return clz(b.data[i]) + (len(b.data)-1-i)*32
		}
	}
	return len(b.data) * 32
}

func (b *Bitset) Equals(other *Bitset) bool {
	if len(b.data) != len(other.data) {
		return false
	}
	for i := 0; i < len(b.data); i++ {
		if b.data[i] != other.data[i] {
			return false
		}
	}
	return true
}

func popcount(a uint32) int {
	count := 0
	for a > 0 {
		count++
		a &= a - 1
	}
	return count
}

func ctz(a uint32) int {
	if a == 0 {
		return 32
	}
	count := 0
	for a&1 == 0 {
		count++
		a >>= 1
	}
	return count
}

func clz(a uint32) int {
	if a == 0 {
		return 32
	}
	count := 0
	for a > 0 {
		count++
		a >>= 1
	}
	return count
}

type IG struct {
	good []*Bitset
	bad  []*Bitset
	bv   []bool
}

func NewIG(n int) *IG {
	good := make([]*Bitset, 2*n)
	bad := make([]*Bitset, 2*n)
	for i := 0; i < 2*n; i++ {
		good[i] = NewBitset(2 * n)
		bad[i] = NewBitset(2 * n)
	}
	bv := make([]bool, 2*n)
	return &IG{
		good: good,
		bad:  bad,
		bv:   bv,
	}
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
				ig.good[i] = ig.good[i].Or(ig.good[mid])
				ig.bad[i] = ig.bad[i].Or(ig.bad[mid])
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

func (ig *IG) GetNum(a int) int {
	if a > 0 {
		return a - 1
	}
	a = -a
	return n + a - 1
}

func (ig *IG) Neg(a int) int {
	if a < n {
		return a + n
	}
	return a - n
}

func (ig *IG) CheckBad(v1, v2 int) bool {
	t := ig.good[v1].Or(ig.good[v2]).And(ig.bad[v1].Or(ig.bad[v2]))
	return !t.None()
}

func Solve(cl1, cl2 []int, g1, g2 *IG, m1, m2 int) {
	used := make([][]bool, 2*n)
	for i := 0; i < 2*n; i++ {
		used[i] = make([]bool, 2*n)
	}
	for i := 0; i < m1; i++ {
		v1 := g1.GetNum(cl1[i*2])
		v2 := g1.GetNum(cl1[i*2+1])
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

func (ig *IG) PrintSolutionAndDie(f1, f2 int) {
	num := make([]int, n)
	sof := make([]int, n)
	for i := 0; i < n; i++ {
		num[i] = -1
	}
	if f1 != -1 {
		if f1 < n {
			num[f1] = 1
		} else {
			f1 -= n
			num[f1] = 0
		}
		ig.Select(f1, num, sof)
	}
	if f2 != -1 {
		if num[f2%n] == -1 {
			if f2 < n {
				num[f2] = 1
			} else {
				f2 -= n
				num[f2] = 0
			}
			ig.Select(f2, num, sof)
		}
	}
	for i := 0; i < n; i++ {
		if num[i] == -1 {
			num[i] = 0
			if !ig.Select(i, num, sof) {
				num[i] = 1
				ig.Select(i, num, sof)
			}
		}
	}
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(num[i])
	}
	fmt.Println()
}

func (ig *IG) Select(v int, num, sof []int) bool {
	t := v
	if num[v] == 0 {
		t += n
	}
	if ig.bv[t] {
		return false
	}
	k := 0
	sof[k] = v
	ok := true
	for i := 0; i < n; i++ {
		if ig.good[t].TestPos(i) {
			if num[i] == 0 {
				ok = false
				break
			}
			if num[i] == -1 {
				num[i] = 1
				sof[k] = i
				k++
			}
		}
		if ig.bad[t].TestPos(i) {
			if num[i] == 1 {
				ok = false
				break
			}
			if num[i] == -1 {
				num[i] = 0
				sof[k] = i
				k++
			}
		}
	}
	if !ok {
		for i := 0; i < k; i++ {
			num[sof[i]] = -1
		}
		return false
	}
	return true
}

func main() {
	var n, m1, m2 int
	fmt.Scan(&n, &m1, &m2)

	g1 := NewIG(n)
	for i := 0; i < m1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g1.Add(a, b)
	}

	g2 := NewIG(n)
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
	}

	if !r2 {
		g1.PrintSolutionAndDie(-1, -1)
	}

	cl1 := make([]int, m1*2)
	for i := 0; i < m1; i++ {
		fmt.Scan(&cl1[i*2], &cl1[i*2+1])
	}

	cl2 := make([]int, m2*2)
	for i := 0; i < m2; i++ {
		fmt.Scan(&cl2[i*2], &cl2[i*2+1])
	}

	Solve(cl1, cl2, g1, g2, m1, m2)
	Solve(cl2, cl1, g2, g1, m2, m1)

	fmt.Println("SIMILAR")
}
