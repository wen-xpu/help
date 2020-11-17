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
	int ID;			 //航班ID
	char time[20];   //起降时间
	char data[10];   //日期
	char start[10];  //起点
	char end[10];	//终点
	int ticketCount; //票数
	int price;		 //票价
} data[100];
struct people
{
	int bill;	  //乘客订单
	char name[10]; //姓名
	char card[18]; //身份证号
	int ticket;	//票数
	int airID;	 //航班号
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
int readData() //读取文件
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
int writeData() //写入文件
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

	printf("请输入账号：");

	scanf("%d", &account);

	if (account == 10086)

	{

		printf("\n");

		admire();

	}

	return t;

}



int userData() //读取文件

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



int userWrite() //写入文件

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

	int choic_number; //命令选择

	printf("+------欢迎使用鲜橙飞机订票系统-------+\n");

	printf("|     1.浏览   |\n");

	printf("|     2.查询   |\n");

	printf("|     3.订票   |\n");

	printf("|     4.退票   |\n");

	printf("|     5.订单   |\n");

	printf("|     6.退出   |\n");

	printf("|     0.管理   |\n");

	printf("+----------------------------------+\n");

	printf("请输入操作指令:");

	scanf("%d", &choic_number);

	switch (choic_number)

	{

	case 0:

		login(); //登录

		break;



	case 1:

		listOfPlanes(); //浏览

		break;



	case 2:

		search(); //查询

		break;

	case 3:

		book(); //订票

		break;

	case 4:

		back(); //退票

		break;

	case 5:

		bill(); //订单

		break;

	case 6:

		drop(); //退出

		break;

	default:

		printf("输入错误，请重新输入\n");

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

	printf("  1、按航班号查询  2、按抵达地点查询\n");

	printf("***************************************************\n");

	printf("请输入查询方式:");

	scanf("%d", &select);

	if (select == 1)

		search_id();

	else if (select == 2)

		search_end();

	else

	{

		printf("请重新选择\n");

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

	printf("请您输入要查询的飞机航班号：");
scanf("%d", &a_id);

	system("cls");

	i = binary_research(0, c, a_id);

	if (i != -1)

	{

		printf("航班ID 起降时间 起飞日期 起点 终点 价格 余票\n");

		printf("%d %s %s %s %s %d %d\n", data[i].ID, data[i].time, data[i].data, data[i].start, data[i].end, data[i].ticketCount, data[i].price);

	}

	if (i == -1)

		printf("没有您想查询的航班!\n");

	system("pause");

	main_menu();

}



void search_end()

{

	char a_end[20];

	int i, w = 0;

	printf("请您输入要前往的目的地：");

	scanf("%s", a_end);

	printf("航班ID 起降时间 起飞日期 起点 终点 价格 余票\n");

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

		printf("没有您想查询的航班!\n");

	system("pause");

	main_menu();

}



void book()

{

	char a_end[20];

	int i, w = 0, p, num, s;

	printf("请您输入要前往的目的地：");

	scanf("%s", a_end);

	printf("航班ID 起降时间 起飞日期 起点 终点 价格 余票\n");

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

		printf("请选择您的航班:");

		scanf("%d", &p);

		for (i = 0; i < planeCount; i++)

		{

			if (p == data[i].ID)

			{

				printf("请输入你的名字:");

				scanf("%s", &user[use].name);

				printf("请输入你的证件号:");

				scanf("%s", &user[use].card);

				printf("请输入购票数");

				scanf("%d", &num);

				printf("确认购票请支付%d元,请按1确认:", data[i].price * num);

				scanf("%d", &s);

				printf("购票成功");

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

		printf("没有您想查询的航班!\n");

	system("pause");

	main_menu();

}



void back()

{

	char lname[10];

	char lcard[10];

	int b, y;

	int i, w = 0;

	printf("请输入您的姓名:");

	scanf("%s", lname);

	printf("请输入您的证件号:");

	scanf("%s", lcard);

	for (i = 0; i < use; i++)

		if (strcmp(lname, user[i].name) == 0 && user[i].ticket != 0 && strcmp(lcard, user[i].card) == 0)

		{

			if (w == 0)

				printf("乘客订单 姓名 身份证号 票数 航班号\n");

			w++;

			printf("%d %s %s %d %d\n", user[i].bill, user[i].name, user[i].card, user[i].ticket, user[i].airID);

		}

	if (w == 0)

	{

		printf("对不起,不存在该乘客!\n");

	}

	else

	{

		printf("请输入订单:");

		scanf("%d", &b);

		int j, t;

		for (i = 0; i < use; i++)

			if (b == user[i].bill)

			{

				t = i;

				printf("确认退票1:");

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

					printf("退票成功!\n");

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

	printf("请输入您的姓名:");

	scanf("%s", lname);

	printf("请输入您的证件号:");

	scanf("%s", lcard);

	for (i = 0; i < use; i++)

		if (strcmp(lname, user[i].name) == 0 && user[i].ticket != 0 && strcmp(lcard, user[i].card) == 0)

		{

			if (w == 0)

				printf("乘客订单 姓名 身份证号 票数 航班号\n");

			w = 1;

			printf("%d %s %s %d %d\n", user[i].bill, user[i].name, user[i].card, user[i].ticket, user[i].airID);

		}

	if (w == 0)

	{

		printf("对不起,不存在该乘客!\n");

	}

	printf("\n");

	main_menu();

}



void drop()

{

	printf("|+---------------------------+|\n");

	printf("|    感谢您的使用    |\n");

	printf("|+---------------------------+|\n");

}



void admire()

{

	int choic_number; //命令选择

	printf("+------欢迎使用鲜橙订票管理系统-------+\n");

	printf("|     1.航班信息录入   |\n");

	printf("|     2.航班信息修改   |\n");

	printf("|     3.航班乘客信息   |\n");

	printf("|     4.航班列表     |\n");

	printf("|     5.整理航班信息   |\n");

	printf("|     6.返回大厅     |\n");

	printf("|     0.退出   |\n");

	printf("+----------------------------------+\n");

	printf("请输入操作指令:");

	scanf("%d", &choic_number);

	switch (choic_number)

	{

	case 1:

		input();

		break;

		//录入

	case 2:

		update();

		break;

		//修改

	case 3:

		passager();

		//乘客信息

		break;

	case 4:

		listOfPlanes(); //航班列表

		break;

	case 5:

		order();

		//整理航班信息

		break;

	case 6:

		main_menu();

		//返回大厅

		break;

	case 0:

		drop();

		break;

	default:

		printf("输入错误，请重新输入");

		admire();

		break;

	}

}



void input()

{

	int next;

	inf++;

	printf("请输入航班号\n");

	scanf("%d", &data[planeCount].ID);

	printf("请输入起降时间\n");

	scanf("%s", data[planeCount].time);

	printf("请输入日期\n");

	scanf("%s", data[planeCount].data);

	printf("请输入起点\n");

	scanf("%s", data[planeCount].start);

	printf("请输入终点\n");

	scanf("%s", data[planeCount].end);

	printf("请输入余票\n");

	scanf("%d", &data[planeCount].ticketCount);

	printf("请输入票价\n");

	scanf("%d", &data[planeCount].price);

	planeCount++;

	writeData();

	printf("%d个数据录入完毕\n", inf);

	printf("继续录入请按1,结束操作请按0\n");

	scanf("%d", &next);

	system("cls");

	if (next == 0)

		admire();

	else if (next == 1)

		input();

}



void listOfPlanes()

{printf("航班ID   起降时间   起飞日期 起点 终点 余票 价格\n");
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

	temp = data[left]; //temp中存的就是基准数

	i = left;

	j = right;

	while (i != j)

	{

		//顺序很重要，要先从右边开始找

		while (data[j].ID >= temp.ID && i < j)

			j--;

		//再找右边的

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

	printf("请输入需操作的航班ID:");

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

		printf("对不起,无此次航班。重新操作:1,返回：0\n");

		int s;

		scanf("%d", &s);

		if (s == 1)

			update();

		if (s == 0)

			admire();

	}

	else

	{

		printf("请输入起降时间\n");

		scanf("%s", data[t].time);

		printf("请输入日期\n");

		scanf("%s", data[t].data);

		printf("请输入起点\n");

		scanf("%s", data[t].start);

		printf("请输入终点\n");

		scanf("%s", data[t].end);

		printf("请输入票价\n");

		scanf("%d", &data[t].ticketCount);

		printf("请输入余票\n");

		scanf("%d", &data[t].price);

		writeData();

		printf("修改成功!\n");

		admire();

	}

}



void passager()

{

	int i;

	// userData();

	if (use == 0)

	{

		printf("没有乘客可查看\n");

		admire();

	}

	printf("乘客订单 姓名 身份证号 票数 航班号\n");

	for (i = 0; i < use; i++)

		if (user[i].ticket != 0)

			printf("%d %s %s  %d %d\n", user[i].bill, user[i].name, user[i].card, user[i].ticket, user[i].airID);

	printf("\n\n\n");

	admire();

}











