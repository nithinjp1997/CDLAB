#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *l,*temp;


void E();
void EP();
void T();
void TP();
void F();
void parser(char *t);


void E()
{
    if(*l == 'i')
    {
        T();
        EP();
    }
    else if (*l == '(')
    {
        T();
        EP();
    }
    
}

void EP()
{
    if(*l == '+')
    {
        parser("+");
        T();
        EP();
    }
    else if (*l == ')')
    {
        return;
    }
    else if (*l == '\n')
    {
        return; 
    }

}

void T()
{
    if(*l == 'i')
    {
        F();
        TP();
    }
    else if (*l == '(')
    {
        F();
        TP();
    }
    
}

void TP()
{
    if(*l == '+')
    {
        return;
    }
    else if (*l == '*')
    {
        parser("*");
        F();
        TP();
    }
    else if (*l == ')')
    {
        return;
    }
    else if (*l == '\n')
    {
        return;
    }    

}

void F()
{
    if(*l == 'i')
    {
        parser("id");
    }
    else if (*l == '(')
    {
        parser("(");
        E();
        parser(")");
    }
    
}

void parser(char *t)
{

    if(*l == *t)
    {
        l = strtok_r(temp," ",&temp);
    }
    else
    {
        printf("Statement not accepted.\n");
        exit(0);
    }

}

int main()
{

    char str[100];
    printf("LL(1) Parser \nEnter the string : ");
    fgets(str,100,stdin);
    temp = strdup(str);
    l = strtok_r(temp," ",&temp);
    E();
    if(*l == '\n')
    {
        printf("Statement is accepted.\n");
    }
    else
    {
        printf("Statement is not accepted.\n");
    }
    return 0;

}
