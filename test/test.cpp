#include <iostream>
#include <sstream>

int main() {
    //将输入流转换成字符串存储在line变量中，getline默认分隔符是'\n'
    std::string line;
    std::getline(std::cin, line);

    //将字符串line转换成流ssi，以便后续getline()函数的处理
    std::stringstream ssi(line);
    std::string item1, item2;

    //对数据流指定分隔符',',将第一部分存储到item1
    //getline()函数同时改变流的状态，此时流的位置在第一个逗号后
    //继续读取，得到第二部分存储到item2
    std::getline(ssi, item1, ',');
    std::getline(ssi, item2, ',');

    //打印结果
    std::cout << "Item 1: " << item1 << std::endl;
    std::cout << "Item 2: " << item2 << std::endl;

    return 0;
}
