# 已经实现的功能
# 1.有文件和目录之分
# 2.就算输入的文件或者目录末尾没有加"/"也不会出错
# 3.__repr__的类内置函数可以格式化输出Node,也就是说只会输出该节点的名字属性
# 4.cd可以输入绝对路径，也可以输入当前路径
# 5.实现了cd、mkdir、mkfile、ls这四个函数
#
# 待改进的点
# 1.可以实现一个pwd的函数
# 2.可以设置一个界面,打开这个脚本，直接在控制台输入命令就行，这样好测试
class Node:
    """定义一个文件或者目录对象"""
    # 名字，父节点，子节点
    def __init__(self,name,type):
        self.name = name
        self.parent = None
        self.children=[]
        self.type = type
    def __repr__(self):
        return self.name

class File_System:
    """由数个Node类型的文件或者目录按一定规则组成的文件系统"""
    # 头节点\,有一个当前位置的属性,还有一个名字(名字随意取)
    def __init__(self,name):
        self.root = Node("/","directory")
        self.now = self.root
        self.name = name

tc_file_System = File_System("tc_ubuntu")

def mkdir(name):
    """创建目录的函数"""
    # 输入应该是目录名加“/”
    if(name[-1] !="/"):
        name+="/"
    node = Node(name[0:-1],"directory")
    tc_file_System.now.children.append(node)
    node.parent = tc_file_System.now

def ls():
    return tc_file_System.now.children

def mkfile(name):
    """创建文件的函数"""
    # 输入应该是文件名加“/”
    if (name[-1] != "/"):
        name+="/"
    node = Node(name[0:-1], "file")
    tc_file_System.now.children.append(node)
    node.parent = tc_file_System.now

def cd(name):
    node = Node(name,"directory")
    for d_f in tc_file_System.now.children:
       if(node.name == d_f.name and d_f.type == 'directory'):
           tc_file_System.now = d_f
           return
    ValueError("找不到该目录")

mkdir("var")
mkdir("etc")
mkdir("boot")
mkdir("usr")
cd("usr")
print(ls())
mkdir("tancong")
cd("tancong")
mkfile("test.c")
mkfile("nihao.c")
print(ls())
