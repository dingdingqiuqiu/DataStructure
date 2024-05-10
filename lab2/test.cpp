#include <iostream>
#include <locale>
#include <codecvt>

void cout_star() {
    // Your implementation of cout_star()
}

void show_help(){
    //15,30,15
    for(int i = 0;i < 4;i++){
        cout_star();
    }
    std::cout << std::endl;

    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    std::wstring s[12] = {
        conv.from_bytes("1.初始化或重置链表"),
        conv.from_bytes("2.销毁链j表"),
        conv.from_bytes("3.链表中数据元素个数"),
        conv.from_bytes("4.所指位序的元素值"),
        conv.from_bytes("5.链表已存在元素的位序"),
        conv.from_bytes("6.请输入元素，求直接前驱"),
        conv.from_bytes("7.请输入元素，求直接后驱"),
        conv.from_bytes("8.请在第i个位置插入元素"),
        conv.from_bytes("9.删除第i个元素"),
        conv.from_bytes("10.输出所输入的链表元素"),
        conv.from_bytes("11.初始化并输入链表元素"),
        conv.from_bytes("12,退出")
    };
    for(int i = 0;i < 12;i++){
        cout_star();
        std::wcout << L"  " << s[i];
        for(int j = 0;j < 28-s[i].length();j++){
            std::wcout << L' ';
        }
        std::wcout << std::endl;
    }

    for(int i = 0;i < 4;i++){
        cout_star();
    }
}

int main(){
    show_help();
    return 0;
}
