#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int max_lenth = 20;
const int max_tasks = 5;

typedef struct {
    int id;
    int progress;
    int step;
} Task;

void print_bar(Task tasks);

void main(){
    Task tasks[max_tasks];
    srand(time(NULL));

    for (int i=0;i<max_tasks;i++){
        tasks[i].id = i+1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 5 + 1;
    }

    int tasks_incomplete = 1;
    while (tasks_incomplete){
        tasks_incomplete = 0;
        for (int i=0;i<max_tasks;i++){
            tasks[i].progress += tasks[i].step;
            if (tasks[i].progress > 100){
                tasks[i].progress = 100;
            }
            else if (tasks[i].progress < 100){
                tasks_incomplete = 1;
            }
            print_bar(tasks[i]);
        }
        sleep(1);
        printf("\n");
    }
    printf("All tasks completed!\n");
    printf("\nDeveloped by: ASUTOSH SAHU");
}

void print_bar(Task tasks){
    int bars_to_show = (tasks.progress * max_lenth) / 100;
    printf("Task %d: [",tasks.id);
    for (int i=0;i<max_lenth;i++){
        if (i < bars_to_show){
            printf("=");
        }
        else{
            printf(" ");
        }
    }
    printf("] %d%%\n",tasks.progress);
}