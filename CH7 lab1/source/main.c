#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef struct _student
{
	char name[5];
	int chinese;
	int english;
	int math;
	int sum;
	float avg;
}student;

int main(void)
{
	student date[5];
	FILE *stream1, *stream2;
	int i;
	stream1 = fopen("D://abc.txt", "r");
	stream2 = fopen("D://abcd.txt", "w");
	if (stream1 == NULL || stream2 == NULL)
	{
		printf("檔案開啟失敗\n");
	}
	else
	{
		fprintf(stream2, "姓名\t國文\t英文\t數學\t總和\t平均\n");
		for (i = 0; i < 5; i++)
		{
			fscanf(stream1, "%s", date[i].name);
			fscanf(stream1, "%d", &date[i].chinese);
			fscanf(stream1, "%d", &date[i].english);
			fscanf(stream1, "%d", &date[i].math);
			date[i].sum = date[i].chinese + date[i].english + date[i].math;
			date[i].avg = date[i].sum / 3.0;
			fprintf(stream2, "%s\t%d\t%d\t%d\t%d\t%.2f\n", date[i].name, date[i].chinese, date[i].english, date[i].math, date[i].sum, date[i].avg);

		}
		fclose(stream1);
		fclose(stream2);
	}
	system("pause");
	return 0;

}