package main

import (
	"fmt"
	"math"
)

const MOD = 1000000007
const MODL = 1000000000000000003
const eps = 1e-8

type lld int64
type pii struct{ x, y int }

type Chest struct {
	foo map[int]int
}

func NewChest() *Chest {
	return &Chest{foo: make(map[int]int)}
}

func (c *Chest) Clear() {
	c.foo = make(map[int]int)
}

func (c *Chest) Put(key, val int) {
	if val == 0 {
		return
	}
	if _, exists := c.foo[key]; exists {
		c.foo[key] += val
	} else {
		c.foo[key] = val
	}
}

func (c *Chest) Pop(key, val int) int {
	res := 0
	if v, exists := c.foo[key]; exists {
		if v > val {
			res = val
			c.foo[key] -= val
		} else {
			res = v
			delete(c.foo, key)
		}
	}
	return res
}

var n int
var a [110000]lld
var _seq, _sup [50]int
var seq, sup [50]int

func process(from int) int {
	copy(seq[:], _seq[:])
	copy(sup[:], _sup[:])
	if from+from < seq[0] {
		return 1
	}
	open := NewChest()
	close := NewChest()
	open.Put(0, from-(seq[0]-from))
	close.Put(0, seq[0]-from)

	for i := 1; i < 45; i++ {
		ext := open.Pop(i-1, seq[i])
		seq[i] -= ext
		open.Put(i, ext)
		ext = close.Pop(i-1, seq[i])
		sup[i] += seq[i] - ext
		close.Put(i, ext)
		cls := open.Pop(i, sup[i])
		sup[i+1] += sup[i] - cls
		close.Put(i, cls)
	}
	if sup[45] != 0 {
		return 1
	}
	return 0
}

func find(lef, rig int) int {
	for lef <= rig {
		mid := (lef + rig) >> 1
		if process(mid) == 0 {
			if mid == lef || process(mid-1) != 0 {
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
	for {
		if _, err := fmt.Scan(&n); err != nil {
			break
		}
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		for i := 0; i < 50; i++ {
			_seq[i] = 0
			_sup[i] = 0
		}
		cur := 0
		for i := 0; i < n; i++ {
			for a[i] >= (1<<(cur+1)) {
				cur++
			}
			if a[i] == (1 << cur) {
				_seq[cur]++
			} else {
				_sup[cur]++
			}
		}
		if process(_seq[0]) != 0 {
			fmt.Println("-1")
		} else {
			hig := _seq[0]
			low := find(1, hig)
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
