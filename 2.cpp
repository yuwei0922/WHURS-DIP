#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;
void main()
{
	FILE* fp1 = nullptr;                                                                  //输入
	unsigned char grey[256 * 256];                                                        //定义原图像灰度值数组
	int grey1[256 * 256];                                                                 //定义进行处理的数组
	char filename[128];
	cout << "请输入待处理文件名称及格式：" << endl;
	cin.getline(filename, 128);
	fopen_s(&fp1, filename, "rb");
	fread(grey, sizeof(unsigned char), 256 * 256, fp1);                                   //读取文件
	for (int i = 0; i < 256 * 256; i++)
		grey1[i] = grey[i];                                                               //复制图像像素到grey1数组

	float temp[3][3] = { 1.0 / 16,2.0 / 16,1.0 / 16,                                     //定义卷积模板
						2.0 / 16,4.0 / 16,2.0 / 16,
						1.0 / 16,2.0 / 16,1.0 / 16 };
	for (int i = 1; i <= 254; i++)
	{
		for (int j = 1; j <= 254; j++)                                                    //不处理第一行/列,最后一行/列
		{
			grey1[i * 256 + j] = grey[(i - 1) * 256 + j - 1] * temp[0][0] + grey[(i - 1) * 256 + j] * temp[0][1] + grey[(i - 1) * 256 + j + 1] * temp[0][2] +
				grey[i * 256 + j - 1] * temp[1][0] + grey[i * 256 + j] * temp[1][1] + grey[i * 256 + j + 1] * temp[1][2] +
				grey[(i + 1) * 256 + j - 1] * temp[2][0] + grey[(i + 1) * 256 + j] * temp[2][1] + grey[(i + 1) * 256 + j + 1] * temp[2][2] ;
		}
	}
	unsigned char grey2[256 * 256];                                                       //再将处理后的数组grey1变为字符型grey2用于输出
	for (int i = 0; i < 256 * 256; i++)
		grey2[i] = grey1[i];

	FILE* fp2;                                                                           //输出
	char filename1[128];
	cout << "请输入输出文件名称及格式：" << endl;
	cin.getline(filename1, 128);
	fopen_s(&fp2, filename1, "wb");
	fwrite(grey2, sizeof(unsigned char), 256 * 256, fp2);
	fclose(fp2);
}