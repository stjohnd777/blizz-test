# blizz-test
blizzard code assignment 

Hearthstone Engineering Test

- Please send back your solutions as source files attached to your email.  
- You may use either C++ or C#, whichever you feel the most comfortable in.  
- For database, any relational database can be used.
- Do not paste your answers into this document or into the body of your email.
- There is no set time limit. 
- However, please let us know the approximate amount of time you spent on the test. 

You may use any reference materials (books, internet sites, etc.). We strongly recommend that you compile and test your answers. If you write any test code, 
please include it with your answers.

- Write your answers assuming they will become part of a large codebase. 
- Your code will be called frequently during gameplay and will be maintained and extended by the entire programming team.  

Our key coding values are: 
- Simple
- Readable
- Efficient

# 1 Write a function that takes an unsigned integer as input, and returns true if all the digits in the base 10 representation of that number are unique. 
bool AllDigitsUnique(unsigned int value)
Example:
AllDigitsUnique(48778584) returns false
AllDigitsUnique(17308459) returns true


# 2  Write a function that modifies an input string, sorting the letters according to a sort order defined by a second string. 
- You may assume that every character in the input string also appears somewhere in the sort order string. 
- Make your function as fast as possible for long input strings.

# Example:
char* inputStr = strdup(“sort the letters in this string”);
SortLetters(inputStr, “ isetlgornh”);
would modify the input string to “     iiisssseeettttttlgorrrnnhh”.
 
# 3. Database Design.
3a. Create card definition tables.
-	Refer to all “Hearthstone’s Standard” cards list (https://playhearthstone.com/en-us/cards?set=standard&viewMode=table) to design relational database table(s). You only need to consider card attributes shown from the card list. (Class, Mana, Attack, Health, Card Type, Rarity, Minion Type, and Keywords) 
3b. Create player card collection tables.
-	Design table(s) to express all card instances owned by players (card collection).
-	A player can own multiple instances of same card.
-	Deleted cards should be are marked as deleted for tracking.
3c. Write analytic queries for players’ card collections.
-	Find out an average number of cards owned by each player.
-	Find out which card is being deleted the most by all players and find an average time it takes for such card to be deleted by players. 
