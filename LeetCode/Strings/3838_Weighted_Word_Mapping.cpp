#include<iostream>
#include<vector>
#include<string>
using namespace std;
//Beats 100% in runtime and 100% in memory
/*
            APPROACH:

            For each word:
            1. Compute sum of weights of all characters
               sum = Σ weights[word[i] - 'a']

            2. Reduce the sum into range [0, 25] using modulo:
               mod = sum % 26

            3. Map this value to a character using REVERSED alphabet:
               0 → 'z'->'a'+25->'a'+(25-0)
               1 → 'y'->'a'+24-> 'a'+(25-1)
               2-> 'x'->'a'+23-> 'a'+(25-2)
               .
               24 → 'b'->'a'+1-> 'a'+(25-24)
               25 → 'a'->'a'+0-> 'a'+(25-25)
               => char ='a' + (25 - mod)

            FORMULA:
               mod = sum % 26
               result_char = 'a' + (25 - mod)
*/
class Solution {
public:
    
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string str; //result string
        for(int i=0;i<words.size();i++){ //iterating over words
            int sum=0;
            for(char c:words[i]){ //iterating over characters of word
                sum=sum+weights[c-'a']; //calculating sum of weights of characters
            }
            int mods=sum%26; //reducing sum to range [0,25]
            char alpha='a'+25-mods; //mapping mod value to character using reversed alphabet
            str.push_back(alpha); //appending the mapped character to result string
        }
        return str; //returning the final result string
    }
};