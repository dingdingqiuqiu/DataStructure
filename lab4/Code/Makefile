# MakeFile文件格式
# 目标(Target)： 依赖(Dependencies)
# 命令(Commands)

# 定义编译器
CC=g++

# 定义目标文件
TARGET1=../Bin/2Tree
TARGET2=../Bin/huffman

# 定义源文件
SRC1=2Tree.cpp
SRC2=huffman.cpp

# 默认编译两个文件
all: $(TARGET1) $(TARGET2)

# 编译2Tree.cpp
$(TARGET1): $(SRC1)
	$(CC) $(SRC1) -o $(TARGET1)

# 编译huffman.cpp
$(TARGET2): $(SRC2)
	$(CC) $(SRC2) -o $(TARGET2)

# 清理可执行文件
clean:
	rm -f $(TARGET1) $(TARGET2)

# 测试二叉树功能
test1:
	$(TARGET1)

# 测试huffman树功能
test2:
	$(TARGET2)

# .PHONY用来声明为伪目标
# 即执行make all或make clean或make test1或make test2时
# make程序直接执行命令而非寻找all文件或clean文件或tets1文件或test2文件
.PHONY: all clean test1 test2
