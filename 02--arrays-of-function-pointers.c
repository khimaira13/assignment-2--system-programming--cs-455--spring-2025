#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void printArray(int [][EXAMS], size_t, size_t);
void minimum(int [][EXAMS], size_t, size_t);
void maximum(int [][EXAMS], size_t, size_t);
void average(int [][EXAMS], size_t, size_t);

int main(){
  int choice = 5;
  int studentGrades[STUDENTS][EXAMS] = {
    {77, 68, 86, 73},
    {96, 87, 89, 78},
    {70, 90, 86, 81}};
  
  void (*processGrades[4])(int [][EXAMS], size_t, size_t) =
    {printArray, minimum, maximum, average};

  while(choice!=4){
    printf("\nEnter a choice:\n");
    printf("  0 Print the array of grades\n");
    printf("  1 Find the minimum grade\n");
    printf("  2 Find the maximum grade\n");
    printf("  3 Print the average on all tests for each student\n");
    printf("  4 End program\n? ");
    scanf("%d",&choice);
    switch(choice){
      case 0:processGrades[choice](studentGrades,STUDENTS,EXAMS); break; //printArray
      case 1:processGrades[choice](studentGrades,STUDENTS,EXAMS); break; //minimum
      case 2:processGrades[choice](studentGrades,STUDENTS,EXAMS); break; //maximum
      case 3:processGrades[choice](studentGrades,STUDENTS,EXAMS); break; //average
      case 4: printf("\nProgram Ended.\n"); break; //end the program
      default: printf("\nInvalid input.\n"); break; //input < 0 or input > 4
    }
  }
}
void printArray(int grades[][EXAMS], size_t students, size_t exams){
  
  printf("\n%22s%5s%5s%5s\n","[0]","[1]","[2]","[3]");
  for(int i = 0; i < students; i++){
    printf("studentGrades[%d] ",i);
    for(int j = 0 ; j < exams; j++){
      printf("%5d",grades[i][j]);
    }
    puts("");
  }
}

void minimum(int grades[][EXAMS], size_t students, size_t exams){
  int min = grades[0][0];
  for(size_t i = 0 ; i < students ; i++){
    for(size_t j = 0 ; j < exams ; j++){
      if(grades[i][j] < min)
        min = grades[i][j];
    }
  }
  printf("\nThe lowest grade is %d\n",min);
 }
 void maximum(int grades[][EXAMS], size_t students, size_t exams){
  int max = grades[0][0];
  for(size_t i = 0 ; i < students ; i++){
    for(size_t j = 0 ; j < exams ; j++){
      if(grades[i][j] > max)
        max = grades[i][j];
    }
  }
  printf("\nThe highest grade is %d\n",max);
 }

 void average(int grades[][EXAMS], size_t students, size_t exams){
  double sum1=0,sum2=0,sum3=0;
  for(int i = 0, j = 1, k = 2, exam = 0 ; exam < exams ; exam++){ //hardcoded for O(n) because students# is defined (fixed) otherwise it would be double for loop for code flexibility
    sum1=sum1+grades[i][exam];
    sum2=sum2+grades[j][exam];
    sum3=sum3+grades[k][exam];
  }
  printf("\nThe average for student 1 is %0.1f",sum1/exams);
  printf("\nThe average for student 2 is %0.1f",sum2/exams);
  printf("\nThe average for student 3 is %0.1f\n",sum3/exams);
 }
