package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"sort"
)

type item struct {
	key   pair
	prior int
	cnt   int
	l, r  *item
}

type pair struct {
	first, second int
}

func less(a, b pair) bool {
	return int64(a.first)*int64(b.second) < int64(a.second)*int64(b.first)
}

func greater(a, b pair) bool {
	return int64(a.first)*int64(b.second) > int64(a.second)*int64(b.first)
}

func equal(a, b pair) bool {
	return int64(a.first)*int64(b.second) == int64(a.second)*int64(b.first)
}

func upd(t *item) {
	if t == nil {
		return
	}
	t.cnt = count(t.l) + count(t.r) + 1
}

func count(t *item) int {
	if t == nil {
		return 0
	}
	return t.cnt
}

func split(t *item, key pair) (l, r *item) {
	if t == nil {
		return nil, nil
	}
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

func wsplit(t *item, key pair) (l, r *item) {
	if t == nil {
		return nil, nil
	}
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
		l, r := split(*t, it.key)
		it.l = l
		it.r = r
		*t = it
	} else {
		insert(&(*t).l, it)
	}
	upd(*t)
}

func merge(t **item, l, r *item) {
	if l == nil {
		*t = r
	} else if r == nil {
		*t = l
	} else if l.prior > r.prior {
		l.r = merge(&l.r, l.r, r)
		*t = l
	} else {
		r.l = merge(&r.l, l, r.l)
		*t = r
	}
	upd(*t)
}

func erase(t **item, key pair) {
	if (*t).key == key {
		merge(t, (*t).l, (*t).r)
	} else {
		if less(key, (*t).key) {
			erase(&(*t).l, key)
		} else {
			erase(&(*t).r, key)
		}
	}
	upd(*t)
}

func ans(a []pair) int64 {
	var t *item
	var ans int64
	for _, i := range a {
		var l, r *item
		l, r = wsplit(t, i.second)
		ans += int64(count(r))
		merge(&t, l, r)
		insert(&t, &item{i.second, rand.Int(), 1, nil, nil})
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Text())
	scanner.Scan()
	w := parseInt(scanner.Text())

	b := make([]pair, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a := parseInt(scanner.Text())
		scanner.Scan()
		v := parseInt(scanner.Text())
		b[i] = pair{abs(a), abs(v - w)}
	}

	sort.Slice(b, func(i, j int) bool {
		return less(b[i].first, b[j].first) || (equal(b[i].first, b[j].first) && greater(b[i].second, b[j].second))
	})

	fmt.Println(ans(b))
}

func parseInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
