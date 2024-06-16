#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
   char data;
   Node *left;
   Node *right;
};

Node *createNode(int data)
{
   Node *newNode = new Node();
   if (!newNode)
   {
      cout << "内存错误\n";
      return NULL;
   }
   newNode->data = data;
   newNode->left = newNode->right = NULL;
   return newNode;
}

Node *insertNode(Node *root, int data)
{

   if (root == NULL)
   {
      root = createNode(data);
      return root;
   }

   queue<Node *> q;
   q.push(root);

   while (!q.empty())
   {
      Node *temp = q.front();
      q.pop();

      if (temp->left != NULL)
         q.push(temp->left);
      else
      {
         temp->left = createNode(data);
         return root;
      }

      if (temp->right != NULL)
         q.push(temp->right);
      else
      {
         temp->right = createNode(data);
         return root;
      }
   }
   return root;
}

void createTree(Node *&root, string input, int &index)
{
   if (index >= input.length())
   {
      return;
   }

   char ch = input[index];
   index++;

   if (ch == '#')
   {
      root = NULL;
   }
   else
   {
      root = createNode(ch);
      createTree(root->left, input, index);
      createTree(root->right, input, index);
   }
}

void preorder(Node *temp)
{
   if (temp == NULL)
      return;

   cout << temp->data << ' ';
   preorder(temp->left);
   preorder(temp->right);
}

void inorder(Node *temp)
{
   if (temp == NULL)
      return;

   inorder(temp->left);
   cout << temp->data << ' ';
   inorder(temp->right);
}

void postorder(Node *temp)
{
   if (temp == NULL)
      return;

   postorder(temp->left);
   postorder(temp->right);
   cout << temp->data << ' ';
}

void levelorder(Node *temp)
{
   if (temp == NULL)
      return;

   queue<Node *> q;
   q.push(temp);

   while (!q.empty())
   {
      Node *temp = q.front();
      q.pop();
      cout << temp->data << ' ';

      if (temp->left != NULL)
         q.push(temp->left);

      if (temp->right != NULL)
         q.push(temp->right);
   }
}

void inorderIterative(Node *temp)
{
   stack<Node *> s;
   Node *curr = temp;

   while (!s.empty() || curr != NULL)
   {
      if (curr != NULL)
      {
         s.push(curr);
         curr = curr->left;
      }
      else
      {
         curr = s.top();
         s.pop();

         cout << curr->data << ' ';

         curr = curr->right;
      }
   }
}

// 非递归前序遍历
void preorderIterative(Node *root)
{
   if (root == NULL)
   {
      return;
   }

   stack<Node *> nodeStack;
   nodeStack.push(root);

   while (!nodeStack.empty())
   {
      Node *node = nodeStack.top();
      cout << node->data << " ";
      nodeStack.pop();

      if (node->right)
      {
         nodeStack.push(node->right);
      }
      if (node->left)
      {
         nodeStack.push(node->left);
      }
   }
}

// 非递归后序遍历
void postorderIterative(Node *root)
{
   if (root == NULL)
   {
      return;
   }

   stack<Node *> nodeStack1, nodeStack2;
   nodeStack1.push(root);

   while (!nodeStack1.empty())
   {
      Node *node = nodeStack1.top();
      nodeStack1.pop();
      nodeStack2.push(node);

      if (node->left)
      {
         nodeStack1.push(node->left);
      }
      if (node->right)
      {
         nodeStack1.push(node->right);
      }
   }

   while (!nodeStack2.empty())
   {
      Node *node = nodeStack2.top();
      cout << node->data << " ";
      nodeStack2.pop();
   }
}

int height(Node *temp)
{
   if (temp == NULL)
      return 0;
   else
   {
      int lheight = height(temp->left);
      int rheight = height(temp->right);

      if (lheight > rheight)
         return (lheight + 1);
      else
         return (rheight + 1);
   }
}

void countLeaves(Node *temp, int &count)
{
   if (temp == NULL)
      return;

   if (temp->left == NULL && temp->right == NULL)
      count++;

   countLeaves(temp->left, count);
   countLeaves(temp->right, count);
}

void test()
{
   string input = "ABC##DE#G##F###";
   int index = 0;
   Node *root = NULL;

   createTree(root, input, index);

   cout << "先序遍历: ";
   preorder(root);
   cout << endl;

   cout << "中序遍历: ";
   inorder(root);
   cout << endl;

   cout << "后序遍历: ";
   postorder(root);
   cout << endl;

   cout << "层序遍历: ";
   levelorder(root);
   cout << endl;

   cout << "中序遍历（迭代）: ";
   inorderIterative(root);
   cout << endl;

   cout << "树的高度: " << height(root) << endl;

   int count = 0;
   countLeaves(root, count);
   cout << "叶子节点数量: " << count << endl;

   return;
}

void menu()
{
   Node *root = NULL;
   int choice;
   do
   {
      cout << "菜单：\n";
      cout << "0. 创建二叉树\n";
      cout << "1. 先序遍历\n";
      cout << "2. 中序遍历\n";
      cout << "3. 后序遍历\n";
      cout << "4. 层序遍历\n";
      cout << "5. 非递归中序遍历\n";
      cout << "6. 计算二叉树的高度\n";
      cout << "7. 计算叶子节点的数量\n";
      cout << "8. 退出\n";
      cout << "请输入你的选择：";
      cin >> choice;

      switch (choice)
      {
      case 0:
      {
         string str;
         cin >> str;
         int index = 0;
         createTree(root, str, index);
         break;
      }
      case 1:
         preorder(root);
         break;
      case 2:
         inorder(root);
         break;
      case 3:
         postorder(root);
         break;
      case 4:
         levelorder(root);
         break;
      case 5:
         inorderIterative(root);
         break;
      case 6:
         cout << "二叉树的高度是：" << height(root) << endl;
         break;
      case 7:
      {
         int count = 0;
         countLeaves(root, count);
         cout << "叶子节点的数量是：" << count << endl;
         break;
      }
      case 8:
         cout << "退出程序\n";
         break;
      default:
         cout << "无效的选择，请重新输入！\n";
         break;
      }
   } while (choice != 8);
}

int main() // 主函数
{
   int T;
   cout << "请选择你要测试的模式" << endl;
   cout << "1.单步调试" << endl;
   cout << "2. 一次执行" << endl;
   cin >> T;

   if (T == 1)
      menu();
   else if (T == 2)
      test(); // 调用测试函数
   return 0;  //
}