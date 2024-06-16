# MakeFile文件格式
# 目标(Target)： 依赖(Dependencies)
# 命令(Commands)

# 定义编译器
CC=g++

# 定义目标文件
TARGET1=../Bin/stack
TARGET2=../Bin/queue

# 定义源文件
SRC1=stack.cpp
SRC2=queue.cpp

# 默认编译两个文件
all: $(TARGET1) $(TARGET2)

# 编译Stack.cpp
$(TARGET1): $(SRC1)
	$(CC) $(SRC1) -o $(TARGET1)

# 编译queue.cpp
$(TARGET2): $(SRC2)
	$(CC) $(SRC2) -o $(TARGET2)

# 清理可执行文件
clean:
	rm -f $(TARGET1) $(TARGET2)

# 测试栈功能
test1:
	$(TARGET1)

# 测试队列功能
test2:
	$(TARGET2)

# .PHONY用来声明为伪目标
# 即执行make all或make clean或make test1或make test2时
# make程序直接执行命令而非寻找all文件或clean文件或test1文件或test2文件
.PHONY: all clean test1 test2
