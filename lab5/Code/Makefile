# MakeFile文件格式
# 目标(Target)： 依赖(Dependencies)
# 命令(Commands)

# 定义编译器
CC=g++

# 定义目标文件
TARGET=../Bin/graph

# 定义源文件
SRC=graph.cpp

# 编译graph.cpp,默认行为
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

# 清理可执行文件
clean:
	rm -f $(TARGET)

# 运行可执行程序
test:
	$(TARGET)

# .PHONY用来声明为伪目标
# 即执行make clean或make test时，make程序直接执行命令而非寻找clean或test文件
.PHONY: clean test
