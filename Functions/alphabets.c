#include <stdio.h>
void alphabets();
void main()
{
  alphabets();
}
  void alphabets()
  {
  char ch ;
  printf("ASCII chart for characters : \n\n") ;
  for(ch = 65 ; ch <= 122 ; ch++)
  {
    if(ch > 90 && ch < 97)
      continue ;
    printf("\t %c %d ",ch,ch) ;
  }
  printf("\n");
  }

