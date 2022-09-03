import time

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

def linear_search(li,val):
    for ind,v in enumerate(li):
        if v == val:
            return v
    else:
        return None

list = list(range(10000))

t1=time.time()
linear_search(list,8000)
t2=time.time()

print("linear_search:%d",t2-t1)

t1=time.time()
binary_search(list,8000)
t2=time.time()
print("binary_search:%d",t2-t1)