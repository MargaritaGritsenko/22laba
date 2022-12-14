#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#define SCREENW 60
#define SCREENH 40
typedef double (*TFun) (double);


double S(double);
double V(double);
double Y(double);
void t_rez(TFun, double, double, double);
void plot(double x0, double x1, TFun f);
void main()
{
    setlocale(LC_ALL, "RU");

    plot(-3, 15, S);
    /*int n=10,menu=10, menu3=10, menu2=10;
    int k;
    double a, b, h;
    while (n != 0)
    {
        printf("1-Вычислить значение\n2-Табулировать\n3-Выполнить операцию\n0-выход\n");
        scanf("%d", &n);
        switch (n) {
        case 1:
            while (menu != 0)
            {
                puts("Введите a");
                scanf("%lf", &a);
                printf("1-Функция V\n2-Функция S\n3-Функция Y\n0-выход\n");
                scanf("%d", &k);
                b = a;
                h = a;
                switch (menu) {
                case 1:
                    t_rez(V, a, b, h);
                    break;
                case 2:
                    t_rez(S, a, b, h);
                    break;
                case 3:
                    t_rez(Y, a, b, h);
                    break;
                default:
                    break;
                }
                break;
            }
        case 2:
            while (menu2 != 0)
            {
                printf("1-Функция V\n2-Функция S\n3-Функция Y\n0-выход\n");
                scanf("%d", &k);
                puts("Введите a,b, h");
                scanf("%lf%lf%lf", &a, &b, &h);
                switch (menu2) {
                case 1:
                    t_rez(V, a, b, h);
                    break;
                case 2:
                    t_rez(S, a, b, h);
                    break;
                case 3:
                    t_rez(Y, a, b, h);
                    break;
                default:
                    break;
                }
                break;
            }
        case 3:
            while (menu3 != 0)
            {
                printf("1-Функция V\n2-Функция S\n3-Функция Y\n0-выход\n");
                scanf("%d", &k);
                puts("Введите a,b");
                scanf("%lf%lf", &a, &b);
                h = 1;
                switch (menu3) {
                case 1:
                    plot(a, b, V);
                    break;
                case 2:
                    plot(a, b, S);
                    break;
                case 3:
                    plot(a, b, Y);
                    break;
                default:
                    break;
                }
                break;
        default:
            break;
            }
        }
    }*/

}
double S(double x) {
    return (fabs(sqrt(pow(x, 3))));
}
double V(double x) {
    if (x > 1) {
        return (tan(pow(x, 2) - 1));
    }
    if (x >= 0 && x <= 1) {
        return -22 * x;
    }
    if (x < 0) {
        return (cos(x));
    }
    return -1;
}
double Y(double r) {
    return (r - 1) / (r + 1) + 1. / 3 * pow((r - 1) / (r + 1), 3) + 1. / 5 * pow((r - 1) / (r + 1), 5) + 1. / 7 * pow((r - 1) / (r + 1), 7);
}
void t_rez(TFun f, double xn, double xk, double h)
{
    printf("______________________________\n");
    for (double x = xn; x <= xk; x += h) {
        printf("| x = %5.2lf | y = %8.4lf|\n", x, f(x));

    }
    printf("_______________________________\n");
}

void plot(double x0, double x1, TFun f)
{
    char screen[SCREENW][SCREENH];
    double x, y[SCREENW];
    double ymin = 0, ymax = 0;
    double hx, hy;
    int i, j;
    int xz, yz;
    hx = (x1 - x0) / (SCREENW - 1);
    for (i = 0, x = x0;i < SCREENW; ++i, x += hx) {
        y[i] = f(x); //расчет значений функции для каждой точки поля вывода графика
        if (y[i] < ymin) ymin = y[i];
        if (y[i] > ymax) ymax = y[i];
    }
    hy = (ymax - ymin) / (SCREENH - 1);
    yz = (int)floor(ymax / hy + 0.5);
    xz = (int)floor((0. - x0) / hx + 0.5);
    //построение осей и заполнение массива отображения пробелами
    for (j = 0;j < SCREENH; ++j)
        for (i = 0;i < SCREENW; ++i) {
            if (j == yz && i == xz) screen[i][j] = '+';
            else if (j == yz) screen[i][j] = '-';
            else if (i == xz) screen[i][j] = '|';
            else screen[i][j] = ' ';
        }
    //определение положения значения функции на поле вывода
    for (i = 0;i < SCREENW; ++i) {
        j = (int)floor((ymax - y[i]) / hy + 2);
        screen[i][j] = '*';
    }
    for (j = 0;j < SCREENH; ++j) {
        for (i = 0;i < SCREENW; ++i)  putchar(screen[i][j]);
        putchar('\n');
    }
}


