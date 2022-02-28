// Solucion donde no se usa hash map, sino que se usan characteres como indexes de un array

#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n=s.length();
        int visited[256];
        for(int i=0;i<256;i++){
            visited[i]=-1;
        }
        int size=0;//size is curr_size
        int max_size=0;
        for(int i=0;i<n;i++){
            int last_occ=visited[s[i]];
            if(last_occ==-1 || last_occ<i-size){
                size+=1;
                max_size=std::max(max_size,size);
            }
            else{
                max_size=std::max(size,max_size);
                size=i-last_occ;
            }
            visited[s[i]]=i;
        }
        return max_size;
    }
};