package main

import (
	"fmt"
	"math"
)

const MOD = 998244353

type modInt struct {
	val int
}

func newModInt(v int64) modInt {
	v = v % MOD
	if v < 0 {
		v += MOD
	}
	return modInt{int(v)}
}

func modInv(a, m int) int {
	g, r, x, y := m, a, 0, 1

	for r != 0 {
		q := g / r
		g, r = r, g%r
		x, y = y, x-q*y
	}

	if x < 0 {
		x += m
	}

	return x
}

func fastMod(x uint64, m int) int {
	return int(x % uint64(m))
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
	m.val = fastMod(uint64(m.val)*uint64(other.val), MOD)
	return m
}

func (m modInt) div(other modInt) modInt {
	return m.mul(other.inv())
}

func (m modInt) inv() modInt {
	return newModInt(int64(modInv(m.val, MOD)))
}

func (m modInt) pow(p int64) modInt {
	if p < 0 {
		panic("modInt.pow: negative exponent")
	}

	a := m
	result := newModInt(1)

	for p > 0 {
		if p&1 == 1 {
			result = result.mul(a)
		}

		a = a.mul(a)
		p >>= 1
	}

	return result
}

func (m modInt) equal(other modInt) bool {
	return m.val == other.val
}

func (m modInt) notEqual(other modInt) bool {
	return m.val != other.val
}

func (m modInt) String() string {
	return fmt.Sprintf("%d", m.val)
}

type segmentChange struct {
	setMin int
	setMax int
}

func newSegmentChange(setMin, setMax int) segmentChange {
	return segmentChange{setMin, setMax}
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
	LProduct modInt
	RProduct modInt
	Sum      modInt
	Minimum  int
	Maximum  int
}

func newSegment(LProduct, RProduct, Sum modInt, Minimum, Maximum int) segment {
	return segment{
		LProduct: LProduct,
		RProduct: RProduct,
		Sum:      Sum,
		Minimum:  Minimum,
		Maximum:  Maximum,
	}
}

func (s *segment) apply(_ int, change segmentChange) {
	if change.hasSetMin() {
		s.Minimum = change.setMin
	}

	if change.hasSetMax() {
		s.Maximum = change.setMax
	}
}

func (s *segment) join(other segment) {
	s.Sum = s.Sum.mul(other.RProduct).add(s.LProduct.mul(other.Sum)).sub(s.LProduct.mul(other.RProduct))
	s.LProduct = s.LProduct.mul(other.LProduct)
	s.RProduct = s.RProduct.mul(other.RProduct)
	s.Minimum = min(s.Minimum, other.Minimum)
	s.Maximum = max(s.Maximum, other.Maximum)
}

func (s *segment) joinTwo(a, b segment) {
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
	if n > st.treeN {
		panic("segTree.build: n is greater than treeN")
	}

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
	st.changes[position] = segmentChange{}
}

func (st *segTree) pushAll(a, b int) {
	if !(0 <= a && a < b && b <= st.treeN) {
		panic("segTree.pushAll: invalid range")
	}

	a += st.treeN
	b += st.treeN - 1

	for up := 31 - bits.LeadingZeros(uint(st.treeN)); up > 0; up-- {
		x, y := a>>up, b>>up
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
	if !(0 <= a && a < b && b <= st.treeN) {
		panic("segTree.joinAll: invalid range")
	}

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
	originalA, originalB := a, b
	length := 1
	rSize := 0

	for a, b = a+st.treeN, b+st.treeN; a < b; a, b = a/2, b/2 {
		if a&1 == 1 {
			rangeOp(a, length)
			a++
		}

		if b&1 == 1 {
			rSize--
			rightHalf := rightHalf[rSize]
			rangeOp(rightHalf.first, rightHalf.second)
		}

		length *= 2
	}

	for i := rSize - 1; i >= 0; i-- {
		rightHalf := rightHalf[i]
		rangeOp(rightHalf.first, rightHalf.second)
	}

	if needsJoin {
		st.joinAll(originalA, originalB)
	}
}

func (st *segTree) query(a, b int) segment {
	if !(0 <= a && a <= b && b <= st.treeN) {
		panic("segTree.query: invalid range")
	}

	var answer segment
	st.processRange(a, b, false, func(position, _ int) {
		answer.join(st.tree[position])
	})
	return answer
}

func (st *segTree) update(a, b int, change segmentChange) {
	if !(0 <= a && a <= b && b <= st.treeN) {
		panic("segTree.update: invalid range")
	}

	st.processRange(a, b, true, func(position, length int) {
		st.tree[position].apply(length, change)

		if position < st.treeN {
			st.changes[position] = st.changes[position].combine(change)
		}
	})
}

type event struct {
	distance int64
	velocity int64
	index    int
	typ      int
}

func newEvent(distance, velocity int64, index, typ int) event {
	return event{distance, velocity, index, typ}
}

func (e event) getTime() modInt {
	return newModInt(e.distance).div(newModInt(e.velocity))
}

func (e event) less(other event) bool {
	return e.distance*other.velocity < other.distance*e.velocity
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

func connectFinal(x, y int, status *[]byte, currentProbability *modInt, tree *segTree) {
	if (*status)[x] == 'L' || (*status)[y] == 'R' {
		return
	}

	if (*status)[x] == 'R' && (*status)[y] == 'L' {
		*currentProbability = newModInt(0)
		return
	}

	if id2(tree, x) == x && id4(tree, y) == y {
		xMin := id4(tree, x)
		yMax := id2(tree, y)

		if (*status)[x] == 'R' {
			for i := y; i <= yMax; i++ {
				if (*status)[i] == '?' {
					(*status)[i] = 'R'
				}
			}

			ySeg := tree.query(y, yMax+1)
			*currentProbability = (*currentProbability).mul(ySeg.RProduct).div(ySeg.Sum)
			return
		}

		if (*status)[y] == 'L' {
			for i := xMin; i <= x; i++ {
				if (*status)[i] == '?' {
					(*status)[i] = 'L'
				}
			}

			xSeg := tree.query(xMin, x+1)
			*currentProbability = (*currentProbability).mul(xSeg.LProduct).div(xSeg.Sum)
			return
		}
	}

	if (*status)[x] == '?' && (*status)[y] == '?' {
		tree.update(x, y+1, newSegmentChange(x, y))
		*currentProbability = (*currentProbability).mul(tree.query(x, y+1).Sum).div(tree.query(x, x+1).Sum).div(tree.query(y, y+1).Sum)
	}
}

func setFinal(index int, direction byte, status *[]byte, currentProbability *modInt, tree *segTree) {
	if (*status)[index] != '?' {
		if (*status)[index] != direction {
			*currentProbability = newModInt(0)
		}
		return
	}

	minimum := id4(tree, index)
	maximum := id2(tree, index)

	if direction == 'L' {
		*currentProbability = (*currentProbability).mul(id1(tree, index, 'L'))
		tree.update(index+1, maximum+1, newSegmentChange(index+1, maximum))

		for i := minimum; i <= index; i++ {
			if (*status)[i] == '?' {
				(*status)[i] = 'L'
			}
		}
	} else if direction == 'R' {
		*currentProbability = (*currentProbability).mul(id1(tree, index, 'R'))
		tree.update(minimum, index, newSegmentChange(minimum, index-1))

		for i := index; i <= maximum; i++ {
			if (*status)[i] == '?' {
				(*status)[i] = 'R'
			}
		}
	} else {
		panic("setFinal: invalid direction")
	}
}

func solve(N int, X, V []int, L, R []modInt) modInt {
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

	events := make([]event, 0, 2*N-2)

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

	currentProbability := newModInt(1)
	total := newModInt(0)

	for _, ev := range events {
		if ev.typ == 0 {
			x, y := ev.index, ev.index+1
			if !id3(tree, x, y) {
				probability := currentProbability.mul(id1(tree, x, 'R')).mul(id1(tree, y, 'L'))
				total = total.add(probability.mul(ev.getTime()))
				connectFinal(x, y, &status, &currentProbability, tree)
			}
		} else {
			x := ev.index
			direction := byte('R')
			if ev.typ < 0 {
				direction = 'L'
			}
			probability := currentProbability.mul(id1(tree, x, direction))
			total = total.add(probability.mul(ev.getTime()))
			setFinal(x, direction, &status, &currentProbability, tree)
		}

		if currentProbability.equal(newModInt(0)) {
			break
		}
	}

	return total
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
		R[i] = newModInt(int64(P)).div(newModInt(100))
		L[i] = newModInt(1).sub(R[i])
	}

	result := solve(N, X, V, L, R)
	fmt.Println(result)
}
