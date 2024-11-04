package main

import (
	"fmt"
	"math/bits"
	"os"
)

const N = 1004
const M = 2004

type Bitset [M / 32]uint32

func (b *Bitset) Set() {
	for i := range b {
		b[i] = 0xFFFFFFFF
	}
}

func (b *Bitset) SetPos(pos int) {
	b[pos/32] |= 1 << (pos % 32)
}

func (b *Bitset) Reset() {
	for i := range b {
		b[i] = 0
	}
}

func (b *Bitset) ResetPos(pos int) {
	b[pos/32] &^= 1 << (pos % 32)
}

func (b *Bitset) Flip(pos int) {
	b[pos/32] ^= 1 << (pos % 32)
}

func (b *Bitset) Test(pos int) bool {
	return (b[pos/32]>>(pos%32))&1 != 0
}

func (b *Bitset) Or(other *Bitset) {
	for i := range b {
		b[i] |= other[i]
	}
}

func (b *Bitset) And(other *Bitset) {
	for i := range b {
		b[i] &= other[i]
	}
}

func (b *Bitset) Count() int {
	count := 0
	for _, v := range b {
		count += bits.OnesCount32(v)
	}
	return count
}

func (b *Bitset) Any() bool {
	for _, v := range b {
		if v != 0 {
			return true
		}
	}
	return false
}

type IG struct {
	good [M]Bitset
	bad  [M]Bitset
	bv   [M]bool
}

func NewIG() IG {
	var ig IG
	for i := range ig.good {
		ig.good[i].Reset()
		ig.bad[i].Reset()
	}
	return ig
}

func (ig *IG) GetNum(a int) int {
	if a > 0 {
		return a - 1
	}
	a = -a
	return N + a - 1
}

func (ig *IG) Neg(a int) int {
	if a < N {
		return a + N
	}
	return a - N
}

func (ig *IG) AddImplication(a, b int) {
	a = ig.GetNum(a)
	b = ig.GetNum(b)
	if b < N {
		ig.good[a].SetPos(b)
	} else {
		ig.bad[a].SetPos(b - N)
	}
}

func (ig *IG) Add(a, b int) {
	ig.AddImplication(-a, b)
	ig.AddImplication(-b, a)
}

func (ig *IG) TransitiveClosure() {
	for i := 0; i < 2*N; i++ {
		if i < N {
			ig.good[i].SetPos(i)
		} else {
			ig.bad[i].SetPos(i - N)
		}
	}
	for mid := 0; mid < 2*N; mid++ {
		for i := 0; i < 2*N; i++ {
			ok := false
			if mid < N {
				if ig.good[i].Test(mid) {
					ok = true
				}
			} else {
				if ig.bad[i].Test(mid - N) {
					ok = true
				}
			}
			if ok {
				ig.good[i].Or(&ig.good[mid])
				ig.bad[i].Or(&ig.bad[mid])
			}
		}
	}

	for i := 0; i < 2*N; i++ {
		if i < N {
			if ig.bad[i].Test(i) {
				ig.bv[i] = true
			}
		} else {
			if ig.good[i].Test(i - N) {
				ig.bv[i] = true
			}
		}
	}

	for i := 0; i < 2*N; i++ {
		for j := 0; j < 2*N; j++ {
			if !ig.bv[j] {
				continue
			}
			if j < N {
				if ig.good[i].Test(j) {
					ig.bv[i] = true
				}
			} else {
				if ig.bad[i].Test(j - N) {
					ig.bv[i] = true
				}
			}
		}
	}
}

func (ig *IG) HasSolution() bool {
	for i := 0; i < N; i++ {
		if ig.bad[i].Test(i) && ig.good[i+N].Test(i) {
			return false
		}
	}
	return true
}

var num [N]int
var sof [N]int

func (ig *IG) Select(v int) bool {
	t := v
	if num[v] == 0 {
		t += N
	}
	if ig.bv[t] {
		return false
	}
	k := 0
	sof[k] = v
	k++
	ok := true
	for i := 0; i < N; i++ {
		if ig.good[t].Test(i) {
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
		if ig.bad[t].Test(i) {
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

func (ig *IG) PrintSolutionAndDie(f1, f2 int) {
	for i := range num {
		num[i] = -1
	}
	if f1 != -1 {
		if f1 < N {
			num[f1] = 1
		} else {
			f1 -= N
			num[f1] = 0
		}
		ig.Select(f1)
	}
	if f2 != -1 {
		if num[f2] == -1 {
			if f2 < N {
				num[f2] = 1
			} else {
				f2 -= N
				num[f2] = 0
			}
			ig.Select(f2)
		}
	}
	for i := 0; i < N; i++ {
		if num[i] != -1 {
			continue
		}
		num[i] = 0
		if !ig.Select(i) {
			num[i] = 1
			ig.Select(i)
		}
	}
	for i := 0; i < N; i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(num[i])
	}
	fmt.Println()
	os.Exit(0)
}

func (ig *IG) CheckBad(v1, v2 int) bool {
	t := Bitset{}
	for i := range t {
		t[i] = ig.good[v1][i] | ig.good[v2][i]
	}
	for i := range t {
		t[i] &= ig.bad[v1][i] | ig.bad[v2][i]
	}
	return t.Any()
}

var cl1 [1000002][2]int
var cl2 [1000002][2]int

func Solve(cl1, cl2 [][2]int, g1, g2 IG, m1, m2 int) {
	used := [M][M]bool{}
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

func main() {
	var n, m1, m2 int
	fmt.Scan(&n, &m1, &m2)

	g1 := NewIG()
	g2 := NewIG()

	for i := 0; i < m1; i++ {
		fmt.Scan(&cl1[i][0], &cl1[i][1])
		g1.Add(cl1[i][0], cl1[i][1])
	}
	for i := 0; i < m2; i++ {
		fmt.Scan(&cl2[i][0], &cl2[i][1])
		g2.Add(cl2[i][0], cl2[i][1])
	}
	g1.TransitiveClosure()
	g2.TransitiveClosure()

	r1 := g1.HasSolution()
	r2 := g2.HasSolution()
	if !r1 && !r2 {
		fmt.Println("SIMILAR")
		os.Exit(0)
	}
	if !r1 {
		g2.PrintSolutionAndDie(-1, -1)
	}
	if !r2 {
		g1.PrintSolutionAndDie(-1, -1)
	}
	Solve(cl1[:m1], cl2[:m2], g1, g2, m1, m2)
	Solve(cl2[:m2], cl1[:m1], g2, g1, m2, m1)
	fmt.Println("SIMILAR")
}
