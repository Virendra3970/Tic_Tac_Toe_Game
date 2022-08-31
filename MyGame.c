 /*
   This is a humble request to my teachers and elders and advice to my younger friends:-
   If you're a Linux user then this project is surely run on your system.
   And if you're a Windows user then Please change some codes which are given below
   1. Change system("clear") => system('cls')
   2. Change getchar() => getch();
   Thnaks A Lot of YOu to Pay attention on my project.
 */
 
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>

 //Dynamic Variavles and function prototypes
 char board[3][3];
 
 char winner;
 
 const char PLAYER ='X';            // Symbol for 1st player
 
 const char COMPUTER ='O';	     	// Symbol for Evil Computer and Computer
 
 const char PLAYER1 ='#';	   // Symbol for 2nd Player
 
 void printWinnerName(char );       	// Function to check who is winner b/w p1 and p2
 
 void resetBoard();		  // This functio is used to create Game Board
 
 void printBoard();		       //This function is used for print Board
 
 int checkFreeSpaces();		 // This funtion is used to count freepsaces means now how many turns are remainnig
 
 int playerMove();			//This function is used for moves of 1st Player
 
 void computerMove(); 		//This function is used for moves of Computer user
 
 char checkWinner();			//This function is used for check winner
 
 void printWinner(char);	// This function is used to print Winner
 
 void Rules();				//This function is used to print Game rules
 
 void secondPlayerMove();	//This function is used for Moves of 2nd Player
 
 void evilComputerMove();		//This function is used to print EvilComputer's move	

				// main funtion body starts
 int main()
 {
 
  int key;
 
  Rules();     // Rules function call
 
  printf("\n\n1. Play With Computer: \n");
 
  printf("2. Play with your friend: \n");
 
  printf("3. Play With Evil Computer: \n");
 
  printf("4. Exit: \n");   		//exit function call which is predefined function
 
  printf("\nEnter your choice: ");
 
  scanf("%d",&key);
 
  switch(key)				//Switch Case Body Starts
 {
// Case 1 Play With Computer
  case 1:
   winner=' ';
 
   resetBoard();    			 //resetBoard function call
 
  while(winner==' ' && checkFreeSpaces()!=0) 	 //checkFreeSpaces function call
  {
   printBoard();			  // printBoard function call
 
   playerMove(); 			 //playerMove function call
 
   winner=checkWinner(); 		  //function call
 
   if(winner!= ' ' || checkFreeSpaces()==0)   
 
      break;
 
   printBoard();
 
   computerMove();
 
   winner=checkWinner();
 
   if(winner!= ' ' || checkFreeSpaces()==0)
 
      break;
  }
 
  printBoard();
 
  printWinnerName(winner);
 
  break;

//Case 2 play with your friend
 case 2:
   winner=' ';
 
   resetBoard();
 
   while(winner==' ' && checkFreeSpaces()!= 0)
  {
    printBoard();

    printf("\n1st Player Turn");

    playerMove();

    winner=checkWinner();

    if(winner != ' ' && checkFreeSpaces() == 0)
      break;

    printBoard();

    printf("\n2nd Player Turn");

    secondPlayerMove();

    winner=checkWinner();

    if(winner != ' ' && checkFreeSpaces() == 0)
      break;
    }

    printBoard();

    printWinner(winner);
    break;


// Case 3 Play with Evil Computer
  case 3:
     winner=' ';

    resetBoard();

  while(winner==' ' && checkFreeSpaces()!=0)
  {
   printBoard();

   playerMove();

   winner=checkWinner();

   if(winner!= ' ' || checkFreeSpaces()==0)
      break;

   printBoard();

   evilComputerMove();

   winner=checkWinner();

   if(winner!= ' ' || checkFreeSpaces()==0)
      break;
  }
  printBoard();

  printWinner(winner);
  break;


//Case 4 to exit from the program
  case 4: 
      exit(0);

  default:
    printf("\nEnter a valid choice.");
}                                                                      //Switch Case Body Closed
return 0;								
}								       //main function body closed
 

// resetBoard Function starts
void resetBoard()
 {
  int i,j;

  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
     board[i][j]= ' ';
  }
}									//resetBoard function closed


//printBoard function starts 
 void printBoard()
 {
  system("clear");
  
  printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
  printf("\n");
 
 }								  //printBoard Function closed


// checkFreeSpaces function starts
 int checkFreeSpaces()
 {

  int i,j,freeSpaces=9;

  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
   {
    if(board[i][j]!=' ')
      freeSpaces--;
   }
  }
  
  return freeSpaces;
 }							  // checkFreeSpaces function closed
 

// 1st PlayerMove function starts 
 int playerMove()
 {
  int x,y;

  do
  {
   printf("\nEnter row #(1-3): ");
   
   scanf("%d",&x);
   
   x--;
   
   printf("\nEnter column #(1-3): ");
   
   scanf("%d",&y);
   
   y--;
   
   if(board[x][y]!=' ')
     printf("\nInvalid Move");
   
   else
   {
    board[x][y]=PLAYER;
    break;
   }
  
  }while(board[x][y]!= ' ');
 }							//1st PlayerMove function closed

// ComputerMove function starts
void computerMove()
{
 int x,y;
 
 srand(time(0));
 
 if(checkFreeSpaces>0)
 {
  do
  {
   x=rand()%3;
   y=rand()%3;
  }while(board[x][y]!= ' ');
 
  board[x][y]=COMPUTER;
 }
 
 else
    printWinner(' ');
}						 //ComputerMove function closed


//checkWinner funtion starts
char checkWinner()
{
 int i,j;

 for(i=0;i<3;i++)
 {
  if(board[i][0]==board[i][1] && board[i][0]==board[i][2]) 
     return board[i][0];
 }
 
 for(i=0;i<3;i++)
 {
  if(board[0][i]==board[1][i] && board[0][i]==board[2][i]) 
     return board[0][i];
 }
 
 if(board[0][0]==board[1][1] && board[0][0]==board[2][2]) 
     return board[0][0];
 
 else if(board[0][2]==board[1][1] && board[0][2]==board[2][0]) 
     return board[0][2];
 
 return ' ';
}							//CheckWinner function body closed

//printWinner function starts
void printWinner(char winner)
{
 if(winner==PLAYER)
   printf("\n You Won !! \n");
 
 else if(winner==COMPUTER)
   printf("\n You Lose !!  \n");   
 
 else
   printf("\nGame Tie \n!!");
}							//printWinner function body closed

//printWinnerName function starts
void printWinnerName(char winner)
{
 if(winner==PLAYER)
   printf("\n 1st Player Win !! \n");
 
 else if(winner==PLAYER1)
   printf("\n 2nd Player Win !!  \n");
 
 else
   printf("\nGame Tie \n!!");
}							//printWinnerName function body closed

//Rules of the game function starts
void Rules()
{
 printf("\n\t###########\t\"Tic-Tac-Toe Game\"\t##########");

 printf("\n\n              Rules Of The Game          ");

 printf("\n1. Player\'s move will be represented by \'X\'\n");

 printf("\n2. Computer\'s and Evil Computer\'s  move will be represented by \'O\'\n");

 printf("\n3. 2nd Player\'s move is reprensented by \'#\'\n");

 printf("\n4. If Player wants to give his move then \n He has to follow this patturn: \n");

  printf(" 11 | 12 | 13 ");
  printf("\n----|----|----\n");
  printf(" 21 | 22 | 23 ");
  printf("\n----|----|----\n");
  printf(" 31 | 32 | 33 ");
  printf("\n");

  printf("\n5. Player will find row number and colunm number to move his turn\n  ");

  printf("\nFor Example: \n");

  printf("\nEnter row #(1-3): 1\n");

  printf("\nEnter Column #(1-3): 1\n\n");

  printf("  X  | 12 | 13  ");
  printf("\n-----|----|----\n");
  printf("  21 | 22 | 23  ");
  printf("\n-----|----|----\n");
  printf("  31 | O  | 33  ");
  printf("\n");

  printf("\nHappy Gaming, Best Of Luck");
  printf("\n\n");
}								//Rules of the game function body closed

//secondPlayerMove function starts
void secondPlayerMove()
{
 int m,n;

 do 
 {
  printf("\nEnter row #(1-3): ");

  scanf("%d",&m);

  m--;  //Since board indeces #(0-2)

  printf("\nEnter column #(1-3): ");

  scanf("%d",&n);

  n--;  //Since board indeces #(0-2)

  if(board[m][n] != ' ')           //if in this move, space is not empty then print this message
     printf("\n Invalid Move !! ");
  else
  {
   board[m][n]=PLAYER1;		//otherwise, assign # in that place
   break;
  }
 
 
 }while(board[m][n] != ' ');	//check condition that space is not empty 
}								//secondPlayerMove function body closed


//Evil Function body starts
void evilComputerMove()
{
 int x,y,i,j;
       
 srand(time(0));
 
 if(checkFreeSpaces>0)
 {
  do
  {
   x=rand()%3;
   y=rand()%3;
  }while(board[x][y]!= ' ');
 
  board[x][y]=COMPUTER;
 }
 
 else
 {
  for(i=0;i<3;i++)
   {
    if(board[i][0]== board[i][1])
       board[i][2]=COMPUTER;
   }
   
   
   for(i=0;i<3;i++)
   {
    if(board[0][i]== board[1][i])
      board[2][i]=COMPUTER;
   }
 
 if(board[0][0]==board[2][2]) 
      board[1][1]=COMPUTER;
 
  if(board[1][1]==board[2][2]) 
      board[0][0]=COMPUTER;
 
 if(board[0][2]==board[1][1])
    board[2][0]=COMPUTER; 
 
 if(board[1][1]==board[2][0])
      board[0][2]=COMPUTER;  
 
 if(board[0][2]==board[2][0])
       board[1][1]=COMPUTER;
    printWinner(' ');
 }

}



