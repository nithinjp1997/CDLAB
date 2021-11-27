#include<stdio.h>
#include<stdlib.h>

char l,str[100];
int i = 0;

void A();
void parser(char t)
{
    if(l == t)
    {
        i++;
        while(str[i] == ' '){i++;}
        l = str[i];
    }    
    else    
    {
        printf("String is not accepted.\n");
        exit(0);
    }
    
}
void B()
{
    if(l == 'b')
    {
        parser('b');
        parser('+');
        A();
    }
    else if (l == 'a')
    {
        parser('a');
    }
    
}
void A()
{
    if(l == 'a')
    {
        parser('a');
        parser('*');
        B();
    }
    else if (l == 'b')
    {
        parser('b');
    }
    
}

int main()
{
    printf("Recursive Descent Parser.\nGrammar:\nA -> a*B/b\nB -> b+A/a\nEnter the string : ");
    fgets(str,100,stdin);
    l = str[i];
    A();
    if(str[i] == '\n')
    {
        printf("String is accepted.\n");
    }
    else
    {
        printf("String is not accepted.\n");
    }
    return 0;
}