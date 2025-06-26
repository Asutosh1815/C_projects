#include <stdio.h>
#include <math.h>

void main(){
    int opt,num1,num2,res;
    while (1) {
        printf("\n----------------");
        printf("\n1.ADD");
        printf("\n2.SUBTRACT");
        printf("\n3.MULTIPLY");
        printf("\n4.DIVIDE");
        printf("\n5.MODULUS");
        printf("\n6.POWER");
        printf("\n7.EXIT");
        printf("\nChoose one option: ");
        scanf("%d",&opt);

        if (opt == 7){
            printf("Thank you");
            break;
        }
        else if (opt < 1 || opt > 7){
            printf("Enter a valid option");
            continue;
        }

        printf("\nEnter first number: ");
        scanf("%d",&num1);
        printf("\nEnter second number: ");
        scanf("%d",&num2);

        switch (opt){
            case 1:
                res=num1+num2;
                break;
            case 2:
                res=num1-num2;
                break;
            case 3:
                res=num1*num2;
                break;
            case 4:
                res=num1/num2;
                break;
            case 5:
                res=num1%num2;
                break;
            case 6:
                res=pow(num1,num2);
                break;
        }
        printf("\nResult = %d",res);
    }
    printf("\nDeveloped by: ASUTOSH SAHU");
}