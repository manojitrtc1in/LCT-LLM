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
	return segmentChange{setMin: math.MinInt, setMax: math.MinInt}
}

func (sc *segmentChange) reset() {
	sc.setMin = math.MinInt
	sc.setMax = math.MinInt
}

func (sc segmentChange) hasSetMin() bool {
	return sc.setMin != math.MinInt
}

func (sc segmentChange) hasSetMax() bool {
	return sc.setMax != math.MinInt
}

func (sc segmentChange) hasChange() bool {
	return sc.hasSetMin() || sc.hasSetMax()
}

func (sc segmentChange) combine(other segmentChange) segmentChange {
	return segmentChange{
		setMin: other.hasSetMin() ? other.setMin : sc.setMin,
		setMax: other.hasSetMax() ? other.setMax : sc.setMax,
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
	treeN  int
	tree   []segment
	changes []segmentChange
}

func newSegTree(n int) segTree {
	st := segTree{}
	st.init(n)
	return st
}

func (st *segTree) init(n int) {
	st.treeN = 1
	for st.treeN < n {
		st.treeN *= 2
	}
	st.tree = make([]segment, 2*st.treeN)
	st.changes = make([]segmentChange, st.treeN)
}

func (st *segTree) build(initial []segment) {
	n := len(initial)
	st.init(n)

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

func (st *segTree) joinAndApply(position, length int) {
	st.tree[position].join(st.tree[2*position], st.tree[2*position+1])
	st.tree[position].apply(length, st.changes[position])
}

func (st *segTree) processRange(a, b int, needsJoin bool, rangeOp func(int, int)) {
	if a == b {
		return
	}
	st.pushAll(a, b)
	originalA, originalB := a, b
	length := 1
	rightHalf := make([][2]int, 0)

	for a += st.treeN; b += st.treeN; a < b; a /= 2 {
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

func (st *segTree) query(a, b int) segment {
	answer := segment{}
	st.processRange(a, b, false, func(position, _ int) {
		answer.join(st.tree[position])
	})
	return answer
}

func (st *segTree) update(a, b int, change segmentChange) {
	st.processRange(a, b, true, func(position, length int) {
		st.tree[position].apply(length, change)
		if position < st.treeN {
			st.changes[position] = st.changes[position].combine(change)
		}
	})
}

type event struct {
	distance, velocity int64
	index, typ         int
}

func newEvent(distance, velocity int64, index, typ int) event {
	return event{distance: distance, velocity: velocity, index: index, typ: typ}
}

func (e event) getTime() modInt {
	return newModInt(e.distance) / newModInt(e.velocity)
}

func (e event) less(other event) bool {
	return e.distance*other.velocity < other.distance*e.velocity
}

var INV100 = newModInt(100).modInv()

var N int
var X, V []int
var L, R []modInt
var events []event
var tree segTree
var currentProbability modInt
var status string

func getMinimum(x int) int {
	return tree.query(x, x+1).minimum
}

func getMaximum(x int) int {
	return tree.query(x, x+1).maximum
}

func inSameComponent(x, y int) bool {
	return y <= getMaximum(x)
}

func getChangeBySetting(index int, direction byte) modInt {
	if status[index] == direction {
		return newModInt(1)
	}
	if status[index] != '?' && status[index] != direction {
		return newModInt(0)
	}

	minimum := getMinimum(index)
	maximum := getMaximum(index)

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

	panic("unreachable")
}

func connectFinal(x, y int) {
	if y-x != 1 {
		panic("invalid connection")
	}

	if status[x] == 'L' || status[y] == 'R' {
		return
	}

	if status[x] == 'R' && status[y] == 'L' {
		currentProbability = newModInt(0)
		return
	}

	xMin := getMinimum(x)
	yMax := getMaximum(y)

	if status[x] == 'R' {
		for i := y; i <= yMax; i++ {
			if status[i] != '?' {
				panic("invalid status")
			}
			status[i] = 'R'
		}
		currentProbability = currentProbability.mul(tree.query(y, yMax+1).RProduct).div(tree.query(y, yMax+1).sum)
		return
	}

	if status[y] == 'L' {
		for i := xMin; i <= x; i++ {
			if status[i] != '?' {
				panic("invalid status")
			}
			status[i] = 'L'
		}
		currentProbability = currentProbability.mul(tree.query(xMin, x+1).LProduct).div(tree.query(xMin, x+1).sum)
		return
	}

	if status[x] == '?' && status[y] == '?' {
		tree.update(xMin, yMax+1, segmentChange{setMin: xMin, setMax: yMax})
		currentProbability = currentProbability.mul(tree.query(xMin, yMax+1).sum).div(tree.query(xMin, x+1).sum.mul(tree.query(y, yMax+1).sum))
	}
}

func setFinal(index int, direction byte) {
	if status[index] != '?' {
		if status[index] != direction {
			currentProbability = newModInt(0)
		}
		return
	}

	minimum := getMinimum(index)
	maximum := getMaximum(index)

	if direction == 'L' {
		currentProbability = currentProbability.mul(getChangeBySetting(index, 'L'))
		tree.update(index+1, maximum+1, segmentChange{setMin: index + 1, setMax: maximum})

		for i := minimum; i <= index; i++ {
			if status[i] != '?' {
				panic("invalid status")
			}
			status[i] = 'L'
		}
	} else if direction == 'R' {
		currentProbability = currentProbability.mul(getChangeBySetting(index, 'R'))
		tree.update(minimum, index, segmentChange{setMin: minimum, setMax: index - 1})

		for i := index; i <= maximum; i++ {
			if status[i] != '?' {
				panic("invalid status")
			}
			status[i] = 'R'
		}
	} else {
		panic("unreachable")
	}
}

func checkValidity() {
	for i := 0; i < N; i++ {
		if status[i] == '?' {
			minimum := getMinimum(i)
			maximum := getMaximum(i)

			for j := minimum; j <= maximum; j++ {
				if status[j] != '?' {
					panic("invalid status")
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
		R[i] = newModInt(int64(P)).mul(INV100)
		L[i] = newModInt(1).sub(R[i])
	}

	tree = newSegTree(N)
	initial := make([]segment, N)

	for i := 0; i < N; i++ {
		initial[i] = newSegment(L[i], R[i], newModInt(1), i, i)
	}

	tree.build(initial)
	status = string(make([]byte, N))
	for i := range status {
		status[i] = '?'
	}

	for i := 0; i < N-1; i++ {
		distance := int64(X[i+1] - X[i])
		events = append(events, newEvent(distance, int64(V[i]+V[i+1]), i, 0))

		if V[i] > V[i+1] {
			events = append(events, newEvent(distance, int64(V[i]-V[i+1]), i, 1))
		} else if V[i+1] > V[i] {
			events = append(events, newEvent(distance, int64(V[i+1]-V[i]), i+1, -1))
		}
	}

	sort.Slice(events, func(i, j int) bool {
		return events[i].less(events[j])
	})

	currentProbability = newModInt(1)
	total := newModInt(0)

	for _, ev := range events {
		if ev.typ == 0 {
			x, y := ev.index, ev.index+1
			if inSameComponent(x, y) {
				panic("invalid component")
			}
			probability := currentProbability.mul(getChangeBySetting(x, 'R')).mul(getChangeBySetting(y, 'L'))
			total = total.add(probability.mul(ev.getTime()))
			connectFinal(x, y)
		} else {
			x := ev.index
			direction := 'R'
			if ev.typ < 0 {
				direction = 'L'
			}
			opposite := 'L' + 'R' - direction
			probability := currentProbability.mul(getChangeBySetting(x, direction))
			total = total.add(probability.mul(ev.getTime()))
			setFinal(x, opposite)
		}

		if currentProbability.val == 0 {
			break
		}
	}

	fmt.Println(total)
}
