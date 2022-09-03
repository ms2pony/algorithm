from timeit import default_timer as timer

def binary_search(li,val):
    left=0
    right=len(li)-1
    while left <= right:
        mid = (left + right)//2
        if li[mid] == val:
            return mid+1
        elif li[mid] < val:
            left = mid + 1
            mid = (left + right)//2
        else:
            right = mid -1
            mid = (left + right) // 2
    else:
        return None

list = list(range(100000))
t1=timer()
binary_search(list,20000)
t2=timer()
print(t2-t1)


