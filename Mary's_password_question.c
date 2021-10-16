/* Daniel has a possible list of passwords of Mary's facebook account. All passwords length is odd.
But Daniel knows that Mary is a big fan of palindromes. So, her password and reverse of her
password both should be in the list.
You have to print the length of Mary's password and its middle character.
Note: The solution will be unique.
Input
The first line of input contains the integer N, the number of possible passwords.
Each of the following N lines contains a single word, its length being an odd number greater
than 2 and lesser than 14. All characters are lowercase letters of the English alphabet.
Output
The first and only line of output must contain the length of the correct password and its central
letter.
Constraints
1≤N≤100 */

////AAnnsswweerr

#include<stdio.h>
#include<string.h>

#define maximumPassLength 13
#define minimunPassLength 3
#define MaxN 100
#define MinN 1

//Reverse of the string
void GetRevofString(char *str)
{
    int i,len,temp;
    len = strlen(str);

    for(i=0; i< len/2; i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main(void)
{
    int N=0, i, j, passwd = 0;

    while(N<MinN || N>MaxN)
    {
        printf("Enter number of lines :");
        scanf("%d", &N);
        if(N<MinN && N>MaxN)
            printf("N should be between %d and %d", MinN,MaxN);

    }

    //create an array to save passwords
    char PassArray[N][maximumPassLength];

    printf("Enter the list of passwords : ");

    for(i=0; i<N; i++)
        scanf("%s", PassArray[i]);

    //taking string in the created array

    for(i=0;i<N ; i++)
    {
        //reverse of the string
        int len = strlen(PassArray[i]);
        char reverseString[len];
        strcpy(reverseString, PassArray[i]);
        GetRevofString(reverseString);

        //compare reverseString with the strings in the PassArray array
        for(j=0;j<N; j++)
        {
            if(strcmp(PassArray[j], reverseString))
            {
                int mid = (len-1)/2;
                printf("%d %c", len,PassArray[i][mid]);
                passwd =1;
                break;
            }
        }

        if(passwd==1)
            break;
    }
    return 0;

}

