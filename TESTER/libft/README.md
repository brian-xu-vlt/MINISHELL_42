# LIBFT

First project of 42 which consists in the creation of functions presents in the standard C library and other personal functions/lib (vector).

# Building

``$> git clone https://github.com/lilafallet/LIBFT_42.git ``

``$> cd LIBFT_42``

  
   ``$> make``

## Part 1
* ft_memset
* ft_bzero
* ft_memcpy
* ft_memccpy
* ft_memmove
* ft_memchr
* ft_memcmp
* ft_strlen
* ft_strdup
* ft_strcpy
* ft_strncpy
* ft_strcat
* ft_strncat
* ft_strlcat
* ft_strchr
* ft_strrchr
* ft_strstr
* ft_strnstr
* ft_strcmp
* ft_strncmp
* ft_atoi
* ft_isalpha
* ft_isdigit
* ft_isalnum
* ft_isascii
* ft_isprint
* ft_toupper
* ft_tolower

## Part 2

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_substr         |Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’lenght’.
ft_strjoin        |Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
ft_strtrim        |Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
ft_split          |Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.
ft_itoa           |Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
ft_strmapi        |Applies the function ’f’ to each character of the string ’s’ to create a new string (with malloc(3)) resulting from successive applications of ’f’.
ft_putchar_fd     |Outputs the character ’c’ to the given file descriptor.
ft_putstr_fd      |Outputs the string ’s’ to the given file descriptor.
ft_putendl_fd     |Outputs the string ’s’ to the given file descriptor, followed by a newline.
ft_putnbr_fd      |Outputs the integer ’n’ to the given file descriptor.

## Bonus part

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_lstnew       |Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.
ft_lstadd_front |Adds the element ’new’ at the beginning of the list.
ft_lstsize      |Counts the number of elements in a list.
ft_lstlast      |Returns the last element of the list.
ft_lstadd_back  |Adds the element ’new’ at the end of the list.
ft_lstdelone    |Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed.
ft_lstclear     |Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL.
ft_lstiter      |Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
ft_lstmapi      |Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.

# Get_next_line

Returns a line ending with a '\n' read from a file descriptor without knowing its size beforehand: [repository of get_next_line](https://github.com/lilafallet/GNL_42)

# Ft_printf

Reproduction of the printf's function : [repository of ft_printf](https://github.com/lilafallet/PRINTF_42)

# Personal functions

## Conversion

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_atoul        |Converts a string to an unsigned long
ft_int_to_char  |Converts values of type integer to values of type character
ft_ltoa_base    |Converts a long to a string in the database
ft_ultoa_base   |Converts an unsigned long to a string in the database

## Initialisation

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_calloc |Allocates a memory block by setting all these bytes to 0

## Is something

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_is_len_zero        |Returns FALSE if the length of the string is 0, return the length of the string if the length of the string is different of zero
ft_iscomma            |Returns TRUE if the character is a comma
ft_iswhitespace       |Returns TRUE if the character is a space or a tabulation
ft_iswhitespacecomma  |Returns TRUE if the character is a space or a tabulation or a comma
ft_iswhitespacedigit  |Returns TRUE if the character is a space or a tabulation or a number

## Maths

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_abs                  |Returns the absolute value of a number
ft_bubblesort_minindex  |Returns the index of the smallest number present in an array of numbers
ft_get_size_of_nb       |Returns the length of a number
ft_lfpow                |Returns the high value (double) at a given power

## Mem

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_memdel       |Takes as parameter the address of a pointer whose pointed area must be freed with free(3), then the pointer is set to NULL.
ft_memdup       |Similar to strdup, it creates a copy of an arbitrary memory area by allocating memory for the copy with malloc.
ft_memjoin_free |Similar to strjoin, it creates a string wich contains the assembly of dest and src of the chosen size of len_dest and len_src then duplicate it in the pointer dest

## Output

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_putchar_fd     |Outputs the character ’c’
ft_putstr_fd      |Outputs the string ’s’
ft_putendl_fd     |Outputs the string ’s’, followed by a newline
ft_putnbr_fd      |Outputs the integer ’n’

## String

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
ft_free_tab       |Free(3) all the string presents in a character string array
ft_strcdup        |Duplicates a string to a given character
ft_strcheck       |Applies a character test function to a string
ft_strclen        |Returns the size of a string to a given character.
ft_strdel         |Takes as parameter the address of a string that must be free with free(3) and its pointer set to NULL
ft_strequ         |Lexicographically compares str1 and str2. If the two strings are equal, the function returns TRUE, or FALSE otherwise
ft_striter        |Applies the function f to each character in the string passed as a parameter. Each character is passed by address to the function f in order to be modified if necessary
ft_strlcpy        |Copies the string src in the string dest up to size - 1 and return the total length of the string they tried to create
ft_strndup        |Returns a pointer to a new string which is a duplicate of the string s. Memory for the new string is obtained with malloc(3), and can be freed with free(3)
ft_strnequ        |Compares lexicographically str1 and str2 up to n characters maximum or a ’0’ has been encountered. If both strings are equal, the function returns TRUE, or FALSE otherwise

## Vector

A vector means a container of elements ordered and accessible by indices, the size of which is dynamic: it is updated automatically when elements are added or deleted. The functions that will follow are functions that we can just as well use with strings, but the fact of using vectors will make it easier and more efficient to change thanks to the t_vector structure:
- the character chain: str
- vector size: size
- the size of the character chain: len
- resize vector: resize

``````````````````````````````````````````C
typedef struct	s_vector
{
	char		*str;
	size_t		size;
	size_t		len;
	size_t		resize;
}				t_vector;
```````````````````````````````````````````

FUNCTION NAME | DESCRIPTION |
:-----------: | :-----------:
vct_add			|Adds a character at the end of the vector
vct_addchararat		|Replaces a character to the given index
vct_addmem		|Copies len bytes from the memory zone src to the memory zone dest
vct_addstr		|Adds a string at the end of the vector
vct_addstrat		|Adds a string to the given index
vct_apply		|Applies a testing/modification function to a vector
vct_cat			|Concatenates two vectors
vct_cdup		|Duplicates a vector up to a given character
vct_chr			|Returns the index of the first occurence of the desired character or FAILURE if the character has not been found
vct_chrstr		|Returns TRUE if the desired string 'search' has be found on the vector's string, FALSE is the string 'search' has not be found
vct_clen		|Returns the length of the vector's string up to a given character
vct_cpy			|Copies a vector's content in an other one
vct_cut			|Deletes the last character of a vector
vct_cutfrom		|Deletes the last nb_of_char of a vector
vct_del			|Deletes a vector
vct_dup			|Duplicates a vector
vct_equ			|Returns SUCCESS if the strings contained in the two vectors are identicals, otherwise FALSE
vct_getcharat		|Returns the nth character of a vector
vct_getfirstchar	|Returns the first character of a vector
vct_getlen		|Returns the length of the vector's string
vct_getstr		|Returns a pointer to the string contained in a vector
vct_join		|Joined the vectors's strings in a new vector
vct_joinfree		|Joined the vectors's strings in a new vector and releases one vector, the other vector or the two vector
vct_new			|Initializes a new vector of the size passed as parameter. If the size is 0, the size will be reset to the value set by DEFAULT_VECTOR_SIZE
vct_nlen		|Returns the size of the vector's string on a maximum n bytes
vct_pop			|Deteles the first character of a vector
vct_popcut		|Deles the first nth 'start' character and the last nth 'end' character
vct_popfrom		|Deltetes the first nth characteres of a vector
vct_print		|Displays a vector on 'len' byte
vct_printf_fd		|Displays a vector on 'len' byte
vct_printendl		|Displays a vector one 'len' byte and add a '\n'
vct_printendl_fd	|Displays a vector one 'len' byte and add a '\n' on a given file descriptor
vct_push		|Adds a character at the begining of a vector
vct_pushstr		|Adds a string at the begining of a vector
vct_readline		|Reads a line on a file descriptor et returns the latter into the vector's string given in the function's parameter
vct_resize		|Resize the vector in function of the given 'len_to_resize' parameter
vct_split		|Divides the character string contained in the vector via the characters present in 'str' and returns to each call of 'split' the next part divided in a new vector as long as it is recalled with the same vector or NULL. If the initial vector changes, the division will be done on this new vector. The NO_SEP provides all the word but not the separator in a separate vector, the flag EACH_SEP flag provides each separator in a separate vector, the flag ALL_SEP provides all the separators that follow in the same vector, the flag WORD provides all the word that follow in the same vector.
vct_splitchr		|Divides the initial vector on the first occurrence of the character c (this one not included). The first part is returned in a new vector while the second is copied into the initial vector by overwriting the data initially present.
vct_strdup		|Returns a copy of the vector's string
