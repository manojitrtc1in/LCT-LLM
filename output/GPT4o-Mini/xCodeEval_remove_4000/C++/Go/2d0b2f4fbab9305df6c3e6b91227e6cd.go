package main

import (
    "fmt"
    "math"
    "sort"
)

type Tuple struct {
    First, Second, Third int
}

type Heap struct {
    data []int
    comp func(i, j int) bool
}

func NewHeap(comp func(i, j int) bool) *Heap {
    return &Heap{comp: comp}
}

func (h *Heap) Push(x int) {
    h.data = append(h.data, x)
    h.up(len(h.data) - 1)
}

func (h *Heap) Pop() int {
    n := len(h.data) - 1
    h.swap(0, n)
    h.down(0, n)
    x := h.data[n]
    h.data = h.data[:n]
    return x
}

func (h *Heap) Len() int {
    return len(h.data)
}

func (h *Heap) Less(i, j int) bool {
    return h.comp(h.data[i], h.data[j])
}

func (h *Heap) Swap(i, j int) {
    h.data[i], h.data[j] = h.data[j], h.data[i]
}

func (h *Heap) up(i int) {
    for i > 0 {
        p := (i - 1) / 2
        if h.Less(p, i) {
            h.Swap(p, i)
            i = p
        } else {
            break
        }
    }
}

func (h *Heap) down(i, n int) {
    for {
        left := 2*i + 1
        right := 2*i + 2
        largest := i
        if left < n && h.Less(largest, left) {
            largest = left
        }
        if right < n && h.Less(largest, right) {
            largest = right
        }
        if largest == i {
            break
        }
        h.Swap(i, largest)
        i = largest
    }
}

func refill(k int, left, right []Tuple) int {
    comp := func(i, j int) bool {
        return right[i].Second-left[i].First < right[j].Second-left[j].First
    }

    idx := make([]int, len(left))
    for i := range idx {
        idx[i] = i
    }

    heap := NewHeap(comp)
    for _, i := range idx {
        heap.Push(i)
    }

    val := 0
    for heap.Len() > 0 && k > 0 {
        i := heap.Pop()
        if left[i].First < right[i].Second {
            w := int(math.Min(float64(k), float64(left[i].Third)))
            k -= w
            val += w * (right[i].Second - left[i].First)
        }
    }
    return val
}

func a176() int {
    var n, m, k int
    fmt.Scan(&n, &m, &k)

    a := make([][]Tuple, n)
    for i := 0; i < n; i++ {
        var str string
        fmt.Scan(&str)
        for j := 0; j < m; j++ {
            var t Tuple
            fmt.Scan(&t.First, &t.Second, &t.Third)
            a[i] = append(a[i], t)
        }
    }

    val := 0
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if i != j {
                val = int(math.Max(float64(val), float64(refill(k, a[i], a[j]))))
            }
        }
    }
    return val
}

func main() {
    fmt.Println(a176())
}
