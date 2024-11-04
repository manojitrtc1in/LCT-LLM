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

type id8 struct {
	_tree *TreeNode
}

func (id *id8) add(k int, v int) {
	if id._tree == nil {
		id._tree = &TreeNode{
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
	node := id._add(k, v)
	if node != nil {
		id._rebalance(node)
	}
}

func (id *id8) _add(k int, v int) *TreeNode {
	node := id._tree
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

func (id *id8) get_height(x *TreeNode) int {
	if x != nil {
		return x.height
	}
	return 0
}

func (id *id8) id1(x *TreeNode) int {
	if x != nil {
		return x.num_total
	}
	return 0
}

func (id *id8) _rebalance(node *TreeNode) {
	n := node
	for n != nil {
		lh := id.get_height(n.left)
		rh := id.get_height(n.right)
		n.height = max(lh, rh) + 1
		balance_factor := lh - rh
		n.num_total = 1 + id.id1(n.left) + id.id1(n.right)
		n.num_left = 1 + id.id1(n.left)

		if balance_factor > 1 {
			if id.get_height(n.left.left) < id.get_height(n.left.right) {
				id._rotate_left(n.left)
			}
			id._rotate_right(n)
		} else if balance_factor < -1 {
			if id.get_height(n.right.right) < id.get_height(n.right.left) {
				id._rotate_right(n.right)
			}
			id._rotate_left(n)
		} else {
			n = n.parent
		}
	}
}

func (id *id8) _remove_one(node *TreeNode) {
	replacement := node.left
	if replacement == nil {
		replacement = node.right
	}
	if node.parent != nil {
		if id._is_left(node) {
			node.parent.left = replacement
		} else {
			node.parent.right = replacement
		}
		if replacement != nil {
			replacement.parent = node.parent
		}
		node.parent = nil
	} else {
		id._tree = replacement
		if replacement != nil {
			replacement.parent = nil
		}
	}
	node.left = nil
	node.right = nil
	node.parent = nil
	id._rebalance(replacement)
}

func (id *id8) _remove_leaf(node *TreeNode) {
	if node.parent != nil {
		if id._is_left(node) {
			node.parent.left = nil
		} else {
			node.parent.right = nil
		}
		id._rebalance(node.parent)
	} else {
		id._tree = nil
	}
	node.parent = nil
	node.left = nil
	node.right = nil
}

func (id *id8) remove(k int) {
	node := id._get_node(k)
	if node == nil {
		return
	}
	if id._is_leaf(node) {
		id._remove_leaf(node)
		return
	}
	if node.left != nil && node.right != nil {
		nxt := id._get_next(node)
		node.key = nxt.key
		node.value = nxt.value
		if id._is_leaf(nxt) {
			id._remove_leaf(nxt)
		} else {
			id._remove_one(nxt)
		}
		id._rebalance(node)
	} else {
		id._remove_one(node)
	}
}

func (id *id8) get(k int) int {
	node := id._get_node(k)
	if node != nil {
		return node.value
	}
	return -1
}

func (id *id8) _get_node(k int) *TreeNode {
	if id._tree == nil {
		return nil
	}
	node := id._tree
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

func (id *id8) get_at(pos int) (int, int) {
	x := pos + 1
	node := id._tree
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

func (id *id8) _is_left(node *TreeNode) bool {
	return node.parent != nil && node.parent.left == node
}

func (id *id8) _is_leaf(node *TreeNode) bool {
	return node.left == nil && node.right == nil
}

func (id *id8) _rotate_right(node *TreeNode) {
	if node.parent == nil {
		id._tree = node.left
		node.left.parent = nil
	} else if id._is_left(node) {
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
	node.height = max(id.get_height(node.left), id.get_height(node.right)) + 1
	node.num_total = 1 + id.id1(node.left) + id.id1(node.right)
	node.num_left = 1 + id.id1(node.left)
}

func (id *id8) _rotate_left(node *TreeNode) {
	if node.parent == nil {
		id._tree = node.right
		node.right.parent = nil
	} else if id._is_left(node) {
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
	node.height = max(id.get_height(node.left), id.get_height(node.right)) + 1
	node.num_total = 1 + id.id1(node.left) + id.id1(node.right)
	node.num_left = 1 + id.id1(node.left)
}

func (id *id8) _get_next(node *TreeNode) *TreeNode {
	if node.right == nil {
		return node.parent
	}
	n := node.right
	for n.left != nil {
		n = n.left
	}
	return n
}

type id0 struct {
	_default int
	_func    func(int, int) int
	_len     int
	_size    int
	data     []int
}

func newid0(data []int, _default int, _func func(int, int) int) *id0 {
	_len := len(data)
	_size := 1 << (len(data)-1)>>1
	d := make([]int, 2*_size)
	copy(d[_size:_size+_len], data)
	for i := _size - 1; i >= 0; i-- {
		d[i] = _func(d[2*i], d[2*i+1])
	}
	return &id0{_default, _func, _len, _size, d}
}

func (id *id0) id4(idx int) {
	id.data[idx] = id._default
}

func (id *id0) id6(idx int) int {
	return id.data[idx+id._size]
}

func (id *id0) id3(idx int, value int) {
	idx += id._size
	id.data[idx] = value
	idx >>= 1
	for idx > 0 {
		id.data[idx] = id._func(id.data[2*idx], id.data[2*idx+1])
		idx >>= 1
	}
}

func (id *id0) id11() int {
	return id._len
}

func (id *id0) query(start int, stop int) int {
	if start == stop {
		return id.id6(start)
	}
	stop++
	start += id._size
	stop += id._size

	res := id._default
	for start < stop {
		if start&1 == 1 {
			res = id._func(res, id.data[start])
			start++
		}
		if stop&1 == 1 {
			stop--
			res = id._func(res, id.data[stop])
		}
		start >>= 1
		stop >>= 1
	}
	return res
}

type SegmentTree struct {
	_default int
	_func    func(int, int) int
	_len     int
	_size    int
	data     []int
}

func newSegmentTree(data []int, _default int, _func func(int, int) int) *SegmentTree {
	_len := len(data)
	_size := 1 << (len(data)-1)>>1
	d := make([]int, 2*_size)
	copy(d[_size:_size+_len], data)
	for i := _size - 1; i >= 0; i-- {
		d[i] = _func(d[2*i], d[2*i+1])
	}
	return &SegmentTree{_default, _func, _len, _size, d}
}

func (id *SegmentTree) id4(idx int) {
	id.data[idx] = id._default
}

func (id *SegmentTree) id6(idx int) int {
	return id.data[idx+id._size]
}

func (id *SegmentTree) id3(idx int, value int) {
	idx += id._size
	id.data[idx] = value
	idx >>= 1
	for idx > 0 {
		id.data[idx] = id._func(id.data[2*idx], id.data[2*idx+1])
		idx >>= 1
	}
}

func (id *SegmentTree) id11() int {
	return id._len
}

func (id *SegmentTree) query(start int, stop int) int {
	if start == stop {
		return id.id6(start)
	}
	stop++
	start += id._size
	stop += id._size

	res := id._default
	for start < stop {
		if start&1 == 1 {
			res = id._func(res, id.data[start])
			start++
		}
		if stop&1 == 1 {
			stop--
			res = id._func(res, id.data[stop])
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

func newFactorial(MOD int) *Factorial {
	factorials := []int{1, 1}
	invModulos := []int{0, 1}
	invFactorial_ := []int{1, 1}
	return &Factorial{MOD, factorials, invModulos, invFactorial_}
}

func (f *Factorial) calc(n int) int {
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

func (f *Factorial) inv(n int) int {
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
		next := (-f.invModulos[p%i] * (p / i)) % p
		f.invModulos = append(f.invModulos, next)
	}
	return f.invModulos[pi]
}

func (f *Factorial) id10(n int) int {
	if n <= -1 {
		fmt.Println("Invalid argument to calculate (n^(-1))!")
		fmt.Println("n must be non-negative value. But the argument was " + strconv.Itoa(n))
		os.Exit(1)
	}
	if n < len(f.invFactorial_) {
		return f.invFactorial_[n]
	}
	f.inv(n)
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

func newCombination(MOD int) *Combination {
	factorial := newFactorial(MOD)
	return &Combination{MOD, factorial}
}

func (c *Combination) ncr(n int, k int) int {
	if k < 0 || n < k {
		return 0
	}
	k = min(k, n-k)
	f := c.factorial
	return (f.calc(n) * f.id10(max(n-k, k)) * f.id10(min(k, n-k))) % c.MOD
}

func powm(a int, n int, m int) int {
	if a == 1 || n == 0 {
		return 1
	}
	if n%2 == 0 {
		s := powm(a, n/2, m)
		return (s * s) % m
	} else {
		return (a * powm(a, n-1, m)) % m
	}
}

func sort_list(list1 []int, list2 []int) []int {
	id5 := make([][]int, len(list2))
	for i := 0; i < len(list2); i++ {
		id5[i] = []int{list2[i], list1[i]}
	}
	sort.Slice(id5, func(i, j int) bool {
		return id5[i][0] < id5[j][0]
	})
	z := make([]int, len(list1))
	for i := 0; i < len(list1); i++ {
		z[i] = id5[i][1]
	}
	return z
}

func product(l []int) int {
	por := 1
	for i := 0; i < len(l); i++ {
		por *= l[i]
	}
	return por
}

func id9(arr []int, n int, key int) int {
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

func countdig(n int) int {
	c := 0
	for n > 0 {
		n /= 10
		c++
	}
	return c
}

func binary(x int, length int) string {
	y := strconv.FormatInt(int64(x), 2)
	if len(y) >= length {
		return y
	} else {
		return strings.Repeat("0", length-len(y)) + y
	}
}

func countGreater(arr []int, n int, k int) int {
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

	return (n - leftGreater)
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

func solve() {
	n, m, a, b := 0, 0, 0, 0
	fmt.Scanf("%d %d %d %d", &n, &m, &a, &b)
	ans := 3
	if a%m == 1 {
		ans -= 1
	}
	if b%m == 0 || b == n {
		ans -= 1
	}
	if m == 1 {
		fmt.Println(1)
		return
	} else if (a-1)/m == (b-1)/m {
		fmt.Println(1)
		return
	} else if (a%m-b%m)%m == 1 {
		fmt.Println(min(2, ans, (b-1)/m-(a-1)/m+1))
		return
	}
	fmt.Println(min(ans, (b-1)/m-(a-1)/m+1))
}

func main() {
	solve()
}
