
#include <iostream>


class SolutionReplaceSpace {
public:
	// length means the max size
	void replaceSpace(char *str,int length) {
        if (str == NULL || length < 0)
			return;

		int spacenum = 0;
		char *tmp = str;
		while (*tmp) {
			if (*tmp == ' ')
				spacenum++;
			tmp++;
		}
		int str_len = strlen(str);

		if (str_len + 2*spacenum > length)
			return;

		for (int i = str_len; i >= 0; --i) {
			if (str[i] == ' ') {
				spacenum --;
				str[i + spacenum * 2] = '%';
				str[i + spacenum*2+1] = '2';
				str[i + spacenum*2+2] = '0';

			} else {
				str[i + spacenum * 2] = str[i];
			}
		}
	}
};
