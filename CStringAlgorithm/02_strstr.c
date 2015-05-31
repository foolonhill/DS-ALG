/**
 * Description:
 * 	find sub_str in str. If found, return the address of first match. If not, return NULL.
 * 
 * There are two versions of strstr() in C++：
 * 	1) char* strstr(char *str, const char *sub_str);
 * 	2) const char* strstr(const char *str, const char *sub_str);
 * 
 * The version in C is:
 * 	char* strstr(const char *str, const char *sub_str);
 */


char* my_strstr(char *str, const char *sub_str)
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
			return str - len;    // if found, *tmp == '\0', so the str didn't go to next, so minus len
		else if (len >= 1) {
			tmp = sub_str;
			str -= len;          // if not found, str - len points to the next position of last time
			len = 0;
		} else {
			tmp = sub_str;
		}
	}
	return NULL;
}
