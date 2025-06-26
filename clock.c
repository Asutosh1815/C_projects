#include <stdio.h>
#include <time.h>
#include <unistd.h>

void fill_time(char*);

void main() {
    char time[50],cur_time[50];
    while (1){
        fill_time(time);
        sleep(1);
    }
    //Developed by: ASUTOSH SAHU
}

void fill_time(char *buffer){
    time_t raw_time;
    struct tm *current_time;
    raw_time = time(NULL);
    current_time = localtime(&raw_time);
    printf("\nCurrent Date & Time: %s\n",asctime(current_time));
}
