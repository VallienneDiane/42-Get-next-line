### GET NEXT LINE

## LANCER LE PROGRAMME

``` gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c ```

Ajouter un main : 

``` 
int main(void)
{
 int  fd;
 char *str;
 
 fd = open("texte.txt", O_RDONLY);
 while ((str = get_next_line(fd)) != NULL)
 {
   printf("%s\n", str);
   free(str);
  }
  return (0);
 }
 ```
 
ps : ne pas oublier d'ajouter la librairie de printf ``` #include <stdio.h> ```
