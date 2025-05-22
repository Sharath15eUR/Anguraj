#include <stdio.h>
#include <string.h>

struct day {
    char dayName[15];
    char tasks[3][50];
};

void inputtasks(struct day* day){
    printf("Enter the tasks for %s (type 'done' to stop):\n", day->dayName);
    int i = 0;
    char status = 'E'; // E for entering and D for done 
    while (status == 'E' && i < 3) {
        printf("  Task %d: ", i + 1);
        fgets(day->tasks[i], 50, stdin);
        day->tasks[i][strcspn(day->tasks[i], "\n")] = '\0';  // Remove newline

        if (strcmp(day->tasks[i], "done") == 0) {
            day->tasks[i][0] = '\0';  // Clear task
            status = 'D';
            break;
        }
        i++;
    }
}

void display(struct day* day){
    printf("Day: %s\n", day->dayName);
    for (int i = 0; i < 3; i++) {
        if (day->tasks[i][0] != '\0') {
            printf("  Task %d: %s\n", i + 1, day->tasks[i]);
        }
    }
    printf("\n");
}

int main(){
    struct day week[7] = {
        {"Monday"},
        {"Tuesday"},
        {"Wednesday"},
        {"Thursday"},
        {"Friday"},
        {"Saturday"},
        {"Sunday"}
    };

    for (int i = 0; i < 7; i++) {
        inputtasks(&week[i]); 
    }

    printf("\n----- Weekly Calendar -----\n");
    for (int i = 0; i < 7; i++) {
        display(&week[i]); 
    }

    return 0;
}
