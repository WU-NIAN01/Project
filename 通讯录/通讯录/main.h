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
#define DEFAULT_CAPACITY 3  //Ĭ������
#define ADD_CAPACITY 2  //ÿ�����ӵ�����


//������Ϣ
typedef struct personal_information
{
	char name[20];
	char sex[20];
	int age;
	char tele[20];
	char address[20];
}per_inf;


//ͨѶ¼
typedef struct address_book
{
	per_inf* p;
	int count;
	int capacity;//ͨѶ¼���Դ�����������ֵ
}address_book;


void init_address_book(address_book* pc);  //��ʼ��ͨѶ¼
void add_contact_person(address_book* pc); //������ϵ��
int add_capacity(address_book* pc);  //��������
void show_contact_person(address_book* pc);   //��ʾͨѶ¼
void delete_contact_person(address_book* pc);  //ɾ����ϵ��
void seek_contact_person(address_book* pc);  //������ϵ��
void modify_contact_person(address_book* pc);  //�޸���ϵ��
void sort_contact_person_byage(address_book* pc);  //���������ͨѶ¼��Ա����
void clear_address_book(address_book* pc);  //����ͨѶ¼���ٵ��ڴ�ռ�
void save_address_book(address_book* pc);  //��ͨѶ¼�������ļ���
void load_address_book(address_book* pc);  //���������ļ��е���Ϣ���ص�ͨѶ¼��