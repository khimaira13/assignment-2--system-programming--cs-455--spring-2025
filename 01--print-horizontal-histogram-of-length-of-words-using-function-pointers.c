#include <stdio.h>
#define SIZE 10

void bubbleSort(int (*compare)(int,int),int arr[],int size);
void swap(int *leftNum,int *rightNum);
int ascending(int leftNum,int rightNum);
int descending(int leftNum,int rightNum);

int main(){
  int order;
  int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
  printf("Enter 1 to sort in ascending order,\nEnter 2 to sort in descending order: ");
  scanf("%d",&order);

  printf("\nData items in original order\n");

  for(int i = 0 ; i < SIZE ; i++){
    printf("%5d ",a[i]);
  }
  puts("");
  if(order == 1){
    bubbleSort(ascending,a,SIZE); 
    printf("\nData items in ascending order\n");
  }
  else if(order == 2){
    bubbleSort(descending,a,SIZE);
    printf("\nData items in ascending order\n");
  }
  else
    puts("Invalid input.");

  for(int i = 0 ; i < SIZE ; i++){
      printf("%5d ",a[i]);
  }
  puts("");
}

void bubbleSort(int (*compare)(int,int),int arr[],int size){
  for(int i = 0 ; i < size-1 ; i++){
    for(int j = 0 ; j < size-1-i ; j++){
      if(compare(arr[j],arr[j+1]))
        swap(&arr[j],&arr[j+1]);
    }
  }
}
void swap(int *leftNum, int *rightNum){
  int temp = *leftNum;
  *leftNum = *rightNum;
  *rightNum = temp;
}
int ascending(int leftNum,int rightNum){ //compare = ascending if order = 1
  return rightNum < leftNum;
}
int descending(int leftNum,int rightNum){ //compare = descending if order = 2
  return rightNum > leftNum;
}
