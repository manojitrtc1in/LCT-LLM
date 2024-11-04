package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	priority    int
	value       int
	id          int
	originalId  int
	upd         int
	left, right *Node
}

func push(it *Node) {
	if it != nil && it.upd != 0 {
		it.value += it.upd
		if it.left != nil {
			it.left.upd += it.upd
		}
		if it.right != nil {
			it.right.upd += it.upd
		}
		it.upd = 0
	}
}

func merge(t **Node, l, r *Node) {
	push(l)
	push(r)
	if l == nil || r == nil {
		if l != nil {
			*t = l
		} else {
			*t = r
		}
	} else if l.priority > r.priority {
		merge(&l.right, l.right, r)
		*t = l
	} else {
		merge(&r.left, l, r.left)
		*t = r
	}
}

func split(t *Node, key int, l, r **Node) {
	if t == nil {
		*l, *r = nil, nil
		return
	}
	push(t)
	if key < t.value {
		split(t.left, key, l, &t.left)
		*r = t
	} else {
		split(t.right, key, &t.right, r)
		*l = t
	}
}

func newNode(value, id int) *Node {
	p := &Node{}
	p.priority = rnd.Intn(1000000000)
	p.value = value
	p.originalId = id
	p.id = -1
	return p
}

var root *Node
var countNodes int

func solve(scanner *bufio.Scanner, writer *bufio.Writer) {
	scanner.Split(bufio.ScanWords)
	n := nextInt(scanner)
	m := nextInt(scanner)
	root = nil

	for i := 0; i < n; i++ {
		t := newNode(i, i)
		merge(&root, root, t)
	}
	leftIds := make(map[int]bool)
	for i := 0; i < n; i++ {
		leftIds[i] = true
	}

	for i := 0; i < m; i++ {
		id := nextInt(scanner) - 1
		pos := nextInt(scanner) - 1

		var t1, t2, t3 *Node
		split(root, pos-1, &t1, &t2)
		split(t2, pos, &t2, &t3)

		if t2.id != -1 {
			if t2.id != id {
				fmt.Fprintln(writer, "-1")
				return
			}
		} else {
			if !leftIds[id] {
				fmt.Fprintln(writer, "-1")
				return
			}
			delete(leftIds, id)
			t2.id = id
		}
		t2.value = 0
		t2.upd = 0
		if t1 != nil {
			t1.upd++
		}
		merge(&root, t2, t1)
		merge(&root, root, t3)
	}

	p := make([]int, n)
	for i := 0; i < n; i++ {
		var t1 *Node
		split(root, i, &t1, &root)
		if t1.id != -1 {
			p[t1.originalId] = t1.id
		}
	}

	for i := 0; i < n; i++ {
		if p[i] == -1 {
			for id := range leftIds {
				p[i] = id
				delete(leftIds, id)
				break
			}
		}
	}

	for i := 0; i < n; i++ {
		fmt.Fprint(writer, p[i]+1, " ")
	}
	fmt.Fprintln(writer)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve(scanner, writer)
}

var rnd = NewRandom()

type Random struct {
}

func NewRandom() *Random {
	return &Random{}
}

func (r *Random) getInt(upTo int) int {
	return rnd.Intn(upTo)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}
