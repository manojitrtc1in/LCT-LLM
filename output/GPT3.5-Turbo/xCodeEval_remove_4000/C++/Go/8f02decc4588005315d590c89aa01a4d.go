package main

import (
	"fmt"
	"sort"
)

var (
	cou  map[int]int
	sum  int
	n    int
	board [4][4]int
)

func backtrack(i, j int) {
	if i == 3 && j == 0 {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				fmt.Printf("%2d%c", board[i][j], map[bool]byte{true: '\n', false: ' '}[j == n-1])
			}
		}
		return
	}
	if j == 3 {
		s := sum
		for x := 0; x < 3; x++ {
			s -= board[i][x]
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
		goFunc(board[0][0]+board[1][0]+board[2][0]-board[1][2]-board[0][3], i, j)
		return
	}
	if i == 2 && j == 2 {
		o := board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1]
		if o%2 == 0 {
			goFunc(o/2, i, j)
		}
		return
	}
	if i == 1 && j == 0 {
		for x := range cou {
			if x > board[0][1] {
				break
			}
			goFunc(x, i, j)
		}
		return
	}
	for x := range cou {
		goFunc(x, i, j)
	}
}

func goFunc(num, i, j int) {
	it, ok := cou[num]
	if !ok || it == 0 {
		return
	}
	under := -1
	if i == 2 {
		under = sum - board[0][j] - board[1][j] - num
		if under == num {
			if it < 2 {
				return
			}
			cou[num]--
		} else {
			it, ok := cou[under]
			if !ok || it == 0 {
				return
			}
			cou[under]--
		}
		board[3][j] = under
	}
	cou[num]--
	board[i][j] = num
	if j == 3 {
		backtrack(i+1, 0)
	} else {
		backtrack(i, j+1)
	}
	cou[num]++
	if i == 2 {
		cou[under]++
	}
}

func main() {
	fmt.Scan(&n)
	nums := make([]int, n*n)
	cou = make(map[int]int)
	for i := 0; i < n*n; i++ {
		fmt.Scan(&nums[i])
		cou[nums[i]]++
		sum += nums[i]
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
					fmt.Printf("%d%c", nums[i], map[bool]byte{true: '\n', false: ' '}[i%n == n-1])
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
	i := n - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		return false
	}
	j := n - 1
	for j > i && nums[j] <= nums[i] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	reverse(nums[i+1:])
	return true
}

func reverse(nums []int) {
	n := len(nums)
	for i := 0; i < n/2; i++ {
		nums[i], nums[n-i-1] = nums[n-i-1], nums[i]
	}
}
