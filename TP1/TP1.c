#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
#include <CUnit/Console.h>

#define MAX_CHAR 43

char* Code39(char* chaine)
{
	printf("début de préparation\n");
	int i=0;
	char* chaine_code=(char*)malloc((2+strlen(chaine))*sizeof (char));

	chaine_code[i]='*';

	for(i=1;i<strlen(chaine);i++)
	{
		if(chaine[i-1]==32 || (chaine[i-1]<=57 && chaine[i-1]>=45) || chaine[i-1]==36 || chaine[i-1]==37 || chaine[i-1]==43 || (chaine[i-1]>=97 && chaine[i-1]<=122) || (chaine[i-1]>=65 && chaine[i-1]<=90))
		{
			chaine_code[i]=toupper(chaine[i-1]);
		}
		else
		{
			printf("Error : Wrong character.\n");
			exit(1);
		}
	}
	chaine_code[i]=toupper(chaine[i-1]);
	i++;
	chaine_code[i]='*';
	printf("fin de préparation\n");
	return chaine_code;
}

int test_chaine(char* chaine)
{
	int i,j,test=0;

	char char_ok[43]="ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789$-/.%+";
	if (chaine[0]=='*' && chaine[strlen(chaine)-1]=='*')
	{
		for (i=1;i<strlen(chaine)-1;i++)
		{
			for (j=0;j<43;j++)
			{
				if (chaine[i]==char_ok[j])
				test++;
			}
		}
		if(test+2==strlen(chaine))
		{
			return 1;
		}
		else return 0;
	}
	else return 0;
}

char* Modulo43(char* chaine)
{
	int sum=0,i,j;
	char* res=malloc(MAX_CHAR+1);
	char char_ok[43]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-. $/+%";

	for (i=0;i<strlen(chaine);i++)
	{
		for(j=0;j<43;j++)
		{
			if(chaine[i]==char_ok[j]) sum+=j;
		}
	}
	char* mod=malloc(1);
	mod[0]=char_ok[sum%43];
	strcat(res,chaine);
	strcat(res,mod);

	return res;
}

void test_uni_test_chaine()
{
	CU_ASSERT(test_chaine("*ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789./-+$%*"));
	CU_ASSERT(!test_chaine("*ABC */AZE98..*"));
	CU_ASSERT(!test_chaine("*aB0 r3712//*"));
	CU_ASSERT(test_chaine("**"));
	CU_ASSERT(!test_chaine(""));
	CU_ASSERT(!test_chaine("78 /AB*"));
	CU_ASSERT(test_chaine("*ABC 123 / $$$*"));
}

void test_uni_Modulo43()
{
	CU_ASSERT(!strcmp(Modulo43("*012*"),"*012*3"));
	CU_ASSERT(!strcmp(Modulo43("*ABC*"),"*ABC*X"));
	CU_ASSERT(!strcmp(Modulo43("**"),"**0"));
	CU_ASSERT(!strcmp(Modulo43("*/3*"),"*/3*0"));
	CU_ASSERT(!strcmp(Modulo43("* M*"),"* M*H"));
}


int main()
{
	CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("test_chaine", 0, 0);

    CU_add_test(suite,"valide",test_uni_test_chaine);
    CU_add_test(suite,"modulo",test_uni_Modulo43);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    //CU_basic_run_tests();
    //CU_automated_run_tests();
    CU_console_run_tests();
    CU_cleanup_registry();	
	/*char* chaine = (char*)malloc((2+MAX_CHAR)*sizeof(char));
	char* chaine_code = (char*)malloc((2+MAX_CHAR)*sizeof(char));

	fgets(chaine,MAX_CHAR,stdin);
	printf("Votre chaine : %s \n",chaine);

	printf("Traitement...\n");

	chaine_code=Code39(chaine);

	printf("Chaine traitée : %s\n",chaine_code);

	printf("Test chaine");
	print("%d",test_chaine(chaine_code));

	free(chaine);
	free(chaine_code);*/
	return 0;
}