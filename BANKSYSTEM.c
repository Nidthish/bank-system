#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define FILE_NAME "used_ids.txt"
struct dateofbirth {
    int date;
    int month;
    int year;
};

struct user {
    char name[50];
    char number[11];  
    int password, amount; 
    char ac_no[11];    
    struct dateofbirth dob;
    char address[100]; 
};
struct user2 {
    char name[50];
    char number[11];  
    int password, amount; 
    char ac_no[11];    
    struct dateofbirth dob;
    char address[100]; 
    char transaction[100][500];
};

void create_account();
void login();
void main_menu();
void change();
void withdraw();
void transaction();
void generate_account_number(char *ac);
int is_duplicate(const char *ac) ;
void save_account_number(const char *ac);
void login() {
    FILE *fp;
    struct user use2;
    char name[50];
    int pword;

    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN PAGE \xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\nENTER YOUR ACCOUNT_NO: ");
    scanf("%49s", name);
    fp = fopen(name, "rb");
    if (fp == NULL) {
        printf("\nACCOUNT NOT FOUND!\n");
        return;
    }

    fread(&use2, sizeof(use2), 1, fp);
    fclose(fp);
    printf("\nENTER YOUR 4-DIGIT PIN: ");
    scanf("%d", &pword);
    if (use2.password == pword) {
        system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN PAGE \xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n================ YOUR DETAILS ================\n");
        printf("\nNAME: %s", use2.name);
        printf("\n\nPHONE_NUMBER: %s", use2.number);
        printf("\n\nDATE OF BIRTH: %d/%d/%d", use2.dob.date, use2.dob.month, use2.dob.year);
        printf("\n\nADDRESS: %s", use2.address);
        printf("\n\nACCOUNT CURRENT BALANCE: %d", use2.amount);
        printf("\n\n============================================");
    } else {
        printf("\nYOUR PIN NUMBER IS INCORRECT!\n");
    }
}
void change() {
    FILE *fp;
    struct user use3;
    char name1[50];
    int pword, op, valid_date = 0;

    system("cls");
    printf("\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 EDITOR SECTION \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\nENTER YOUR ACCOUNT NUMBER: ");
    scanf("%49s", name1);
    fp = fopen(name1, "rb");
    if (fp == NULL) {
        printf("\nACCOUNT NOT FOUND!\n");
        return;
    }

    fread(&use3, sizeof(use3), 1, fp);
    fclose(fp);
    printf("\nENTER YOUR 4-DIGIT PIN: ");
    scanf("%d", &pword);
    if (use3.password == pword) {
        system("cls");
        printf("\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 EDITOR SECTION \xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n================ YOUR DETAILS ================\n");
        printf("\n[1]NAME: %s",use3.name);
        printf("\n\n[2]PHONE_NUMBER: %s",use3.number);
        printf("\n\n[3]DATEOFBIRTH: %d/%d/%d",use3.dob.date,use3.dob.month,use3.dob.year);
        printf("\n\n[4]ADDRESS: %s",use3.address);
        printf("\n\n[5]PIN NUMBER: %d",use3.password);
        printf("\n\n============================================");
        printf("\nWHAT DO YOU WANT TO CHANGE: ");
        scanf("%d", &op);
    } else {
        printf("\nYOUR PIN NUMBER IS INCORRECT!\n");
        return;
}
    switch (op) {
        case 1:
            printf("\nENTER YOUR NAME: ");
            scanf("%49s", use3.name);
            while ((getchar()) != '\n'); 
            break;
        case 2:
            printf("\nENTER YOUR MOBILE NUMBER: ");
            scanf("%10s", use3.number);
             while ((getchar()) != '\n'); 
            break;
        case 3:
            while (!valid_date) {
                printf("\nENTER YOUR DATE OF BIRTH (DD/MM/YYYY): ");
                scanf("%d/%d/%d", &use3.dob.date, &use3.dob.month, &use3.dob.year);
                if (use3.dob.date >= 1 && use3.dob.date <= 31 && use3.dob.month >= 1 && use3.dob.month <= 12 && use3.dob.year >= 1900 && use3.dob.year <= 2020) {
                    valid_date = 1;
                } else {
                    printf("\nINVALID DATE! PLEASE ENTER AGAIN..!\n");
                }
            }
            break;
        case 4:
            printf("\nENTER YOUR ADDRESS: ");
            scanf(" %[^\n]s", use3.address);
            break;
        case 5:
        	printf("\nENTER YOUR 4-DIGIT PIN: ");
            scanf("%d",&use3.password);
            break;
        default:
            printf("ENTER A VALID OPTION!");
            getch();
            change();
    }

    fp = fopen(use3.ac_no, "wb");
    if (fp == NULL) {
        printf("\nERROE WHILE UPDATE FILE!\n");
        return;
    }

    fwrite(&use3, sizeof(use3), 1, fp);
    fclose(fp);
    printf("\n\n============================================");
    printf("\n\nCHANGE MADE SUCCESSFULLY!!");
}

void withdraw() {
    struct user use1;
    FILE *fp;
    FILE *his;
    char name1[50];
    int pword, amount, op;
    time_t t;
    struct tm *timeInfo;

    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2 ATM MENU \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\nENTER YOUR ACCOUNT NUMBER: ");
    scanf("%49s", name1);
    fp = fopen(name1, "rb");
    if (fp == NULL) {
        printf("\n\tACCOUNT NOT FOUND....!\n");
        return;
    }

    fread(&use1, sizeof(use1), 1, fp);
    fclose(fp);

    printf("\nENTER YOUR 4-DIGIT PIN: ");
    scanf("%d", &pword);

    if (use1.password != pword) {
        printf("\n!\n");
        return;
    }

    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2 ATM MENU \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\nYOUR CURRENT ACCOUNT BALANCE IS: %d", use1.amount);
    printf("\n\nENTER THE AMOUNT YOU WANT TO WITHDRAW: ");
    scanf("%d", &amount);
    if (amount <= 0 || amount > 9999) {
        printf("\nINVALID AMOUNT! ENTER A VALUE BETWEEN 1 AND 9999.\n");
        return;
    }
    if (amount > use1.amount) {
        printf("\nINSUFFICIENT BALANCE!\n");
        return;
    }
    printf("\nPROCESSING YOUR REQUEST ");
    int j;
    for (j = 0; j < 5; j++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }

    use1.amount -= amount;
    time(&t);
    timeInfo = localtime(&t);
    fp = fopen(use1.ac_no, "wb");
    if (fp == NULL) {
        printf("\nERROT UPDATING FILE..!\n");
        return;
    }
    fwrite(&use1, sizeof(use1), 1, fp);
    fclose(fp);

    printf("\n\nTRANSACTION SUCCESSFUL!");
    printf("\n\nDO YOU WANT TO PRINT A RECEIPT? (1 FOR YES, ANY OTHER NUMBER FOR NO): ");
    scanf("%d", &op);

    if (op == 1) {
        system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2 ATM MENU \xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t\t\t===============================\n");
        printf("\t\t\t\t\t\t\t\t        WITHDRAWAL RECEIPT     \n");
        printf("\t\t\t\t\t\t\t\t===============================\n");
        printf("\n\t\t\t\t\t\t\t\tDATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
               timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
               timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        printf("\n\t\t\t\t\t\t\t\tAMOUNT WITHDRAWN: %d\n", amount);
        printf("\n\t\t\t\t\t\t\t\tREMAINING BALANCE: %d\n", use1.amount);
        printf("\t\t\t\t\t\t\t\t===============================\n");
        printf("\t\t\t\t\t\t\t\tTHANK YOU FOR BANKING WITH US!\n");
        printf("\t\t\t\t\t\t\t\t===============================\n");
    } else {
        printf("\n\tTHANK YOU FOR BANKING WITH US!\n");
    }
    strcat(name1, "his");
    his = fopen(name1, "a");
    if (his != NULL) {
        fprintf(his, "-------------------------------------------------\n");
        fprintf(his, "\n\tDATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
                timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
                timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        fprintf(his, "\n\tAMOUNT WITHDRAWN: %d\n", amount);
        fclose(his);
    } else {
        printf("\nError updating transaction history!\n");
    }
}

void transaction()
{
	struct user use1;
	struct user2 use2;
	FILE *fp;
	FILE *his;
	char ac_no1[50],ac_no2[50];
	int pword,op;
	int amount;
	time_t t;
    struct tm *timeInfo;
	system("cls");
	printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\n\t\t\t\t\t\t   =============== TRANSACTION SECTION ===============\n");
	printf("\n\nENTER YOUR ACCOUNT NUMBER: ");
	scanf("%s",ac_no1);
	printf("\n\nENTER THE RECEIVER ACCOUNT NUMBER: ");
	scanf("%s",ac_no2);
	fp=fopen(ac_no1,"rb");
	 if (fp == NULL) {
        printf("\nACCOUNT NOT FOUND....!\n");
        return;
    }
	fread(&use1,sizeof(use1),1,fp);
	fclose(fp);
	fp=fopen(ac_no2,"rb");
	 if (fp == NULL) {
        printf("\nACCOUNT NOT FOUND....!\n");
        return ;
    }
    fread(&use2,sizeof(use2),1,fp);
	fclose(fp);
	printf("\n\nENTER THE AMOUNT TO TRANSFER: ");
	scanf("%d",&amount);
	if(amount>use1.amount)
	{
		printf("\nINSUFFICIENT BALANCE");
		return;
	}
	printf("\n\nENTER YOUR 4-DIGIT PIN: ");
	scanf("%d",&pword);
	if(pword==use1.password)
	{
		use1.amount-=amount;
		use2.amount+=amount;
		time(&t);
		timeInfo = localtime(&t);
		fp=fopen(use1.ac_no,"wb");
fwrite(&use1, sizeof(use1), 1, fp);
fclose(fp);
fp=fopen(use2.ac_no,"wb");
fwrite(&use2, sizeof(use2), 1, fp);
fclose(fp);
	
		int i;
		printf("\n\nYOUR TRANSACTION IS PROCESSING");
		for(i=0;i<5;i++)
		{
			Sleep(500);
			printf(".");
			fflush(stdout);
		}
		printf("\n\nTRANSACTION IS SUCCESSFULLY MADE!");
		printf("\n\nDO YOU WANT TO PRINT A RECEIPT? (1 FOR YES, ANY OTHER NUMBER FOR NO): ");
		scanf("%d",&op);
		if(op==1)
		{
			system("cls");
				printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
				printf("\n\t\t\t\t\t\t   =============== TRANSACTION SECTION ===============\n");
			printf("\n\nPRINTING YOUR RECIPT");
			for(i=0;i<5;i++)
		{
			Sleep(500);
			printf(".");
			fflush(stdout);
		}
		system("cls");
		printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
		printf("\n\t\t\t\t\t\t   =============== TRANSACTION SECTION ===============\n");
		printf("\n\t\t\t\t\t\t\t\t===============================\n");
		printf("\t\t\t\t\t\t\t\t         WITHDRAWAL RECEIPT     \n");
		printf("\t\t\t\t\t\t\t\t===============================\n");
		printf("\n\t\t\t\t\t\t\t\tDATE: %02d-%02d-%d TIME:%02d:%02d:%02d\n",timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
		printf("\n\t\t\t\t\t\t\t\tAMOUNT TRANSFERED: %d\n",amount);
		printf("\n\t\t\t\t\t\t\t\tRECEIVER ACCOUNT NUMBER: %s\n",use2.ac_no);
		printf("\n\t\t\t\t\t\t\t\tREMAING BALANCE: %d\n",use1.amount);
		printf("\t\t\t\t\t\t\t\t===============================\n");
		printf("\t\t\t\t\t\t\t\tTHANKYOU FOR BANKING WITH US!\n");
		printf("\t\t\t\t\t\t\t\t===============================\n");
		
		}
	}
	else {
		printf("\n\nPLEASE ENTER THE VALID PASSWORD!....");
		Sleep(3000);
		system("cls");
		transaction();
	}
strcat(ac_no1,"his");
    his = fopen(ac_no1, "a");
    if (his != NULL) {
        fprintf(his,"-------------------------------------------------\n");
        fprintf(his,"\n\tDATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
                timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
                timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        fprintf(his,"\n\tRECEIVER ACCOUNT NO: %s\n",use2.ac_no);
        fprintf(his,"\n\tAMOUNT TRANSFERED: %d\n", amount);
        fclose(his);
    } else {
        printf("\nERROR OCCUR IN SAVING TRANSATION.....!\n");
    }
strcat(use2.ac_no, "his");
    his = fopen(use2.ac_no, "a");
    if (his != NULL) {
        fprintf(his, "-------------------------------------------------\n");
        fprintf(his, "n\tDATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
                timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
                timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        fprintf(his,"\n\tSENDER ACCOUNT NO: %s\n",use1.ac_no);
        fprintf(his,"\n\tAMOUNT RECEIVED: %d\n", amount);
        ;
    fclose(his);
    } else {
        printf("\nERROR OCCUR IN SAVING TRANSATION.....!\n");
    }
}
void history()
{
	struct user use1;
    FILE *fp;
    FILE *his;
    char name1[50],line[256];
    int pword;
    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t ================ TRANSACTTION HISTORY ================\n");
    printf("\n\nENTER YOUR ACCOUNT NUMBER: ");
    scanf("%49s", name1);
    fp = fopen(name1, "rb");
    if (fp == NULL) {
        printf("\nACCOUNT NOT FOUND!\n");
        return;
    }

    fread(&use1, sizeof(use1), 1, fp);
    fclose(fp);
    printf("\n\nENTER YOUR 4-DIGIT PIN NUMBER: ");
    scanf("%d", &pword);
    if (use1.password == pword) {
        system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t ================ TRANSACTTION HISTORY ================\n\n\n");
        strcat(name1,"his");
        his = fopen(name1, "r");
					if (his == NULL) {
					printf("\nACCOUNT NOT FOUND........!!\n");
					return;
					}
		while(fgets(line,sizeof(line),his))
		{
			printf("%s",line);
		}
		}
		else
		{
			printf("\n\nNO TRANSACTION FOUND..");
		}
}

void create_account() {
    struct user use1;
    FILE *fp;
    FILE *profile;
    char ac[11];
    int valid_date = 0;
    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t      ============= NEW ACCOUNT SECTION =============\n");
    printf("\n\nENTER YOUR FULL NAME: ");
    scanf("%49s", use1.name);
    printf("\n\nENTER YOUR MOBILE NUMBER: ");
    scanf("%11s", use1.number);
    while ((getchar()) != '\n'); 
    while (!valid_date) {
    printf("\n\nENTER YOUR DATE OF BIRTH (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &use1.dob.date, &use1.dob.month, &use1.dob.year);
    if (use1.dob.date >= 1 && use1.dob.date <= 31 &&
        use1.dob.month >= 1 && use1.dob.month <= 12 &&
        use1.dob.year >= 1900 && use1.dob.year <= 2020) {
        valid_date = 1;
    } else {
        printf("\nINVALID DATE! PLEASE ENTER AGAIN....");
    }
}
	printf("\n\nENTER YOUR ADDRESS: ");
    scanf(" %[^\n]s", use1.address);
    do {
        generate_account_number(ac);
    } while (is_duplicate(ac));
    save_account_number(ac);
	printf("\n\nYOUR (10-digits) ACCOUNT NUMBER IS: %s\n",ac);
	strcpy(use1.ac_no,ac);
    printf("\n\nSET YOUR PIN/PASSWORD (4-digit number): ");
    scanf("%d", &use1.password);
    printf("\n\nINITIAL DEPOSIT AMOUNT: ");
    scanf("%d", &use1.amount);
    profile=fopen("ACCOUNT_DETAILS.txt","a+");
    fprintf(profile,"NAME OF USER:%s | ACCOUNT NUMBER:%s\n\n",use1.name,use1.ac_no);
    fclose(profile);
    fp = fopen(use1.ac_no, "wb");
    if (fp == NULL) {
        printf("\nERROR CREATE WHILE ACCOUNT....!\n");
        return;
    }

    fwrite(&use1, sizeof(use1), 1, fp);
    fclose(fp);
    printf("\nACCOUNT CREATION IN PROGRESS! DO NOT CLOSE THE APLLICATION");
    int j;
    for (j = 0; j < 5; j++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }

    printf("\n\nACCOUNT SUCCESSFULLY CREATED!\n");
}
void generate_account_number(char *ac)
{
	int i;
	srand(time(0)+rand());
	for(i=0;i<10;i++)
	{
		int digit=rand()%10;
		ac[i]=digit+'0';
	}
	ac[10]='\0';
}
int is_duplicate(const char *ac) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return 0;

    char line[10 + 2];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, ac) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}
void save_account_number(const char *ac) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file) {
        fprintf(file, "%s\n", ac);
        fclose(file);
    }
}
void main_menu() {
    int op;
    char option[10];

    while (1) {
        system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t ================  WELCOME TO MAINMENU  ================\n");
        printf("\n\n[1] CREATE AN NEW ACCOUNT\n");
        printf("\n[2] ACCOUNT DETAILS\n");
        printf("\n[3] CHANGE DETAILS IN YOUR EXISTING ACCOUNT\n");
        printf("\n[4] AMOUNT WITHDRAW\n");
        printf("\n[5] TRANSFER AMOUNT\n");
        printf("\n[6] TRANSACTION HISTORY\n");
        printf("\n[7] EXIT\n");
        
        printf("\n\nPLEASE!...ENTER YOUR OPTION: ");
        scanf("%d", &op);

        switch (op) {
            case 1: create_account(); break;
            case 2: login(); break;
            case 3: change(); break;
            case 4: withdraw(); break;
            case 5: transaction(); break;
            case 6: history(); break;
            case 7: exit(0);
            default: printf("\nINVALID CHOICE!\n");
        }
        
        printf("\n\n\nPLEASE CONFIRM! IF YOU WISH TO PROCEED [YES/NO]: ");
        scanf("%9s", option);
        if (strcmp(option, "NO") == 0 || strcmp(option, "no") == 0) {
            break;
        }
    }
}

int main() {
    main_menu();
    return 0;
}
