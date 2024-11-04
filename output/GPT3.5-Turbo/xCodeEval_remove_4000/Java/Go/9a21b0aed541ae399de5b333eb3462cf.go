package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Pair struct {
	first  interface{}
	second interface{}
}

func createPair(first, second interface{}) Pair {
	return Pair{first, second}
}

type Division struct {
	Pair
}

func createDivision(dividend, divider interface{}) Division {
	d := Division{}
	d.first = dividend
	d.second = divider
	d.reduce()
	return d
}

func (d *Division) reduce() {
	switch dividend := d.first.(type) {
	case int:
		divider := d.second.(int)
		gcd := gcd(dividend, divider)
		d.first = dividend / gcd
		d.second = divider / gcd
	case int64:
		divider := d.second.(int64)
		gcd := gcd(dividend, divider)
		d.first = dividend / gcd
		d.second = divider / gcd
	case float32:
		divider := d.second.(float32)
		gcd := gcd(dividend, divider)
		d.first = dividend / gcd
		d.second = divider / gcd
	case float64:
		divider := d.second.(float64)
		gcd := gcd(dividend, divider)
		d.first = dividend / gcd
		d.second = divider / gcd
	}
}

func (d *Division) add(number Division, function int) Division {
	switch dividend := d.first.(type) {
	case int:
		divider := d.second.(int)
		dividend1 := number.first.(int)
		divider1 := number.second.(int)
		lcm := lcm(divider, divider1)
		if function == 0 {
			d.first = (lcm/divider)*dividend + (lcm/divider1)*dividend1
			d.second = lcm
			d.reduce()
			return Division{}
		}
		result := createDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	case int64:
		divider := d.second.(int64)
		dividend1 := number.first.(int64)
		divider1 := number.second.(int64)
		lcm := lcm(divider, divider1)
		if function == 0 {
			d.first = (lcm/divider)*dividend + (lcm/divider1)*dividend1
			d.second = lcm
			d.reduce()
			return Division{}
		}
		result := createDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	case float32:
		divider := d.second.(float32)
		dividend1 := number.first.(float32)
		divider1 := number.second.(float32)
		lcm := lcm(divider, divider1)
		if function == 0 {
			d.first = (lcm/divider)*dividend + (lcm/divider1)*dividend1
			d.second = lcm
			d.reduce()
			return Division{}
		}
		result := createDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	case float64:
		divider := d.second.(float64)
		dividend1 := number.first.(float64)
		divider1 := number.second.(float64)
		lcm := lcm(divider, divider1)
		if function == 0 {
			d.first = (lcm/divider)*dividend + (lcm/divider1)*dividend1
			d.second = lcm
			d.reduce()
			return Division{}
		}
		result := createDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	default:
		return Division{}
	}
}

func (d *Division) id0(number Division) Division {
	return d.add(number, 1)
}

func (d *Division) multiply(number Division, function int) Division {
	switch dividend := d.first.(type) {
	case int:
		first := dividend * number.first.(int)
		second := d.second.(int) * number.second.(int)
		if function == 0 {
			d.first = first
			d.second = second
			d.reduce()
			return Division{}
		}
		answer := createDivision(first, second)
		answer.reduce()
		return answer
	case int64:
		first := dividend * number.first.(int64)
		second := d.second.(int64) * number.second.(int64)
		if function == 0 {
			d.first = first
			d.second = second
			d.reduce()
			return Division{}
		}
		answer := createDivision(first, second)
		answer.reduce()
		return answer
	case float32:
		first := dividend * number.first.(float32)
		second := d.second.(float32) * number.second.(float32)
		if function == 0 {
			d.first = first
			d.second = second
			d.reduce()
			return Division{}
		}
		answer := createDivision(first, second)
		answer.reduce()
		return answer
	case float64:
		first := dividend * number.first.(float64)
		second := d.second.(float64) * number.second.(float64)
		if function == 0 {
			d.first = first
			d.second = second
			d.reduce()
			return Division{}
		}
		answer := createDivision(first, second)
		answer.reduce()
		return answer
	default:
		return Division{}
	}
}

func (d *Division) id14(number Division) Division {
	return d.multiply(number, 1)
}

func gcd(a, b interface{}) interface{} {
	switch a := a.(type) {
	case int:
		b := b.(int)
		if b == 0 {
			return a
		}
		return gcd(b, a%b)
	case int64:
		b := b.(int64)
		if b == 0 {
			return a
		}
		return gcd(b, a%b)
	case float32:
		b := b.(float32)
		if b == 0 {
			return a
		}
		return gcd(b, float32(math.Mod(float64(a), float64(b))))
	case float64:
		b := b.(float64)
		if b == 0 {
			return a
		}
		return gcd(b, math.Mod(a, b))
	default:
		return nil
	}
}

func lcm(a, b interface{}) interface{} {
	switch a := a.(type) {
	case int:
		b := b.(int)
		return a / gcd(a, b) * b
	case int64:
		b := b.(int64)
		return a / gcd(a, b) * b
	case float32:
		b := b.(float32)
		return a / gcd(a, b) * b
	case float64:
		b := b.(float64)
		return a / gcd(a, b) * b
	default:
		return nil
	}
}

type Graph struct {
	base     [][]int
	used     []bool
	quantity int
	ancestor []int
}

func (g *Graph) getBase() [][]int {
	return g.base
}

func (g *Graph) getUsed() []bool {
	return g.used
}

func (g *Graph) getQuantity() int {
	return g.quantity
}

func (g *Graph) getAncestor() []int {
	return g.ancestor
}

func (g *Graph) start(length int) {
	g.used = make([]bool, length)
	g.ancestor = make([]int, length)
	g.ancestor[0] = -1
	g.quantity = 0
}

func (g *Graph) id6(length, quantity int, readConsole bool, value [][]int) {
	g.base = make([][]int, length)
	inputBase := make([][]int, length)
	for i := 0; i < length; i++ {
		inputBase[i] = make([]int, 0)
	}
	for i := 0; i < quantity; i++ {
		var input []int
		if readConsole {
			input = id7(" ")
		} else {
			input = value[i]
		}
		inputBase[input[0]-1] = append(inputBase[input[0]-1], input[1]-1)
		inputBase[input[1]-1] = append(inputBase[input[1]-1], input[0]-1)
	}
	for i := 0; i < length; i++ {
		g.base[i] = inputBase[i]
	}
	g.start(length)
}

func (g *Graph) id9(length, not int, readConsole bool, value [][]int) {
	g.base = make([][]int, length)
	buffer := make([]int, 0)
	var InputArray []int
	for i := 0; i < length; i++ {
		if readConsole {
			InputArray = id7(" ")
		} else {
			InputArray = value[i]
		}
		for index := 0; index < length; index++ {
			if i != index && InputArray[index] != not {
				buffer = append(buffer, index)
			}
		}
		g.base[i] = buffer
		buffer = make([]int, 0)
	}
	g.start(length)
}

func (g *Graph) dfs(position int) error {
	g.used[position] = true
	g.quantity++
	var next int
	for index := 0; index < len(g.base[position]); index += 2 {
		next = g.base[position][index]
		if !g.used[next] {
			g.ancestor[next] = position
			err := g.dfs(next)
			if err != nil {
				return err
			}
		} else {
			if next != g.ancestor[position] {
				return fmt.Errorf("Cycle detected")
			}
		}
	}
	return nil
}

func (g *Graph) dijkstra(start, stop, size int) int {
	start--
	stop--
	dist := make([]int, size)
	for i := 0; i < size; i++ {
		if i != start {
			dist[i] = int(^uint(0) >> 1)
		}
		g.ancestor[i] = start
	}

	queue := make([][]int, 0)
	queue = append(queue, []int{start, 0})
	var position int
	for len(queue) != 0 {
		getQueue := queue[0]
		queue = queue[1:]
		position = getQueue[0]
		if getQueue[1] > dist[position] {
			continue
		}
		for index := 0; index < len(g.base[position]); index += 2 {
			if dist[position]+g.base[position][index+1] < dist[g.base[position][index]] && !g.used[g.base[position][index]] {
				dist[g.base[position][index]] = dist[position] + g.base[position][index+1]
				g.ancestor[g.base[position][index]] = position
				queue = append(queue, []int{g.base[position][index], dist[g.base[position][index]]})
			}
		}
		g.used[position] = true
	}
	if dist[stop] == int(^uint(0)>>1) {
		return -1
	}
	return dist[stop]
}

func id11(base [][]int, length, not int) bool {
	for k := 0; k < length; k++ {
		for i := 0; i < length; i++ {
			for j := 0; j < length; j++ {
				if base[i][k] == not || base[k][j] == not {
					continue
				}
				total := base[i][k] + base[k][j]
				if base[i][j] != not {
					base[i][j] = min(base[i][j], total)
				} else {
					base[i][j] = total
				}
			}
		}
	}
	for index := 0; index < length; index++ {
		if base[index][index] != 0 {
			return false
		}
	}
	return true
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func ShellSort(array []int) {
	for gap := len(array) / 2; gap > 0; gap /= 2 {
		for i := gap; i < len(array); i++ {
			temp := array[i]
			var j int
			for j = i; j >= gap && array[j-gap] > temp; j -= gap {
				array[j] = array[j-gap]
			}
			array[j] = temp
		}
	}
}

func HeapSort(array []int) {
	for i := len(array)/2 - 1; i >= 0; i-- {
		shiftDown(array, i, len(array))
	}
	for i := len(array) - 1; i > 0; i-- {
		swap(array, 0, i)
		shiftDown(array, 0, i)
	}
}

func shiftDown(array []int, i, n int) {
	tmp := array[i]
	for child := leftChild(i); child < n; child = leftChild(i) {
		if child != n-1 && array[child] < array[child+1] {
			child++
		}
		if tmp < array[child] {
			array[i] = array[child]
		} else {
			break
		}
		i = child
	}
	array[i] = tmp
}

func leftChild(i int) int {
	return 2*i + 1
}

func swap(array []int, i, j int) {
	temp := array[i]
	array[i] = array[j]
	array[j] = temp
}

func MergeSort(array []int, low, high int) {
	if low < high {
		mid := (low + high) / 2
		MergeSort(array, low, mid)
		MergeSort(array, mid+1, high)
		merge(array, low, mid, high)
	}
}

func merge(array []int, low, mid, high int) {
	n := high - low + 1
	temp := make([]int, n)
	i := low
	j := mid + 1
	k := 0
	for i <= mid || j <= high {
		if i > mid {
			temp[k] = array[j]
			j++
		} else if j > high {
			temp[k] = array[i]
			i++
		} else if array[i] < array[j] {
			temp[k] = array[i]
			i++
		} else {
			temp[k] = array[j]
			j++
		}
		k++
	}
	for j = 0; j < n; j++ {
		array[low+j] = temp[j]
	}
}

func id4(elements []int) {
	for i := 1; i < len(elements); i++ {
		key := elements[i]
		j := i - 1
		for j >= 0 && key < elements[j] {
			elements[j+1] = elements[j]
			j--
		}
		elements[j+1] = key
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < t; i++ {
		scanner.Scan()
		i1, _ := strconv.Atoi(scanner.Text())

		countValue := make(map[int]int)
		for i2 := 0; i2 < i1; i2++ {
			countValue = make(map[int]int)
			scanner.Scan()
			quantity := parseIntArray(scanner.Text())
			base := parseIntArray(scanner.Text())

			for i := 0; i < quantity[2]; i++ {
				countValue[base[i]]++
			}
			min := len(countValue)
			for i := quantity[2]; i < quantity[0]; i++ {
				countValue[base[i-quantity[2]]]--
				if countValue[base[i-quantity[2]]] == 0 {
					delete(countValue, base[i-quantity[2]])
				}
				countValue[base[i]]++
				if len(countValue) < min {
					min = len(countValue)
				}
			}
			fmt.Println(min)
		}
	}
}

func parseIntArray(s string) []int {
	strArr := strings.Split(s, " ")
	intArr := make([]int, len(strArr))
	for i, v := range strArr {
		intArr[i], _ = strconv.Atoi(v)
	}
	return intArr
}
