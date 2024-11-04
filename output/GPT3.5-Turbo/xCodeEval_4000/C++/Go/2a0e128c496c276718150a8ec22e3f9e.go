package main

import (
	"fmt"
	"math"
)

const MOD = 998244353

type modInt struct {
	val int
}

func newModInt(v int) modInt {
	if v < 0 {
		v = v%MOD + MOD
	}
	if v >= MOD {
		v %= MOD
	}
	return modInt{val: v}
}

func modInv(a, m int) int {
	g := m
	r := a
	x := 0
	y := 1

	for r != 0 {
		q := g / r
		g %= r
		g, r = r, g
		x -= q * y
		x, y = y, x
	}

	if x < 0 {
		x += m
	}

	return x
}

func (m modInt) toInt() int {
	return m.val
}

func (m *modInt) add(other modInt) {
	m.val += other.val
	if m.val >= MOD {
		m.val -= MOD
	}
}

func (m *modInt) sub(other modInt) {
	m.val -= other.val
	if m.val < 0 {
		m.val += MOD
	}
}

func fastMod(x uint64, m int) int {
	return int(x % uint64(m))
}

func (m *modInt) mul(other modInt) {
	m.val = fastMod(uint64(m.val)*uint64(other.val), MOD)
}

func (m *modInt) div(other modInt) {
	m.mul(other.inv())
}

func (m modInt) inv() modInt {
	return newModInt(modInv(m.val, MOD))
}

func (m modInt) pow(p int64) modInt {
	a := m
	result := newModInt(1)

	for p > 0 {
		if p&1 == 1 {
			result.mul(a)
		}

		a.mul(a)
		p >>= 1
	}

	return result
}

func (m modInt) neg() modInt {
	if m.val == 0 {
		return newModInt(0)
	}
	return newModInt(MOD - m.val)
}

func (m modInt) equal(other modInt) bool {
	return m.val == other.val
}

func (m modInt) notEqual(other modInt) bool {
	return m.val != other.val
}

func (m *modInt) inc() {
	if m.val == MOD-1 {
		m.val = 0
	} else {
		m.val++
	}
}

func (m *modInt) dec() {
	if m.val == 0 {
		m.val = MOD - 1
	} else {
		m.val--
	}
}

func (m modInt) negEqualZero() bool {
	return m.val == 0
}

func (m modInt) String() string {
	return fmt.Sprintf("%d", m.val)
}

const INF = 1e9 + 5

type segmentChange struct {
	setMin, setMax int
}

func newSegmentChange(setMin, setMax int) segmentChange {
	return segmentChange{setMin: setMin, setMax: setMax}
}

func (sc *segmentChange) reset() {
	sc.setMin = INF
	sc.setMax = INF
}

func (sc segmentChange) hasSetMin() bool {
	return sc.setMin != INF
}

func (sc segmentChange) hasSetMax() bool {
	return sc.setMax != INF
}

func (sc segmentChange) hasChange() bool {
	return sc.hasSetMin() || sc.hasSetMax()
}

func (sc segmentChange) combine(other segmentChange) segmentChange {
	return segmentChange{
		setMin: min(other.setMin, sc.setMin),
		setMax: min(other.setMax, sc.setMax),
	}
}

type segment struct {
	LProduct, RProduct, sum modInt
	minimum, maximum        int
}

func newSegment(L, R, sum modInt, minimum, maximum int) segment {
	return segment{
		LProduct: L,
		RProduct: R,
		sum:      sum,
		minimum:  minimum,
		maximum:  maximum,
	}
}

func (s *segment) apply(_ int, change segmentChange) {
	if change.hasSetMin() {
		s.minimum = change.setMin
	}

	if change.hasSetMax() {
		s.maximum = change.setMax
	}
}

func (s *segment) join(other segment) {
	s.sum.mul(other.RProduct)
	s.sum.add(s.LProduct.mul(other.sum))
	s.sum.sub(s.LProduct.mul(other.RProduct))
	s.LProduct.mul(other.LProduct)
	s.RProduct.mul(other.RProduct)
	s.minimum = min(s.minimum, other.minimum)
	s.maximum = max(s.maximum, other.maximum)
}

func (s *segment) joinWithSegments(a, b segment) {
	*s = a
	s.join(b)
}

type segTree struct {
	treeN   int
	tree    []segment
	changes []segmentChange
}

func newSegTree(n int) *segTree {
	st := &segTree{
		treeN:   0,
		tree:    nil,
		changes: nil,
	}
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
	assert(n <= st.treeN)

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

func (st *segTree) pushAll(a, b int) {
	assert(0 <= a && a < b && b <= st.treeN)
	a += st.treeN
	b += st.treeN - 1

	for up := 31 - bits.LeadingZeros32(uint32(st.treeN)); up > 0; up-- {
		x := a >> up
		y := b >> up
		st.pushDown(x, 1<<up)
		if x != y {
			st.pushDown(y, 1<<up)
		}
	}
}

func (st *segTree) joinAndApply(position, length int) {
	st.tree[position].join(st.tree[2*position], st.tree[2*position+1])
	st.tree[position].apply(length, st.changes[position])
}

func (st *segTree) joinAll(a, b int) {
	assert(0 <= a && a < b && b <= st.treeN)
	a += st.treeN
	b += st.treeN - 1
	length := 1

	for a > 1 {
		a /= 2
		b /= 2
		length *= 2
		st.joinAndApply(a, length)
		if a != b {
			st.joinAndApply(b, length)
		}
	}
}

func (st *segTree) processRange(a, b int, needsJoin bool, rangeOp func(position, length int)) {
	if a == b {
		return
	}
	st.pushAll(a, b)
	originalA := a
	originalB := b
	length := 1
	rSize := 0

	for a += st.treeN; a < b; a /= 2 {
		b /= 2
		length *= 2
		if a&1 == 1 {
			rangeOp(a, length)
			a++
		}

		if b&1 == 1 {
			rightHalf[rSize] = struct{ first, second int }{b - 1, length}
			rSize++
			b--
		}
	}

	for i := rSize - 1; i >= 0; i-- {
		rangeOp(rightHalf[i].first, rightHalf[i].second)
	}

	if needsJoin {
		st.joinAll(originalA, originalB)
	}
}

func (st *segTree) query(a, b int) segment {
	assert(0 <= a && a <= b && b <= st.treeN)
	answer := segment{}

	st.processRange(a, b, false, func(position, _ int) {
		answer.join(st.tree[position])
	})

	return answer
}

func (st *segTree) update(a, b int, change segmentChange) {
	assert(0 <= a && a <= b && b <= st.treeN)

	st.processRange(a, b, true, func(position, length int) {
		st.tree[position].apply(length, change)

		if position < st.treeN {
			st.changes[position] = st.changes[position].combine(change)
		}
	})
}

type event struct {
	distance, velocity int64
	index, typ          int
}

func newEvent(distance, velocity int64, index, typ int) event {
	return event{
		distance: distance,
		velocity: velocity,
		index:    index,
		typ:      typ,
	}
}

func (e event) getTime() modInt {
	return newModInt(e.distance).div(newModInt(e.velocity))
}

func (e event) less(other event) bool {
	return e.distance*int64(other.velocity) < other.distance*int64(e.velocity)
}

var rightHalf [32]struct {
	first, second int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func assert(condition bool) {
	if !condition {
		panic("assertion failed")
	}
}

func main() {
	var N int
	fmt.Scan(&N)
	X := make([]int, N)
	V := make([]int, N)
	L := make([]modInt, N)
	R := make([]modInt, N)

	for i := 0; i < N; i++ {
		var P int
		fmt.Scan(&X[i], &V[i], &P)
		R[i] = newModInt(P).mul(newModInt(100).inv())
		L[i] = newModInt(1).sub(R[i])
	}

	tree := newSegTree(N)
	initial := make([]segment, N)

	for i := 0; i < N; i++ {
		initial[i] = newSegment(L[i], R[i], newModInt(1), i, i)
	}

	tree.build(initial)
	status := make([]byte, N)
	for i := range status {
		status[i] = '?'
	}

	events := []event{}
	for i := 0; i < N-1; i++ {
		distance := int64(X[i+1] - X[i])
		velocity := int64(V[i] + V[i+1])
		events = append(events, newEvent(distance, velocity, i, 0))

		if V[i] > V[i+1] {
			events = append(events, newEvent(distance, int64(V[i]-V[i+1]), i, +1))
		} else if V[i+1] > V[i] {
			events = append(events, newEvent(distance, int64(V[i+1]-V[i]), i+1, -1))
		}
	}

	sortEvents(events)
	currentProbability := newModInt(1)
	total := newModInt(0)

	for _, ev := range events {
		if ev.typ == 0 {
			x := ev.index
			y := ev.index + 1
			assert(!inSameComponent(tree, x, y))
			probability := currentProbability.mul(getChangeBySetting(tree, status, x, 'R')).mul(getChangeBySetting(tree, status, y, 'L'))
			total = total.add(probability.mul(ev.getTime()))
			connectFinal(tree, status, x, y)
		} else {
			assert(abs(ev.typ) == 1)
			x := ev.index
			direction := byte('R')
			if ev.typ < 0 {
				direction = 'L'
			}
			opposite := byte('L' + 'R' - direction)
			probability := currentProbability.mul(getChangeBySetting(tree, status, x, direction))
			total = total.add(probability.mul(ev.getTime()))
			setFinal(tree, status, x, opposite)
		}

		if currentProbability.equal(newModInt(0)) {
			break
		}
	}

	fmt.Println(total)
}

func sortEvents(events []event) {
	sort.Slice(events, func(i, j int) bool {
		return events[i].less(events[j])
	})
}

func inSameComponent(tree *segTree, x, y int) bool {
	assert(x <= y)
	return y <= tree.query(x, x+1).maximum
}

func getMinimum(tree *segTree, x int) int {
	return tree.query(x, x+1).minimum
}

func getMaximum(tree *segTree, x int) int {
	return tree.query(x, x+1).maximum
}

func getChangeBySetting(tree *segTree, status []byte, index int, direction byte) modInt {
	if status[index] == direction {
		return newModInt(1)
	}

	if status[index] != '?' && status[index] != direction {
		return newModInt(0)
	}

	assert(status[index] == '?')
	minimum := getMinimum(tree, index)
	maximum := getMaximum(tree, index)

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

func connectFinal(tree *segTree, status []byte, x, y int) {
	assert(y-x == 1)

	if status[x] == 'L' || status[y] == 'R' {
		return
	}

	if status[x] == 'R' && status[y] == 'L' {
		currentProbability := newModInt(0)
		return
	}

	assert(getMaximum(tree, x) == x && getMinimum(tree, y) == y)
	xMin := getMinimum(tree, x)
	yMax := getMaximum(tree, y)

	if status[x] == 'R' {
		for i := y; i <= yMax; i++ {
			assert(status[i] == '?')
			status[i] = 'R'
		}

		currentProbability := currentProbability.mul(tree.query(y, yMax+1).RProduct).div(tree.query(y, yMax+1).sum)
		return
	}

	if status[y] == 'L' {
		for i := xMin; i <= x; i++ {
			assert(status[i] == '?')
			status[i] = 'L'
		}

		currentProbability := currentProbability.mul(tree.query(xMin, x+1).LProduct).div(tree.query(xMin, x+1).sum)
		return
	}

	assert(status[x] == '?' && status[y] == '?")
	tree.update(xMin, yMax+1, newSegmentChange(xMin, yMax))
	currentProbability := currentProbability.mul(tree.query(xMin, yMax+1).sum).div(tree.query(xMin, x+1).sum).div(tree.query(y, yMax+1).sum)
}

func setFinal(tree *segTree, status []byte, index int, direction byte) {
	if status[index] != '?' {
		if status[index] != direction {
			currentProbability := newModInt(0)
		}
		return
	}

	assert(status[index] == '?")
	minimum := getMinimum(tree, index)
	maximum := getMaximum(tree, index)

	if direction == 'L' {
		currentProbability := currentProbability.mul(getChangeBySetting(tree, status, index, 'L'))
		tree.update(index+1, maximum+1, newSegmentChange(index+1, maximum))

		for i := minimum; i <= index; i++ {
			assert(status[i] == '?")
			status[i] = 'L'
		}
	} else if direction == 'R' {
		currentProbability := currentProbability.mul(getChangeBySetting(tree, status, index, 'R'))
		tree.update(minimum, index, newSegmentChange(minimum, index-1))

		for i := index; i <= maximum; i++ {
			assert(status[i] == '?")
			status[i] = 'R'
		}
	} else {
		panic("unreachable")
	}
}
