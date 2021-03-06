#include <iostream>
#include <array>
#include <set>
#include <algorithm>

#include "UniqueDigitsQuestion.h"
#include "SortQuestion.h"

#include "./test/TimeMetric.hpp"
#include <iostream>

using namespace std;
using namespace dsj;

int main() {

    long integer = 9876543210;

    long counter0 =0;
    dsj::utils::TimeMetrics::Start("opt");
    for (unsigned long i = 0; i <= 9876543210; i++) {
        auto b = dsj::optimized::hasUniqueDigits(i);
        if ( b) {
            counter0++;
            std::cout <<  (double)i/(double)9876543210 * 100.0 << "% hasUniqueDigits(" << i << ") =" << b << std::endl;
        }
    }
    dsj::utils::TimeMetrics::Stop("opt");

    long counter1 =0;
    dsj::utils::TimeMetrics::Start("str");
    for (unsigned long i = 0; i  <= 9876543210; i++) {
        auto b = dsj::str::hasUniqueDigits(i);
        if ( b) {
            counter1++;
            std::cout <<   (double)i/(double)9876543210 * 100.0 << "% hasUniqueDigits(" << i << ") =" << b << std::endl;
        }
    }
    dsj::utils::TimeMetrics::Stop("str");

    cout << "Total:" << counter0 << ":" << dsj::utils::TimeMetrics::TotalTime("opt") << std::endl;
    cout << "Total:" << counter1 << ":" << dsj::utils::TimeMetrics::TotalTime("str") << std::endl;
    return 0;
}
