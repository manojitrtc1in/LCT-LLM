
import heapq
from collections import Counter
import math
from collections import defaultdict


def id57(array, target):
    combinations = []
    helperMethod(array, target, 0, [], combinations)
    return combinations


def helperMethod(array, target, startIdx, currentSum, combinations):
    if target == 0:
        combinations.append(currentSum)
        return
    if target < 0:
        return
    for i in range(startIdx, len(array)):
        if i == startIdx and currentSum[i] != currentSum[i - 1]:
            currentNum = array[i]
            currentTarget = target - currentNum
            newSum = currentSum + [currentNum]
            helperMethod(array, currentTarget, i, newSum, combinations)


def id0(maxSteps, height):
    memorize = {"0": 1, "1": 1}
    return helper(0, 0, maxSteps, height)


def helper(step, id25, maxSteps, height, memorize):
    if f"{step}" in memorize:
        return memorize[f"{step}"]
    for step in range(1, min(maxSteps, height) + 1):
        id25 += helper(height - step,)


def id26(string):
    hashMap = {"1": "", "2": "abc", "3": "def", "4": "ghi",
               "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
    result = []
    anotherHelper(string, 0, '', hashMap, result)
    return result


def anotherHelper(string, idx, currentString, hashMap, result):
    if len(currentString) == len(string):
        result.append(currentString)
        return
    currentMap = hashMap[string[idx]]
    for char in currentMap:
        anotherHelper(string, idx + 1, currentString + char, hashMap, result)


def id57(array, target):
    result = []
    dfs(array, 0, [], target, result)
    return result


def dfs(array, startIdx, currentSum, target, result):
    if target == 0:
        result.append(currentSum)
        return
    if target < 0:
        return

    for i in range(startIdx, len(array)):
        newSum = currentSum + [array[i]]
        dfs(array, i, newSum, target - array[i], result)


class Info:
    def __init__(self, ways):
        self.ways = ways

















def id45(board):
    for row in range(len(board)):
        for col in range(len(board[row])):
            currentNum = board[row][col]
            if currentNum != ".":
                if not validateDigit(row, col, currentNum, board):
                    return False
                else:
                    continue
    return True


def validateDigit(row, col, currentNum, board):
    rowCounter = 0
    for i in range(len(board[row])):
        if board[row][i] == currentNum:
            rowCounter += 1
    if rowCounter > 1:
        return False
    colCounter = 0
    for i in range(len(board)):
        if board[i][col] == currentNum:
            colCounter += 1
    if colCounter > 1:
        return False
    gridCounter = 0
    currentRow = row // 3
    currentCol = col // 3
    for rowIdx in range(3):
        for colIdx in range(3):
            id17 = currentRow * 3 + rowIdx
            id50 = currentCol * 3 + colIdx
            number = board[id17][id50]
            if number == currentNum:
                gridCounter += 1
    if gridCounter > 1:
        return False
    return True






def countArrangement(string):
    result = []
    one(string, result, '')
    return len(result) - 1


def one(string, result, currentString):
    if currentString not in result:
        result.append(currentString)

    for i in range(len(string)):
        newString = string[:i] + string[i + 1:]
        one(newString, result, currentString + string[i])


def id38(array):
    result = []
    end = len(array) - 1
    id53(array, 0, [], end, result)
    return result


def id53(array, idx, currentArr, end, result):
    if idx == end:
        currentArr.append(idx)
        result.append(currentArr)
        return

    for i in range(len(array[idx])):
        newArr = currentArr + [idx]
        id53(array, array[idx][i], newArr, end, result)








def id2(string):
    result = []
    if string.isnumeric():
        return result
    two(string, 0, result)
    return result


def two(string, idx, result):
    if idx == len(string):
        return
    if string[idx].isnumeric():
        two(string, idx + 1, result)
        return
    id12 = list(string)
    id55 = list(string)
    id12[idx] = id12[idx].upper()
    id55[idx] = id55[idx].lower()
    stringUpper = ''.join(id12)
    stringLower = ''.join(id55)
    if stringUpper not in result:
        result.append(stringUpper)
    if stringLower not in result:
        result.append(stringLower)
    two(stringUpper, idx + 1, result)
    two(stringLower, idx + 1, result)


def id14(array, direction):
    maxHeight = 0
    result = []
    if direction == "east":
        for i in reversed(range(len(array))):
            if array[i] > maxHeight:
                maxHeight = array[i]
                result.append(i)
    else:
        for i in range(len(array)):
            if array[i] > maxHeight:
                maxHeight = array[i]
                result.append(i)
    return result[::-1] if direction == "east" else result


def id46(matrix):
    visitedAtlantic = [[False for i in range(
        len(matrix[0]))] for i in range(len(matrix))]
    visitedPacific = [[False for i in range(
        len(matrix[0]))] for i in range(len(matrix))]
    resultAtlantic = []
    resultPacific = []
    for i in range(len(matrix[0])):
        if not visitedPacific[0][i]:
            bfs(0, i, matrix, visitedPacific, resultPacific)

    for i in range(len(matrix)):
        if not visitedPacific[i][0]:
            bfs(i, 0, matrix, visitedPacific, resultPacific)

    for i in range(len(matrix[len(matrix) - 1])):
        if not visitedAtlantic[len(matrix) - 1][i]:
            bfs(len(matrix) - 1, i, matrix, visitedAtlantic, resultAtlantic)

    for i in range(len(matrix)):
        if not visitedAtlantic[i][len(matrix[0]) - 1]:
            bfs(i, len(matrix[0]) - 1, matrix, visitedAtlantic, resultAtlantic)
    lst3 = []
    for i in range(len(resultAtlantic)):
        if resultAtlantic[i] in resultPacific:
            lst3.append(resultAtlantic[i])
    return lst3


def bfs(i, j, matrix, visited, result):
    queue = [[i, j]]
    while(len(queue)):
        currentNode = queue.pop(0)
        i = currentNode[0]
        j = currentNode[1]
        if visited[i][j]:
            continue
        visited[i][j] = True
        result.append([i, j])
        neighbours = getNeighbours(i, j, matrix, visited)
        for neighbour in neighbours:
            queue.append(neighbour)


def getNeighbours(i, j, matrix, visited):
    neighbours = []
    if i > 0:
        neighbours.append(((i - 1, j), "forth"))

    if i < len(matrix) - 1:
        neighbours.append(((i + 1, j), "forth"))

    if j > 0:
        neighbours.append(((i, j - 1), "left"))

    if j < len(matrix[0]) - 1:
        neighbours.append(((i, j + 1), "right"))

    return neighbours


def id31(string):
    id19 = list(string)
    result = []
    hashMap = {}
    four(result, id19, '', hashMap)
    return len(result)


def four(result, string, currentStr, hashMap):
    if len(currentStr):
        result.append(''.join(currentStr))
    for i in range(len(string)):
        if string[i] in hashMap:
            continue
        hashMap[string[i]] = True
        id19 = string[:i] + string[i + 1:]
        four(result, id19, currentStr + string[i], {})







def id3(string):
    hashMap = {}
    startIdx = 0
    id40 = float('-inf')
    for endIdx in range(len(string)):
        if string[endIdx] not in hashMap:
            hashMap[string[endIdx]] = True
            id40 = max(id40, (endIdx + 1) - startIdx)
        else:
            while(string[endIdx] in hashMap):
                hashMap.pop(string[startIdx])
                startIdx += 1
            hashMap[string[endIdx]] = True
    return id40


def id35(array, k):
    anotherK = 0
    startIdx = 0
    id40 = float('-inf')
    for endIdx, num in enumerate(array):
        if num == 0:
            anotherK += 1
        if anotherK <= k:
            id40 = max(id40, (endIdx + 1) - startIdx)
        else:
            while(anotherK >= k):
                if array[startIdx] == 0:
                    anotherK -= 1
                startIdx += 1
    return id40






def id49(string, k):
    vowels = 'aeiou'
    maxLength = float('-inf')
    currentLength = 0
    startIdx = 0
    for endIdx, letter in enumerate(string):
        if (endIdx + 1 - startIdx) <= k:
            if letter in vowels:
                currentLength += 1
                maxLength = max(maxLength, currentLength)
        else:
            while((endIdx + 1 - startIdx) > k):
                if string[startIdx] in vowels:
                    currentLength -= 1
                startIdx += 1
            if letter in vowels:
                currentLength += 1
                maxLength = max(maxLength, currentLength)
    return maxLength if maxLength != float('-inf') else 0




array = [1, 2, 3, 4]


def id20(array, target):
    for leftPointer in range(len(array)):
        for rightPointer in range(leftPointer + 1, len(array)):
            currentSum = array[leftPointer] + array[rightPointer]
            if currentSum == target:
                return [array[leftPointer], array[rightPointer]]





def largestRectangle(array):
    stack = []
    maxArea = float('-inf')
    for i in range(len(array)):
        while(len(stack) and array[i] <= array[stack[-1]]):
            rightBound = stack.pop()
            width = i if not len(stack) else i - stack[-1]
            currentArea = array[rightBound] * width
            maxArea = max(maxArea, currentArea)
        stack.append(i)
    return maxArea


class MinHeap:
    def __init__(self, array):
        self.heap = self.buildHeap(array)

    def buildHeap(self, array):
        parentIdx = ((len(array)) - 1) // 2
        for i in reversed(range(parentIdx)):
            self.id4(i, array)
        return array

    def id4(self, parentIdx, array):
        id18 = (2 * parentIdx) + 1
        while(id18 < len(array)):
            id51 = (2 * parentIdx) + 2 if (2 *
                                                  parentIdx) + 2 < len(array) else -1
            if id51 != -1 and array[id51] < array[id18]:
                id28 = id51
            else:
                id28 = id18
            if array[id28] < array[parentIdx]:
                self.swap(parentIdx, id28, array)
                parentIdx = id28
                id18 = (2 * parentIdx) + 1
            else:
                break

    def id32(self, childIdx):
        parentIdx = (childIdx - 1) // 2
        while(childIdx > 0 and self.heap[childIdx] <= self.heap[parentIdx]):
            self.swap(childIdx, parentIdx, self.heap)
            childIdx = parentIdx
            parentIdx = (childIdx - 1) // 2

    def insert(self, value):
        self.heap.append(value)
        self.id32(len(self.heap) - 1)

    def remove(self):
        self.swap(0, len(self.heap) - 1, self.heap)
        value = self.heap.pop()
        self.id4(0, self.heap)
        return value

    def swap(self, i, j, array):

        temp = array[i]
        array[i] = array[j]
        array[j] = temp

    def peek(self):
        return self.heap[0]


class MaxHeap:
    def __init__(self, array):
        self.heap = self.buildHeap(array)

    def buildHeap(self, array):
        parentIdx = ((len(array)) - 1) // 2
        for i in reversed(range(parentIdx) + 1):
            self.id4(i, array)
        return array

    def id32(self, childIdx):
        parentIdx = (childIdx - 1) // 2
        while(childIdx > 0 and self.heap[parentIdx] <= self.heap[childIdx]):
            self.swap(childIdx, parentIdx, self.heap)
            childIdx = parentIdx
            parentIdx = (childIdx - 1) // 2

    def id4(self, parentIdx, array):
        id18 = (2 * parentIdx) + 1
        while(id18 < len(array)):
            id51 = (2 * parentIdx) + 2 if (2 *
                                                  parentIdx) + 2 < len(array) else -1
            if id51 != -1 and array[id51] > array[id18]:
                id28 = id51
            else:
                id28 = id18
            if array[id28] > array[parentIdx]:
                self.swap(id28, parentIdx, array)
                parentIdx = id28
                id18 = (2 * parentIdx) + 1
            else:
                break

    def insert(self, value):
        self.heap.append(value)
        self.id32(len(self.heap) - 1)

    def remove(self):
        self.swap(0, len(self.heap) - 1, self.heap)
        value = self.heap.pop()
        self.id4(0, self.heap)
        return value

    def swap(self, i, j, array):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

    def peek(self):
        return self.heap[0]





class MedianFinder:
    def __init__(self):
        self.minHeap = MinHeap([])
        self.maxHeap = MaxHeap([])

    def addNumber(self, value):
        if not len(self.maxHeap.heap):
            self.maxHeap.insert(value)
            return
        id7 = self.maxHeap.peek()
        if value < id7:
            currentDiff = len(self.maxHeap.heap) - len(self.minHeap.heap)
            if currentDiff >= 1:
                removedValue = self.maxHeap.remove()
                self.maxHeap.insert(value)
                self.minHeap.insert(removedValue)
            else:
                self.maxHeap.insert(value)
        else:
            currentDiff = len(self.minHeap.heap) - len(self.maxHeap.heap)
            if currentDiff >= 1:
                removedValue = self.minHeap.remove()
                self.minHeap.insert(value)
                self.maxHeap.insert(removedValue)
            else:
                self.minHeap.insert(value)

    def findMedian(self):
        if len(self.minHeap.heap) == len(self.maxHeap.heap):
            id34 = self.minHeap.peek()
            id7 = self.maxHeap.peek()
            return (id34 + id7) / 2
        if len(self.minHeap.heap) > len(self.maxHeap.heap):
            return self.minHeap.peek()
        else:
            return self.maxHeap.peek()


def id29(array):
    array.sort()
    heap = MaxHeap([])
    for i in range(len(array)):
        startTime = array[i][0]
        endTime = array[i][1]
        if not len(heap.heap):
            heap.insert(endTime)
            continue
        if startTime < heap.peek():
            heap.remove()
            heap.insert(endTime)
        else:
            heap.insert(endTime)
    return len(heap.heap)


def id39(matrix):
    sortedArray = []
    heap = MinHeap([])
    for i in range(len(matrix)):
        heap.insert(
            {"num": matrix[i][0], "numberIdx": 0, "arrayIdx": i})
    result = []
    while(len(heap.heap)):
        currentMinimal = heap.remove()
        sortedArray.append(currentMinimal["num"])
        if len(matrix[currentMinimal["arrayIdx"]]) > currentMinimal["numberIdx"] + 1:
            currentMinimal = {"num": matrix[currentMinimal["arrayIdx"]][currentMinimal["numberIdx"] + 1],
                              "numberIdx": currentMinimal["numberIdx"] + 1, "arrayIdx": currentMinimal["arrayIdx"]}
            heap.insert(currentMinimal)
    return sortedArray





def heapSort(array):
    buildHeap(array)
    for endIdx in reversed(range(1, len(array))):
        swap(endIdx, 0, array)
        id4(0, endIdx - 1, array)
    return array


def buildHeap(array):
    id54 = (len(array) - 1) // 2
    for i in reversed(range(id54 + 1)):
        id4(i, len(array) - 1, array)


def id4(currentIdx, endIdx, array):
    id18 = (2 * currentIdx) + 1
    while(id18 <= endIdx):
        id51 = (2 * currentIdx) + 2 if (2 *
                                               currentIdx) + 2 <= endIdx else -1
        if id51 != -1 and array[id51] > array[id18]:
            id28 = id51
        else:
            id28 = id18
        if array[id28] > array[currentIdx]:
            swap(id28, currentIdx, array)
            currentIdx = id28
            id18 = (2 * currentIdx) + 1
        else:
            return


def swap(i, j, array):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp


array = [[3, 2], [4, 3]]
array.sort(key=lambda x: (x[1]))


def courseSchedule(array):
    array.sort(key=lambda x: (x[1]))
    timeFrame = 0
    maxHeap = MaxHeap([])
    for i in range(len(array)):
        timeFrame += array[i][0]
        if timeFrame <= array[i][1]:
            maxHeap.insert(array[i][0])
        else:
            if not(len(maxHeap.heap)):
                continue
            removedCourse = maxHeap.remove()
            timeFrame -= removedCourse
            maxHeap.insert(array[i][0])
    return len(maxHeap.heap)





def taskScheduler(array, n):
    counts = {}
    for char in array:
        if char not in counts:
            counts[char] = 1
        else:
            counts[char] += 1
    maxHeap = MaxHeap(list(counts.values()))
    counts = 0
    while(len(maxHeap.heap)):
        id47 = []
        for i in range(n + 1):
            if len(maxHeap.heap):
                element = maxHeap.remove()
                id47.append(element)
        for elem in id47:
            if elem - 1 > 0:
                maxHeap.insert(elem - 1)
        counts += len(id47) if not len(maxHeap.heap) else n + 1
    return counts






def id52(string):
    count = Counter(string)
    currentLargest = heapq.nlargest(len(count), count.keys(), count.get)
    currentString = ""
    while(len(currentLargest)):
        id47 = []
        for i in range(len(currentLargest)):
            currentElement = currentLargest.pop(0)
            id47.append(currentElement)
            count[currentElement] -= 1
            if len(currentString) and currentString[len(currentString) - 1] == currentElement:
                print(currentString)
                return ""
            currentString += currentElement
        for elem in id47:
            if elem in count and count[elem] == 0:
                count.pop(elem)
        currentLargest = heapq.nlargest(len(count), count.keys(), count.get)
    return currentString



def id41(array, target):
    leftPointer = 0
    rightPointer = len(array) - 1
    while(rightPointer > leftPointer):
        middle = (rightPointer + leftPointer) // 2
        if target == array[leftPointer]:
            return leftPointer
        if target == array[rightPointer]:
            return rightPointer
        if array[leftPointer] <= array[middle]:
            if array[middle] == target:
                return middle
            if target < array[middle] and target >= array[leftPointer]:
                if target == array[leftPointer]:
                    return leftPointer
                rightPointer = middle - 1
            else:
                leftPointer = middle + 1
        else:
            if array[middle] == target:
                return middle
            if target > array[middle] and target <= array[rightPointer]:
                if target == array[rightPointer]:
                    return rightPointer
                leftPointer = middle + 1
            else:
                rightPointer = middle - 1
    return -1


def id22(array, target):
    finalRange = [-1, -1]
    searchHelper(0, len(array) - 1, array, target, True, finalRange)
    searchHelper(0, len(array) - 1, array, target, False, finalRange)
    return finalRange


def searchHelper(leftPointer, rightPointer, array, target, isLeft, finalRange):
    if leftPointer > rightPointer:
        return

    middlePointer = (rightPointer + leftPointer) // 2
    if array[middlePointer] > target:
        searchHelper(leftPointer, middlePointer - 1,
                     array, target, isLeft, finalRange)
    elif array[middlePointer] < target:
        searchHelper(middlePointer + 1, rightPointer,
                     array, target, isLeft, finalRange)
    else:
        if isLeft:
            if array[middlePointer] == 0 or array[middlePointer] != array[middlePointer - 1]:
                finalRange[0] = middlePointer
            else:
                searchHelper(leftPointer, middlePointer - 1,
                             array, target, isLeft, finalRange)
        else:
            if array[middlePointer] == len(array) - 1 or array[middlePointer] != array[middlePointer + 1]:
                finalRange[1] = middlePointer
            else:
                searchHelper(middlePointer + 1, rightPointer,
                             array, target, isLeft, finalRange)


def id58(array):
    count = Counter(array)
    for num in count:
        if count[num] == 1:
            return num
    return count


def findElement(array):
    leftSum = 0
    rightSum = 0
    leftPointer = 0
    rightPointer = len(array) - 1
    leftSum += array[leftPointer]
    rightSum += array[rightPointer]
    while(rightPointer > leftPointer):
        if rightSum >= leftSum:
            leftPointer += 1
            leftSum += array[leftPointer]
        else:
            rightPointer -= 1
            rightSum += array[rightPointer]
    return [leftPointer, rightPointer]




































def id13(array):
    minHeap = MinHeap(array)
    id13 = 0
    currentMinimum = 0
    while(len(minHeap.heap)):
        element = minHeap.remove()
        id13 += currentMinimum
        currentMinimum += element
    return id13


class id21:

    def __init__(self):
        self.head = None
        self.tail = None

    def id11(self, id23):
        currentHead = self.head
        if currentHead is None:
            self.head = id23
            self.tail = id23
        else:
            currentHead.prev = id23
            id23.next = currentHead
            self.head = id23

    def id48(self, id23):
        tailNode = self.tail
        if tailNode is None:
            self.head = id23
            self.tail = id23
        else:
            nextNode = tailNode.next
            id23.next = nextNode
            id23.prev = tailNode
            tailNode.next = id23
            self.tail = id23

    def evict(self):
        id16 = self.tail
        prevNode = id16.prev
        if prevNode is None:
            self.head = None
            self.tail = None
        else:
            prevNode.next = None
            self.tail = prevNode


class id56:

    def __init__(self, capacity):
        self.cache = {}
        self.capacity = capacity
        self.size = 0
        LinkedList = id21()

    def get(self, key):
        if key not in self.cache:
            return -1
        keyNode = self.cache[key]
        self.LinkedList.id11(keyNode)
        return key.val

    def put(self, key, value):
        size = self.size
        capacity = self.capacity
        if key in self.cache:
            keyNode = self.cache[key]
            keyNode.val = value
            self.LinkedList.id11(keyNode)
        else:
            if size < capacity:
                listNode = id10(value, key)
                self.LinkedList.id11(listNode)
                size += 1
            else:
                self.LinkedList.evict()
                listNode = id10(value, key)
                self.LinkedList.id11(listNode)


class id10:

    def __init__(self, val, key):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None





















def id33(array, k):
    matrix = [[0 for i in range(len(array))] for i in range(k + 1)]
    cache = {}
    for i in range(1, len(matrix)):
        cache = {}
        for y in range(1, len(matrix[i])):
            matrix[i][y] = max(
                matrix[i][y - 1], array[y] + id8(matrix, cache, array, y, i - 1))


def id8(matrix, cache, array, idx, topIdx):
    if idx - 1 not in cache:
        cache[idx] = matrix[topIdx][idx - 1] - array[idx - 1]
        return cache[idx]
    currentMax = float('-inf')
    currentMax = max(cache[idx - 1], matrix[topIdx][idx - 1] - array[idx - 1])
    cache[idx] = currentMax
    return currentMax




def id43(matrix, size):
    maxSum = float('-inf')
    for i in range(len(matrix)):
        cache = {}
        difference = len(matrix) - i
        if difference < size:
            break
        for y in range(len(matrix[i])):
            difference = len(matrix[i]) - y
            currentSum = 0
            if difference < size:
                break
            for x in range(size):
                currentSum += getSum(matrix, y + x, i, cache, size)
            maxSum = max(maxSum, currentSum)
    return maxSum


def getSum(matrix, x, y, cache, size):
    if x in cache:
        return cache[x]
    currentSum = 0
    for i in range(size):
        currentSum += matrix[y + i][x]
    cache[x] = currentSum
    return currentSum










def id36(matrix):
    id6(matrix, 0, 0)
    return matrix


def id6(matrix, row, col):
    currentCol = col
    currentRow = row

    if currentCol == len(matrix[0]):
        currentRow += 1
        currentCol = 0
        if currentRow == len(matrix):
            return True

    if matrix[currentRow][currentCol] == ".":
        return id24(matrix, currentRow, currentCol)

    return id6(matrix, currentRow, currentCol + 1)


def id24(matrix, row, col):
    for i in range(1, 10):
        value = str(i)
        isValid = id44(matrix, row, col, value)
        if isValid:
            matrix[row][col] = value
            if id6(matrix, row, col + 1):
                return True
    matrix[row][col] = "."
    return False


def id44(matrix, row, col, value):
    id1 = value in matrix[row]
    id15 = value in map(lambda r: r[col], matrix)

    
    
    
    

    if id1 or id15:
        return False

    currentRow = row // 3
    currentCol = col // 3

    for rowIdx in range(3):
        for colIdx in range(3):
            id17 = currentRow * 3 + rowIdx
            id50 = currentCol * 3 + colIdx
            if matrix[id17][id50] == value:
                return False
    return True














































def id30(minHeap, visited):
    currentNode, minDistance = minHeap.remove()
    while(currentNode in visited):
        currentNode, minDistance = minHeap.remove()
    return currentNode, minDistance





class DSFU:
    def __init__(self, id9):
        self.parentArray = {i: -1 for i in range(1, id9 + 1)}

    def findOperation(self, vertexOne, vertexTwo):
        id5 = self.findHelper(vertexOne)
        id27 = self.findHelper(vertexTwo)
        return (id5, id27)

    def findHelper(self, vertex):
        currentNode = vertex
        if self.parentArray[currentNode] == -1:
            return currentNode
        returnedNode = self.findHelper(self.parentArray[currentNode])
        self.parentArray[currentNode] = returnedNode
        return returnedNode

    def unionOperation(self, vertexOne, vertexTwo):
        id5, id27 = self.findOperation(vertexOne, vertexTwo)
        if id5 != id27:
            self.parentArray[id5] = id27
            return False
        return True


def id37(edges):
    id9 = len(edges)
    dsfu = DSFU(id9)
    result = set()
    for path, toPath in edges:
        containsCycle = dsfu.unionOperation(path, toPath)
        if containsCycle:
            result.add((path, toPath))
    return result


t = int(input())
for i in range(t):
    n = int(input())
    id42 = math.floor(n * (2 / 3));
    id42 = id42 + id42 % 2;
    print(n - id42, int(id42 / 2))