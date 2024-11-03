package main

import (
	"fmt"
)

func LIS(n int, a []int) int {
	b := []int{}
	b = append(b, a[0])
	for i := 1; i < n; i++ {
		if b[len(b)-1] < a[i] {
			b = append(b, a[i])
		} else {
			l := 0
			r := len(b)
			for l < r {
				m := (l + r) / 2
				if b[m] < a[i] {
