
#include<iostream>
#include<string>
#include<stack>
using namespace std;
typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, * HuffmanTree;
typedef char** HuffmanCode;
void Select(HuffmanTree& HT, int end, int& s1, int& s2)		//找出最小的两个值。两个最小的值得下标记录到 s1 s2中。
{
    int min1 = 0x3f3f3f, min2 = 0x3f3f3f;//先将最小值定义为无穷大方便之后替换
    for (int i = 1; i <= end; i++)
    {
        if (HT[i].parent == 0 && HT[i].weight < min1)//在没有父结点的结点中循环找到权值最小的
        {
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    for (int i = 1; i <= end; i++)
    {
        if (HT[i].parent == 0 && HT[i].weight < min2 && s1 != i)//找出第二小的
        {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
}
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n) //创建哈夫曼树和哈夫曼编码
{

    int i, s1, s2;
    HuffmanTree p;
    if (n <= 1)
        return;//返回空地址
    int m = 2 * n - 1;//无度数为1的结点，故一共有2n-1个结点

    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//分配空间
    for (p = HT + 1, i = 1; i <= n; i++, p++, w++)//从下标为1的位置开始把权值导入，父亲和孩子在最开始都没有
    {
        *p = { *w, 0, 0, 0 };
    }


    for (; i <= m; i++, p++)//把后面的全初始化为0
        *p = { 0, 0, 0, 0 };

    for (i = n + 1; i <= m; i++)//从下标为n+1处开始赋值
    {

        Select(HT, i - 1, s1, s2);//选择范围是0——n
        HT[i].weight = HT[s1].weight + HT[s2].weight;//将最小的两个先合并
        HT[s1].parent = i;
        HT[s2].parent = i;//这两个的父亲结点自然就是下标为i处
        HT[i].lchild = s1;
        HT[i].rchild = s2;//下标为i的结点的孩子结点就是他俩
    }

    //从叶子到根逆向求每个字符的哈夫曼树编码
    stack<char> s;//声明存放char类型的stack容器s
    for (i = 1; i <= n; i++)
    {

        int temp = i, p, k = 0;
        p = HT[temp].parent;
        while (p)
        {
            if (HT[p].lchild == temp)//左孩子入栈0
                s.push('0');
            if (HT[p].rchild == temp)//有孩子入栈1
                s.push('1');
            temp = p;
            p = HT[temp].parent;//更新父结点
            k++;
        }

        int j = 0;
        while (!s.empty())
        {
            HC[i][++j] = s.top();//将栈中的01序列存放在数组中
            s.pop();
        }
        HC[i][0] = j;//记录每个结点01序列的个数，方便循环输出
    }
}
void showHuffmanCode(HuffmanCode HC) 		//显示每个字符的哈夫曼编码
{
    char c;
    for (int i = 1; i <= 27; i++)
    {
        if (i != 27)
        {
            c = i + 'A' - 1;
            cout << c << "的哈夫曼编码是：";
        }
        else
        {
            cout << "空格的哈夫曼编码是：";
        }
        for (int j = 1; j <= HC[i][0]; j++)
        {
            cout << HC[i][j];//输出哈夫曼编码
        }
        cout << endl;
    }
}
void TanserString(HuffmanCode HC, string s)	//将字符转化为哈夫曼编码
{
    string ss;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;//转化为小写
        if (s[i] == ' ')
            s[i] = 'z' + 1;
    }

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= HC[s[i] - 'a' + 1][0]; j++)
            ss += HC[s[i] - 'a' + 1][j];//按字符类型相加
    }
    cout << ss << endl;
}
void TanserHuffmanCode(HuffmanCode HC, string s)	//将哈夫曼码变为字符
{
    string ss = "", s1 = "";
    string t[27];
    for (int i = 0; i < 27; i++) //将27个字符的哈夫曼编码存在数组t中
    {
        t[i] = "";
        for (int k = 1; k <= HC[i + 1][0]; k++)
        {
            t[i] += HC[i + 1][k];
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        ss += s[i];//一直读取后面的编码直到有字符与其对应
        for (int j = 0; j < 27; j++)
        {
            if (ss == t[j])
            {

                ss = "";//将前面的清空，继续寻找下一组匹配的编码
                if (j != 26)
                {
                    s1 += j + 'a';
                }

                else if (j == 26)
                {
                    s1 += ' ';
                }
            }
        }
    }
    cout << s1 << endl;
}
void zhujiemian()
{
    cout << "************************************************************" << endl;
    cout << "********   1.输入HuffmanTree的参数                      ****" << endl;
    cout << "********   2.初始化HuffmanTree参数.《含有26字母及空格》 ****" << endl;
    cout << "********   3.创建HuffmanTree和编码表。                  ****" << endl;
    cout << "********   4.输出编码表。                               ****" << endl;
    cout << "********   5.输入编码，并翻译为字符。                   ****" << endl;
    cout << "********   6.输入字符，并实现转码                       ****" << endl;
    cout << "********   7.退出                                       ****" << endl;
    cout << "************************************************************" << endl;
}
int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    string s;
    HC = (HuffmanCode)malloc((27 + 1) * sizeof(char*));
    for (int i = 1; i <= 28; i++)
        HC[i] = (char*)malloc((27 + 1) * sizeof(char));//HC是二维的故分配两次
    zhujiemian();
    int a[27] = { 64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 168 };
    int operator_code;
    while (1)
    {
        cout << "请输入操作 ：";
        cin >> operator_code;
        if (operator_code == 1)
        {
            HuffmanCoding(HT, HC, a, 27);
            cout << "创建成功，1,2,3已完成，无需输入2,3" << endl;
        }
        else if (operator_code == 4)
        {
            showHuffmanCode(HC);
        }
        else if (operator_code == 5)
        {
            cout << "请输入HuffmanCode：";
            cin >> s;
            TanserHuffmanCode(HC, s);
        }
        else if (operator_code == 6)
        {
            getchar();//将输入字符存放在缓冲区域内，直到按回车为止
            cout << "请输入字符：";
            getline(cin, s);//将输入内容传递给s
            TanserString(HC, s);
        }
        else if (operator_code == 7)
        {
            break;
        }
        else
        {
            cout << "输入违法请重新输入" << endl;
        }
    }
    return 0;
}





