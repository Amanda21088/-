#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __CONTACT_H__
#define __CONTACT_H__
#include<stdio.h>
#include<assert.h>
#include<string.h>
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT
};


#define MAX 1000
#define MAX_NAME 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[SEX_MAX];
	short int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;


typedef struct Contact
{
	PeoInfo data[MAX]; //存放信息
	int sz;//通讯录有效信息的个数
}Contact;

void InitContact(Contact* pcon);
void AddContact(Contact* pcon);
void ShowContact(const Contact* pcon);
void DelContact(Contact* pcon);
void SearchContact(const Contact*pcon);
void ModifyContact(Contact*pcon);
void EmptyContact(Contact *pcon);
void SortContact(Contact *pcon);
#endif //_CONTACT_H__
