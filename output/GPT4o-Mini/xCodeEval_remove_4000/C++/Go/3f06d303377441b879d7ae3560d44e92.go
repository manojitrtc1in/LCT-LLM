package main

import (
	"fmt"
	"math"
	"sort"
)

const MOD = 998244353

type ModInt struct {
	val int
}

func NewModInt(v int64) ModInt {
	if v < 0 {
		v = v%MOD + MOD
	}
	if v >= MOD {
		v %= MOD
	}
	return ModInt{int(v)}
}

func (m ModInt) ModInv() ModInt {
	a, m := m.val, MOD
	g, r, x, y := m, a, 0, 1

	for r != 0 {
		q := g / r
		g, r = r, g%r
		x, y = y-q*x, x
	}

	if x < 0 {
		x += m
	}
	return NewModInt(int64(x))
}

func (m ModInt) Add(other ModInt) ModInt {
	m.val += other.val
	if m.val >= MOD {
		m.val -= MOD
	}
	return m
}

func (m ModInt) Sub(other ModInt) ModInt {
	m.val -= other.val
	if m.val < 0 {
		m.val += MOD
	}
	return m
}

func (m ModInt) Mul(other ModInt) ModInt {
	return NewModInt(int64(m.val) * int64(other.val) % MOD)
}

func (m ModInt) Div(other ModInt) ModInt {
	return m.Mul(other.ModInv())
}

func (m ModInt) Pow(p int64) ModInt {
	result := NewModInt(1)
	a := m

	for p > 0 {
		if p&1 == 1 {
			result = result.Mul(a)
		}
		a = a.Mul(a)
		p >>= 1
	}
	return result
}

func (m ModInt) String() string {
	return fmt.Sprintf("%d", m.val)
}

const INF = int(1e9 + 5)

type SegmentChange struct {
	setMin, setMax int
}

func NewSegmentChange() SegmentChange {
	return SegmentChange{INF, INF}
}

func (sc *SegmentChange) Reset() {
	sc.setMin, sc.setMax = INF, INF
}

func (sc SegmentChange) HasSetMin() bool {
	return sc.setMin != INF
}

func (sc SegmentChange) HasSetMax() bool {
	return sc.setMax != INF
}

func (sc SegmentChange) HasChange() bool {
	return sc.HasSetMin() || sc.HasSetMax()
}

func (sc SegmentChange) Combine(other SegmentChange) SegmentChange {
	return SegmentChange{
		setMin: func() int {
			if other.HasSetMin() {
				return other.setMin
			}
			return sc.setMin
		}(),
		setMax: func() int {
			if other.HasSetMax() {
				return other.setMax
			}
			return sc.setMax
		}(),
	}
}

type Segment struct {
	LProduct, RProduct, Sum ModInt
	Minimum, Maximum        int
}

func NewSegment(L, R, sum ModInt, min, max int) Segment {
	return Segment{L, R, sum, min, max}
}

func (s *Segment) Apply(length int, change SegmentChange) {
	if change.HasSetMin() {
		s.Minimum = change.setMin
	}
	if change.HasSetMax() {
		s.Maximum = change.setMax
	}
}

func (s *Segment) Join(other Segment) {
	s.Sum = s.Sum.Mul(other.RProduct).Add(s.LProduct.Mul(other.Sum)).Sub(s.LProduct.Mul(other.RProduct))
	s.LProduct = s.LProduct.Mul(other.LProduct)
	s.RProduct = s.RProduct.Mul(other.RProduct)
	s.Minimum = int(math.Min(float64(s.Minimum), float64(other.Minimum)))
	s.Maximum = int(math.Max(float64(s.Maximum), float64(other.Maximum)))
}

type SegTree struct {
	treeN  int
	tree   []Segment
	changes []SegmentChange
}

func NewSegTree(n int) SegTree {
	treeN := 1
	for treeN < n {
		treeN *= 2
	}
	return SegTree{
		treeN:  treeN,
		tree:   make([]Segment, 2*treeN),
		changes: make([]SegmentChange, treeN),
	}
}

func (st *SegTree) Build(initial []Segment) {
	n := len(initial)
	for i := 0; i < n; i++ {
		st.tree[st.treeN+i] = initial[i]
	}
	for position := st.treeN - 1; position > 0; position-- {
		st.tree[position].Join(st.tree[2*position], st.tree[2*position+1])
	}
}

func (st *SegTree) PushDown(position, length int) {
	if !st.changes[position].HasChange() {
		return
	}
	if 2*position < st.treeN {
		st.changes[2*position] = st.changes[2*position].Combine(st.changes[position])
		st.changes[2*position+1] = st.changes[2*position+1].Combine(st.changes[position])
	}
	st.tree[2*position].Apply(length/2, st.changes[position])
	st.tree[2*position+1].Apply(length/2, st.changes[position])
	st.changes[position].Reset()
}

func (st *SegTree) JoinAndApply(position, length int) {
	st.tree[position].Join(st.tree[2*position], st.tree[2*position+1])
	st.tree[position].Apply(length, st.changes[position])
}

func (st *SegTree) JoinAll(a, b int) {
	length := 1
	for a > 1 {
		a /= 2
		b /= 2
		length *= 2
		st.JoinAndApply(a, length)
		if a != b {
			st.JoinAndApply(b, length)
		}
	}
}

type Event struct {
	distance, velocity int64
	index, eventType   int
}

func (e Event) GetTime() ModInt {
	return NewModInt(e.distance) / NewModInt(e.velocity)
}

type ByDistance []Event

func (a ByDistance) Len() int           { return len(a) }
func (a ByDistance) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByDistance) Less(i, j int) bool { return a[i].distance*a[j].velocity < a[j].distance*a[i].velocity }

var (
	N                int
	X, V             []int
	L, R             []ModInt
	events           []Event
	tree             SegTree
	currentProbability ModInt
	status           string
)

func id4(x int) int {
	return tree.tree[tree.treeN+x].Minimum
}

func id2(x int) int {
	return tree.tree[tree.treeN+x].Maximum
}

func id3(x, y int) bool {
	return y <= id2(x)
}

func id1(index int, direction byte) ModInt {
	if status[index] == direction {
		return NewModInt(1)
	}
	if status[index] != '?' && status[index] != direction {
		return NewModInt(0)
	}
	minimum := id4(index)
	maximum := id2(index)

	if direction == 'L' {
		left := tree.tree[tree.treeN+minimum].LProduct
		right := tree.tree[tree.treeN+index+1].Sum
		before := tree.tree[tree.treeN+minimum].Sum
		return left.Mul(right).Div(before)
	} else if direction == 'R' {
		left := tree.tree[tree.treeN+minimum].Sum
		right := tree.tree[tree.treeN+index].RProduct
		before := tree.tree[tree.treeN+minimum].Sum
		return left.Mul(right).Div(before)
	}
	return NewModInt(0)
}

func connectFinal(x, y int) {
	if y-x != 1 {
		return
	}
	if status[x] == 'L' || status[y] == 'R' {
		return
	}
	if status[x] == 'R' && status[y] == 'L' {
		currentProbability = NewModInt(0)
		return
	}
	xMin := id4(x)
	yMax := id2(y)

	if status[x] == 'R' {
		for i := y; i <= yMax; i++ {
			status[i] = 'R'
		}
		ySeg := tree.tree[tree.treeN+y].RProduct
		currentProbability = currentProbability.Mul(ySeg.Div(tree.tree[tree.treeN+y].Sum))
		return
	}
	if status[y] == 'L' {
		for i := xMin; i <= x; i++ {
			status[i] = 'L'
		}
		xSeg := tree.tree[tree.treeN+x].LProduct
		currentProbability = currentProbability.Mul(xSeg.Div(tree.tree[tree.treeN+x].Sum))
		return
	}
}

func setFinal(index int, direction byte) {
	if status[index] != '?' {
		if status[index] != direction {
			currentProbability = NewModInt(0)
		}
		return
	}
	minimum := id4(index)
	maximum := id2(index)

	if direction == 'L' {
		currentProbability = currentProbability.Mul(id1(index, 'L'))
		tree.Update(index+1, maximum+1, SegmentChange{index + 1, maximum})
		for i := minimum; i <= index; i++ {
			status[i] = 'L'
		}
	} else if direction == 'R' {
		currentProbability = currentProbability.Mul(id1(index, 'R'))
		tree.Update(minimum, index, SegmentChange{minimum, index - 1})
		for i := index; i <= maximum; i++ {
			status[i] = 'R'
		}
	}
}

func id0() {
	for i := 0; i < N; i++ {
		if status[i] == '?' {
			minimum := id4(i)
			maximum := id2(i)
			for j := minimum; j <= maximum; j++ {
				if status[j] != '?' {
					panic("status mismatch")
				}
			}
		}
	}
}

func main() {
	fmt.Scan(&N)
	X = make([]int, N)
	V = make([]int, N)
	L = make([]ModInt, N)
	R = make([]ModInt, N)

	for i := 0; i < N; i++ {
		var P int
		fmt.Scan(&X[i], &V[i], &P)
		R[i] = NewModInt(int64(P) * NewModInt(100).ModInv().val)
		L[i] = NewModInt(1).Sub(R[i])
	}

	tree = NewSegTree(N)
	initial := make([]Segment, N)

	for i := 0; i < N; i++ {
		initial[i] = NewSegment(L[i], R[i], NewModInt(1), i, i)
	}

	tree.Build(initial)
	status = string(make([]byte, N))
	for i := 0; i < N; i++ {
		status[i] = '?'
	}

	for i := 0; i < N-1; i++ {
		distance := int64(X[i+1] - X[i])
		events = append(events, Event{distance, int64(V[i] + V[i+1]), i, 0})

		if V[i] > V[i+1] {
			events = append(events, Event{distance, int64(V[i] - V[i+1]), i, 1})
		} else if V[i+1] > V[i] {
			events = append(events, Event{distance, int64(V[i+1] - V[i]), i + 1, -1})
		}
	}

	sort.Sort(ByDistance(events))
	currentProbability = NewModInt(1)
	total := NewModInt(0)

	for _, ev := range events {
		if ev.eventType == 0 {
			x := ev.index
			y := ev.index + 1
			if id3(x, y) {
				continue
			}
			probability := currentProbability.Mul(id1(x, 'R')).Mul(id1(y, 'L'))
			total = total.Add(probability.Mul(ev.GetTime()))
			connectFinal(x, y)
		} else {
			x := ev.index
			direction := 'R'
			if ev.eventType < 0 {
				direction = 'L'
			}
			opposite := 'L' + 'R' - direction
			probability := currentProbability.Mul(id1(x, byte(direction)))
			total = total.Add(probability.Mul(ev.GetTime()))
			setFinal(x, opposite)
		}
		if currentProbability.val == 0 {
			break
		}
	}

	fmt.Println(total)
}
