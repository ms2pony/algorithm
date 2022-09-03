import random as rd

def soap_sort(li):
    j = 0
    while(1):
        flag = 0
        for i in range(len(li)-1-j):
            if(li[i]>li[i+1]):
                flag = 1
                li[i],li[i+1] = li[i+1], li[i] #这是一个好方法要牢记！！
        if(flag == 0):
            return
        j +=1
        print (li)

li = [rd.randint(21,20000) for i in range(20)]
print (li)
soap_search(li)
print (li)
