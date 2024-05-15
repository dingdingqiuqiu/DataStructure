#include <stdio.h>
#include<iostream>
#include <stdlib.h>

using namespace std;
typedef int Elemtype;
//声明一个结构体来表示节点
typedef struct Node
{
    Elemtype data;   //节点数据域
    struct Node* next; //节点指针域
}QueueNode, * QueuePtr;
//声明一个结构体来定义上面这个结构体的两个指针
typedef struct
{
    QueueNode* front, * rear;//分别指向队首和队尾的指针
}LinkQueue;
//首先进行初始化
void Init(LinkQueue* s)
{
    QueueNode* p;
    p = (QueueNode*)malloc(sizeof(QueueNode));
    p->next = NULL;
    s->front = s->rear = p;
}
//判断队列是否为空,为空返回真1，不为空返回假0
int Empty(LinkQueue s)
{
    //队空的条件是头指针和尾指针指向相同的地方
    if (s.front == s.rear)
    {
        return 1;
    }
    return 0;
}

//求队列长度
int GetLength(LinkQueue s)
{
    //声明一个节点类型的指针
    QueueNode* p;
    //让p指向队列的头指针
    p = s.front;
    //声明一个变量用来记录队列当前长度
    int length = 0;
    while (p->next)//当指针p所指的节点不为空时执行循环体
    {
        length++;
        p = p->next;
    }
    return length;//返回当前队列的长度
}
//入队操作
void Add(LinkQueue* s, Elemtype x)
{
    //声明一个节点类型的指针变量用来存储要入队的元素
    QueueNode* p;
    p = (QueueNode*)malloc(sizeof(QueueNode));
    if (!p) {
        printf("内存分配失败\n\n");
        return;
    }
    p->data = x;        //指针指向的节点的数据域存放x
    p->next = NULL;     //指针指向的节点的指针域置为空
    s->rear->next = p;   //将队列的尾指针的指针域next指向指针p所指的节点
    s->rear = p;         //将队列的尾指针向后移一位，指向刚入队的节点的位置
}
//获取队首元素
Elemtype GetTop(LinkQueue s)
{
    //首先判断队列是否为空
    if (Empty(s))
    {
        printf("队列为空，无法获取队首元素\n\n");
        return 0;
    }
    return s.front->next->data;//不为空的话就返回队首指针指向的第一个元素的数据域
}
//出队操作
void Del(LinkQueue* s, Elemtype* e)
{
    //先判断队列是否为空
    if (Empty(*s))
    {
        printf("当前队列为空，无法执行出队操作\n\n");
        return;
    }
    //用临时变量保存出队的元素
    QueueNode* p;
    p = s->front->next;
    if (p == s->rear)
    {
        s->front = s->rear;
    }
    *e = p->data;
    s->front->next = p->next;
    free(p);

}


// 清空队列
void Clear(LinkQueue* s) {
    // 将队列中的所有元素依次出队，直到队列为空
    while (!Empty(*s)) {
        Del(s, NULL);
    }
}
void Destroy(LinkQueue* s) {
    // 先清空队列
    Clear(s);
    // 释放队列头结点所占用的内存空间
    free(s->front);
    // 将队列的头指针和尾指针置为空
    s->front = s->rear = NULL;
}
// 输出队列元素
void PrintQueue(LinkQueue s) {
    if (Empty(s)) {
        cout << "队列为空，无法输出元素" << endl;
        return;
    }

    // 临时指针指向队列头结点的下一个节点
    QueuePtr p = s.front->next;
    cout << "队列元素为：" << endl;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    //声明一个节点类型的变量
    Elemtype e;
    //声明一个顺序队名字为s
    LinkQueue s;
    //对这个顺序队进行初始化
    

    int choice;


  
        cout << "\n队列操作菜单:" << endl;
        cout << "1. 初始化并创建队列" << endl;
        cout << "2. 销毁队列" << endl;
        cout << "3. 清空队列" << endl;
        cout << "4. 判断队列是否为空" << endl;
        cout << "5. 返回队列中元素个数" << endl;
        cout << "6. 返回队列对头元素" << endl;
        cout << "7. 插入新的队尾元素" << endl;
        cout << "8. 删除对头元素" << endl;
        cout << "9. 输出队列元素" << endl;
        cout << "10. 退出" << endl;
        cout << "请输入队列操作" << endl;

        while (true)
        {
            cin >> choice;



            switch (choice)
            {
            case 1:
                Init(&s);
                cout << "初始化成功" << endl;
                break;
            case 2:
                Destroy(&s);
                cout << "成功销毁" << endl;
                break;
            case 3:
                Clear(&s);
                cout << "成功清空" << endl;
                break;
            case 4:
                if (Empty(s) == 1)
                {
                    cout << "队列为空" << endl;
                }
                if (Empty(s) == 0)
                {
                    cout << "队列不为空" << endl;
                }
                break;
            case 5:
                cout << "队列中元素的个数：" << GetLength(s) << endl;
                break;
            case 6:
                e = GetTop(s);
                if (e) {
                    cout << "当前队列的队首元素为" << e << endl;
                }
                break;
            case 7:
                cout << "要输入的元素：";
                cin >> e;
                Add(&s, e);
                break;
            case 8:
                Del(&s, &e);
                cout << "删除成功";
                break;
            case 9:
                PrintQueue(s);
                break;
            case 10:
                exit(0);
                break;
            default:
                cout << "无该操作" << endl;
                break;
            }
        }
    return 0;
}
    
