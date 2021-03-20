#include <stdio.h>
#include <stdlib.h>

#define PRINT_Yes printf("Yes \n")
#define PRINT_No printf("No \n")
#define IS_NUMBER_IN_RANGE(x,limit) if(0 <= x && x < limit)PRINT_Yes; else PRINT_No;
#define PRINT_ELEMENT_MASS(dmass,i,j) printf("%d \n", (*(*(dmass+i))+j));
#define RETURN_ELEMENT_MASS(dmass,i,j) (*(*(dmass+i))+j);
#define GET_NUM_ELEMETS(arr) sizeof(arr)/sizeof(arr[0]);

int main()
{
    //Task 1-------------------------------------------------
    int n, limit;
    printf("Is number <= 0 and < limit? \n");
    printf("Input number: ");
    scanf("%d", &n);
    printf("Input limit: ");
    scanf("%d", &limit);

    IS_NUMBER_IN_RANGE(n,limit);

    //--------------------------------------------------------
    //Task2---------------------------------------------------
    n = 5;
    int p = 1;
    int** dmass = NULL;

    dmass = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        dmass[i] = (int*)calloc(n, sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dmass[i][j] = p++;
        }
    }

   //macros variant 1:
    PRINT_ELEMENT_MASS(dmass,3,2);
   //macros variant 2:
    int element = RETURN_ELEMENT_MASS(dmass,3,2);
    printf("%d \n", element);


    for(int i = 0; i < n; i++){
        free(dmass[i]);
    }
    free(dmass);
    //---------------------------------------------------
    //Task3---------------------------------------------
    int mass [] = {1,2,3,4,5,6};

    n = GET_NUM_ELEMETS(mass);
    printf("%d \n", n);

    system("pause");
    return 0;
}
