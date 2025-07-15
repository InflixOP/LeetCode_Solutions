class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3)
        return false;
         int v=0;
        int c=0;
        for(char ch:word){
            if(!isalnum(ch))
            return false;
            if(isalpha(ch)){
                ch=tolower(ch);
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                v++;
                else
                c++;
            }
        }
        return v>0&&c>0;
    }
};