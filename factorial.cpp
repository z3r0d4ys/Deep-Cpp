#include <stdio.h>

int factorial(int n);

int main() {
 int num;
 printf("Please enter a number:\n");
 scanf("%d",&num);
 
 int result = factorial(num);
 printf("Result is %d\n",result);
 return 0;
}

int factorial(int n){
 if (n == 0) {
 return 1;
 } else {
 return n * factorial(n - 1);
 }
}
