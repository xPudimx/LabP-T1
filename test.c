#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getType(char* str, char* ch){
  //TIPOS
  //Tipo 1 = str str
  //Tipo 2 = int int
  //Tipo 3 = str int
  //Tipo 4 = int str
  char *token, *string, *tofree,*var1, *var2, *dup1, *dup2;
  int tmp1,tmp2, tipo;
  tofree = string = strdup(str);
  if (string == NULL)
  return -1;

  token = strsep(&string, "=");
  token = strsep(&string, "=");
  token[strlen(token)-1]='\0'; // remove ";"
  dup1 = strdup(token);
  dup2 = strdup(token);

  var1 = strsep(&dup1, ch);
  if((var1[0] > 0x60 && var1[0] < 0x7B)) // detect string
  {
    var1 = strsep(&dup1, ch);
    if((var1[0] > 0x61 && var1[0] < 0x7A)){
      tipo = 1;
      return tipo;
    }
    else {
      tmp2 = atoi(var1);
      tipo = 3;
      return tipo;
    }
  }

  var2 = strsep(&dup2, ch);
  if(!(var2[0] > 0x60 && var2[0] < 0x7B)){
    tmp1 = atoi(var2);
    var2 = strsep(&dup2, ch);
    if(!(var2[0] > 0x61 && var2[0] < 0x7A)){
      tmp2 = atoi(var2);
      tipo = 2;
      return tipo;
    }
    else {
      tipo = 4;
      return tipo;
    }
  }
}
//
int main()
{
  // char* s = "x=y+z;";
  // int t = getType(s, "+");
  // printf("Tipo %d\n", t);
  // char* string = strdup(s);
  // char* token = strsep(&string, "=");
  // printf("%s\n", token);
  // token = strsep(&string, "=");
  // printf("%s\n", token);
  // token[strlen(token)-1]='\0';
  // char* var;
  // var = strsep(&token, "+");
  // printf("%s\n", var);
  // var = strsep(&token, "+");
  // printf("%s\n", var);
    //Tipo 1 = str str
    //Tipo 2 = int int
    //Tipo 3 = str int
    //Tipo 4 = int str
    char *token, *string, *tofree,*var1, *var2, *dup1, *dup2;
    char *str = "x=y+2;";
    int tmp1,tmp2, tipo;
    char* ch = "+";
    tofree = string = strdup(str);
    if (string == NULL)
      return -1;
    token = strsep(&string, "=");
    printf("%s\n", token);
    token = strsep(&string, "=");
    printf("%s\n", token);
    token[strlen(token)-1]='\0'; // remove ";"
    dup1 = strdup(token);
    dup2 = strdup(token);

    var1 = strsep(&dup1, ch);
    printf("%s\n", var1);
    if((var1[0] >= 0x60 && var1[0] <= 0x7B)) // detect string
    {
      printf("str1 = [ %s ] \n", var1);
      var1 = strsep(&dup1, "+");
      printf("%s\n", var1);
      if((var1[0] >= 0x61 && var1[0] <= 0x7A)){
        tipo = 1;
        printf("str2 = [ %s ] tipo = %d \n", var1, tipo);
      }
      else {
        tmp2 = atoi(var1);
        tipo = 3;
        printf("int2 = [ %d ] tipo = %d \n ",tmp2, tipo);
      }
    }

    var2 = strsep(&dup2, "+");
    printf("%s\n", var2);
    if(!(var2[0] >= 0x60 && var2[0] <= 0x7B)){
      tmp1 = atoi(var2);
      printf("int1 = [ %d ] \n ",tmp1);
      var2 = strsep(&dup2, "+");
      printf("%s\n", var2);
      if(!(var2[0] >= 0x61 && var2[0] <= 0x7A)){
        tmp2 = atoi(var2);
        tipo = 2;
        printf("int2 = [ %d ] tipo = %d\n ",tmp2, tipo);
      }
      else {
        tipo = 4;
        printf("str2 = [ %s ] tipo = %d\n", var2, tipo);
      }
    }

  return 0;
}