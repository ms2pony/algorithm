from timeit import default_timer as timer
def linear_search(li,val):
    for ind,v in enumerate(li):
        if v == val:
            return v
    else:
        return None

list = list(range(100000))
t1=timer()
linear_search(list,20000)
t2=timer()
print(t2-t1)