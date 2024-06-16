#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
typedef int Elemtype;

#define MAXSIZE 1000

// font == rear 为空
// font -> next -> data 为首元素
// rear -> data 为尾元素

// 声明一个结构体来表示节点
typedef struct Node
{
    Elemtype data;   // 节点数据域
    struct Node* next; // 节点指针域
}QueueNode, * QueuePtr;

// 声明一个结构体来定义上面这个结构体的两个指针
typedef struct
{
    QueueNode* front, * rear;// 分别指向队首和队尾的指针
}LinkQueue;

// 判断该队列是否被初始化
bool isInit(LinkQueue l) {
    bool flag = false;
    if (l.front != NULL && l.rear != NULL) {
        flag = true;
    }
    return flag;
}

// 判断该队列是否被初始化
bool isInit(LinkQueue *ptrL) {
    bool flag = false;
    if (ptrL->front != NULL && ptrL->rear != NULL) {
        flag = true;
    }
    return flag;
}

// 首先进行初始化
void Init(LinkQueue* ptrL)
{
    // 申请一个节点的空间，并将该节点指针域赋空，用ptrQ指向它
    // 此时队列指针结构体队首队尾指向相同元素
    QueuePtr ptrQ;
    ptrQ = (QueuePtr)malloc(sizeof(QueueNode));
    ptrQ->next = NULL;
    ptrL->front = ptrL->rear = ptrQ;
    cout << "初始化成功" << endl;
    return;
}

// 判断队列是否为空,为空返回真1，不为空返回假0
void Empty(LinkQueue l)
{
    if (!isInit(l)) {
        cout << "该队列还未初始化，请先将其初始化" << endl;
        return;
    }
    //队空的条件是头指针和尾指针指向相同的地方
    if (l.front == l.rear)
    {
        cout << "队列为空" << endl;
        return;
    } else {
        cout << "队列非空" << endl;
        return;
    }
}

// 求队列长度
void GetLength(LinkQueue l)
{
    if (!isInit(l)) {
        cout << "该队列还未初始化，请先将其初始化" << endl;
        return;
    }
    //声明一个指向节点的指针ptrQ
    QueuePtr ptrQ;
    //让ptrQ指向队列的头指针
    ptrQ = l.front;
    //声明一个变量用来记录队列当前长度
    int length = 0;
    while (ptrQ->next)//当指针ptrQ所指的节点不为空时执行循环体
    {
        length++;
        ptrQ = ptrQ->next;
    }
    cout << "队列中有" << length << "个元素" << endl;
    return;
}

// 入队操作
void Add(LinkQueue* ptrL, Elemtype x)
{
    if (!isInit(ptrL)) {
        cout << "该队列还未初始化，请先将其初始化" << endl;
        return;
    }
    //声明一个节点类型的指针变量用来存储要入队的元素
    QueuePtr ptrQ;
    ptrQ = (QueuePtr)malloc(sizeof(QueueNode));
    if (!ptrQ) {
        printf("内存分配失败\n");
        return;
    }
    ptrQ->data = x;        //指针指向的节点的数据域存放x
    ptrQ->next = NULL;     //指针指向的节点的指针域置为空
    ptrL->rear->next = ptrQ;   //将队列的尾指针的指针域next指向指针p所指的节点
    ptrL->rear = ptrQ;         //将队列的尾指针向后移一位，指向刚入队的节点的位置
    cout << "元素" << x << "已被成功插入" << endl;
    return;
}

// 获取队首元素
void GetTop(LinkQueue l)
{
    if (!isInit(l)) {
        cout << "该队列还未初始化，请先将其初始化" << endl;
        return;
    }
    // 首先判断队列是否为空
    if (l.front == l.rear)
    {
        cout << "队列为空，无法获取队首元素" << endl;
        return;
    } else {
        cout << "当前队列的队首元素为" << l.front->next->data << endl;
        return;
    }
}

// 出队操作
void Del(LinkQueue *ptrL)
{
    // 判断该队列是否被初始化
    if (!isInit(ptrL)) {
        cout << "该队列还未初始化，请先将其初始化" << endl;
        return;
    }
    // 先判断队列是否为空
    if (ptrL->front == ptrL->rear)
    {
        cout << "当前队列为空，无法执行出队操作" << endl;
        return;
    }
    // 用临时变量保存出队的元素
    // 队头出队，释放内存
    QueueNode* ptrQ =  ptrL->front->next;
    Elemtype e = ptrQ->data;
    ptrL->front->next = ptrQ->next;
    free(ptrQ);
    cout << "元素" << e << "出队成功" << endl;
}

// 清空队列
void Clear(LinkQueue* ptrL) {
    // 判断该队列是否被初始化
    if (!isInit(ptrL)) {
        cout << "该队列还未初始化，请先将其初始化" << endl;
        return;
    }
    // 将队列中的所有元素依次出队，直到队列为空
    while (ptrL->front->next != NULL) {
        QueueNode* ptrQ =  ptrL->front->next;
        ptrL->front->next = ptrQ->next;
        free(ptrQ);
    }
    if (ptrL->front->next == NULL) {
        ptrL->rear = ptrL->front;
    }
    cout << "该队列已被清空" << endl;
    return;
}

void Destroy(LinkQueue* ptrL) {
    // 判断该队列是否被初始化
    if (!isInit(ptrL)) {
        cout << "该队列还未初始化，请先将其初始化" << endl;
        return;
    }
    // 先清空队列
    Clear(ptrL);
    // 释放队列头结点所占用的内存空间
    free(ptrL->front);
    // 将队列的头指针和尾指针置为空
    ptrL->front = ptrL->rear = NULL;
    cout << "该队列已被成功销毁" << endl;
    return;
}

// 输出队列元素
void PrintQueue(LinkQueue l) {
    // 判断该队列是否被初始化
    if (!isInit(l)) {
        cout << "该队列还未初始化，请先将其初始化" << endl;
        return;
    }
    if (l.front == l.rear) {
        cout << "队列为空，无法输出元素" << endl;
        return;
    }
    // 临时指针指向队列头结点的下一个节点
    QueuePtr ptrQ = l.front->next;
    cout << "队列元素为：" << endl;
    while (ptrQ != NULL) {
        cout << ptrQ->data << " ";
        ptrQ = ptrQ->next;
    }
    cout << endl;
    return;
}

// 打印'*'
void cout_star(){
    for(int i = 0;i < 15;i++){
        cout << '*';
    }
    return;
}

// 打印提示信息
void show_help(){
    int maxNumMsg = 11;
    // star_NUM = 15,30,15
    for(int i = 0;i < 4;i++){
        cout_star();
    }
    cout << endl;

    string s[maxNumMsg] = {
        "    1.初始化队列              ",
        "    2.销毁队列                ", 
        "    3.清空队列                ",
        "    4.判断队列是否为空        ",
        "    5.返回队列中元素个数      ",
        "    6.返回队列队头元素        ",
        "    7.插入新的队尾元素        ",
        "    8.删除队头元素            ",
        "    9.初始化并创建队列        ",
        "    10.输出队列元素           ",
        "    11.退出                   ",
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
    return;
}

// 主函数
int main()
{
    // 打印提示信息
    show_help();
    // 节点元素数据域
    Elemtype e;
    // 定义一个队列指针结构体,两个元素，分别指向队首和队尾
    LinkQueue l;
    l.front = l.rear = NULL;
    // 选择信息
    int choice;
    while (true)
        {
            cout << "请输入选择：";
            cin >> choice;
            switch (choice)
            {
            case 1:
                Init(&l);
                break;
            case 2:
                Destroy(&l);
                break;
            case 3:
                Clear(&l);
                break;
            case 4:
                Empty(l);
                break;
            case 5:
                GetLength(l);
                break;
            case 6:
                GetTop(l);
                break;
            case 7:
                cout << "请输入要插入的队尾元素：";
                cin >> e;
                Add(&l, e);
                break;
            case 8:
                Del(&l);
                break;
            case 9:
                Init(&l);
                int n;
                int a[MAXSIZE];
                cout << "请输入要插入的元素个数:";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cin >> a[i];
                }
                for (int i = 0; i < n; i++) {
                    Add(&l,a[i]);
                }
                break;
            case 10:
                PrintQueue(l);
                break;
            case 11:
                exit(0);
                break;
            default:
                cout << "无该操作" << endl;
                break;
            }
        }
    return 0;
}
    
