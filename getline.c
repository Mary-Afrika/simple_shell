#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * my_getline - this function is buggy, should be checked,
 * had a go and couldn't figure it out
 * @lineptr: pointer to buffer
 * @n: memory to be allocated, 0
 * means allocate 'dynamically'
 * @stream: type stream
 * Return: number of chars read
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    static char buffer[BUFFER_SIZE]; 
    static size_t buffer_index = 0;
    static size_t buffer_size = 0;

    
    ssize_t chars_read = 0;
   int c;
   char *new_lineptr;
 
    if (*lineptr == NULL || *n == 0) {
        *n = BUFFER_SIZE;
        *lineptr = malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
    }

    while (1) {
        if (buffer_index >= buffer_size) {
      
	  buffer_size = fread(buffer, sizeof(char), BUFFER_SIZE, stream);
            buffer_index = 0;

            if (buffer_size == 0) {
                if (chars_read == 0) {
                    return -1;
                } else {
                    break;  
                }
            }
        }

        c = buffer[buffer_index++]; 

	
        if (chars_read >= (ssize_t)(*n) - 1) {
            
            *n *= 2;
        new_lineptr = realloc(*lineptr, *n);
            if (new_lineptr == NULL) {
                return -1; 
            }
            *lineptr = new_lineptr;
        }

        (*lineptr)[chars_read++] = c;

        if (c == '\n') {
            break; 
        }
    }

    (*lineptr)[chars_read] = '\0';
    return chars_read; 
}

/**
 * my_getline - a custom _getline function, works nearly same as
 * stadard getline function
 * @lineptr: pointer to buffer
 * @n: memory to be allocated, 0
 * means allocate 'dynamically'
 * @stream: type stream
 * Return: number of chars read
*/
ssize_t _etline(char **lineptr, size_t *n, FILE *stream)
{
static char line[1024];
char *ptr;
ssize_t len;

   if (lineptr == NULL || n == NULL)
   {
      return -1;
   }

   if (ferror (stream))
      return -1;

   if (feof(stream))
      return -1;
     
   fgets(line,1024,stream);

   ptr = strchr(line,'\n');   
   if (ptr)
      *ptr = '\0';

   len = strlen(line);
   
   if ((len+1) < 1024)
   {
      ptr = realloc(*lineptr, 1024);
      if (ptr == NULL)
         return(-1);
      *lineptr = ptr;
      *n = 1024;
   }

   strcpy(*lineptr, line); 
   
   return(len);
}

/**
 * my_getline - a custom _getline function, works nearly same as
 * standard getline function
 * @lineptr: pointer to buffer
 * @n: memory to be allocated, 0 means allocate 'dynamically'
 * @stream: type stream
 * Return: number of chars read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    static char line[1024];
    char *ptr;
    ssize_t len;
    ssize_t chars_read;

    if (lineptr == NULL || n == NULL)
    {
        return -1;
    }

    if (ferror(stream))
        return -1;

    if (feof(stream))
        return -1;

    chars_read = read(fileno(stream), line, 1024);
    if (chars_read == -1)
        return -1;

    ptr = strchr(line, '\n');
    if (ptr)
        *ptr = '\0';

    len = strlen(line);

    if ((len + 1) < 1024)
    {
        ptr = realloc(*lineptr, 1024);
        if (ptr == NULL)
            return -1;
        *lineptr = ptr;
        *n = 1024;
    }

    strcpy(*lineptr, line);

    return (len);
}
