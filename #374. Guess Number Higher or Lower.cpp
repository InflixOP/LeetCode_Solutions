/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 class Solution {
    public:
        int guessNumber(int n) {
            int l=1,h=n,p;
            while(1){
                p=(h-l)/2+l;
                if(guess(p)==1)
                l=p+1;
                else if(guess(p)==-1)
                h=p-1;
                else 
                break;
            }
            return p;
        }
    };