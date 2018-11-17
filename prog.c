#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void DebugArr(int * arr, int n){
  for (int i = 0; i < n; i++)
    printf("%d ",  arr[i]);
  printf("\n");
}

int* merge(int *elementA, int *elementB, int lengthA, int lengthB) {
  int* too = malloc(sizeof(int) * (lengthA + lengthB));
  int a = 0;
  int b = 0;
  for (int i = 0; i < lengthA + lengthB;) {
    if (a < lengthA && elementA[a] >= elementB[b])
      too[i++] = elementA[a++];

    if (b >= lengthB)
      too[i++] = elementA[a++];
      
    if (a >= lengthA)
      too[i++] = elementB[b++];
  
    if (b < lengthB && elementB[b] >= elementA[a])
      too[i++] = elementB[b++];
  }
  return too;
}

int* sort(int * mass, int length){
  if(length == 1){
    return mass;
  }
  int midle = length/2;
  return merge(&(sort(&mass[0], length/2)[0]), &(sort(&mass[length/2], length - length/2)[0]), length/2, length - length/2);
}

int main(void) {
  int n;
  scanf("%d", &n);
  int *arr = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  int *Mass = sort(&arr[0], n);
  DebugArr(Mass, n);
  return 0;
}