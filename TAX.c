//Program to Save Record of Tax Payer


//Header Files
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//Function Declaration Part
int Add();
void Delete();
int List();
void Search();
void Edit();

//Structure to store Record
struct data
{
    char name[20];
    int id,age;
    long long int  income;
    long long int tpay;
    int trate;
}studata;

//Main Function
int main(void)
{
    int input,i,n;
    char user[20];
    
    
    printf("\n%105s","INCOME TAX CALCULATOR");
    printf("\n%105s\n","---------------------");
    printf("\n\n%s\n","ENTER THE USER NAME");
    gets(user);
    user[0]=toupper(user[0]);
    printf("Hello %s\n",user);
    A:
    	
    	for(i=0;i<5;i++)
    	printf("==========================================");
    printf("\n\nWHAT WOULD YOU LIKE TO DO\n\n");
    printf("PRESS 1 = TO VIEW LIST\nPRESS 2 = TO ADD DATA TO RECORD\nPRESS 3 = TO EDIT DATA IN RECORD\nPRESS 4 = TO DELETE DATA FROM RECORD\n");
    printf("PRESS 5 = TO SEARCH DATA IN RECORD\nPRESS 6 = TO EXIT\n");
    scanf("%d",&input);
    switch(input)
    {
    case 1:
        List();
        break;
    case 2:
    	printf("How Many Record You Want To Add");
    	scanf("%d",&n);
    	for(i=0;i<n;i++)
        Add();
        printf("\n****Record Has Been Added****\n");
        break;
    case 3:
        Edit();
        printf("\n****Record Has Been Edited****\n");
        break;
    case 4:
        Delete();
        printf("\n****Record Has Been Deleted****\n");
        break;
    case 5:
        Search();
        break;
    case 6:
    	printf("THIS IS CSE PROJECT BY SIDDHARTH CHOUDHARY/nROLL NO:K17DQ50\n");
    	printf("********THANKYOU**********");
        return 0;
    default:
        printf("INVALID INPUT TRY AGAIN");
        break;
    }
    goto A;
}


int List()
{
    char c;
    int d,i=0;
FILE *fptr;
fptr=fopen("tax calculator100.txt","rb");

printf("THE DATA IN THE RECORD IS:\n\n");

printf("%-5s|%-20s|%-10s|%-5s|%-20s|%-10s|%-20s\n","NO.","NAME","ID NO","AGE","INCOME","tax rate","tax pay");

while(fread(&studata,sizeof(struct data),1,fptr)>0)
{
	i++;
if(studata.id!=0)
printf("%-5d|%-20s|%-10d|%-5d|%-20lld|%-10d|%-20lld\n",i,studata.name,studata.id,studata.age,studata.income,studata.trate,studata.tpay);

}
fclose(fptr);
}



int Add()
{
printf("ENTER THE CUSTOMER RECORED\n\n");
FILE *fptr;
fptr=fopen("tax calculator100.txt","ab");

printf("enter the tax payer name\n");
scanf("%s",studata.name);
printf("enter the tax payer id\n");
scanf("%d",&studata.id);
printf("enter the tax payer age\n");
scanf("%d",&studata.age);
printf("enter the tax payer income\n");
scanf("%lld",&studata.income);
if(studata.age<60)
    {

        if(studata.income<250000)
            {
                studata.trate=0;
                studata.tpay=studata.income;
            }
        if(studata.income>=250000&&studata.income<500000)
            {
                studata.trate=10;
                studata.tpay=(studata.income)/10;
            }
        if(studata.income>=500000&&studata.income<1000000)
    		{
    			    studata.trate=20;
            studata.tpay=(studata.income)/20;
			}
    	if(studata.income>=1000000)
            {
                studata.trate=30;
                studata.tpay=(studata.income)/30;
            }
    }
if(studata.age>=60&&studata.age<80)
    {
        if(studata.income<300000)
            {
                studata.trate=0;
                studata.tpay=(studata.income);
            }
        if(studata.income>=300000&&studata.income<500000)
            {
                studata.trate=10;
                studata.tpay=(studata.income)/10;
            }
        if(studata.income>=500000&&studata.income<1000000)
            {
                studata.trate=20;
            studata.tpay=(studata.income)/20;
            }
        if(studata.income>=1000000)
            {
                studata.trate=30;
                studata.tpay=(studata.income)/30;
            }

    }
if(studata.age>80)
    {
        if(studata.income<500000)
            {
                studata.trate=0;
                studata.tpay=(studata.income);
            }
        if(studata.income>=500000&&studata.income<1000000)
            {
                studata.trate=20;
                studata.tpay=(studata.income)/20;
            }
        if(studata.income>=1000000)
            {
                studata.trate=30;
                studata.tpay=(studata.income)/30;
            }

}


fwrite(&studata,sizeof(struct data),1,fptr);


fclose(fptr);
}



void Delete()
{
    int no,i=0;
    FILE *fptr,*fp1;
        List();
    printf("\n\nEnter ID You Want To Delete\n");
    scanf("%d",&no);
    fptr=fopen("tax calculator100.txt","rb");
    fp1=fopen("temp1.txt","wb");
    while(fread(&studata,sizeof(studata),1,fptr)>0)
    {
        if(studata.id!=no)
        {
            fwrite(&studata,sizeof(studata),1,fp1);
        }
    }
    fclose(fp1);
    fclose(fptr);
remove("tax calculator100.txt");
rename("temp1.txt","tax calculator100.txt");
}




void Search()
{
    int i=0;
    int key;
    FILE *fptr;
   	fptr=fopen("tax calculator100.txt","rb");
    printf("\nEnter The ID You Want To Search=");
    scanf("%d",&key);
    puts("");
    while((fread(&studata,sizeof(studata),1,fptr))>0)
    {
    if(key==studata.id)
    {
        printf("Yes It Is Founded\n");
        printf("CUSTOMER NAME:%s\nCUSTOMER ID:%d\nCUSTOMER AGE:%d\nCUSTOMER INCOME:%lld\n",studata.name,studata.id,studata.age,studata.income);
    	printf("CUSTOMER TAX RATE:%d\nCUSTOMER TAX TO PAY:%lld\n",studata.trate,studata.tpay);
    	i++;
	}
	
}
if(i==0)
	printf("\nSorry, No Record Found");
}

void Edit()
{

    int no;
    FILE *fptr,*fp1;
    fptr=fopen("tax calculator100.txt","rb");
    fp1=fopen("temp1.txt","wb");
    printf("\n\nEnter The ID You Want To Edit\n");
    scanf("%d",&no);

    while(fread(&studata,sizeof(studata),1,fptr)>0)
    {
        if(studata.id!=no)
        {
            fwrite(&studata,sizeof(studata),1,fp1);
        }
    }
    fclose(fptr);
    fclose(fp1);
remove("tax calculator100.txt");
rename("temp1.txt","tax calculator100.txt");
Add();

}

