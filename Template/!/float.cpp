// 保留 3 位小数， 舍入规则并不是四舍五入 
double f = 3.1415;
cout << setiosflags(ios::fixed);
cout << setprecision(3);
cout << f <<endl;
