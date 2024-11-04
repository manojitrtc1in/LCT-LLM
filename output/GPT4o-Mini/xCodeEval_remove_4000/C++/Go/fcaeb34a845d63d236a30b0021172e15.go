package main

import (
	"fmt"
	"sort"
	"os"
)

const MOD = 1e9 + 7

var cou = make(map[int]int)
var sum, n int
var board [4][4]int

func goFunc(num, i, j int) {
	if count, exists := cou[num]; exists && count > 0 {
		cou[num]--
		board[i][j] = num
		if j == 3 {
			backtrack(i + 1, 0)
		} else {
			backtrack(i, j + 1)
		}
		cou[num]++
	}
}

func backtrack(i, j int) {
	if i == n && j == 0 {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				fmt.Printf("%2d%c", board[i][j], " \n"[j == n-1])
			}
		}
		os.Exit(0)
	}
	if j == 3 {
		s := sum
		for x := 0; x < 3; x++ {
			s -= board[i][x]
		}
		if i == 0 && s < board[0][0] {
			return
		}
		goFunc(s, i, j)
		return
	}
	if i == 3 {
		s := sum
		for x := 0; x < 3; x++ {
			s -= board[x][j]
		}
		goFunc(s, i, j)
		return
	}
	if i == 2 && j == 1 {
		v := board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3]
		if v >= board[0][0] {
			goFunc(v, i, j)
		}
		return
	}
	if i == 2 && j == 2 {
		o := board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1]
		if o%2 == 0 && o/2 >= board[0][0] {
			goFunc(o/2, i, j)
		}
		return
	}
	limit := -1e9
	if (i == 0 && j == 2) || ((i == 1 || i == 2) && (j == 0)) {
		limit = board[0][1]
	} else if (i == j || i+j == 3) && (i > 0 || j > 0) {
		limit = board[0][0]
	}
	for x, count := range cou {
		if x >= limit {
			goFunc(x, i, j)
		}
	}
}

func main() {
	fmt.Scan(&n)
	nums := make([]int, n*n)
	for i := 0; i < n*n; i++ {
		var x int
		fmt.Scan(&x)
		cou[x]++
		sum += x
		nums[i] = x
	}
	if sum%n != 0 {
		return
	}
	sum /= n
	fmt.Println(sum)
	if n <= 3 {
		sort.Ints(nums)
		for {
			good := true
			for i := 0; i < n; i++ {
				s1, s2 := 0, 0
				for j := 0; j < n; j++ {
					s1 += nums[i*n+j]
					s2 += nums[j*n+i]
				}
				if s1 != sum || s2 != sum {
					good = false
				}
			}
			s1, s2 := 0, 0
			for i := 0; i < n; i++ {
				s1 += nums[i*n+i]
				s2 += nums[i*n+n-i-1]
			}
			if s1 != sum || s2 != sum {
				good = false
			}
			if good {
				for i := 0; i < n*n; i++ {
					fmt.Printf("%d%c", nums[i], " \n"[i%n == n-1])
				}
				return
			}
			if !nextPermutation(nums) {
				break
			}
		}
	}
	backtrack(0, 0)
}

func nextPermutation(nums []int) bool {
	n := len(nums)
	i := n - 1
	for i > 0 && nums[i-1] >= nums[i] {
		i--
	}
	if i <= 0 {
		return false
	}
	j := n - 1
	for nums[j] <= nums[i-1] {
		j--
	}
	nums[i-1], nums[j] = nums[j], nums[i-1]
	reverse(nums[i:])
	return true
}

func reverse(nums []int) {
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
}
