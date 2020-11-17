#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#define M 10000;
using namespace std;
FILE *fp;
int planeCount = 0;
int use = 0;
int inf = 0;
struct plane
{
	int ID;			 //����ID
	char time[20];   //��ʱ��
	char data[10];   //����
	char start[10];  //���
	char end[10];	//�յ�
	int ticketCount; //Ʊ��
	int price;		 //Ʊ��
} data[100];
struct people
{
	int bill;	  //�˿Ͷ���
	char name[10]; //����
	char card[18]; //���֤��
	int ticket;	//Ʊ��
	int airID;	 //�����
} user[100];
void login();
void search();
void book();
void back();
void bill();
void drop();
void main_menu();
int deal();
void admire();
void input();
void listOfPlanes();
void update();
void order();
void search_end();
void search_id();
int readData();
void passager();
int userData();
int userWrite();
void quicksort();
int main()
{
	readData();
	userData();
	main_menu();
return 0;}
int readData() //��ȡ�ļ�
{
	int i = 0;
	if ((fp = fopen("plane.txt", "r+")) == NULL)
	{
		return 0;
	}
	while (~fscanf(fp, "%d %s %s %s %s %d %d", &data[i].ID, data[i].time, data[i].data, data[i].start, data[i].end, &data[i].ticketCount, &data[i].price))
	{
		i++;
		planeCount++;
	}
	fclose(fp);
	return 0;
}
int writeData() //д���ļ�
{
	int i;
	if ((fp = fopen("plane.txt", "w")) == NULL)
	{
		return 0;
	}
	for (i = 0; i < planeCount; i++)
	{

		fprintf(fp, "%d %s %s %s %s %d %d\n", data[i].ID, data[i].time, data[i].data, data[i].start, data[i].end, data[i].ticketCount, data[i].price);

	}

	fclose(fp);

	return 0;

}



int account;



int deal()

{

	int i=0, t = -1;

	printf("�������˺ţ�");

	scanf("%d", &account);

	if (account == 10086)

	{

		printf("\n");

		admire();

	}

	return t;

}



int userData() //��ȡ�ļ�

{

	int i = 0;

	if ((fp = fopen("user.txt", "r+")) == NULL)

	{

		return 0;

	}

	while (~fscanf(fp, "%d %s %s %d %d", &user[i].bill, user[i].name, user[i].card, &user[i].ticket, &user[i].airID))

	{

		i++;

		use++;

	}

	fclose(fp);

	return 0;

}



int userWrite() //д���ļ�

{

	int i;



	if ((fp = fopen("user.txt", "w")) == NULL)

	{

		return 0;

	}

	for (i = 0; i < use; i++)

	{

		fprintf(fp, "%d %s %s %d %d\n", user[i].bill, user[i].name, user[i].card, user[i].ticket, user[i].airID);

	}

	fclose(fp);

	return 0;

}



void main_menu()

{

	account = 0;

	int choic_number; //����ѡ��

	printf("+------��ӭʹ���ʳȷɻ���Ʊϵͳ-------+\n");

	printf("|     1.���   |\n");

	printf("|     2.��ѯ   |\n");

	printf("|     3.��Ʊ   |\n");

	printf("|     4.��Ʊ   |\n");

	printf("|     5.����   |\n");

	printf("|     6.�˳�   |\n");

	printf("|     0.����   |\n");

	printf("+----------------------------------+\n");

	printf("���������ָ��:");

	scanf("%d", &choic_number);

	switch (choic_number)

	{

	case 0:

		login(); //��¼

		break;



	case 1:

		listOfPlanes(); //���

		break;



	case 2:

		search(); //��ѯ

		break;

	case 3:

		book(); //��Ʊ

		break;

	case 4:

		back(); //��Ʊ

		break;

	case 5:

		bill(); //����

		break;

	case 6:

		drop(); //�˳�

		break;

	default:

		printf("�����������������\n");

		main_menu();

		break;

	}

}



void login()

{deal();

}



void search()

{

	int select;
 int i = 0, sum = 0;

	printf("***************************************************\n");

	printf("  1��������Ų�ѯ  2�����ִ�ص��ѯ\n");

	printf("***************************************************\n");

	printf("�������ѯ��ʽ:");

	scanf("%d", &select);

	if (select == 1)

		search_id();

	else if (select == 2)

		search_end();

	else

	{

		printf("������ѡ��\n");

		system("cls");

		search();

	}

}



int binary_research(int left, int right, int element)

{

	while (left <= right)

	{

		int mid = (left + right) / 2;

		if (data[mid].ID > element)

		{

			right = mid - 1;

		}

		else if (data[mid].ID < element)

		{

			left = mid + 1;

		}

		else

		{

			return mid;

		}

	}

	return -1;

}



void search_id()

{

	int a_id, c = planeCount;

	int i = -1, w = 0;

	printf("��������Ҫ��ѯ�ķɻ�����ţ�");
scanf("%d", &a_id);

	system("cls");

	i = binary_research(0, c, a_id);

	if (i != -1)

	{

		printf("����ID ��ʱ�� ������� ��� �յ� �۸� ��Ʊ\n");

		printf("%d %s %s %s %s %d %d\n", data[i].ID, data[i].time, data[i].data, data[i].start, data[i].end, data[i].ticketCount, data[i].price);

	}

	if (i == -1)

		printf("û�������ѯ�ĺ���!\n");

	system("pause");

	main_menu();

}



void search_end()

{

	char a_end[20];

	int i, w = 0;

	printf("��������Ҫǰ����Ŀ�ĵأ�");

	scanf("%s", a_end);

	printf("����ID ��ʱ�� ������� ��� �յ� �۸� ��Ʊ\n");

	for (i = 0; i < planeCount; i++)

	{

		if (strcmp(a_end, data[i].end) == 0)

		{

			w = 1;

			printf("%d %s %s %s %s %d %d\n", data[i].ID, data[i].time, data[i].data, data[i].start, data[i].end, data[i].ticketCount, data[i].price);

		}

	}

	printf("\n");

	if (w == 0)

		printf("û�������ѯ�ĺ���!\n");

	system("pause");

	main_menu();

}



void book()

{

	char a_end[20];

	int i, w = 0, p, num, s;

	printf("��������Ҫǰ����Ŀ�ĵأ�");

	scanf("%s", a_end);

	printf("����ID ��ʱ�� ������� ��� �յ� �۸� ��Ʊ\n");

	for (i = 0; i < planeCount; i++)

	{

		if (strcmp(a_end, data[i].end) == 0 && data[i].ticketCount != 0)

		{

			w = 1;

			printf("%d %s %s %s %s %d %d\n", data[i].ID, data[i].time, data[i].data, data[i].start, data[i].end, data[i].ticketCount, data[i].price);

		}

	}

	if (w != 0)

	{

		printf("��ѡ�����ĺ���:");

		scanf("%d", &p);

		for (i = 0; i < planeCount; i++)

		{

			if (p == data[i].ID)

			{

				printf("�������������:");

				scanf("%s", &user[use].name);

				printf("���������֤����:");

				scanf("%s", &user[use].card);

				printf("�����빺Ʊ��");

				scanf("%d", &num);

				printf("ȷ�Ϲ�Ʊ��֧��%dԪ,�밴1ȷ��:", data[i].price * num);

				scanf("%d", &s);

				printf("��Ʊ�ɹ�");

				data[i].ticketCount -= num;

				writeData();

				user[use].bill = use + 1009;

				user[use].ticket = num;

				user[use].airID = data[i].ID;

				use++;

				userWrite();

			}

		}

	}

	printf("\n");

	if (w == 0)

		printf("û�������ѯ�ĺ���!\n");

	system("pause");

	main_menu();

}



void back()

{

	char lname[10];

	char lcard[10];

	int b, y;

	int i, w = 0;

	printf("��������������:");

	scanf("%s", lname);

	printf("����������֤����:");

	scanf("%s", lcard);

	for (i = 0; i < use; i++)

		if (strcmp(lname, user[i].name) == 0 && user[i].ticket != 0 && strcmp(lcard, user[i].card) == 0)

		{

			if (w == 0)

				printf("�˿Ͷ��� ���� ���֤�� Ʊ�� �����\n");

			w++;

			printf("%d %s %s %d %d\n", user[i].bill, user[i].name, user[i].card, user[i].ticket, user[i].airID);

		}

	if (w == 0)

	{

		printf("�Բ���,�����ڸó˿�!\n");

	}

	else

	{

		printf("�����붩��:");

		scanf("%d", &b);

		int j, t;

		for (i = 0; i < use; i++)

			if (b == user[i].bill)

			{

				t = i;

				printf("ȷ����Ʊ1:");

				scanf("%d", &y);

				if (y == 1)

				{

					for (j = 0; j < planeCount; j++)

					{

						if (data[j].ID == b)

						{

							data[j].ticketCount += user[i].ticket;

							writeData();

						}

					}

					user[t].ticket = 0;

					user[t].airID = 0;

					userWrite();

					printf("��Ʊ�ɹ�!\n");

				}

			}

	}

	main_menu();

}



void bill()

{

	char lname[10];

	char lcard[10];

	int i, w = 0;

	printf("��������������:");

	scanf("%s", lname);

	printf("����������֤����:");

	scanf("%s", lcard);

	for (i = 0; i < use; i++)

		if (strcmp(lname, user[i].name) == 0 && user[i].ticket != 0 && strcmp(lcard, user[i].card) == 0)

		{

			if (w == 0)

				printf("�˿Ͷ��� ���� ���֤�� Ʊ�� �����\n");

			w = 1;

			printf("%d %s %s %d %d\n", user[i].bill, user[i].name, user[i].card, user[i].ticket, user[i].airID);

		}

	if (w == 0)

	{

		printf("�Բ���,�����ڸó˿�!\n");

	}

	printf("\n");

	main_menu();

}



void drop()

{

	printf("|+---------------------------+|\n");

	printf("|    ��л����ʹ��    |\n");

	printf("|+---------------------------+|\n");

}



void admire()

{

	int choic_number; //����ѡ��

	printf("+------��ӭʹ���ʳȶ�Ʊ����ϵͳ-------+\n");

	printf("|     1.������Ϣ¼��   |\n");

	printf("|     2.������Ϣ�޸�   |\n");

	printf("|     3.����˿���Ϣ   |\n");

	printf("|     4.�����б�     |\n");

	printf("|     5.��������Ϣ   |\n");

	printf("|     6.���ش���     |\n");

	printf("|     0.�˳�   |\n");

	printf("+----------------------------------+\n");

	printf("���������ָ��:");

	scanf("%d", &choic_number);

	switch (choic_number)

	{

	case 1:

		input();

		break;

		//¼��

	case 2:

		update();

		break;

		//�޸�

	case 3:

		passager();

		//�˿���Ϣ

		break;

	case 4:

		listOfPlanes(); //�����б�

		break;

	case 5:

		order();

		//��������Ϣ

		break;

	case 6:

		main_menu();

		//���ش���

		break;

	case 0:

		drop();

		break;

	default:

		printf("�����������������");

		admire();

		break;

	}

}



void input()

{

	int next;

	inf++;

	printf("�����뺽���\n");

	scanf("%d", &data[planeCount].ID);

	printf("��������ʱ��\n");

	scanf("%s", data[planeCount].time);

	printf("����������\n");

	scanf("%s", data[planeCount].data);

	printf("���������\n");

	scanf("%s", data[planeCount].start);

	printf("�������յ�\n");

	scanf("%s", data[planeCount].end);

	printf("��������Ʊ\n");

	scanf("%d", &data[planeCount].ticketCount);

	printf("������Ʊ��\n");

	scanf("%d", &data[planeCount].price);

	planeCount++;

	writeData();

	printf("%d������¼�����\n", inf);

	printf("����¼���밴1,���������밴0\n");

	scanf("%d", &next);

	system("cls");

	if (next == 0)

		admire();

	else if (next == 1)

		input();

}



void listOfPlanes()

{printf("����ID   ��ʱ��   ������� ��� �յ� ��Ʊ �۸�\n");
int i;
for(i=0;i<planeCount;i++)
printf(" %d    %s %s %s %s %d %d\n", data[i].ID,data[i].time,data[i].data,data[i].start,data[i].end,data[i].ticketCount,data[i].price);
main_menu();
}


void quicksort(int left, int right)

{

	int i, j;

	plane t, temp;

	if (left > right)

		return;

	temp = data[left]; //temp�д�ľ��ǻ�׼��

	i = left;

	j = right;

	while (i != j)

	{

		//˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��

		while (data[j].ID >= temp.ID && i < j)

			j--;

		//�����ұߵ�

		while (data[i].ID <= temp.ID && i < j)

			i++;

		if (i < j)

		{

			t = data[i];

			data[i] = data[j];

			data[j] = t;

			writeData();

		}

	}

	data[left] = data[i];

	data[i] = temp;

	writeData();

	quicksort(left, i - 1);

	quicksort(i + 1, right);

}



void order()

{

	int c;

	c = planeCount;

	quicksort(0, c - 1);

	listOfPlanes();

}



void update()

{



	int p_id, t = -1, i;

	printf("������������ĺ���ID:");

	scanf("%d", &p_id);

	for (i = 0; i < planeCount; i++)

	{

		if (data[i].ID == p_id)

		{

			t = i;

			break;

		}

	}

	if (t == -1)

	{

		printf("�Բ���,�޴˴κ��ࡣ���²���:1,���أ�0\n");

		int s;

		scanf("%d", &s);

		if (s == 1)

			update();

		if (s == 0)

			admire();

	}

	else

	{

		printf("��������ʱ��\n");

		scanf("%s", data[t].time);

		printf("����������\n");

		scanf("%s", data[t].data);

		printf("���������\n");

		scanf("%s", data[t].start);

		printf("�������յ�\n");

		scanf("%s", data[t].end);

		printf("������Ʊ��\n");

		scanf("%d", &data[t].ticketCount);

		printf("��������Ʊ\n");

		scanf("%d", &data[t].price);

		writeData();

		printf("�޸ĳɹ�!\n");

		admire();

	}

}



void passager()

{

	int i;

	// userData();

	if (use == 0)

	{

		printf("û�г˿Ϳɲ鿴\n");

		admire();

	}

	printf("�˿Ͷ��� ���� ���֤�� Ʊ�� �����\n");

	for (i = 0; i < use; i++)

		if (user[i].ticket != 0)

			printf("%d %s %s  %d %d\n", user[i].bill, user[i].name, user[i].card, user[i].ticket, user[i].airID);

	printf("\n\n\n");

	admire();

}











