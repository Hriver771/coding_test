#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_array(unsigned char * source_data, int N, int M)
{
    unsigned char data;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            data = source_data[i*M+j];
            printf("%d\t", data);
        }
        printf("\n");
    }
}

int convert_dec(unsigned char ** source_data)
{
    int result = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i == 1 && j==1){
                continue;
            }
            source_data[i][j] = source_data[i][j] > source_data[1][1] ? 1 : 0;
        }
    }
    print_array(source_data, 3, 3);

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
        result += source_data[i][j] * pow(2,7-k);
    }
    return result;

}

void convert(unsigned char ** source_data, int N, int M, unsigned char ** convert_data)
{
    
}


int main()
{
    int N, M;
    N = 3;
    M = 3;
    unsigned char * array = (unsigned char *)malloc(sizeof(unsigned char *)*M*N);
    srand(time(NULL));
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            array[M*i+j] = rand() % 236 + 10;
        }
    }
    print_array(array, 3, 3);
    double r = convert_dec(array);
    printf("test #3 (1) result = %f\n", r);

    unsigned char data[4][4] = {{37, 49, 72, 36},
                                {14, 48, 74, 28},
                                {23, 16, 82, 77},
                                {14, 13, 12, 89},
    };
    N = 4;
    M = 4;
    unsigned char ** array2 = (unsigned char **)malloc(sizeof(unsigned char *)*M);
    for(int i=0; i<M; i++)
    {
        array2[i] = (unsigned char *)malloc(sizeof(unsigned char)*N);
        array2[i] = data[i];
    }
    print_array(array2, N, M);

    unsigned char ** conv_data = (unsigned char **)malloc(sizeof(unsigned char *)*M);
    for(int i=0; i<M; i++)
    {
        conv_data[i] = (unsigned char *)malloc(sizeof(unsigned char)*N);
    }
    convert(array2, N, M, conv_data);
    print_array(conv_data, N, M);

}