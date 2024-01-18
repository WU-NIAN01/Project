#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>


#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 20
#define MAX_ADDRESS 20
#define DEFAULT_CAPACITY 3  //默认容量
#define ADD_CAPACITY 2  //每次增加的容量


//个人信息
typedef struct personal_information
{
	char name[20];
	char sex[20];
	int age;
	char tele[20];
	char address[20];
}per_inf;


//通讯录
typedef struct address_book
{
	per_inf* p;
	int count;
	int capacity;//通讯录可以存放人数的最大值
}address_book;


void init_address_book(address_book* pc);  //初始化通讯录
void add_contact_person(address_book* pc); //增添联系人
int add_capacity(address_book* pc);  //增加容量
void show_contact_person(address_book* pc);   //显示通讯录
void delete_contact_person(address_book* pc);  //删除联系人
void seek_contact_person(address_book* pc);  //查找联系人
void modify_contact_person(address_book* pc);  //修改联系人
void sort_contact_person_byage(address_book* pc);  //根据年龄对通讯录成员排序
void clear_address_book(address_book* pc);  //清理通讯录开辟的内存空间
void save_address_book(address_book* pc);  //将通讯录保存在文件中
void load_address_book(address_book* pc);  //将储存在文件中的信息加载到通讯录中