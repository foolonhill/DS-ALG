/**
*
*/


char* my_strstr(const char *sub_str, char *str)
{
	if (sub_str == NULL || str == NULL)
		return NULL;

	const char *tmp = sub_str;
	int len = 0;

	while (*str != '\0') {
		while (*str != '\0' && *tmp != '\0' && *str++ == *tmp) {
			tmp++;
			len++;
		}

		if (*tmp == '\0') 
			return str - len;
		else if (len >= 1) {
			tmp = sub_str;
			str -= len;
			len = 0;
		} else {
			tmp = sub_str;
		}

	}

	return NULL;
}
