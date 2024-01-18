#include "main.h"


int add_capacity(address_book* pc)  //��������
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		per_inf* ptr = (per_inf*)realloc(pc->p, (pc->capacity + ADD_CAPACITY) * sizeof(per_inf));
		if (ptr == NULL)
		{
			perror("����ʧ��:");
			return 1;
		}
		else
		{
			pc->p = ptr;
			pc->capacity += ADD_CAPACITY;
		}
	}
	return 0;
}


void load_address_book(address_book* pc)  //���������ļ��е���Ϣ���ص�ͨѶ¼��
{
	assert(pc);
	FILE* file = fopen("ͨѶ¼.txt", "rb");
	if (file == NULL)
	{
		perror("ͨѶ¼����ʧ��:");
		return;
	}
	int i = 0;
	while (fread(pc->p + i, sizeof(per_inf), 1, file))
	{
		add_capacity(pc);
		pc->count++;
		i++;
	}
	fclose(file);
	file = NULL;
}


void init_address_book(address_book* pc)  //��ʼ��ͨѶ¼
{
	assert(pc);
	pc->p = (per_inf*)calloc(DEFAULT_CAPACITY, sizeof(per_inf));
	if (pc->p == NULL)
	{
		perror("error:");
		return;
	}
	pc->count = 0;
	pc->capacity = DEFAULT_CAPACITY;
	load_address_book(pc);
}


void show_contact_person(address_book* pc)  //��ʾͨѶ¼
{
	assert(pc);
	printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (int i = 0;i < pc->count;i++)
		printf("%-20s\t%-20s\t%-20d\t%-20s\t%-20s\n",
			(pc->p + i)->name,
			(pc->p + i)->sex,
			(pc->p + i)->age,
			(pc->p + i)->tele,
			(pc->p + i)->address);
}


void add_contact_person(address_book* pc)  //������ϵ��
{
	assert(pc);
	int tmp = add_capacity(pc);
	if (tmp)
		return;
	printf("����������:>");
	scanf("%s", (pc->p + pc->count)->name);
	printf("�������Ա�:>");
	scanf("%s", (pc->p + pc->count)->sex);
	printf("����������:>");
	scanf("%d", &((pc->p + pc->count)->age));
	printf("������绰:>");
	scanf("%s", (pc->p + pc->count)->tele);
	printf("�������ַ:>");
	scanf("%s", (pc->p + pc->count)->address);
	pc->count++;
	printf("���ӳɹ�\n");
}


void delete_contact_person(address_book* pc)  //ɾ����ϵ��
{
	assert(pc);
	char str[MAX_NAME] = { 0 };
	printf("����������:>");
	scanf("%s", str);
	int i;
	for (i = 0;i < pc->count;i++)
	{
		if (!strcmp(str, (pc->p + i)->name))
			break;
	}
	if (i == pc->count)
	{
		printf("û���ҵ�ָ����ϵ��\n");
		return;
	}
	else
		for (;i < pc->count-1;i++)
			*(pc->p + i) = *(pc->p + i + 1);
	pc->count--;
	printf("ɾ���ɹ�\n");
}


void seek_contact_person(address_book* pc)  //������ϵ��
{
	assert(pc);
	char str[MAX_NAME] = { 0 };
	printf("����������:>");
	scanf("%s", str);
	int i;
	for (i = 0;i < pc->count;i++)
	{
		if (!strcmp(str, (pc->p + i)->name))
			break;
	}
	if (i == pc->count)
	{
		printf("û���ҵ�ָ����ϵ��\n");
		return;
	}
	else
		printf("%-20s\t%-20s\t%-20d\t%-20s\t%-20s\n",
			(pc->p + i)->name,
			(pc->p + i)->sex,
			(pc->p + i)->age,
			(pc->p + i)->tele,
			(pc->p + i)->address);
}


void modify_contact_person(address_book* pc)  //�޸���ϵ��
{
	assert(pc);
	char str[MAX_NAME] = { 0 };
	printf("����������:>");
	scanf("%s", str);
	int i;
	for (i = 0;i < pc->count;i++)
	{
		if (!strcmp(str, (pc->p + i)->name))
			break;
	}
	if (i == pc->count)
	{
		printf("û���ҵ�ָ����ϵ��\n");
		return;
	}
	else
	{
		printf("�������Ա�:>");
		scanf("%s", (pc->p + i)->sex);
		printf("����������:>");
		scanf("%d", &((pc->p + i)->age));
		printf("������绰:>");
		scanf("%s", (pc->p + i)->tele);
		printf("�������ַ:>");
		scanf("%s", (pc->p + i)->address);
		printf("�޸ĳɹ�\n");
	}
}

int sort_by_age(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return ((per_inf*)e1)->age - ((per_inf*)e2)->age;
}


void sort_contact_person_byage(address_book* pc)  //���������ͨѶ¼��Ա����
{
	assert(pc);
	qsort(pc->p, pc->count, sizeof(per_inf), sort_by_age);
	printf("����ɹ�\n");
}


void clear_address_book(address_book* pc)  //����ͨѶ¼���ٵ��ڴ�ռ�
{
	assert(pc);
	free(pc->p);
	pc->p = NULL;
}


void save_address_book(address_book* pc) //��ͨѶ¼�������ļ���
{
	assert(pc);
	FILE* file = fopen("ͨѶ¼.txt", "wb");
	if (file==NULL)
	{
		perror("ͨѶ¼����ʧ��:");
		return;
	}
	fwrite(pc->p, sizeof(per_inf), pc->count, file);
	fclose(file);
	file = NULL;
}