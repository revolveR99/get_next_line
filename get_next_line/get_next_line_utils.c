/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:26:19 by zabdulza          #+#    #+#             */
/*   Updated: 2024/02/17 16:16:22 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function to calculate the length of a string
size_t	ft_len(char *s)
{
	size_t	i; // Declare variable to store the length

	i = 0; // Initialize the length to 0
	if (!s) // If the string is NULL
		return (0); // Return 0
	while (s[i] != '\0') // Loop until the end of the string ('\0') is encountered
		i++; // Increment the length
	return (i); // Return the length of the string
}

// Function to copy memory from source to destination
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*original_dst; // Declare a variable to store the original destination pointer
	char	*dst1; // Declare a char pointer for destination
	char	*src2; // Declare a char pointer for source

	dst1 = (char *)dst; // Cast destination pointer to char pointer
	src2 = (char *)src; // Cast source pointer to char pointer
	if (!dst && !src) // If both source and destination pointers are NULL
		return (NULL); // Return NULL
	original_dst = dst; // Store the original destination pointer
	while (n--) // Loop until n becomes 0
		*((char *)dst1++) = *((char *)src2++); // Copy character from source to destination
	return (original_dst); // Return the original destination pointer
}

// Function to find the first occurrence of '\n' character in a string
int	ft_find_n(char *s)
{
	int	i; // Declare a variable to store the index

	i = 0; // Initialize index to 0
	if (!s) // If the string is NULL
		return (0); // Return 0
	while (s[i]) // Loop until the end of the string ('\0') is encountered
	{
		if (s[i] == '\n') // If '\n' character is found
			return (1); // Return 1
		i++; // Move to the next character
	}
	return (0); // Return 0 if '\n' is not found
}

// Function to concatenate two strings
char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len1; // Declare variable to store length of s1
	size_t		len2; // Declare variable to store length of s2
	char		*strg; // Declare pointer to store concatenated string

	len1 = 0; // Initialize length of s1 to 0
	if (!s1) // If s1 is NULL
	{
		s1 = (char *)malloc(sizeof(char)); // Allocate memory for s1
		s1[0] = '\0'; // Set s1 as an empty string
	}
	if (!s1 && !s2) // If both s1 and s2 are NULL
		return (NULL); // Return NULL
	if (s1) // If s1 is not NULL
		len1 = ft_len(s1); // Calculate length of s1
	len2 = ft_len(s2); // Calculate length of s2
	strg = (char *)malloc(sizeof(char) * (len1 + len2 + 1)); // Allocate memory for concatenated string
	if (!strg) // If memory allocation fails
		return (NULL); // Return NULL
	ft_memcpy(strg, s1, len1); // Copy s1 to the beginning of the concatenated string
	ft_memcpy(strg + len1, s2, len2 + 1); // Copy s2 after s1 in the concatenated string
	free(s1); // Free memory allocated for s1
	return (strg); // Return the concatenated string
}

// Function to find the length of the initial segment of a string which consists of characters not in a given set
size_t	ft_strcspn(const char *str, const char *charset)
{
	size_t	index; // Declare variable to store index
	size_t	charset_index; // Declare variable to store index for charset

	index = 0; // Initialize index to 0
	while (str[index] != '\0') // Loop until the end of the string ('\0') is encountered
	{
		charset_index = 0; // Initialize charset_index to 0
		while (charset[charset_index] != '\0') // Loop until the end of charset ('\0') is encountered
		{
			if (str[index] == charset[charset_index]) // If character in string matches character in charset
				return (index); // Return the current index
			charset_index++; // Move to the next character in charset
		}
		index++; // Move to the next character in string
	}
	return (index); // Return the length of the string if no character from charset is found
}

}
