#include <string>
#include <iostream>

int main() {
    //打印提示信息
    std::cout << "请输入一个数字，我会将其分割,并求和：";
    
    //存储输入数字
    int num;
    std::cin >> num;

    //将数字转化成字符串,并分割
    std::string str = std::to_string(num);
    std::cout << "分割结果为：" << std::endl;
    for(int i = 0;i < str.length();i++){
        std::cout << str[i] << std::endl;
    }

    //将字符串转化为数字，并求和
    int sum = 0;
    int num1;
    for(int i = 0;i < str.length();i++){
        //num1 = std::stoi(str);
        //经过上一步，num1将转换回num
        num1 = str[i] - 48;
        sum += num1;
    }
    std::cout << "求和结果为：" << sum;
    return 0;
}
