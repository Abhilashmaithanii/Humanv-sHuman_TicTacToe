#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char A[9];// character array for board
char player1[20],player2[20], sign;
char p1,p2;

void names(); // Function to enter name and decide who plays first
int winner();// Function which decide winner of game

int main()
{
      int index;
          int p, i,j;


            printf("tik tac toe");
    printf("\n\n");
    printf("\t\t\t    |    |     \n");
    printf("\t\t\t----+----+----\n");
    printf("\t\t\t    |    |     \n");
    printf("\t\t\t----+----+---\n");
    printf("\t\t\t    |    |     \n");


    names();


    for(i=0; i<9; i++) {

        if(i%2==0) {
            p=1;
            sign=p1;
        }
        else
        {   p=2;
            sign=p2;
        }



NX:     if(sign=='O')
       {
        printf("%s enter the move(1-9)  :",player1);
        scanf("%d",&index);
       }
       else
       {printf("%s enter the move(1-9)  :",player2);
        scanf("%d",&index);}

    if(index<1||index>9)
        {   printf("invalid move\n");
            goto NX;
        }

    if(A[index-1]=='O'||A[index-1]=='X')
    {
        printf("Position already taken\n");
        goto NX;
    }
    for(j=0; j<9; j++) {
        if(A[j]!='O'&&A[j]!='X')
            A[j]=' ';
    }

    A[index-1]=sign;

    system("cls");
    printf("tik tack toe");
    printf("\n\n");
    printf("\t\t\t  %c | %c  | %c  \n", A[0], A[1], A[2]);
    printf("\t\t\t----+----+----\n");
    printf("\t\t\t  %c | %c  | %c  \n", A[3], A[4], A[5]);
    printf("\t\t\t----+----+---\n");
    printf("\t\t\t  %c | %c  | %c  \n", A[6], A[7], A[8]);


    winner();


    }

    return 0;
}

int winner()
{
    int k,l,m,flag=0,win=0;

          for(k=0; k<9; k++) {
        if(k%3==0)
            flag=0;

        if(A[k]==sign)
            flag++;

        if(flag == 3) {
           win=1;
           goto D;
        }
    }

    flag = 0;
    for(l=0;l<3;l++) {
        for(m=l;m<=l+6;m=m+3) {
            if(A[m]==sign)
                flag++;
        }
        if(flag==3) {
            win=1;
           goto D;
        }
        flag=0;
    }
    if((A[0]==sign&&A[4]==sign&&A[8]==sign) ||
            (A[2]==sign&&A[4]==sign&&A[6]==sign))
           {
        win= 1;
        goto D;
    }
    else
        return 0;
D:
    if(win!=0)
       {
        if(sign=='O')
           printf("%s is winner!!!",player1);
       else
        printf("%s is winner!!! ",player2);

       exit(1);
       }

    else
        printf("Match draw!!!");

    return 0;
}

void names()
{   char name[20];
    printf("Enter Name of Player :  O  :");
    gets(player1);
    printf("Enter Name of Player :  X  :");
    gets(player2);
    printf("\n\n");
    printf("Enter name of Player who is willing to play first Move :\n");
Re:    gets(name);
    if(strcmp(name,player1)==0)
    {p1='O';
    p2='X';
    }
    else if(strcmp(name,player2)==0)
         {p1='X';
    p2='O';
    }
    else
    {
        printf("Invalid Input\n");
        printf("Enter again  :  ");
        goto Re;
    }
    system("cls");
}
