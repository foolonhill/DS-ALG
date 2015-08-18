#include <vector>

using std::vector;


class SolutionTwoArray {
public:
    bool Find(vector<vector<int> > array,int target) {
        if (array.size() <= 0)
            return false;
		if (array[0].size() <= 0)
			return false;
        size_t rows = array.size();
        size_t columns = array[0].size();
        
		int i = 0;
		int j = columns - 1;           // j must be int , cannot be size_t because it can be negative
		while (i < rows && j >= 0) {
			if (array[i][j] == target)
				return true;
			else if (array[i][j] > target)
				j--;
			else
				i++;
		}
        
        return false;
    }
};
