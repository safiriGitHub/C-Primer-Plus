# 第六章 C控制语句：循环

## while 循环
可以把下面的伪代码作为while循环的标准格式：

获得第1个用于测试的值
当测试为真时
处理值
获取下一个值

while循环的通用形式
```
while (expression)
statement
```

- 其他例子
```
while后面跟一行表达式语句
int n = 0;
while (n < 3)
printf(“n is %d\n”, n);
n++;
/// 会打印无数个 n= 0

while后语句块
int n = 0;
while (n < 3) {
	printf(“n is %d\n”, n);
	n++;
}
/// 打印
n=0
n=1
n=2
```

有时候会故意使用 带空语句的while语句，因为所有的任务都在测试条件中完成了，不需要在 循环体中做什么。
例如，假设你想跳过输入到第1个非空白字符或数字，可 以这样写： 
```
while (scanf("%d", &num) == 1)
 ; /* 跳过整数输入 */
```

## 关系运算符

while (number < 6)

while (ch != ‘$’)

注意：比较浮点数时，尽量使用`<` 和 `>`。因为浮点数的舍入误差会导致在逻辑上应该相等的两数却不相等。

while(0)   false
while(1)  true
while(2)  true
while(3)  true
while(-1)  true
while(-2)  true
一般而言，所有非零值都视为真，只有0被视为假

5 = canoes  -> 语法错误
5 == canoes -> 检查canoes的值是否为5
经验丰富的程序员在构建比较是否相等的表达式时，都习惯把常量放在左侧

_Bool类型
`input_is_good = (scanf("%ld", &num) == 1);`
C99提供了stdbool.h头文件，该头文件让bool成为_Bool的别名，而且还 把true和false分别定义为1和0的符号常量。包含该头文件后，写出的代码可 以与C++兼容，因为C++把bool、true和false定义为关键字。

## for循环
for循环把（初始化、测试和更新）组合在一处。

```

for(num=1;num<=6;num++)

可省略第三个表达式，但不能省略分号
for (n=3; ans <= 25;)
ans=ans*n;

省略第二个表达式被视为真,所以下面的循环会一直运行
for(; ;)

第一个表达式不一定是给变量赋初值，如使用printf()。
for(printf("Keep entering numbers!\n"); num != 6;)
scanf("%d", &num);
```

## 逗号运算符
扩展for循环的灵活性。
`for(ounces = 1, cost = 46; ounces <= 16; ounces++, cost += 20)`

`houseprice = 249, 500`   结果为249

`houseprice = (249, 500)`  结果为500

## 出口条件循环：do while
while /for 循环都是入口条件循环，即在循环的每次迭代之前检查测试条件

do while 循环出口条件循环，在循环的每次迭代之后检查测试条件。至少执行循环体一次

```
do 
statement
while (expression);
```
