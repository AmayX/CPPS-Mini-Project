#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define X 15
#define Y 15
char RealMap[X][Y], GameMap[X][Y];
int G=0,mines=20;

int menu()
{
printf("Welcome to Minesweeper!\n");
 printf("*************************\n");
 printf("****** 1.play ******\n");
 printf("****** 0.exit ******\n");
 printf("*************************\n");
 printf(" Please select a choice:");
 int choice = 0;
 scanf("%d", &choice);
 return choice;
}

/*void SetDifficulty() //do this later
{
  int d=1;
  Ask:printf("Select Difficulty: \n");
  printf("1. Easy (10x10 grid, 10 mines) \n");
  printf("2. Medium (15x15 grid, 20 mines) \n");
  printf("3. Hard (20x20 grid, 30 mines) \n");
  scanf("%d",&d);
  if (d>3||d<1)
  {
    printf("Invalid choice. Please re-Enter");
    goto Ask;
  }
  switch(d)
  {
    case 1: X=10; Y=10; mines=10; break;
    case 2: X=15; Y=15; mines=20; break;
    case 3: X=20; Y=20; mines=30; break;
    default: X=15; Y=15; mines=10; break;
  }
}*/

int randInt()
{
  int num;
  num=rand()%15;
  return num;
}

void initialize(char a[X][Y])
{
  int i,j;
  for (i=0;i<X;i++) //initialization
  {
    for (j=0;j<Y;j++)
    {
      a[i][j]='*';
    }
  }
}

void Place_Mine()
{
  int i,j,minex,miney;
  for (i=0;i<mines;i++)
  {
    minex=randInt();
    miney=randInt();
    RealMap[minex][miney]='1';
  }
}

char green(char t)
{
  printf("\033[0;32m");
  printf("\033[0m");
}

void UpdateMap(char GameMap[X][Y], char RealMap[X][Y], int i, int j) {
  int count = 0;
 if (i - 1 >= 0 && j - 1 >= 0 && RealMap[i - 1][j - 1] == '1')
 {
 count++;
 }
 if (i - 1 >= 0 && RealMap[i - 1][j] == '1')
 {
 count++;
 }
 if (i - 1 >= 0 && j + 1 < Y && RealMap[i - 1][j + 1] == '1')
 {
 count++;
 }
 if (j - 1 >= 0 && RealMap[i][j - 1] == '1')
 {
 count++;
 }
 if (j + 1 < Y && RealMap[i][j + 1] == '1')
 {
 count++;
 }
 if (i + 1 < X && j - 1 >= 0 && RealMap[i + 1][j - 1] == '1')
 {
 count++;
 }
 if (i + 1 < X && RealMap[i + 1][j] == '1')
 {
 count++;
 }
 if (i + 1 < X && j + 1 < Y && RealMap[i + 1][j + 1] == '1')
 {
 count++;
 }
 GameMap[i][j] = count + '0';
 /*if (GameMap[i][j]=='0')
 {
   GameMap[i][j]==green(GameMap[i][j]);
 }*/ //do this later
}

void ShowMap(char Map[X][Y])
{
  for (int t=0;t<=X;t++)
  {
    if (t==0)
    {
      printf("X |");
      continue;
    }
    if (t<10)
    {
      printf("%d  ",t);
    }
    else
    {
      printf("%d ",t);
    }
  }
printf("\n");
for (int k=0;k<47;k++)
{
  printf("-");
}
printf("\n");
for (int i = 0; i < X; i++)
{
if (i<9)
{
  printf(" %d",i+1);
}
else
{
  printf("%d",i+1);
}
printf("|");
for (int j = 0; j < X; j++)
{
printf(" %c ", Map[i][j]);
}
printf("\n");
}
}

void StartGame() {
  int i,j,blank_count=0;
  do {
  ShowMap(GameMap);
  printf("Enter coordinates: ");
  scanf("%d %d",&j,&i);
  i-=1;
  j-=1;
  if (i<0||i>X||j<0||j>Y)
  {
    printf("Invalid Choice! Please re-enter!\n");
    continue;
  }
  if (GameMap[i][j]!='*')
  {
    printf("The coordinates are already occupied! Please re-enter!\n");
    continue;
  }
  if (RealMap[i][j]=='1')
  {
    ShowMap(RealMap);
    printf("Game Over!\n");
    G=1;
    break;
  }
  blank_count++;
  if (blank_count == X * Y - 10)
 {
 printf("Congratulations, mine clearance is a success!\n");
 break;
 }
UpdateMap(GameMap,RealMap,i,j);
system("cls");
}while(1);
}

int main(void)
{
  int i,j;
  srand(time(0));
  initialize(RealMap);
  initialize(GameMap);
  Place_Mine();
  //ShowMap(RealMap);
  int choice=menu();
  //SetDifficulty();
  switch (choice) {
    case 0: printf("Thanks for playing!\n");
    break;
    case 1: for(;;) {
      StartGame();
      if (G==1)
      {
        exit(0);
      }
    }
    break;
  }
  return 0;
}
