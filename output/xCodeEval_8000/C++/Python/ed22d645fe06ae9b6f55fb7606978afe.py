import sys

def LIS(n, a):
    b = []
    b.append(a[0])
    for i in range(1, n):
        if b[-1] < a[i]:
            b.append(a[i])
        else:
            b[lower_bound(b, a[i])] = a[i]
    return len(b)

def lower_bound(arr, target):
    left = 0
    right = len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
