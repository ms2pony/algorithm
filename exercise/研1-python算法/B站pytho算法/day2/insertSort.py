import random as rd

def insertSort(li):
    li1 = []
    for i in range(1,len(li)):
        tmp = li[i]
        j = i - 1
        while j >= 0 and li[j] > tmp:
            li[j+1] = li[j]
            j -= 1
        li[j+1] = tmp
        print(li)   # print函数在循环嵌套中，可以复现整个实验过程！

li = [rd.randint(108,2222) for i in range(30)]
print(li)
insertSort(li)
