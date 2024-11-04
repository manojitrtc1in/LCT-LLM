package main

import (
	"fmt"
	"math"
	"sort"
)

const MOD = 998244353

type modInt struct {
	val int
}

func newModInt(v int64) modInt {
	if v < 0 {
		v = v%MOD + MOD
	}
	if v >= MOD {
		v %= MOD
	}
	return modInt{val: int(v)}
}

func (m modInt) modInv() modInt {
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
	return newModInt(int64(x))
}

func (m modInt) add(other modInt) modInt {
	m.val += other.val
	if m.val >= MOD {
		m.val -= MOD
	}
	return m
}

func (m modInt) sub(other modInt) modInt {
	m.val -= other.val
	if m.val < 0 {
		m.val += MOD
	}
	return m
}

func (m modInt) mul(other modInt) modInt {
	return newModInt(int64(m.val) * int64(other.val) % MOD)
}

func (m modInt) div(other modInt) modInt {
	return m.mul(other.modInv())
}

func (m modInt) pow(p int64) modInt {
	result := newModInt(1)
	a := m

	for p > 0 {
		if p&1 == 1 {
			result = result.mul(a)
		}
		a = a.mul(a)
		p >>= 1
	}

	return result
}

func (m modInt) String() string {
	return fmt.Sprintf("%d", m.val)
}

const INF = 1e9 + 5

type segmentChange struct {
	setMin, setMax int
}

func newSegmentChange() segmentChange {
	return segmentChange{setMin: math.MinInt32, setMax: math.MinInt32}
}

func (sc *segmentChange) reset() {
	sc.setMin = math.MinInt32
	sc.setMax = math.MinInt32
}

func (sc segmentChange) hasSetMin() bool {
	return sc.setMin != math.MinInt32
}

func (sc segmentChange) hasSetMax() bool {
	return sc.setMax != math.MinInt32
}

func (sc segmentChange) hasChange() bool {
	return sc.hasSetMin() || sc.hasSetMax()
}

func (sc segmentChange) combine(other segmentChange) segmentChange {
	return segmentChange{
		setMin: func() int {
			if other.hasSetMin() {
				return other.setMin
			}
			return sc.setMin
		}(),
		setMax: func() int {
			if other.hasSetMax() {
				return other.setMax
			}
			return sc.setMax
		}(),
	}
}

type segment struct {
	LProduct, RProduct, sum modInt
	minimum, maximum        int
}

func newSegment(L, R, sum modInt, minimum, maximum int) segment {
	return segment{LProduct: L, RProduct: R, sum: sum, minimum: minimum, maximum: maximum}
}

func (s *segment) apply(length int, change segmentChange) {
	if change.hasSetMin() {
		s.minimum = change.setMin
	}
	if change.hasSetMax() {
		s.maximum = change.setMax
	}
}

func (s *segment) join(other segment) {
	s.sum = s.sum.mul(other.RProduct).add(s.LProduct.mul(other.sum)).sub(s.LProduct.mul(other.RProduct))
	s.LProduct = s.LProduct.mul(other.LProduct)
	s.RProduct = s.RProduct.mul(other.RProduct)
	s.minimum = int(math.Min(float64(s.minimum), float64(other.minimum)))
	s.maximum = int(math.Max(float64(s.maximum), float64(other.maximum)))
}

type segTree struct {
	treeN int
	tree   []segment
	changes []segmentChange
}

func newSegTree(n int) segTree {
	treeN := 1
	for treeN < n {
		treeN *= 2
	}
	return segTree{
		treeN: treeN,
		tree:   make([]segment, 2*treeN),
		changes: make([]segmentChange, treeN),
	}
}

func (st *segTree) build(initial []segment) {
	n := len(initial)
	for i := 0; i < n; i++ {
		st.tree[st.treeN+i] = initial[i]
	}
	for position := st.treeN - 1; position > 0; position-- {
		st.tree[position].join(st.tree[2*position], st.tree[2*position+1])
	}
}

func (st *segTree) pushDown(position, length int) {
	if !st.changes[position].hasChange() {
		return
	}
	if 2*position < st.treeN {
		st.changes[2*position] = st.changes[2*position].combine(st.changes[position])
		st.changes[2*position+1] = st.changes[2*position+1].combine(st.changes[position])
	}
	st.tree[2*position].apply(length/2, st.changes[position])
	st.tree[2*position+1].apply(length/2, st.changes[position])
	st.changes[position].reset()
}

func (st *segTree) processRange(a, b int, needsJoin bool, rangeOp func(int, int)) {
	if a == b {
		return
	}
	st.pushAll(a, b)
	originalA, originalB := a, b
	length := 1
	rightHalf := make([][2]int, 0)

	for a += st.treeN; b += st.treeN; a < b; a /= 2, b /= 2 {
		if a&1 == 1 {
			rangeOp(a, length)
			a++
		}
		if b&1 == 1 {
			rightHalf = append(rightHalf, [2]int{b - 1, length})
			b--
		}
	}
	for i := len(rightHalf) - 1; i >= 0; i-- {
		rangeOp(rightHalf[i][0], rightHalf[i][1])
	}
	if needsJoin {
		st.joinAll(originalA, originalB)
	}
}

func (st *segTree) joinAll(a, b int) {
	length := 1
	for a > 1 {
		a /= 2
		b /= 2
		length *= 2
		st.tree[a].join(st.tree[2*a], st.tree[2*a+1])
		st.tree[a].apply(length, st.changes[a])
		if a != b {
			st.tree[b].join(st.tree[2*b], st.tree[2*b+1])
			st.tree[b].apply(length, st.changes[b])
		}
	}
}

type event struct {
	distance, velocity int64
	index, typ         int
}

func (e event) getTime() modInt {
	return newModInt(e.distance) / newModInt(e.velocity)
}

func (e event) less(other event) bool {
	return e.distance*other.velocity < other.distance*e.velocity
}

var rightHalf [32][2]int

var (
	N                int
	X, V             []int
	L, R             []modInt
	events           []event
	tree             segTree
	currentProbability modInt
	status           string
)

func id4(x int) int {
	return tree.query(x, x+1).minimum
}

func id2(x int) int {
	return tree.query(x, x+1).maximum
}

func id3(x, y int) bool {
	return y <= id2(x)
}

func id1(index int, direction byte) modInt {
	if status[index] == direction {
		return newModInt(1)
	}
	if status[index] != '?' && status[index] != direction {
		return newModInt(0)
	}
	minimum := id4(index)
	maximum := id2(index)

	if direction == 'L' {
		left := tree.query(minimum, index+1).LProduct
		right := tree.query(index+1, maximum+1).sum
		before := tree.query(minimum, maximum+1).sum
		return left.mul(right).div(before)
	} else if direction == 'R' {
		left := tree.query(minimum, index).sum
		right := tree.query(index, maximum+1).RProduct
		before := tree.query(minimum, maximum+1).sum
		return left.mul(right).div(before)
	}
	return newModInt(0)
}

func connectFinal(x, y int) {
	if y-x != 1 {
		return
	}
	if status[x] == 'L' || status[y] == 'R' {
		return
	}
	if status[x] == 'R' && status[y] == 'L' {
		currentProbability = newModInt(0)
		return
	}
	xMin := id4(x)
	yMax := id2(y)

	if status[x] == 'R' {
		for i := y; i <= yMax; i++ {
			if status[i] != '?' {
				break
			}
			status[i] = 'R'
		}
		currentProbability = currentProbability.mul(tree.query(y, yMax+1).RProduct).div(tree.query(y, yMax+1).sum)
		return
	}
	if status[y] == 'L' {
		for i := xMin; i <= x; i++ {
			if status[i] != '?' {
				break
			}
			status[i] = 'L'
		}
		currentProbability = currentProbability.mul(tree.query(xMin, x+1).LProduct).div(tree.query(xMin, x+1).sum)
		return
	}
}

func setFinal(index int, direction byte) {
	if status[index] != '?' {
		if status[index] != direction {
			currentProbability = newModInt(0)
		}
		return
	}
	minimum := id4(index)
	maximum := id2(index)

	if direction == 'L' {
		currentProbability = currentProbability.mul(id1(index, 'L'))
		tree.update(index+1, maximum+1, segmentChange{setMin: index + 1, setMax: maximum})
		for i := minimum; i <= index; i++ {
			status[i] = 'L'
		}
	} else if direction == 'R' {
		currentProbability = currentProbability.mul(id1(index, 'R'))
		tree.update(minimum, index, segmentChange{setMin: minimum, setMax: index - 1})
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
					break
				}
			}
		}
	}
}

func main() {
	fmt.Scan(&N)
	X = make([]int, N)
	V = make([]int, N)
	L = make([]modInt, N)
	R = make([]modInt, N)

	for i := 0; i < N; i++ {
		var P int
		fmt.Scan(&X[i], &V[i], &P)
		R[i] = newModInt(int64(P)).mul(newModInt(100).modInv())
		L[i] = newModInt(1).sub(R[i])
	}

	tree = newSegTree(N)
	initial := make([]segment, N)

	for i := 0; i < N; i++ {
		initial[i] = newSegment(L[i], R[i], newModInt(1), i, i)
	}

	tree.build(initial)
	status = string(make([]byte, N))
	for i := 0; i < N; i++ {
		status[i] = '?'
	}

	for i := 0; i < N-1; i++ {
		distance := int64(X[i+1] - X[i])
		events = append(events, event{distance, int64(V[i] + V[i+1]), i, 0})

		if V[i] > V[i+1] {
			events = append(events, event{distance, int64(V[i] - V[i+1]), i, 1})
		} else if V[i+1] > V[i] {
			events = append(events, event{distance, int64(V[i+1] - V[i]), i + 1, -1})
		}
	}

	sort.Slice(events, func(i, j int) bool {
		return events[i].less(events[j])
	})

	currentProbability = newModInt(1)
	total := newModInt(0)

	for _, ev := range events {
		if ev.typ == 0 {
			x := ev.index
			y := ev.index + 1
			if id3(x, y) {
				continue
			}
			probability := currentProbability.mul(id1(x, 'R')).mul(id1(y, 'L'))
			total = total.add(probability.mul(ev.getTime()))
			connectFinal(x, y)
		} else {
			x := ev.index
			direction := 'R'
			if ev.typ < 0 {
				direction = 'L'
			}
			opposite := 'L' + 'R' - direction
			probability := currentProbability.mul(id1(x, direction))
			total = total.add(probability.mul(ev.getTime()))
			setFinal(x, opposite)
		}
		if currentProbability.val == 0 {
			break
		}
	}

	fmt.Println(total)
}
