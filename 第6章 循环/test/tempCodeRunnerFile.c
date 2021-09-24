ain(void)
// {
//     double lucky = 1000000;
//     double lucky_reduce = 100000;
//     double lucky_grow = 0.08;
//     double lucky_num;
//     int year = 1;
//     printf("year\tlucky_num\t\n");
    
//     // lucky_num = lucky * pow((1+lucky_grow), year);
//     lucky_num = lucky * (1+lucky_grow);
//     while (lucky_num >= 0)
//     {
//         printf("%d\t%.2lf\n", year, lucky_num);
//         lucky_num -= lucky_reduce;
//         lucky_num = lucky_num * (1+lucky_grow);
//         year++;
//     }
    
//     return 0;
// }