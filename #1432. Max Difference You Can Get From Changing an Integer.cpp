class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string max,min;
        char ele = 'a';
        int n=str.length();
        for(int i=0 ; i<n ; i++){
            if(str[i] != '9'){
                ele = str[i];
                break;
            }
        }
        for(int i=0 ; i<n ; i++){
            if(str[i] == ele){
                max.push_back('9');
            }else{
                max.push_back(str[i]);
            }
        }
        int flag = 0;
        ele = 'a';
        if(str[0] != '1'){
            ele = str[0];
            for(int i=0 ; i<n ; i++){
                if(str[i] == ele){
                    min.push_back('1');
                }else{
                    min.push_back(str[i]);
                }
            }
        }else{
            min.push_back(str[0]);
            for(int i=1 ; i<n ; i++){
                if(str[i] != '0' && str[i] != '1' && flag ==0 ){
                    ele = str[i];
                    flag++;
                }
                if(str[i] == ele){
                    min.push_back('0');
                }else{
                    min.push_back(str[i]);
                }
            }
        }

        return (stoi(max) - stoi(min));
    }
};