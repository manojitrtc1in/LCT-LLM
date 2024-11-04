package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const (
	eps          = 1e-12
	MAX_MOD      = 1000000007
	MOD          = 998244353
)

type Point struct {
	x, y float64
}

type Line struct {
	first, second Point
}

type Circle struct {
	center Point
	r      float64
}

func dot(a, b Point) float64 {
	return a.x*b.x + a.y*b.y
}

func cross(a, b Point) float64 {
	return a.x*b.y - a.y*b.x
}

func DistLinePoint(a Line, b Point) float64 {
	if dot(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.x - a.first.x, b.y - a.first.y}) < eps {
		return distance(b, a.first)
	}
	if dot(Point{a.first.x - a.second.x, a.first.y - a.second.y}, Point{b.x - a.second.x, b.y - a.second.y}) < eps {
		return distance(b, a.second)
	}
	return math.Abs(cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.x - a.first.x, b.y - a.first.y})) / distance(a.first, a.second)
}

func isIntersectedLS(a, b Line) bool {
	return (cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.first.x - a.first.x, b.first.y - a.first.y})*cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.second.x - a.first.x, b.second.y - a.first.y}) < eps) &&
		(cross(Point{b.second.x - b.first.x, b.second.y - b.first.y}, Point{a.first.x - b.first.x, a.first.y - b.first.y})*cross(Point{b.second.x - b.first.x, b.second.y - b.first.y}, Point{a.second.x - b.first.x, a.second.y - b.first.y}) < eps)
}

func intersectionL(a, b Line) Point {
	da := Point{a.second.x - a.first.x, a.second.y - a.first.y}
	db := Point{b.second.x - b.first.x, b.second.y - b.first.y}
	return Point{
		x: a.first.x + da.x*cross(db, Point{b.first.x - a.first.x, b.first.y - a.first.y})/cross(db, da),
		y: a.first.y + da.y*cross(db, Point{b.first.x - a.first.x, b.first.y - a.first.y})/cross(db, da),
	}
}

func distance(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

func DistLineLine(a, b Line) float64 {
	if isIntersectedLS(a, b) {
		return 0
	}
	return math.Min(math.Min(DistLinePoint(a, b.first), DistLinePoint(a, b.second)), math.Min(DistLinePoint(b, a.first), DistLinePoint(b, a.second)))
}

func intersectionCircleCircle(a, b Circle) (Point, Point) {
	dist := distance(a.center, b.center)
	if dist > eps+a.r+b.r || dist+eps < math.Abs(a.r-b.r) {
		panic("Circles do not intersect")
	}
	target := Point{b.center.x - a.center.x, b.center.y - a.center.y}
	pointer := target.x*target.x + target.y*target.y
	aa := (pointer + a.r*a.r - b.r*b.r) / 2.0
	l := Point{
		x: (aa*target.x + target.y*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
		y: (aa*target.y - target.x*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
	}
	r := Point{
		x: (aa*target.x - target.y*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
		y: (aa*target.y + target.x*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
	}
	r.x += a.center.x
	r.y += a.center.y
	l.x += a.center.x
	l.y += a.center.y
	return l, r
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

type modint struct {
	value int64
}

func newModint(a int64) modint {
	return modint{((a % MAX_MOD) + 2*MAX_MOD) % MAX_MOD}
}

func (m modint) add(rhs modint) modint {
	return newModint(m.value + rhs.value)
}

func (m modint) sub(rhs modint) modint {
	if m.value < rhs.value {
		m.value += MAX_MOD
	}
	return newModint(m.value - rhs.value)
}

func (m modint) mul(rhs modint) modint {
	return newModint((m.value * rhs.value) % MAX_MOD)
}

func (m modint) div(rhs modint) modint {
	rem := MAX_MOD - 2
	for rem > 0 {
		if rem%2 == 1 {
			m = m.mul(rhs)
		}
		rhs = rhs.mul(rhs)
		rem /= 2
	}
	return m
}

type Dice struct {
	vertexs []int64
}

func NewDice(init []int64) Dice {
	return Dice{vertexs: init}
}

func (d *Dice) RtoL() {
	for q := 1; q < 4; q++ {
		d.vertexs[q], d.vertexs[q+1] = d.vertexs[q+1], d.vertexs[q]
	}
}

func (d *Dice) LtoR() {
	for q := 3; q >= 1; q-- {
		d.vertexs[q], d.vertexs[q+1] = d.vertexs[q+1], d.vertexs[q]
	}
}

func (d *Dice) UtoD() {
	d.vertexs[5], d.vertexs[4] = d.vertexs[4], d.vertexs[5]
	d.vertexs[2], d.vertexs[5] = d.vertexs[5], d.vertexs[2]
	d.vertexs[0], d.vertexs[2] = d.vertexs[2], d.vertexs[0]
}

func (d *Dice) DtoU() {
	d.vertexs[0], d.vertexs[2] = d.vertexs[2], d.vertexs[0]
	d.vertexs[2], d.vertexs[5] = d.vertexs[5], d.vertexs[2]
	d.vertexs[5], d.vertexs[4] = d.vertexs[4], d.vertexs[5]
}

func (d *Dice) ReachAble(now Dice) bool {
	hoge := make(map[Dice]struct{})
	next := []Dice{now}
	hoge[now] = struct{}{}
	for len(next) > 0 {
		seeing := next[0]
		next = next[1:]
		if seeing == *d {
			return true
		}
		seeing.RtoL()
		if _, exists := hoge[seeing]; !exists {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.LtoR()
		seeing.LtoR()
		if _, exists := hoge[seeing]; !exists {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.RtoL()
		seeing.UtoD()
		if _, exists := hoge[seeing]; !exists {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.DtoU()
		seeing.DtoU()
		if _, exists := hoge[seeing]; !exists {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
	}
	return false
}

func (d *Dice) Equal(a Dice) bool {
	for q := 0; q < 6; q++ {
		if a.vertexs[q] != d.vertexs[q] {
			return false
		}
	}
	return true
}

func TwoDimDice(center, up int) (Dice, Dice) {
	target := 1
	for {
		if center != target && 7-center != target && up != target && 7-up != target {
			break
		}
		target++
	}
	return NewDice([]int64{int64(up), int64(target), int64(center), int64(7 - target), int64(7 - center), int64(7 - up)}),
		NewDice([]int64{int64(up), int64(7 - target), int64(center), int64(target), int64(7 - center), int64(7 - up)})
}

func OneDimDice(center int) (Dice, Dice, Dice, Dice) {
	bo := int(math.Min(float64(center), float64(7-center)))
	var goa [2]int
	if bo == 1 {
		goa = [2]int{2, 3}
	} else if bo == 2 {
		goa = [2]int{1, 3}
	} else if bo == 3 {
		goa = [2]int{1, 2}
	}
	return NewDice([]int64{int64(goa[0]), int64(goa[1]), int64(center), int64(7 - goa[1]), int64(7 - center), int64(7 - goa[0])}),
		NewDice([]int64{int64(goa[0]), int64(7 - goa[1]), int64(center), int64(goa[1]), int64(7 - center), int64(7 - goa[0])}),
		NewDice([]int64{int64(7 - goa[0]), int64(goa[1]), int64(center), int64(7 - goa[1]), int64(7 - center), int64(goa[0])}),
		NewDice([]int64{int64(7 - goa[0]), int64(7 - goa[1]), int64(center), int64(goa[1]), int64(7 - center), int64(goa[0])})
}

type Dijkstra struct {
	vertexs      [][]Pair
	CostFunction func(int) int64
}

type Pair struct {
	first  int
	second int64
}

func NewDijkstra(n int, cost func(int) int64) *Dijkstra {
	vertexs := make([][]Pair, n)
	return &Dijkstra{vertexs: vertexs, CostFunction: cost}
}

func (d *Dijkstra) AddEdge(a, b int, c int64) {
	d.vertexs[a] = append(d.vertexs[a], Pair{first: b, second: c})
}

func (d *Dijkstra) BuildResult(startPoint int) []int64 {
	dist := make([]int64, len(d.vertexs))
	for i := range dist {
		dist[i] = math.MaxInt64
	}
	dist[startPoint] = 0
	next := &PriorityQueue{}
	heap.Push(next, Pair{first: startPoint, second: 0})
	for next.Len() > 0 {
		now := heap.Pop(next).(Pair)
		if dist[now.first] != now.second {
			continue
		}
		for _, x := range d.vertexs[now.first] {
			nowCost := now.second + d.CostFunction(x.second)
			if dist[x.first] > nowCost {
				dist[x.first] = nowCost
				heap.Push(next, Pair{first: x.first, second: nowCost})
			}
		}
	}
	return dist
}

type PriorityQueue []Pair

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].second < pq[j].second
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(Pair))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

func main() {
	var n int
	fmt.Scan(&n)
	var t string
	fmt.Scan(&t)

	var cnter []int64
	for i := 0; i < len(t); i++ {
		if t[i] == '0' {
			cnter = append(cnter, int64(i*2+i%2))
		}
	}

	var hoge [300000]struct {
		first, second modint
	}
	var rev [300000]struct {
		first, second modint
	}

	nexts := struct {
		first, second modint
	}{newModint(1), newModint(1)}

	for i := 0; i < len(cnter); i++ {
		hoge[i+1] = hoge[i]
		hoge[i+1].first = hoge[i+1].first.add(nexts.first.mul(newModint(cnter[i] % 2)))
		hoge[i+1].second = hoge[i+1].second.add(nexts.second.mul(newModint(cnter[i] % 2)))
		rev[i+1] = rev[i]
		rev[i+1].first = rev[i+1].first.add(nexts.first.mul(newModint((cnter[i]+1)%2)))
		rev[i+1].second = rev[i+1].second.add(nexts.second.mul(newModint((cnter[i]+1)%2)))
		nexts.first = nexts.first.mul(newModint(2))
		nexts.second = nexts.second.mul(newModint(2))
	}

	var query int
	fmt.Scan(&query)
	for i := 0; i < query; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		a--
		b--

		left := Pair{first: sort.Search(len(cnter), func(i int) bool { return cnter[i] >= int64(a*2) }) - 1, second: sort.Search(len(cnter), func(i int) bool { return cnter[i] >= int64((a+c)*2) }) - 1}
		right := Pair{first: sort.Search(len(cnter), func(i int) bool { return cnter[i] >= int64(b*2) }) - 1, second: sort.Search(len(cnter), func(i int) bool { return cnter[i] >= int64((b+c)*2) }) - 1}

		if left.second-left.first != right.second-right.first {
			fmt.Println("No")
			continue
		}

		ok := 1
		var aa, bb struct {
			first, second modint
		}
		aa = hoge[left.second]
		aa.first = aa.first.sub(hoge[left.first].first)
		aa.second = aa.second.sub(hoge[left.first].second)

		if a%2 == b%2 {
			bb = hoge[right.second]
			bb.first = bb.first.sub(hoge[right.first].first)
			bb.second = bb.second.sub(hoge[right.first].second)
		} else {
			bb = rev[right.second]
			bb.first = bb.first.sub(rev[right.first].first)
			bb.second = bb.second.sub(rev[right.first].second)
		}

		if left.first != 0 {
			aa.first = aa.first.div(newModint(1 << left.first))
			aa.second = aa.second.div(newModint(1 << left.first))
		}
		if right.first != 0 {
			bb.first = bb.first.div(newModint(1 << right.first))
			bb.second = bb.second.div(newModint(1 << right.first))
		}
		if aa.first.value != bb.first.value || aa.second.value != bb.second.value {
			ok = 0
		}
		if ok == 1 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
