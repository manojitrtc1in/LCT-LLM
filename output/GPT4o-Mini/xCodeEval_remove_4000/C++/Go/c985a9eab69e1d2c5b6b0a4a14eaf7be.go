package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"sort"
)

type Item struct {
	key   [2]int
	prior int
	cnt   int
	l, r  *Item
}

type PItem *Item

func newItem(key [2]int) PItem {
	return &Item{key: key, prior: rand.Int(), cnt: 1}
}

func (t *Item) update() {
	if t == nil {
		return
	}
	t.cnt = 1
	if t.l != nil {
		t.cnt += t.l.cnt
	}
	if t.r != nil {
		t.cnt += t.r.cnt
	}
}

func split(t PItem, key [2]int) (PItem, PItem) {
	if t == nil {
		return nil, nil
	}
	if key < t.key || (key == t.key && rand.Int()%2 == 0) {
		l, r := split(t.l, key)
		t.l = r
		t.update()
		return l, t
	}
	l, r := split(t.r, key)
	t.r = l
	t.update()
	return t, r
}

func wsplit(t PItem, key [2]int) (PItem, PItem) {
	if t == nil {
		return nil, nil
	}
	if key < t.key || key == t.key {
		l, r := wsplit(t.l, key)
		t.l = r
		t.update()
		return l, t
	}
	l, r := wsplit(t.r, key)
	t.r = l
	t.update()
	return t, r
}

func insert(t *PItem, it PItem) {
	if *t == nil {
		*t = it
	} else if it.prior > (*t).prior {
		l, r := split(*t, it.key)
		it.l = l
		it.r = r
		*t = it
	} else {
		if it.key < (*t).key || (it.key == (*t).key && rand.Int()%2 == 0) {
			insert(&(*t).l, it)
		} else {
			insert(&(*t).r, it)
		}
	}
	(*t).update()
}

func merge(t *PItem, l, r PItem) {
	if l == nil || r == nil {
		*t = l
		if r != nil {
			*t = r
		}
		return
	}
	if l.prior > r.prior {
		merge(&l.r, l.r, r)
		*t = l
	} else {
		merge(&r.l, l, r.l)
		*t = r
	}
	(*t).update()
}

func erase(t *PItem, key [2]int) {
	if (*t).key == key {
		merge(t, (*t).l, (*t).r)
	} else {
		if key < (*t).key {
			erase(&(*t).l, key)
		} else {
			erase(&(*t).r, key)
		}
	}
	if *t != nil {
		(*t).update()
	}
}

func ans(a [][2][2]int) int64 {
	var t PItem
	var total int64
	for _, i := range a {
		l, r := wsplit(t, i[1])
		if r != nil {
			total += int64(r.cnt)
		}
		merge(&t, l, r)
		insert(&t, newItem(i[1]))
	}
	return total
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, w int
	fmt.Fscan(reader, &n, &w)
	b := make([][2][2]int, n)
	for i := 0; i < n; i++ {
		var a, v int
		fmt.Fscan(reader, &a, &v)
		b[i] = [2][2]int{{abs(a), abs(v - w)}, {abs(a), abs(v + w)}}
	}
	sort.Slice(b, func(i, j int) bool {
		return b[i][0] < b[j][0] || (b[i][0] == b[j][0] && b[i][1] > b[j][1])
	})
	fmt.Fprintln(writer, ans(b))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
