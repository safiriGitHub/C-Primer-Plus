/* randbin.c -- 用二进制I/O进行随机访问 */
// 随机访问是用二进制I/O写入二进制文件最常用的方式

#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main()
{
    double numbers[ARSIZE];
    double value;
    const char *file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;

    //创建一组double类型的值
    for (i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0*i + 1.0/(i+1);
    // 尝试打开文件
    if ((iofile  = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    //以二进制格式把数组写入文件
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);

    if ((iofile = fopen(file, "rb")) == NULL) 
    {
        fprintf(stderr, "Could not open %s for random access.\n", file); 
        exit(EXIT_FAILURE); 
    }
    //从文件中读取选定的内容
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >=0 && i < ARSIZE)
    {
        pos = (long)i*sizeof(double); //计算偏移量
        fseek(iofile, pos, SEEK_SET); //定位到此处
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value); 
        printf("Next index (out of range to quit):\n");
    }
    
    //完成
    fclose(iofile);
    puts("Bye!");
    return 0;
}

/*
numbers.dat 
不能用文本编辑器读取最后的二进制文件numbers.dat，因为无法把文件中的值转换成字符串。
然而，储存在文件中的每个值都 与储存在内存中的值完全相同，没有损失任何精确度。
此外，每个值在文件 中也同样占用64位存储空间，所以可以很容易地计算出每个值的位置。
*/