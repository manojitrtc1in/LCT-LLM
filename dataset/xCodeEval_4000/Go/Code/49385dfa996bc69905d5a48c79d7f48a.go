

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)




























const (
	

	MOD          = 1000000000 + 7
	ALPHABET_NUM = 26
	INF_INT64    = math.MaxInt64
	INF_BIT60    = 1 << 60
	INF_INT32    = math.MaxInt32
	INF_BIT30    = 1 << 30
	NIL          = -1

	

	WHITE = 0
	GRAY  = 1
	BLACK = 2
)

func init() {
	

	ReadString = newReadString(os.Stdin, bufio.ScanWords)
	stdout = bufio.NewWriter(os.Stdout)
}

var (
	n int
	A []int

	memo [1000000 + 50]int
)

func main() {
	n = ReadInt()
	A = ReadIntSlice(n)

	for i := 0; i < n; i++ {
		memo[A[i]]++
	}

	tr := NewTreap()

	

	for i := 0; i <= 100000+50; i++ {
		if memo[i] == 0 {
			

			

			tr.Insert(i)
		}
	}
	B := make([]int, n)
	for i := 0; i < n; i++ {
		

		node := tr.FindMinimum()
		B[i] = node.key
		tr.Delete(node.key)

		memo[A[i]]--
		memo[B[i]]++
		if memo[A[i]] == 0 {
			

			tr.Insert(A[i])
		} else {
			

			

			

			

			

			

		}
	}

	fmt.Println(PrintIntsLine(B...))
}






























type Node struct {
	key, priority int
	right, left   *Node
}

type Treap struct {
	root *Node
}








func NewTreap() *Treap {
	tr := new(Treap)
	tr.root = nil
	return tr
}





func (tr *Treap) InsertBySettingPri(key, priority int) {
	tr.root = tr.insert(tr.root, key, priority)
}



var _gtx, _gty, _gtz, _gtw = 123456789, 362436069, 521288629, 88675123







func (tr *Treap) Insert(key int) {
	

	

	

	randInt := func() int {
		tt := (_gtx ^ (_gtx << 11))
		_gtx = _gty
		_gty = _gtz
		_gtz = _gtw
		_gtw = (_gtw ^ (_gtw >> 19)) ^ (tt ^ (tt >> 8))
		return _gtw
	}

	tr.root = tr.insert(tr.root, key, randInt())
}





func (tr *Treap) Find(k int) *Node {
	u := tr.root
	for u != nil && k != u.key {
		if k < u.key {
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





var (
	

	ReadString func() string
	stdout     *bufio.Writer
)

func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
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



func ReadInt() int {
	return int(readInt64())
}
func ReadInt2() (int, int) {
	return int(readInt64()), int(readInt64())
}
func ReadInt3() (int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64())
}
func ReadInt4() (int, int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64())
}



func ReadInt64() int64 {
	return readInt64()
}
func ReadInt64_2() (int64, int64) {
	return readInt64(), readInt64()
}
func ReadInt64_3() (int64, int64, int64) {
	return readInt64(), readInt64(), readInt64()
}
func ReadInt64_4() (int64, int64, int64, int64) {
	return readInt64(), readInt64(), readInt64(), readInt64()
}

func readInt64() int64 {
	i, err := strconv.ParseInt(ReadString(), 0, 64)
	if err != nil {
		panic(err.Error())
	}
	return i
}



func ReadIntSlice(n int) []int {
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt()
	}
	return b
}



func ReadInt64Slice(n int) []int64 {
	b := make([]int64, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt64()
	}
	return b
}



func ReadFloat64() float64 {
	return float64(readFloat64())
}

func readFloat64() float64 {
	f, err := strconv.ParseFloat(ReadString(), 64)
	if err != nil {
		panic(err.Error())
	}
	return f
}



func ReadFloat64Slice(n int) []float64 {
	b := make([]float64, n)
	for i := 0; i < n; i++ {
		b[i] = ReadFloat64()
	}
	return b
}



func ReadRuneSlice() []rune {
	return []rune(ReadString())
}







func ZeroPaddingRuneSlice(n, digitsNum int) []rune {
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





func Strtoi(s string) int {
	if i, err := strconv.Atoi(s); err != nil {
		panic(errors.New("[argument error]: Strtoi only accepts integer string"))
	} else {
		return i
	}
}



func PrintIntsLine(A ...int) string {
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



func PrintInts64Line(A ...int64) string {
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



func PrintfDebug(format string, a ...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}





func PrintfBufStdout(format string, a ...interface{}) {
	fmt.Fprintf(stdout, format, a...)
}
