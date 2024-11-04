package main

import (
	"bufio"
	"fmt"
	"os"
)

type Bitset struct {
	data []uint
}

func NewBitset(n int) *Bitset {
	data := make([]uint, (n+31)/32)
	return &Bitset{data: data}
}

func (b *Bitset) Set() {
	for i := 0; i < len(b.data); i++ {
		b.data[i] = ^uint(0)
	}
}

func (b *Bitset) SetPos(pos int) {
	b.data[pos>>5] |= 1 << (pos & 31)
}

func (b *Bitset) Reset() {
	for i := 0; i < len(b.data); i++ {
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
	full := shift >> 5
	if full >= len(b.data) {
		b.Reset()
		return b
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

	return b
}

func (b *Bitset) ShiftRight(shift int) *Bitset {
	full := shift >> 5
	if full >= len(b.data) {
		b.Reset()
		return b
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

	return b
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

func popcount(x uint) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}

func ctz(x uint) int {
	count := 0
	for x&1 == 0 {
		count++
		x >>= 1
	}
	return count
}

func clz(x uint) int {
	count := 0
	for x != 0 {
		count++
		x >>= 1
	}
	return 32 - count
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
	t := v
	if ig.Num[v] == 0 {
		t += n
	}
	if ig.bv[t] {
		return false
	}
	k := 0
	sof := make([]int, 0)
	sof = append(sof, v)
	ok := true
	for i := 0; i < n; i++ {
		if ig.good[t].TestPos(i) {
			if ig.Num[i] == 0 {
				ok = false
				break
			}
			if ig.Num[i] == -1 {
				ig.Num[i] = 1
				sof = append(sof, i)
			}
		}
		if ig.bad[t].TestPos(i) {
			if ig.Num[i] == 1 {
				ok = false
				break
			}
			if ig.Num[i] == -1 {
				ig.Num[i] = 0
				sof = append(sof, i)
			}
		}
	}

	if !ok {
		for i := 0; i < len(sof); i++ {
			ig.Num[sof[i]] = -1
		}
		return false
	}
	return true
}

func (ig *IG) PrintSolutionAndDie(f1, f2 int) {
	for i := 0; i < n; i++ {
		ig.Num[i] = -1
	}
	if f1 != -1 {
		if f1 < n {
			ig.Num[f1] = 1
		} else {
			f1 -= n
			ig.Num[f1] = 0
		}
		ig.Select(f1)
	}
	if f2 != -1 {
		if ig.Num[f2 < n ? f2 : f2-n] == -1 {
			if f2 < n {
				ig.Num[f2] = 1
			} else {
				f2 -= n
				ig.Num[f2] = 0
			}
			ig.Select(f2)
		}
	}
	for i := 0; i < n; i++ {
		if ig.Num[i] != -1 {
			continue
		}
		ig.Num[i] = 0
		if !ig.Select(i) {
			ig.Num[i] = 1
			ig.Select(i)
		}
	}
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(ig.Num[i])
	}
	fmt.Println()
	os.Exit(0)
}

func (ig *IG) CheckBad(v1, v2 int) bool {
	t := ig.good[v1].Or(&ig.good[v2]).And(ig.bad[v1].Or(&ig.bad[v2]))
	return t.Any()
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n = atoi(scanner.Text())
	scanner.Scan()
	m1 = atoi(scanner.Text())
	scanner.Scan()
	m2 = atoi(scanner.Text())

	g1 := NewIG(n)
	g2 := NewIG(n)

	for i := 0; i < m1; i++ {
		scanner.Scan()
		a := atoi(scanner.Text())
		scanner.Scan()
		b := atoi(scanner.Text())
		g1.Add(a, b)
	}

	for i := 0; i < m2; i++ {
		scanner.Scan()
		a := atoi(scanner.Text())
		scanner.Scan()
		b := atoi(scanner.Text())
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

	solve(cl1, cl2, g1, g2, m1, m2)
	solve(cl2, cl1, g2, g1, m2, m1)

	fmt.Println("SIMILAR")
}

func atoi(s string) int {
	var res int
	var neg bool
	for i := 0; i < len(s); i++ {
		if s[i] == '-' {
			neg = true
			continue
		}
		res = res*10 + int(s[i]-'0')
	}
	if neg {
		res = -res
	}
	return res
}

func solve(cl1, cl2 []pair, g1, g2 *IG, m1, m2 int) {
	used := make([][]bool, 2*n)
	for i := 0; i < 2*n; i++ {
		used[i] = make([]bool, 2*n)
	}

	for i := 0; i < m1; i++ {
		v1 := g1.GetNum(cl1[i].x)
		v2 := g1.GetNum(cl1[i].y)
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

type pair struct {
	x, y int
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
