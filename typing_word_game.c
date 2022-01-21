#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE 9
static char* source[ARRAY_SIZE] = {"The", "quick", "brown","fox","jumps","over","the","lazy","dog"};

void shuffle(char**);
void playGame(char**);
int strcmp(char*,char*);
int main()
{
  char * hints[ARRAY_SIZE];
    //seed srand()
  srand(time(NULL));
    //shuffle array
  shuffle(hints);
    //play game
  playGame(hints);
    //exit
  printf("Exiting");
  return 0;
}

//Fisher-Yates Shuffle
void shuffle(char** hint)
{
  for(int i = 0; i  < ARRAY_SIZE; i++){
    //draw a random number between 0 and i
    int j = rand() % (i+1);
    if(j != i) {
      hint[i] = hint[j];
    }
    hint[j] = source[i];
  }
}


/*Play Game*/
//*Given hint[] ARRAY_SIZE
// int round = 0;
// //Display Prompt
// 
// //start timer
// //get user input
// //end timer
// //compare result
// //if strcmp(input,result)==0 continue until !(round<ARRAY_SIZE)else repeat that round
void playGame(char** hint)
{
  struct timeval * starttime = NULL;
  struct timeval * endtime = NULL;
  struct timeval * result = NULL;
  int isCorrect = 0;
  char* inString = NULL;
  for(int round = 0; round < ARRAY_SIZE; round++){
    do{
      //display prompt
      printf("%s\n",hint[round]);
      //start timer
      gettimeofday(starttime,NULL);
      //get user input
      scanf("%s",inString);
      //stop timer
      gettimeofday(endtime,NULL);
      //get result
      timersub(endtime,starttime,result);
      //check user input
      if(strcmp(hint[round],inString) == 0){
        isCorrect = 1;
        printf("Correct! %ld.%06d\n",result->tv_sec,result->tv_usec);
      }else{
        isCorrect = 0;
      }
    }while(isCorrect == 0);
  }

}

/*Timer Implementation*/
//The timer works by storing a timeval (struct timeval startTime) at the beginning of the code to be executed
//and at the end of the code (struct timeval endTime).  Timersub subtracts the two and returns the result to
//the passed in string
//struct timeval * startTime; struct timeval * endTime; struct timeval * result;
//gettimeofday(startTime); //set startTime
// *get user input*
//gettimeofday(endTime); //set endtime
//timersub(endTime,startTime,result); //result = endTime-startTime

//compares the cstring parameters by ascii value
//post: return 0 if l and r are identical
int strcmp(char* l, char* r)
{
  int a = l[0];
  int b = r[0];
  int counter = 0;
  while((a != '\0') && (b != '\0')){
    if(a != b){
      return a-b;
    }
    counter++;
    a = l[counter];
    b = r[counter];
  }
  return a-b;
}




