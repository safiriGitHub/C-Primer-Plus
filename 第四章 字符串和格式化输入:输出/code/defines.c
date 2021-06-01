// defines.c -- 使用limit.h和float头文件中定义的明示常量
#include <stdio.h>
#include <limits.h> //整型限制
#include <float.h>  //浮点型限制

int main(void) {
    printf("整型的明示常量：");

    printf("char-----\n");
    printf("CHAR_BIT: %d\n", CHAR_BIT); // char类型的位数
    printf("ChAR_MAX: %d\n", CHAR_MAX); // char类型最大值
    printf("CHAR_MIN: %d\n", CHAR_MIN); // char类型最小值
    printf("SCHAR_MAX: %d\n", SCHAR_MAX); // signed char 最大值
    printf("SCHAR_MIN: %d\n", SCHAR_MIN); // signed char 最小值
    printf("UCHAR_MAX: %d\n", UCHAR_MAX); // unsigned char 最大值
    
    printf("short-----\n"); 
    printf("SHRT_MAX: %d\n", SHRT_MAX); // short 最大值
    printf("SHRT_MIN: %d\n", SHRT_MIN); // short 最小值
    printf("USHRT_MAX: %d\n", USHRT_MAX); // unsigned short 最大值

    printf("int-----\n");
    printf("INT_MAX: %d\n", INT_MAX); 
    printf("INT_MIN: %d\n", INT_MIN); 
    printf("UINT_MAX: %d\n", UINT_MAX); 

    printf("long-----\n");
    printf("LONG_BIT: %d\n", LONG_BIT);
    printf("LONG_MAX: %ld\n", LONG_MAX); 
    printf("LONG_MIN: %ld\n", LONG_MIN); 
    printf("ULONG_MAX: %lu\n", ULONG_MAX); 

    printf("long long-----\n");
    printf("LLONG_MAX: %lld\n", LLONG_MAX); 
    printf("LLONG_MIN: %lld\n", LLONG_MIN); 
    printf("ULLONG_MAX: %llu\n", ULLONG_MAX);

    printf("float-----\n");
    printf("FLT_MANT_DIG: %d\n", FLT_MANT_DIG); // float类型的尾数位数 
    printf("FLT_DIG: %d\n", FLT_DIG); //float类型的最小有效数字位数（十进制） 
    printf("FLT_MIN_10_EXP: %d\n", FLT_MIN_10_EXP); //带全部有效数字的float类型的最小负指数（以10为底）
    printf("FLT_MAX_10_EXP: %d\n", FLT_MAX_10_EXP); //float类型的最大正指数（以10为底）
    printf("FLT_MIN: %.100f\n", FLT_MIN); //保留全部精度的float类型最小正数
    printf("FLT_MAX: %.100f\n", FLT_MAX); //float类型的最大正数
    printf("FLT_EPSILON: %f\n", FLT_EPSILON); //1.00和比1.00大的最小float类型值之间的差值 ??什么意思


    printf("double-----\n");
    printf("DBL_MANT_DIG: %d\n", DBL_MANT_DIG); // float类型的尾数位数 
    printf("DBL_DIG: %d\n", DBL_DIG); //float类型的最小有效数字位数（十进制） 
    printf("DBL_MIN_10_EXP: %d\n", DBL_MIN_10_EXP); //带全部有效数字的float类型的最小负指数（以10为底）
    printf("DBL_MAX_10_EXP: %d\n", DBL_MAX_10_EXP); //float类型的最大正指数（以10为底）
    printf("DBL_MIN: %.100f\n", DBL_MIN); //保留全部精度的float类型最小正数 ？？如何打印
    printf("DBL_MAX: %.100f\n", DBL_MAX); //float类型的最大正数
    printf("DBL_EPSILON: %f\n", DBL_EPSILON); //1.00和比1.00大的最小float类型值之间的差值 ??什么意思

    
    return 0;
}