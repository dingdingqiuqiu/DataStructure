#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

using namespace std;

//typedef定义"struct LNode"的别名"LNode"
//typedef定义"struct LNode*"的别名"LinkList"
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//打印'*'
void cout_star(){
    for(int i = 0;i < 15;i++){
        cout << '*';
    }
}

//判断链表是否为空表
void is_Eme(LNode *l){
    if(l != NULL){
        cout << "该链表非空表" << endl;
    } else {
        cout << "该链表为空表" << endl;
    }
    return;
}

//打印提示信息
void show_help(){
    //15,30,15
    for(int i = 0;i < 4;i++){
        cout_star();
    }
    cout << endl;


    string s[13] = {
        "    1.初始化或重置链表        ",
        "    2.销毁链表                ", 
        "    3.链表中数据元素个数      ",
        "    4.所指位序的元素值        ",
        "    5.链表已存在元素的位序    ",
        "    6.请输入元素，求直接前驱  ",
        "    7.请输入元素，求直接后驱  ",
        "    8.请在第i个位置插入元素   ",
        "    9.删除第i个元素           ",
        "    10.输出所输入的链表元素   ",
        "    11.初始化并输入链表元素   ",
        "    12.判断链表是否为空表     ",
        "    13.退出                   "
    };

    for(int i = 0;i < 13;i++){
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

//打印链表中的元素
void show_elems(LNode *l){
    if(l == NULL) {
        cout << "链表已被销毁" << endl;
        return;
    }
    //若非最后一个元素
    if(l->next != NULL){
        cout << l->data << " ";
        show_elems(l->next);
    }
    if(l->next == NULL){
        cout << l->data << endl;
        return;
    }
}

//初始化链表
Status InitList(LinkList &L) {
    L = (LNode*)malloc(sizeof(LNode));
    if(L == NULL) return ERROR;
    memset(L,0,sizeof(LNode));
    L->next = NULL;
    return OK;
}

//销毁单链表
Status DestoryList(LinkList &L) {
    //递归试下
    if(L->next == NULL){
        free(L);
    } else {
        DestoryList(L->next);
    }
    return OK;
}

//链表中元素个数
int count_elems(LinkList L){
    int res = 0;
    while(L != NULL){
        res++;
        L = L->next;
    }
    return res;
}

//所指位序的元素值
void find_elem(LinkList L,int i){
    int count = i;
    if(i < 1 || i > count_elems(L)){
        cout << "该位序不存在" << endl;
        return;
    }
    while(--count != 0){
        L = L->next;
    }
    cout << "位置" << i << "处的" << "元素值为" << L->data << endl;
    return;
}

//输入元素，输出元素位置
void index_elem(LinkList L,ElemType e){
    //计数变量i
    bool flag = false;
    int i = 1;
    //只要L不指向空，一直找
    while(L != NULL){
        //找寻判断
        if(L->data == e){
            cout << "元素" << e << "的位置为第" << i << "位" << endl;
            flag = true;
        }
        //链表遍历
        i++;
        L = L->next;
    }
    if(!flag){
        cout << "找不到要寻找的元素值" << endl;
    }
    return;
}

//前驱
void f_elem(LinkList l,ElemType e){
    //l非空，一直找
    bool flag = false;
    while(l->next != NULL){
        //找到对应元素
        if(l->next->data == e){
            cout << "元素" << e << "的前驱为元素" << l->data << endl;
            flag = true;
        }
        l = l->next;
    }
    if(!flag){
        cout << "找不到元素" << e << "的前驱，请检查输入。" << endl; 
    }
    return;
}

//后继
void b_elem(LinkList l,ElemType e){
    bool flag = false;
    while(l != NULL) {
        if(l->data == e && l->next != NULL){
            cout << "元素" << e << "的后继为" << l->next->data << endl;
            flag = true;
        }
        l = l->next;
    }
    if(!flag){
        cout << "找不到元素" << e << "的后继，请检查输入。" << endl;
    }
}

//插入元素
LNode* insert_elem(LNode* &l,int i){
    //eg,i == 2,
    //input合规判定，不合规直接返回NULL,并打印提示
    LNode* s = l;
    if (i < 1 || i > count_elems(l)+1){
        cout << "输入不合规，请重新输入" << endl;
        return s;
    } else if (i == count_elems(l)+1){
        while(l->next != NULL){
            l = l->next;
        }
        cout << "请输入要插入的数据：";
        ElemType e;
        cin >> e;
        LNode* insert = new LNode();
        l->next = insert;
        insert->data = e;
        insert->next = NULL;
        cout << "操作成功" << endl;
        return s;
    } else if (i == 1){//输入合规下先遍历，合适位置插入值
        //似乎两种情况，当i = 1时，无需前方元素的next指向insert
        //当i > 1时，需要前方next指向insert
        cout << "请输入要插入的数据：";
        ElemType e;
        cin >> e;
        LNode* insert = new LNode();
        insert->next = l;
        insert->data = e;
        cout << "操作成功" << endl;
        return insert;
    } else {
        //eg.i == 2
        while(--i > 1){
            l = l->next;
        }
        cout << "请输入要插入的数据:";
        ElemType e;
        cin >> e;
        LNode *insert = new LNode();
        insert->next = l->next;
        l->next = insert;
        insert->data = e;
        cout << "操作成功" << endl;
        return s;
    }
}

//创建单个Node（弃用）
LNode *create_node(ElemType Data,LinkList Next){
    LNode *node = NULL;
    //分配堆空间
    node = (LNode *)malloc(sizeof(LNode));
    //如果堆空间分配失败
    if(node == NULL){
        cout << "分配失败" << endl;
    }
    //对分配到的空间数据置零
    memset(node,0,sizeof(LNode));
    //数据赋值
    node->data = Data;
    node->next = Next;
    return node;
}

//删除链表中指定位置的元素
LNode* destory_elem(LNode* &l,int i){
    //eg,i == 2,
    //input合规判定，不合规直接返回NULL,并打印提示
    LNode* s = l;
    if (i < 1 || i > count_elems(l)){
        cout << "输入不合规，请重新输入" << endl;
        return s;
    }/* else if (i == count_elems(l)){//删除最后一个元素
        while(l->next->next != NULL){
            l = l->next;
        }
        free(l->next);
        l->next = NULL;
        return s;
    } */else if (i == 1){//删除第一个元素
        LNode* newstar = l->next;
        //释放空间
        free(l);
        cout << "操作成功" << endl;
        return newstar;
    } else {
        //eg,2
        //改变前一个的next,释放空间
        while(--i > 1){
            l = l->next;
        }
        //保存下next的next值，free后会丢失
        LNode *temp = l->next->next;
        free(l->next);
        //改变next
        l->next = temp;
        cout << "操作成功" << endl;
        return s;
    }
}

//创建并初始化链表
void input_data(LNode *l,ElemType e){
    /*LNode *node = NULL;
    //分配堆空间
    node = (LNode *)malloc(sizeof(LNode));
    //如果堆空间分配失败
    if(node == NULL){
        cout << "分配失败" << endl;
    }
    //对分配到的空间数据置零
    memset(node,0,sizeof(LNode));
    //数据赋值
    node->data = e;
    node->next = l;
    show_elems(node);
    return node;*/
    /*
    LNode* insert = new LNode();
    insert->next = l;
    insert->data = e;
    return insert;
*/
    LNode *back = new LNode();
    while(l->next!=NULL){
        l = l->next;
    }
    l->next = back;
    back->data = e;
    back->next = NULL;
    return;
   /* LNode *s = new LNode();
    s->data = e;
    if(l == NULL){
        s->next = NULL;
    } else{
        s->next = l;
    }
    cout << s->data;
    return s;*/
}

//测试程序
int main1(){
    show_help();
    //创建一个节点
    LNode *node = create_node(10,NULL);
    //打印测试
    show_elems(node);
    return 0;
}

//主函数
int main(){
    int operate_code;
    show_help();
    //创建并初始化链表
    LNode *list = create_node(0,NULL); 
    //交互页面
    while(1){
        cout << "请输入操作代码：" ;
        cin >> operate_code;

        //初始化或重置链表
        if(operate_code ==  1 ) {
            DestoryList(list);
            cout << "请输入初始链表首节点值：";
            ElemType e;
            cin >> e;
            list = create_node(e,NULL);
            cout << "操作成功!" << endl;
        }

        //销毁链表
        else if(operate_code ==  2 ){
            if(list != NULL){
                if(DestoryList(list)){
                    cout << "链表销毁成功!" << endl;
                } else {
                    cout << "链表销毁失败!" << endl;
                }
            }
        }

        //链表中元素个数
        else if(operate_code ==  3 ){
            int res = count_elems(list);
            cout << "链表中元素个数为" << res << endl;
        }

        //所指位序的元素值
        else if(operate_code ==  4 ){
            int i;
            cout << "请输入你要寻找的元素的位序:";
            cin >> i;
            find_elem(list,i);
        }

        //链表已存在元素的位序    
        else if(operate_code ==  5 ){
            int e;
            cout << "请输入你要寻找的元素值:";
            cin >> e;
            index_elem(list,e);
        }

        //请输入元素，求直接前驱
        else if(operate_code ==  6 ){
            ElemType e;
            cout << "请输入要寻找前驱的元素值:";
            cin >> e;
            f_elem(list,e);
        }

        //请输入元素，求直接后继
        else if(operate_code ==  7 ){
            ElemType e;
            cout << "请输入要寻找后继的元素值:";
            cin >> e;
            b_elem(list,e);
        }

        //在第i个位置插入元素
        else if(operate_code ==  8 ){
            int i;
            cout << "请输入要插入的元素的位序:";
            cin >> i;
            list = insert_elem(list,i);
            //show_elems(list); 
        }

        //删除第i个元素
        else if(operate_code ==  9 ){
            cout << "请输入要删除的元素下标：";
            int i;
            cin >> i;
            list = destory_elem(list,i);
            //show_elems(list);
            //cout << "操作成功" << endl;
        }

        //输出所输入的链表元素
        else if(operate_code ==  10 ){
            show_elems(list);
        }

        //初始化并输入链表元素
        else if(operate_code ==  11 ){
            //销毁旧链表
            if(list != NULL)
            DestoryList(list);
            //新链表初始化,必须先初始化然后再输入链表元素，原因希腊奶。
            cout << "请输入初始链表首节点值：";
            ElemType e;
            cin >> e;
            list = create_node(e,NULL);

            ElemType E;
            cout << "请输入链表元素（以空格分割各元素，回车停止输入）:" << endl;
            string line;
            cin.ignore();
            getline(cin,line);
            stringstream ss(line);
            while(ss >> E){
                input_data(list,E);
            }
            //cout << e << endl;
            //show_elems(list);
            cout << "操作成功" << endl;
        }

        //判断链表是否为空
        else if(operate_code == 12){
            is_Eme(list);
        }

        //退出
        else if(operate_code ==  13 ){
            break;
        }

        //打印错误提示信息
        else{
            cout << "输入不符合标准,请重新输入。\n" << endl;
            show_help();
        }
    } 

    //销毁链表

    return 0;
}
