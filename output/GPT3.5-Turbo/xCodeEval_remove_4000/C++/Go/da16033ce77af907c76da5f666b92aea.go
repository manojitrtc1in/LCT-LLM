package main

import (
	"fmt"
	"math"
	"sort"
)

type ll int64
type llu uint64
type lld float64

type ordered_set []int
type matrix [][]int

var pi = 2 * math.Acos(0.0)

var id1, test_case = 0, 1

var main_array [][]int
var dp_table [][]int

func function_name() {
	var array_number, operation_number int
	fmt.Scanf("%d %d", &array_number, &operation_number)

	id3 := make([][]int, operation_number)
	for i := 0; i < operation_number; i++ {
		id3[i] = make([]int, array_number)
	}

	main_array = make([][]int, array_number)
	for i := 0; i < array_number; i++ {
		main_array[i] = make([]int, operation_number)
	}

	maximum := 0
	dp_table = make([][]int, array_number)
	for i := 0; i < array_number; i++ {
		dp_table[i] = make([]int, operation_number+1)
		for j := 0; j <= operation_number; j++ {
			dp_table[i][j] = maximum
		}
	}

	for i := 0; i < array_number; i++ {
		var element_number int
		fmt.Scanf("%d", &element_number)
		for j := 0; j < element_number; j++ {
			var element int
			fmt.Scanf("%d", &element)
			if j < operation_number {
				main_array[i][j] = element + boolToInt(j > 0)*main_array[i][j-1]
				id3[j][i] = main_array[i][j]
			}
		}
	}

	for i := 0; i < operation_number; i++ {
		sort.Slice(id3[i], func(a, b int) bool {
			return id3[i][a] > id3[i][b]
		})
	}

	for i := 0; i < array_number; i++ {
		for j := 0; j < operation_number; j++ {
			if main_array[i][j] < id3[j][min(operation_number/(j+1), array_number-1)] {
				main_array[i][j] = 0
			}
		}
	}

	for id0 := 0; id0 < array_number; id0++ {
		if id0 > 0 {
			dp_table[id0] = dp_table[id0-1]
		}

		for id2 := 0; id2 < operation_number; id2++ {
			if main_array[id0][id2] != 0 {
				for operation_left, old := operation_number, operation_number-(id2+1); operation_left > id2; operation_left, old = operation_left-1, old-1 {
					if id0 == 0 {
						dp_table[id0][operation_left] = max(dp_table[id0][operation_left], main_array[id0][id2])
					} else {
						dp_table[id0][operation_left] = max(dp_table[id0][operation_left], main_array[id0][id2]+dp_table[id0-1][old])
					}
				}
			}
		}
	}

	answer := dp_table[array_number-1][operation_number]
	fmt.Printf("%d\n", answer)
}

func function_name(v1, v2, v3 int) {

}

func function_name(line string) {

}

type initial_works struct{}

func (iw initial_works) with_test_case_number() {
	fmt.Scanf("%d", &id1)

	for test_case <= id1 {
		function_name()
		test_case++
	}
}

func (iw initial_works) single_iteration() {
	function_name()
}

func (iw initial_works) without_test_case_number() {
	var v1, v2, v3 int
	for fmt.Scanf("%d %d %d", &v1, &v2, &v3) == 3 && v1 != 0 {
		function_name(v1, v2, v3)
		test_case++
	}
}

func (iw initial_works) eoof() {
	var id4 string
	for {
		_, err := fmt.Scanf("%s", &id4)
		if err != nil {
			break
		}

		line := id4
		function_name(line)
		test_case++
	}
}

func main() {
	initial_works := initial_works{}

	initial_works.single_iteration()
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
