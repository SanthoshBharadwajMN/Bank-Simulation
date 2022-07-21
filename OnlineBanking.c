//*****************************************************************************
//*****************************************************************************

//                        	ONLINE BANKING SERVICE


//*****************************************************************************
//*****************************************************************************

#include<stdio.h>      //importing header files

#include<string.h>
#include<stdlib.h>
#include<termios.h>

#define ENTER 13


//******************************************************************************
// to run termios
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old); //grab old terminal i/o settings
    new = old; //make new settings same as old settings
    new.c_lflag &= ~ICANON; //disable buffered i/o
    new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
    tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* 
Read 1 character without echo 
getch() function definition.
*/
char getch(void)
{
    return getch_(0);
}

//*****************************************************************************
//*****************************************************************************

// START OF MAIN PROGRAM............

void login(void);                             // function decleration

void signup(void);

void menu(void);
void close(void);
void see(void);
void erase1(void);
void transact(void);
void new_acc();
void fordelay(int j);
void edit();

int n;                                     // global variables
int j;
int main_exit;

//*****************************************************************************
                                                    //  structure decleration  

static int i=0;


struct

{

char name1[30],pass[30];

}write,comp;

struct date{
    int day,month,year;

    };
struct {
    char name[30];
    int acc_no,age;
    char address[60];
    char aadhar[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;
                               



//*****************************************************************************
//*****************************************************************************

                                          // main function
int main()

{

system("clear");
printf("\n\n\n\n\n\t\t\t\tONLINE BANKING PORTAL");

printf("\n\t\t\t\t=====================");

printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");

if(getch()==13)

  system("clear");

XY:

printf("\n\n\n\n\t\t\t1. LOGIN\t\t2. SIGNUP");

printf("\n\n\t\t\t\tENTER YOUR CHOICE: ");

scanf("%d",&n);

switch(n)

  {

    case 1: system("clear");

        login();

        break;

    case 2: system("clear");

        signup();

        break;

    default: printf("\n\n\t\t\t\tNO MATCH FOUND");

        printf("\n\n\t\t\tPress Enter to re-Enter the choice");

        if(getch()==13)

        system("clear");
        goto XY;

  }

  return 0;

}

//*****************************************************************************
//*****************************************************************************
                                                  
                                                  // defining function

void signup()

  {
  	FILE *ptr;
  	ptr=fopen("file.dat","a+");
  	system("clear");
  	printf("\n\n\t\t\t\tWELCOME TO SIGN-UP PORTAL");

        printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",write.name1);
   
   	while(fscanf(ptr,"%s %s\n",write.name1,write.pass)!=EOF)
   	{
   		
        if (comp.name1==write.name1)
        {
          printf("USERNAME ALREDY EXISTS !");
            fordelay(1000000000);
                break;
         }
         else
         {
         
            break;
          }
        }
        
        printf("\n\n\t\t\t\t  SET PASSWORD: ");
        scanf(" %s",write.pass);
        fprintf(ptr,"%s %s\n",write.name1,write.pass);
        
        fclose(ptr);

        printf("\n\n\t\tYour sign up was successful");

        printf("\n\n\t\tTry login your account??\n\n\t\t  ");

        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR EXIT \n\n\t\t\t\t");

        scanf("%d",&n);

        switch(n)

          {

              case 1: system("clear");

                    login();

                    break;

              case 2: system("clear");

                    printf("\n\n\t\t\t\t\tTHANK YOU FOR SIGNING IN\n\n\n");
                    exit(0);

          }  
}
        

//*****************************************************************************

void login()
{
	FILE *ptr;
       char name[30],pass[30];

       int checku,checkp;

       ptr=fopen("file.dat","r");
       printf("\n\n\t\t\t\tWELCOME TO LOG-IN PORTAL");

       printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
       log:

       printf("\n\n\t\t\t\t  ENTER USERNAME: ");

       scanf("%s",name);

       printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
       scanf("%s",pass);
       
         while (fscanf(ptr,"%s %s",write.name1,write.pass)!=EOF)
          {
          

          checku=strcmp(name,write.name1);

          checkp=strcmp(pass,write.pass);

          if(checku==0 && checkp==0)

          {

            system("clear");

            printf("\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");

            printf("\n\t\t\t\tWELCOME, HAVE A NICE DAY");
            system("clear");
            menu();
          }
          else if(checku==0&&checkp!=0)

           {

            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);

            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");

            if(getch()=='y'|| getch()=='Y')
            	goto log;
            	
            }
          else

          {

            printf("\n\tYou are not a Registered User\n \t\t\tPls register yourself\n\n\n");
           signup();
           }
       }
 }

     
//*****************************************************************************
   
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
//*****************************************************************************

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
//*****************************************************************************

void menu(void)
{
   int choice;
    system("clear");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("clear");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase1();
        break;
        case 6:close();
        break;

    }
}
//*****************************************************************************

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("clear");
    printf("\t\t\t ADD RECORD  ");
    printf("\n\n\nEnter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the aadhar number:");
    scanf(" %s",add.aadhar);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:Rs ");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t@.Saving\n\t@.Current\n\t@.Fixed1(for 1 year)\n\t@.Fixed2(for 2 years)\n\t@.Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("clear");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//*****************************************************************************
void edit()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the user whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("clear");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,upd.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("clear");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("clear");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("clear");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("clear");
                 if (main_exit==1)
                 menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;
                    }
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("clear");
        if (main_exit==1)
            menu();
        else
            close();
        }
}
//*****************************************************************************

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmp(add.acc_type,"fixed1")==0||strcmp(add.acc_type,"fixed2")==0||strcmp(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("clear");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:Rs  ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:Rs  ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("clear");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("clear");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
//*****************************************************************************

void erase1(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the user you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase1();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("clear");
        if (main_exit==1)
            menu();
        else
            close();
        }

}
//*****************************************************************************

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
   
     printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("clear");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \naadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rs  %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmp(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs %.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+1);
                    }
                else if(strcmp(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);

                    }
                else if(strcmp(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+3);

                    }
                 else if(strcmp(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmp(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
       

    fclose(ptr);
     if(test!=1)
        {   system("clear");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("clear");
                if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("clear");
                        printf("\nInvalid!\a");
                        goto see_invalid;
                    }
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("clear");
            menu();
        }

        else
           {
		system("clear");
                close();
            }
      }

//*****************************************************************************

void close(void)
{
    printf("\n\n\n\n\t\t\t**************THANK YOU****************\n\n\n\n\n");
    exit(0);
}
//*****************************************************************************
//*****************************************************************************

                             //  THANK YOU
                             
 // MEMBERS: THANUJA D, SHRAVYA M, SHRADDHA NARAYAN HEGDE, SAHANA RG, SAKSHA R
 //TANISH CS, SANTHOSH BHARADWAJ MN ,SURYA ASHWIN K, ROHAN H RAJ.

//*****************************************************************************
//*****************************************************************************