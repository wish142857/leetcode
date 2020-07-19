#pragma once
#include <ctime>
#include <iostream>
#include <random>


namespace s470 {
    //---------------------------------------------
    // @Date: 2020/7/19 
    // @Algorithm: Rejection Sampling Algorithm
    // @Time: O(1)
    // @Space: O(1)
    //---------------------------------------------
    // The rand7() API is already defined for you.
    // int rand7();
    // @return a random integer in the range 1 to 7
    class Solution {
    public:
        Solution() {
            srand((int)time(NULL));
        }

        int rand7() {
            return (rand() % 7) + 1;
        }

        int rand10() {
            int x = 0;
            do {
                x = (rand7() - 1) * 7 + rand7();
            } while (x > 40);
            return (x % 10) + 1;
        }
    };
}
