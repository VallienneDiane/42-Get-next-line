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


| Function name            | get_next_line                                           |
| ------------------------ | :-----------------------------------------------------: |
| Prototype                | char *get_next_line(int fd)                             |
| Turn in files            | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| Parameters               | File descriptor to read from                            |
| Return value             | Read line:  correct behavior                            |
|                          | NULL: nothing else to read or an error occurred         |
| External functs.         | read, malloc, free                                      |
