package main

import (
	"fmt"
)

type MCMF_CS2 struct {
	n, m         int
	cap          []int
	nodes        []Node
	sentinelNode *Node
	arcs         []Arc
	sentinelArc  *Arc
	buckets      []Bucket
	lBucket      *Bucket
	linf         int
	timeForPrice int
	epsilon      int
	dn           int
	priceMin     int
	mmc          int
	fScale       float64
	cutOffFactor float64
	cutOn        float64
	cutOff       float64
	totalExcess  int
	flagPrice    int
	flagUpdt     int
	sncMax       int
	dArc         Arc
	dNode        Node
	dummyNode    *Node
	nRel         int
	nRef         int
	nSrc         int
	nPush        int
	nRelabel     int
	nDischarge   int
	nRefine      int
	nUpdate      int
	nScan        int
	nPrscan      int
	nPrscan1     int
	nPrscan2     int
	nBadPricein  int
	nBadRelabel  int
	nPrefine     int
	noZeroCycles bool
	checkSolution bool
	compDuals     bool
	costRestart   bool
	printAns      bool
	nodeBalance   []int
	nodeMin       int
	nodeMax       int
	arcFirst      []int
	arcTail       []int
	posCurrent    int
	arcCurrent    *Arc
	arcNew        *Arc
	arcTmp        *Arc
	maxCost       int
	totalP        int
	totalN        int
	iNode         *Node
	jNode         *Node
}

type Node struct {
	excess   int
	price    int
	first    *Arc
	current  *Arc
	suspended *Arc
	qNext    *Node
	bNext    *Node
	bPrev    *Node
	rank     int
	inp      int
}

type Arc struct {
	rezCapacity int
	cost        int
	head        *Node
	sister      *Arc
}

type Bucket struct {
	pFirst *Node
}

func NewMCMF_CS2(numNodes, numArcs int) *MCMF_CS2 {
	return &MCMF_CS2{
		n:             numNodes,
		m:             numArcs,
		flagPrice:     0,
		flagUpdt:      0,
		nPush:         0,
		nRelabel:      0,
		nDischarge:    0,
		nRefine:       0,
		nUpdate:       0,
		nScan:         0,
		nPrscan:       0,
		nPrscan1:      0,
		nPrscan2:      0,
		nBadPricein:   0,
		nBadRelabel:   0,
		nPrefine:      0,
		noZeroCycles:  false,
		checkSolution: false,
		compDuals:     false,
		costRestart:   false,
		printAns:      true,
	}
}

func (m *MCMF_CS2) SetArc(tailNodeID, headNodeID, lowBound, upBound, cost int) {
	if tailNodeID < 0 || tailNodeID > m.n || headNodeID < 0 || headNodeID > m.n {
		fmt.Println("Invalid node ID")
		return
	}
	if upBound < 0 {
		upBound = 0x7fffffff
	}
	if lowBound < 0 || lowBound > upBound {
		fmt.Println("Invalid bounds")
		return
	}

	m.arcFirst[tailNodeID+1]++
	m.arcFirst[headNodeID+1]++
	iNode := m.nodes[tailNodeID]
	jNode := m.nodes[headNodeID]

	m.arcTail[m.posCurrent] = tailNodeID
	m.arcTail[m.posCurrent+1] = headNodeID
	m.arcCurrent.SetHead(jNode)
	m.arcCurrent.SetRezCapacity(upBound - lowBound)
	m.cap[m.posCurrent] = upBound
	m.arcCurrent.SetCost(cost)
	m.arcCurrent.SetSister(m.arcCurrent + 1)
	(m.arcCurrent + 1).SetHead(iNode)
	(m.arcCurrent + 1).SetRezCapacity(0)
	m.cap[m.posCurrent+1] = 0
	(m.arcCurrent + 1).SetCost(-cost)
	(m.arcCurrent + 1).SetSister(m.arcCurrent)

	iNode.DecExcess(lowBound)
	jNode.IncExcess(lowBound)

	if headNodeID < m.nodeMin {
		m.nodeMin = headNodeID
	}
	if tailNodeID < m.nodeMin {
		m.nodeMin = tailNodeID
	}
	if headNodeID > m.nodeMax {
		m.nodeMax = headNodeID
	}
	if tailNodeID > m.nodeMax {
		m.nodeMax = tailNodeID
	}

	if cost < 0 {
		cost = -cost
	}
	if cost > m.maxCost && upBound > 0 {
		m.maxCost = cost
	}

	m.arcCurrent += 2
	m.posCurrent += 2
}

func (m *MCMF_CS2) SetSupplyDemandOfNode(id, excess int) {
	if id < 0 || id > m.n {
		fmt.Println("Invalid node ID")
		return
	}
	m.nodes[id].SetExcess(excess)
	if excess > 0 {
		m.totalP += excess
	}
	if excess < 0 {
		m.totalN -= excess
	}
}

func (m *MCMF_CS2) RunCS2() {
	m.preProcessing()

	if m.checkSolution {
		m.nodeBalance = make([]int, m.n+1)
		for i := range m.nodes {
			m.nodeBalance[i] = m.nodes[i].excess
		}
	}

	m.m = 2 * m.m
	m.cs2Initialize()

	m.cs2(&objectiveCost)

	fmt.Println(objectiveCost)

	if m.checkSolution {
		fmt.Println("Checking feasibility...")
		if m.checkFeas() {
			fmt.Println("...OK")
		} else {
			fmt.Println("ERROR: Solution infeasible")
		}
		fmt.Println("Computing prices and checking CS...")
		m.computePrices()
		if m.checkCS() {
			fmt.Println("...OK")
		} else {
			fmt.Println("ERROR: CS violation")
		}
	}

	if m.printAns {
		m.printSolution()
	}

	m.deallocateArrays()
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	grid := make([][]int, n)
	for i := range grid {
		grid[i] = make([]int, m)
		for j := range grid[i] {
			fmt.Scan(&grid[i][j])
		}
	}
	a, b, c := make([]int, 0), make([]int, 0), make([]int, 0)
	for i := range grid {
		for j := range grid[i] {
			if (i+j)%2 == 1 {
				if i > 0 {
					a = append(a, f(i, j))
					b = append(b, f(i-1, j))
					c = append(c, grid[i][j] != grid[i-1][j])
				}
				if j > 0 {
					a = append(a, f(i, j))
					b = append(b, f(i, j-1))
					c = append(c, grid[i][j] != grid[i][j-1])
				}
				if i+1 < n {
					a = append(a, f(i, j))
					b = append(b, f(i+1, j))
					c = append(c, grid[i][j] != grid[i+1][j])
				}
				if j+1 < m {
					a = append(a, f(i, j))
					b = append(b, f(i, j+1))
					c = append(c, grid[i][j] != grid[i][j+1])
				}
			}
		}
	}
	numNodes := n * m * 4
	numArcs := len(a)

