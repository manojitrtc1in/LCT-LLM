package main

import (
	"fmt"
	"math/rand"
	"sync"
)

type Point struct {
	x, y int
}

type Modular struct {
	m int
}

func NewModular(m int) *Modular {
	return &Modular{m: m}
}

func (mod *Modular) ValueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod *Modular) Mul(x, y int) int {
	return mod.ValueOf(x * y)
}

func (mod *Modular) Plus(x, y int) int {
	return mod.ValueOf(x + y)
}

type Factorial struct {
	fact, inv []int
	modular   *Modular
}

func NewFactorial(limit int, modular *Modular) *Factorial {
	fact := make([]int, limit+1)
	inv := make([]int, limit+1)
	fact[0], inv[0] = 1, 1
	for i := 1; i <= limit; i++ {
		fact[i] = modular.Mul(fact[i-1], i)
		inv[i] = modular.Mul(inv[i-1], Inverse(i, modular))
	}
	return &Factorial{fact: fact, inv: inv, modular: modular}
}

func (f *Factorial) Fact(n int) int {
	return f.fact[n]
}

func (f *Factorial) InvFact(n int) int {
	return f.inv[n]
}

func Inverse(n int, mod *Modular) int {
	return mod.Mul(-mod.m/n, mod.ValueOf(n))
}

type Combination struct {
	factorial *Factorial
	modular   *Modular
}

func NewCombination(limit int, modular *Modular) *Combination {
	return &Combination{factorial: NewFactorial(limit, modular), modular: modular}
}

func (c *Combination) Combination(m, n int) int {
	if n > m {
		return 0
	}
	return c.modular.Mul(c.modular.Mul(c.factorial.Fact(m), c.factorial.InvFact(n)), c.factorial.InvFact(m-n))
}

type DSU struct {
	p, rank, size []int
}

func NewDSU(n int) *DSU {
	p := make([]int, n)
	rank := make([]int, n)
	size := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i
		rank[i] = 0
		size[i] = 1
	}
	return &DSU{p: p, rank: rank, size: size}
}

func (dsu *DSU) Find(a int) int {
	if dsu.p[a] != a {
		dsu.p[a] = dsu.Find(dsu.p[a])
	}
	return dsu.p[a]
}

func (dsu *DSU) Merge(a, b int) {
	a = dsu.Find(a)
	b = dsu.Find(b)
	if a == b {
		return
	}
	if dsu.rank[a] < dsu.rank[b] {
		a, b = b, a
	}
	dsu.size[a] += dsu.size[b]
	dsu.p[b] = a
	if dsu.rank[a] == dsu.rank[b] {
		dsu.rank[a]++
	}
}

type id7 struct{}

func (solver *id7) Solve(testNumber int, in *FastInput, out *FastOutput) {
	n := in.ReadInt()
	pts := make([]Point, n)
	for i := 0; i < n; i++ {
		pts[i] = Point{x: in.ReadInt(), y: in.ReadInt()}
	}

	x := NewHashMap(n)
	y := NewHashMap(n)
	dsu := NewDSU(n)

	for i := 0; i < n; i++ {
		if x.ContainsKey(pts[i].x) {
			dsu.Merge(x.Get(pts[i].x), i)
		}
		if y.ContainsKey(pts[i].y) {
			dsu.Merge(y.Get(pts[i].y), i)
		}
		x.Put(pts[i].x, i)
		y.Put(pts[i].y, i)
	}

	xStack := NewStack(n)
	yStack := NewStack(n)

	for i := 0; i < n; i++ {
		xStack.AddLast(dsu.Find(i), pts[i].x)
		yStack.AddLast(dsu.Find(i), pts[i].y)
	}

	xList := NewIntegerList(n)
	yList := NewIntegerList(n)

	mod := NewModular(int(1e9 + 7))
	comb := NewCombination(2*n, mod)
	ans := 1

	for i := 0; i < n; i++ {
		if dsu.Find(i) != i {
			continue
		}
		xList.Clear()
		yList.Clear()
		xList.AddAll(xStack.Iterator(i))
		yList.AddAll(yStack.Iterator(i))
		xList.Unique()
		yList.Unique()

		line := xList.Size() + yList.Size()
		num := dsu.size[i]
		local := 0
		for j := 0; j <= num; j++ {
			local = mod.Plus(local, comb.Combination(line, j))
		}

		ans = mod.Mul(ans, local)
	}

	out.Println(ans)
}

type FastInput struct {
	// Implementation of FastInput
}

func (in *FastInput) ReadInt() int {
	// Implementation of ReadInt
	return 0
}

type FastOutput struct {
	// Implementation of FastOutput
}

func (out *FastOutput) Println(v int) {
	fmt.Println(v)
}

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		in := &FastInput{}
		out := &FastOutput{}
		solver := &id7{}
		solver.Solve(1, in, out)
	}()
	wg.Wait()
}
