#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

char getch() {
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

void register_user();
void login_user();
void get_password(char *password);

#define max_user 10

int user_count = 0;

typedef struct {
    char user_name[50];
    char pass[50];
}User;

User users[max_user];

int main(){
    while(1){
        int opt;
        printf("\n\n-----WELCOME-----\n");
        printf("\n1.REGISTER");
        printf("\n2.LOGIN");
        printf("\n3.EXIT");
        printf("\nSelect an option: ");
        scanf("%d",&opt);

        switch (opt){
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                printf("\nThank you");
                return 0;
            default:
                printf("\nEnter a valid option");
        }    
    }
    printf("\nDeveloped by: ASUTOSH SAHU");
    return 0;
}

void register_user(){
    char username[50];
    char password[50];
    if (user_count >= max_user) {
        printf("\nUser limit reached. Cannot register more users.\n");
        return;
    }
    printf("\nEnter username: ");
    scanf("%s",username);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].user_name) == 0) {
            printf("\nUsername already exists. Try a different one.\n");
            return;
        }
    }

    printf("\nEnter password: ");
    get_password(password);
    
    strcpy(users[user_count].user_name, username);
    strcpy(users[user_count].pass, password);
    user_count++;
    printf("\nRegistered successfully");
}

void login_user(){
    char username[50];
    char password[50];
    printf("\nEnter username: ");
    scanf("%s",username);
    printf("\nEnter password: ");
    get_password(password);
    for (int i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].user_name) == 0 &&
            strcmp(password, users[i].pass) == 0) {
            printf("\nLogin successful");
            return;
        }
    }
    printf("\nInvalid username or password");
}

void get_password(char *password){
    int index = 0;
    char ch;
    while (1){
        ch = getch();
        if (ch == '\n' || ch == '\r'){
            break;
        }
        else if (ch == 127 || ch == '\b'){
            if (index > 0) {
                index--;
                printf("\b \b");
            }
        }
        else {
            password[index++] = ch;
            printf("*");
        }
    }
    password[index] = '\0';
}