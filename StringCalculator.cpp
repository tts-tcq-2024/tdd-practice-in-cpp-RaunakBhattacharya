#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <boost/algorithm/string.hpp> // Include Boost library for string split

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = ",\n"; // Handle newline characters as delimiters
    std::string numbersPart = getDelimiterAndNumbersPart(numbers, delimiter);
    std::vector<int> nums = splitNumbers(numbersPart, delimiter);

    std::vector<int> negatives = findNegatives(nums);
    throwIfNegatives(negatives);

    return calculateSum(nums);
}

std::string StringCalculator::getDelimiterAndNumbersPart(const std::string& numbers, std::string& delimiter) {
    if (numbers.substr(0, 2) == "//") {
        size_t pos = numbers.find('\n');
        delimiter = numbers.substr(2, pos - 2);
        return numbers.substr(pos + 1);
    }
    return numbers;
}

std::vector<int> StringCalculator::splitNumbers(const std::string& numbers, const std::string& delimiter) {
    std::vector<std::string> strNums;
    boost::split(strNums, numbers, boost::is_any_of(delimiter)); // Use Boost library to split string with multiple delimiters

    std::vector<int> nums;
    for (const auto& strNum : strNums) {
        if (!strNum.empty()) {
            nums.push_back(std::stoi(strNum));
        }
    }

    return nums;
}

std::vector<int> StringCalculator::findNegatives(const std::vector<int>& nums) {
    std::vector<int> negatives;

    for (const auto& num : nums) {
        if (num < 0) {
            negatives.push_back(num);
        }
    }

    return negatives;
}

void StringCalculator::throwIfNegatives(const std::vector<int>& negatives) {
    if (!negatives.empty()) {
        std::ostringstream oss;
        oss << "negatives not allowed: ";
        for (const auto& num : negatives) {
            oss << num << " ";
        }
        throw std::runtime_error(oss.str());
    }
}

int StringCalculator::calculateSum(const std::vector<int>& nums) {
    int sum = 0;

    for (const auto& num : nums) {
        if (num <= 1000) {
            sum += num;
        }
    }

    return sum;
}
