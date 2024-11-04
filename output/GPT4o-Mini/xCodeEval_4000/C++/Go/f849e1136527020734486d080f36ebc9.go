package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Node struct {
	v   int
	pos int
}

type SplayTree struct {
	root *Node
}

func (st *SplayTree) Insert(node *Node) {
	// Insert logic for splay tree
}

func (st *SplayTree) Erase(node *Node) {
	// Erase logic for splay tree
}

func (st *SplayTree) Size() int {
	// Return size of the splay tree
	return 0
}

func (st *SplayTree) Begin() *Node {
	// Return the first node in the splay tree
	return nil
}

func (st *SplayTree) FindNth(k int) *Node {
	// Find the k-th node in the splay tree
	return nil
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	arr := make([]Node, n)
	splay := SplayTree{}
	ans := int64(0)
	lastLeft, lastRight := 0, 0

	for i := 0; i < n; i++ {
		var v int
		fmt.Fscan(reader, &v)
		arr[i] = Node{v: v, pos: i}
	}

	for i := 0; i < n; i++ {
		splay.Insert(&arr[i])
	}

	for splay.Size() > 0 {
		it := splay.Begin()
		left := it.pos - 1
		right := it.pos + 1

		splay.Erase(it)

		if it.pos == left && it.pos == right {
			ans += int64(min(lastLeft, lastRight))
		} else if it.pos == left {
			ans += int64(lastLeft)
			lastLeft = it.v
		} else if it.pos == right {
			ans += int64(lastRight)
			lastRight = it.v
		} else {
			ans += int64(min(arr[left].v, arr[right].v))
		}
	}

	fmt.Fprintln(writer, ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
