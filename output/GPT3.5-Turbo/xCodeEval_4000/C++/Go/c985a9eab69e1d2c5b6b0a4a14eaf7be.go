package main

import (
	"fmt"
	"math/rand"
)

type item struct {
	key   [2]int
	prior int
	cnt   int
	l, r  *item
}

func less(a, b [2]int) bool {
	return int64(a[0])*int64(b[1]) < int64(a[1])*int64(b[0])
}

func equal(a, b [2]int) bool {
	return int64(a[0])*int64(b[1]) == int64(a[1])*int64(b[0])
}

func split(t *item, key [2]int) (*item, *item) {
	if t == nil {
		return nil, nil
	}
	var l, r *item
	if less(key, t.key) || (equal(key, t.key) && rand.Intn(2) == 0) {
		l, t.l = split(t.l, key)
		r = t
	} else {
		t.r, r = split(t.r, key)
		l = t
	}
	upd(l)
	upd(r)
	return l, r
}

func wsplit(t *item, key [2]int) (*item, *item) {
	if t == nil {
		return nil, nil
	}
	var l, r *item
	if less(key, t.key) || equal(key, t.key) {
		l, t.l = wsplit(t.l, key)
		r = t
	} else {
		t.r, r = wsplit(t.r, key)
		l = t
	}
	upd(l)
	upd(r)
	return l, r
}

func insert(t **item, it *item) {
	if *t == nil {
		*t = it
	} else if it.prior > (*t).prior {
		lt, rt := split(*t, it.key)
		it.l = lt
		it.r = rt
		*t = it
	} else {
		insert(&((*t).l), it)
	}
	upd(*t)
}

func merge(t **item, l, r *item) {
	if l == nil || r == nil {
		if l != nil {
			*t = l
		} else {
			*t = r
		}
	} else if l.prior > r.prior {
		merge(&(l.r), l.r, r)
		*t = l
	} else {
		merge(&(r.l), l, r.l)
		*t = r
	}
	upd(*t)
}

func erase(t **item, key [2]int) {
	if (*t).key == key {
		merge(t, (*t).l, (*t).r)
	} else {
		if less(key, (*t).key) {
			erase(&((*t).l), key)
		} else {
			erase(&((*t).r), key)
		}
	}
	upd(*t)
}

func upd(t *item) {
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

func ans(a [][][]int) int64 {
	var t *item
	var ans int64
	for _, i := range a {
		l, r := wsplit(t, i[1])
		ans += int64(count(r))
		merge(&t, l, r)
		insert(&t, &item{i[1], rand.Int(), 1, nil, nil})
	}
	return ans
}

func count(t *item) int {
	if t == nil {
		return 0
	}
	return t.cnt
}

func main() {
	var n, w int
	fmt.Scan(&n, &w)
	b := make([][][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([][]int, 2)
		b[i][0] = make([]int, 2)
		b[i][1] = make([]int, 2)
		fmt.Scan(&b[i][0][0], &b[i][0][1])
		b[i][1][0] = abs(b[i][0][0])
		b[i][1][1] = abs(b[i][0][1] - w)
		b[i][0][0] = abs(b[i][0][0])
		b[i][0][1] = abs(b[i][0][1] + w)
	}
	for i := 0; i < n; i++ {
		if b[i][0][0] > b[i][0][1] {
			b[i][0][0], b[i][0][1] = b[i][0][1], b[i][0][0]
		}
		if b[i][1][0] > b[i][1][1] {
			b[i][1][0], b[i][1][1] = b[i][1][1], b[i][1][0]
		}
	}
	fmt.Println(ans(b))
}
