class Solution {
public:
    int getVerNum(int& idx, const string& version) {
        int n = version.size();
        string numStr;
        if(idx >= n)
            return 0;
        while(idx < n && version[idx] != '.') {
            numStr.push_back(version[idx]);
            idx++;
        }
        idx++;
        return stoi(numStr);
    }
    int compareVersion(string version1, string version2) {
        int idx1 = 0, idx2 = 0;
        int m = version1.size(), n = version2.size();
        while(idx1 < m || idx2 < n) {
            int ver1Num = getVerNum(idx1, version1);
            int ver2Num = getVerNum(idx2, version2);
            if(ver1Num < ver2Num)
                return -1;
            else if(ver1Num > ver2Num)
                return 1;
        }
        return 0;
    }
};