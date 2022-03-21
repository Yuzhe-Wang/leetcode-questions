/*
Description:
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

/*
given a begin word, a dictionary, a end word, return the shortest number of works
1. everytime we can only change one letter
2. the starting word is not in the dictionary

decision tree/ bfs
first, check if the answer existes in the dictionary
modify each of the letters for the current word, from a to z, and lookup in the dictionary to get
the children
fifo fringe - queue
pop from queue, if not visited (after visiting a word, just delete it from the dictionary), expand that node, add all the children into the fringe
terminate when the poped string is te target, return the depth
                                hit
                                hot
                    dot                     lot
            dog.          lot.        log.         dot
       cog      log           
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // tranform the dictionary into a hashset for faster lookup
        unordered_set<string> dic(wordList.begin(), wordList.end());
        // check if the answer exists in the dictionary
        if(dic.find(endWord) == dic.end()) return 0;
        // do bfs
        queue<pair<string,int>> fringe;
        fringe.push(make_pair(beginWord,1));
        
        while(!fringe.empty()) {
            for(int i = 0; i < fringe.size(); ++i) {
                auto curr = fringe.front();
                string word = curr.first;
                fringe.pop();
                for(int j = 0; j < word.length(); ++j) {
                    char x = word[j];
                    for(int k = 'a'; k <='z'; ++k) {
                        word[j] = k;
                        if(word == endWord) return curr.second + 1;
                        if(dic.find(word) == dic.end()) continue;
                        dic.erase(word);
                        fringe.push(make_pair(word,curr.second + 1));
                    }
                    word[j] = x;
                }
            }
        }
        return 0;
    }
};