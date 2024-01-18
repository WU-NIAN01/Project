#include "main.h"
enum
{
	EXIT,
	ADDITION,
	DELETE,
	SEEK,
	MODIFY,
	SORT,
	SHOW,
};
void menu()
{
	printf("***********************************\n");
	printf("*******  1.添加   2.删除  *********\n");
	printf("*******  3.查找   4.修改  *********\n");
	printf("*******  5.排序   6.显示  *********\n");
	printf("*******  0.退出           *********\n");
}
int main()
{
	int input = 0;
	address_book con;
	init_address_book(&con);
	printf("操作通讯录后请输入0退出，以免数据丢失\n\n");
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
		case ADDITION:
			add_contact_person(&con);
			break;
		case DELETE:
			delete_contact_person(&con);
			break;
		case SEEK:
		    seek_contact_person(&con);
			break;
		case MODIFY:
			modify_contact_person(&con);
			break;
		case SORT:
			sort_contact_person_byage(&con);
			break;
		case SHOW:
			show_contact_person(&con);
			break;
		case EXIT:
			save_address_book(&con);
			clear_address_book(&con);
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	return 0;
}