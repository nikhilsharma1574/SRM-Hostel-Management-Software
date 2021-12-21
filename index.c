#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include<windows.h>
#include <unistd.h>


bool check = true;
int c,seat = 0, fullseat = 3;


struct flight{
  char name[30],origin[30],destination[30];
  int id,date,adult,child,infant,month,year,price;
};

struct refund{
  int refid,refprice;
};

void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int del(int , int);

void showLoading(char sh[])
{
  const int trigger = 500;
  const int numDots = 4;
    gotoxy(5,5);
   char prompt[100] ;
  strcpy(prompt,sh);
  int times=2;
  while (times--) {
      printf("\r%*s\r%s", numDots, "", prompt);

      for (int i = 0; i < numDots; i++) {
          usleep(trigger * 600);
          printf(".");
      }
  }
  fflush(stdout);
}

void hostel(){
  time_t t;
  time(&t);
  system("cls");
  FILE *g=NULL;
   gotoxy(22,0);
  printf("\n                                         SRM Booking Portal \n\n");
  printf("---------------------------------------------------------------------------------------------------\n");
  gotoxy(73,5);
  printf("%s\n",ctime(&t));
  printf("  Weclome Back Student\n");
  printf("  Please Login With SRM Student ID\n\n");
  char username[15];
  char password[12];
  char name[40];
  g=fopen("srmhostel.txt","a");
  printf("  Enter Student Name = ");
  scanf("%s",name);
  printf("  Enter Year = ");
  int year;
  int total=0;
  scanf("%d",&year);
  fputs("\n",g);
  fputs(name,g);
  fprintf(g," Year= %d ",year);
  gotoxy(25,14);
  printf(" Enter Management Username: ");
  scanf("%s",&username);
  gotoxy(25,16);
  printf(" Enter Password: ");
  scanf("%s",&password);
  if(strcmp(username,"srmadmin")==0)
  {
    if(strcmp(password,"ramapuram")==0)
   {
     system("cls");
     gotoxy(45,8);
     printf("\n\n                                      Welcome Login Success!\n");
     printf("                             Press Enter to redirect to Student profile\n");
     getch();
     system("cls");
     printf("\n                                        Welcome Back SRM Student \n");
     printf("---------------------------------------------------------------------------------------------------\n\n");
     gotoxy(73,5);
     printf("%s\n",ctime(&t));
     printf("  Select Hostel\n\n");
     printf("  1 Hostel 1 (AC)\n  2 Hostel 2 (AC)\n  3 Hostel 3 (NON-AC)\n  4 Hostel 4(NON-AC)\n\n");
     int c;
     printf("        Enter Your Choice = ");
     scanf("%d",&c);
     if (c==1 || c==2)
      {
  printf("  U Have Opt. For AC Room +2,10,000\n\n");
  total=total+210000;
  fputs("   AC Hostel\t",g);
      }
      else if (c==3 || c==4)
      {
       printf("  U Have Opt. For NON-AC Room +1,20,000\n\n");
       total=total+120000;
       fputs("  NON-AC Hostel\t",g);
      }
      else
      {
       printf("  Undefined Entery\n");
      }
      char q[5];
      printf("  Do U Want Mess Facility? (+20,000/-) yes/no =  ");
      scanf("%s",q);
      if (strcmp(q,"yes")==0)
      {
       printf("Mess Added\n\n");
       total=total+20000;
       fputs("Mess Added\t",g);
      }
      else if (strcmp(q,"no")==0)
     { printf("Mess Not Added\n\n");
       fputs("Mess Not Added\t",g);
     }
     else
     {
       printf("Undefine Input\n\n");
     }
     char transport_char[5];
     printf("  Do You Want Transport facility for 9000 per year ? (yes/no) = ");
     scanf("%s",transport_char);
     if (strcmp(transport_char,"yes")==0)
      {
       total=total+9000;
       fputs("Transport Added\t",g);
      }
      else if (strcmp(transport_char,"no")==0)
     {
       fputs("Transport Not Added\t",g);
     }
     else
     {
       printf("  Undefine Input\n\n");
     }
     system("cls");
     gotoxy(39,1);
     printf("Details To Be Confirmed\n ");
     printf("---------------------------------------------------------------------------------------------------\n\n\n");
     gotoxy(73,5);
     printf("%s\n",ctime(&t));
     printf("  Student ID                   = studentofsrm\n\n");
     printf("  Student Year                 = %d Year\n\n",year);
     switch (c)
     {
       case 1:
       case 2:
       printf("  Student Choosed Hostel type  = AC-ROOM\n\n");
       break;
       case 3:
       case 4:
       printf("  Student Choosed Hostel type  = NON-AC-ROOM\n\n");
       break;
     }
     if (strcmp(q,"yes")==0)
     {
       printf("  Mess Facility                = YES \n\n");
     }
     else if (strcmp(q,"no")==0)
     {
       printf("  Mess Facility                = NO \n\n");
     }
     else
     {
       printf("\n  Wrong password\n");
     }
     if (strcmp(transport_char,"yes")==0)
      {
       printf("  Transport                    = Added\n");
      }
      else if (strcmp(transport_char,"no")==0)
     {
       printf("  Transport                    = Not Added\n");
     }
     gotoxy(28,23);
     printf("  Press Enter To Go To Next Page");
     getch();
     system("cls");
      printf("\n                                    Payments Details / Feekart\n");
      printf("---------------------------------------------------------------------------------------------------\n");
      gotoxy(73,5);
      printf("%s\n",ctime(&t));
      printf("  Hostel Fees = ");
      if(c==1 || c==2)
      {
  printf("2,10,000/-\n\n");
      }
      if(c==3 || c==4)
      {
  printf("1,20,000/-\n\n");
      }
       if (strcmp(transport_char,"yes")==0)
      {
       printf("  Transport Fees = 9000/-\n\n");
      }
      else if (strcmp(transport_char,"no")==0)
     {
       printf("  Transport Fees = 0/-\n\n");
     }
     printf("  Mess Fees = ");
     if (strcmp(q,"yes")==0)
     {
       printf("20000/-\n\n");
     }
     if (strcmp(q,"no")==0)
     {
       printf("0/-\n\n");
     }
     printf("  Total Bill Ammount = %d",total);
     fprintf(g,"%d ",total);
     fprintf(g,"%s ",ctime(&t));
    }
   else
   {
     printf("\n  User doesn't exist\n\n");
   }
   getch();
   system("cls");
   printf("\n                                        Confirmation\n");
      printf("---------------------------------------------------------------------------------------------------\n");
      gotoxy(73,5);
      printf("%s\n",ctime(&t));
      printf("  Student Name = %s\n",name);
      printf("  Year = %d\n",year);
      gotoxy(20,12);
      printf("Press Enter To Send Data To Server");
      getch();
       system("cls");
       showLoading("Sending Data Please Wait");
       system("cls");
       gotoxy(25,12);
       printf("  Data Has Been Sent To College Server");
  }
    getch();
    system("cls");
    gotoxy(42,1);
    printf("   ReDirect Page\n ");
     printf("---------------------------------------------------------------------------------------------------\n\n\n");
    gotoxy(73,5);
    printf("%s\n",ctime(&t));
    printf("  Press 1 to Go To Main Page\n  Press 2 To Exit The Page\n\n");
    printf("       Enter Choice = ");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
     system("cls");
    main();
    }
    if(choice==2)
    {
    thankyou();
    //getch();
    }
    getch();
}
 void choice()
 {
  time_t t;
  time(&t);
  system("cls");
  gotoxy(22,2);
  printf("\n                               SRM Booking Portal \n\n");
  printf("---------------------------------------------------------------------------------------------------\n");
  gotoxy(73,5);
  printf("%s\n",ctime(&t));
  printf("  Select Operation ;-\n\n\n1) New Registration\n\n2) Data Server\n\n");
  printf("  Enter Choice = ");
  int choice1;
  scanf("%d",&choice1);
  if(choice1==1)
  { system("cls");
    hostel();
    getch();
  }
  if(choice1==2);
  {
   // check();
  }
  getch();
  system("cls");
}




void flight();
void flightBooking();
void flightCheck();
void flightCancel();
void thankyou(){
  system("cls");
  gotoxy(30,13);
  printf(" Thank You For Using SRM Help Desk\n");
  getch();
  exit(1);
}

void showDots(){
  printf("---------------------------------------------------------------------------------------------------");
}




void showHeader(){
  time_t t;
  time(&t);
  gotoxy(45,1);
   printf("Welcome To\n");
  gotoxy(42,2);
   printf("SRM Booking Portal \n");
   showDots();
   gotoxy(73,5);
   printf("%s",ctime(&t));
   //printf ("\n");
}



int main()
{
// clrscr();
// time_t t;
// time(&t);
 do
 {
   system("cls");
   showHeader();
   printf("  Select Booking Preffrence :-\n\n\n");
   printf("     1 - Flight Booking Service\n\n");
   printf("     2 - SRM hostel/Hostel Booking\n\n\n");
   gotoxy(27,20);
   printf("Please Enter Your Choice = ");
   scanf("%d",&c);
    system("cls");
   // clrscr();
   switch (c)
   {
     case 1:
      flight();
      break;
    case 2:
      hostel();
      break;
    default:
      printf("Enter Appropriate Choice\n");
   }
 } while(c>2);
}
  void flight()
  {
    FILE *f;
    showHeader();
    printf("  Select Booking Preffrence :-\n\n\n");
    printf("  1 - Flight Booking \n\n");
    printf("  2 - Check\n\n");
    printf("  3 - Cancel\n\n");
    printf("          Enter Choice = ");
    scanf("%d",&c);

    switch (c)
    {
      case 1:
      system("cls");
        flightBooking();
        break;
      case 2:
      system("cls");
        flightCheck();
        break;
      case 3:
      system("cls");
        flightCancel();
        break;
      default:
        printf("  Enter Appropriate Choice\n");
    }
  }
 void flightBooking()
 {
   time_t t;
   time(&t);
   FILE *f;
   struct flight f1;
   f = fopen("mmt.txt" , "rb");
   while(fread(&f1,sizeof(f1),1,f))
    seat++;
   if(seat >= fullseat)
   {
     printf("  Seat full\n");
     getch();
     exit (0);
   }
   fclose(f);
   char o[100],d[100];
   showHeader();
    system("cls");
    gotoxy(31,1);
    printf(" SRM Welcomes You to Flight Booking Gateway\n\n");
    showHeader();
    gotoxy(10,12);
    printf("Enter Origin = ");
    scanf("%s",f1.origin);
    // printf("\n");
    gotoxy(70,12);
    printf("Enter Destination = ");
    scanf("%s",f1.destination);
    gotoxy(10,14);
    printf("Enter Date Of Journey = ");
    scanf("%d",&f1.date);
    gotoxy(10,16);
    printf("Enter Month Of Journey = ");
    scanf("%d",&f1.month);
    gotoxy(10,18);
    printf("Enter Year Of Journey = ");
    scanf("%d",&f1.year);
    gotoxy(10,20);
    system("cls");
    showLoading("  Fetching flights");
    system("cls");
    showHeader();
    gotoxy(2,12);
    printf("  Enter passengers\n");
    gotoxy(2,14);
    printf("  Adults - ");
    scanf("%d",&f1.adult);
    //printf("\n");
    gotoxy(2,16);
    printf("  Children - ");
    scanf("%d",&f1.child);
    //printf("\n");
    gotoxy(2,18);
    printf("  Infants - ");
    scanf("%d",&f1.infant);
    printf("\n");
    system("cls");
    f1.price = 3000*f1.adult + 2000*f1.child + 1500*f1.infant;
    showHeader();
    gotoxy(2,12);
    printf("  Enter Reservation Clerk Name  = ");
    scanf("%s",f1.name);
    f1.id = 1000+seat+1;
    gotoxy(2,14);
    printf("  Total price of %d Passenger = Rs.%d\n\n  Press Enter to Confirm",f1.adult+f1.child+f1.infant,f1.price);
    getch();
    f = fopen("mmt.txt" , "ab+");
   fwrite(&f1,sizeof(f1),1,f);
   fclose(f);
   system("cls");
   showLoading("Loading");
   system("cls");
   showHeader();
   printf("\n\n  Booking confirmed!\n\n");
   printf("  Name - %s\n  Booking Id - %d\n  Date - %d/%d/%d\n  Origin - %s\n  Destination - %s\n  Passengers\n  Adults - %d\n  Children - %d\n  Infants - %d\n  Price paid - %d",f1.name,f1.id,f1.date,f1.month,f1.year,f1.origin,f1.destination,f1.adult,f1.child,f1.infant,f1.price);
   printf("\n\n  Please note your booking id !!\n");
   printf("Press Enter To Continue");
   getch();
   system("cls");
   showHeader();
   printf("%s\n",ctime(&t));
   printf("  Press 1 to Go To Main Page\n  Press 2 To Exit The Page\n\n");
   printf("       Enter Choice = ");
   int choice;
   scanf("%d",&choice);
   if(choice==1)
   {
    system("cls");
   main();
   }
   if(choice==2)
   {
     system("cls");
     showHeader();
     thankyou();
     getch();
   }
   getch();
   // main();
 }

void flightCheck()
{
  time_t t;
  time(&t);
  FILE *f;
  struct flight f1;
  int idCheck;
  showHeader();
  gotoxy(3,7);
  printf("  Enter Booking ID - ");
  scanf("%d",&idCheck);
  f = fopen("mmt.txt" , "rb+");
  system("cls");
  showLoading("Searching");
  system("cls");
  while(fread(&f1,sizeof(f1),1,f) && check)
  {
    if(idCheck == f1.id)
    {
      check = false;
      showHeader();
      printf("  Name - %s\n\n  Booking Id - %d\n  Date - %d/%d/%d\n  Origin - %s\n  Destination - %s\n  Passengers\n  Adults - %d\n  Children - %d\n  Infants - %d\n  Price paid - %d",f1.name,f1.id,f1.date,f1.month,f1.year,f1.origin,f1.destination,f1.adult,f1.child,f1.infant,f1.price);
      getch();
      system("cls");
      printf("%s\n",ctime(&t));
   printf("  Press 1 to Go To Main Page\n  Press 2 To Exit The Page\n\n");
   printf("       Enter Choice = ");
   int choice;
   scanf("%d",&choice);
   if(choice==1)
   {
    system("cls");
   main();
   }
   if(choice==2)
   {
     system("cls");
     showHeader();
     thankyou();
     getch();
   }
      break;
    }
  }
  gotoxy(2,5);
  if(check)
    showHeader();
    printf("  No such record found\n");
    fclose(f);
    getch();
    system("cls");
    main();
}

void flightCancel()
{
  FILE *f;
  check = true;
  struct flight f1;
  int bookId , refund;
  int ch ;
  int cc;
  showHeader();
  // showDots();
  printf("\n  1 - Instant refund ( 10 percent deduction )\n\n");
  printf("  2 - Wait for departure ( No deduction )\n\n");
  printf("  3 - Know more about 1 and 2\n\n");
  printf("  Enter a choice  -  ");
  scanf("%d",&cc);
  // clscr();
  system("cls");
  showHeader();
  gotoxy(5,8);
  printf("  Enter your booking id  -  ");
  scanf("%d",&bookId);
  system("cls");
  showLoading("Searching");
  system("cls");
  f = fopen("mmt.txt" , "rb");
  while(fread(&f1,sizeof(f1),1,f) && check)
  {
    if(bookId == f1.id)
    {
      check = false;
      break;
    }
  }
  if(check && cc!=2)
  {
    showHeader();
    gotoxy(3,15);
    printf("  No such record found\n");
    getch();
    system("cls");
    main();
  }
    fclose(f);
  // clscr();
  switch (cc)
  {
    case 1:
      refund = del(bookId,cc);
      showHeader();
      gotoxy(3,15);
      printf("  Successfully cancelled!!\n");
      gotoxy(3,17);
      printf("  Amount refunded = Rs. %d",refund-(refund*10/100));
      getch();
      system("cls");
      main();
      break;
    case 2:
      showHeader();
      printf("\n  1 - Create a full refund!!\n");
      printf("  2 - Collect Refund\n");
      printf("  Enter a choice  -  ");
      scanf("%d",&ch);
      system("cls");
      switch (ch)
      {
        case 1:
          showHeader();
          gotoxy(3,15);
          del(bookId,cc);
          printf("  Successfully created full return!!");
          getch();
          main();
          break;
        case 2:
          showHeader();
          gotoxy(3,15);
          f = fopen("mmt.txt" , "rb");
          seat = 0;
          while(fread(&f1,sizeof(f1),1,f))
            seat++;
          fclose(f);
          FILE *fref;
          struct flight ref;
          // search refund listt put in refund
          fref = fopen("refund.txt" , "rb");
          fseek(fref, 0, SEEK_END);
           if (ftell(fref) == 0){
             check = true;
           }
           fseek(fref, 0, SEEK_SET);
          while(fread(&ref,sizeof(ref),1,fref))
          {
            if(bookId == ref.id)
            {
              refund = ref.price;
              check = false;
              break;
            }
          }
          fclose(fref);
          if(check){
            printf("  Create a full time refund first\n");
            getch();
            system("cls");
            main();
          }
          if(seat == fullseat)
          {
            int refDel = 3;
            printf("  Full refund permitted  -  Rs.%d",refund);
            int empty =  del(bookId, refDel);
            getch();
            system("cls");
            main();
          }
          else{
            system("cls");
            showHeader();
            printf("  Wait for seat to be filled !!\n");
            getch();
            system("cls");
            main();
          }
          break;
      }
        break;
      case 3:
        printf("  Instant Refund - Instant refund with deducting 10 percent\n");
        printf("  Wait for departure - If all seats are booked at the time of full money will be refunded\n");
        printf("  If not you can take instant refund with 10-percent deduction\n");
        printf("  Press ENter to go back");
        getch();
        flightCancel();
        system("cls");
        break;
      default:
        printf("  Enter Appropriate Choice\n");
        break;
    }
}
int del(int id , int c)
{
  if(c == 1)
  {
    int retPrice;
    struct flight f1;
    FILE *f;
    FILE *fc;
    f = fopen("mmt.txt" , "rb");
    fc = fopen("mmtCopy.txt" , "ab+");
    while(fread(&f1,sizeof(f1),1,f))
    {
      if(id != f1.id){
        fwrite(&f1,sizeof(f1),1,fc);
      }
      else
      retPrice =  f1.price;
    }
    fclose(f);
    fclose(fc);
    remove("mmt.txt");
    rename("mmtCopy.txt" , "mmt.txt");
    return retPrice;
  }

  if(c == 2)
  {
  int retPrice;
  struct flight f1;
  FILE *f;
  FILE *fc , *refund;
  f = fopen("mmt.txt" , "rb");
  fc = fopen("mmtCopy.txt" , "ab+");
  refund = fopen("refund.txt" , "ab+");
  while(fread(&f1,sizeof(f1),1,f))
  {
    if(id != f1.id){
      fwrite(&f1,sizeof(f1),1,fc);
    }
    else{
      fwrite(&f1,sizeof(f1),1,refund);
      retPrice =  f1.price;
    }
  }
  fclose(f);
  fclose(fc);
  fclose(refund);
  remove("mmt.txt");
  rename("mmtCopy.txt" , "mmt.txt");
  return retPrice;
  }
  if(c == 3)
  {
    struct flight f1;
    FILE *f;
    FILE *fc;
    f = fopen("refund.txt" , "rb");
    fc = fopen("refundCopy.txt" , "ab+");
    while(fread(&f1,sizeof(f1),1,f))
    {
      if(id != f1.id){
        fwrite(&f1,sizeof(f1),1,fc);
      }
    }
    fclose(f);
    fclose(fc);
    remove("refund.txt");
    rename("refundCopy.txt" , "refund.txt");
    return 0;
  }
}
