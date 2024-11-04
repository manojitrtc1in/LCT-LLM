package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Kattio struct {
	scanner *bufio.Scanner
	writer  *bufio.Writer
}

func NewKattio() *Kattio {
	return &Kattio{
		scanner: bufio.NewScanner(os.Stdin),
		writer:  bufio.NewWriter(os.Stdout),
	}
}

func (k *Kattio) nextLine() string {
	k.scanner.Scan()
	return k.scanner.Text()
}

func (k *Kattio) next() string {
	k.scanner.Scan()
	return k.scanner.Text()
}

func (k *Kattio) nextInt() int {
	val, _ := strconv.Atoi(k.next())
	return val
}

func (k *Kattio) nextLong() int64 {
	val, _ := strconv.ParseInt(k.next(), 10, 64)
	return val
}

func (k *Kattio) flush() {
	k.writer.Flush()
}

var powerSet [][]int64
var mod = int64(math.Pow(10, 9) + 7)

func main() {
	input := NewKattio()
	defer input.writer.Flush()

	n := input.nextInt()
	w := input.nextLong()
	fmt.Fprintln(input.writer, bfs(w, n))
}

func bfs(w int64, n int) int {
	q := []int64{w}
	h := make(map[int64]int)
	h[w] = 0
	min := int(^uint(0) >> 1)

	for len(q) > 0 {
		s := q[0]
		q = q[1:]

		if n == len(fmt.Sprintf("%d", s)) {
			return h[s]
		}

		t := make(map[int]struct{})
		e := fmt.Sprintf("%d", s)
		for _, char := range e {
			digit := int(char - '0')
			t[digit] = struct{}{}
		}

		for x := range t {
			v := int64(x) * s
			if len(fmt.Sprintf("%d", v)) > n {
				continue
			}
			if _, exists := h[v]; !exists {
				h[v] = h[s] + 1
				q = append(q, v)
			}
		}
	}
	if min == int(^uint(0)>>1) {
		return -1
	}
	return min
}

func log2(n int64) int {
	cnt := 0
	for n > 1 {
		n /= 2
		cnt++
	}
	return cnt
}

func bfsGraph(node int, a [][]int) []int {
	q := []int{node}
	distances := make([]int, len(a))
	for i := range distances {
		distances[i] = -1
	}
	distances[node] = 0

	for len(q) > 0 {
		parent := q[0]
		q = q[1:]

		cost := distances[parent]
		for _, node1 := range a[parent] {
			if distances[node1] == -1 {
				q = append(q, node1)
				distances[node1] = cost + 1
			}
		}
	}
	return distances
}

func get(n int) int {
	sum := 0
	for n > 0 {
		sum += n % 10
		n /= 10
	}
	return sum
}

func primeFactors(n int) int64 {
	sum := int64(1)
	for n%2 == 0 {
		sum *= 2
		n /= 2
	}
	for i := 3; i <= int(math.Sqrt(float64(n))); i += 2 {
		for n%i == 0 {
			sum *= int64(i)
			n /= i
		}
		if n < i {
			break
		}
	}
	if n > 2 {
		sum *= int64(n)
	}
	return sum
}

func printPrimeFactorization(n int) []int {
	a := []int{}
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			if isPrime(i) {
				a = append(a, i)
				n /= i
				i = 0
			} else if isPrime(n/i) {
				a = append(a, n/i)
				n = i
				i = 0
			}
		}
	}
	return a
}

func generate(ind int, a []int64, sub []int64) {
	if ind == len(a) {
		powerSet = append(powerSet, sub)
		return
	}
	have := append([]int64{}, sub...)
	less := append([]int64{}, sub...)
	have = append(have, a[ind])
	generate(ind+1, a, have)
	generate(ind+1, a, less)
}

func factorial(n int64) int64 {
	if n <= 1 {
		return 1
	}
	t := n - 1
	for t > 1 {
		n *= t
		t--
	}
	return n
}

func isPalindrome(n int) bool {
	t := n
	ans := 0
	for t > 0 {
		ans = ans*10 + t%10
		t /= 10
	}
	return ans == n
}

type tri struct {
	x, y, z int
}

func isPrime(num int64) bool {
	if num == 1 {
		return false
	}
	if num == 2 {
		return true
	}
	if num%2 == 0 {
		return false
	}
	if num == 3 {
		return true
	}
	for i := int64(3); i <= int64(math.Sqrt(float64(num)))+1; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func prefixSum(a []int) {
	for i := 1; i < len(a); i++ {
		a[i] += a[i-1]
	}
}

func suffixSum(a []int64) {
	for i := len(a) - 2; i > -1; i-- {
		a[i] += a[i+1]
	}
}

func mod(a, b int64) int64 {
	r := a % b
	if r < 0 {
		return r + b
	}
	return r
}

func binaryToDecimal(w string) int64 {
	r := int64(0)
	l := int64(0)
	for i := len(w) - 1; i > -1; i-- {
		x := int64(w[i]-'0') * int64(math.Pow(2, float64(l)))
		r += x
		l++
	}
	return r
}

func decimalToBinary(n int64) string {
	w := ""
	for n > 0 {
		w = fmt.Sprintf("%d%s", n%2, w)
		n /= 2
	}
	return w
}

func isSorted(a []int) bool {
	for i := 0; i < len(a)-1; i++ {
		if a[i] > a[i+1] {
			return false
		}
	}
	return true
}

func print(a []int) {
	for _, v := range a {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

func read(a []int) {
	for i := range a {
		a[i] = input.nextInt()
	}
}

type pair struct {
	x, y int64
}

func (p pair) String() string {
	return fmt.Sprintf("%d %d", p.x, p.y)
}

func LCM(x, y int64) int64 {
	return x / GCD(x, y) * y
}

func GCD(x, y int64) int64 {
	if y == 0 {
		return x
	}
	return GCD(y, x%y)
}

func simplifyTheFraction(a, b int64) {
	gcd := GCD(a, b)
	fmt.Println(a/gcd, b/gcd)
}

type RedBlackNode struct {
	key       interface{}
	parent    *RedBlackNode
	left      *RedBlackNode
	right     *RedBlackNode
	numLeft   int
	numRight  int
	color     int
}

const (
	BLACK = 0
	RED   = 1
)

type RedBlackTree struct {
	nil  *RedBlackNode
	root *RedBlackNode
}

func NewRedBlackTree() *RedBlackTree {
	nilNode := &RedBlackNode{}
	return &RedBlackTree{
		nil:  nilNode,
		root: nilNode,
	}
}

func (tree *RedBlackTree) leftRotate(x *RedBlackNode) {
	tree.leftRotateFixup(x)

	y := x.right
	x.right = y.left

	if y.left != tree.nil {
		y.left.parent = x
	}
	y.parent = x.parent

	if tree.nil == x.parent {
		tree.root = y
	} else if x.parent.left == x {
		x.parent.left = y
	} else {
		x.parent.right = y
	}

	y.left = x
	x.parent = y
}

func (tree *RedBlackTree) leftRotateFixup(x *RedBlackNode) {
	if x.left == tree.nil && x.right.left == tree.nil {
		x.numLeft = 0
		x.numRight = 0
		x.right.numLeft = 1
	} else if x.left == tree.nil && x.right.left != tree.nil {
		x.numLeft = 0
		x.numRight = 1 + x.right.left.numLeft + x.right.left.numRight
		x.right.numLeft = 2 + x.right.left.numLeft + x.right.left.numRight
	} else if x.left != tree.nil && x.right.left == tree.nil {
		x.numRight = 0
		x.right.numLeft = 2 + x.left.numLeft + x.left.numRight
	} else {
		x.numRight = 1 + x.right.left.numLeft + x.right.left.numRight
		x.right.numLeft = 3 + x.left.numLeft + x.left.numRight + x.right.left.numLeft + x.right.left.numRight
	}
}

func (tree *RedBlackTree) rightRotate(y *RedBlackNode) {
	tree.rightRotateFixup(y)

	x := y.left
	y.left = x.right

	if x.right != tree.nil {
		x.right.parent = y
	}
	x.parent = y.parent

	if tree.nil == y.parent {
		tree.root = x
	} else if y.parent.right == y {
		y.parent.right = x
	} else {
		y.parent.left = x
	}
	x.right = y
	y.parent = x
}

func (tree *RedBlackTree) rightRotateFixup(y *RedBlackNode) {
	if y.right == tree.nil && y.left.right == tree.nil {
		y.numRight = 0
		y.numLeft = 0
		y.left.numRight = 1
	} else if y.right == tree.nil && y.left.right != tree.nil {
		y.numRight = 0
		y.numLeft = 1 + y.left.right.numRight + y.left.right.numLeft
		y.left.numRight = 2 + y.left.right.numRight + y.left.right.numLeft
	} else if y.right != tree.nil && y.left.right == tree.nil {
		y.numLeft = 0
		y.left.numRight = 2 + y.right.numRight + y.right.numLeft
	} else {
		y.numLeft = 1 + y.left.right.numRight + y.left.right.numLeft
		y.left.numRight = 3 + y.right.numRight + y.right.numLeft + y.left.right.numRight + y.left.right.numLeft
	}
}

func (tree *RedBlackTree) insert(key interface{}) {
	tree.insert(&RedBlackNode{key: key})
}

func (tree *RedBlackTree) insert(z *RedBlackNode) {
	y := tree.nil
	x := tree.root

	for x != tree.nil {
		y = x
		if z.key.(int) < x.key.(int) {
			x.numLeft++
			x = x.left
		} else {
			x.numRight++
			x = x.right
		}
	}

	z.parent = y

	if tree.nil == y {
		tree.root = z
	} else if z.key.(int) < y.key.(int) {
		y.left = z
	} else {
		y.right = z
	}

	z.left = tree.nil
	z.right = tree.nil
	z.color = RED

	tree.insertFixup(z)
}

func (tree *RedBlackTree) insertFixup(z *RedBlackNode) {
	var y *RedBlackNode
	for z.parent.color == RED {
		if z.parent == z.parent.parent.left {
			y = z.parent.parent.right
			if y.color == RED {
				z.parent.color = BLACK
				y.color = BLACK
				z.parent.parent.color = RED
				z = z.parent.parent
			} else if z == z.parent.right {
				z = z.parent
				tree.leftRotate(z)
			} else {
				z.parent.color = BLACK
				z.parent.parent.color = RED
				tree.rightRotate(z.parent.parent)
			}
		} else {
			y = z.parent.parent.left
			if y.color == RED {
				z.parent.color = BLACK
				y.color = BLACK
				z.parent.parent.color = RED
				z = z.parent.parent
			} else if z == z.parent.left {
				z = z.parent
				tree.rightRotate(z)
			} else {
				z.parent.color = BLACK
				z.parent.parent.color = RED
				tree.leftRotate(z.parent.parent)
			}
		}
	}
	tree.root.color = BLACK
}

func (tree *RedBlackTree) treeMinimum(node *RedBlackNode) *RedBlackNode {
	for node.left != tree.nil {
		node = node.left
	}
	return node
}

func (tree *RedBlackTree) treeSuccessor(x *RedBlackNode) *RedBlackNode {
	if x.right != tree.nil {
		return tree.treeMinimum(x.right)
	}

	y := x.parent
	for y != tree.nil && x == y.right {
		x = y
		y = y.parent
	}
	return y
}

func (tree *RedBlackTree) remove(v *RedBlackNode) {
	z := tree.search(v.key)

	var x, y *RedBlackNode
	if z.left == tree.nil || z.right == tree.nil {
		y = z
	} else {
		y = tree.treeSuccessor(z)
	}

	if y.left != tree.nil {
		x = y.left
	} else {
		x = y.right
	}

	x.parent = y.parent

	if y.parent == tree.nil {
		tree.root = x
	} else if y.parent.left == y {
		y.parent.left = x
	} else {
		y.parent.right = x
	}

	if y != z {
		z.key = y.key
	}

	tree.fixNodeData(x, y)

	if y.color == BLACK {
		tree.removeFixup(x)
	}
}

func (tree *RedBlackTree) fixNodeData(x, y *RedBlackNode) {
	var current, track *RedBlackNode

	if x == tree.nil {
		current = y.parent
		track = y
	} else {
		current = x.parent
		track = x
	}

	for current != tree.nil {
		if y.key != current.key {
			if y.key.(int) > current.key.(int) {
				current.numRight--
			}
			if y.key.(int) < current.key.(int) {
				current.numLeft--
			}
		} else {
			if current.left == tree.nil {
				current.numLeft--
			} else if current.right == tree.nil {
				current.numRight--
			} else if track == current.right {
				current.numRight--
			} else if track == current.left {
				current.numLeft--
			}
		}
		track = current
		current = current.parent
	}
}

func (tree *RedBlackTree) removeFixup(x *RedBlackNode) {
	var w *RedBlackNode
	for x != tree.root && x.color == BLACK {
		if x == x.parent.left {
			w = x.parent.right
			if w.color == RED {
				w.color = BLACK
				x.parent.color = RED
				tree.leftRotate(x.parent)
				w = x.parent.right
			}
			if w.left.color == BLACK && w.right.color == BLACK {
				w.color = RED
				x = x.parent
			} else {
				if w.right.color == BLACK {
					w.left.color = BLACK
					w.color = RED
					tree.rightRotate(w)
					w = x.parent.right
				}
				w.color = x.parent.color
				x.parent.color = BLACK
				w.right.color = BLACK
				tree.leftRotate(x.parent)
				x = tree.root
			}
		} else {
			w = x.parent.left
			if w.color == RED {
				w.color = BLACK
				x.parent.color = RED
				tree.rightRotate(x.parent)
				w = x.parent.left
			}
			if w.right.color == BLACK && w.left.color == BLACK {
				w.color = RED
				x = x.parent
			} else {
				if w.left.color == BLACK {
					w.right.color = BLACK
					w.color = RED
					tree.leftRotate(w)
					w = x.parent.left
				}
				w.color = x.parent.color
				x.parent.color = BLACK
				w.left.color = BLACK
				tree.rightRotate(x.parent)
				x = tree.root
			}
		}
	}
	x.color = BLACK
}

func (tree *RedBlackTree) search(key interface{}) *RedBlackNode {
	current := tree.root
	for current != tree.nil {
		if current.key == key {
			return current
		} else if current.key.(int) < key.(int) {
			current = current.right
		} else {
			current = current.left
		}
	}
	return nil
}

func (tree *RedBlackTree) numGreater(key interface{}) int {
	return tree.findNumGreater(tree.root, key)
}

func (tree *RedBlackTree) numSmaller(key interface{}) int {
	return tree.findNumSmaller(tree.root, key)
}

func (tree *RedBlackTree) findNumGreater(node *RedBlackNode, key interface{}) int {
	if node == tree.nil {
		return 0
	} else if key.(int) < node.key.(int) {
		return 1 + node.numRight + tree.findNumGreater(node.left, key)
	} else {
		return tree.findNumGreater(node.right, key)
	}
}

func (tree *RedBlackTree) findNumSmaller(node *RedBlackNode, key interface{}) int {
	if node == tree.nil {
		return 0
	} else if key.(int) <= node.key.(int) {
		return tree.findNumSmaller(node.left, key)
	} else {
		return 1 + node.numLeft + tree.findNumSmaller(node.right, key)
	}
}

func (tree *RedBlackTree) isNil(node *RedBlackNode) bool {
	return node == tree.nil
}

func (tree *RedBlackTree) size() int {
	return tree.root.numLeft + tree.root.numRight + 1
}
