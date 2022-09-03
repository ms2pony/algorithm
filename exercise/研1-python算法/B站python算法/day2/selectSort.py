import random as rd

def selectSort(li):
    li1 = []
    for i in range(len(li)):
        minv = min(li)
        li1.append(minv)
        li.remove(minv)
    return li1

li = [rd.randint(2,8888) for i in range(30)]
print (li)
print (selectSort(li))