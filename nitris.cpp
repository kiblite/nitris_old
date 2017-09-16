// header files
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "formatted_console_io_v20.h"

using namespace std;
// global constants

	////GABBY////

	//display constants
	const int WHITE_MIN_X = 18;
	const int WHITE_MIN_Y = 2;
	const int WHITE_MAX_X = 61;
	const int WHITE_MAX_Y = 21;
	
	const int TITLE_N_X = 8;
	const int TITLE_I_X = 21;
	const int TITLE_T_X = 32;
	const int TITLE_R_X = 45;
	const int TITLE_I2_X = 55;
	const int TITLE_S_X = 63;
	const int TITLE_Y = 7;
	
	const int MENU_X = 22;
	const int MENU_Y = 3;
	
	const int END_MIN_X = 10;
	const int END_MIN_Y = 5;
	const int END_MAX_X = 69;
	const int END_MAX_Y = 18;


	////ANDY////

	//chars for char arrays 
  const char NULL_CHAR = '\0';
  const char ENDLINE_CHAR = '\n';
  const char COMMA = ',';
  const char COLON = ':';

  //window size for menus
  const int DISPLAYSCORE_MIN_X = 12;
  const int DISPLAYSCORE_MIN_Y = 1;
  const int DISPLAYSCORE_MAX_X = 68;
  const int DISPLAYSCORE_MAX_Y = 22;

  const int SAVESCORE_MIN_X = 10;
  const int SAVESCORE_MIN_Y = 6;
  const int SAVESCORE_MAX_X = 70;
  const int SAVESCORE_MAX_Y = 18;


  //constant menu title position and list header position
  const int TITLE_X = 40;
  const int ANDY_TITLE_Y = 2;
  const int HDR_SCR_X = 15;
  const int HDR_SCR_Y = 6;

  //array lengths and double precision
  const int MAX_SCORES = 11;

  const int PRECISION = 2;

  const int MAX_STR_LEN = 80;


	////KEVIN////

	// game arena constants
	const int MAX_ROW_LEN = 20;
	const int MAX_COL_LEN = 37;
	const int GAME_MIN_X = 21;
	const int GAME_MIN_Y = 0;
	const int MAX_SPAWN_RANGE = 34;
	const int SCORE_X = GAME_MIN_X + MAX_COL_LEN + 4;
	const int SCORE_Y = MAX_ROW_LEN + 2;
	const int LOGO_X = 6;
	const int LOGO_Y = 6;
	const int TEST_ROW = 2;
	
	// difficulty constants
	const int MODERATE = 1;
	
	// gameplay constants
	const char NO_MOVE = '\0';
	const int BLOCK_WIDTH = 3;
	const int BLOCK_HEIGHT = 2;
	
// function prototypes

/*
Name: drawBackGround
Process: draws the background
Function Input/Parameters: beginning x/y coords (int), ending x/y coords (int)
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: outputs a blue background and white foreground
Dependencies: curses, formatted_console_io_v20.h
Developer: Gabby Kobany
*/
void drawBackGround();

/*
Name: loadTitle
Process: Displays fancy title to the user.
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output / Monitor: title sent to monitor 
Dependencies: curses, formatted_console_io_v20.h
Developer: Gabby Kobany
*/
void loadTitle();

/*
Name: loadMainMenu
Process: Displays main menu to the user.
Function Input/Parameters: difficulty setting
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output / Monitor: Main menu displayed. 
Dependencies: curses, formatted_console_io_v20.h
Developer: Gabby Kobany
*/
void loadMainMenu(int difficulty);

/*
Name: deployUserChoice
Process: gets a input from user, and deploys the corresponding function
Function Input/Parameters: difficulty
Function Output/Parameters: none
Function Output/Returned: none
Device Input / Keyboard: requires user input
Device Output / Monitor: outputs prompt to the user 
Dependencies: curses, formatted_console_io_v20.h
Developer: Gabby Kobany
*/
void deployUserChoice(int difficulty);

/*
Name: loadDifficultyScreen
Process: displays the score screen, gets difficulty from user
Function Input/Parameters: none
Function Output/Parameters: difficulty variable (int)
Function Output/Returned: none
Device Input / Keyboard: gets difficulty input from user 
Device Output / Monitor: displays screen for difficulty options 
Dependencies: curses, formatted_console_io_v20.h
Developer: Gabby Kobany 
*/
void loadDifficultyScreen(int &difficulty);

/*
Name: loadInstructions
Process: displays the instructions screen
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: user input to continue
Device Output: none
Dependencies: curses, formatted_console_io_v20.h
Developer: Gabby Kobany
*/
void loadInstructions();

/*
Name: loadGameUI
Process: draws the basic game interface according to difficulty
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output / Monitor: displays game UI 
Dependencies: curses, formatted_console_io_v20.h
Developer: Kevin Boles
*/
void loadGameUI();

/*
Name: loadScoreScreen
Process: prints previous play and score data
Function Input/Parameters: arrays: scores, plays, and names
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none 
Device Output / Monitor: Displays all past game data 
Dependencies: curses, formatted_console_io_v20.h, cstring
Developer: Andy Narvaez Nunez
*/
void loadScoreScreen( int scores[], int plays[], char names[][ MAX_COL_LEN ] );

/*
Name: loadScoreData
Process: loads score data from file into arrays
Function Input/Parameters: arrays size, arrays: scores, plays, and names
Function Output/Parameters: array size
Function Output/Returned: none
Device Input: file with score data
Device Output: none
Dependencies: fstream
Developer: Andy Narvaez Nunez
*/
void loadScoreData( int playerScore[], int playerPlay[], 
                                  char nameChars[][ MAX_COL_LEN ], int &size );
/*
Name: saveScoreData
Process: prompts player for name. Saves the name, score, and plays of user in a
        score file, sorted by win rate
Function Input/Parameters: arraySize, arrays: score, plays, name
Function Output/Parameters: array size
Function Output/Returned: none
Device Input: score file
Device Output: prompt for player name
Dependencies: fstream, formatted console, cstring
Developer: Andy Narvaez Nunez
*/
void saveScoreData(  int scores[], int plays[], char names[][ MAX_COL_LEN ], 
                                               int currScore, int currPlays  );

/*
Name: sortArray
Process: sorts array starting with the largest value
Function Input/Parameters: array size, arrays: scores, plays, names
Function Output/Parameters: sorted array
Function Output/Returned: none
Device Input: none
Device Output: none
Dependencies: cstring, fstream
Developer: Andy Narvaez Nunez
*/
void sortArray( int arrScores[], int arrPlays[], char arrNames[][ MAX_COL_LEN ],
                                                                    int size );

/*
Name: loadGameData
Process: loads game data into array
Function Input/Parameters: game array, score, plays, difficulty
Function Output/Parameters: 
Function Output/Returned: 
Device Input: saved game file
Device Output: none
Dependencies: fstream, cstring
Developer: Andy Narvaez Nunez
*/
void loadGameData( char gameArr[][ MAX_COL_LEN ], int &playerScore, 
                                       int &playerPlay, int &difficultyLevel );

/*
Name: loadNewGame
Process: loads new game for player
Function Input/Parameters: game array and difficulty level
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: none
Dependencies: formatted console
Developer: Andy Narvaez Nunez
*/
void loadNewGame( char gameArr[][ MAX_COL_LEN ], int diffLevel );

/*
Name: loadSavedGame
Process: loads previously saved game
Function Input/Parameters: game array, difficulty, score, and plays
Function Output/Parameters: new difficulty, new scores, new plays
Function Output/Returned: none
Device Input: previous game save file
Device Output: none
Dependencies: fstream, cstring, none
Developer: Andy Narvaez Nunez
*/
void loadSavedGame( char gameArr[][ MAX_COL_LEN ], int &difficulty, int &score, 
                                                                  int &plays );

/*
Name: saveGameData
Process: saves current game data
Function Input/Parameters: game array, difficulty, scores, plays
Function Output/Parameters: none
Function Output/Returned: none
Device Input: save file
Device Output: none
Dependencies: fstream
Developer: Andy Narvaez Nunez
*/
void saveGameData( char gameArr[][ MAX_COL_LEN ], int &difficulty, int &score,
                                                                  int &plays );

/*
Name: saveGameData
Process: 
Function Input/Parameters: 
Function Output/Parameters: 
Function Output/Returned: 
Device Input:
Device Output: 
Dependencies:
Developer: Andy Navarez
*/
void initializeGameArray( char dataArray[][ MAX_COL_LEN ] );

/*
Name: playGame
Process: main gameplay loop; creates functional gameplay arena on the screen
Function Input/Parameters: none (EC: difficulty modifier (int))
Function Output/Parameters: none
Function Output/Returned: none
Device Input / Keyboard: gets user keypresses to control the game
Device Output / Monitor: displays the game arena and action to the user via
					     monitor 
Dependencies:curses, formatted_console_io_v20.h, cstdlib
Developer: Kevin Boles
*/
void playGame(char gameArray[][ MAX_COL_LEN ], int difficulty, int scoreCount, int playCount);

/*
Name: getBlockStatus
Process: gets a random character for the block to user
Function Input/Parameters: none
Function Output/Parameters: blockStatus (char)
Function Output/Returned: none
Device Input: none
Device Output: none
Dependencies: cstdlib
Developer: Kevin Boles
*/
void getBlockStatus(char &blockStatus);

/*
Name:spawnBlock
Process: creates a 3x2 brick of characters in an array
Function Input/Parameters: starting x/y coordinates (int), 
						   value for insertion (char), 2-D array (char)
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: none
Dependencies: none
Developer: Kevin Boles
*/
void spawnBlock(int xLoc, int yLoc, char blockStatus, char gameArr[][MAX_COL_LEN]);

/*
Name: printArray()
Process: starting from an x/y coord, takes a array value and visually represents
		 it on the screen.
Function Input/Parameters: 2D character array
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output / Monitor: displays the array on the screen  
Dependencies: curses, formatted_console_io_v20.h
Developer: Kevin Boles
*/
void printArray(int xLoc, int yLoc, char gameArr[][MAX_COL_LEN]);

/*
Name: charToColor()
Process: takes a character value, and uses setColor depending on the char value
Function Input/Parameters: character value
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: none
Dependencies: curses, formatted_console_io_v20.h
Developer: Kevin Boles
*/
void charToColor(char testChar);

/*
Name: moveBlock()
Process: waits for user input (or lack thereof), replaces the current block
		 with empty characters, changes the block's x/y spawning coords, then
		 spawns a new block at the new coords, assuming no collision has 
		 occurred.
Function Input/Parameters: 2D character array (char), blockStaus (char)
Function Output/Parameters: x and y reference values (&int), 
							couldMove (bool)
Function Output/Returned: none
Device Input / Keyboard: gets user input for movement
Device Output: none
Dependencies: none
Developer: Kevin Boles
*/
void moveBlock(int &xLoc, int &yLoc, char blockStatus,  char gameArr[][MAX_COL_LEN], bool &couldMove, int userMove);

/*
Name: collisionDetected
Process: checks for non-empty spaces around a point in an array, returns a bool value
Function Input/Parameters: x and y position, user input constant
Function Output/Parameters: none
Function Output/Returned: bool
Device Input: none
Device Output: none 
Dependencies: none
Developer: Kevin Boles
*/
bool collisionDetected(int xPos, int yPos, int userInput, char gameArr[][MAX_COL_LEN]);

/*
Name: pauseGame
Process: pauses the game for the user, presents options
Function Input/Parameters: score, plays, character array
Function Output/Parameters: none
Function Output/Returned: none
Device Input / Keyboard: gets input from the user to leave the screen or other
						 options
Device Output / Monitor: Displays pause information at the bottom of the screen
Dependencies: curses, formatted_console_io_v20.h
Developer: Kevin Boles
*/
void pauseGame(char gameArr[][ MAX_COL_LEN ], int &difficulty, int &score, 
                                                                   int &plays);

/*
Name: checkArray
Process: checks the array for point-giving conditions and increments the score
Function Input/Parameters: 2D char array
Function Output/Parameters: returned score
Function Output/Returned: none
Device Input: none
Device Output: none
Dependencies: curses, formatted_console_io_v20.h
Developer: Gabby Kobany
*/
void checkArray(int score, char gameArr[][MAX_COL_LEN]);


// main function
int main()
{
//initialize program
	srand(time(NULL));
	
	// start curses
		// function: startCurses()
	startCurses();
	
	// display title screen
		// function: loadTitle()
	loadTitle();
	
	// load user interface
		// function: loadMainMenu()
	loadMainMenu(MODERATE);

// end program
		
	// stop curses
		// function: endCurses()
	endCurses();
	
	// return 0
	return 0;
}

// supporting function implementation
void drawBackGround()
{
int xOff, yOff;

for (xOff=0; xOff < SCRN_MAX_X; xOff+=18 )
{
for ( yOff=0; yOff < SCRN_MAX_Y; yOff+=4)
{
setColor (COLOR_WHITE, COLOR_RED, "BRIGHT");
clearScreen ( 0+xOff, 0 + yOff, 2+xOff, 1+yOff);
setColor (COLOR_WHITE, COLOR_CYAN, "BRIGHT");
clearScreen (0+xOff, 2+yOff, 2+xOff, 3+yOff);
}
setColor (COLOR_WHITE, COLOR_RED, "BRIGHT");
clearScreen (0+xOff, 0+yOff, 2+xOff, 1+yOff);
}

for (xOff=0; xOff < SCRN_MAX_X; xOff+=18 )
{
for ( yOff=0; yOff < SCRN_MAX_Y; yOff+=4)
{
setColor (COLOR_WHITE, COLOR_BLUE, "BRIGHT");
clearScreen ( 3+xOff, 0 + yOff, 5+xOff, 1+yOff);
setColor (COLOR_WHITE, COLOR_MAGENTA, "BRIGHT");
clearScreen (3+xOff, 2+yOff, 5+xOff, 3+yOff);
}
setColor (COLOR_WHITE, COLOR_BLUE, "BRIGHT");
clearScreen (3+xOff, 0+yOff, 5+xOff, 1+yOff);
}

for (xOff=0; xOff < SCRN_MAX_X; xOff+=18 )
{
for ( yOff=0; yOff < SCRN_MAX_Y; yOff+=4)
{
setColor (COLOR_WHITE, COLOR_YELLOW, "BRIGHT");
clearScreen ( 6+xOff, 0 + yOff, 8+xOff, 1+yOff);
setColor (COLOR_WHITE, COLOR_GREEN, "BRIGHT");
clearScreen (6+xOff, 2+yOff, 8+xOff, 3+yOff);
}
setColor (COLOR_WHITE, COLOR_YELLOW, "BRIGHT");
clearScreen (6+xOff, 0+yOff, 8+xOff, 1+yOff);
}
for (xOff=0; xOff < SCRN_MAX_X; xOff+=18 )
{
for ( yOff=0; yOff < SCRN_MAX_Y; yOff+=4)
{
setColor (COLOR_WHITE, COLOR_CYAN, "BRIGHT");
clearScreen ( 9+xOff, 0 + yOff, 11+xOff, 1+yOff);
setColor (COLOR_WHITE, COLOR_RED, "BRIGHT");
clearScreen (9+xOff, 2+yOff, 11+xOff, 3+yOff);
}
setColor (COLOR_WHITE, COLOR_CYAN, "BRIGHT");
clearScreen (9+xOff, 0+yOff, 11+xOff, 1+yOff);
}
for (xOff=0; xOff < SCRN_MAX_X; xOff+=18 )
{
for ( yOff=0; yOff < SCRN_MAX_Y; yOff+=4)
{
setColor (COLOR_WHITE, COLOR_MAGENTA, "BRIGHT");
clearScreen ( 12+xOff, 0 + yOff, 14+xOff, 1+yOff);
setColor (COLOR_WHITE, COLOR_BLUE, "BRIGHT");
clearScreen (12+xOff, 2+yOff, 14+xOff, 3+yOff);
}
setColor (COLOR_WHITE, COLOR_MAGENTA, "BRIGHT");
clearScreen (12+xOff, 0+yOff, 14+xOff, 1+yOff);
}
for (xOff=0; xOff < SCRN_MAX_X; xOff+=18 )
{
for ( yOff=0; yOff < SCRN_MAX_Y; yOff+=4)
{
setColor (COLOR_WHITE, COLOR_GREEN, "BRIGHT");
clearScreen ( 15+xOff, 0 + yOff, 17+xOff, 1+yOff);
setColor (COLOR_WHITE, COLOR_YELLOW, "BRIGHT");
clearScreen (15+xOff, 2+yOff, 17+xOff, 3+yOff);
}
setColor (COLOR_WHITE, COLOR_GREEN, "BRIGHT");
clearScreen (15+xOff, 0+yOff, 17+xOff, 1+yOff);
}
}

// supporting function implementation
void loadTitle()
{
//initialize variables

//set color
//function: setColor
   setColor (COLOR_YELLOW, COLOR_BLUE, "BRIGHT");

//clear screen
//function: clearScreen
   clearScreen ( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y);

//display title and subtitle
//function: printStringAt

   //print 'N'
   printStringAt (TITLE_N_X, TITLE_Y ,"NNN     NN", "LEFT");
   printStringAt (TITLE_N_X, TITLE_Y+1, "NN N    NN", "LEFT");
   printStringAt (TITLE_N_X, TITLE_Y+2, "NN  N   NN", "LEFT");
   printStringAt (TITLE_N_X, TITLE_Y+3, "NN   N  NN", "LEFT");
   printStringAt (TITLE_N_X, TITLE_Y+4, "NN    N NN", "LEFT");
   printStringAt (TITLE_N_X, TITLE_Y+5, "NN     NNN", "LEFT");

   //print 'I'
   printStringAt (TITLE_I_X, TITLE_Y, "IIIIIIII", "LEFT");
   printStringAt (TITLE_I_X, TITLE_Y+1, "   II", "LEFT");
   printStringAt (TITLE_I_X, TITLE_Y+2, "   II", "LEFT");
   printStringAt (TITLE_I_X, TITLE_Y+3, "   II", "LEFT");
   printStringAt (TITLE_I_X, TITLE_Y+4, "   II", "LEFT");
   printStringAt (TITLE_I_X, TITLE_Y+5, "IIIIIIII", "LEFT");

   //print 'T'
  printStringAt (TITLE_T_X, TITLE_Y, "TTTTTTTTTT", "LEFT");
  printStringAt (TITLE_T_X, TITLE_Y+1, "TTTTTTTTTT", "LEFT");
  printStringAt (TITLE_T_X, TITLE_Y+2, "    TT", "LEFT");
  printStringAt (TITLE_T_X, TITLE_Y+3, "    TT", "LEFT");
  printStringAt (TITLE_T_X, TITLE_Y+4, "    TT", "LEFT");
  printStringAt (TITLE_T_X, TITLE_Y+5, "    TT", "LEFT");

  //print 'R'
  printStringAt (TITLE_R_X, TITLE_Y, "RRRRRR", "LEFT");
  printStringAt (TITLE_R_X, TITLE_Y+1, "RR   RR", "LEFT");
  printStringAt (TITLE_R_X, TITLE_Y+2, "RR   RR", "LEFT");
  printStringAt (TITLE_R_X, TITLE_Y+3, "RRRRRR", "LEFT");
  printStringAt (TITLE_R_X, TITLE_Y+4, "RR RR", "LEFT");
  printStringAt (TITLE_R_X, TITLE_Y+5, "RR  RR", "LEFT");

  //print second 'i'
  printStringAt (TITLE_I2_X, TITLE_Y, "IIIIII", "LEFT");
  printStringAt (TITLE_I2_X, TITLE_Y+1, "  II", "LEFT");
  printStringAt (TITLE_I2_X, TITLE_Y+2, "  II", "LEFT");
  printStringAt (TITLE_I2_X, TITLE_Y+3, "  II", "LEFT"); 
  printStringAt (TITLE_I2_X, TITLE_Y+4, "  II", "LEFT"); 
  printStringAt (TITLE_I2_X, TITLE_Y+5, "IIIIII", "LEFT");

  //print 's'
  printStringAt (TITLE_S_X, TITLE_Y, "SSSSSSS", "LEFT");
  printStringAt (TITLE_S_X, TITLE_Y+1, "SS", "LEFT");
  printStringAt (TITLE_S_X, TITLE_Y+2, "SS", "LEFT");
  printStringAt (TITLE_S_X, TITLE_Y+3, "SSSSSSS", "LEFT");
  printStringAt (TITLE_S_X, TITLE_Y+4, "     SS", "LEFT");
  printStringAt (TITLE_S_X, TITLE_Y+5, "SSSSSSS", "LEFT");

  //print sub-title
  printStringAt (26, TITLE_Y+10, "Just a little less than Tetris", "LEFT");
  printStringAt (18, TITLE_Y+12, "by Kevin Boles, Gabby Kobany, and Andy Navarez", "LEFT");
 
//wait for user input
//waitForInput
   waitForInput (FIXED_WAIT);
}

void loadMainMenu(int difficulty)
{
// initialize variables

// display
// functgion: drawBackGround()
   drawBackGround();

// draw inner box
	
	 //set color
	   //function: setColor()
	   setColor (COLOR_BLUE, COLOR_WHITE, "BRIGHT");
	
	 //clear smaller screen
	   //fuction: clearScreen
	   clearScreen ( END_MIN_X, END_MIN_Y - 3, END_MAX_X, END_MAX_Y+2);

// display header
// printStringAt()
   printStringAt( MENU_X+17, MENU_Y, "NITRIS GAME- KEVIN, GABBY, AND ANDY'S GAME", "CENTER");
   printStringAt( MENU_X+17, MENU_Y+1, "==========================================", "CENTER");

// display user options

// difficulty option
//function: printStringAt
   printStringAt (MENU_X, MENU_Y+4, "1. <S>et Difficulty", "LEFT");

// play game option
   //function: printStringAt
   printStringAt (MENU_X, MENU_Y+6, "2. <P>lay Game", "LEFT");

// continue previous option
   //function: printStringAt
   printStringAt (MENU_X, MENU_Y+8, "3. <C>ontinue Previous Game", "LEFT");

// score screen option
    //function: printStringAt
    printStringAt (MENU_X, MENU_Y+10, "4. <D>isplay Scores", "LEFT");

// end program option
    //function: printStringAt
    printStringAt (MENU_X, MENU_Y+12, "5. <E>nd Nitris", "LEFT");

// prompt for and deploy user choice
// deployUserChoice()
   deployUserChoice(difficulty);

}

void deployUserChoice(int difficulty)
{
// initialize variables
	char userInput;
	char gameArr[MAX_ROW_LEN][MAX_COL_LEN];
	char namesArr[MAX_ROW_LEN][MAX_COL_LEN];
	int scoreCount = 0, playCount = 0;
	int scoreArr[MAX_ROW_LEN], playArr[MAX_ROW_LEN];
	
// display enter selection prompt
// promptForCharAt()
   printStringAt (MENU_X, MENU_Y+15, "Enter Selection: ", "LEFT");
   userInput = waitForInput(FIXED_WAIT);
   
// deploy corresponding function

// deploy difficulty screen for <s> or '1'
	// loadDifficultyScreen()
	   if (userInput == 1 || userInput == 's')
	     {
			 loadDifficultyScreen(difficulty);
	     }
	
	// deploy game screen for <p> or '2'
	   if (userInput == 2 || userInput == 'p')
	     {
	  		 loadNewGame(gameArr, difficulty);
	     }
	
	// continue from previous game for <c> or '3'
	// loadSavedGame()
	   if (userInput == 3 || userInput == 'c')
	     {
			loadSavedGame(gameArr, scoreCount, playCount, difficulty);
	     }
	
	// deploy score screen for <d> or '4' 
	// loadScoreScreen()
	   if (userInput == 4 || userInput == 'd')
	     {
	 	 	loadScoreScreen(scoreArr, playArr, namesArr);
	     }
	
	// end program for <e> or '5'
	   if (userInput == 5 || userInput == 'e')
	     {
	
		 // draw background
		       //function: drawBackGround
		       drawBackGround();
		
		     //set color
		       //function: setColor()
		       setColor (COLOR_BLUE, COLOR_WHITE, "BRIGHT");
		
		     //clear smaller screen
		       //fuction: clearScreen
		       clearScreen ( END_MIN_X, END_MIN_Y, END_MAX_X, END_MAX_Y);
		
		    //display end program title
		//function: printStringAt
		       printStringAt ( END_MIN_X+14, END_MIN_Y+1, "END KEVIN, GABBY, AND ANDY'S PROGRAM", "LEFT");
		       printStringAt ( END_MIN_X+14, END_MIN_Y+2, "====================================", "LEFT");
		
		    //display thank you message
		      //function: printStringAt
		      printStringAt (END_MIN_X+19, END_MIN_Y+5, "THANK YOU FOR PLAYING", "LEFT");
		      printStringAt (END_MIN_X+27, END_MIN_Y+7, "NITRIS", "LEFT");
		     
		    //display wait for input message
		      //function: printStringAt
		      printStringAt (END_MIN_X+18, END_MIN_Y+10, "Press Any Key to Continue", "LEFT");
		
		    //wait for user input
		      //function: waitForInput
		      waitForInput (FIXED_WAIT);
	     }
	
	// if another option, go back to main menu
	  else 
	     {
		 loadMainMenu(difficulty);
	     }
}


void loadDifficultyScreen(int &difficulty)
{
// initialize variables


//set color
 //function: setColor
drawBackGround();

//set color
  //function: setColor()
  setColor (COLOR_BLUE, COLOR_WHITE, "BRIGHT");

//clear smaller screen
  //fuction: clearScreen
  clearScreen ( WHITE_MIN_X-3, WHITE_MIN_Y+2, WHITE_MAX_X+3, WHITE_MAX_Y-3);


// display difficulty header with underline
	// printStringAt()
	   printStringAt ( WHITE_MIN_X-3, WHITE_MIN_Y+3, "Kevin, Gabby, and Andy's Difficulty Setting Module", "LEFT");
	   printStringAt ( WHITE_MIN_X-3, WHITE_MIN_Y+4, "==================================================", "LEFT");

// display difficulty options
	// printStringAt()
	   printStringAt (WHITE_MIN_X+4, WHITE_MIN_Y+6, "1. Difficulty <E>asy", "LEFT");
	   printStringAt (WHITE_MIN_X+4, WHITE_MIN_Y+8, "2. Difficulty <M>oderate", "LEFT");
	   printStringAt (WHITE_MIN_X+4, WHITE_MIN_Y+10, "3. Difficulty <H>ard", "LEFT");
	   printStringAt (WHITE_MIN_X+4, WHITE_MIN_Y+12, "4. Difficulty <L>udicrous", "LEFT");

// prompt for user selection
	// promptForCharAt()
	   printStringAt (WHITE_MIN_X+4, WHITE_MAX_Y-4, "Enter Selection: ", "LEFT");
	   difficulty = waitForInput (FIXED_WAIT);

// change difficulty corresponding to input

	// easy for <e> or '1' input
	 if (difficulty == 1 || difficulty == 'e')
	    {
	difficulty = 1;
		// go back to main menu
			//function: loadMainMenu()
	    loadMainMenu(MODERATE);
	    }
	
	// moderate for <m> or '2' input
	 if (difficulty == 2 || difficulty == 'm')
	    {
	difficulty = 2;
		// go back to main menu
			//function: loadMainMenu()
	    loadMainMenu(MODERATE);
	    }
	
	// hard for <h> or '3'
	 if (difficulty == 3 || difficulty == 'h')
	    {
	difficulty = 3;
		// go back to main menu
			//function: loadMainMenu()
	    loadMainMenu(MODERATE);
	    }
	
	// ludicrous for <l> or '4'
	 if (difficulty == 4 || difficulty == 'l')
	    {
	difficulty = 4;
		// go back to main menu
			//function: loadMainMenu()
	    loadMainMenu(MODERATE);
	    }


}


void loadInstructions()
{
// initialize variables

// draw background
drawBackGround();

 //set color
   //function: setColor()
   setColor (COLOR_BLUE, COLOR_WHITE, "BRIGHT");

 //clear smaller screen
   //fuction: clearScreen
   clearScreen ( END_MIN_X, END_MIN_Y, END_MAX_X, END_MAX_Y+2);

//display instructions header with underline
  //function: printStringAt
  printStringAt ( END_MIN_X+7, END_MIN_Y+2, "Kevin, Gabby, and Andy's Instructions Module", "LEFT");
  printStringAt ( END_MIN_X+7, END_MIN_Y+3, "============================================", "LEFT");

// print instructions
 // function: printStringAt
 printStringAt (END_MIN_X+16, END_MIN_Y+5, "Try to get three colors in a row", "LEFT");
 printStringAt (END_MIN_X+13, END_MIN_Y+7, "Vertically or Horizontally", "LEFT");
 printStringAt (END_MIN_X+4, END_MIN_Y+9, "Use left and right arrows to guide the falling blocks", "LEFT");
 printStringAt (END_MIN_X+10, END_MIN_Y+11, "Use <D> to remove the bottom row of blocks", "LEFT");

//print continue message
 //function: printStringAt
 printStringAt (END_MIN_X+13, END_MIN_Y+14, "Press Any Key to Continue", "LEFT");

// get user input to continue
// function: waitForInput
   waitForInput (FIXED_WAIT);

}

void loadGameUI()
{
// initialize variables
int counter;

// print background
	// function: setcolor, clearScreen
	
	// create background
	setColor( COLOR_BLACK, COLOR_WHITE, SET_BRIGHT );
	clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
	
	setColor(COLOR_BLUE, COLOR_WHITE, SET_BRIGHT);
	clearScreen(GAME_MIN_X, GAME_MIN_Y, MAX_COL_LEN + GAME_MIN_X, MAX_ROW_LEN + GAME_MIN_Y);

// make game background
setColor(COLOR_BLUE, COLOR_BLACK, SET_BRIGHT);
clearScreen(GAME_MIN_X, GAME_MIN_Y, MAX_COL_LEN + GAME_MIN_X, MAX_ROW_LEN + GAME_MIN_Y);

// print arena border

	// set colors
	setColor(COLOR_BLUE, COLOR_WHITE, SET_BRIGHT);

	// print game border (LEFT)
	for(counter = 0; counter <= MAX_ROW_LEN; counter++)
	{
		printCharAt(GAME_MIN_X, counter, '|');
	}
	
	// print game border (RIGHT)
	for(counter = 0; counter <= MAX_ROW_LEN; counter++)
	{
		printCharAt(GAME_MIN_X + MAX_COL_LEN, counter, '|');
	}
	// print scoreboard upper border
	for(counter = 0; counter <= 79; counter++)
	{
	printCharAt(counter, MAX_ROW_LEN + 1, '=');
	}

// display logo
	
	// Left side logo
	printStringAt(LOGO_X, LOGO_Y, "Michael's", "LEFT");
	printStringAt(LOGO_X - 1, LOGO_Y + 2, "Nitris Game", "LEFT");
	
	// Right side logo
	printStringAt(GAME_MIN_X + MAX_COL_LEN + LOGO_X + 1, LOGO_Y, "Michael's", "LEFT");
	printStringAt(GAME_MIN_X + MAX_COL_LEN + LOGO_X, LOGO_Y + 2, "Nitris Game", "LEFT");
	

// display bottom row text

	// print scoreboard
	printStringAt(SCORE_X, SCORE_Y, "Score:", "LEFT" );
	printStringAt(SCORE_X, SCORE_Y + 1, "Plays:", "LEFT" );
	
	// wait for user input to continue
	printStringAt(GAME_MIN_X, SCORE_Y + 1, "Press any key to start game", "LEFT" );
	waitForInput( FIXED_WAIT );
	
	// clear start text
	printStringAt(GAME_MIN_X, SCORE_Y + 1, "                           ", "LEFT" );

	// print controls
	printStringAt(GAME_MIN_X, SCORE_Y, "Use arrow keys to control block", "LEFT" );
	printStringAt(GAME_MIN_X, SCORE_Y + 1, "<D> Clears Bottom Row", "LEFT" );
	printStringAt(GAME_MIN_X, SCORE_Y + 2, "Space bar pauses game - ESCape ends game", "LEFT" );
	
}

void playGame(char gameArray[][ MAX_COL_LEN ], int difficulty, int scoreCount, int playCount)
{
// initialize function

	// initialize variables
	int testIndex;

	// position related
	int xLoc = 0, yLoc = 2;
	int userMove;
		
	// game cycle related	
	bool continueGame = true;
	char blockStatus;
	bool couldMove = true;
		
	// player info
	char userName[MAX_ROW_LEN][MAX_COL_LEN];
	int scoreArr[MAX_SCORES], playArr[MAX_SCORES];
	
// fill up game arena array with empty tiles and border
	// function: initializeArray()
initializeGameArray(gameArray);

// make game background
loadGameUI();

	
// run while nothing detected in top two rows
while(continueGame == true)
	{
		// refresh scores
		setColor(COLOR_BLUE, COLOR_WHITE, SET_BRIGHT);
			
			// score count
			printIntAt(SCRN_MAX_X - 2, SCORE_Y, scoreCount, "RIGHT");
			
			// play count		
			printIntAt(SCRN_MAX_X - 2, SCORE_Y + 1, playCount, "RIGHT");
	
		// reset block cycle	
			
			// get new block starting coords
				// function: rand()
			xLoc = rand() % MAX_SPAWN_RANGE;
			xLoc += 1;			
			yLoc = 0;
			
			// reset couldMove
			couldMove = true;
			
		// get new block char (blockStatus)
			// function: getBlockStatus
		getBlockStatus(blockStatus);
		
		// create a new block
			// function: spawnBlock()
		spawnBlock(xLoc, yLoc, blockStatus, gameArray);
			
		
			// run while the block has moved down previously
			while(couldMove)
				{
				
				// default move
					userMove = NO_MOVE;
				
				// wait for user input
					// switch/case
					userMove = waitForInput( 0 );
				
						// if no input, move down
							// function: moveBlock()
						if( userMove == NO_MOVE)
							{
								moveBlock(xLoc, yLoc, blockStatus, gameArray, couldMove, userMove);
							}
						
						// if left arrow, move left
							// function: moveBlock()
						else if(userMove == KB_LEFT_ARROW)
							{
								moveBlock(xLoc, yLoc, blockStatus, gameArray, couldMove, userMove);
							}
							
						// if right arrow, move right
							// function: moveBlock()
						else if(userMove == KB_RIGHT_ARROW)
							{
								moveBlock(xLoc, yLoc, blockStatus, gameArray, couldMove, userMove);
							}
						
							
						// if down arrow, move down
							// function: moveBlock()
						else if(userMove == KB_DOWN_ARROW)
							{
								moveBlock(xLoc, yLoc, blockStatus, gameArray, couldMove, NO_MOVE);
							}
						
						// if space, pause screen
							// function: pauseGame()
						else if(userMove == ' ')
							{
								
								// pause game
								pauseGame(gameArray, difficulty, scoreCount, playCount);
								
							}
						else if(userMove == KB_ESCAPE)
							{
							// print pause instructions at bottom of the screen

								// erase old lines
									
									// set color
									setColor(COLOR_BLUE, COLOR_WHITE, SET_BRIGHT);
									
									// clear screen
									clearScreen(GAME_MIN_X, SCORE_Y, MAX_COL_LEN + GAME_MIN_X + 2, SCORE_Y + 2);
									
									// print instructions	
									printStringAt(GAME_MIN_X, SCORE_Y + 1, "Game Ended - Press any key to continue", "LEFT" );
									
									// wait for input
									waitForInput( FIXED_WAIT );
									
									// save score data
									saveScoreData(scoreArr, playArr, userName, scoreCount, playCount);
									
									// end loop
									couldMove = false;
									continueGame = false;
									
									// load main menu
									loadMainMenu(difficulty);
							}
						
						// if other, assume no input
							// function: moveBlock()
						else
						{
							userMove = '\0';
							moveBlock(xLoc, yLoc, blockStatus, gameArray, couldMove, userMove);
						}
						
				}
				
		// check array for scoring conditions
			// function: checkArray [NOT DONE, HAD TO CARRY TEAM]
				
		// update play count scores
		playCount++;
		
		// test if game should continue
			
			// loop across test row
			for(testIndex = 0; testIndex <= MAX_COL_LEN; testIndex++)
				{
					// if anything but E, return false
					if(gameArray[TEST_ROW][testIndex] != 'E')
						{
						continueGame = false;
						}
				
				}
	}
	

// display end game message

// erase old lines
		
	// set color
	setColor(COLOR_BLUE, COLOR_WHITE, SET_BRIGHT);
		
	// clear screen
	clearScreen(GAME_MIN_X, SCORE_Y, MAX_COL_LEN + GAME_MIN_X + 2, SCORE_Y + 2);
		
	// print instructions
	
	printStringAt(GAME_MIN_X, SCORE_Y + 1, "Game Over - Press any key to continue", "LEFT" );


//wait for user input
waitForInput(FIXED_WAIT);

// load game over screen
	// function: gameOverScreen()
saveScoreData(scoreArr, playArr, userName, scoreCount, playCount);

}

void getBlockStatus(char &blockStatus)
{
// initialize function

	// get a random number between 0 and 4
		// function: rand()
	int randNum = rand() % 5;

// test randdom number for character value
	switch(randNum)
	{	
	// if 0, set to red (R)
	case 0:
		blockStatus = 'R';
	break;
	
	// if 1, set to yellow (Y)
	case 1:
		blockStatus = 'Y';
	break;
	
	// if 2, set to green (G)
	case 2:
		blockStatus = 'G';
	break;
	
	// if 3, set to (cyan) (C)
	case 3:
		blockStatus = 'C';
	break;
	
	// if 4 set to (magenta) (M)
	case 4:
		blockStatus = 'M';
	break;
	
	// set default case
	default:
		blockStatus = 'E';
	break;
	}
}


void spawnBlock(int xLoc, int yLoc, char blockStatus, char gameArr[][MAX_COL_LEN])
{
// initialize variables
int rowIndex, colIndex;

// iterate across rows (for block height spaces starting from yLoc)
	for(rowIndex = yLoc; rowIndex <= yLoc + 1; rowIndex++)
		{
			// iterate across columns
				// for
			for(colIndex = xLoc; colIndex <= xLoc + 2; colIndex++)	
				{
					// from xLoc, create characters for block length
						// for()
					gameArr[rowIndex][colIndex] = blockStatus;
				}
		}

// print array to screen
	// printArray()
printArray(GAME_MIN_X, GAME_MIN_Y, gameArr);
}

void printArray(int xStart, int yStart, char gameArr[][MAX_COL_LEN])
{
// initialize function
int rowIndex, colIndex;

// loop across array rows
for(rowIndex = 0; rowIndex <= MAX_ROW_LEN; rowIndex++)
	{
		// loop across array columns
		for(colIndex = 0; colIndex <= MAX_COL_LEN; colIndex++)
			{
			// print a color
			if(gameArr[rowIndex][colIndex] != 'E')
				{
					// set color
						// function: charToColor()
					charToColor(gameArr[rowIndex][colIndex]);
						
					// print color at current x/y Loc position
						// printCharAt()
					printCharAt(colIndex + xStart, rowIndex + yStart, ' ');
				}
			}
	}
}

void charToColor(char testChar)
{
// initialize variables

// test for each case
	// switch/case
switch(testChar)
	{
		// set color to black
			// function: setColor()
		case 'E':
			setColor( COLOR_RED, COLOR_BLACK, SET_BRIGHT );
		break;
		
		// set color to red
			// function: setColor()
		case 'R':
			setColor( COLOR_WHITE, COLOR_RED, SET_BRIGHT );
		break;
			
		// set color to yellow
			// function: setColor()	
		case 'Y':
			setColor( COLOR_RED, COLOR_YELLOW, SET_BRIGHT );
		break;
			
		// set color to green
			// function: setColor()	
		case 'G':
			setColor( COLOR_RED, COLOR_GREEN, SET_BRIGHT );
		break;
			
		// set color to cyan
			// function: setColor()	
		case 'C':
			setColor( COLOR_RED, COLOR_CYAN, SET_BRIGHT );
		break;
			
		// set color to magenta
			// function: setColor()	
		case 'M':
			setColor( COLOR_RED, COLOR_MAGENTA, SET_BRIGHT );
		break;
			
		// set color to white
			// function: setColor()
		case 'W':
			setColor( COLOR_RED, COLOR_WHITE, SET_BRIGHT );
		break;
			
		// default: black
			// function: setColor()
		default:
			setColor( COLOR_RED, COLOR_BLACK, SET_BRIGHT );
		break;
		
	}
}

void moveBlock(int &xLoc, int &yLoc, char blockStatus,  char gameArr[][MAX_COL_LEN], bool &couldMove, int userMove)
{
// initialize function
int currentXLoc = GAME_MIN_X + xLoc;
int currentYLoc = GAME_MIN_Y + yLoc;

// check user move
	switch(userMove)
		{
		
		case NO_MOVE:
		// if NO REPSPONSE, move down one space

				if(	collisionDetected(xLoc, yLoc, userMove, gameArr) )
					{
						// change couldMove to false
						couldMove = false;
					}
					
				// if no collision detected, move down
				else
					{
						// erase old block from screen
						setColor(COLOR_RED, COLOR_BLACK, SET_BRIGHT);
						clearScreen(currentXLoc, currentYLoc, currentXLoc + BLOCK_WIDTH - 1, currentYLoc + BLOCK_HEIGHT - 1);
						
						// erase old block
							// function: spawnblock
						spawnBlock(xLoc, yLoc, 'E', gameArr);
						
						// add 1 to y offset
						yLoc += 1;
						
						// spawn block from new position
							// function: spawnBlock
						spawnBlock(xLoc, yLoc, blockStatus, gameArr);
						
					}
		break;

		// if LEFT, attempt to move left
		case KB_LEFT_ARROW:
			if(	collisionDetected(xLoc, yLoc, userMove, gameArr) )
					{
						// do nothing/repeat cycle
						
					}
					
				// if no collision detected, move left
				else
					{
						// erase old block from screen
						setColor(COLOR_RED, COLOR_BLACK, SET_BRIGHT);
						clearScreen(currentXLoc, currentYLoc, currentXLoc + BLOCK_WIDTH - 1, currentYLoc + BLOCK_HEIGHT - 1);
						
						// erase old block
							// function: spawnblock
						spawnBlock(xLoc, yLoc, 'E', gameArr);
						
						// add 1 to y offset
						xLoc -= 1;
						
						// spawn block from new position
							// function: spawnBlock
						spawnBlock(xLoc, yLoc, blockStatus, gameArr);
						
					}
		break;
		
		// if RIGHT, attempt to move right
		case KB_RIGHT_ARROW:
			
			if(	collisionDetected(xLoc, yLoc, userMove, gameArr) )
					{
					
					
					}
					
				// if no collision detected, move right
				else
					{
						// erase old block from screen
						setColor(COLOR_RED, COLOR_BLACK, SET_BRIGHT);
						clearScreen(currentXLoc, currentYLoc, currentXLoc + BLOCK_WIDTH - 1, currentYLoc + BLOCK_HEIGHT - 1);
						
						// erase old block
							// function: spawnblock
						spawnBlock(xLoc, yLoc, 'E', gameArr);
						
						// add 1 to y offset
						xLoc += 1;
						
						// spawn block from new position
							// function: spawnBlock
						spawnBlock(xLoc, yLoc, blockStatus, gameArr);
						
					}
		break;
		
		// if DOWN, attempt move down
		case KB_DOWN_ARROW:
			
			if(	collisionDetected(xLoc, yLoc, userMove, gameArr) )
					{
						// change couldMove to false
						couldMove = false;
					}
					
				// if no collision detected, move down
				else
					{
						// erase old block from screen
						setColor(COLOR_RED, COLOR_BLACK, SET_BRIGHT);
						clearScreen(currentXLoc, currentYLoc, currentXLoc + BLOCK_WIDTH - 1, currentYLoc + BLOCK_HEIGHT - 1);
						
						// erase old block
							// function: spawnblock
						spawnBlock(xLoc, yLoc, 'E', gameArr);
						
						// add 1 to y offset
						yLoc += 2;
						
						// spawn block from new position
							// function: spawnBlock
						spawnBlock(xLoc, yLoc, blockStatus, gameArr);
						
					}
		break;
		
		// if anything else, do nothing
		default:
		
		break;

		}
}

bool collisionDetected(int xPos, int yPos, int userInput, char gameArr[][MAX_COL_LEN])
{
// initialize function
char testChar;
int index;

// DOWN check
if(userInput == NO_MOVE)
	{
	// get three character value of point two rows directly below
	for(index = 1; index <= BLOCK_WIDTH; index++)
		{
			testChar = gameArr[yPos + BLOCK_HEIGHT][xPos + index - 1];
			
			// if it's not empty, return true
			if(testChar != 'E')
				{
				return true;
				}
		}
	
	}
// LEFT check
if(userInput == KB_LEFT_ARROW)
	{
		// check for empty space to the left
		if( (xPos - 1 <= 0) || (gameArr[yPos + 1][xPos - 1] != 'E') )
			{
			return true;
			}

	}


// RIGHT check
if(userInput == KB_RIGHT_ARROW)
	{
		// check for empty space to the right
		if( (xPos + 3 >= MAX_COL_LEN) || (gameArr[yPos + 1][xPos + 3] != 'E') )
			{
			return true;
			}

	}
// return false
return false;
}


void pauseGame(char gameArr[][ MAX_COL_LEN ], int &difficulty, int &score, 
                                                                   int &plays) 
{
// initialize function
 char input = 'a';

// print pause instructions at bottom of the screen

	// erase old lines
		
		// set color
		setColor(COLOR_BLUE, COLOR_WHITE, SET_BRIGHT);
		
		// clear screen
		clearScreen(GAME_MIN_X, SCORE_Y, MAX_COL_LEN + GAME_MIN_X + 2, SCORE_Y + 2);
		
	// print instructions
		printStringAt(GAME_MIN_X, SCORE_Y, "Game Paused", "LEFT" );
		printStringAt(GAME_MIN_X, SCORE_Y + 1, "Press <S> to save game", "LEFT" );
		printStringAt(GAME_MIN_X, SCORE_Y + 2, "Press Space Bar to resume game", "LEFT" );

// get user input

if(input != 's' || input != 'S' || input != ' ')
	{
	input = waitForInput(FIXED_WAIT);
	
	// check input
	if(input == 's' || input == 'S')
		{
		// save game data
			// function: saveGameData()
		saveGameData(gameArr, difficulty, score, plays);
		
			// resume game
			// print normal game data at the bottom of the screen
				// clear screen
				clearScreen(GAME_MIN_X, SCORE_Y, MAX_COL_LEN + GAME_MIN_X + 2, SCORE_Y + 2);
			
				//display unpaused instructions
				printStringAt(GAME_MIN_X + 2, SCORE_Y, "Use arrow keys to control block", "LEFT" );
				printStringAt(GAME_MIN_X + 2, SCORE_Y + 1, "<D> Clears Bottom Row", "LEFT" );
				printStringAt(GAME_MIN_X, SCORE_Y + 2, "Space bar pauses game - ESCape ends game", "LEFT" );
				
				// display last saved state
				printStringAt(SCRN_MIN_X, SCORE_Y + 1, "Last saved at play: ", "LEFT" );
				printIntAt(GAME_MIN_X - 2, SCORE_Y + 1, plays, "RIGHT");
		
		}
		
	else if(input == ' ')
		{
		// resume game
			// print normal game data at the bottom of the screen
				// clear screen
				clearScreen(GAME_MIN_X, SCORE_Y, MAX_COL_LEN + GAME_MIN_X + 2, SCORE_Y + 2);
			
				//display unpaused instructions
				printStringAt(GAME_MIN_X, SCORE_Y, "Use arrow keys to control block", "LEFT" );
				printStringAt(GAME_MIN_X, SCORE_Y + 1, "<D> Clears Bottom Row", "LEFT" );
				printStringAt(GAME_MIN_X, SCORE_Y + 2, "Space bar pauses game - ESCape ends game", "LEFT" );
		}
	}
	
	// resume game (catch other inputs)
	// print normal game data at the bottom of the screen
		// clear screen
		clearScreen(GAME_MIN_X, SCORE_Y, MAX_COL_LEN + GAME_MIN_X + 2, SCORE_Y + 2);
			
		//display unpaused instructions
		printStringAt(GAME_MIN_X + 2, SCORE_Y, "Use arrow keys to control block", "LEFT" );
		printStringAt(GAME_MIN_X + 2, SCORE_Y + 1, "<D> Clears Bottom Row", "LEFT" );
		printStringAt(GAME_MIN_X, SCORE_Y + 2, "Space bar pauses game - ESCape ends game", "LEFT" );
				
	
}

void checkArray(int score, char gameArr[][MAX_COL_LEN])
{
// initialize function

// check for continuous horizonal strings

 //loop across rows of array
   //function: for()

 //if three consecutive blocks contain same color short

   //set color to white
     //function: setColor

   //increment score by one

   //end row loop

// check for continuous vertical strings

 //loop across columns of array
   //function: for()

 //if three consecutive blocks contain same color short

   //set color to white
     //function: setColor

   //increment score by one

   //end column loop

//return score

}

void loadScoreScreen( int scores[], int plays[], char names[][ MAX_COL_LEN ] )
{
// initialize variables
  //xPos, yPos
  int xPos = TITLE_X;
  int yPos = TITLE_Y;
  int arraySize = 0;

  int colIndex, rowIndex;
  double score, play, winRate;

//load data into arrays
  //loadScoreData( scores, plays, nameChars, arraysize )
  loadScoreData( scores, plays, names, arraySize );

//clear screen
  //clearScreen()
  setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
  clearScreen( DISPLAYSCORE_MIN_X, DISPLAYSCORE_MIN_Y, DISPLAYSCORE_MAX_X, 
                                                          DISPLAYSCORE_MAX_Y );

// print header with underline
// printStringAt()
  printStringAt( xPos, yPos - 4, "TEAM A.G.K's Score Display Module", "CENTER" );
  yPos++;
  printStringAt( xPos, yPos - 4, "=================================", "CENTER" );

//print name, underline, inStream Name
  //modify x-y positions for list titles
  xPos = HDR_SCR_X;
  yPos = HDR_SCR_Y;

  //print list headers spaced across the screen( Name, Score, Plays, WinRate )
     //printStringAt()
  printStringAt( xPos, yPos, "Name", "LEFT" );
  xPos+= 20;
  printStringAt( xPos, yPos, "Scores", "LEFT" );
  xPos+= 10;
  printStringAt( xPos, yPos, "Plays", "LEFT" );
  xPos+= 10;
  printStringAt( xPos, yPos, "Win Rate", "LEFT" );

  //Reset x position for new line, increment y value
  xPos = HDR_SCR_X;
  yPos = ( HDR_SCR_Y + 1 );

  //print underlines for each header
     //printStringAt()
  printStringAt( xPos, yPos, "====", "LEFT" );
  xPos+= 20;
  printStringAt( xPos, yPos, "======", "LEFT" );
  xPos+= 10;
  printStringAt( xPos, yPos, "=====", "LEFT" );
  xPos+= 10;
  printStringAt( xPos, yPos, "========", "LEFT" );
  yPos++;


//loop across arrays, printing one set of data at a time
//start with 2D array and nest all other arrays within
  //for()
for( rowIndex = 0; rowIndex <  arraySize; rowIndex++ )
  {
  //reset the x value for new line
  xPos = HDR_SCR_X;
  
  //Print Name array first
     //for()
  for( colIndex = 0; names[ rowIndex ][ colIndex ] != NULL_CHAR; colIndex++ )
     {
 //print first char at index
        //printCharAt()
     printCharAt( xPos, yPos, names[ rowIndex ][ colIndex ] );

     //increment print position for next loop
     xPos++;
     }
  
  //set x position for score list
  xPos= (HDR_SCR_X + 22);

  //print score then set x position for plays list
     //printIntAt()
  printIntAt( xPos, yPos, scores[ rowIndex ], "CENTER" );
  xPos+= 10;

  //print plays then set x position for winRate list
     //printIntAt()
  printIntAt( xPos, yPos, plays[ rowIndex ], "CENTER" );
  xPos+= 10;

  //assign score and play integers to double values
  score = scores[ rowIndex ];
  play = plays[ rowIndex ];

  //calculate win rate
  winRate = ( score / play )*100 ;

  //print win rate and percent char
     //printDoubleAt()/printCharAt()
  printDoubleAt( xPos, yPos, winRate, PRECISION, "CENTER" );
  xPos+= 4;
  printCharAt ( xPos, yPos, '%' );

  //increment y position for new line
  yPos++;
  }

//modify x-y positions for competion message
  xPos = ( DISPLAYSCORE_MAX_X - 28 );
  yPos = ( DISPLAYSCORE_MAX_Y - 1 );

//print completion message
  //printStringAt()
printStringAt( xPos, yPos, 
              "Score Display Complete - Press Any Key to Continue", "CENTER" );


//wait for input
  waitForInput( FIXED_WAIT );

  }

void loadScoreData( int playerScore[], int playerPlay[], 
                                   char nameChars[][ MAX_COL_LEN ], int &size )
  {
  
  //initialize variables
  ifstream inStream;
  int index, rowIndex, colIndex, score, plays;
  char dummy, name[ MAX_COL_LEN ];


  //open file
     //inStream.clear()/.open()
  inStream.clear();
  inStream.open( "scorefile.txt" );

  //initialize intiger arrays
  for( index = 0; index < ( MAX_SCORES - 1); index++ )
     {

     //set value to zero
     playerScore[ index ] = 0;
     playerPlay[ index ] = 0;

     }

  //initialize 2D character array
  for( rowIndex = 0; rowIndex < ( MAX_SCORES - 1 ); rowIndex++ )
     {

     for( colIndex = 0; colIndex < MAX_COL_LEN; colIndex++ )
        {
    //set char value to null
        nameChars[ rowIndex ][ colIndex ] = NULL_CHAR;

        }

     }

  //while the file is still good, upload file data
     //while( inStream.good() )
  rowIndex = 0;
  while( inStream.good() )
     {

     //load score data
     //load score to value, load value to array
        //instream >>
     inStream >> score; 
     playerScore[ rowIndex ] = score;

     //load play data
     //load play to value, load value to array
     //instream >>
     inStream >> dummy >> plays;
     playerPlay [ rowIndex ] = plays;

     //ignore the comma
     inStream >> dummy;

     //load one line: name sting
        //getline()
    inStream.getline( name, MAX_COL_LEN, ENDLINE_CHAR );

     //load name into 2D Array
        //for()
     for ( colIndex = 0; colIndex < MAX_COL_LEN; colIndex++ )
        {
      //load character at column in row
        nameChars[ rowIndex ][ colIndex ] = name[ colIndex ];

        }

     //increment array size and row index
     size++;
     rowIndex++;

     }

  //array size kept coming back too large so I had to reduce by one
  size--;

  //when input is complete, close file
     // inStream.close()
  inStream.close();

  }

void saveScoreData( int scores[], int plays[], char names[][ MAX_COL_LEN ], 
                                                 int currScore, int currPlays )
  {
  //initialize variables
  int arraySize = 0;
  ofstream outStream;
  int xPos = ( SAVESCORE_MIN_X + 30 );
  int yPos = ( SAVESCORE_MIN_Y + 1 );
  int rowIndex;

  // create background
  drawBackGround();

  //clear screen for module
     //setColor()/clearScreen()
  setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
  clearScreen( SAVESCORE_MIN_X, SAVESCORE_MIN_Y, SAVESCORE_MAX_X, SAVESCORE_MAX_Y );

  //load scores with commas
     //loadScoreData( score, plays, name, arraySize )
  loadScoreData( scores, plays, names, arraySize );

  //print module title with underline
     //printStringAt()
  printStringAt( xPos, yPos, "A.G.K's Score Loading Module", "CENTER" );
  yPos+= 2;
  printStringAt( xPos, yPos, "============================", "CENTER" );
  yPos++;
  
  //print instructions for user
     //printStringAt()
  printStringAt( xPos, yPos, 
                    "If your score per plays rate is high enough,", "CENTER" );
  yPos+= 2;
  printStringAt( xPos, yPos, 
              "your name and data will be added to the score list", "CENTER" );
  yPos+= 2;

  //prompt user for name and load it into last row of char array
     //promptForString()
  xPos -= 20; 
  promptForStringAt( xPos, yPos, "Enter your name: ", names[ arraySize ] );

  //print current play score and current plays in last index
  scores[ arraySize ] = currScore;
  plays[ arraySize ] = currPlays;

  //increment array size
  arraySize++;

  //once the user has enter name, data will be uploaded to arrays and sorted

  //print goodbye message
     //printStringAt
  yPos+= 3;
  printStringAt( xPos, yPos, "Press any key to continue", "Center" );

  //sort the arrays in order of increasing win rate
     //sortArray()
  sortArray( scores, plays, names, arraySize );

  //save new arrays to score file
  //open out stream
     //outStream.open()
  outStream.open( "scorefile.txt" );

  //check if arrays have more than 10 inputs
     //if()
  if( arraySize >=  MAX_SCORES )
     {

     //if they due, reduce size so that only 10 inputs are printed
     arraySize = ( MAX_SCORES - 1 );

     }

  //print scores to file in a loop
     //for()
  for( rowIndex = 0; rowIndex <  arraySize; rowIndex++ )
     {
     //send first set of data to file
     outStream << scores[ rowIndex ] << COMMA << plays[ rowIndex ] << COMMA << 
               names[ rowIndex ] << endl ;

     }

  //once all the processing has been done, hold screen for user and close file
     //waitForInput, outStream.close()
  waitForInput( FIXED_WAIT );
  outStream.close();

  }


void sortArray( int arrScores[], int arrPlays[], 
                                     char arrNames[][ MAX_COL_LEN ], int size )
  {
  //initialize variables
  double scoreOne, scoreTwo, playOne, playTwo, rateOne, rateTwo;
  bool swapped = true;
  int index;
  char nameOne[ MAX_COL_LEN ], nameTwo[ MAX_COL_LEN ];
  
  //loop until no morew swaps
     //while()
  while( swapped )
     {
     //set boolean to false and index to zero

     //loop until next to last item while
     for( swapped = false, index = 0; index < size; index++ )
        {
  
        //set test values to doubles for win rate calculation
        scoreOne = arrScores[ index ];
        scoreTwo = arrScores [ index + 1 ];
        playOne = arrPlays [ index ];
        playTwo = arrPlays [ index + 1 ];

        //calculate win rate
        rateOne = ( scoreOne / playOne )* 100;
        rateTwo = ( scoreTwo / playTwo )* 100;

        //check for first rate greater than second rate
           //if()
        if( rateOne < rateTwo )
           {
  
           //swap index values
           swap( arrScores[ index ], arrScores[ index + 1 ] );
           swap( arrPlays[ index ], arrPlays[ index + 1 ] );
           strcpy( nameOne, arrNames[ index ] );
           strcpy( nameTwo, arrNames[ index + 1 ] );
           strcpy( arrNames[ index ], nameTwo );
           strcpy( arrNames[ index + 1], nameOne );

           //set swap to true
           swapped = true;

           }

        }

     }
  }


void loadGameData( char gameArr[][ MAX_COL_LEN ], int &playerScore, 
                                        int &playerPlay, int &difficultyLevel )
{
  //intialize variables
     //inStream
  ifstream inStream;
  char uselessString[ MAX_STR_LEN ];
  int rowIndex;
  char dummyChar;
  //initialize game array
     //initializeArray( dataArray )
  initializeGameArray( gameArr );

  //open file
     //inStream.clear()/open()
  inStream.clear();
  inStream.open( "prevgame.txt" );

  //if file found, load data, otherwise return empty array
  if ( inStream.good() )
     {

     //load data from files
     //load Variables: inStream >> difficulty >> score >> plays
        //inStream.getLine( uselessString, MAX_INPUT_LENGTH, COLON );)
        // inStream >> difficultyLevel
        //inStream.ignore( MAX_STR_LEN, ENDLINE_CHAR );
     inStream.getline( uselessString, MAX_STR_LEN, COLON );
     inStream >> difficultyLevel;
     inStream.ignore( MAX_STR_LEN, ENDLINE_CHAR );

        //inStream.getLine( uselessString, MAX_STR_LEN, COMMA );)
        // inStream >> playerScore
     inStream.getline( uselessString, MAX_STR_LEN, COLON );
     inStream >> playerScore;
     inStream.ignore( MAX_STR_LEN, ENDLINE_CHAR );

        //inStream.getLine( uselessString, MAX_STR_LEN, COMMA );)
        // inStream >> playerPlay
     inStream.getline( uselessString, MAX_STR_LEN, COLON );
     inStream >> playerPlay;
     inStream.ignore( MAX_STR_LEN, ENDLINE_CHAR );

     // THIS PART KEEPS MESSING UP

     //load rows to array *this is where I'm stuck
     //based on row# load chars into array
     //until the 20th row
        //do
     for( rowIndex = 0; rowIndex < MAX_ROW_LEN ; rowIndex++ )
        {
           //inStream.getLine( uselessString, MAX_STR_LEN, COMMA );)
           // inStream >> rowIndex
        inStream >> uselessString >> dummyChar >> rowIndex >> dummyChar;

           //inStream.getLine( dataArray[ rowIndex ]; MAX_COL_LEN; ENDLINE_CHAR )
        inStream.getline( gameArr[ rowIndex ], MAX_COL_LEN, ENDLINE_CHAR );

    	}

     }
     
  //close file
     //inStream.close()
     inStream.close();


}

void loadNewGame( char gameArr[][ MAX_COL_LEN ], int diffLevel )
{
// initialize variables

// display instructions screen and wait for input
loadInstructions();

// begin game process
playGame(gameArr, diffLevel, 0,0);
 

}

void loadSavedGame( char gameArr[][ MAX_COL_LEN ], int &difficulty, int &score, 
                                                                   int &plays )
{
// initialize variables

//open saved game file and input into array
  //loadGameData( gameArray, score, plays, difficulty )
loadGameData( gameArr, score, plays ,difficulty);

// display instructions and wait for input
// loadInstructions(), wait for input
loadInstructions();
waitForInput( FIXED_WAIT );

// begin game process
playGame(gameArr, difficulty, score, plays);

}

void saveGameData( char gameArr[][ MAX_COL_LEN ], int &difficulty, int &score, 
                                                                   int &plays )
{
  //initialize variables
  //inStream, index, outStream   
  ofstream outStream;
  int rowIndex, colIndex;

  //open file
     //outStream.clear, outStream.open
  outStream.clear();
  outStream.open( "prevgame.txt" );

  //input difficulty, present score, present play, and game arena chars

     //input difficulty
        //input text and difficulty
     outStream << "Difficulty Level: " << difficulty << endl;

     //input score
        //input text and score
     outStream << "Present Score: " << score << endl;

     //input plays
        //input text
     outStream << "Present Plays: " << plays << endl;

     //input arena loop until row 21
     for( rowIndex = 0; rowIndex < GAME_MIN_X; rowIndex++ )
        {
    
        //input row title
           //outStream <<
        outStream << "Row: " << rowIndex << COMMA;

        //print array chars in that row
        for( colIndex = 0; colIndex < MAX_COL_LEN; colIndex++ )
           {

       //print array char
           outStream << gameArr[ rowIndex ][ colIndex ];

           }
        outStream << endl;

        }
        
  //close file
     //outStream.close
  outStream.close();

}

void initializeGameArray( char gameArray[][ MAX_COL_LEN ] )
{

//initialize variables
int rowIndex, colIndex;

//set all rows to null char

// loop across rows
for(rowIndex = 0; rowIndex <= MAX_ROW_LEN; rowIndex++)
{
    // loop across columns
   	for(colIndex = 0; colIndex <= MAX_COL_LEN; colIndex++)
{
// assign E to present spot
gameArray[rowIndex][colIndex] = 'E';

}	
// set first and last of all rows to vertical wall (EXTRA CREDIT OPTION)
   //for()
}

// set bottom row to horizontal wall (EXTRA CREDIT OPTION)

}           
