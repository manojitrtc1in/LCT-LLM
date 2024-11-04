package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var mod int = 1000000007
var mod1 int = 998244353

type TreeNode struct {
	key       int
	value     int
	left      *TreeNode
	right     *TreeNode
	parent    *TreeNode
	height    int
	num_left  int
	num_total int
}

type AvlTree struct {
	tree *TreeNode
}

func (t *AvlTree) add(k, v int) {
	if t.tree == nil {
		t.tree = &TreeNode{
			key:       k,
			value:     v,
			left:      nil,
			right:     nil,
			parent:    nil,
			height:    1,
			num_left:  1,
			num_total: 1,
		}
		return
	}
	node := t._add(k, v)
	if node != nil {
		t._rebalance(node)
	}
}

func (t *AvlTree) _add(k, v int) *TreeNode {
	node := t.tree
	for node != nil {
		if k < node.key {
			if node.left != nil {
				node = node.left
			} else {
				node.left = &TreeNode{
					key:       k,
					value:     v,
					left:      nil,
					right:     nil,
					parent:    node,
					height:    1,
					num_left:  1,
					num_total: 1,
				}
				return node.left
			}
		} else if node.key < k {
			if node.right != nil {
				node = node.right
			} else {
				node.right = &TreeNode{
					key:       k,
					value:     v,
					left:      nil,
					right:     nil,
					parent:    node,
					height:    1,
					num_left:  1,
					num_total: 1,
				}
				return node.right
			}
		} else {
			node.value = v
			return nil
		}
	}
	return nil
}

func (t *AvlTree) get_height(x *TreeNode) int {
	if x != nil {
		return x.height
	}
	return 0
}

func (t *AvlTree) get_num_total(x *TreeNode) int {
	if x != nil {
		return x.num_total
	}
	return 0
}

func (t *AvlTree) _rebalance(node *TreeNode) {
	n := node
	for n != nil {
		lh := t.get_height(n.left)
		rh := t.get_height(n.right)
		n.height = max(lh, rh) + 1
		balance_factor := lh - rh
		n.num_total = 1 + t.get_num_total(n.left) + t.get_num_total(n.right)
		n.num_left = 1 + t.get_num_total(n.left)

		if balance_factor > 1 {
			if t.get_height(n.left.left) < t.get_height(n.left.right) {
				t._rotate_left(n.left)
			}
			t._rotate_right(n)
		} else if balance_factor < -1 {
			if t.get_height(n.right.right) < t.get_height(n.right.left) {
				t._rotate_right(n.right)
			}
			t._rotate_left(n)
		} else {
			n = n.parent
		}
	}
}

func (t *AvlTree) _remove_one(node *TreeNode) {
	replacement := node.left
	if replacement == nil {
		replacement = node.right
	}
	if node.parent != nil {
		if t._is_left(node) {
			node.parent.left = replacement
		} else {
			node.parent.right = replacement
		}
		if replacement != nil {
			replacement.parent = node.parent
		}
		node.parent = nil
	} else {
		t.tree = replacement
		if replacement != nil {
			replacement.parent = nil
		}
	}
	node.left = nil
	node.right = nil
	node.parent = nil
	t._rebalance(replacement)
}

func (t *AvlTree) _remove_leaf(node *TreeNode) {
	if node.parent != nil {
		if t._is_left(node) {
			node.parent.left = nil
		} else {
			node.parent.right = nil
		}
		t._rebalance(node.parent)
	} else {
		t.tree = nil
	}
	node.parent = nil
	node.left = nil
	node.right = nil
}

func (t *AvlTree) remove(k int) {
	node := t._get_node(k)
	if node == nil {
		return
	}
	if t._is_leaf(node) {
		t._remove_leaf(node)
		return
	}
	if node.left != nil && node.right != nil {
		nxt := t._get_next(node)
		node.key = nxt.key
		node.value = nxt.value
		if t._is_leaf(nxt) {
			t._remove_leaf(nxt)
		} else {
			t._remove_one(nxt)
		}
		t._rebalance(node)
	} else {
		t._remove_one(node)
	}
}

func (t *AvlTree) get(k int) int {
	node := t._get_node(k)
	if node != nil {
		return node.value
	}
	return -1
}

func (t *AvlTree) _get_node(k int) *TreeNode {
	node := t.tree
	for node != nil {
		if k < node.key {
			node = node.left
		} else if node.key < k {
			node = node.right
		} else {
			return node
		}
	}
	return nil
}

func (t *AvlTree) get_at(pos int) (int, int) {
	x := pos + 1
	node := t.tree
	for node != nil {
		if x < node.num_left {
			node = node.left
		} else if node.num_left < x {
			x -= node.num_left
			node = node.right
		} else {
			return node.key, node.value
		}
	}
	panic("Out of ranges")
}

func (t *AvlTree) _is_left(node *TreeNode) bool {
	return node.parent != nil && node.parent.left == node
}

func (t *AvlTree) _is_leaf(node *TreeNode) bool {
	return node.left == nil && node.right == nil
}

func (t *AvlTree) _rotate_right(node *TreeNode) {
	if node.parent == nil {
		t.tree = node.left
		node.left.parent = nil
	} else if t._is_left(node) {
		node.parent.left = node.left
		node.left.parent = node.parent
	} else {
		node.parent.right = node.left
		node.left.parent = node.parent
	}
	bk := node.left.right
	node.left.right = node
	node.parent = node.left
	node.left = bk
	if bk != nil {
		bk.parent = node
	}
	node.height = max(t.get_height(node.left), t.get_height(node.right)) + 1
	node.num_total = 1 + t.get_num_total(node.left) + t.get_num_total(node.right)
	node.num_left = 1 + t.get_num_total(node.left)
}

func (t *AvlTree) _rotate_left(node *TreeNode) {
	if node.parent == nil {
		t.tree = node.right
		node.right.parent = nil
	} else if t._is_left(node) {
		node.parent.left = node.right
		node.right.parent = node.parent
	} else {
		node.parent.right = node.right
		node.right.parent = node.parent
	}
	bk := node.right.left
	node.right.left = node
	node.parent = node.right
	node.right = bk
	if bk != nil {
		bk.parent = node
	}
	node.height = max(t.get_height(node.left), t.get_height(node.right)) + 1
	node.num_total = 1 + t.get_num_total(node.left) + t.get_num_total(node.right)
	node.num_left = 1 + t.get_num_total(node.left)
}

func (t *AvlTree) _get_next(node *TreeNode) *TreeNode {
	if node.right == nil {
		return node.parent
	}
	n := node.right
	for n.left != nil {
		n = n.left
	}
	return n
}

type SegmentTree1 struct {
	data    []int
	_size   int
	_default int
	_func    func(int, int) int
}

func NewSegmentTree1(data []int, defaultVal int, funcVal func(int, int) int) *SegmentTree1 {
	size := 1 << (len(data) - 1)
	st := &SegmentTree1{
		data:    make([]int, 2*size),
		_size:   size,
		_default: defaultVal,
		_func:    funcVal,
	}
	copy(st.data[size:size+len(data)], data)
	for i := size - 1; i >= 0; i-- {
		st.data[i] = funcVal(st.data[2*i], st.data[2*i+1])
	}
	return st
}

func (st *SegmentTree1) Query(start, stop int) int {
	if start == stop {
		return st.data[start+st._size]
	}
	stop++
	start += st._size
	stop += st._size

	res := st._default
	for start < stop {
		if start&1 == 1 {
			res = st._func(res, st.data[start])
			start++
		}
		if stop&1 == 1 {
			stop--
			res = st._func(res, st.data[stop])
		}
		start >>= 1
		stop >>= 1
	}
	return res
}

type SegmentTree struct {
	data    []int
	_size   int
	_default int
	_func    func(int, int) int
}

func NewSegmentTree(data []int, defaultVal int, funcVal func(int, int) int) *SegmentTree {
	size := 1 << (len(data) - 1)
	st := &SegmentTree{
		data:    make([]int, 2*size),
		_size:   size,
		_default: defaultVal,
		_func:    funcVal,
	}
	copy(st.data[size:size+len(data)], data)
	for i := size - 1; i >= 0; i-- {
		st.data[i] = funcVal(st.data[2*i], st.data[2*i+1])
	}
	return st
}

func (st *SegmentTree) Query(start, stop int) int {
	if start == stop {
		return st.data[start+st._size]
	}
	stop++
	start += st._size
	stop += st._size

	res := st._default
	for start < stop {
		if start&1 == 1 {
			res = st._func(res, st.data[start])
			start++
		}
		if stop&1 == 1 {
			stop--
			res = st._func(res, st.data[stop])
		}
		start >>= 1
		stop >>= 1
	}
	return res
}

type Factorial struct {
	MOD           int
	factorials    []int
	invModulos    []int
	invFactorial_ []int
}

func NewFactorial(MOD int) *Factorial {
	f := &Factorial{
		MOD:           MOD,
		factorials:    []int{1, 1},
		invModulos:    []int{0, 1},
		invFactorial_: []int{1, 1},
	}
	return f
}

func (f *Factorial) Calc(n int) int {
	if n <= -1 {
		fmt.Println("Invalid argument to calculate n!")
		fmt.Println("n must be non-negative value. But the argument was " + strconv.Itoa(n))
		os.Exit(1)
	}
	if n < len(f.factorials) {
		return f.factorials[n]
	}
	nextArr := make([]int, n+1-len(f.factorials))
	initialI := len(f.factorials)
	prev := f.factorials[len(f.factorials)-1]
	m := f.MOD
	for i := initialI; i <= n; i++ {
		prev = nextArr[i-initialI] = (prev * i) % m
	}
	f.factorials = append(f.factorials, nextArr...)
	return f.factorials[n]
}

func (f *Factorial) Inv(n int) int {
	if n <= -1 {
		fmt.Println("Invalid argument to calculate n^(-1)")
		fmt.Println("n must be non-negative value. But the argument was " + strconv.Itoa(n))
		os.Exit(1)
	}
	p := f.MOD
	pi := n % p
	if pi < len(f.invModulos) {
		return f.invModulos[pi]
	}
	nextArr := make([]int, n+1-len(f.invModulos))
	initialI := len(f.invModulos)
	for i := initialI; i < p && i <= n; i++ {
		next := -f.invModulos[p%i] * (p / i) % p
		f.invModulos = append(f.invModulos, next)
	}
	return f.invModulos[pi]
}

func (f *Factorial) InvFactorial(n int) int {
	if n <= -1 {
		fmt.Println("Invalid argument to calculate (n^(-1))!")
		fmt.Println("n must be non-negative value. But the argument was " + strconv.Itoa(n))
		os.Exit(1)
	}
	if n < len(f.invFactorial_) {
		return f.invFactorial_[n]
	}
	f.Inv(n)
	nextArr := make([]int, n+1-len(f.invFactorial_))
	initialI := len(f.invFactorial_)
	prev := f.invFactorial_[len(f.invFactorial_)-1]
	p := f.MOD
	for i := initialI; i <= n; i++ {
		prev = nextArr[i-initialI] = (prev * f.invModulos[i%p]) % p
	}
	f.invFactorial_ = append(f.invFactorial_, nextArr...)
	return f.invFactorial_[n]
}

type Combination struct {
	MOD       int
	factorial *Factorial
}

func NewCombination(MOD int) *Combination {
	c := &Combination{
		MOD:       MOD,
		factorial: NewFactorial(MOD),
	}
	return c
}

func (c *Combination) Ncr(n, k int) int {
	if k < 0 || n < k {
		return 0
	}
	k = min(k, n-k)
	f := c.factorial
	return (f.Calc(n) * f.InvFactorial(max(n-k, k)) * f.InvFactorial(min(k, n-k))) % c.MOD
}

func Powm(a, n, m int) int {
	if a == 1 || n == 0 {
		return 1
	}
	if n%2 == 0 {
		s := Powm(a, n/2, m)
		return (s * s) % m
	} else {
		return (a * Powm(a, n-1, m)) % m
	}
}

func SortList(list1, list2 []int) []int {
	zippedPairs := make([][]int, len(list2))
	for i := range zippedPairs {
		zippedPairs[i] = []int{list2[i], list1[i]}
	}
	sort.Slice(zippedPairs, func(i, j int) bool {
		return zippedPairs[i][0] < zippedPairs[j][0]
	})
	z := make([]int, len(list1))
	for i := range zippedPairs {
		z[i] = zippedPairs[i][1]
	}
	return z
}

func Product(l []int) int {
	por := 1
	for i := range l {
		por *= l[i]
	}
	return por
}

func BinarySearchCount(arr []int, n, key int) int {
	left := 0
	right := n - 1

	count := 0

	for left <= right {
		mid := (right + left) / 2

		if arr[mid] < key {
			count = mid + 1
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return count
}

func CountDig(n int) int {
	c := 0
	for n > 0 {
		n /= 10
		c++
	}
	return c
}

func Binary(x, length int) string {
	y := strconv.FormatInt(int64(x), 2)
	if len(y) >= length {
		return y
	}
	return strings.Repeat("0", length-len(y)) + y
}

func CountGreater(arr []int, n, k int) int {
	l := 0
	r := n - 1

	leftGreater := n

	for l <= r {
		m := (l + r) / 2
		if arr[m] >= k {
			leftGreater = m
			r = m - 1
		} else {
			l = m + 1
		}
	}

	return n - leftGreater
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, a, b int
	fmt.Fscan(reader, &n, &m, &a, &b)

	ans := 3
	if a%m == 1 {
		ans -= 1
	}
	if b%m == 0 || b == n {
		ans -= 1
	}
	if m == 1 {
		fmt.Fprintln(writer, 1)
		return
	} else if (a-1)/m == (b-1)/m {
		fmt.Fprintln(writer, 1)
		return
	} else if (a%m-b%m)%m == 1 {
		fmt.Fprintln(writer, min(2, ans, (b-1)/m-(a-1)/m+1))
		return
	}
	fmt.Fprintln(writer, min(ans, (b-1)/m-(a-1)/m+1))
}