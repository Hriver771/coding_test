#include "stdafx.h"
 
 
int _tmain(int argc, _TCHAR* argv[])
{
    /////////////////외적구하기////////////////////
    D3DXVECTOR3 vec1(0.0f, 0.0f, 1.0f); //백터 입력
    D3DXVECTOR3 vec2(7.0f, 0.0f, 5.0f);
 
    D3DXVec3Cross(&vec1, &vec1, &vec2); //외적구하기
    printf("%f, %f, %f\n", vec1.x, vec1.y, vec1.z);
    
    return 0;
}