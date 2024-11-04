package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type frac struct {
	n int64
	d int64
}

func newFrac(n int64, d int64) frac {
	if n == 0 && d == 0 {
		panic("Invalid fraction")
	}
	if d < 0 {
		n *= -1
		d *= -1
	}
	g := gcd(abs(n), d)
	n /= g
	d /= g
	return frac{n, d}
}

func (f frac) String() string {
	return fmt.Sprintf("%d/%d", f.n, f.d)
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func min(a, b frac) frac {
	if a <= b {
		return a
	}
	return b
}

func max(a, b frac) frac {
	if a >= b {
		return a
	}
	return b
}

func bestIn(x, y frac) frac {
	if x < y {
		panic("Invalid range")
	}

	x1 := x.toCont()
	y1 := y.toCont()
	x2 := make([]int64, len(x1))
	copy(x2, x1)
	x2[len(x2)-1]--
	x2 = append(x2, 1)
	y2 := make([]int64, len(y1))
	copy(y2, y1)
	y2[len(y2)-1]--
	y2 = append(y2, 1)

	z := func(a, b []int64) frac {
		c := make([]int64, 0)
		for i := 0; ; i++ {
			var ai, bi int64
			if i < len(a) {
				ai = a[i]
			} else {
				ai = 1<<63 - 1
			}
			if i < len(b) {
				bi = b[i]
			} else {
				bi = 1<<63 - 1
			}
			if ai != bi {
				c = append(c, min(ai, bi)+1)
				return fromCont(c)
			}
			c = append(c, ai)
		}
	}

	ans := newFrac(1, 0)
	for _, f := range []frac{z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)} {
		if x < f && f < y && (ans.d == 0 || f.d < ans.d) {
			ans = f
		}
	}
	return ans
}

func (f frac) toCont() []int64 {
	if f.d == 0 {
		return []int64{1<<63 - 1}
	}
	cont := make([]int64, 0)
	for n, d := f.n, f.d; ; n, d = d, n {
		f := (n + d - 1) / d
		cont = append(cont, f)
		n -= f * d
		if n == 0 {
			break
		}
	}
	return cont
}

func fromCont(cont []int64) frac {
	n, d := int64(1), int64(0)
	for i := len(cont) - 1; i >= 0; i-- {
		n, d = d, n
		n += d * cont[i]
	}
	return newFrac(n, d)
}

type modnum struct {
	v int
}

func newModnum(v int) modnum {
	if v < 0 {
		v += 998244353
	}
	return modnum{v % 998244353}
}

func (m modnum) String() string {
	return strconv.Itoa(m.v)
}

func (m modnum) add(o modnum) modnum {
	return newModnum(m.v + o.v)
}

func (m modnum) sub(o modnum) modnum {
	return newModnum(m.v - o.v)
}

func (m modnum) mul(o modnum) modnum {
	return newModnum(int(int64(m.v) * int64(o.v) % 998244353))
}

func (m modnum) inv() modnum {
	return newModnum(m.pow(998244353 - 2))
}

func (m modnum) pow(e int) int {
	if e < 0 {
		return m.inv().pow(-e)
	}
	if e == 0 {
		return 1
	}
	if e&1 == 1 {
		return m.mul(m.pow(e - 1))
	}
	return m.mul(m).pow(e / 2)
}

func (m modnum) div(o modnum) modnum {
	return m.mul(o.inv())
}

func (m modnum) factorial(n int) modnum {
	fact := make([]modnum, n+1)
	fact[0] = newModnum(1)
	for i := 1; i <= n; i++ {
		fact[i] = fact[i-1].mul(newModnum(i))
	}
	return fact[n]
}

func (m modnum) inverseFactorial(n int) modnum {
	invFact := make([]modnum, n+1)
	invFact[n] = m.factorial(n).inv()
	for i := n - 1; i >= 0; i-- {
		invFact[i] = invFact[i+1].mul(newModnum(i + 1))
	}
	return invFact[n]
}

func (m modnum) smallInv(n int) modnum {
	return m.factorial(n - 1).mul(m.inverseFactorial(n))
}

func (m modnum) ncr(n, r int) modnum {
	if r < 0 || n < r {
		return newModnum(0)
	}
	return m.factorial(n).mul(m.inverseFactorial(r)).mul(m.inverseFactorial(n - r))
}

type node struct {
	p     [4]modnum
	noLL  bool
	noRR  bool
	noRL  bool
	none  bool
}

func newNode() node {
	return node{
		p:    [4]modnum{0, 0, 0, 0},
		none: true,
	}
}

func nn(a, b node) node {
	if a.none {
		return b
	}
	if b.none {
		return a
	}
	r := b
	r.none = false
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			iF := i&1 == 1
			iB := (i>>1)&1 == 1
			jF := j&1 == 1
			jB := (j>>1)&1 == 1
			if a.noLL && !iB && !jF {
				continue
			}
			if a.noRR && iB && jF {
				continue
			}
			if a.noRL && iB && !jF {
				continue
			}
			r.p[iF+2*jB] = r.p[iF+2*jB].add(a.p[i].mul(b.p[j]))
		}
	}
	return r
}

type segmentTree struct {
	SZ    int
	id    node
	table []node
}

func newSegmentTree(SZ int, id node) *segmentTree {
	st := &segmentTree{
		SZ:    SZ,
		id:    id,
		table: make([]node, 2*SZ),
	}
	return st
}

func (st *segmentTree) setLeaves(create func(int) node) {
	for i := 0; i < st.SZ; i++ {
		st.table[st.SZ+i] = create(i)
	}
	for i := st.SZ - 1; i > 0; i-- {
		st.table[i] = nn(st.table[2*i], st.table[2*i+1])
	}
}

func (st *segmentTree) replace(i int, v node) {
	st.table[i+st.SZ] = v
	for i /= 2; i > 0; i /= 2 {
		st.table[i] = nn(st.table[2*i], st.table[2*i+1])
	}
}

func (st *segmentTree) query(i, j int) node {
	left := st.id
	right := st.id
	for i += st.SZ; i < j; i /= 2 {
		if i&1 == 1 {
			left = nn(left, st.table[i])
			i++
		}
		if j&1 == 1 {
			i--
			right = nn(st.table[i], right)
		}
		j /= 2
	}
	return nn(left, right)
}

func (st *segmentTree) get(i int) node {
	return st.table[st.SZ+i]
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	N := nextInt(scanner)
	pipes := make([][3]int, N)
	for i := 0; i < N; i++ {
		pipes[i][0] = nextInt(scanner)
		pipes[i][1] = nextInt(scanner)
		pipes[i][2] = nextInt(scanner)
	}

	type dir int
	const (
		LL dir = iota
		RR
		RL
	)

	type event struct {
		i int
		d dir
		t frac
	}

	evs := make([]event, 0)
	for i := 0; i < N-1; i++ {
		dx := pipes[i+1][0] - pipes[i][0]
		dv := pipes[i+1][1] - pipes[i][1]

		evs = append(evs, event{i, RL, newFrac(int64(dx), int64(pipes[i+1][1]+pipes[i][1]))})

		if dv > 0 {
			evs = append(evs, event{i, LL, newFrac(int64(dx), int64(dv))})
		}
		if dv < 0 {
			evs = append(evs, event{i, RR, newFrac(int64(dx), -int64(dv))})
		}
	}

	sort.Slice(evs, func(i, j int) bool {
		return evs[i].t.n*evs[j].t.d < evs[j].t.n*evs[i].t.d
	})

	st := newSegmentTree(N, newNode())
	st.setLeaves(func(i int) node {
		pR := newModnum(pipes[i][2]).mul(newModnum(100).inv())
		r := newNode()
		r.p = [4]modnum{newModnum(1).sub(pR), newModnum(0), newModnum(0), pR}
		r.none = false
		return r
	})

	ans := newModnum(0)
	prob := newModnum(1)
	for _, e := range evs {
		c := st.get(e.i)
		switch e.d {
		case LL:
			c.noLL = true
		case RR:
			c.noRR = true
		case RL:
			c.noRL = true
		}
		st.replace(e.i, c)

		u := st.query(0, st.SZ)
		PROB := u.p[0].add(u.p[1]).add(u.p[2]).add(u.p[3])
		ans = ans.add(prob.sub(PROB).mul(newModnum(e.t.n).mul(newModnum(e.t.d).inv())))
		prob = PROB
	}

	fmt.Println(ans)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
