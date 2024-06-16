# MakeFile文件格式
# 目标(Target)： 依赖(Dependencies)
# 命令(Commands)

# 定义编译器
CC=g++

# 定义目标文件
TARGET=../Bin/LNode

# 定义源文件
SRC=LNode.cpp

# 编译LNode,默认行为
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

# 清理可执行文件
clean:
	rm -f $(TARGET)

# 测试可行性程序正确性
test:
	$(TARGET)

# .PHONY用来声明为伪目标
# 即执行make clean或make test时，make程序直接执行命令而非寻找clean文件或test文件
.PHONY: clean test
