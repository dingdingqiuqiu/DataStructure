#include <stdio.h>
#include <iostream>

#define MAXSIZE 10

typedef int ElemType;

using namespace std;

typedef struct List{
    ElemType elem[MAXSIZE];
    int length;
}List;

//插入元素
void insert_elem(List *l,int pos,ElemType e){

    //检查位置是否有效
    if(pos <= 0 || pos > l->length+1){
        //如果位置无效，输出错误信息并返回
        cout << "位置无效" << endl;
        return;
    }
    //检查线性表是否已满
    if(l->length == MAXSIZE){
        //如果线性表已满，输出错误信息并返回
        cout << "线性表已满" << endl;
        return;
    }
    //将指定位置以及其后所有元素向后移动一位
    if(l->length != 0){
        //eg length == 1,pos = 1. List = [114],
        //for1: [114,114]
        //for2: i = 0 ,erro.
        for(int i = l->length;i >= pos;i--){
            l->elem[i] = l->elem[i-1];
        }
    }
    //在指定位置插入新元素
    l->elem[pos-1] = e;
    //线性表的长度加1
    l->length++;
    //打印成功信息
    //cout << "操作成功！" << endl;
}

//删除元素
void delete_elem(List *n,int exe){
    for(int i = 0;i < n->length;i++){
        if(n->elem[i] == exe){
            //相等元素销毁
            n->elem[i] = n->elem[i+1];
            //其余元素前移
            for(int j = i+1;j <= n->length-2;j++){
                n->elem[j] = n->elem[j+1];
            }
            //总长度减一
            n->length--;
            return;
        }
    }
}

//交集
List *LAndN(List *l,List *n){
    //只有l中有该元素且n中有该元素时，将其加入到res
    List *res = new List();
    for(int i = 0;i < l->length;i++){
        for(int j = 0;j < n->length;j++){
            if(l->elem[i] == n->elem[j]){
                res->elem[res->length] = l->elem[i];
                res->length++;
            }
        }
    }
    return res;
}

//并集
List *LAndN2(List *l,List *n,List *m){
    //只有l中有该元素或n中有该元素时，将其加入到res
    //思路：先简单合并，再删除交集元素
    List *res = new List();
    //add
    for(int i = 0;i < l->length;i++){
        res->elem[i] = l->elem[i];
        res->length++;
    }
    int temp = res->length;
    for(int i = 0;i < n->length;i++){
        res->elem[i+temp] = n->elem[i];
        res->length++;
    }
    //delete
    for(int i = 0;i < m->length;i++){
        delete_elem(res,m->elem[i]);
    }
    return res;
}

//差集实现
//大体实现思路为并集减交集
List *LAndN3(List *m,List *n){
    for(int i = 0;i < n->length;i++){
        delete_elem(m,n->elem[i]);
    }
    return m;
}



//打印集合
void show_list(List *l){
    for(int i  = 0;i < l->length;i++){
        cout << l->elem[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    //集合初始化
    List *l = new List();
    List *n = new List();
    for(int i = 0;i < 5;i++){
        l->elem[i] = i;
        l->length++;
        n->elem[i] = i+1;
        n->length++;
    }

    //交集
    List *res1 = LAndN(l,n);
    show_list(res1);
    
    //并集
    List *res2 = LAndN2(l,n,res1);
    show_list(res2);

    //差集
    List *res3 = LAndN3(res2,res1);
    show_list(res3);

    return 0;
}
