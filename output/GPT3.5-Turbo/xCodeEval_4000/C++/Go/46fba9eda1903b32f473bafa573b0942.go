package main

import (
	"bufio"
	"fmt"
	"os"
)

var MOD int64 = 1e9 + 7
var INF int64 = 1e18

type ii struct {
	first, second int
}

type iii struct {
	first  ii
	second int
}

type viii []iii
type vi []int
type vvi [][]int
type vii []ii
type vll []int64
type vvii []vii
type llll struct {
	first, second int64
}
type vllll []llll

type orderedSet struct {
	tree *tree
}

type tree struct {
	root *node
}

type node struct {
	key         int
	left, right *node
	count       int
}

func (t *tree) insert(key int) {
	if t.root == nil {
		t.root = &node{key: key, count: 1}
		return
	}

	curr := t.root
	for {
		curr.count++
		if key < curr.key {
			if curr.left == nil {
				curr.left = &node{key: key, count: 1}
				return
			}
			curr = curr.left
		} else if key > curr.key {
			if curr.right == nil {
				curr.right = &node{key: key, count: 1}
				return
			}
			curr = curr.right
		} else {
			return
		}
	}
}

func (t *tree) orderOfKey(key int) int {
	curr := t.root
	res := 0
	for curr != nil {
		if key < curr.key {
			curr = curr.left
		} else if key > curr.key {
			res += 1 + curr.count
			curr = curr.right
		} else {
			return res + curr.count
		}
	}
	return res
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func yes() {
	fmt.Println("Yes")
}

func no() {
	fmt.Println("No")
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	a := parseInt(scanner.Bytes())

	n := int64(1e17)
	n *= 18
	n %= a
	k := n

	for i := 0; i < 44; i++ {
		n = (n + k) % int64(a)
	}

	if n < 0 {
		n += int64(a)
	}
	c := int64(a) - n
	d := c + int64(1e18) - 1

	fmt.Println(c, d)
}

func parseInt(b []byte) int {
	n := 0
	for _, v := range b {
		n = n*10 + int(v-'0')
	}
	return n
}
