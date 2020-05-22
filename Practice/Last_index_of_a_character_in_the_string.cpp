/**
 * Title   : Last index of a character in the string
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/last-index-of-a-character-in-the-string/0
 **/

#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    char s[100004],c;
    scanf("%d",&t);
    while(t--)
    {
    int i=0;
    int pos=-1;
    fgets(s,sizeof(s),stdin);
    fgets(s,sizeof(s),stdin);
    scanf("%c",&c);
    int k=strlen(s);
    while(k--)
    {
        if(c==s[i])
        {
            pos=i;
        }
        i++;
    }
    printf("%d\n",pos);
    }
    return 0;
}
