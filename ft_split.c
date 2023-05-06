#include "pipex.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    size_t j;
    char *str;

    str = (char *)malloc(sizeof(*s) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (i >= start && j < len)
        {
            str[j] = s[i];
            j++;
        }
        i++;
    }
    str[j] = 0;
    return (str);
}

static int ft_count_word(char const *s, char c)
{
    int i;
    int word;

    i = 0;
    word = 0;
    while (s && s[i])
    {
        if (s[i] != c)
        {
            word++;
            while (s[i] != c && s[i])
                i++;
        }
        else
            i++;
    }
    return (word);
}

static int ft_size_word(char const *s, char c, int i)
{
    int size;

    size = 0;
    while (s[i] != c && s[i])
    {
        size++;
        i++;
    }
    return (size);
}

static void ft_free(char **strs, int j)
{
    while (j-- > 0)
        free(strs[j]);
    free(strs);
}

char **ft_split(char const *s, char c)
{
    int i;
    int word;
    char **strs;
    int size;
    int j;

    i = 0;
    j = -1;
    word = ft_count_word(s, c);
    if (!(strs = (char **)malloc((word + 1) * sizeof(char *))))
        return (NULL);
    while (++j < word)
    {
        while (s[i] == c)
            i++;
        size = ft_size_word(s, c, i);
        if (!(strs[j] = ft_substr(s, i, size)))
        {
            ft_free(strs, j);
            return (NULL);
        }
        i += size;
    }
    strs[j] = 0;
    return (strs);
}
