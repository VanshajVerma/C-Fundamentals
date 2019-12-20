/*
program : staircase.c
Author : Vanshaj Verma
*/
# include <stdio.h>

int main(){

    // Defining the variables
    int n;

    // Taking the input
    printf("Enter number of staircases: ");
    scanf("%d", &n);

    // Conditional statement for making sure the input is in our range
    if (n>=0 && n<=100){

        // Loop for printing the patterns in 5's 
        // and conditional statement for the remaining.
        while(n>=5){
            printf("  #   #   #   #   #\n ##  ##  ##  ##  ##\n### ### ### ### ###\n");
            n = n - 5;
        }    
        if(n==4){
            printf("  #   #   #   #\n ##  ##  ##  ##\n### ### ### ###\n");
        }
        else if(n==3){
            printf("  #   #   #\n ##  ##  ##\n### ### ###\n");
        }
        else if(n==2){
            printf("  #   #\n ##  ##\n### ###\n");
        }
        else if(n==1){
            printf("  #\n ##\n###\n");
        }
    }

    // Required code if the input is out of the range
    else {
        printf("n=%d, must be in [0,100]\n", n);
        return 1;
    }


    return 0;
}