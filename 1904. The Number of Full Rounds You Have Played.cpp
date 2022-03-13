/*
Description:
You are participating in an online chess tournament. There is a chess round that starts every 15 minutes. The first round of the day starts at 00:00, and after every 15 minutes, a new round starts.

For example, the second round starts at 00:15, the fourth round starts at 00:45, and the seventh round starts at 01:30.
You are given two strings loginTime and logoutTime where:

loginTime is the time you will login to the game, and
logoutTime is the time you will logout from the game.
If logoutTime is earlier than loginTime, this means you have played from loginTime to midnight and from midnight to logoutTime.

Return the number of full chess rounds you have played in the tournament.

Note: All the given times follow the 24-hour clock. That means the first round of the day starts at 00:00 and the last round of the day starts at 23:45.
*/

// basic idea: convert the strings to numbers of minutes and then do the calculation

#include<iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int start = stoi(loginTime.substr(0,2)) * 60 + stoi(loginTime.substr(3));
        int end = stoi(logoutTime.substr(0,2)) * 60 + stoi(logoutTime.substr(3));
        
        // if the ending time is smaller than the starting time
        // that means the ending time is on the next day
        if(end < start) {
            end += 24 * 60;
        }
        
        // round the starting time up to something that is divisible by 15
        if(start % 15 != 0) {
            start += 15 - (start %15);
        }
        
        //calculate the result
        int result = 0;
        result = (end - start) / 15;
        return result;
    }
};