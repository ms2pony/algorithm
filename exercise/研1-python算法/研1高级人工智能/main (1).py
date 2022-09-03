#!/usr/bin/env python 
# -*- coding:utf-8 -*-
import numpy as np
import math
import random
import time as t

def G2D(G):
# %UNTITLED 此处显示有关此函数的摘要
# %   此处显示详细说明 计算每个栅格至各自邻域无障碍栅格代价值的子函数
    llen=len(G)
# %D是所有点到所有点的矩阵。纵向将所有点作为起点，横向将所有点作为邻域局部到达点
    D=np.zeros((llen*llen,llen*llen))
    for i in range(llen):
        for j in range(llen):
            if G[i][j] == 0:
                for m in range(llen):
                    for n in range(llen):
                        if G[m][n] == 0:
                            im = abs(i - m)
                            jn = abs(j - n)
                            if ((im + jn == 1) | ((im == 1) & (jn == 1))):
                                D[ i * llen + j][m * llen + n] = pow((im + jn) , 0.5)
    return D


if __name__ == '__main__':
    G = [[0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0],
         [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0],
         [1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0]]
    MM=len(G)
    # Tau = np.ones((MM * MM, MM * MM))
    # Tau = [x * 8 for x in Tau]
    Tau = []
    for i in range(MM * MM):
        templistTau = []
        for j in range(MM * MM):
            templistTau.append(8)
        Tau.append(templistTau)
    # print(Tau)
    K = 100  # 迭代次数（指蚂蚁出动多少波）100
    M = 50  # 蚂蚁个数
    S = 1  # 最短路径的起始点
    E = MM * MM  # 最短路径的目的点
    Alpha = 1  # Alpha 表征信息素重要程度的参数
    Beta = 7  # Beta 表征启发式因子重要程度的参数
    Rho = 0.3  # Rho 信息素蒸发系数
    Q = 1  # Q 信息素增加强度系数
    minkl = float('inf')
    mink = 0
    minl = 0
    D = G2D(G)
    # print(D)
    N = len(D)  # N表示问题的规模（象素个数）  #37-59行计算终止栅格点的横纵坐标值
    a = 1  # 小方格象素的边长
    Ex = a * ((E%MM) - 0.5)  # 终止点横坐标
    if Ex==-0.5:
        Ex = MM - 0.5
    Ey = a * (MM + 0.5 - math.ceil(E / MM)) # 终止点纵坐标
    Eta = np.zeros(N)  # 启发式信息，取为至目标点的直线距离的倒数   #一维
    # 以下启发式信息矩阵 #构建启发式信息矩阵。（MM，MM）为终止点的坐标值，计算每个栅格至终点的信息素量
    for i in range (1,N+1):
        ix = a * ((i%MM) - 0.5)
        if (ix == -0.5):
            ix = MM - 0.5
        iy = a * (MM + 0.5 - math.ceil(i / MM))
        if i!=E:
            Eta[i-1] = 1 / pow((pow((ix - Ex) , 2) + pow((iy - Ey) , 2)) , 0.5)
        else:
            Eta[i-1] = 100
    # 用3维list存储每一代的每一只蚂蚁的爬行路线
    ROUTES = []
    for i in range (K):
        templistK = []
        for i in range(M):
            templistM = []
            templistK.append(templistM)
        ROUTES.append(templistK)
    PL = np.zeros((K, M))  #用矩阵存储每一代的每一只蚂蚁的爬行路线长度
    # 启动K轮蚂蚁觅食活动，每轮派出M只蚂蚁
    iterate = 0
    print("start walk!")
    for k in range(K):
        for m in range(M):
            # 状态初始化
            W = S  # 当前节点初始化为起始点
            Path = [S] # 爬行路线初始化------------这里定义为List
            PLkm = 0  # 爬行路线长度初始化
            TABUkm = np.ones(N)  # 禁忌表初始化。禁忌表记录走过的位置，将走过的位置由1变0 #一维
            TABUkm[S-1] = 0  # 已经在初始点了，因此要排除    #注意从0开始
            DD = D.copy()  # 邻接矩阵初始化
            # 下一步可以前往的节点
            DW = DD[W-1].copy()
            DW1 = [x+1 for x in range (len(DW)) if DW[x]!=0]   #W节点可选择的所有节点有对角关系的，也有
            # print(DW1)
            for j in range (len(DW1)):
                if TABUkm[int(DW1[j]-1)] == 0:
                    DW[int(DW1[j]-1)] = 0                                     #??????????????
            LJD = [x+1 for x in range (len(DW)) if DW[x]!=0]   #lsit  # lsit LJD记录未走过的点的索引号
            Len_LJD = len(LJD)  # 可选节点的个数
            # 蚂蚁未遇到食物或者陷入死胡同或者觅食停止
            while ((W!=E)&(Len_LJD>=1)):
            #转轮赌法选择下一步怎么走
                PP = np.zeros(Len_LJD)     #--------PP应该是一维的吧？
                sumpp = 0
                for i in range(Len_LJD):
                    PP[i] = (pow(Tau[W-1][LJD[i]-1] , Alpha)) * (pow((Eta[LJD[i]-1]) , Beta))
                    sumpp = sumpp+PP[i]
                for i in range(Len_LJD):
                    PP[i] = PP[i]/sumpp
                Pcum = [PP[0]]  #轮盘赌为依据的数组
                for i in range (1,Len_LJD):
                    Pcum.append(Pcum[i-1]+PP[i])
                # print(PP)
                Select = [x for x in range (len(Pcum)) if Pcum[x]>=random.random()] #轮盘赌
                to_visit = LJD[Select[0]]
                # print("to_visit",to_visit)
                # 状态更新和记录
                Path.append(to_visit)   #路径增加
                PLkm = PLkm + DD[W-1][to_visit-1]  # 路径长度增加
                W = to_visit  # 蚂蚁移到下一个节点
                for kk in range(N):
                    if TABUkm[kk] == 0:
                        DD[W-1][kk] = 0
                        DD[kk][W-1] = 0
                TABUkm[W-1] = 0         #已访问过的节点从禁忌表中删除
                DW = DD[W-1].copy()
                DW1 = [x+1 for x in range (len(DW)) if DW[x]!=0]  # list
                # print(DW1)
                for j in range(len(DW1)):
                    if TABUkm[int(DW1[j]-1)] == 0:
                        DW[j] = 0
                LJD = W1 = [x+1 for x in range (len(DW)) if DW[x]!=0]  # lsit  # lsit LJD记录未走过的点的索引号
                Len_LJD = len(LJD)  # 可选节点的个数

            #记下每一代每一只蚂蚁的觅食路线和路线长度
            # print(Path)
            ROUTES[k][m] = Path.copy()
            if Path[-1] == E:
                PL[k][m] = PLkm
                if PLkm < minkl:
                    mink = k
                    minl = m
                    minkl = PLkm
            else:
                PL[k][m] = 0
        #更新信息素
        Delta_Tau = np.zeros((N, N))  # 更新量初始化
        for m in range(M):
            if PL[k][m]:
                ROUT = ROUTES[k][m].copy()
                TS = len(ROUT) - 1  # 跳数
                PL_km = PL[k][m]
                for s in range(TS):
                    x = ROUT[s]
                    y = ROUT[s+1]
                    Delta_Tau[x-1][y-1] = Delta_Tau[x-1][y-1] + Q / PL_km
                    Delta_Tau[y-1][x-1] = Delta_Tau[y-1][x-1] + Q / PL_km
            # print(Tau)
        for i in range (N):
            for j in range(N):
                Tau[i][j] = (1 - Rho)* Tau[i][j] + Delta_Tau[i][j]  #信息素挥发一部分，新增加一部分
        print("schedule:", k + 1)


    print(ROUTES)
    print(PL)

    import matplotlib.pyplot as plt

    print("start plot!")
    plt.rcParams['font.family'] = ['SimHei']  # 显示中文
    minPL = np.zeros(K)
    for i in range(K):
        PLK = PL[i]
        Nonzero = [x for x in range (len(PLK)) if PLK[x]!=0]
        PLKPLK = [PLK[x] for x in Nonzero]
        if len(PLKPLK)==0:
            minPL[i] = 0
        else:
            minPL[i] = min(PLKPLK)
    plt.figure(1)
    plt.plot(minPL);
    plt.title('收敛曲线变化趋势');
    plt.xlabel('迭代次数');
    plt.ylabel('最小路径长度')
    plt.savefig("figure1.png")

    # 绘爬行图
    plt.figure(2)
    # plt.axis([0, MM, 0, MM])
    new_ticks = np.linspace(0, MM, MM+1)
    plt.xticks(new_ticks)
    plt.yticks(new_ticks)
    for i in range(1,MM+1):
        for j in range(1,MM+1):
            if G[i-1][j-1] == 1:
                x1 = j-1
                y1 = MM-i
                x2 = j
                y2 = MM - i
                x3 = j
                y3 = MM - i + 1
                x4 = j - 1
                y4 = MM - i + 1
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
    plt.savefig("figure2.png")
    plt.show()
    print("plot finished!")
    #     end
    #     plotif2 = 0 % 绘各代蚂蚁爬行图
    #     if plotif2 == 1
    #         figure(3)
    #     axis([0, MM, 0, MM])
    #     for i=1:MM
    #     for j=1:MM
    #     if G(i, j) == 1
    #         x1 = j - 1
    #         y1 = MM - i
    #     x2 = jy2 = MM - i
    #     x3 = jy3 = MM - i + 1
    #     x4 = j - 1
    #     y4 = MM - i + 1
    #     fill([x1, x2, x3, x4], [y1, y2, y3, y4], [0.2, 0.2, 0.2])
    #     hold
    #     on
    #     else
    #     x1 = j - 1
    #     y1 = MM - i
    #     x2 = jy2 = MM - i
    #     x3 = jy3 = MM - i + 1
    #     x4 = j - 1
    #     y4 = MM - i + 1
    #     fill([x1, x2, x3, x4], [y1, y2, y3, y4], [1, 1, 1])
    #     hold
    #     on
    #     end
    #     end
    # end
    # for k=1:K
    # PLK = PL(k,:)
    # minPLK = min(PLK)
    # pos = find(PLK == minPLK)
    # m = pos(1)
    # ROUT = ROUTES
    # {k, m}
    # LENROUT = length(ROUT)
    # Rx = ROUT
    # Ry = ROUT
    # for ii=1:LENROUT
    # Rx(ii) = a * (mod(ROUT(ii), MM) - 0.5)
    # if Rx(ii) == -0.5
    #     Rx(ii) = MM - 0.5
    # end
    # Ry(ii) = a * (MM + 0.5 - ceil(ROUT(ii) / MM))
    # end
    # plot(Rx, Ry)




