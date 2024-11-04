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
	return Division{createPair(dividend, divider)}
}

func (d *Division) reduce() {
	if val, ok := d.first.(int); ok {
		dividend := val
		divider := d.second.(int)
		gcd := Gcd(dividend, divider)
		d.first = dividend / gcd
		d.second = divider / gcd
	} else if val, ok := d.first.(int64); ok {
		dividend := val
		divider := d.second.(int64)
		gcd := Gcd(dividend, divider)
		d.first = dividend / gcd
		d.second = divider / gcd
	} else if val, ok := d.first.(float32); ok {
		dividend := val
		divider := d.second.(float32)
		gcd := Gcd(dividend, divider)
		d.first = dividend / gcd
		d.second = divider / gcd
	} else if val, ok := d.first.(float64); ok {
		dividend := val
		divider := d.second.(float64)
		gcd := Gcd(dividend, divider)
		d.first = dividend / gcd
		d.second = divider / gcd
	}
}

func (d *Division) addWithoutReturn(number Division) {
	d.add(number, 0)
}

func (d *Division) addWithReturn(number Division) Division {
	return d.add(number, 1)
}

func (d *Division) add(number Division, function int) Division {
	if val, ok := d.first.(int); ok {
		dividend := val
		divider := d.second.(int)
		dividend1 := number.first.(int)
		divider1 := number.second.(int)
		lcm := Lcm(divider, divider1)
		if function == 0 {
			d.first = (lcm/divider)*dividend + (lcm/divider1)*dividend1
			d.second = lcm
			d.reduce()
			return Division{}
		}
		result := createDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	} else if val, ok := d.first.(int64); ok {
		dividend := val
		divider := d.second.(int64)
		dividend1 := number.first.(int64)
		divider1 := number.second.(int64)
		lcm := Lcm(divider, divider1)
		if function == 0 {
			d.first = (lcm/divider)*dividend + (lcm/divider1)*dividend1
			d.second = lcm
			d.reduce()
			return Division{}
		}
		result := createDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	} else if val, ok := d.first.(float32); ok {
		dividend := val
		divider := d.second.(float32)
		dividend1 := number.first.(float32)
		divider1 := number.second.(float32)
		lcm := Lcm(divider, divider1)
		if function == 0 {
			d.first = (lcm/divider)*dividend + (lcm/divider1)*dividend1
			d.second = lcm
			d.reduce()
			return Division{}
		}
		result := createDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	} else if val, ok := d.first.(float64); ok {
		dividend := val
		divider := d.second.(float64)
		dividend1 := number.first.(float64)
		divider1 := number.second.(float64)
		lcm := Lcm(divider, divider1)
		if function == 0 {
			d.first = (lcm/divider)*dividend + (lcm/divider1)*dividend1
			d.second = lcm
			d.reduce()
			return Division{}
		}
		result := createDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	} else {
		panic("UnsupportedOperationException")
	}
}

func (d *Division) multiplyWithoutReturn(number Division) {
	d.multiply(number, 0)
}

func (d *Division) multiplyWithReturn(number Division) Division {
	return d.multiply(number, 1)
}

func (d *Division) multiply(number Division, function int) Division {
	if val, ok := d.first.(int); ok {
		first := val * number.first.(int)
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
	} else if val, ok := d.first.(int64); ok {
		first := val * number.first.(int64)
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
	} else if val, ok := d.first.(float32); ok {
		first := val * number.first.(float32)
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
	} else if val, ok := d.first.(float64); ok {
		first := val * number.first.(float64)
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
	} else {
		panic("UnsupportedOperationException")
	}
}

func Gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return Gcd(b, a%b)
}

func Gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return Gcd(b, a%b)
}

func Gcd(a, b float32) float32 {
	if b == 0 {
		return a
	}
	return Gcd(b, float32(math.Mod(float64(a), float64(b))))
}

func Gcd(a, b float64) float64 {
	if b == 0 {
		return a
	}
	return Gcd(b, math.Mod(a, b))
}

func Lcm(a, b int) int {
	return a / Gcd(a, b) * b
}

func Lcm(a, b int64) int64 {
	return a / Gcd(a, b) * b
}

func Lcm(a, b float32) float32 {
	return a / Gcd(a, b) * b
}

func Lcm(a, b float64) float64 {
	return a / Gcd(a, b) * b
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

func (g *Graph) ribMatrixToDefault(length, quantity int, readConsole bool, value [][]int) error {
	g.base = make([][]int, length)
	inputBase := make([][]int, length)
	for i := 0; i < length; i++ {
		inputBase[i] = make([]int, 0)
	}
	for i := 0; i < quantity; i++ {
		var input []int
		if readConsole {
			input = readArrayInt(" ")
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
	return nil
}

func (g *Graph) adjacencyMatrixToDefault(length, not int, readConsole bool, value [][]int) error {
	g.base = make([][]int, length)
	buffer := make([]int, 0)
	var InputArray []int
	for i := 0; i < length; i++ {
		if readConsole {
			InputArray = readArrayInt(" ")
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
	return nil
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
				return fmt.Errorf("Exception")
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

func floydWarshall(base [][]int, length, not int) bool {
	for k := 0; k < length; k++ {
		for i := 0; i < length; i++ {
			for j := 0; j < length; j++ {
				if base[i][k] == not || base[k][j] == not {
					continue
				}
				total := base[i][k] + base[k][j]
				if base[i][j] != not {
					base[i][j] = Min(base[i][j], total)
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

func Min(a, b int) int {
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

func InsertionSort(elements []int) {
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

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readArrayInt(split string) []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	strArr := strings.Split(scanner.Text(), split)
	intArr := make([]int, len(strArr))
	for i, str := range strArr {
		intArr[i], _ = strconv.Atoi(str)
	}
	return intArr
}

func writeInt(number int, end string) {
	fmt.Print(number, end)
}

func writeArray(array []int, split string, enter bool) {
	for i, num := range array {
		fmt.Print(num)
		if i != len(array)-1 {
			fmt.Print(split)
		}
	}
	if enter {
		fmt.Println()
	}
}

func main() {
	i1 := readInt()
	countValue := make(map[int]int)
	for i2 := 0; i2 < i1; i2++ {
		countValue = make(map[int]int)
		quantity := readArrayInt(" ")
		base := readArrayInt(" ")
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
		writeInt(min, "\n")
	}
}
