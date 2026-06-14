//https://youtu.be/urZ7Jj2UXp0?si=owScaO_gueGMo3U_
//for detailed Derivation Refer to Notes in Notebook 
#include <iostream>
using namespace std;


class Solution {
public:

    int addDigits(int num) {
        // --------------------------------------------
        // APPROACH 1: BRUTE FORCE (Simulation)
        // Keep adding digits until single digit remains
        // Time: O(log n * log n), Space: O(1)
        // --------------------------------------------

        /*
        while(num >= 10) {   // repeat until single digit
        
            int sum = 0;
            
            // extract digits and add them
            while(num > 0) {
                sum += num % 10;  // last digit
                num /= 10;        // remove last digit
            }
            
            num = sum; // update number with digit sum
        }
        
        return num;

        */


        // --------------------------------------------
        // APPROACH 2: OPTIMIZED (Digital Root Formula)
        // --------------------------------------------


        // --------------------------------------------
        // BASE CASE
        // If number is 0, then only result is 0
        // --------------------------------------------
        if(num == 0) return 0;

    
        /*
            When we keep adding digits repeatedly, the number
            eventually reduces to a single digit (1–9).

            Pattern:
            1 → 1
            2 → 2
            ...
            9 → 9
            10 → 1
            11 → 2
            ...
            18 → 9
            19 → 1

            So results repeat in cycles of 9.

            Therefore:
            - If a number is divisible by 9 → answer is 9
            - Otherwise → answer is num % 9
        */

        // --------------------------------------------
        // EDGE CASE:
        // If num is multiple of 9 (like 9, 18, 27...)
        // --------------------------------------------
        if(num % 9 == 0) return 9;

        // --------------------------------------------
        // GENERAL CASE:
        // Return remainder after dividing by 9
        // --------------------------------------------
        return num % 9;
    }
};