#include "pipex.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    int s1_len;
    int s2_len;
    int i;
    int j;

    if (s1 == NULL || s2 == NULL)
        return NULL;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (str == NULL)
        return NULL;
    // ft_memcpy(str, s1, s1_len);
    // ft_memcpy(str + s1_len, s2, s2_len + 1);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        str[i] = s2[j];
        j++;
        i++;
    }
    str[i] = '\0';

    return str;
}