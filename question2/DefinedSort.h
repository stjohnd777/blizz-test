//
// Created by Daniel St. John on 3/5/21.
//
#pragma once

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

