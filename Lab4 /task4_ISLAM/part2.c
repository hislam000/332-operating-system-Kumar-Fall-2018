/*
Csc332 - Operating System Lab
DUE: November 2, 2018
Hasibul Islam

PART 2 Average Grade Calculator
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) { 

    int value_x;    
    int value_y;    
    int level;
    int row= 0;     
    int col= 0;
    int i = 0;      
    int j = 0;

    //average
    double calculate_avg= 0; 
    printf("\nEnter ## Chapters: "); 
    scanf("%d", &value_x);
    printf("\nEnter HW##: "); 
    scanf("%d", &value_y);

    //varibale_row as v_row
    //varibale_col as v_col
    const int v_row = 10, v_col = value_x*value_y;
    double quiz_grades [v_col] [v_row], avg [v_col]; 

    FILE * test = fopen("quiz_grades.txt", "read"); // Using the source file to open

    while(row < v_row) {
    while(col < v_col) {
            fscanf(test, "%lf", &quiz_grades[col][row]);
            col++;
        }
            col =0;     row++;
    }
            row = 0;    col = 0;
    while(i < value_x) {    wait(&level);
        //Manager processes.
        //Data Type: process ID
        pid_t manager_pro = fork();
    if(manager_pro == 0){
            col = value_y * i; 
    while(j < value_y) {    wait(&level);
        //Worker process
        //Data Type: process ID
        pid_t worker_pro= fork();

    if(worker_pro == 0){
    while(row < v_row){ 
            calculate_avg += quiz_grades[col][row]; row++;    
        }
            avg[col] = calculate_avg / v_row; 
printf("\nCalculate_Average: HW#%d: %f \n",(col + 1), avg[col]); 
                    exit(0); 
                }
    else if (worker_pro< 0){   
                perror("Worker Error"); }
    else   {
        if(wait(&level) == -1) {
                        printf("Worker Error\n");}
        }
            row = 0;    col++;   j++;
        }
            exit(0);
        }
    else if(manager_pro < 0) {
            perror("Manager Error");
            return 1;
        }
    else {
        if(wait(&level) == -1) {
                printf("Manager Error\n"); }
        }
            j = 0;  i++;
        }      
    fclose(test); 
    return 0;
}
