package main

import (
	"fmt"
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
	g, r, x, y := m, a, 0, 1

	for r != 0 {
		q := g / r
		g, r = r, g%r
		x, y = x-q*y, x
	}

	if x < 0 {
		x += m
	}
	return x
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
	m.val = (m.val * other.val) % MOD
	return m
}

func (m modInt) div(other modInt) modInt {
	inv := modInv(other.val, MOD)
	m.val = (m.val * inv) % MOD
	return m
}

func (m modInt) pow(p int) modInt {
	result := modInt{val: 1}
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

type segmentChange struct {
	setMin, setMax int
}

type segment struct {
	LProduct, RProduct, sum modInt
	minimum, maximum       int
}

type segTree struct {
	treeN   int
	tree    []segment
	changes []segmentChange
}

func newSegTree(n int) *segTree {
	treeN := 1
	for treeN < n {
		treeN *= 2
	}

	tree := make([]segment, 2*treeN)
	changes := make([]segmentChange, treeN)

	return &segTree{
		treeN:   treeN,
		tree:    tree,
		changes: changes,
	}
}

func (st *segTree) build(initial []segment) {
	n := len(initial)
	st.tree = make([]segment, 2*st.treeN)

	for i := 0; i < n; i++ {
		st.tree[st.treeN+i] = initial[i]
	}

	for position := st.treeN - 1; position > 0; position-- {
		st.tree[position] = st.tree[2*position].join(st.tree[2*position+1])
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
	a += st.treeN
	b += st.treeN - 1

	for up := 31 - clz(st.treeN); up > 0; up-- {
		x, y := a>>up, b>>up
		st.pushDown(x, 1<<up)
		if x != y {
			st.pushDown(y, 1<<up)
		}
	}
}

func (st *segTree) joinAndApply(position, length int) {
	st.tree[position] = st.tree[2*position].join(st.tree[2*position+1])
	st.tree[position].apply(length, st.changes[position])
}

func (st *segTree) joinAll(a, b int) {
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

	for a += st.treeN; a < b; a /= 2 {
		b /= 2
		length *= 2
		if a&1 == 1 {
			rangeOp(a, length)
			a++
		}
		if b&1 == 1 {
			rightHalf[rSize] = [2]int{b - 1, length}
			rSize++
			b--
		}
	}

	for i := rSize - 1; i >= 0; i-- {
		rangeOp(rightHalf[i][0], rightHalf[i][1])
	}

	if needsJoin {
		st.joinAll(originalA, originalB)
	}
}

func (st *segTree) query(a, b int) segment {
	answer := segment{}

	st.processRange(a, b, false, func(position, _ int) {
		answer = answer.join(st.tree[position])
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

func (e event) Less(other event) bool {
	return e.distance*other.velocity < other.distance*e.velocity
}

type segmentChange struct {
	setMin, setMax int
}

func (sc segmentChange) hasSetMin() bool {
	return sc.setMin != -1<<31
}

func (sc segmentChange) hasSetMax() bool {
	return sc.setMax != -1<<31
}

func (sc segmentChange) hasChange() bool {
	return sc.hasSetMin() || sc.hasSetMax()
}

func (sc segmentChange) combine(other segmentChange) segmentChange {
	return segmentChange{
		setMin: min(other.setMin, sc.setMin),
		setMax: max(other.setMax, sc.setMax),
	}
}

type segment struct {
	LProduct, RProduct, sum modInt
	minimum, maximum       int
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

func (s segment) apply(_ int, change segmentChange) {
	if change.hasSetMin() {
		s.minimum = change.setMin
	}

	if change.hasSetMax() {
		s.maximum = change.setMax
	}
}

func (s segment) join(other segment) segment {
	sum := s.sum.mul(other.RProduct).add(s.LProduct.mul(other.sum)).sub(s.LProduct.mul(other.RProduct))
	LProduct := s.LProduct.mul(other.LProduct)
	RProduct := s.RProduct.mul(other.RProduct)
	minimum := min(s.minimum, other.minimum)
	maximum := max(s.maximum, other.maximum)

	return newSegment(LProduct, RProduct, sum, minimum, maximum)
}

func (s segment) join2(a, b segment) segment {
	s = a
	return s.join(b)
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

func (e event) Less(other event) bool {
	return e.distance*other.velocity < other.distance*e.velocity
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
		R[i] = newModInt(P).div(newModInt(100))
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

	for i := 0; i < N-1; i++ {
		distance := int64(X[i+1] - X[i])
		events = append(events, newEvent(distance, V[i]+V[i+1], i, 0))

		if V[i] > V[i+1] {
			events = append(events, newEvent(distance, V[i]-V[i+1], i, +1))
		} else if V[i+1] > V[i] {
			events = append(events, newEvent(distance, V[i+1]-V[i], i+1, -1))
		}
	}

	sort.Slice(events, func(i, j int) bool {
		return events[i].Less(events[j])
	})

	currentProbability := newModInt(1)
	total := newModInt(0)

	for _, ev := range events {
		if ev.typ == 0 {
			x, y := ev.index, ev.index+1
			if inSameComponent(x, y) {
				continue
			}
			probability := currentProbability.mul(getChangeBySetting(x, 'R')).mul(getChangeBySetting(y, 'L'))
			total = total.add(probability.mul(ev.getTime()))
			connectFinal(x, y)
		} else {
			x := ev.index
			direction := byte('R')
			if ev.typ < 0 {
				direction = 'L'
			}
			opposite := byte('L' + 'R' - direction)
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

	if status[index] == '?' {
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
	}

	panic("unreachable")
}

func connectFinal(x, y int) {
	if y-x == 1 {
		if status[x] == 'L' || status[y] == 'R' {
			return
		}

		if status[x] == 'R' && status[y] == 'L' {
			currentProbability = newModInt(0)
			return
		}

		if getMaximum(x) == x && getMinimum(y) == y {
			if status[x] == 'R' {
				for i := y; i <= getMaximum(y); i++ {
					status[i] = 'R'
				}
				ySeg := tree.query(y, getMaximum(y)+1)
				currentProbability = currentProbability.mul(ySeg.RProduct).div(ySeg.sum)
				return
			}

			if status[y] == 'L' {
				for i := getMinimum(x); i <= x; i++ {
					status[i] = 'L'
				}
				xSeg := tree.query(getMinimum(x), x+1)
				currentProbability = currentProbability.mul(xSeg.LProduct).div(xSeg.sum)
				return
			}
		}
	}

	panic("unreachable")
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
			status[i] = 'L'
		}
	} else if direction == 'R' {
		currentProbability = currentProbability.mul(getChangeBySetting(index, 'R'))
		tree.update(minimum, index, segmentChange{setMin: minimum, setMax: index - 1})
		for i := index; i <= maximum; i++ {
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
					panic("invalid state")
				}
			}
		}
	}
}

func clz(x int) int {
	if x == 0 {
		return 32
	}
	return 31 - bits.Len32(uint32(x))
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
