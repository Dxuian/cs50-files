#include<stdio.h>

int main(){
    int atomicNumber[100] = {1, 2, 3, 4, 5, 6, 7};

    int atomicMass[] = {1, 2, 4, 6, 8, 10};

    int size = sizeof(atomicNumber)/sizeof(int);


    int number1;
    printf("Enter the number of elements you want to add \n");

    scanf("%d", &number1);

    while(number1 != 1){
        for(int i = 7; i <= 10; i++){
            int number;
            scanf("%d", &number);
            atomicNumber[i] = number;

            // printf("Do you want to continue? \nPress 1 to continue \n");

            // int choice;
            // scanf("%d", &choice);
            // if(choice != 1){
            //     break;
            // }
        }
        number1--;
    }



    for(int i = 0; i <= 10; i++){
        printf("%d ",atomicNumber[i]);
    }

    return 0;
}