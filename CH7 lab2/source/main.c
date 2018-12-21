#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct cliendate
{
	int acctnum;
	char lastname[15];
	char firstname[10];
	double balance;
};
int main(void)
{
	FILE *pRead, *pWrite;
	FILE *cfptr;
	int cnt = 0;
	struct cliendate client = { 0,"","",0.0 };
	pRead = fopen("D://credit.txt", "r");
	if (NULL == pRead)
	{
		return 0;
	}
	pWrite = fopen("D://credit_bin.txt", "wb");
	if (NULL == pWrite)
	{
		fclose(pRead);
		return 0;
	}
	while (!feof(pRead))
	{
		fscanf(pRead, "%d%s%s%lf", &client.acctnum, &client.lastname, &client.firstname, &client.balance);
		fwrite(&client, sizeof(struct cliendate), 1, pWrite);
		printf("%-6d%-16d%-11s%10.2f\n", client.acctnum, client.lastname, client.firstname, client.balance);
	}
	fclose(pRead);
	fclose(pWrite);
	printf("已讀取文字檔的ACSII資料，並轉成二進位資料檔案\n\n");
	system("pause");
	printf("\n讀取二進制資料檔案，並格式化輸出如下:\n");
	if ((cfptr = fopen("D://credit_bin.txt", "rb")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "ACCt", "last name", "first name", "balance");
		cnt = fread(&client, sizeof(struct cliendate), 1, cfptr);

		while (cnt > 0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.acctnum, client.lastname, client.firstname, client.balance);
			cnt = fread(&client, sizeof(struct cliendate), 1, cfptr);
		}
		fclose(cfptr);
	}
	system("pause");
	return 0;
}


