//
//  fwb.c
//  FileWriteBinary
//
//  Created by Mewlan Musajan on 10/29/17.
//  Copyright (c) 2017 Mewlan Musajan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define DICT_LEN sizeof(struct Dictionary)
#define COUNT 3

unsigned int L;

struct Dictionary
{
	char errorViewString[52];
	char dataInsertInstructionViewString[60];
	char dataUpdatedViewString[32];
	char searchViewString[32];
	char catalogViewString[32];
	char backViewString[32];
	char selectLanguageViewString[120];
	char functionDataInsertString[32];
	char functionSearchString[32];
	char functionCatalogString[32];
	char functionSelectLanguageString[32];
} dict[COUNT];

typedef enum Language
{
	english,
	chinese,
	uyghur
} LANG;

LANG CurrentLanguage = 0;

/******Model******/

void save()
{
	FILE *dictionaryfp;
	if ((dictionaryfp = fopen("iWillDictViewString.dat", "wb")) == NULL)
	{
		printf("can not open file.\n");
		exit(0);
	}
	switch (CurrentLanguage) {
		case english:rewind(dictionaryfp);break;
		case chinese:fseek(dictionaryfp, DICT_LEN, 0);break;
		case uyghur:fseek(dictionaryfp, 2 * DICT_LEN, 0);break;
		default:break;
	}
	for (int i = 0; i < COUNT; ++i)
	{
		if (fwrite(&dict[i], DICT_LEN, 1, dictionaryfp) != 1)
		{
			printf("dictionary write error\n");
		}
	}
	fclose(dictionaryfp);
}

/******Model******/


int main(int argc, char const *argv[])
{
	for (int i = 0; i < COUNT; ++i)
	{
		fflush(stdin);
		printf("errorViewString:, dataInsertInstructionViewString:\n");
		scanf("%[^\n]%*c%[^\n]%*c", dict[i].errorViewString, dict[i].dataInsertInstructionViewString);
		fflush(stdin);
		printf("dataUpdatedViewString:, searchViewString:\n");
		scanf("%[^\n]%*c%[^\n]%*c", dict[i].dataUpdatedViewString, dict[i].searchViewString);
		fflush(stdin);
		printf("catalogViewString:, backViewString:\n");
		scanf("%[^\n]%*c%[^\n]%*c", dict[i].catalogViewString, dict[i].backViewString);
		fflush(stdin);
		printf("selectLanguageViewString:, functionDataInsertString:\n");
		scanf("%[^\n]%*c%[^\n]%*c", dict[i].selectLanguageViewString, dict[i].functionDataInsertString);
		fflush(stdin);
		printf("functionSearchString:, functionCatalogString:\n");
		scanf("%[^\n]%*c%[^\n]%*c", dict[i].functionSearchString, dict[i].functionCatalogString);
		fflush(stdin);
		printf("functionSelectLanguageString:\n");
		scanf("%[^\n]%*c", dict[i].functionSelectLanguageString);	
		fflush(stdin);
	}
	save();
	return 0;
}