/* TIC TAC TOE GAME */

#include <stdio.h>
#include <stdlib.h>
#include<WINDOWS.H>


char matrix[3][3]; 

void scan_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
  {
    for(j=0; j<3; j++)
				{
					 matrix[i][j] =  ' ' ;
					}
				}
}

void player_move(void)
{
  int x, y;
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 14);
  printf("\nEnter X,Y coordinates for your move: ");
  scanf("%d%*c%d", &x, &y);

  x--; y--;

  if(matrix[x][y]!= ' ')
		{
			 SetConsoleTextAttribute(hConsole, 14);
    printf("\n \nInvalid move, try again.\n \n");
    player_move();
  }
  else matrix[x][y] = 'X';
}

void computer_move(void)
{
  int i, j;
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  for(i=0; i<3; i++){
    for(j=0; j<3; j++)
      if(matrix[i][j]==' ') 
						break;
      if(matrix[i][j]==' ') 
				  break;
  }

  if(i*j==9)  
		{
		  SetConsoleTextAttribute(hConsole, 11);
    printf("\ndraw\n");
    exit(0);
  }
  else
    matrix[i][j] = 'O';
}

void display_matrix(void)
{
  int t;
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  for(t=0; t<3; t++)
		 {
			 SetConsoleTextAttribute(hConsole, 240);
    printf(" %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    if(t!=2)
     SetConsoleTextAttribute(hConsole, 240);
				 printf("\n---|---|---\n");
  }
  printf("\n");
}

char check(void)
{
  int i;

  for(i=0; i<3; i++) 
    if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2]) 
							return matrix[i][0];

  for(i=0; i<3; i++)
    if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
							 return matrix[0][i];

  if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
       return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
       return matrix[0][2];

  return ' ';
}


int main(void)
{
	HANDLE hConsole;
 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 {
	SetConsoleTextAttribute(hConsole, 11);
	
printf(" \n\t \t \t \t \t \t$$$$$$$$$$$$$$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$$  $$$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$    $$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$      $$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$        $$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$          $$$$$");
printf(" \n\t \t \t \t \t \t$$$$    TIC     $$$$");
printf(" \n\t \t \t \t \t \t$$$              $$$");
printf(" \n\t \t \t \t \t \t$$                $$");
printf(" \n\t \t \t \t \t \t$       TAC        $");
printf(" \n\t \t \t \t \t \t$$                $$");
printf(" \n\t \t \t \t \t \t$$$              $$$");
printf(" \n\t \t \t \t \t \t$$$$    TOE     $$$$");
printf(" \n\t \t \t \t \t \t$$$$$          $$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$        $$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$      $$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$    $$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$$ $$$$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$$$$$$$$$$$$$");
}
{
   SetConsoleTextAttribute(hConsole, 15);	
	
    int i, j, number_of_rows;
    char name[50];
    int length_of_name;

    printf("\n \nEnter your name please : ");
    gets(name);
 
    printf("\n \nEnter value of n : ");
    scanf("%d", &number_of_rows);

    length_of_name = strlen(name);

    
    for(i=number_of_rows/2; i<=number_of_rows; i+=2)
    {
        for(j=1; j<number_of_rows-i; j+=2)
        {
            printf(" ");
        }
 
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
 
        for(j=1; j<=number_of_rows-i; j++)
        {
            printf(" ");
        }
 
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
 
        printf("\n");
    }
 
   
    for(i=number_of_rows; i>=1; i--)
    {
        for(j=i; j<number_of_rows; j++)
        {
            printf(" ");
        }
        
        
        if(i == number_of_rows) 
        {
            for(j=1; j<=(number_of_rows * 2-length_of_name)/2; j++)
            {
                printf("*");
            }   

            printf("%s", name);

            for(j=1; j<(number_of_rows*2-length_of_name)/2; j++)
            {
                printf("*");
            }
        }
        else 
        {
            for(j=1; j<=(i*2)-1; j++)
            {
                printf("*");
            }
        }
 
        printf("\n");
								}
 
   
}
  char done;
  
  SetConsoleTextAttribute(hConsole, 14);
  printf("\n \nTic Tac Toe game.\n");
  printf("\nYou will be playing against the computer.\n");

  done =  ' ';
  scan_matrix();

  do {
    display_matrix();
    player_move();
    done = check(); 
    if(done!= ' ')
				 break; 
    computer_move();
    done = check(); 
  } while(done== ' ');

  if(done=='X')
  {
		SetConsoleTextAttribute(hConsole, 11); 
		printf("\n \nYOU WON!\n");
  }
		else
		{ 
  SetConsoleTextAttribute(hConsole, 11);
		printf("\n \nI WON!\n");
  display_matrix(); 
  }
  SetConsoleTextAttribute(hConsole, 15); 
  printf(" \n \n \n CREATED BY : \n" );
	printf(" \n -------------------------------\n ");
	printf("| HUSSAIN GHAZALI  | |17k-3900| \n | HASSAN SHAKEEL   | |17k-3857| \n | ZUHAIR WAHEED    | |17k-3706| \n | SHAYAN NOOR KHAN | |17k-3744|");
      printf(" \n ------------------------------- \n");
  return 0;
}



