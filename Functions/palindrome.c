#include<stdio.h>
void ispalindrome();
int main()
{
    int n;
    printf("Enter the no.\n");
    scanf("%d",&n);
    ispalindrome(n);
}
    void ispalindrome(int n)
    {
    int num=n;
    int rev=0;
    while(n!=0)
    {
    int dig = n%10;
    rev = rev*10 +dig;
    n /= 10;
    }
    if(num==rev)
    {
    printf("It is a palindrome no. \n");
    }
    else
    {
        printf("It is not a palindrome no. \n");
    }
    }
    
