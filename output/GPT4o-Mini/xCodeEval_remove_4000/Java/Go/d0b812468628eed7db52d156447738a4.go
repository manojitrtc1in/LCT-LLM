package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type id7 struct {
	r *bufio.Reader
	w *bufio.Writer
}

func newId7() *id7 {
	return &id7{
		r: bufio.NewReader(os.Stdin),
		w: bufio.NewWriter(os.Stdout),
	}
}

func (input *id7) nextLine() string {
	line, _ := input.r.ReadString('\n')
	return strings.TrimSpace(line)
}

func (input *id7) next() string {
	line := input.nextLine()
	return strings.Fields(line)[0]
}

func (input *id7) nextInt() int {
	val, _ := strconv.Atoi(input.next())
	return val
}

func (input *id7) nextLong() int64 {
	val, _ := strconv.ParseInt(input.next(), 10, 64)
	return val
}

var input = newId7()
var powerSet [][]int64
var mod = int64(math.Pow(10, 9) + 7)

func main() {
	n := input.nextInt()
	w := input.nextLong()
	fmt.Fprintln(input.w, bfs(w, n))
	input.w.Flush()
}

func bfs(w int64, n int) int {
	q := []int64{w}
	h := make(map[int64]int)
	h[w] = 0
	min := math.MaxInt32

	for len(q) > 0 {
		s := q[0]
		q = q[1:]

		if n == len(strconv.FormatInt(s, 10)) {
			return h[s]
		}

		t := make(map[int]struct{})
		e := strconv.FormatInt(s, 10)
		for _, ch := range e {
			digit := int(ch - '0')
			t[digit] = struct{}{}
		}

		for x := range t {
			v := int64(x) * s
			if len(strconv.FormatInt(v, 10)) > n {
				continue
			}
			if _, exists := h[v]; !exists {
				h[v] = h[s] + 1
				q = append(q, v)
			}
		}
	}
	if min == math.MaxInt32 {
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
		nodes := a[parent]
		cost := distances[parent]

		for _, node1 := range nodes {
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

func id9(n int) []int {
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
	have := make([]int64, len(sub))
	copy(have, sub)
	less := make([]int64, len(sub))
	copy(less, sub)
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
		r += b
	}
	return r
}

func id13(w string) int64 {
	r := int64(0)
	l := int64(0)
	for i := len(w) - 1; i > -1; i-- {
		x := int64(w[i] - '0') * int64(math.Pow(2, float64(l)))
		r += x
		l++
	}
	return r
}

func id3(n int64) string {
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
		fmt.Fprintf(input.w, "%d ", v)
	}
	fmt.Fprintln(input.w)
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

func id10(a, b int64) {
	gcd := GCD(a, b)
	fmt.Printf("%d %d\n", a/gcd, b/gcd)
}

type id0 struct {
	key       interface{}
	parent    *id0
	left      *id0
	right     *id0
	numLeft   int
	numRight  int
	color     int
}

const (
	BLACK = 0
	RED   = 1
)

type id5 struct {
	nil  *id0
	root *id0
}

func newId5() *id5 {
	nilNode := &id0{}
	return &id5{
		nil:  nilNode,
		root: nilNode,
	}
}

func (t *id5) leftRotate(x *id0) {
	t.id17(x)
	y := x.right
	x.right = y.left

	if !t.isNil(y.left) {
		y.left.parent = x
	}
	y.parent = x.parent

	if t.isNil(x.parent) {
		t.root = y
	} else if x.parent.left == x {
		x.parent.left = y
	} else {
		x.parent.right = y
	}

	y.left = x
	x.parent = y
}

func (t *id5) id17(x *id0) {
	if t.isNil(x.left) && t.isNil(x.right.left) {
		x.numLeft = 0
		x.numRight = 0
		x.right.numLeft = 1
	} else if t.isNil(x.left) && !t.isNil(x.right.left) {
		x.numLeft = 0
		x.numRight = 1 + x.right.left.numLeft + x.right.left.numRight
		x.right.numLeft = 2 + x.right.left.numLeft + x.right.left.numRight
	} else if !t.isNil(x.left) && t.isNil(x.right.left) {
		x.numRight = 0
		x.right.numLeft = 2 + x.left.numLeft + x.left.numRight
	} else {
		x.numRight = 1 + x.right.left.numLeft + x.right.left.numRight
		x.right.numLeft = 3 + x.left.numLeft + x.left.numRight + x.right.left.numLeft + x.right.left.numRight
	}
}

func (t *id5) rightRotate(y *id0) {
	t.id12(y)
	x := y.left
	y.left = x.right

	if !t.isNil(x.right) {
		x.right.parent = y
	}
	x.parent = y.parent

	if t.isNil(y.parent) {
		t.root = x
	} else if y.parent.right == y {
		y.parent.right = x
	} else {
		y.parent.left = x
	}
	x.right = y
	y.parent = x
}

func (t *id5) id12(y *id0) {
	if t.isNil(y.right) && t.isNil(y.left.right) {
		y.numRight = 0
		y.numLeft = 0
		y.left.numRight = 1
	} else if t.isNil(y.right) && !t.isNil(y.left.right) {
		y.numRight = 0
		y.numLeft = 1 + y.left.right.numRight + y.left.right.numLeft
		y.left.numRight = 2 + y.left.right.numRight + y.left.right.numLeft
	} else if !t.isNil(y.right) && t.isNil(y.left.right) {
		y.numLeft = 0
		y.left.numRight = 2 + y.right.numRight + y.right.numLeft
	} else {
		y.numLeft = 1 + y.left.right.numRight + y.left.right.numLeft
		y.left.numRight = 3 + y.right.numRight + y.right.numLeft + y.left.right.numRight + y.left.right.numLeft
	}
}

func (t *id5) insert(key interface{}) {
	t.insertNode(&id0{key: key})
}

func (t *id5) insertNode(z *id0) {
	y := t.nil
	x := t.root

	for !t.isNil(x) {
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

	if t.isNil(y) {
		t.root = z
	} else if z.key.(int) < y.key.(int) {
		y.left = z
	} else {
		y.right = z
	}

	z.left = t.nil
	z.right = t.nil
	z.color = RED

	t.id8(z)
}

func (t *id5) id8(z *id0) {
	y := t.nil

	for z.parent.color == RED {
		if z.parent == z.parent.left {
			y = z.parent.parent.right
			if y.color == RED {
				z.parent.color = BLACK
				y.color = BLACK
				z.parent.parent.color = RED
				z = z.parent.parent
			} else if z == z.parent.right {
				z = z.parent
				t.leftRotate(z)
			} else {
				z.parent.color = BLACK
				z.parent.parent.color = RED
				t.rightRotate(z.parent.parent)
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
				t.rightRotate(z)
			} else {
				z.parent.color = BLACK
				z.parent.parent.color = RED
				t.leftRotate(z.parent.parent)
			}
		}
	}
	t.root.color = BLACK
}

func (t *id5) treeMinimum(node *id0) *id0 {
	for !t.isNil(node.left) {
		node = node.left
	}
	return node
}

func (t *id5) id1(x *id0) *id0 {
	if !t.isNil(x.left) {
		return t.treeMinimum(x.right)
	}

	y := x.parent
	for !t.isNil(y) && x == y.right {
		x = y
		y = y.parent
	}
	return y
}

func (t *id5) remove(v *id0) {
	z := t.search(v.key)
	x := t.nil
	y := t.nil

	if t.isNil(z.left) || t.isNil(z.right) {
		y = z
	} else {
		y = t.id1(z)
	}

	if !t.isNil(y.left) {
		x = y.left
	} else {
		x = y.right
	}

	x.parent = y.parent

	if t.isNil(y.parent) {
		t.root = x
	} else if !t.isNil(y.parent.left) && y.parent.left == y {
		y.parent.left = x
	} else if !t.isNil(y.parent.right) && y.parent.right == y {
		y.parent.right = x
	}

	if y != z {
		z.key = y.key
	}

	t.id2(x, y)

	if y.color == BLACK {
		t.id11(x)
	}
}

func (t *id5) id2(x, y *id0) {
	current := t.nil
	track := t.nil

	if t.isNil(x) {
		current = y.parent
		track = y
	} else {
		current = x.parent
		track = x
	}

	for !t.isNil(current) {
		if y.key != current.key {
			if y.key.(int) > current.key.(int) {
				current.numRight--
			}
			if y.key.(int) < current.key.(int) {
				current.numLeft--
			}
		} else {
			if t.isNil(current.left) {
				current.numLeft--
			} else if t.isNil(current.right) {
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

func (t *id5) id11(x *id0) {
	var w *id0

	for x != t.root && x.color == BLACK {
		if x == x.parent.left {
			w = x.parent.right
			if w.color == RED {
				w.color = BLACK
				x.parent.color = RED
				t.leftRotate(x.parent)
				w = x.parent.right
			}
			if w.left.color == BLACK && w.right.color == BLACK {
				w.color = RED
				x = x.parent
			} else {
				if w.right.color == BLACK {
					w.left.color = BLACK
					w.color = RED
					t.rightRotate(w)
					w = x.parent.right
				}
				w.color = x.parent.color
				x.parent.color = BLACK
				w.right.color = BLACK
				t.leftRotate(x.parent)
				x = t.root
			}
		} else {
			w = x.parent.left
			if w.color == RED {
				w.color = BLACK
				x.parent.color = RED
				t.rightRotate(x.parent)
				w = x.parent.left
			}
			if w.right.color == BLACK && w.left.color == BLACK {
				w.color = RED
				x = x.parent
			} else {
				if w.left.color == BLACK {
					w.right.color = BLACK
					w.color = RED
					t.leftRotate(w)
					w = x.parent.left
				}
				w.color = x.parent.color
				x.parent.color = BLACK
				w.left.color = BLACK
				t.rightRotate(x.parent)
				x = t.root
			}
		}
	}
	x.color = BLACK
}

func (t *id5) search(key interface{}) *id0 {
	current := t.root

	for !t.isNil(current) {
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

func (t *id5) numGreater(key interface{}) int {
	return t.id4(t.root, key)
}

func (t *id5) id16(key interface{}) int {
	return t.id15(t.root, key)
}

func (t *id5) id4(node *id0, key interface{}) int {
	if t.isNil(node) {
		return 0
	} else if key.(int) < node.key.(int) {
		return 1 + node.numRight + t.id4(node.left, key)
	} else {
		return t.id4(node.right, key)
	}
}

func (t *id5) id14(key interface{}, maxReturned int) []interface{} {
	list := []interface{}{}
	t.id14Helper(t.root, key, &list)
	if len(list) > maxReturned {
		return list[:maxReturned]
	}
	return list
}

func (t *id5) id14Helper(node *id0, key interface{}, list *[]interface{}) {
	if t.isNil(node) {
		return
	} else if node.key.(int) > key.(int) {
		t.id14Helper(node.left, key, list)
		*list = append(*list, node.key)
		t.id14Helper(node.right, key, list)
	} else {
		t.id14Helper(node.right, key, list)
	}
}

func (t *id5) id15(node *id0, key interface{}) int {
	if t.isNil(node) {
		return 0
	} else if key.(int) <= node.key.(int) {
		return t.id15(node.left, key)
	} else {
		return 1 + node.numLeft + t.id15(node.right, key)
	}
}

func (t *id5) isNil(node *id0) bool {
	return node == t.nil
}

func (t *id5) size() int {
	return t.root.numLeft + t.root.numRight + 1
}
