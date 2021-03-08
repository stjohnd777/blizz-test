#include <iostream>

#include "question1/UniqueDigits.h"
#include "question2/DefinedSort.h"

#include "test/utils/TimeMetric.hpp"
#include <iostream>

using namespace std;
using namespace dsj;

int main() {

    string inputStr =  "sort the letters in this string";
    string sortBy = " isetlgornh";
    SortLetters(inputStr, sortBy);
    cout << inputStr << endl;

    long counter0 =0;
    dsj::utils::TimeMetrics::Start("opt");
    for (unsigned long i = 0; i <= 100000; i++) {
        auto b = dsj::optimized::AllDigitsUnique(i);
        if ( b) {
            counter0++;
            std::cout <<  (double)i/(double)9876543210 * 100.0 << "% IsUniqueDigits(" << i << ") =" << b << std::endl;
        }
    }
    dsj::utils::TimeMetrics::Stop("opt");

    long counter1 =0;
    dsj::utils::TimeMetrics::Start("str");
    for (unsigned long i = 0; i  <= 100000; i++) {
        auto b = dsj::str::AllDigitsUnique(i);
        if ( b) {
            counter1++;
            std::cout <<   (double)i/(double)9876543210 * 100.0 << "% IsUniqueDigits(" << i << ") =" << b << std::endl;
        }
    }
    dsj::utils::TimeMetrics::Stop("str");

    cout << "Total:" << counter0 << ":" << dsj::utils::TimeMetrics::TotalTime("opt") << std::endl;
    cout << "Total:" << counter1 << ":" << dsj::utils::TimeMetrics::TotalTime("str") << std::endl;



    return 0;
}
