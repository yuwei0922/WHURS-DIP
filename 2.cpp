#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;
void main()
{
	FILE* fp1 = nullptr;                                                                  //����
	unsigned char grey[256 * 256];                                                        //����ԭͼ��Ҷ�ֵ����
	int grey1[256 * 256];                                                                 //������д��������
	char filename[128];
	cout << "������������ļ����Ƽ���ʽ��" << endl;
	cin.getline(filename, 128);
	fopen_s(&fp1, filename, "rb");
	fread(grey, sizeof(unsigned char), 256 * 256, fp1);                                   //��ȡ�ļ�
	for (int i = 0; i < 256 * 256; i++)
		grey1[i] = grey[i];                                                               //����ͼ�����ص�grey1����

	float temp[3][3] = { 1.0 / 16,2.0 / 16,1.0 / 16,                                     //������ģ��
						2.0 / 16,4.0 / 16,2.0 / 16,
						1.0 / 16,2.0 / 16,1.0 / 16 };
	for (int i = 1; i <= 254; i++)
	{
		for (int j = 1; j <= 254; j++)                                                    //�������һ��/��,���һ��/��
		{
			grey1[i * 256 + j] = grey[(i - 1) * 256 + j - 1] * temp[0][0] + grey[(i - 1) * 256 + j] * temp[0][1] + grey[(i - 1) * 256 + j + 1] * temp[0][2] +
				grey[i * 256 + j - 1] * temp[1][0] + grey[i * 256 + j] * temp[1][1] + grey[i * 256 + j + 1] * temp[1][2] +
				grey[(i + 1) * 256 + j - 1] * temp[2][0] + grey[(i + 1) * 256 + j] * temp[2][1] + grey[(i + 1) * 256 + j + 1] * temp[2][2] ;
		}
	}
	unsigned char grey2[256 * 256];                                                       //�ٽ�����������grey1��Ϊ�ַ���grey2�������
	for (int i = 0; i < 256 * 256; i++)
		grey2[i] = grey1[i];

	FILE* fp2;                                                                           //���
	char filename1[128];
	cout << "����������ļ����Ƽ���ʽ��" << endl;
	cin.getline(filename1, 128);
	fopen_s(&fp2, filename1, "wb");
	fwrite(grey2, sizeof(unsigned char), 256 * 256, fp2);
	fclose(fp2);
}