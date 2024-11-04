package main

import (
	"container/heap"
	"fmt"
	"math/rand"
	"time"
)

type Node struct {
	priority    int
	value       int
	id          int
	originalId  int
	upd         int
	left, right *Node
}

type Treap struct {
	root *Node
}

func (t *Treap) push(it *Node) {
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

func (t *Treap) merge(l, r *Node) *Node {
	t.push(l)
	t.push(r)
	if l == nil || r == nil {
		if l != nil {
			return l
		}
		return r
	}
	if l.priority > r.priority {
		l.right = t.merge(l.right, r)
		return l
	}
	r.left = t.merge(l, r.left)
	return r
}

func (t *Treap) split(node *Node, key int) (*Node, *Node) {
	if node == nil {
		return nil, nil
	}
	t.push(node)
	if key < node.value {
		left, right := t.split(node.left, key)
		node.left = right
		return left, node
	}
	left, right := t.split(node.right, key)
	node.right = left
	return node, right
}

type Random struct {
	rng *rand.Rand
}

func NewRandom(seed int64) *Random {
	return &Random{rng: rand.New(rand.NewSource(seed))}
}

func (r *Random) GetInt(upTo int) int {
	return r.rng.Intn(upTo)
}

var rnd = NewRandom(time.Now().UnixNano())

func newNode(value, id int) *Node {
	return &Node{
		priority:   rnd.GetInt(1000000000),
		value:      value,
		originalId: id,
		id:         -1,
	}
}

func solve(n, m int, operations [][]int) []int {
	root := &Treap{}
	leftIds := make(map[int]struct{})
	for i := 0; i < n; i++ {
		leftIds[i] = struct{}{}
		node := newNode(i, i)
		root.root = root.merge(root.root, node)
	}

	p := make([]int, n)
	for _, op := range operations {
		id := op[0] - 1
		pos := op[1] - 1

		t1, t2 := root.split(root.root, pos)
		t2, t3 := root.split(t2, pos+1)

		if t2 != nil && t2.id != -1 {
			if t2.id != id {
				return []int{-1}
			}
		} else {
			if _, exists := leftIds[id]; !exists {
				return []int{-1}
			}
			delete(leftIds, id)
			t2.id = id
		}
		t2.value = 0
		t2.upd = 0
		if t1 != nil {
			t1.upd++
		}
		root.root = root.merge(root.merge(t2, t1), t3)
	}

	for i := 0; i < n; i++ {
		t1, root.root := root.split(root.root, i)
		if t1 != nil && t1.id != -1 {
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

	return p
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	operations := make([][]int, m)
	for i := 0; i < m; i++ {
		var id, pos int
		fmt.Scan(&id, &pos)
		operations[i] = []int{id, pos}
	}

	result := solve(n, m, operations)
	for _, val := range result {
		fmt.Print(val + 1, " ")
	}
	fmt.Println()
}
