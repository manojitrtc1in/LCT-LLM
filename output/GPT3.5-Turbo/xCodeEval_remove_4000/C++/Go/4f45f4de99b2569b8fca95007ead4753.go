package main

import (
	"fmt"
)

const inf = 0x3f3f3f3f

type id13 struct {
	foo map[int]int
}

func newId13() *id13 {
	return &id13{
		foo: make(map[int]int),
	}
}

func (id *id13) put(key, val int) {
	if val == 0 {
		return
	}
	if v, ok := id.foo[key]; ok {
		id.foo[key] = v + val
	} else {
		id.foo[key] = val
	}
}

func (id *id13) pop(key, val int) int {
	res := 0
	if v, ok := id.foo[key]; ok {
		if v > val {
			res = val
			id.foo[key] = v - val
		} else {
			res = v
			delete(id.foo, key)
		}
	}
	return res
}

func process(from int, seq, sup []int) int {
	if from+from < seq[0] {
		return 1
	}
	open := newId13()
	close := newId13()
	open.put(0, from-(seq[0]-from))
	close.put(0, seq[0]-from)
	for i := 1; i < 45; i++ {
		ext := open.pop(i-1, seq[i])
		seq[i] -= ext
		open.put(i, ext)
		ext = close.pop(i-1, seq[i])
		sup[i] += seq[i] - ext
		close.put(i, ext)
		cls := open.pop(i, sup[i])
		sup[i+1] += sup[i] - cls
		close.put(i, cls)
	}
	if sup[45] != 0 {
		return 1
	}
	return 0
}

func find(lef, rig int, seq, sup []int) int {
	for lef <= rig {
		mid := (lef + rig) >> 1
		if process(mid, seq, sup) == 0 {
			if mid == lef || process(mid-1, seq, sup) == 1 {
				return mid
			}
			rig = mid - 1
		} else {
			lef = mid + 1
		}
	}
	return -1
}

func main() {
	var n int
	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}
		a := make([]int64, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		seq := make([]int, 50)
		sup := make([]int, 50)
		for i := 0; i < 50; i++ {
			seq[i] = 0
			sup[i] = 0
		}
		cur := 0
		for i := 0; i < n; i++ {
			for a[i] >= (1 << (cur + 1)) {
				cur++
			}
			if a[i] == (1 << cur) {
				seq[cur]++
			} else {
				sup[cur]++
			}
		}
		if process(seq[0], seq, sup) == 1 {
			fmt.Println("-1")
		} else {
			hig := seq[0]
			low := find(1, hig, seq, sup)
			for i := low; i <= hig; i++ {
				if i != low {
					fmt.Print(" ")
				}
				fmt.Print(i)
			}
			fmt.Println()
		}
	}
}
