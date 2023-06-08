#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// #include<gmpxx.h>  We should use a library like this for huge numbers that long long can't store
//                    Unfortunatly I am having a problem installing the libraries, I will fix it ASAP.
//                                                                                                  
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

  long long dyn[n];
  
    for(int i = 0; i<n; i++)
        dyn[i] = -1;

        dyn[0] = 0;
        dyn[1] = 1;
        dyn[2] = 2;



        int first = dyn[n-2] != -1 ? dyn[n-2] : dynamic(n-2);
        int sec = dyn[n-3] != -1 ? dyn[n-3] : dynamic(n-3);
        dyn[n] = first + sec;

return dyn[n];

}

long long iterative(int n){

long long iter[n];

  iter[0] = 0;
  iter[1] = 1;
  iter[2] = 2;

  for(int i = 3; i<=n ; i++){
    iter[i] = iter[i-3] + iter[i-2];
    
}
    return iter[n];

}

int main(){
  int n = 70; // To Use INT_MAX we should use library that handles arbitrary precision integers such as bigint.h, tommath.h, gmp.h, etc.. . 
              //  but as I said theres a problem with installing them and I don't have enough time to fix the problem because of the college exams.
  

  printf("Recursive Approach: %d = %d\n", n, recursive(n));
  printf("Dynammic Programming Approach: %d = %d\n", n, dynamic(n));
  printf("Iterative Approach: %d = %d", n, iterative(n));
}
