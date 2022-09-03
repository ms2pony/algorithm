import random as rd

def partition(li,left,right):
    tmp = li[left]
    while left < right: #right和left下标之间只有一个元素或无元素停止
        while left < right and tmp <= li[right]:
            right -=1
        li[left] = li[right]
        print(li)
        while left < right and tmp >= li[left]:
            left +=1
        li[right] = li[left]
        print(li)
    li[left] = tmp
    print(li)
    return left

li = [rd.randint(108,2222) for i in range(30)]
# print(li)
# quickSort(li,0,len(li)-1)

def quickSort(li,left,right):
    if left < right:
        mid = partition(li, left, right)
        quickSort(li, left, mid-1)
        quickSort(li,mid+1,right)

quickSort(li,0,len(li)-1)
