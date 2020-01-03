#include <stdio.h>
#include <math.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

double fun_rect_area(int left, int top, int right, int bottom)
{
    return (right - left) * (top - bottom);
}

double fun_rect(int left1, int top1, int right1, int bottom1, int left2, int top2, int right2, int bottom2)
{
    double result;
    if (left1 < right2 && right1 > left2 && top1 > top2 && bottom1 < bottom2 )
    {
        result = 0;
    }
    else
    {
        int interL = MAX(left1, left2); 
        int interR = MIN(right1, right2);
        int interT = MIN(top1, top2);
        int interB = MAX(bottom1, bottom2);
        result = fun_rect_area(interL, interT, interR, interB);
    }

    return result;
}

double fun_circle(int x1, int y1, int r1, int x2, int y2, int r2)
{
    int a = x1 - x2;
    int b = y1 - y2;
    double d = sqrt((a * a) + (b * b));

    if(d < r1 || d < r2)
    {
        int smallR = r1<r2?r1:r2;
        double area = (double)smallR*(double)smallR*M_PI;
        return area;
    }
    else if(d < (r1 + r2))
    {
        int a = r1>r2?r1:r2;
        int b = r1<r2?r1:r2;
        double s = ( a*a * (2*acos((d*d-(a*a - b*b))/(2*a*d))) - sin(2*acos((d*d-(a*a - b*b))/(2*a*d)))
                   + b*b * (2*acos((d*d+(a*a - b*b))/(2*b*d))) - sin(2*acos((d*d+(a*a - b*b))/(2*b*d)))
                   )/2;

    }
    else if(d > (r1 + r2))
    {
        printf("No intersection");
        return 0;
    }
}

int main()
{
    double result1, result2;
    result1 = fun_rect(0, 12, 5, 8, 3, 10, 8, 7);
    printf("result1 = %0.2f", result1);

    double cir1, cir2, cir3;
    cir1 = fun_circle(5, 5, 5, 3, 3, 3);
    printf("겹칠 때: %f", cir1);
    cir2 = fun_circle(5, 5, 5, 14, 3, 3);
    printf("case3 = %f", cir2);
    cir3 = fun_circle(5, 5, 5, 5,3, 3);
    printf("case2 = %f", cir3);
}