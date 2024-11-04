package main

import (
	"fmt"
	"math/rand"
	"time"
)

const FAST_ALLOCATOR_MEMORY = 1e6 // Define your memory size here

var allocatorPos int
var allocatorMemory [FAST_ALLOCATOR_MEMORY]byte

func new(size int) *byte {
	res := &allocatorMemory[allocatorPos]
	allocatorPos += size
	if allocatorPos > FAST_ALLOCATOR_MEMORY {
		panic("Memory overflow")
	}
	return res
}

func delete(ptr *byte) {}

type BufferFlusher struct{}

func (bf *BufferFlusher) Flush() {
	// Implement flush logic if needed
}

var id4 = &BufferFlusher{}

type ll int64
type ld float64
type pii struct {
	first, second int
}
type ui uint
type ull uint64

func init() {
	rand.Seed(time.Now().UnixNano())
}

func rmax(a *ll, b ll) {
	if *a < b {
		*a = b
	}
}

func rmin(a *ll, b ll) {
	if *a > b {
		*a = b
	}
}

func mul(a, b, m ll) ll {
	return (a * b) % m
}

func binpow(n, p, m ll) ll {
	if p == 0 {
		return 1
	}
	if p&1 == 1 {
		return mul(n, binpow(n, p-1, m), m)
	}
	v := binpow(n, p/2, m)
	return mul(v, v, m)
}

func isPrime(n ll) bool {
	for i := ll(2); i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func factor(n ll) []ll {
	var ans []ll
	for i := ll(2); i*i <= n; i++ {
		for n%i == 0 {
			ans = append(ans, i)
			n /= i
		}
	}
	if n != 1 {
		ans = append(ans, n)
	}
	return ans
}

func id0(n ll) []ll {
	var ret []ll
	for i := ll(1); i*i <= n; i++ {
		if n%i == 0 {
			ret = append(ret, i)
			if i*i != n {
				ret = append(ret, n/i)
			}
		}
	}
	return ret
}

func id9(n ll) []struct {
	first ll
	second int
} {
	fac := factor(n)
	var ret []struct {
		first ll
		second int
	}
	L := 0
	for L < len(fac) {
		R := L
		for R < len(fac) && fac[R] == fac[L] {
			R++
		}
		ret = append(ret, struct {
			first ll
			second int
		}{fac[L], R - L})
		L = R
	}
	return ret
}

func id11(L int) ll {
	L += rand.Intn(4242)
	for !isPrime(ll(L)) {
		L++
	}
	return ll(L)
}

func nmod(a, m ll) ll {
	return (a%m + m) % m
}

func mrand() int {
	return abs(int(rand.Int63() << 15) + rand.Int())
}

type Treap struct {
	left                     *Treap
	right                    *Treap
	t                        ll
	y                        int
	prefixSum                ll
	speed                    ll
	push                     ll
	minPrefixSumInSubtree    ll
}

func NewTreap(t, val, speed ll) *Treap {
	return &Treap{
		t:                        t,
		y:                        mrand(),
		prefixSum:               val,
		speed:                   speed,
		minPrefixSumInSubtree:   val,
	}
}

func vertexAdd(a *Treap, push ll) {
	a.prefixSum += push
	a.minPrefixSumInSubtree += push
	a.push += push
}

func push(a *Treap) {
	pushVal := a.push
	if pushVal == 0 {
		return
	}
	if a.left != nil {
		vertexAdd(a.left, pushVal)
	}
	if a.right != nil {
		vertexAdd(a.right, pushVal)
	}
	a.push = 0
}

const INF = 1e18

func smin(a *Treap) ll {
	if a == nil {
		return INF
	}
	return a.minPrefixSumInSubtree
}

func recalc(a *Treap) {
	a.minPrefixSumInSubtree = min(smin(a.left), min(smin(a.right), a.prefixSum))
}

func merge(a, b *Treap) *Treap {
	if a == nil {
		return b
	}
	if b == nil {
		return a
	}
	if a.y < b.y {
		push(a)
		a.right = merge(a.right, b)
		recalc(a)
		return a
	} else {
		push(b)
		b.left = merge(a, b.left)
		recalc(b)
		return b
	}
}

func split(a *Treap, k ll) (*Treap, *Treap) {
	if a == nil {
		return a, a
	}
	push(a)
	if a.t < k {
		l, r := split(a.right, k)
		a.right = l
		recalc(a)
		return a, r
	} else {
		l, r := split(a.left, k)
		a.left = r
		recalc(a)
		return l, a
	}
}

func id12(a *Treap) *Treap {
	push(a)
	if a.left == nil {
		return a
	}
	return id12(a.left)
}

func id7(a *Treap) *Treap {
	push(a)
	if a.right == nil {
		return a
	}
	return id7(a.right)
}

func id2(a *Treap, v ll) *Treap {
	push(a)
	if smin(a.left) <= v {
		return id2(a.left, v)
	}
	if a.prefixSum <= v {
		return a
	}
	return id2(a.right, v)
}

func printTree(a *Treap) {
	if a == nil {
		return
	}
	printTree(a.left)
	fmt.Print(a.t, " ")
	printTree(a.right)
}

func main() {
	init()
	root := NewTreap(0, 0, 0)
	root = merge(root, NewTreap(2e9, 0, 0))
	q := readInt()
	var t, s, typ int
	for i := 0; i < q; i++ {
		typ = readInt()
		if typ == 1 {
			t = readInt()
			s = readInt()
			l, r := split(root, ll(t))
			vr := id12(r)
			vl := id7(l)
			psum := vl.prefixSum + (ll(t)-vl.t)*vl.speed
			id5 := psum + (vr.t-ll(t))*ll(s)
			vertexAdd(r, id5-vr.prefixSum)
			root = merge(l, merge(NewTreap(ll(t), psum, ll(s)), r))
		} else if typ == 2 {
			t = readInt()
			l, tr := split(root, ll(t))
			y, r := split(tr, ll(t)+1)
			vl := id7(l)
			vr := id12(r)
			id5 := vl.prefixSum + (vr.t-vl.t)*vl.speed
			vertexAdd(r, id5-vr.prefixSum)
			root = merge(l, r)
		} else {
			L := readInt()
			R := readInt()
			v := readInt()
			if v == 0 {
				fmt.Println(L)
				continue
			}
			l, yr := split(root, ll(L))
			y, r := split(yr, ll(R)+1)
			if y == nil {
				fmt.Println(-1)
			} else {
				vl := id12(y)
				vr := id7(y)
				id13 := vl.prefixSum - v
				if y.minPrefixSumInSubtree > id13 {
					id5 := vr.prefixSum + (ll(R)-vr.t)*vr.speed
					if id5 > id13 {
						fmt.Println("-1")
					} else {
						fmt.Printf("%.20f\n", float64(vr.t)+(float64(id13-vr.prefixSum)/float64(vr.speed)))
					}
				} else {
					h := id2(y, id13)
					yl, yr := split(y, h.t)
					vyl := id7(yl)
					fmt.Printf("%.20f\n", float64(vyl.t)+(float64(id13-vyl.prefixSum)/float64(vyl.speed)))
					y = merge(yl, yr)
				}
			}
			root = merge(l, merge(y, r))
		}
	}
}

func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}
