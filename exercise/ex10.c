/*Introduction
Convert a expression to a abstract syntax tree(AST).
The expression only has +,−,∗,/,(,) and variables(a to z and A to Z).
Ensure that each operator will be enclosed in parentheses regardless of the four fundamental operations of arithmetic.*/

//Input has one line.
//Output the preorder of the AST. There is no '\n' in the end.

#include <stdio.h>
#include <stdlib.h>

// 定義抽象語法樹節點的結構
struct ASTNode {
    char data;  // 運算符或變數
    struct ASTNode* left;
    struct ASTNode* right;
};

// 定義堆疊的結構
struct StackNode {
    struct ASTNode* data;
    struct StackNode* next;
};

// 創建新節點的函數
struct ASTNode* createNode(char data) {
    struct ASTNode* newNode = (struct ASTNode*)malloc(sizeof(struct ASTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 判斷是否為變數
int isVariable(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// 將節點壓入堆疊的函數
void push(struct StackNode** top, struct ASTNode* node) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = node;
    newNode->next = *top;
    *top = newNode;
}

// 從堆疊彈出節點的函數
struct ASTNode* pop(struct StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct ASTNode* popped = temp->data;
    free(temp);
    return popped;
}

// 從表達式構建抽象語法樹的函數
struct ASTNode* buildAST(char expression[], int length) {
    struct StackNode* stack = NULL;

    for (int i = 0; i < length; i++) {
        if (isVariable(expression[i])) {
            push(&stack, createNode(expression[i]));
        } else if (expression[i] == ')') {
            struct ASTNode* right = pop(&stack);
            struct ASTNode* operator = pop(&stack);
            struct ASTNode* left = pop(&stack);

            operator->left = left;
            operator->right = right;

            push(&stack, operator);
        } else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/') {
            push(&stack, createNode(expression[i]));
        }
    }

    return pop(&stack);
}

// Preorder 遍歷並輸出節點值的函數（忽略左右括號）
void preorderTraversal(struct ASTNode* root) {
    if (root != NULL) {
        // 判斷並輸出節點的值（忽略左右括號）
        if (isVariable(root->data) || (root->data != '(' && root->data != ')')) {
            printf("%c", root->data);
        }

        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    char expression[200000];  // 假設輸入表達式的最大長度為100

    //printf("請輸入表達式：");
    scanf("%s", expression);

    int length = 0;
    while (expression[length] != '\0') {
        length++;
    }

    struct ASTNode* root = buildAST(expression, length);

    //printf("抽象語法樹中的節點值（Preorder 遍歷）：\n");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
