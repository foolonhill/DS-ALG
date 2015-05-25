
/*
** my fisrt version
*/
int my_atoi(const char *str)
{
	if (str == NULL)
		return 0;

	int len = 0;
	const char *tmp = str;
	while (*tmp) {
		if (*tmp < '0' || *tmp > '9')
			return 0;
		len++;
		tmp++;
	}

	int sum = 0;
	tmp = str;
	while (*tmp) {
		sum += (*tmp - '0') * pow(10, len - 1);
		len--;
		tmp++;
	}

	return sum;
}
