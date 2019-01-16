#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNext(char p[],int next[]);
void recursion(char s[], char p[], int i, int j);
void KMP(char s[], char p[], int next[]);
int main()
{
    char s[17] = {'a','b','f','a','k','l','f','i','o','p','q','r','s','o','k','p','s'};
    char p[8] = {'o','p','q','r','s','o','k','p'};
    int next[8];
    int i=0, j=0;
    recursion(s, p, i, j);
    //getNext(p,next);
    //KMP(s, p, next);
    return 0;
}
//±©Á¦µÝ¹é
void recursion(char s[], char p[], int i, int j)
{
    if(j == 4){
        printf("ÔÚ%d´¦×Ö·û´®Æ¥Åä³É¹¦", i);
        return;
    }
    if(s[i] == p[j]){
        ++i;
        ++j;
        recursion(s, p, i, j);
    }
    else{
        i = i-(j-1);
        j = 0;
        recursion(s, p, i, j);
    }
}
void KMP(char s[], char p[], int next[])
{
    int i = 0;
    int j = 0;
    while(i < 17 && j < 8){
            if(j == -1 || s[i] == p[j]){
                i++;
                ++j;
            printf("%d",j);
            }
            else
                j = next[j];
    }
    printf("\n%d", j);
    if(j == 8)
        printf("Æ¥Åä³É¹¦");
    else
        printf("Æ¥ÅäÊ§°Ü");
}

void getNext(char p[],int next[])
{
    next[0] = -1;
    int i = 0, j = -1;
    while( i < 8){
        if(j == -1 || p[i] == p[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else
            //»ØËÝ
            j = next[j];
    }
}
