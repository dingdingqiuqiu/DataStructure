#include <iostream>
#include <sstream>
#define MaxSize 20

typedef int ElemType;

using namespace std;

typedef struct List{
    ElemType elem[MaxSize];
    int length;
}List;

//-2,打印线性表中的元素
void show_elems(List *l){
    cout << "线性表中元素如下：" << endl;
    for(int i = 0;i < l->length;i++){
        cout << l->elem[i] << " ";
    }
    cout << endl;
    return;
}

//-1,使用逗号分割的输入处理
void input(int *prt_num1,int *prt_num2){
    string str;
    //I don't know why getline(cin, str) not work.
    //if not getchar(),it doesn't work.
    //but append getchar(),the getline(cin,str) work.
    //getchar();
    cin.ignore();
    getline(cin,str);
    //cin >> str;
    stringstream ss(str);
    string str_num1, str_num2;
    getline(ss,str_num1,',');
    getline(ss,str_num2,',');
    try {
        *prt_num1 = stoi(str_num1);
        *prt_num2 = stoi(str_num2);
    } catch (invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
    }
    return ;
}

//0.操作页面(自带页面)
void show_help(){ 
    cout << "******* Data Structure *******" << endl;
    cout << "0-----退出程序并删除线性表" << endl;
    cout << "1-----线性表元素定位" << endl;
    cout << "2-----判断线性表是否为空" << endl;
    cout << "3-----求线性表长度" << endl;
    cout << "4-----获取线性表指定位置元素" << endl;
    cout << "5-----求前驱" << endl;
    cout << "6-----求后继" << endl;
    cout << "7-----在线性表指定位置插入元素 "<< endl;
    cout << "8-----删除线性表指定位置元素" << endl;
    cout << "9-----显示线性表" << endl;
    //cout << "   退出,输入一个负数！" << endl;
}

//2.定义操作函数1
//删除线性表中指定位置的函数
void delete_elem(List *l,int pos){
    //检查位置是否有效
    if(pos < 0 || pos >= l->length){
        //如果位置无效，输出错误信息并返回
        cout << "位置无效" << endl;
        return;
    } 
    //将指定位置后的所有元素向前移动一位
    for(int i = pos;i < l->length-1;i++){
        l->elem[i] = l->elem[i+1];
    }
    //线性表长度减1
    l->length--;
    cout << "操作成功!" << endl;
}

//3.定义操作函数2
//在指定位置插入元素
void insert_elem(List *l,int pos,ElemType e){

    //检查位置是否有效
    if(pos <= 0 || pos > l->length+1){
        //如果位置无效，输出错误信息并返回
        cout << "位置无效" << endl;
        return;
    }
    //检查线性表是否已满
    if(l->length == MaxSize){
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
    cout << "操作成功！" << endl;
}

//4.定义操作函数3
//销毁线性表
void Destory_list(List *&l){
    //删除线性表
    delete l;
    //将线性表的指针设置为nullptr,防止悬挂指针
    l = nullptr;
}

//4.定义操作函数3
void find_elem(List *l,int expeceted_elem){
    int flag = 0;
    for(int i = 0;i < l->length;i++){
        if(l->elem[i] == expeceted_elem){
            flag = 1;
            cout << "位置" << i+1 << "处有该元素" << endl;
        }
    }
    if(!flag){
        cout << "该线性表中不存在此元素" << endl;
    }
}

//5.补全测试函数main
int main(){
    char operate_code;
    show_help();
    //创建并初始化线性表
    List *l = new List();
    l->length = 0;
    //交互页面
    while(1){
        cout << "请输入操作代码：";
        cin >> operate_code;

        //退出码操作
        if(operate_code == '0'){
            break;
        }
        //清空线性表
        /*else if(operate_code == '1'){
            l-> length == 0;
            cout << "操作成功!" << endl;
        }*/
        //线性表元素定位
        else if(operate_code == '1') {
            int expeceted_elem;
            cout << "请输入要寻找的元素:";
            cin >> expeceted_elem;
            find_elem(l,expeceted_elem);
        }
        //判断线性表是否为空
        else if(operate_code == '2'){
            if(l->length != 0){
                cout << "该线性表非空" << endl;
            } else {
                cout << "该线性表为空表" << endl;
            }
        }
        //求线性表的长度
        else if(operate_code == '3'){
            cout << "该线性表的长度为:" <<l->length << endl;
        }
        //获取线性表指定位置元素
        else if(operate_code == '4'){
            int i;
            cout << "请输入你想获取的元素位置:";
            cin >> i;
            if (i <= 0 || i > l->length){
                cout << "位置无效" << endl;
            } else{
                cout << "该线性表位置" << i << "处的元素为" << l->elem[i-1] << endl;
            }
        }
        //求前驱    
        else if(operate_code == '5'){
            int i;
            cout << "请输入你要求其前驱的元素位置:";
            cin >> i;
            if(i > 1 && i <= l->length){
                cout << "位置" << i << "处元素前驱为" << l->elem[i-2] << endl;
            } else {
                cout << "该位置元素前驱不存在" << endl;
            }
        }
        //求后继
        else if(operate_code == '6'){
            int i;
            cout << "请输入你要求其后继的元素位置:";
            cin >> i;
            if(i >= 1 && i <= l->length-1){
                cout << "位置" << i << "处元素的后继为" << l->elem[i] << endl;
            } else {
                cout << "该位置元素后继不存在" << endl;
            }        
        }
        //在线性表指定位置插入元素
        else if(operate_code == '7'){
            //输入格式提示信息
            cout << "输入要插入的数据信息（位置,数据）：";
            int ops,data;
            input(&ops,&data);
            insert_elem(l,ops,data);
        }
        //删除线性表指定位置元素
        else if(operate_code == '8'){
            cout << "请输入你要删除的元素在线性表中所处的位置：";
            int i;
            cin >> i;
            delete_elem(l,i-1);
        }
        //显示线性表
        else if(operate_code == '9'){
            //show_elems(l);
            cout << "线性表中元素如下：" << endl;
            for(int i = 0;i < l->length;i++){
                cout << l->elem[i] << " ";
            }
            cout << endl;
        }
        //打印错误提示信息
        else{
            cout << "输入不符合标准,请重新输入。\n" << endl;
            show_help();
        }
    } 
    //摧毁线性表
    Destory_list(l);
    return 0;
}
