#include <stdio.h>

int myMult(int fir, int sec);

int main(){
 int num1 = 21, num2 = 6;
 int result = myMult(num1, num2);
 printf("The result is %d\n", result);
}

int myMult(int fir, int sec){
 if (fir == 1) {
 return sec;
 } else {
 return sec + myMult(fir-1, sec);
 }
}
