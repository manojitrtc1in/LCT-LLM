package main

import (
	"fmt"
	"math/rand"
	"sort"
)

type Item struct {
	key   [2]int
	prior int
	cnt   int
	l, r  *Item
}

func NewItem(key [2]int) *Item {
	return &Item{key: key, prior: rand.Int(), cnt: 1, l: nil, r: nil}
}

func (t *Item) Update() {
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

func Split(t *Item, key [2]int) (*Item, *Item) {
	if t == nil {
		return nil, nil
	}
	if less(key, t.key) || (equal(key, t.key) && rand.Int()%2 == 0) {
		l, r := Split(t.l, key)
		t.l = r
		t.Update()
		return l, t
	}
	l, r := Split(t.r, key)
	t.r = l
	t.Update()
	return t, r
}

func WSplit(t *Item, key [2]int) (*Item, *Item) {
	if t == nil {
		return nil, nil
	}
	if less(key, t.key) || equal(key, t.key) {
		l, r := WSplit(t.l, key)
		t.l = r
		t.Update()
		return l, t
	}
	l, r := WSplit(t.r, key)
	t.r = l
	t.Update()
	return t, r
}

func Insert(t **Item, it *Item) {
	if *t == nil {
		*t = it
	} else if it.prior > (*t).prior {
		l, r := Split(*t, it.key)
		*t = it
		(*t).l = l
		(*t).r = r
	} else {
		if less(it.key, (*t).key) || (equal(it.key, (*t).key) && rand.Int()%2 == 0) {
			Insert(&(*t).l, it)
		} else {
			Insert(&(*t).r, it)
		}
	}
	(*t).Update()
}

func Merge(t **Item, l, r *Item) {
	if l == nil || r == nil {
		*t = l
		if l == nil {
			*t = r
		}
		return
	}
	if l.prior > r.prior {
		Merge(&l.r, l.r, r)
		*t = l
	} else {
		Merge(&r.l, l, r.l)
		*t = r
	}
	(*t).Update()
}

func Erase(t **Item, key [2]int) {
	if (*t).key == key {
		Merge(t, (*t).l, (*t).r)
	} else {
		if less(key, (*t).key) {
			Erase(&(*t).l, key)
		} else {
			Erase(&(*t).r, key)
		}
	}
	if *t != nil {
		(*t).Update()
	}
}

func less(a, b [2]int) bool {
	return int64(a[0])*int64(b[1]) < int64(a[1])*int64(b[0])
}

func equal(a, b [2]int) bool {
	return int64(a[0])*int64(b[1]) == int64(a[1])*int64(b[0])
}

func Ans(a [][2][2]int) int64 {
	var t *Item
	var ans int64
	for _, i := range a {
		l, r := WSplit(t, i[1])
		if r != nil {
			ans += int64(r.cnt)
		}
		Merge(&t, l, r)
		Insert(&t, NewItem(i[1]))
	}
	return ans
}

func main() {
	var n, w int
	fmt.Scan(&n, &w)
	b := make([][2][2]int, n)
	for i := 0; i < n; i++ {
		var a, v int
		fmt.Scan(&a, &v)
		b[i] = [2][2]int{{abs(a), abs(v - w)}, {abs(a), abs(v + w)}}
	}
	sort.Slice(b, func(i, j int) bool {
		if b[i][0] != b[j][0] {
			return b[i][0] < b[j][0]
		}
		return b[i][1] > b[j][1]
	})
	fmt.Println(Ans(b))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
