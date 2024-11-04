package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

type Node struct {
	priority    int
	value       int
	id          int
	originalId  int
	upd         int
	l, r        *Node
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

var rnd = NewRandom(3731)

func push(it *Node) {
	if it != nil && it.upd != 0 {
		it.value += it.upd
		if it.l != nil {
			it.l.upd += it.upd
		}
		if it.r != nil {
			it.r.upd += it.upd
		}
		it.upd = 0
	}
}

func merge(t **Node, l, r *Node) {
	push(l)
	push(r)
	if l == nil || r == nil {
		*t = l
		if l == nil {
			*t = r
		}
	} else if l.priority > r.priority {
		merge(&l.r, l.r, r)
		*t = l
	} else {
		merge(&r.l, l, r.l)
		*t = r
	}
}

func split(t *Node, key int, l, r **Node) {
	if t == nil {
		*l = nil
		*r = nil
		return
	}
	push(t)
	if key < t.value {
		split(t.l, key, l, &t.l)
		*r = t
	} else {
		split(t.r, key, &t.r, r)
		*l = t
	}
}

var root *Node
const id5 = 2000000
var memo [id5]Node
var countNodes int
var p []int

func newNode(value, id int) *Node {
	p := &memo[countNodes]
	countNodes++
	p.priority = rnd.GetInt(1000000000)
	p.value = value
	p.originalId = id
	p.id = -1
	return p
}

func solve(in *fmt.Scanner, out *fmt.Writer) {
	var n, m int
	in.Scan(&n)
	in.Scan(&m)
	root = nil

	for i := 0; i < n; i++ {
		t := newNode(i, i)
		merge(&root, root, t)
	}
	leftIds := make(map[int]struct{})
	for i := 0; i < n; i++ {
		leftIds[i] = struct{}{}
	}

	for i := 0; i < m; i++ {
		var id, pos int
		in.Scan(&id)
		in.Scan(&pos)
		id--
		pos--

		var t1, t2, t3 *Node
		split(root, pos-1, &t1, &t2)
		split(t2, pos, &t2, &t3)

		if t2 != nil && t2.id != -1 {
			if t2.id != id {
				fmt.Fprintln(out, "-1")
				return
			}
		} else {
			if _, exists := leftIds[id]; !exists {
				fmt.Fprintln(out, "-1")
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

	p = make([]int, n)
	for i := 0; i < n; i++ {
		var t1 *Node
		split(root, i, &t1, &root)
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

	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", p[i]+1)
	}
	fmt.Fprintln(out)
}

func main() {
	in := fmt.NewScanner(os.Stdin)
	out := fmt.NewWriter(os.Stdout)
	solve(in, out)
}
