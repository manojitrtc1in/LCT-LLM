

package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
)

var (
	n, q int
	P    []int
)

func main() {
	defer stdout.Flush()

	n, q = id5()
	P = readis(n)
	sort.Sort(sort.IntSlice(P))

	pt := id11()
	dt := id11()

	pt.Insert(P[0])
	for i := 1; i < n; i++ {
		diff := P[i] - P[i-1]
		pt.Insert(P[i])
		dt.Insert(diff)
	}
	maxp := pt.FindMaximum()
	minp := pt.FindMinimum()
	maxd := dt.FindMaximum()
	if maxd == nil {
		printf("%d\n", 0)
	} else {
		total := maxp.key - minp.key
		ans := total - maxd.key
		printf("%d\n", ans)
	}

	for i := 0; i < q; i++ {
		t, x := id5()
		if t == 1 {
			

			r := pt.MinGreater(x)
			l := pt.MaxLess(x)
			if r != nil {
				diff := r.key - x
				dt.Insert(diff)
			}
			if l != nil {
				diff := x - l.key
				dt.Insert(diff)
			}
			if r != nil && l != nil {
				diff := r.key - l.key
				dt.Delete(diff)
			}
			pt.Insert(x)

			

			maxp := pt.FindMaximum()
			minp := pt.FindMinimum()
			maxd := dt.FindMaximum()
			if maxd == nil {
				printf("%d\n", 0)
			} else {
				total := maxp.key - minp.key
				ans := total - maxd.key
				printf("%d\n", ans)
			}
		} else {
			

			r := pt.MinGreater(x)
			l := pt.MaxLess(x)
			if r != nil {
				

				diff := r.key - x
				dt.Delete(diff)
			}
			if l != nil {
				

				diff := x - l.key
				dt.Delete(diff)
			}
			if r != nil && l != nil {
				

				diff := r.key - l.key
				dt.Insert(diff)
			}
			pt.Delete(x)

			

			maxp := pt.FindMaximum()
			minp := pt.FindMinimum()
			maxd := dt.FindMaximum()
			if maxd == nil {
				printf("%d\n", 0)
			} else {
				total := maxp.key - minp.key
				ans := total - maxd.key
				printf("%d\n", ans)
			}
		}
	}
}

































type Node struct {
	key, priority int
	right, left   *Node
}

type Treap struct {
	root    *Node
	cnts    map[int]int
	randInt func() int
}








func id11() *Treap {
	tr := new(Treap)

	tr.root = nil
	tr.cnts = make(map[int]int)

	

	

	

	_gtx, _gty, _gtz, _gtw := 123456789, 362436069, 521288629, 88675123
	tr.randInt = func() int {
		tt := (_gtx ^ (_gtx << 11))
		_gtx = _gty
		_gty = _gtz
		_gtz = _gtw
		_gtw = (_gtw ^ (_gtw >> 19)) ^ (tt ^ (tt >> 8))
		return _gtw
	}

	return tr
}





func (tr *Treap) Count(key int) int {
	return tr.cnts[key]
}


















func (tr *Treap) Insert(key int) {
	preCnt := tr.Count(key)
	tr.increase(key, 1)
	if preCnt > 0 {
		return
	}

	tr.root = tr.insert(tr.root, key, tr.randInt())
}





func (tr *Treap) Find(key int) *Node {
	cnt := tr.cnts[key]
	if cnt == 0 {
		return nil
	}

	u := tr.root
	for u != nil && key != u.key {
		if key < u.key {
			u = u.left
		} else {
			u = u.right
		}
	}
	return u
}





func (tr *Treap) FindMinimum() *Node {
	u := tr.root
	for u != nil && u.left != nil {
		u = u.left
	}
	return u
}





func (tr *Treap) FindMaximum() *Node {
	u := tr.root
	for u != nil && u.right != nil {
		u = u.right
	}
	return u
}





func (tr *Treap) Delete(key int) {
	tr.decrease(key, 1)
	curCnt := tr.Count(key)
	if curCnt > 0 {
		return
	}

	tr.root = tr.delete(tr.root, key)
}





func (tr *Treap) Inorder() []int {
	res := make([]int, 0, 200000+5)
	tr.inorder(tr.root, &res)
	return res
}



func (tr *Treap) Preorder() []int {
	res := make([]int, 0, 200000+5)
	tr.preorder(tr.root, &res)
	return res
}





func (tr *Treap) MinGeq(x int) *Node {
	return tr.biggerLowerBound(tr.root, x)
}





func (tr *Treap) MinGreater(x int) *Node {
	return tr.biggerUpperBound(tr.root, x)
}





func (tr *Treap) MaxLeq(x int) *Node {
	return tr.smallerUpperBound(tr.root, x)
}





func (tr *Treap) MaxLess(x int) *Node {
	return tr.smallerLowerBound(tr.root, x)
}






func (tr *Treap) increase(key, num int) {
	tr.cnts[key] += num
}

func (tr *Treap) decrease(key, num int) {
	curCnt := tr.cnts[key]
	if curCnt-num < 0 {
		panic("too many elements is deleted!")
	}

	tr.cnts[key] -= num
}

func (tr *Treap) insert(t *Node, key, priority int) *Node {
	

	if t == nil {
		node := new(Node)
		node.key, node.priority = key, priority
		return node
	}

	

	if key == t.key {
		return t
	}

	if key < t.key {
		

		t.left = tr.insert(t.left, key, priority) 

		

		if t.priority < t.left.priority {
			t = tr.rightRotate(t)
		}
	} else {
		

		t.right = tr.insert(t.right, key, priority) 

		if t.priority < t.right.priority {
			

			t = tr.leftRotate(t)
		}
	}

	return t
}



func (tr *Treap) delete(t *Node, key int) *Node {
	if t == nil {
		return nil
	}

	

	if key < t.key {
		t.left = tr.delete(t.left, key)
	} else if key > t.key {
		t.right = tr.delete(t.right, key)
	} else {
		

		return tr._delete(t, key)
	}

	return t
}



func (tr *Treap) _delete(t *Node, key int) *Node {
	if t.left == nil && t.right == nil {
		

		return nil
	} else if t.left == nil {
		

		t = tr.leftRotate(t)
	} else if t.right == nil {
		

		t = tr.rightRotate(t)
	} else {
		

		if t.left.priority > t.right.priority {
			t = tr.rightRotate(t)
		} else {
			t = tr.leftRotate(t)
		}
	}

	return tr.delete(t, key)
}

func (tr *Treap) rightRotate(t *Node) *Node {
	s := t.left
	t.left = s.right
	s.right = t
	return s
}

func (tr *Treap) leftRotate(t *Node) *Node {
	s := t.right
	t.right = s.left
	s.left = t
	return s
}



func (tr *Treap) biggerLowerBound(t *Node, x int) *Node {
	if t == nil {
		return nil
	} else if t.key >= x {
		

		node := tr.biggerLowerBound(t.left, x)
		if node != nil {
			return node
		} else {
			return t
		}
	} else {
		

		return tr.biggerLowerBound(t.right, x)
	}
}



func (tr *Treap) biggerUpperBound(t *Node, x int) *Node {
	if t == nil {
		return nil
	} else if t.key > x {
		

		node := tr.biggerUpperBound(t.left, x)
		if node != nil {
			return node
		} else {
			return t
		}
	} else {
		

		return tr.biggerUpperBound(t.right, x)
	}
}



func (tr *Treap) smallerUpperBound(t *Node, x int) *Node {
	if t == nil {
		return nil
	} else if t.key <= x {
		node := tr.smallerUpperBound(t.right, x)
		if node != nil {
			return node
		} else {
			return t
		}
	} else {
		return tr.smallerUpperBound(t.left, x)
	}
}



func (tr *Treap) smallerLowerBound(t *Node, x int) *Node {
	if t == nil {
		return nil
	} else if t.key < x {
		node := tr.smallerLowerBound(t.right, x)
		if node != nil {
			return node
		} else {
			return t
		}
	} else {
		return tr.smallerLowerBound(t.left, x)
	}
}

func (tr *Treap) inorder(u *Node, res *[]int) {
	if u == nil {
		return
	}
	tr.inorder(u.left, res)
	*res = append(*res, u.key)
	tr.inorder(u.right, res)
}

func (tr *Treap) preorder(u *Node, res *[]int) {
	if u == nil {
		return
	}
	*res = append(*res, u.key)
	tr.preorder(u.left, res)
	tr.preorder(u.right, res)
}





const (
	MOD = 1000000000 + 7
	

	ALPH_N  = 26
	INF_I64 = math.MaxInt64
	INF_B60 = 1 << 60
	INF_I32 = math.MaxInt32
	INF_B30 = 1 << 30
	NIL     = -1
)



func modi(val, m int) int {
	res := val % m
	if res < 0 {
		res += m
	}
	return res
}



func modll(val, m int64) int64 {
	res := val % m
	if res < 0 {
		res += m
	}
	return res
}



func init() {
	

	reads = id7(os.Stdin, bufio.ScanWords)
	stdout = bufio.NewWriter(os.Stdout)
}




























var (
	

	reads  func() string
	stdout *bufio.Writer
)

func id7(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+9)) 

	r.Split(sf)

	return func() string {
		if !r.Scan() {
			panic("Scan failed")
		}
		return r.Text()
	}
}



func readi() int {
	return int(id0())
}
func id5() (int, int) {
	return int(id0()), int(id0())
}
func id4() (int, int, int) {
	return int(id0()), int(id0()), int(id0())
}
func id1() (int, int, int, int) {
	return int(id0()), int(id0()), int(id0()), int(id0())
}



func readll() int64 {
	return id0()
}
func id12() (int64, int64) {
	return id0(), id0()
}
func id9() (int64, int64, int64) {
	return id0(), id0(), id0()
}
func id3() (int64, int64, int64, int64) {
	return id0(), id0(), id0(), id0()
}

func id0() int64 {
	i, err := strconv.ParseInt(reads(), 0, 64)
	if err != nil {
		panic(err.Error())
	}
	return i
}



func readis(n int) []int {
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = readi()
	}
	return b
}



func id8(n int) []int64 {
	b := make([]int64, n)
	for i := 0; i < n; i++ {
		b[i] = readll()
	}
	return b
}



func readf() float64 {
	return float64(id10())
}

func id10() float64 {
	f, err := strconv.ParseFloat(reads(), 64)
	if err != nil {
		panic(err.Error())
	}
	return f
}



func readfs(n int) []float64 {
	b := make([]float64, n)
	for i := 0; i < n; i++ {
		b[i] = readf()
	}
	return b
}



func readrs() []rune {
	return []rune(reads())
}





func id13(A ...int) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i])
		res = append(res, []rune(str)...)

		if i != len(A)-1 {
			res = append(res, ' ')
		}
	}

	return string(res)
}



func id2(A ...int64) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.FormatInt(A[i], 10) 

		res = append(res, []rune(str)...)

		if i != len(A)-1 {
			res = append(res, ' ')
		}
	}

	return string(res)
}





func printf(format string, a ...interface{}) {
	fmt.Fprintf(stdout, format, a...)
}





func debugf(format string, a ...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}





func id6(n, digitsNum int) []rune {
	sn := fmt.Sprintf("%b", n)

	residualLength := digitsNum - len(sn)
	if residualLength <= 0 {
		return []rune(sn)
	}

	zeros := make([]rune, residualLength)
	for i := 0; i < len(zeros); i++ {
		zeros[i] = '0'
	}

	res := []rune{}
	res = append(res, zeros...)
	res = append(res, []rune(sn)...)

	return res
}
