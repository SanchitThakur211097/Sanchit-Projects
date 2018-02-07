#include<math.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
//#include<graphics.h>
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
void load();
void board();
int checkwin();
int leap(int n);
int find(int dd,int mm,int yy,int c);
int main()
{
	
	//system ("color 9f");
	
	char ch[100];
	int f1=-1;
	int player=1,choice;
	char mark;
int dd,mm,yy,x,a,b,f,i,j,sum=0,count=0;
	printf("\n\t\t\t   INTEGRATED PROJECT-II\n\n");
	printf("\n\t\t\tWELCOME IN TIC TAC TOE GAME");
		printf("\t\t\t\t\n");
		printf("\t\t\t-------*--*---*---*---*----");
		printf("\n\t\t\t\t");
		//clrscr();
   scanf("%d",&dd);
  
scanf("%d",&mm);

scanf("%d",&yy);

    x=leap(yy);
    a=find(dd,mm,yy,x);
   
    while(f1!=0)
    {                
	 printf("Enter Password-");
    scanf("%s",ch);
    for(i=0;ch[i]!='\0';i++)
    {
    	if(ch[0]=='I')
    	{
    		f1=1;
		}
		else
		{
		
		f1=-1;
		break;
	    }
		if(ch[1]=='P')
		{
			f1=1;
		}
			else
		{
		
		f1=-1;
		break;
	    }
		if(ch[2]=='2')
		{
			f1=1;
		}
			else
		{
		
		f1=-1;
		break;
	    }
	}
	if(f1==-1)
	{
		printf("\t\t\t\tincorrect password!!!!!\n\n\t\t\t\tPlease try again\n\n\t\t\t\t");
		count++;
		if(count==2)
		{
			printf("\n\t\t\tNOTE:last warning***\n");
		}
		if(count>2)
		{
			break;
		}
	     f1=-1;
	}
	else
	break;
}

if(count==3)
{
printf("\n\t\t__________________________________________________");	
printf("\n\t\t|Sorry!!you are no longer participant in this game|");
printf("\n\t\t__________________________________________________");
getch();
}
else
{

	
		    load();
		    	printf("\n\n\n\n\n\t\t\tPLAYER-1(X)  -  PLAYER-2(O)  \n\n\n");
	printf("*********************--Press any key to start the game--************************\n\n\n\n\n");
	getch();
		    do
		    {
			
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);
    
    
    if (i == 1)
    {
	
         board();
        printf("==>\aPlayer %d win \n", --player);}
    else
        printf("==>\aGame draw");

    getch();
			}
		    
		   printf("\n\t\t\t\t\t\-made by ----");
		   printf("\n\t\t\t\t\t\t\-Anup Yadav (1511981348)");
		   printf("\n\t\t\t\t\t   \t\-Akshit Bassi (1511981365)");
		   printf("\n\t\t\t\t\t\t\-Sanchit Thakur (1511981332)");
		   getch();
		   return 0;
		   }
	

void load()
{
    int i,j;
    printf("\n\n\n\n\n\t\t\t\t");
    printf("loading...");
    printf("\n\t\t\t  ");
    for(i=1;i<=22;i++){
    for(j=0;j<=100000000;j++);
    printf("%c",219);}
    //printf("\n\t\t\t     Press enter....");

}
void board()
{

	//printf("\t\t\t\t");
	printf("\t\t\t\t     |     |     \n");
    printf("\t\t\t\t  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t     |     |     \n");

    printf("\t\t\t\t  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t     |     |     \n");

    printf("\t\t\t\t  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("\t\t\t\t     |     |     \n\n");
	
}
int leap(int yy)
{
    int flag=0;
    if((yy%100)==0)
    {
        if((yy%400)==0)
        {
         flag=1;
        }
    }
    else
    {
        if((yy%4)==0)
        {
            flag=1;
        }
    }
    if(flag==1)
    return 1;
    else
    return 0;
}
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}
int find(int dd,int mm,int yy,int c)
{
        int a[13],b[4],x,y,z,w,i,result;
        a[0]=0,a[1]=1,a[2]=4,a[3]=4,a[4]=0,a[5]=2,a[6]=5,a[7]=0,a[8]=3,a[9]=6,a[10]=1,a[11]=4,a[12]=6;
        b[0]=4,b[1]=2,b[2]=0,b[4]=6;
        x=yy%100;
        y=x/4;
        z=y+dd;
        for(i=0;i<13;i++)
        {
                if(mm==i)
                {
                        z=z+a[i];
                }
        }
        if(c==1)
        {
        if(mm==1||mm==2)
                z=z-1;
        }
        w=yy/100;
        if((w%4)==0)
        {
                z=z+6;
        }
        else if ((w%4)==1)
        {
                z=z+4;
        }
        else if((w%4)==2)
        {
                z=z+2;
        }
        else if((w%4)==3)
        {
                z=z+0;
        }
        z=z+x;
        result=z%7;
        switch(result){
                case 0: printf("\t\t\t\tSATURDAY");
            break;
        case 1:
            printf("\t\t\t\tSUNDAY");
            break;
        case 2: 
        printf("\t\t\t\tMONDAY");
            break;
        case 3:
           printf("\t\t\t\tTUESDAY");
            break;
        case 4: 
         printf("\t\t\t\tWEDNESDAY");
            break;
        case 5: printf("\t\t\t\tTHURSDAY");
            break;
        case 6: printf("\t\t\t\tFRIDAY");
            break;
   }
   printf("\n");
   printf("\n\t\t\t\t");
   return result;
}

