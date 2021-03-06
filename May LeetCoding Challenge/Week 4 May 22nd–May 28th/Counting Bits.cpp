/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> count(num+1);
        count[0]=0;
        if(num==0)
            return count;
        count[1]=1;
        if(num==1)
            return count;
        cout<<count[0]<<endl<<count[1]<<endl;
        int index=2;
        int loop=log2(num);
        for(int i=0;i<loop;i++)
        {
            for(int j=0;j<(1<<(i+1));j++)
            {
                count[index++]=count[j]+1;
                cout<<count[index-1]<<endl;
                if(index==num+1)
                    return count;
            }
        }
        return count;
    }
};
