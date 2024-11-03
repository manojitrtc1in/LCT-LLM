package main

import (
	"fmt"
)

const p_N = 1500000

var huiwen [2500]int
var flag [p_N + 5]bool
var prime [p_N + 5]int
var pk = 0

func get_p() {
	for i := 2; i < p_N; i++ {
		if !flag[i] {
			prime[pk] = i
			pk++
		}
		for j := 0; i*prime[j] < p_N; j++ {
			flag[i*prime[j]] = true
			if i%prime[j] == 0 {
				break
			}
		}
	}
}

func main() {
	get_p()
	var p, q float64
	fmt.Scan(&p, &q)
	var ans, t1, t2 int
	for i := 1; i < 1498941; i++ {
		if i >= prime[t1] {
			t1++
		}
		if i >= huiwen[t2] {
			t2++
		}
		if t1 <= (t2)*(p/q) {
			ans = i
		}
	}
	fmt.Println(ans)
}
