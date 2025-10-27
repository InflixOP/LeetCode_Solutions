class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if (bank.size() < 2 ) return 0;
        int result = 0;
        int temp = 0;
        int count = 0;
        int size = bank[0].length();
        for (auto it : bank)
        {
            count = 0;
            for (int i=0; i < size; i++) {
                if(it[i] == '1') count++;
            }
            if (count != 0) {
                result += count * temp;
                temp = count;
            }
        }

        return result;

    }
};