// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include<stdafx.h>
#include "omp.h"
#include<string>
#include<stdio.h>
#include <tchar.h> 
#include<time.h>
#include <ctime>
#include<iostream>
using namespace std;
clock_t t0;
void test()
{
    int a = 0;
    clock_t t1 = clock();
    for (int i = 0; i < 100000000; i++)
    {
        a = i + 1;
    }
    clock_t t2 = clock();
    printf("Thread%d Time = %d\n", omp_get_thread_num(), t2 - t1);
}
void test1() {
    int ifirst = 10;
    int k[600];
    int  i2=0;
    clock_t t1 = clock();
    for (int j = 0; j <= 60; j++)
    {
        #pragma omp parallel for shared(i2)
        for (int i = 0; i < 6000; i++) {
            #pragma omp critical
            i2 = i2+i - (i / 600) * 600;
            //k[i2] = ifirst + i;
        }
    }
    cout << i2 << endl;
    clock_t t2= clock();
    printf("Total time = %d\n", t2 - t1);

}
void test2() {
    int ifirst = 10;
    int k[600];
    int  i2=0;
    clock_t t1 = clock();
    for (int j = 0; j <= 60; j++)
    {
        #pragma omp parallel for
        for (int i = 0; i < 6000000; i++) {
            
            i2 =i2+ i - (i / 600) * 600;
            //k[i2] = ifirst + i;
        }
    }
    cout << i2 << endl;
    clock_t t2 = clock();
    printf("Total time = %d\n", t2 - t1);
}
void test3() {
    int ifirst = 10;
    int k[600];
    int  i2 = 0;
    clock_t t1 = clock();
    for (int j = 0; j <= 60; j++)
    {

        for (int i = 0; i < 6000; i++) {
            i2 = i2 + i - (i / 600) * 600;
            //k[i2] = ifirst + i;
        }
    }
    cout << i2 << endl;
    clock_t t2 = clock();
    printf("Total time = %d\n", t2 - t1);
}
int main(int argc, char* argv[])
{
    clock_t t1 = clock();
    t0 = clock();
   // omp_set_num_threads(8);
 //#pragma omp parallel for
    for (int j = 0; j < 16; j++) {
        
        //clock_t t2 = clock();
       // printf("Thread%d Time = %d\n", omp_get_thread_num(), t2 - t1);
        //printf("i= %d\n", j);
    }
    test1();
    test1();
    test2();
    test3();
    clock_t t2 = clock();
    printf("Total time = %d\n", t2 - t0);
    //test();
    return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
