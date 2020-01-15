#include<stdio.h>

void main(){
  int hash_table[100][2] = {0}, ele, choice = 0, active_ind = 1, i, hash_ind;
  int active_table[100] = {0};
  active_table[0] = 1;
  active_table[1] = 1;

  while(choice != 3){
    printf("Enter the choice:\n1. Enter Element\n2. Display Hash Table\n3.EXIT\n");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter Element: ");
        scanf("%d", &ele);
        hash_ind = ele%100;
        if(active_table[hash_ind] == 0){
          for(i = active_ind+1; i <= hash_ind; i++){
            active_table[i] = 1;
          }
        }
        active_ind = hash_ind;
        i = ele/100;
        if(hash_table[hash_ind][0] == 0)
          hash_table[hash_ind][0] = ele;
        else if(hash_table[hash_ind][1] == 0)
          hash_table[hash_ind][1] = ele;
        else if(hash_table[hash_ind][0]/100 < i)
          hash_table[hash_ind][0] = ele;
        else if(hash_table[hash_ind][1]/100 < i)
          hash_table[hash_ind][1] = ele;
        break;

      case 2:
        printf("Hash Table ->\n");
        for(i = 0; i <= active_ind; i++){
          printf("%d %d\n", hash_table[i][0], hash_table[i][1]);
        }
        break;

      case 3:
        printf("\nThankyou");
        return;

      default:
        printf("Wrong Choice Entered !!");
    }

  }

}