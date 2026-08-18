#include "sign.h"
int get_sign(char *operand)
{
    if(operand[0]=='-')
    {
        return -1;
    }
    return 1;
}
int check_sign_combination(int flag1, int flag2)
{
    if (flag1 == 1 && flag2 == 1)
    {
        return 1;
    }
    else if (flag1 == 1 && flag2 == -1)
    {
        return 2;
    }
    else if (flag1 == -1 && flag2 == 1)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}
int check_subtraction_sign(int flag1, int flag2)
{
    if(flag1==1 && flag2==1)
    {
        return 1;
    }
    else if(flag1==1 && flag2==-1)
    {
        return 2;
    }
    else if(flag1==-1 && flag2==1)
    {
      return 3;
    }
    else
    {
        return 4;
    }
}

int check_multiplication_sign(int flag1, int flag2)
{
    if(flag1==1 && flag2==1)
    {
        return 1;
    }
    else if(flag1==1 && flag2==-1)
    {
        return 2;
    }
    else if(flag1==-1 && flag2==1)
    {
      return 3;
    }
    else
    {
        return 4;
    }
}

int check_division_sign(int flag1,int flag2)
{
    if(flag1==1 && flag2==1)
    {
      return 1;
    }
    else if(flag1==1 && flag2==-1)
    {
        return 2;
    }
    else if(flag1==-1 && flag2==1)
    {
      return 3;
    }
    else
    {
        return 4;
    }
}