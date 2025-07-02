#include <stdio.h>
#include <string.h>

const char *ACCOUNT_FILE = "accounts.dat";

void create_account();
void deposit();
void withdraw();
void check_balance();

typedef struct {
    char name[50]; 
    int acc_no;
    float balance;
} Account;

int main(){
    int opt;
    while (1){
        printf("\n\n-----WELCOME-----\n");
        printf("\n1.CREATE ACCOUNT");
        printf("\n2.DEPOSIT MONEY");
        printf("\n3.WITHDRAW MONEY");
        printf("\n4.CHECK BALANCE");
        printf("\n5.EXIT");
        printf("\nSelect one option: ");
        scanf("%d",&opt);

        switch (opt){
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("\nThank you");
                return 0;
                break;
            default:
                printf("\nEnter a valid option");
                break;
        }
    }
    printf("\nDeveloped by: ASUTOSH SAHU");
    return 0;
}

void create_account(){
    Account acc;
    FILE *f = fopen(ACCOUNT_FILE,"ab+");
    if (f == NULL){
        printf("\nError in opening file");
        return;
    }

    char c;
    do{
        c = getchar();
    }
    while(c != '\n' && c != EOF);

    printf("\nEnter name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    int index = strcspn(acc.name, "\n");
    acc.name[index] = '\0';
    printf("\nEnter account no: ");
    scanf("%d",&acc.acc_no);
    acc.balance = 0;
    
    fwrite(&acc,sizeof(acc),1,f);
    fclose(f);
    printf("\nAccount created successfully");
}

void deposit(){
    FILE *f = fopen(ACCOUNT_FILE,"rb+");
    if (f == NULL){
        printf("\nError in opening file");
        return;
    }

    int acc_no;
    float money;
    Account acc_r;
    printf("\nEnter your account number: ");
    scanf("%d",&acc_no);
    printf("\nEnter amount to deposit: ");
    scanf("%f",&money);

    while (fread(&acc_r,sizeof(acc_r),1,f)){
        if (acc_r.acc_no == acc_no){
            acc_r.balance += money;
            fseek(f,-sizeof(acc_r),SEEK_CUR);
            fwrite(&acc_r,sizeof(acc_r),1,f);
            fclose(f);
            printf("\nSuccessfully deposited Rs.%.2f \nNew balance is Rs.%.2f",money,acc_r.balance);
            return;
        }
    }
    fclose(f);
    printf("\nAccount not found");
}

void withdraw(){
    FILE *f = fopen(ACCOUNT_FILE,"rb+");
    if (f == NULL){
        printf("\nError in opening file");
        return;
    }

    int acc_no;
    float money;
    Account acc_r;
    printf("\nEnter your account number: ");
    scanf("%d",&acc_no);
    printf("\nEnter the amount to withdraw: ");
    scanf("%f",&money);

    while(fread(&acc_r,sizeof(acc_r),1,f)){
        if (acc_r.acc_no == acc_no){
            if (acc_r.balance >= money){
                acc_r.balance -= money;
                fseek(f,-sizeof(acc_r),SEEK_CUR);
                fwrite(&acc_r,sizeof(acc_r),1,f);
                printf("\nSuccessfully withdrawn Rs.%.2f \nRemaining balance is Rs.%.2f",money,acc_r.balance);
            }
            else{
                printf("\nInsufficient balance");
            }
            fclose(f);
            return;
        }
    }
    fclose(f);
    printf("\nAccount not found");
}

void check_balance(){
    FILE *f = fopen(ACCOUNT_FILE,"rb");
    if (f == NULL){
        printf("\nError in opening file");
        return;
    }

    int acc_no;
    Account acc_read;
    printf("\nEnter your account number: ");
    scanf("%d",&acc_no);

    while(fread(&acc_read,sizeof(acc_read),1,f)){
        if (acc_read.acc_no == acc_no){
            printf("\nYour current balance is Rs.%.2f",acc_read.balance);
            fclose(f);
            return;
        }
    }
    fclose(f);
    printf("\nAccount not found");
}