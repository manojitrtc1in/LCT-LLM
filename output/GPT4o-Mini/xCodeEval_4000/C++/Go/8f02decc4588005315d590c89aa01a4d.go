package main

import (
	"fmt"
	"sort"
)

const MOD = 1e9 + 7

var cou = make(map[int]int)
var sum, n int
var board [4][4]int

func goFunc(num, i, j int)
func backtrack(i, j int) {
	if i == 3 && j == 0 {
		for x := 0; x < n; x++ {
			for y := 0; y < n; y++ {
				if y == n-1 {
					fmt.Printf("%2d\n", board[x][y])
				} else {
					fmt.Printf("%2d ", board[x][y])
				}
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
		for x, count := range cou {
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
	it, exists := cou[num]
	if !exists || it == 0 {
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
			if it, exists = cou[under]; !exists || it == 0 {
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
					if i%n == n-1 {
						fmt.Printf("%d\n", nums[i])
					} else {
						fmt.Printf("%d ", nums[i])
					}
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
