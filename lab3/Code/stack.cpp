#include <iostream>
#include <sstream>
using namespace std;
#define MAXSIZE 100
typedef int DataType;
typedef int Status;
#define OK 1;
#define ERROR 0;
typedef  struct {
    DataType* base;
    DataType* top;
    int stacksize;
}SeqStack;

// 扩展栈大小
/*Status ExStack(SeqStack &S) {
    DataType* newbase = new DataType[S.stacksize + 10]; // 假设每次扩展10个元素的空间
    if (!newbase) {
        cerr << "内存分配失败，无法扩展栈空间" << endl;
        return ERROR;
    }
    // 将原栈中的元素复制到新栈中
    for (int i = 0; i < S.stacksize; ++i) {
        newbase[i] = S.base[i];
    }
    // 释放原栈空间
    delete[] S.base;
    // 更新栈指针和栈大小
    S.base = newbase;
    S.top = S.base + S.stacksize;
    S.stacksize += 10;
    return OK;
}*/

// 判断该栈是否被初始化
bool isInit(SeqStack &S) {
    bool flag = false;
    if (S.base != NULL) {
        flag = true;
    }
    return flag;
} 

// 初始化栈
Status InitStack(SeqStack &S) {
    S.base = new DataType[MAXSIZE];
    S.top = S.base;
    S.stacksize = MAXSIZE;
    cout << "已完成初始化" << endl;
    return OK;
}

// 置空该栈
int ClearStack(SeqStack &S) {
    if (!isInit(S)) {
        cout << "该栈还未初始化,请先将其初始化" << endl;
        return ERROR;
    } else {
        S.top = S.base;
        cout << "已将栈置空" << endl;
        return 0;
    }
}

// 判定顺序栈是否为空
bool StackEmpty(SeqStack S) {
    if (!isInit(S)) {
        cout << "该栈还未初始化,请先将其初始化" << endl;
        return ERROR;
    } else {
        if (S.top == S.base) {
            cout << "该栈为空" << endl;
        } else {
            cout << "该栈非空" << endl;
        }
        return OK;
    }
}

// 求顺序栈的长度
int StackLength(SeqStack S) {
    if (!isInit(S)) {
        cout << "该栈还未初始化,请先将其初始化" << endl;
        return ERROR;
    } else {
        cout << "该顺序栈的长度为" << S.top - S.base << endl;
        return OK;
    }
}

// 求栈顶元素
Status GetTop(SeqStack S, DataType &e) {
    if (!isInit(S)) {
        cout << "该栈还未初始化,请先将其初始化" << endl;
        return ERROR;
    } else {
        if (S.top == S.base) {
            cout << "该栈已为空" << endl;
            return ERROR;
        }
        else {
        e = *(S.top - 1);
        return OK;
        }
    }
}

// 入栈
Status  Push(SeqStack& S, DataType e) {
    if (!isInit(S)) {
        cout << "该栈还未初始化,请先将其初始化" << endl;
        return ERROR;
    } else {
        if (S.top - S.base == S.stacksize) {return ERROR;}
        else {
            *S.top++ = e;
            return OK;
        }
    }
}

// 出栈，并输出出栈元素
Status  Pop(SeqStack& S, DataType& e) {   
// 若栈不空，则删除S的栈顶元素，用e返回其值，
// 并返回OK; 否则返回ERROR
    if (!isInit(S)) {
        cout << "该栈还未初始化,请先将其初始化" << endl;
        return ERROR;
    } else {
        if (S.top == S.base) {return ERROR;}
        else {
            e = *--S.top;
            return OK;
        }
    }   
}

//输出栈内元素
Status Output(SeqStack S) {   
    //若栈不空，则删除S的栈顶元素，用e返回其值，
    //并返回OK; 否则返回ERROR
    if (!isInit(S)) {
        cout << "该栈还未初始化,请先将其初始化" << endl;
        return ERROR;
    } else {
        if (S.top == S.base) {return ERROR;}
        else {
            cout << "栈中元素为：";
        while (S.top != S.base) {
            cout << *--S.top << " ";
        }
        cout << endl;
        return OK;
        }
    }
}

// 创建并输入栈元素
Status CreateStack(SeqStack& S) {
    // 初始化栈
    InitStack(S);
    // 输入栈元素
    int data;
    cout << "请输入栈元素：" << endl;
    string line;
    cin.ignore();
    getline(cin, line);
    cout << line << endl;
    stringstream ss(line);
    while (ss >> data) {
        // 判断栈是否已满
        if (S.top - S.base >= S.stacksize) {
            // 栈满，扩展栈空间
            cout << "该栈已满，无法输入更多元素" << endl;
            return ERROR;
        } else {
            // 将元素压入栈中
            *(S.top++) = data;
        }
    }
    /*cin >> data;
    while (data != -1) {
        *(S.top++) = data;
        cin >> data;
    }*/
    cout << "成功创建" << endl;
    return OK;
}

//销毁栈
Status DestroyStack(SeqStack& S) {   
    if (S.base == NULL) {
        cout << "该栈还未初始化,请先将其初始化" << endl;
        return ERROR;
    } else{
        delete[] S.base;
        S.stacksize = 0;
        S.base = S.top = NULL;
        cout << "栈已销毁" << endl;
        return OK;
    }
}


// 打印'*'
void cout_star(){
    for(int i = 0;i < 15;i++){
        cout << '*';
    }
}

// 打印提示信息
void show_help(){
    int maxNumMsg = 12;
    // star_NUM = 15,30,15
    for(int i = 0;i < 4;i++){
        cout_star();
    }
    cout << endl;

    string s[maxNumMsg] = {
        "    1.初始化为空栈            ",
        "    2.销毁栈                  ", 
        "    3.将栈置空                ",
        "    4.判断栈是否为空栈        ",
        "    5.返回栈的长度            ",
        "    6.求栈顶元素              ",
        "    7.入栈                    ",
        "    8.出栈                    ",
        "    9.输出栈内元素            ",
        "    10.创建并输入栈元素       ",
        "    11.退出                   ",
        "    12.数制转换               "
    };

    for(int i = 0; i < maxNumMsg; i++){
        cout_star();
        cout << s[i];
        cout_star();
        cout << endl;
    }

    for(int i = 0;i < 4;i++){
        cout_star();
    }
    cout << endl;
}

// 十进制转二进制
void O2B(int num) {
    int t = num;
    SeqStack s;
    InitStack(s);
    while (num != 0) {
        Push(s,num % 2);
        num /= 2;
    }
    // Output(s);
    cout << "数字" << t << "的二进制形式为：";
    while (s.top != s.base) {
        cout << *--s.top << " ";
    }
    cout << endl;
}

// 主函数
int main()
{
    show_help();
    int chioce;
    SeqStack S;
    S.base = S.top = NULL;
    S.stacksize = 0;
    while (1)
    {   
        cout << "请输入选择：" ;
        cin >> chioce;
        switch (chioce)
        {
        case 1:
            InitStack(S);
            break;
        case 2:
            DestroyStack(S);
            break;
        case 3:
            ClearStack(S);
            break;
        case 4:
            StackEmpty(S);
            break;
        case 5:
            StackLength(S);
            break;
        case 6:
            DataType e;
            if (GetTop(S, e)) {
                cout << "栈顶元素为：" << e << endl;
            }
            break;
        case 7:
            cout << "请输入要入栈的元素：";
            cin >> e;
            if (Push(S, e)) {
                cout << "元素" << e << "已入栈" << endl;
            }
            break;
        case 8:
            if (Pop(S,e)) {
                cout<<"元素" << e <<"已出栈" << endl;
            }
            break;
        case 9:
            Output(S);
            break;
        case 10:
            CreateStack(S);
            break;
        case 11:
            exit(0);
            break;
        case 12:
            int num;
            cout << "请输入想转换的十进制整数:";
            cin >> num;
            O2B(num);
        default:
            break;
        }
    }
    return 0;
}
