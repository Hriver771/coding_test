#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_array(unsigned char array[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    unsigned char array[3][3];
    int result = 0;
    srand(time(NULL));
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            array[i][j] = rand() % 236 + 10;
        }
    }
    print_array(array);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i == 1 && j==1){
                continue;
            }
            array[i][j] = array[i][j] > array[1][1] ? 1 : 0;
        }
    }
    print_array(array);

    for(int k=0; k<8; k++)
    {
        int i, j;
        if(k>=0 && k<3)
            i = 0;
        else if(k>=4 && k<7)
            i = 2;
        else
            i = 1;

        if(k>=2 && k<5)
            j = 2;
        else if(k==1 || k==5)
            j = 1;
        else
            j = 0;

        result += array[i][j] * pow(2,7-k);
    }
    printf("result = %d", result);
}