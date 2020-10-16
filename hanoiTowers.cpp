#include <stdio.h>

void hanoi(int n, char source, char destination, char auxillary){
 
 if (n == 1) {
 printf("Move the top disk from %c to %c\n", source, destination);
 return;
 }
 
 hanoi(n-1, source, auxillary, destination);
 printf("Move the top disk from %c to %c\n", source, destination);
 hanoi(n-1, auxillary, destination, source);
 }

int main(){
 int n = 3;
 hanoi(n, 'A', 'C', 'B');
}
