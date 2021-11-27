#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isoperator(char *tok)
{
    if (*tok == '+' || *tok == '-' || *tok == '*' ||
        *tok == '/' || *tok == '>' || *tok == '<' ||
        *tok == '=' || !strcmp(tok,">=")|| !strcmp(tok,"<=")
        || !strcmp(tok,"!=")|| !strcmp(tok,"=="))
        {
            printf("%s is an operator.\n",tok);
            return 1;
        }
    
    return 0;
         
}

int iskeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
    {
        printf("%s is a keyword.\n",str);
        return 1;
    } 
    return 0;
}

int isidentifier(char *str)
{
    int flag = 0,len = strlen(str);
    if(isalpha(str[0])!= 0 || str[0]== '_')
    {
        flag =1;
        int i =1;
        for(i=1;i<len;i++)
        {
            if(isalpha(str[i])!= 0)
            {
                flag = 1;
            }
            else if (isdigit(str[i]!= 0) && i+1 == len)
            {
                flag = 1;
            }
            else if (str[i]=='_')
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                return flag; 
            }
            
        
        }
        if (flag == 1)
        {
            printf("%s is an identifier.\n",str);
            return flag;
        }
           
    }
    return flag;
}

int isinteger(char *str)
{
  int i,flag = 0,len = strlen(str);
  for (i = 0;i<len;i++)
  {
      if(isdigit(str[i]) == 0)
      {
          flag = 0;
          return flag;
      }
      else 
      {
          flag = 1;
      }
  }
  printf("%s is an integer.\n",str);
  return flag;
}

int main(int argc,char *argv[])
{

  char str[254], delim[]=" ,;";
  printf("Enter the input : ");
  fgets(str,254,stdin);
  str[strlen(str) - 1] = '\0';
  char *token,*temp = strdup(str);
  while (token = strtok_r(temp,delim,&temp))
    {
        if(isoperator(token));
        else if (iskeyword(token));
        else if (isidentifier(token));
        else if (isinteger(token));
        else
            {
                printf("%s is not a valid identifier.\n",token);
            }
    }
    
  return 0;
}