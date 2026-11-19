/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 22:18:00 by username          #+#    #+#             */
/*   Updated: 2026/11/19 20:11:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		//if char is not empty + char equal to space increase the index  by 1 next iteration should be by 
		while (s[i] && s[i] == c)
			i++;
		// if the space ended break and count a word			
		if (s[i])
			count++;
		//	if not a space increase the index by 1 until the next space is found
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_split_free(char **split, int count)
{
	while (count > 0)
		free(split[--count]);
	free(split);
	return (NULL);
}

static char	*ft_split_word(char const *s, char c, int *i)
{
    char	*word;
	int		len;
//skip the spaces in the string until the first word is found so we going to loop until the first char is not a space and then we going to count the length of the word until the next space is found
	while (s[*i] && s[*i] == c)
		(*i)++;
		//count the length of the word until the next space is found
	len = ft_word_len(s + *i, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + *i, len + 1);
	// let the index jump to the next word in the string so we can continue to loop until the end of the string is reached
	*i += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	//create a new pointer to pointer to char where the split words will be stored
	char	**split;
	int		count;
	int		i;
	int		j;
	//check that the input string is not NULL where if the argc return 1 so it's the  name of the file if 2 the name of thfile+space 
	if (!s)
		return (NULL);
	//count the number of words in the string using the ft_count_words function where the words are separated by the space for example we have 1 2 3 so the count is 3 	
	count = ft_count_words(s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		split[j] = ft_split_word(s, c, &i);
		if (!split[j])
			return (ft_split_free(split, j));
		j++;
	}
	split[j] = NULL;
	return (split);
}
