## Daniel St. John
#### Blizzard Code Assignment 
 - stjohnd@gmail.com 
- 719 439 7835
---
#### Hearthstone Engineering Test

    - Send your solutions as source files attached in email.  
    - Use  C++ or C#
    - Any relational database can be used.
    - There is no set time limit, but know the approximate amount of time you spent on the test. 
    - You may use any reference materials (books, internet sites, etc.). 
    - We strongly recommend that you compile and test your answers. 
    - If you write any test code, please include it with your answers.
    - Write your answers assuming they will become part of a large codebase. 
    - Your code will be called frequently during gameplay and will be maintained and extended by the entire programming team.  

---
- #### Uniques Coding Values: 
    -  Simple
    - Readable
    - Efficient

---

#### Question 1
- Write a function that takes an unsigned integer as input and returns true if all the digits in the base 10 representation of that number are unique. 

    - Example:
        - AllDigitsUnique(48778584) returns false
        - AllDigitsUnique(17308459) returns true

---  
- #### Some Remark 
    - The build system is cmake. 
    - The Unit Test frame ork is Catch2. Catch is header only. 
    - The TimeMetric class is not part of the code base but provided to give timing stats, and this class came from my Utilities on GitHub. 
    - I created two implementations. 
        - The solution under the namespace dsj::optimized is the intended solution. 
        - The solution under the namespace dsj::str is readable, simple and illustrates the issues with string when performance is needed.
- The reader should be able to use any IDE with CMake to run the unit test. There is a main method provided just in case cmake goes wrong.

- #### Some general remarks on the problem:
    - The largest base ten integer that has unique digits is 9,876,543,210.
    - I pondered the potential for summing the digits as a solution on the equivalence classes under rearrangement but this did not pan out 
    - Solving this problem by treating the integer as a string is easy but not performant
    - Striping digits via divide 10 mode 10 and tracking visited digits is the submitted approach
    - For interest I contrasted the two natural approaches. 
    - ##### The optimized approach is at least one order of magnitude faster
        - Total Uniques:  6454891:   Run time : 1022.5
        - Total Uniques:  6454891:   Run Time : 11091.7
        
    - I work with std:string not char* unless on an FPGA or RTOS

```
namespace dsj {

    /**
     * This is more performant implementation
     */
    namespace optimized {
        /**
         * Get the nth signifigant digit of the number, for example
         * GetDigitAt(42,0) return 2 and GetDigitAt(42,1) return 4 and then
         * for out of range is has been determined to return 0;
         *
         * @param integer
         * @param n
         * @return
         */
        unsigned int GetDigitAt(unsigned long integer, int n);
        /**
         * The analogy to string length for integer, for example 42 return 2 and
         * 9876543210 return 10
         *
         * @param integer
         * @param n
         * @return
         */
        unsigned int DigitLength(unsigned long integer);
        //bool IsNumberComposedUniqueDigits(unsigned long candidate);
        /**
         * If all the digit in the number are unique return true otherwise false
         *  * Example:
         *  AllDigitsUnique(48778584) returns false
         *  AllDigitsUnique(17308459) returns true
         * @param candidate
         * @return
         */
        bool AllDigitsUnique(unsigned long candidate);
    }

    /**
     * This is a readable simple implementation using string,
     * not intended as usable for performance intense requirements
     */
    namespace str {
        unsigned int GetDigitAt(unsigned long integer, int n);
        unsigned int DigitLength(unsigned long integer);
        //bool IsNumberComposedUniqueDigits(unsigned long candidate);
        bool AllDigitsUnique(unsigned long candidate);
    }
}
```
```
namespace dsj {

    /**
     * This is more performant implementation
     */
    namespace optimized {
        /**
         * Get the nth signifigant digit of the number, for example
         * GetDigitAt(42,0) return 2 and GetDigitAt(42,1) return 4 and then
         * for out of range is has been determined to return 0;
         *
         * @param integer
         * @param n
         * @return
         */
        unsigned int GetDigitAt(unsigned long integer, int n);
        /**
         * The analogy to string length for integer, for example 42 return 2 and
         * 9876543210 return 10
         *
         * @param integer
         * @param n
         * @return
         */
        unsigned int DigitLength(unsigned long integer);
        //bool IsNumberComposedUniqueDigits(unsigned long candidate);
        /**
         * If all the digit in the number are unique return true otherwise false
         *  * Example:
         *  AllDigitsUnique(48778584) returns false
         *  AllDigitsUnique(17308459) returns true
         * @param candidate
         * @return
         */
        bool AllDigitsUnique(unsigned long candidate);
    }

    /**
     * This is a readable simple implementation using string,
     * not intended as usable for performance intense requirements
     */
    namespace str {
        unsigned int GetDigitAt(unsigned long integer, int n);
        unsigned int DigitLength(unsigned long integer);
        //bool IsNumberComposedUniqueDigits(unsigned long candidate);
        bool AllDigitsUnique(unsigned long candidate);
    }
}
```
---
``` 
using namespace std;
using namespace dsj;

TEST_CASE("Test Length Optimized", "[001]") {
    REQUIRE(dsj::optimized::DigitLength(0) == 1);
    REQUIRE(dsj::optimized::DigitLength(3) == 1);
    REQUIRE(dsj::optimized::DigitLength(6) == 1);
    REQUIRE(dsj::optimized::DigitLength(9) == 1);
    REQUIRE(dsj::optimized::DigitLength(12) == 2);
    REQUIRE(dsj::optimized::DigitLength(999) == 3);
    REQUIRE(dsj::optimized::DigitLength(1234) == 4);
    REQUIRE(dsj::optimized::DigitLength(1234567) == 7);
    REQUIRE(dsj::optimized::DigitLength(123456789) == 9);
    REQUIRE(dsj::optimized::DigitLength(1234567890) == 10);
    REQUIRE(dsj::optimized::DigitLength(12345678901) == 11);
    REQUIRE(dsj::optimized::DigitLength(123456789012) == 12);
    REQUIRE(dsj::optimized::DigitLength(1234567890123) == 13);
    REQUIRE(dsj::optimized::DigitLength(12345678901234) == 14);
    REQUIRE(dsj::optimized::DigitLength(123456789012345) == 15);
    REQUIRE(dsj::optimized::DigitLength(1234567890123456) == 16);
    REQUIRE(dsj::optimized::DigitLength(12345678901234567) == 17);
    REQUIRE(dsj::optimized::DigitLength(123456789012345678) == 18);
    REQUIRE(dsj::optimized::DigitLength(1234567890123456789) == 19);
}

TEST_CASE("Test Length String", "[002]") {
    REQUIRE(dsj::str::DigitLength(0) == 1);
    REQUIRE(dsj::str::DigitLength(3) == 1);
    REQUIRE(dsj::str::DigitLength(6) == 1);
    REQUIRE(dsj::str::DigitLength(9) == 1);
    REQUIRE(dsj::str::DigitLength(12) == 2);
    REQUIRE(dsj::str::DigitLength(999) == 3);
    REQUIRE(dsj::str::DigitLength(1234) == 4);
    REQUIRE(dsj::str::DigitLength(1234567) == 7);
    REQUIRE(dsj::str::DigitLength(123456789) == 9);
    REQUIRE(dsj::str::DigitLength(1234567890) == 10);
    REQUIRE(dsj::str::DigitLength(12345678901) == 11);
    REQUIRE(dsj::str::DigitLength(123456789012) == 12);
    REQUIRE(dsj::str::DigitLength(1234567890123) == 13);
    REQUIRE(dsj::str::DigitLength(12345678901234) == 14);
    REQUIRE(dsj::str::DigitLength(123456789012345) == 15);
    REQUIRE(dsj::str::DigitLength(1234567890123456) == 16);
    REQUIRE(dsj::str::DigitLength(12345678901234567) == 17);
    REQUIRE(dsj::str::DigitLength(123456789012345678) == 18);
    REQUIRE(dsj::str::DigitLength(1234567890123456789) == 19);
}
TEST_CASE("Performance Compare DigitLength", "[003]") {

    for (int i = 0; i < 100000; i++) {

        dsj::utils::TimeMetrics::Start("str::DigitLength");
        REQUIRE(dsj::str::DigitLength(1234567890) == 10);
        REQUIRE(dsj::str::DigitLength(12345678901) == 11);
        REQUIRE(dsj::str::DigitLength(123456789012) == 12);
        REQUIRE(dsj::str::DigitLength(1234567890123) == 13);
        REQUIRE(dsj::str::DigitLength(12345678901234) == 14);
        REQUIRE(dsj::str::DigitLength(123456789012345) == 15);
        REQUIRE(dsj::str::DigitLength(1234567890123456) == 16);
        REQUIRE(dsj::str::DigitLength(12345678901234567) == 17);
        REQUIRE(dsj::str::DigitLength(123456789012345678) == 18);
        REQUIRE(dsj::str::DigitLength(1234567890123456789) == 19);
        dsj::utils::TimeMetrics::Stop("str::DigitLength");

        dsj::utils::TimeMetrics::Start("division::DigitLength");
        REQUIRE(dsj::optimized::DigitLength(1234567890) == 10);
        REQUIRE(dsj::optimized::DigitLength(12345678901) == 11);
        REQUIRE(dsj::optimized::DigitLength(123456789012) == 12);
        REQUIRE(dsj::optimized::DigitLength(1234567890123) == 13);
        REQUIRE(dsj::optimized::DigitLength(12345678901234) == 14);
        REQUIRE(dsj::optimized::DigitLength(123456789012345) == 15);
        REQUIRE(dsj::optimized::DigitLength(1234567890123456) == 16);
        REQUIRE(dsj::optimized::DigitLength(12345678901234567) == 17);
        REQUIRE(dsj::optimized::DigitLength(123456789012345678) == 18);
        REQUIRE(dsj::optimized::DigitLength(1234567890123456789) == 19);
        dsj::utils::TimeMetrics::Stop("division::DigitLength");
    }
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str::DigitLength") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division::DigitLength") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str::DigitLength") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division::DigitLength") << std::endl;

    REQUIRE(true == true);
}
TEST_CASE("Get GetDigitAt Optimized ", "[011]") {
    for (auto index = 0; index < 10; index++) {
        cout << "GetDigitAt(9876543210, " << index << ")=" << dsj::optimized::GetDigitAt(9876543210, index) << endl;
        REQUIRE (dsj::optimized::GetDigitAt(9876543210, index) == index);
    }
}
TEST_CASE("Get GetDigitAt String ", "[012]") {
    for (auto index = 0; index < 10; index++) {
        cout << "GetDigitAt(9876543210, " << index << ")=" << dsj::str::GetDigitAt(9876543210, index) << endl;
        REQUIRE (dsj::optimized::GetDigitAt(9876543210, index) == index);
    }
}
TEST_CASE("Performance Compare GetDigitAt", "[013]") {
    for (int i = 0; i < 100000; i++) {

        dsj::utils::TimeMetrics::Start("str::GetDigitAt");
        dsj::optimized::GetDigitAt(9876543210, 5);
        dsj::utils::TimeMetrics::Stop("str::GetDigitAt");

        dsj::utils::TimeMetrics::Start("division::GetDigitAt");
        dsj::str::GetDigitAt(9876543210, 5);
        dsj::utils::TimeMetrics::Stop("division::GetDigitAt");
    }
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str::GetDigitAt") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division::GetDigitAt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str::GetDigitAt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division::GetDigitAt") << std::endl;
}
TEST_CASE("IsUniqueDigits  DivMod ", "[021]") {
    using namespace dsj::optimized;
    REQUIRE(AllDigitsUnique(9876543210) == true);
    REQUIRE(AllDigitsUnique(0) == true);
    REQUIRE(AllDigitsUnique(11) == false);
    REQUIRE(AllDigitsUnique(12) == true);
    REQUIRE(AllDigitsUnique(21) == true);
    REQUIRE(AllDigitsUnique(123) == true);
    REQUIRE(AllDigitsUnique(132) == true);
    REQUIRE(AllDigitsUnique(321) == true);
    REQUIRE(AllDigitsUnique(113) == false);
    REQUIRE(AllDigitsUnique(223) == false);
    REQUIRE(true == true);
}
TEST_CASE("IsUniqueDigits String ", "[022]") {
    using namespace dsj::str;
    REQUIRE(AllDigitsUnique(9876543210) == true);
    REQUIRE(AllDigitsUnique(0) == true);
    REQUIRE(AllDigitsUnique(11) == false);
    REQUIRE(AllDigitsUnique(12) == true);
    REQUIRE(AllDigitsUnique(21) == true);
    REQUIRE(AllDigitsUnique(123) == true);
    REQUIRE(AllDigitsUnique(132) == true);
    REQUIRE(AllDigitsUnique(321) == true);
    REQUIRE(AllDigitsUnique(113) == false);
    REQUIRE(AllDigitsUnique(223) == false);
    REQUIRE(true == true);
}
TEST_CASE("Compare IsUniqueDigits  DivMod vrs String ", "[023]") {

    for (int i = 0; i < 1000000; i++) {
        dsj::utils::TimeMetrics::Start("str");
        dsj::optimized::AllDigitsUnique(i);
        dsj::utils::TimeMetrics::Stop("str");

        dsj::utils::TimeMetrics::Start("opt");
        dsj::str::AllDigitsUnique(i);
        dsj::utils::TimeMetrics::Stop("opt");
    }

    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("opt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("opt") << std::endl;

    cout << "optimized/string : " << (double)dsj::utils::TimeMetrics::TotalTime("opt") /  (double)dsj::utils::TimeMetrics::TotalTime("opt") << endl;
}
```

--- 
#### 2  Write a function that modifies an input string, sorting the letters according to a sort order defined by a second string. 
- You may assume that every character in the input string also appears somewhere in the sort order string. 
- Make your function as fast as possible for long input strings.

- #### Example:
  - SortLetters(inputStr, “ isetlgornh”)
  - would modify the input string to “     iiisssseeettttttlgorrrnnhh”.
--- 
- #### Some general remarks on the problem:
    - Unless I am missing something this question is a STL solution
    - key point is passing input string by reference
    - STL inplace sort in reportedly the most efficient possible manner
    - using const for the sortOrder string

```
#include <string>
#include <algorithm>

namespace dsj {
    /**
     * SortLetters re arrange string characters into sorted order specificed by
     * the sortOrder string
     *
     * @param input ref <std::string>
     * @param sortOrder ref  <std::sting>
     */
    void SortLetters(std::string &input, const std::string &sortOrder) {
        std:
        sort(begin(input), end(input), [&](char a, char b) {
            int indexA = sortOrder.find(a, 0);
            int indexB = sortOrder.find(b, 0);
            return indexA < indexB;
        });
    }

}
```
---
```
using namespace std;
using namespace dsj;

TEST_CASE("Test 1 SortBy(` isetlgornh`)", "[001]") {
    string inputStr =  "sort the letters in this string";
    string sortBy = " isetlgornh";
    SortLetters(inputStr, sortBy);
    cout << inputStr << endl;
    REQUIRE(inputStr == "     iiisssseeettttttlgorrrnnhh");
}


TEST_CASE("Test Empty", "[002]") {
    string inputStr =  "";
    string sortBy = " isetlgornh";
    SortLetters(inputStr, sortBy);
    cout << inputStr << endl;
    REQUIRE(inputStr == "");
}

TEST_CASE("Test Undefined", "[003]") {
    string inputStr ;
    string sortBy = " isetlgornh";
    SortLetters(inputStr, sortBy);
    cout << inputStr << endl;
    REQUIRE(inputStr == "");
}
```
---



#### Question 3 Database Design.

#### 3a. Create card definition tables.
-	Refer to all “Hearthstone’s Standard” cards list (https://playhearthstone.com/en-us/cards?set=standard&viewMode=table) to design relational database table(s). You only need to consider card attributes shown from the card list. (Class, Mana, Attack, Health, Card Type, Rarity, Minion Type, and Keywords) 

- #### Create a card_definition table
    - Well, in real I would have a reference table for the class, type, rarity, minion type, and keywords.
```
create table card_definitions
(
	id int auto_increment primary key,
	name varchar(20) not null,
	mana int default 0 not null,
	attack int null,
	health int default 1 null,
	class int null,
	card_type int not null,
	rarity int null,
	minion_type int null,
	keywords varchar(100) null,
	constraint card_definitions_ref_minion_type_id_fk foreign key (minion_type) references ref_minion_type (id),
	constraint card_definitions_ref_rarity_id_fk foreign key (rarity) references ref_rarity (id)
);

create table card_definitions_simple
(
	id int auto_increment
		primary key,
	card_name varchar(20) not null,
	class varchar(20) not null,
	card_type varchar(20) null,
	rarity varchar(20) not null,
	minion_type varchar(20) null,
	mana int null,
	attack int null,
	health int null,
	keywords varchar(20) null
);

create table ref_card_type
(
    id   int auto_increment,
    word varchar(100) not null,
    constraint card_type_id_uindex
        unique (id),
    constraint card_type_word_uindex
        unique (word)
);

alter table ref_card_type
    add primary key (id);

// and more ref table
```
| id | card_type |
| --- | ----------- |
1|HERO
25|Minion
28|Minion - Beast
24|Minion - Demon
26|Minion - Dragon
29|Minion - Elemental
27|Minion - Mech
30|,Minion - Murloc
31|Minion - Totem
32|Spell
36|Spell - Arcane
38|Spell - Fel
33|Spell - Holy
34|Spell - Nature
35|Spell - Shadow
37|Weapon

| id | card_name | class | card_type | rarity | minion_type | mana | attack | haelth |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
3001|Big Bad Wolf|Neutral|Hero|Common||||20|
3002|Big Bad Wolf|Neutral|Hero|Common||||20|
3003|Kindly Grandmother|Neutral|Hero|Common||||20|
3004|The Crone|Neutral|Hero|Common||||30|
3005|Trembling|Neutral|Hero Power|Common|0|0|||


---
#### 3b. Create player card collection tables.
-	Design table(s) to express all card instances owned by players (card collection).
-	A player can own multiple instances of same card.
-	Deleted cards should be are marked as deleted for tracking.

The player_deck is manages the player deck of card via linking the card_definitions and the player. The player can have 
many card for the came definition and the delete column manages deleted cards from the deck without 
deleting the record

#### To select the active cards in the deck for user with id
```
select deck.player_id, def.card_name
    from blizzard.player_deck as deck, blizzard.card_definitions_simple as def
        where deck.player_id = 1
            and deck.deleted = 0
            and def.id= deck.card_id;
```
#### To select the deleted cards in the deck for user with id
```
select deck.player_id, def.card_name
    from blizzard.player_deck as deck, blizzard.card_definitions_simple as def
        where deck.player_id = 1
            and deck.deleted = 1
            and def.id= deck.card_id;
```
#### ERD
![alt text](img/3b.png)
---
#### 3c. Write analytic queries for players’ card collections.
-	##### Find out an average number of cards owned by each player.

```
forEach (ID :deck.player_id ) {
   return 
    Average ( select  count(def.card_name)
        from blizzard.player_deck as deck, blizzard.card_definitions_simple as def
            where deck.player_id = ID
                and deck.deleted = 0
                and def.id= deck.card_id order by deck.player_id ) ;
}
```

-	##### Find out which card is being deleted the most by all players and find an average time it takes for such card to be deleted by players. 

