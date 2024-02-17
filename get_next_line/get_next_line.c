/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:26:10 by zabdulza          #+#    #+#             */
/*   Updated: 2024/02/17 16:18:57 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* This function takes a buffer 'bfr' as input and creates a new buffer containing
   the contents after the first occurrence of '\n' character. It then frees the input buffer 'bfr'
   and returns the new buffer. */
char	*ft_nw_crt_bfr(char *bfr)
{
	int		i;          // Index variable for iteration through the buffer
	int		zi;         // Index variable for storing characters into the result buffer
	int		ln;         // Length of the input buffer 'bfr'
	char	*result;    // Pointer to the newly created buffer

	i = 0;
	zi = 0;
	ln = ft_len(bfr);    // Calculate the length of the input buffer 'bfr'
	while (bfr[i] && bfr[i] != '\n')   // Loop until '\n' or end of buffer is encountered
		i++;
	if (!bfr[i])    // If '\n' is not found, free the input buffer 'bfr' and return NULL
	{
		free(bfr);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ln - i + 1));   // Allocate memory for the new buffer
	if (!result)    // Check if memory allocation was successful
		return (NULL);
	i++;    // Move past the '\n' character
	while (bfr[i])   // Copy the remaining characters after '\n' into the new buffer
		result[zi++] = bfr[i++];
	result[zi] = '\0';   // Null-terminate the new buffer
	free(bfr);    // Free the input buffer 'bfr'
	return (result);   // Return the new buffer
}

/* This function reads from the file descriptor 'fd' and appends the read contents to the buffer 'bfr'
   until a newline character is encountered or the end of file is reached. */
char	*ft_creat_bfr(char *bfr, int bfr_sze, int fd)
{
	char	*temporary;   // Temporary buffer for reading from file descriptor

	temporary = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));   // Allocate memory for temporary buffer
	if (!temporary)    // Check if memory allocation was successful
		return (NULL);
	while ((bfr_sze != 0 && !ft_find_n(bfr)))   // Loop until newline character is found or end of file
	{
		bfr_sze = read(fd, temporary, BUFFER_SIZE);   // Read from file descriptor into temporary buffer
		if (bfr_sze == -1)    // Check for read error
		{
			free(temporary);
			return (NULL);
		}
		temporary[bfr_sze] = '\0';   // Null-terminate the temporary buffer
		bfr = ft_strjoin(bfr, temporary);   // Concatenate temporary buffer to 'bfr'
	}
	free(temporary);    // Free the temporary buffer
	if (bfr[0] == 0)    // If 'bfr' is empty, free it and return NULL
	{
		free(bfr);
		return (NULL);
	}
	return (bfr);    // Return the updated buffer 'bfr'
}

/* This function is the main function of the get_next_line implementation.
   It reads from the file descriptor 'fd' and returns a line from the input, delimited by '\n'. */
char	*get_next_line(int fd)
{
	char		*lyne;    // Pointer to the line read from file descriptor
	static char	*bfr;     // Static buffer to hold contents read from file descriptor

	int (i) = 0;   // Index variable for the loop
	if (fd < 0 || BUFFER_SIZE <= 0)   // Check for valid file descriptor and buffer size
		return (NULL);
	bfr = ft_creat_bfr(bfr, 1, fd);   // Create or update the buffer 'bfr' with contents from file descriptor
	if (!bfr)   // Check if buffer creation/update was successful
		return (NULL);
	i = ft_strcspn(bfr, "\n");   // Find the index of the first occurrence of '\n' in the buffer
	lyne = (char *)malloc(sizeof(char) * (i + 2));   // Allocate memory for the line
	if (!lyne)   // Check if memory allocation was successful
		return (NULL);
	ft_memcpy(lyne, bfr, i);   // Copy characters from buffer 'bfr' to the line
	if (bfr[i] == '\n')   // If '\n' is found in buffer, include it in the line
	{
		lyne[i] = bfr[i];
		i++;
	}
	lyne[i] = '\0';   // Null-terminate the line
	bfr = ft_nw_crt_bfr(bfr);   // Create a new buffer containing the remaining contents after '\n'
	return (lyne);   // Return the line read from file descriptor
}
