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
	printf("*******  1.���   2.ɾ��  *********\n");
	printf("*******  3.����   4.�޸�  *********\n");
	printf("*******  5.����   6.��ʾ  *********\n");
	printf("*******  0.�˳�           *********\n");
}
int main()
{
	int input = 0;
	address_book con;
	init_address_book(&con);
	printf("����ͨѶ¼��������0�˳����������ݶ�ʧ\n\n");
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("�����������������\n");
		}
	} while (input);
	return 0;
}