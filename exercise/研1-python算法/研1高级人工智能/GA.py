import numpy as np
import random
import matplotlib.pyplot as plt
import math

class GA(object):
    def __init__(self, population_size, chromosome_length, pc, pm):

        self.population_size = population_size
        self.choromosome_length = chromosome_length
        self.pc = pc
        self.pm = pm

    def species_origin(self):
        population = [[]]
        for i in range(self.population_size):

            temporary = []
            # 染色体暂存器
            for j in range(self.choromosome_length):
                temporary.append(random.randint(0, 1))
            # 随机产生一个染色体,由二进制数组成
            population.append(temporary)
            # 将染色体添加到种群中
        return population[1:]
        # 将种群返回，种群是个二维数组，个体和染色体两维

    # 从二进制到十进制
    # 编码  input:种群,染色体长度 编码过程就是将多元函数转化成一元函数的过程
    def translation(self, population):
        temporary = []
        for i in range(len(population)):
            total = 0
            for j in range(self.choromosome_length):
                total += population[i][j] * (math.pow(2, j))
            # 从第一个基因开始，每位对2求幂，再求和
            # 如：0101 转成十进制为：1 * 20 + 0 * 21 + 1 * 22 + 0 * 23 = 1 + 0 + 4 + 0 = 5
            temporary.append(total)
        # 一个染色体编码完成，由一个二进制数编码为一个十进制数
        return temporary

    # 返回种群中所有个体编码完成后的十进制数
    def function(self, population):
        function1 = []
        temporary = self.translation(population)
        for i in range(len(temporary)):
            x = temporary[i] * 10 / (math.pow(2, self.choromosome_length) - 1)
            function1.append(10 * math.sin(5*x) + 7*abs(x-5)+10)
        return function1

    def btoten(self, population):
        function1 = []
        temporary = self.translation(population)
        for i in range(len(temporary)):
            x = temporary[i] * 10 / (math.pow(2, self.choromosome_length) - 1)
            function1.append(x)
        return function1

    # 定义适应度
    def fitness(self, function1):
        fitness_value = []
        num = len(function1)
        for i in range(num):
            fitness_value.append(function1[i])
        # 将适应度添加到列表中
        return fitness_value

    # 计算适应度和
    def sum(self, fitness_value):
        total = 0
        for i in range(len(fitness_value)):
            total += fitness_value[i]
        return total

    # 计算适应度斐伯纳且列表
    def cumsum(self, fitness1):
        for i in range(len(fitness1) - 2, -1, -1):
            # range(start,stop,[step])
            # 倒计数
            total = 0
            j = 0
            while (j <= i):
                total += fitness1[j]
                j += 1

            fitness1[i] = total
            fitness1[len(fitness1) - 1] = 1

    # 选择种群中个体适应度最大的个体
    def selection(self, population, fitness_value):
        new_fitness = []
        # 单个公式暂存器
        total_fitness = self.sum(fitness_value)
        # 将所有的适应度求和
        for i in range(len(fitness_value)):
            new_fitness.append(fitness_value[i] / total_fitness)
        # 将所有个体的适应度正则化
        self.cumsum(new_fitness)
        #
        ms = []
        # 存活的种群
        population_length = pop_len = len(population)
        # 求出种群长度
        # 根据随机数确定哪几个能存活
        for i in range(pop_len):
            ms.append(random.random())
        # 产生种群个数的随机值
        # ms.sort()
        # 存活的种群排序
        fitin = 0
        newin = 0
        new_population = new_pop = population

        # 轮盘赌方式
        while newin < pop_len:
            if (ms[newin] < new_fitness[fitin]):
                new_pop[newin] = population[fitin]
                newin += 1
            else:
                fitin += 1
        population = new_pop

    # 交叉操作
    def crossover(self, population):
        # pc是概率阈值，选择单点交叉还是多点交叉，生成新的交叉个体，这里没用
        pop_len = len(population)

        for i in range(pop_len - 1):

            if (random.random() < self.pc):
                cpoint = random.randint(0, len(population[0]))
                # 在种群个数内随机生成单点交叉点
                temporary1 = []
                temporary2 = []
                temporary1.extend(population[i][0:cpoint])
                temporary1.extend(population[i + 1][cpoint:len(population[i])])
                # 将tmporary1作为暂存器，暂时存放第i个染色体中的前0到cpoint个基因，
                # 然后再把第i+1个染色体中的后cpoint到第i个染色体中的基因个数，补充到temporary2后面
                temporary2.extend(population[i + 1][0:cpoint])
                temporary2.extend(population[i][cpoint:len(population[i])])
                # 将tmporary2作为暂存器，暂时存放第i+1个染色体中的前0到cpoint个基因，
                # 然后再把第i个染色体中的后cpoint到第i个染色体中的基因个数，补充到temporary2后面
                population[i] = temporary1
                population[i + 1] = temporary2
        # 第i个染色体和第i+1个染色体基因重组/交叉完成

    def mutation(self, population):
        # pm是概率阈值
        px = len(population)
        # 求出种群中所有种群/个体的个数
        py = len(population[0])
        # 染色体/个体基因的个数
        for i in range(px):
            if (random.random() < self.pm):
                mpoint = random.randint(0, py - 1)
                #
                if (population[i][mpoint] == 1):
                    # 将mpoint个基因进行单点随机变异，变为0或者1
                    population[i][mpoint] = 0
                else:
                    population[i][mpoint] = 1
    # transform the binary to decimalism
    # 将每一个染色体都转化成十进制 max_value,再筛去过大的值
    def b2d(self, best_individual):
        total = 0
        b = len(best_individual)
        for i in range(b):
            total = total + best_individual[i] * math.pow(2, i)
        total = total * 10 / (math.pow(2, self.choromosome_length) - 1)
        return total

    # 寻找最好的适应度和个体
    def best(self, population, fitness_value):

        px = len(population)
        bestindividual = []
        bestfitness = fitness_value[0]
        for i in range(1, px):
            # 循环找出最大的适应度，适应度最大的也就是最好的个体
            if (fitness_value[i] > bestfitness):
                bestfitness = fitness_value[i]
                bestindividual = population[i]

        return [bestindividual, bestfitness]

    def main(self):
        results = [[]]
        population = self.species_origin()
        for i in range(500):
            function_value = self.function(population)
            fitness_value = self.fitness(function_value)
            best_individual, best_fitness = self.best(population, fitness_value)
            results.append([best_fitness, self.b2d(best_individual)])
            # 将最好的个体和最好的适应度保存，并将最好的个体转成十进制,适应度函数
            self.selection(population, fitness_value)
            self.crossover(population)
            self.mutation(population)
        x1=self.btoten(population)
        y1=self.function(population)
        #   一元函数曲线绘制
        x = np.arange(0, 10, 0.01)
        y = 10 * np.sin(5 * x) + 7 * abs(x - 5) + 10
        plt.plot(x, y)

        plt.plot(x1, y1, '*b')
        plt.plot(results[499][1], results[499][0], '*r')
        plt.savefig("GAfigure.png")
        plt.show()
        print("最好的结果为：x="+str(results[499][1])+",y="+str(results[499][0]))


if __name__ == '__main__':
    population_size = 1000
    chromosome_length = 10
    pc = 0.6
    pm = 0.01
    ga = GA(population_size, chromosome_length, pc, pm)
    ga.main()