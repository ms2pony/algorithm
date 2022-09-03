def hanoi(n,a,b,c):
    if n>0:
        hanoi(n-1,b,a,c)
        print("moving %s to %s!"%(a,b))
        hanoi(n-1,a,c,b)

hanoi(3,'A','B','C')
