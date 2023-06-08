/*
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
           // printf("%d\n", node->val);
        }

        else if(node->type == SUB){
            node->val =  right - left;
           // printf("%d\n", node->val);
        }


        else if(node->type == MUL){
            node->val = left * right;
            //printf("%d\n", node->val);
        }

        else if(node->type == DIV){
            node->val = right / left;
          //  printf("%d\n", node->val);
        }

        }
 //   }

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
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <tommath.h>

/*
int recursive(int n){
if(n == 0){
  return 0;
}
if(n == 1){
  return 1;
}
else if(n == 2){
  return 2;
}

return recursive(n-2) + recursive(n-3);

}

int dynamic(int n){

}

unsigned long long iterative(int n){

unsigned long long iter[n];

  iter[0] = 0;
  iter[1] = 1;
  iter[2] = 2;

  for(int i = 3; i<=n ; i++){
    iter[i] = iter[i-3] + iter[i-2];
    printf("for %d  --> %d\n  ",i, iter[i]);
}
    return iter[n];

}

int main(){
  int n = 90;
  unsigned long long sol;
  sol = iterative(n);

  // printf("Recursive Approach: %d = %d\n", n, recursive(n));
  // printf("Dynammic Programming Approach: %d = %d\n", n, dynamic(n));
  printf("Iterative Approach: %d = %d", n, iterative(n));
  // printf("                         %d  ", sol);
}
*/

void iterativeFibonacci(int n) {
    mpz_t a, b, c;
    mpz_inits(a, b, c, NULL);

    mpz_set_ui(a, 0);
    mpz_set_ui(b, 1);

    if (n <= 0) {
        gmp_printf("F(%d) = %Zd\n", n, a);
        return;
    }

    for (int i = 2; i <= n; i++) {
        mpz_add(c, a, b);
        mpz_set(a, b);
        mpz_set(b, c);
    }

    gmp_printf("F(%d) = %Zd\n", n, b);

    mpz_clears(a, b, c, NULL);
}

int main() {
    int n = 100; // Example input

    iterativeFibonacci(n);

    return 0;
}

