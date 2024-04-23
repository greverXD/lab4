#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

void push(Node*& top, int data) 
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop(Node*& top) 
{
    if (top == nullptr) 
    {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    int data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}

void printStack(Node* top) 
{
    while (top != nullptr) 
    {
        cout << top->data << " " << endl;
        top = top->next;
    }
    cout << endl;
}

void removeEvenNumbers(Node*& top)
{
    Node* tempStack = nullptr;
    while (top != nullptr) 
    {
        if (top->data % 2 == 0) 
        {
            pop(top);
        }
        else 
        {
            push(tempStack, top->data);
            pop(top);
        }
    }

    while (tempStack != nullptr) 
    {
        push(top, tempStack->data);
        pop(tempStack);
    }
}

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

void insert(TreeNode*& root, int data) 
{
    if (root == nullptr) 
    {
        root = new TreeNode;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (data < root->data) 
    {
        insert(root->left, data);
    }
    else {
        insert(root->right, data);
    }
}

void inorderTraversal(TreeNode* root, Node*& sortedStack)
{
    if (root != nullptr) 
    {
        inorderTraversal(root->left, sortedStack);
        push(sortedStack, root->data);
        inorderTraversal(root->right, sortedStack);
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    Node* myStack = nullptr;
    srand(time(0));

    for (int i = 0; i < 10; ++i) 
    {
        int num = rand() % 101 - 50; // генерация случайного числа от -50 до 50
        push(myStack, num);
    }

    cout << "Исходный стек: " << endl;
    printStack(myStack);

    removeEvenNumbers(myStack);

    cout << "Стек после удаления четных чисел: " << endl;
    printStack(myStack);

    TreeNode* treeRoot = nullptr;

    Node* tempStack = nullptr;
    while (myStack != nullptr) 
    {
        int num = pop(myStack);
        insert(treeRoot, num);
    }

    Node* sortedStack = nullptr;
    inorderTraversal(treeRoot, sortedStack);

    cout << "Отсортированный стек: " << endl;
    printStack(sortedStack);

    return 0;
}