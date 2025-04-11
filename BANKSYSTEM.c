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
    struct dateofbirth dob;
    char address[100];
    char ac_type[8];
    char ac_no[11];
    int password, amount;
    int loan_amount,loan_status,EMI;
     
};
struct user2 {
	
	char name[50];
    char number[11];  
    struct dateofbirth dob;
    char address[100];
    char ac_type[8];
    char ac_no[11];
    int password, amount;
};
void main_menu();
void login();
void login_menu(char *ac_no);
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
void forget_password(struct user *use)
{
	char num[11];
	int pin,pin2;
	system("cls");
	printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\n\n ENTER YOUR MOBILE NUMBER:");
	scanf("%11s",num);
	while((getchar())!='\n');
	if(strcmp(num,use->number)!=0)
	{
		printf("\n\n MOBILE IS NOT MATCH!..");
		return ;
	}
	printf("\n\n MOBILE NUMBER MATCHED");
	printf("\n\n ENTER YOUR NEW PIN NUMBER: ");
	scanf("%d",&pin);
	while(1){
		
	printf("\n\n CONFIRM YOUR NEW PIN NUMBER: ");
	scanf("%d",&pin2);
	if(pin==pin2)
	{
		use->password=pin2;
		FILE *fp = fopen(use->ac_no, "wb");
            if (fp != NULL) {
                fwrite(use, sizeof(*use), 1, fp);
                fclose(fp);
		printf("\n\n YOUR 4 DIGIT PIN SUCCESSFULLY CHANGED...");
		break;
	}
}

}
}


void create_account() {
    struct user use1;
    FILE *fp;
    FILE *profile;
    char ac[11];
    int valid_date = 0,actype;
    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t      ============= NEW ACCOUNT SECTION =============\n");
    printf("\n\n ENTER YOUR FULL NAME WITHOUT SPACE ( EX:INITIAL.NAME ): ");
    scanf("%49s", use1.name);
    printf("\n\n ENTER YOUR MOBILE NUMBER: ");
    scanf("%11s", use1.number);
    while((getchar())!='\n');
    while (!valid_date) {
    printf("\n\n ENTER YOUR DATE OF BIRTH (DD/MM/YYYY): ");
    scanf("%d / %d/ %d", &use1.dob.date, &use1.dob.month, &use1.dob.year);
    if (use1.dob.date >= 1 && use1.dob.date <= 31 &&
        use1.dob.month >= 1 && use1.dob.month <= 12 &&
        use1.dob.year >= 1900 && use1.dob.year <= 2020) {
        valid_date = 1;
    } else {
        printf("\n INVALID DATE! PLEASE ENTER AGAIN....");
    }
}
	printf("\n\n ENTER YOUR ADDRESS: ");
    scanf(" %[^\n]s", use1.address);
    do {
        generate_account_number(ac);
    } while (is_duplicate(ac));
    save_account_number(ac);
    while(1){
    	printf("\n\n ENTER YOUR ACCOUNT TYPE( [1]SAVING OR [2]CURRENT ): ");
    	scanf("%d",&actype);
    	if(actype==1) 
    	{   
		    strcpy(use1.ac_type,"SAVING");
    		break;
		}
		else if(actype==2)
		{
			strcpy(use1.ac_type,"CURRENT");
			break;
		}
		else printf("\n\n PLEASE ENTER VALID OPTION!..");
	}
	printf("\n\n YOU CHOOSE \"%s\" ACCOUNT \n",use1.ac_type);
	printf("\n\n YOUR (10-digits) ACCOUNT NUMBER IS: %s\n",ac);
	strcpy(use1.ac_no,ac);
    printf("\n\n SET YOUR PIN/PASSWORD (4-digit number): ");
    scanf("%d", &use1.password);
    while(1){
    	printf("\n\n INITIAL DEPOSIT AMOUNT: ");
    scanf("%d", &use1.amount);
    if(use1.amount>0)
    {
    	break;
	}
	}
    
    profile=fopen("ACCOUNT_DETAILS.txt","a+");
    fprintf(profile,"\n NAME OF USER: %s | ACCOUNT NUMBER: %s | password: %d",use1.name,use1.ac_no,use1.password);
    fclose(profile);
    fp = fopen(use1.ac_no, "wb");
    if (fp == NULL) {
        printf("\n ERROR WHILE CREATE ACCOUNT....!\n");
        return;
    }

    fwrite(&use1, sizeof(use1), 1, fp);
    fclose(fp);
    printf("-------------------------------------------------------------------------------------------------------------------------");
    printf("\n ACCOUNT CREATION IN PROGRESS! DO NOT CLOSE THE APPLICATION");
    int j;
    for (j = 0; j < 5; j++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }

    printf("\n\n ACCOUNT SUCCESSFULLY CREATED!\n");
}
void view_account_details(struct user *use2)
{ int option;

    system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN PAGE \xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n ================ YOUR DETAILS ================\n");
        printf("\n NAME: %s", use2->name);
        printf("\n\n PHONE_NUMBER: %s", use2->number);
        printf("\n\n DATE OF BIRTH: %d/%d/%d", use2->dob.date, use2->dob.month, use2->dob.year);
        printf("\n\n ADDRESS: %s", use2->address);
        printf("\n\n ACCOUNT TYPE: %s",use2->ac_type);
        printf("\n\n ACCOUNT CURRENT BALANCE: %d", use2->amount);
        printf("\n\n ============================================");

        printf("\n\n PRESS ANY KEY TO GO BACK ");
        getch();
        login_menu(use2->ac_no);
        
    }
void change_account_details(char *ac_no)
    { 
    FILE *fp;
    struct user use3;
    int op, valid_date = 0;
    fp = fopen(ac_no, "rb");
    if (fp == NULL) {
        printf("\n ACCOUNT NOT FOUND!\n");
        return;
    }
    fread(&use3, sizeof(use3), 1, fp);
    fclose(fp);

    system("cls");
    printf("\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 EDITOR SECTION \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n ================ YOUR DETAILS ================\n");
    printf("\n [1]NAME: %s",use3.name);
    printf("\n\n [2]PHONE_NUMBER: %s",use3.number);
    printf("\n\n [3]DATEOFBIRTH: %d/%d/%d",use3.dob.date,use3.dob.month,use3.dob.year);
    printf("\n\n [4]ADDRESS: %s",use3.address);
    printf("\n\n [5]PIN NUMBER: %d",use3.password);
    printf("\n\n =============================================");
    printf("\n WHAT DO YOU WANT TO CHANGE: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("\n ENTER YOUR NAME: ");
            scanf(" %s", use3.name);
            break;
            case 2:
            printf("\n ENTER YOUR MOBILE NUMBER: ");
            scanf("%10s", use3.number);
            while ((getchar()) != '\n'); 
            break;
            case 3:
            while (!valid_date) {
                printf("\n ENTER YOUR DATE OF BIRTH (DD/MM/YYYY): ");
                scanf("%d/%d/%d", &use3.dob.date, &use3.dob.month, &use3.dob.year);
                if (use3.dob.date >= 1 && use3.dob.date <= 31 && use3.dob.month >= 1 && use3.dob.month <= 12 && use3.dob.year >= 1900 && use3.dob.year <= 2020) {
                    valid_date = 1;
                } else {
                    printf("\nINVALID DATE! PLEASE ENTER AGAIN..!\n");
                }
            }
            break;
            case 4:
            printf("\n ENTER YOUR ADDRESS: ");
            scanf(" %[^\n]s", use3.address);
            break;
        case 5:
        printf("\n ENTER YOUR 4-DIGIT PIN: ");
            scanf("%d",&use3.password);
            break;

        default:
            printf("\n ENTER A VALID OPTION!\n");
            printf("\n PRESS ANY KEY TO GO BACK ");
            getch();
            login_menu(ac_no);
    }

    // Save updated details
    fp = fopen(use3.ac_no, "wb");
    if (fp == NULL) {
        printf("\n ERROR WHILE UPDATING FILE!\n");
        return;
    }

    fwrite(&use3, sizeof(use3), 1, fp);
    fclose(fp);
    printf("\n\n=============================================");
    printf("\n\nCHANGE MADE SUCCESSFULLY!!"); 
    printf("\n\n PRESS any key to go back");
    getch();
    login_menu(ac_no);
}

void withdrawl(char *ac_no) {
    struct user use1;
    FILE *fp;
    FILE *his;
    char choice[11],dum_ac[11];
    int amount, op,option,pword;
    time_t t;
    struct tm *timeInfo;
    fp = fopen(ac_no, "rb");
    if (fp == NULL) {
        printf("\n\tACCOUNT NOT FOUND....!\n");
        return;
    }
    fread(&use1, sizeof(use1), 1, fp);
    fclose(fp);
    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2 ATM MENU \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n [1] AMOUNT WITHDRAWL");
    printf("\n\n [2] DEPOSIT AMOUNT");
    printf("\n\n ENTER YOUR CHOICE: ");
    scanf("%d",&option);
    if(option==1){
        system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2 ATM MENU \xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\n YOUR CURRENT ACCOUNT BALANCE IS: %d", use1.amount);
        printf("\n\n ENTER THE AMOUNT YOU WANT TO WITHDRAW: ");
        scanf("%d", &amount);
        printf("\n\n ENTER YOUR 4-DIGIT PIN: ");
        scanf("%d",&pword);
        if(pword!=use1.password){
            printf("\n\n PLEASE ENTER THE VALID PASSWORD");
            Sleep(2000);
            withdrawl(ac_no);
        }
        if (amount <= 0 || amount > 9999) {
            printf("\n INVALID AMOUNT! ENTER A VALUE BETWEEN 1 AND 9999.\n");
            withdrawl(ac_no);
        }
        if (amount > use1.amount) {
            printf("\n INSUFFICIENT BALANCE!\n");
            withdrawl(ac_no);
        }
        printf("\n PROCESSING YOUR REQUEST ");
        int j;
        for (j = 0; j < 5; j++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }

    use1.amount -= amount;
    time(&t);
    timeInfo = localtime(&t);
    strcpy(choice,"withdrawl");
}
else if(option==2){
    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2 ATM MENU \xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n YOUR CURRENT ACCOUNT BALANCE IS: %d", use1.amount);
    printf("\n\n ENTER THE AMOUNT YOU WANT TO DEPOSIT: ");
    scanf("%d",&amount);
    printf("\n\n ENTER YOUR 4-DIGIT PIN: ");
    scanf("%d",&pword);
    if(pword!=use1.password){
        printf("\n\n PLEASE ENTER THE VALID PASSWORD");
        Sleep(2000);
        withdrawl(ac_no);
    }
    if(amount>20000){
        printf("\n\n SORRY YOU ARE UNABLE TO DEPOSIT THAT AMOUNT");
        withdrawl(ac_no);
    }
    printf("\n\n PROCESSING YOUR REQUEST ");
    int j;
    for (j = 0; j < 5; j++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }
    use1.amount+=amount;
    time(&t);
    timeInfo=localtime(&t);
    strcpy(choice,"DEPOSIT");
}
else 
{
    printf("\n\n PLEASE ENTER A VALID OPTION");
    Sleep(2000);
    withdrawl(ac_no);
}

    fp = fopen(use1.ac_no, "wb");
    if (fp == NULL) {
        printf("\n ERROT UPDATING FILE..!\n");
        return;
    }
    fwrite(&use1, sizeof(use1), 1, fp);
    fclose(fp);

    printf("\n\n TRANSACTION SUCCESSFUL!");
    printf("\n\n DO YOU WANT TO PRINT A RECEIPT? (1 FOR YES, ANY OTHER NUMBER FOR NO): ");
    scanf("%d", &op);
    int i;
    
    if (op == 1) {
    	printf("\n PRINTING YOUR RECIPT ");
    	for(i=0;i<5;i++)
		{
			Sleep(500);
			printf(".");
			fflush(stdout);
		}
        system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2 ATM MENU \xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\n\t\t\t\t\t\t\t   ================================\n");
        printf("\t\t\t\t\t\t\t            WITHDRAWAL RECEIPT     \n");
        printf("\t\t\t\t\t\t\t    ================================\n");
        printf("\n\t\t\t\t\t\t\t    DATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
               timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
               timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        printf("\n\t\t\t\t\t\t\t    AMOUNT %s: %d\n",choice,amount);
        printf("\n\t\t\t\t\t\t\t    REMAINING BALANCE: %d\n", use1.amount);
        printf("\t\t\t\t\t\t\t    ================================\n");
        printf("\t\t\t\t\t\t\t    THANK YOU FOR BANKING WITH US!\n");
        printf("\t\t\t\t\t\t\t    ================================\n");
    } else {
        printf("\n\n THANK YOU FOR BANKING WITH US!\n");
    }
    strcpy(dum_ac,ac_no);
    strcat(dum_ac,".his");
    his = fopen(dum_ac, "a");
    if (his != NULL) {
        
        fprintf(his, "\n\tDATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
                timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
                timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        fprintf(his, "\n\tAMOUNT %s: %d\n", choice,amount);
        fprintf(his, "-------------------------------------------------\n");
		fclose(his);
    } else {
        printf("\n Error updating transaction history!\n");
    }
    printf("\n\n PRESS ANY KEY TO GO BACK");
    getch();
    login_menu(ac_no);
}
void transaction(char *ac_no)
{
	struct user use1;
	struct user2 use2;
	FILE *fp;
	FILE *his;
	char ac_no1[11],ac_no2[11];
	int pword,op;
	int amount;
	time_t t;
    struct tm *timeInfo;
	system("cls");
	printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\n\t\t\t\t\t\t   =============== TRANSACTION SECTION ===============\n");
	printf("\n\n ENTER THE RECEIVER ACCOUNT NUMBER: ");
	scanf("%s",ac_no2);
	fp=fopen(ac_no,"rb");
	 if (fp == NULL) {
        printf("\n ACCOUNT NOT FOUND....!\n");
        return;
    }
	fread(&use1,sizeof(use1),1,fp);
	fclose(fp);

	fp=fopen(ac_no2,"rb");
	 if (fp == NULL) {
        printf("\n ACCOUNT NOT FOUND....!\n");
        Sleep(2000);
        login_menu(ac_no);
    }
    fread(&use2,sizeof(use2),1,fp);
	fclose(fp);
	printf("\n\n ENTER THE AMOUNT TO TRANSFER: ");
	scanf("%d",&amount);

	if(amount>use1.amount)
	{
		printf("\n INSUFFICIENT BALANCE");
		login_menu(ac_no);
	}
	printf("\n\n ENTER YOUR 4-DIGIT PIN: ");
	scanf("%d",&pword);
	if(pword!=use1.password)
	{ printf("\n\n PLEASE ENTER THE VALID PASSWORD!....");
		Sleep(3000);
		system("cls");
		transaction(ac_no);
    }
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
		printf("\n\n YOUR TRANSACTION IS PROCESSING");
		for(i=0;i<5;i++)
		{
			Sleep(500);
			printf(".");
			fflush(stdout);
		}
		printf("\n\n TRANSACTION IS SUCCESSFULLY MADE!");
		printf("\n\n DO YOU WANT TO PRINT A RECEIPT? (1 FOR YES, ANY OTHER NUMBER FOR NO): ");
		scanf("%d",&op);
		if(op==1)
		{
			printf("\n\n PRINTING YOUR RECIPT");
			for(i=0;i<5;i++)
		{
			Sleep(500);
			printf(".");
			fflush(stdout);
		}
		system("cls");
		printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
		printf("\n\t\t\t\t\t\t   =============== TRANSACTION SECTION ===============\n");
		printf("\n\n\t\t\t\t\t\t\t    ===============================\n");
        printf("\t\t\t\t\t\t\t            TRANSACTION RECIPT    \n");
        printf("\t\t\t\t\t\t\t    ===============================\n");
        printf("\n\t\t\t\t\t\t\t    DATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
               timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
               timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        printf("\n\t\t\t\t\t\t\t    AMOUNT TRANSFERRED: %d\n", amount);
        printf("\n\t\t\t\t\t\t\t    RECEIVER ACCOUNT NUMBER: %s\n",use2.ac_no);
        printf("\n\t\t\t\t\t\t\t    REMAINING BALANCE: %d\n", use1.amount);
        printf("\t\t\t\t\t\t\t    ===============================\n");
        printf("\t\t\t\t\t\t\t    THANK YOU FOR BANKING WITH US!\n");
        printf("\t\t\t\t\t\t\t    ===============================\n");
		
		}
    strcpy(ac_no1,use1.ac_no);
    strcat(ac_no1,".his");
    his = fopen(ac_no1, "a");
    if (his != NULL) {
        
        fprintf(his,"\n\tDATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
                timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
                timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        fprintf(his,"\n\tRECEIVER ACCOUNT NO: %s\n",use2.ac_no);
        fprintf(his,"\n\tAMOUNT TRANSFERED: %d\n", amount);
        fprintf(his,"-------------------------------------------------\n");
		fclose(his);
    } else {
        printf("\n ERROR OCCUR IN SAVING TRANSATION.....!\n");
    }
strcat(ac_no2, ".his");
    his = fopen(ac_no2, "a");
    if (his != NULL) {
        
        fprintf(his, "\n\tDATE: %02d-%02d-%d TIME: %02d:%02d:%02d\n",
                timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
                timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        fprintf(his,"\n\tSENDER ACCOUNT NO: %s\n",use1.ac_no);
        fprintf(his,"\n\tAMOUNT RECEIVED: %d\n", amount);
        fprintf(his, "-------------------------------------------------\n");
    fclose(his);
    } else {
        printf("\n ERROR OCCUR IN SAVING TRANSATION.....!\n");
    }
printf("\n\n PRESS ANY KEY TO GO BACK");
getch();
login_menu(ac_no);
}

void transaction_history(char *ac_no)
{
	struct user use1;
    FILE *fp;
    FILE *his;
    char dum_ac[11],line[256];
    fp = fopen(ac_no, "rb");
    if (fp == NULL) {
        printf("\n ACCOUNT NOT FOUND!\n");
        return;
    }
    fread(&use1, sizeof(use1), 1, fp);
    fclose(fp);
    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t ================ TRANSACTTION HISTORY ================\n\n\n");
    printf("\n CURRENT ACCOUNT BALANCE: %d\n",use1.amount);
    printf("\n-------------------------------------------------\n");
    strcpy(dum_ac,use1.ac_no);
    strcat(dum_ac,".his");
    his = fopen(dum_ac, "r");
    if (his == NULL)
    {
        printf("\n ACCOUNT NOT FOUND........!!\n");
        return;
    }
    while(fgets(line,sizeof(line),his))
    {
        printf("%s",line);
    }
    printf("\n\n PRESS ANY KEY TO GO BACK");
    getch();
    login_menu(ac_no);
}
void loan_section(char *ac_no) {
    struct user use1;
    FILE *fp;
    int option, loan;
    
    fp = fopen(ac_no, "rb");
    if (!fp) {
        printf("\n ACCOUNT NOT FOUND!\n");
        return;
    }
    fread(&use1, sizeof(use1), 1, fp);
    fclose(fp);
    
    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t      ================ LOAN SECTION ================\n\n\n");
    printf("\n\n [1] APPLY FOR LOAN");
    printf("\n\n [2] VIEW LOAN STATUS");
    printf("\n\n [3] REPAY LOAN");
    printf("\n\n [4] EXIT");
    printf("\n\n Enter your choice: ");
    scanf("%d", &option);
    
    switch (option) {
    case 1:
    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t      ================ LOAN SECTION ================\n\n");

    if (use1.loan_status == 1) {
        printf("\n\n YOU ALREADY HAVE AN ACTIVE LOAN OF RS.%d", use1.loan_amount);
        printf("\n\n PRESS ANY KEY TO GO BACK");
        getch();
        break;
    }

    printf("\n\nENTER LOAN AMOUNT YOU WANT: ");
    scanf("%d", &loan);

    if (loan <= 0) {
        printf("\n\n INVALID LOAN AMOUNT");
        printf("\n\n PRESS ANY KEY TO GO BACK");
        getch();
        break;
    } else if (loan >= 500000) {
        printf("\n\n YOUR LOAN AMOUNT IS TOO HIGH");
        printf("\n\n PRESS ANY KEY TO GO BACK");
        getch();
        break;
    } else {
        float interest_rate = 5.0;
        int duration_months = 12;

        float interest = (loan * interest_rate * duration_months) / (100 * 12);
        float total_with_interest = loan + interest;

        use1.loan_amount = total_with_interest;
        use1.loan_status = 1;
        use1.amount += loan;

        printf("\n\n LOAN APPROVED OF RS.%d", loan);
        printf("\n INTEREST: RS.%.2f", interest);
        printf("\n TOTAL PAYABLE: RS.%.2f", total_with_interest);
        printf("\n RS.%d CREDITED TO YOUR ACCOUNT", loan);
    }
    printf("\n\n PRESS ANY KEY TO GO BACK");
    getch();
    break;

    case 2:
            system("cls");
            printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\t\t\t\t\t\t      ================ LOAN SECTION ================\n\n");
            if (use1.loan_status == 0) {
                printf("\n\n LOAN STATUS: NO ACTIVE LOAN");
                printf("\n\n PRESS ANY KEY TO GO BACK");
                getch();
                break;
                
            } else {
                printf("\n\n LOAN STATUS: YOU HAVE ACTTIVE LOAN Rs.%d", use1.loan_amount);
                printf("\n\n PRESS ANY KEY TO GO BACK");
                getch();
                break;
            }
            break;
            
    case 3:
            system("cls");
            printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\t\t\t\t\t\t    ================ LOAN SECTION ================\n\n");
            if (use1.loan_status == 0) {
                printf("\n\n NO LOAN EMI TO PAY");
                printf("\n\n PRESS ANY KEY TO GO BACK");
                getch();
                break;
            }
            printf("\n\n ENTER YOU EMI AMOUNT TO PAY: ");
            scanf("%d", &loan);
            if (loan > use1.amount) {
                printf("\n\n INSUFFICIANT BALANACE!");
                printf("\n\n PRESS ANY KEY TO GO BACK");
                getch();
                break;

            } else if (loan >= use1.loan_amount) {
                use1.amount -= use1.loan_amount;
                use1.loan_amount = 0;
                use1.loan_status = 0;
                printf("\n\n LOAN IS FULLY PAID!");
                printf("\n\n PRESS ANY KEY TO GO BACK");
                getch();
                break;

            } else {
                use1.amount -= loan;
                use1.loan_amount -= loan;
                printf("\n\n RS.%d AMOUNT ID REPAYED REMAININING LOAN RS.%d", loan, use1.loan_amount);
                printf("\n\n PRESS ANY KEY TO GO BACK");
                getch();
                break;  
            }
            break;
    case 4:
        login_menu(ac_no);
        break;

    default:
            printf("\n invalid option!");
            Sleep(3000);
            loan_section(ac_no);

    }
    fp = fopen(ac_no, "wb");
    fwrite(&use1, sizeof(use1), 1, fp);
    fclose(fp);
    loan_section(ac_no);
}
void login_menu(char *ac_no){
    int option2,i;
    struct user use2;
    FILE *fp = fopen(ac_no, "rb");
    if (fp == NULL) {
        printf("\nACCOUNT NOT FOUND!\n");
        return;
    }
    fread(&use2, sizeof(use2), 1, fp);
    fclose(fp);
        system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN PAGE \xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\n [1] VIEW ACCOUNT DETAILS");
        printf("\n\n [2] CHANGE ACCOUNT DETAILS");
        printf("\n\n [3] WIHTDRAWL (OR) DEPOSIT AMOUNT");
        printf("\n\n [4] FUND TRANSACTION ");
        printf("\n\n [5] LOAN " );
        printf("\n\n [6] TRANSACTION HISTORY");
        printf("\n\n [7] LOGOUT ");
        printf("\n\n ENTER YOUR CHOICE :");
        scanf("%d",&option2);

        switch(option2)

        {
            case 1: view_account_details(&use2);break;
            case 2: change_account_details(ac_no);break;
            case 3: withdrawl(ac_no);break;
            case 4: transaction(ac_no);break;
            case 5: loan_section(ac_no);break;
            case 6: transaction_history(ac_no);break;
            case 7:
            printf("\n\n LOGING OUT YOUR ACCOUNT ");
            for(i=0;i<5;i++)
            {
                Sleep(500);
                printf(".");
                fflush(stdout);
            }
            main_menu() ; 
            break;
            default : printf("\n\n ENTER VALID OPTION"); login_menu(ac_no);
        }
}

void login() {
    FILE *fp;
    struct user use2;
    char ac_no[50];
    int i,pword,option1,option2;

    system("cls");
    printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN PAGE \xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n\n ENTER YOUR ACCOUNT_NO: ");
    scanf("%49s",ac_no);
    fp = fopen(ac_no, "rb");
    if (fp == NULL) {
        printf("\nACCOUNT NOT FOUND!\n");
        return;
    }

    fread(&use2, sizeof(use2), 1, fp);
    fclose(fp);
    printf("\n\n ENTER YOUR 4-DIGIT PIN: ");
    scanf("%d", &pword);
    if (use2.password != pword) {
       printf("\n\n YOUR PIN NUMBER IS INCORRECT!( PRESS 1 IF YOU FORGET PASSWORD ): ");
        scanf("%d",&option1);
        if(option1==1)
        {
        	forget_password(& use2);
		}
		else printf("\n\n THANK YOU BANKING WIHT US! ");return;
    }
    printf("\n\n LOGING TO YOUR ACCOUNT ");
    for(i=0;i<5;i++)
    {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }
login_menu(ac_no);

}


void account_delete()
{
	char ac_no[10];
	int pword,option;
	FILE *fp;
	struct user use;
	system("cls");
	printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\n\t\t\t\t\t\t  ============= ACCOUNT DELETION SECTION =============\n");
	
	printf("\n\n ENTER YOUR ACCOUNT NUMBER TO DELETE: ");
	scanf("%s",ac_no);
	fp=fopen(ac_no,"r");
	if(fp==NULL)
	{
		printf("\n NO ACCOUNT FOUND !");
		return ;
	}
	fread(&use,sizeof(use),1,fp);
	fclose(fp);
	printf("\n\n ENTER YOUR 4-DIGIT PIN NUMBER: ");
	scanf("%d",&pword);
	
	while(1){
	if(pword!=use.password)
	{
		printf("\n\n PLEASE ENTER CORRECT PIN NUMBER: ");
		scanf("%d",&pword);
	}
	else break;
	}
	
	printf("\n\n WOULD YOU LIKE TO DELETE YOUR ACCOUNT ? (PRESS 1 IF YOU WANT TO DELETE) : ");
	scanf("%d",&option);
	
	if(option!=1)
	{
	printf("\n\n THANK YOU FOR BANKING WITH US.. ");
	
	return ;
	}
	int i;
	printf("\n\n DELETING YOUR ACCOUNT ");
	for(i=0;i<=5;i++)
	{
		Sleep(500);
		printf(".");
		fflush(stdout);
	}
	remove(use.ac_no);
	strcat(ac_no,".his");
	remove(ac_no);
	FILE *file = fopen(FILE_NAME, "r");
	FILE *temp = fopen("temp.txt","w");
    if (!file) return ;

    char line[10 + 2];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line,ac_no) == 0) {
        	continue;
        }
        fprintf(temp,"%s\n",line);
    }
    fclose(file);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt",FILE_NAME);
    

	system("cls");
	printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\n\t\t\t\t\t\t  ============= ACCOUNT DELETION SECTION =============\n");
	
	printf("\n\n ACCOUNT DELETED SUCCESSFULLY...");
		
}

void main_menu() {
    int op;
    int option;

    while (1) {
        system("cls");
        printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t\t\t\t\t\t ================  WELCOME TO MAINMENU  ================\n");
        printf("\n\n\n [1] CREATE A NEW ACCOUNT\n");
        printf("\n [2] LOGIN TO YOUR ACCOUNT\n");
        printf("\n [3] DELETE AN EXISTING ACCOUNT\n");
        printf("\n [4] EXIT \n");
        printf("\n\n PLEASE!...ENTER YOUR OPTION: ");
        scanf("%d", &op);

        switch (op) {
            case 1: create_account(); break;
            case 2: login(); break;
            case 3: account_delete();break;
            case 4: exit(0);
            default: printf("\nINVALID CHOICE!\n");
        }
        
        printf("\n\n\n press 1 if you want to continue: ");
        scanf("%d",&option);
        if (option!=1) {
            break;
        }
    }
}

int main() {
    main_menu();
    return 0;
}
