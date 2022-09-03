#1.可以将字符串中特定的符号去掉的方法

import math #数学库，导入后可以执行很多专业数学运算
import numpy as np #数据处理库，导入后可以执行很多专业数学运算，比如矩阵运算
import subfile as sb #自己写的库，实现了邻接矩阵的生成
import random

f = open("test") #文件操作，这种不太规范，建议去网上参考文件操作规范代码
data=[] #列表声明，虽然python大部分可以不声明变量，但是这个时候还是得声明一下，因为第13行要用到list的append方法
temp=[]
for line in f:  #默认从f中依次读取一行，每次迭送一行
    for j in line:  #默认每次跌送一个字符
        if j=='0' or j=='1':
            temp.append(int(j)) #int函数将字符转换成int类型
    data.append(temp)  #与前面的append不同，这里是将一个list放入data这个list中，所以list可以存放list 
    temp=[]
f.close()

G = np.array(data)  #将data这个二维的列表（因为该列表含有子列表），转换成2维矩阵，需要导入numpy库，这是一个numpy类型的二维数组（矩阵），不是普通二维数组，可以使用numpy中的方法
MM = G.shape[0] #shape方法就是numpy数组中特有的方法，它可以返回n维矩阵的行，和列，shape[0]表示行数，1表示列，如果是高维矩阵那就还有shape[2]
Tau = np.ones([MM*MM,MM*MM])    #numpy中的全1元素生成的方法，参数是行数和列数
Tau=8*Tau   #矩阵的普通数乘直接乘数字就行了
K=100   
S=1
M=50
E=MM*MM
Alpha=1
Beta=7
Rho=0.3
Q=1
minkl = float("inf")    #float("inf")可以表示无穷大，并赋值给一个变量
mink = 0
minl = 0
D=sb.G2D(G) #将G矩阵（表示地图）输入，输出关于G的邻接矩阵，该函数由另一个模块实现了
N = D.shape[0]  #返回D的行数
a=1
Ex= a*((E%MM)-0.5)
if Ex == -0.5:
    Ex=MM-0.5
Ey=a*(MM+0.5 - math.ceil(E/MM)) #ceil是math库中向上取整方法
Eta=np.zeros(N) #0元素矩阵生成方法
#qifashixinxijvzhen
for i in range(N):
    ix = a *(i%MM-0.5)
    if ix == -0.5:
        ix = MM-0.5
    iy = a*(MM+0.5-math.ceil((i/MM)))
    if i !=E:
        Eta[i]=1/((ix-Ex)**2+(iy-Ey)**2)*0.5
    else:
        Eta[i]=100
ROUTES=np.array([K,M])  #array方法生成一个矩阵，有多个可选的参数，第一个参数是shape，若shape=[3.4]，则会生成一个3*4矩阵
PL = np.zeros((K,M))

for k in range(K):  # i in set 语句中set不能是int类型，如果是int类型，必须使用range，所以set是int类型，就应该这样 for i in range(len)
    for m in range(M):
        W=S
        Path=S
        PLkm=0
        TABUkm=np.ones(N)
        TABUkm[S]=0
        DD=D
        DW=DD[W,:]  #numpy数组，D[W,:]就表示D的第W行，D[i]只是表示矩阵D中的一个元素
        DW1=[]
        for count in range(len(DW)):
            if DW[count] !=0:
               DW1.append(DW[count])
        for j in range(len(DW1)):
            if TABUkm(DW1(j)) == 0:
                DW[DW1[j]]=0    #原来matlab第77行
        LJD = [x for x in range(len(DW)) if DW[x]!=0]  
        Len_LJD = len(LJD);  #可选节点数
        
        while W != EE and Len_LJD>=1:
            PP = np.zeros(Len_LJD)
            
            for i in range(Len_LJD):
                PP(i) = (Tau(W,LJD(i))**Alpha)*((Eta(LJD(i)))**Beta)
                
            sumpp = sum(PP)
            PP = PP/sumpp
            Pcum(1) = PP(1)
                for i in range(1:range(Len_LJD)):
                    Pcum(i) = Pcum(i-1) + PP(i)
            Select = [x for x in range(len(Pcum)) if Pcum(x)>=random.random()]
            to_visit = LJD[Select[i]]
                
            Path = [Path,to_visit]
            PLkm = PLkm+DD[W,to_visit]
            
            W = to_visit
            for kk in range(N):
                if TABUkm[kk] == 0
                    DD[W,kk] = 0
                    DD[kk,W] = 0
            TABUkm(w) = 0
            
            DW=DD[W,:]
                DW1=[x for x in range(len(DW)) if DW[x]!=0]
            for j in range(DW1):
                if TABUkm[DW1[j]] == 0:
                    DW[j] = 0
            LJD=[x for x in range(len(DW)) if DW[x]!=0]
            Len_LJD = len(LJD)
            
        ROUTES(k,m) = Path
        if Path[-1] == E:
            PL[k,m] = PLkm
            if PLkm<minkl:
                mink = k
                minl = m
                minkl = PLkm
        else: v   ;
            PL(k,m) = 0

    Delta_Tau = np.zeros[N,N]

    for m in range(len(M)):
        if PL[k,m]:
            ROUT = ROUTES(k,m)
            TS = len(ROUT)-1
            PL_km = PL[k,m]
            for s in range(len(TS)):
                x = ROUT[s]
                y = ROUT[s+1]
                Delta_Tau[x,y] = Delta_Tau[x,y]+Q/PL_km
                Delta_Tau[y,x] = Delta_Tau[y,x]+Q/PL_km
    Tau = np.dot(1-Rho,Tau)+Delta_Tau

#绘图
import matplotlib.pyplot as plt

plotif = 1
if plotif == 1:
    minPL = np.zeros(K)
    for i in range(K):
        PLK = PL(i,:)
        Nonezero = [x for x in range(len(PLK)) if PLK[x]!=0]
        PLKPLK = PLK(Nonezero)
        minPL(i) = min(PLKPLK)
    plt.figure(1)
    plt.plot(minPL)
    plt.title('收敛曲线变化趋势')
    plt.xlabel('迭代次数')
    plt.ylabel('最小路径长度')
    #绘制爬行图
    plt.figure(2)
    # plt.axis([0,MM,0,MM])
    new_ticks = np.linspace(0, MM, MM+1)
    plt.xticks(new_ticks)
    plt.yticks(new_ticks)
    for i in range(MM):
        for j in range(MM):
            if G[i,j]==1:
                x1=j-1
                y1=MM-i
                x2=j
                y2=MM-i
                x3=j
                y3=MM-i+1
                x4=j-1
                y4=MM-i+1
                plt.fill([x1, x2, x3, x4], [y1, y2, y3, y4], color = [0.2,0.2,0.2])
            else:
                x1 = j - 1
                y1 = MM - i
                x2 = j
                y2 = MM - i
                x3 = j
                y3 = MM - i + 1
                x4 = j - 1
                y4 = MM - i + 1
                plt.fill([x1, x2, x3, x4], [y1, y2, y3, y4], color = [1,1,1])
plt.title('机器人运动轨迹')
plt.xlabel('坐标x')
plt.ylabel('坐标y')
ROUT = ROUTES[mink][minl].copy()
LENROUT = len(ROUT)
Rx = ROUT.copy()
Ry = ROUT.copy()
for ii in range(LENROUT):
    Rx[ii] = a * ((ROUT[ii]%MM) - 0.5)
    if Rx[ii] == -0.5:
        Rx[ii] = MM - 0.5
    Ry[ii] = a * (MM + 0.5 - math.ceil(ROUT[ii] / MM))
plt.plot(Rx, Ry)
plt.grid()
plt.savefig("main.png")
plt.show()
            
            











