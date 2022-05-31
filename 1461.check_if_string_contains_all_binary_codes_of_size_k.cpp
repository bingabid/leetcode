// leetcode: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = (1<<k);
        vector<bool> hash(n,false);
        int mask = n - 1, hashVal = 0;
        for(int i=0;i<s.length();i++){
            //(hashVal<<1)&mask : way to remove the leading bit(when number of bits in hashVal is k)
            hashVal = ((hashVal<<1)&mask)|(s[i]-'0');
            if(i>=k-1 && hash[hashVal]==false){
                hash[hashVal] = true;
                n--;
                if(n == 0) return true;
            }
        }
        return false;
    }
};
