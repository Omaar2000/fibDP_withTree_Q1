#include <stdio.h>
#include <stdlib.h>


typedef enum TypeTag{
  ADD, MUL, SUB, DIV
};

typedef struct Node {
    enum TypeTag type;
    int val;
    struct Node* left ;
    struct Node* right;
} Node;

Node* makeFunc(enum TypeTag type, Node* left, Node* right){
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;

    return node;
}

Node* makeNode(int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->type = -1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void calc(Node* node)
{
        int left = node->left->val;
        int right = node->right->val;

        if(node->type == ADD){
            node->val = left + right;
        }

        else if(node->type == SUB){
            node->val =  right - left;
        }


        else if(node->type == MUL){
            node->val = left * right;
        }

        else if(node->type == DIV){
            node->val = right / left;
        }

}

 int fibonacci (int n, int *fib){



    for(int i = 0; i<n; i++)
        fib[i] = -1;

        fib[0] = 0;
        fib[1] = 1;



        int first = fib[n-1] != -1 ? fib[n-1] : fibonacci(n-1, fib);
        int sec = fib[n-2] != -1 ? fib[n-2] : fibonacci(n-2, fib);
        fib[n] = first + sec;

return fib[n];

 }


int main()
{

    Node *add = makeFunc(ADD, makeNode(10),makeNode(6));
    Node *mul = makeFunc(MUL, makeNode(9),makeNode(4));
    Node *sub = makeFunc(SUB, mul,add);



    calc(add);
    calc(mul);
    calc(sub);

    int fib[abs(sub->val)] ;

    fibonacci(abs(sub->val)-1, fib);

    for(int i = 0; i < abs(sub->val); i++)
    printf("%d\n", fib[i]);



  return 0;
}
