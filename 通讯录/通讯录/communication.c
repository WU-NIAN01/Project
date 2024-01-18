#include "main.h"


int add_capacity(address_book* pc)  //增加容量
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		per_inf* ptr = (per_inf*)realloc(pc->p, (pc->capacity + ADD_CAPACITY) * sizeof(per_inf));
		if (ptr == NULL)
		{
			perror("增容失败:");
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


void load_address_book(address_book* pc)  //将储存在文件中的信息加载到通讯录中
{
	assert(pc);
	FILE* file = fopen("通讯录.txt", "rb");
	if (file == NULL)
	{
		perror("通讯录加载失败:");
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


void init_address_book(address_book* pc)  //初始化通讯录
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


void show_contact_person(address_book* pc)  //显示通讯录
{
	assert(pc);
	printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0;i < pc->count;i++)
		printf("%-20s\t%-20s\t%-20d\t%-20s\t%-20s\n",
			(pc->p + i)->name,
			(pc->p + i)->sex,
			(pc->p + i)->age,
			(pc->p + i)->tele,
			(pc->p + i)->address);
}


void add_contact_person(address_book* pc)  //增加联系人
{
	assert(pc);
	int tmp = add_capacity(pc);
	if (tmp)
		return;
	printf("请输入名字:>");
	scanf("%s", (pc->p + pc->count)->name);
	printf("请输入性别:>");
	scanf("%s", (pc->p + pc->count)->sex);
	printf("请输入年龄:>");
	scanf("%d", &((pc->p + pc->count)->age));
	printf("请输入电话:>");
	scanf("%s", (pc->p + pc->count)->tele);
	printf("请输入地址:>");
	scanf("%s", (pc->p + pc->count)->address);
	pc->count++;
	printf("增加成功\n");
}


void delete_contact_person(address_book* pc)  //删除联系人
{
	assert(pc);
	char str[MAX_NAME] = { 0 };
	printf("请输入名字:>");
	scanf("%s", str);
	int i;
	for (i = 0;i < pc->count;i++)
	{
		if (!strcmp(str, (pc->p + i)->name))
			break;
	}
	if (i == pc->count)
	{
		printf("没有找到指定联系人\n");
		return;
	}
	else
		for (;i < pc->count-1;i++)
			*(pc->p + i) = *(pc->p + i + 1);
	pc->count--;
	printf("删除成功\n");
}


void seek_contact_person(address_book* pc)  //查找联系人
{
	assert(pc);
	char str[MAX_NAME] = { 0 };
	printf("请输入名字:>");
	scanf("%s", str);
	int i;
	for (i = 0;i < pc->count;i++)
	{
		if (!strcmp(str, (pc->p + i)->name))
			break;
	}
	if (i == pc->count)
	{
		printf("没有找到指定联系人\n");
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


void modify_contact_person(address_book* pc)  //修改联系人
{
	assert(pc);
	char str[MAX_NAME] = { 0 };
	printf("请输入名字:>");
	scanf("%s", str);
	int i;
	for (i = 0;i < pc->count;i++)
	{
		if (!strcmp(str, (pc->p + i)->name))
			break;
	}
	if (i == pc->count)
	{
		printf("没有找到指定联系人\n");
		return;
	}
	else
	{
		printf("请输入性别:>");
		scanf("%s", (pc->p + i)->sex);
		printf("请输入年龄:>");
		scanf("%d", &((pc->p + i)->age));
		printf("请输入电话:>");
		scanf("%s", (pc->p + i)->tele);
		printf("请输入地址:>");
		scanf("%s", (pc->p + i)->address);
		printf("修改成功\n");
	}
}

int sort_by_age(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return ((per_inf*)e1)->age - ((per_inf*)e2)->age;
}


void sort_contact_person_byage(address_book* pc)  //根据年龄对通讯录成员排序
{
	assert(pc);
	qsort(pc->p, pc->count, sizeof(per_inf), sort_by_age);
	printf("排序成功\n");
}


void clear_address_book(address_book* pc)  //清理通讯录开辟的内存空间
{
	assert(pc);
	free(pc->p);
	pc->p = NULL;
}


void save_address_book(address_book* pc) //将通讯录保存在文件中
{
	assert(pc);
	FILE* file = fopen("通讯录.txt", "wb");
	if (file==NULL)
	{
		perror("通讯录保存失败:");
		return;
	}
	fwrite(pc->p, sizeof(per_inf), pc->count, file);
	fclose(file);
	file = NULL;
}