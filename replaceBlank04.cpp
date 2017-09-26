class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(str == NULL || length <= 0){
			return ;
		}
		int num_blank = 0;
		int i=0;
		while(str[i] != '\0'){
			if(str[i] == ' '){
				++num_blank;
			}
			++i;
		}
		int new_len = length + 2*num_blank;
		int j = new_len;
		i = length;
		while(i != j){
			if(str[i] != ' '){
				str[j--] = str[i];
			}
			else{
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
			}
			--i;
		}
	}
};
