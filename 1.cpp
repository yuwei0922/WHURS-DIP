#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void main()
{
	//读取文件
	FILE* fp = nullptr;
	char grey[256 * 256];
	char filename[128];
	cout << "请输入待处理文件名称及格式：" << endl;
	cin.getline(filename, 128);
	fopen_s(&fp, filename, "rb");                                                       //打开二进制文件
	fread(grey, sizeof(unsigned char), 256 * 256, fp);                                  //二进制文件读取
	if (fp == nullptr)
		printf("读取文件失败\n");
	else
		printf("文件读取成功\n");

	//处理数据
	int countData[256] = { 0 };                                                         //设置统计数量的数组
	float histRate[256] = { 0 };                                                        //设置计算频率的数组
	for (int i = 0; i < 256 * 256; i++)
	{
		countData[grey[i]]++;                                                           //统计各灰度的像素个数
	}
	for (int i = 0; i < 256; i++)
	{
		histRate[i] = countData[i] / (256.0 * 256.0);                                     //计算各个灰度的频率
	}

	//输出
	FILE* fp1 = nullptr;
	char filename1[128];
	cout << "请输入结果文件名称及格式：" << endl;
	cin.getline(filename1, 128);
	fopen_s(&fp1, filename1, "w+");
	fprintf(fp1, "grey   count    rate\n");
	for (int n = 0; n < 256; n++)
	{
		fprintf(fp1, "%d      %d        %f\n", n, countData[n], histRate[n]);          //循环输出每个灰度级以及数量，频率
	}
	fclose(fp);                                                                        //关闭文件


}