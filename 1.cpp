#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void main()
{
	//��ȡ�ļ�
	FILE* fp = nullptr;
	char grey[256 * 256];
	char filename[128];
	cout << "������������ļ����Ƽ���ʽ��" << endl;
	cin.getline(filename, 128);
	fopen_s(&fp, filename, "rb");                                                       //�򿪶������ļ�
	fread(grey, sizeof(unsigned char), 256 * 256, fp);                                  //�������ļ���ȡ
	if (fp == nullptr)
		printf("��ȡ�ļ�ʧ��\n");
	else
		printf("�ļ���ȡ�ɹ�\n");

	//��������
	int countData[256] = { 0 };                                                         //����ͳ������������
	float histRate[256] = { 0 };                                                        //���ü���Ƶ�ʵ�����
	for (int i = 0; i < 256 * 256; i++)
	{
		countData[grey[i]]++;                                                           //ͳ�Ƹ��Ҷȵ����ظ���
	}
	for (int i = 0; i < 256; i++)
	{
		histRate[i] = countData[i] / (256.0 * 256.0);                                     //��������Ҷȵ�Ƶ��
	}

	//���
	FILE* fp1 = nullptr;
	char filename1[128];
	cout << "���������ļ����Ƽ���ʽ��" << endl;
	cin.getline(filename1, 128);
	fopen_s(&fp1, filename1, "w+");
	fprintf(fp1, "grey   count    rate\n");
	for (int n = 0; n < 256; n++)
	{
		fprintf(fp1, "%d      %d        %f\n", n, countData[n], histRate[n]);          //ѭ�����ÿ���Ҷȼ��Լ�������Ƶ��
	}
	fclose(fp);                                                                        //�ر��ļ�


}