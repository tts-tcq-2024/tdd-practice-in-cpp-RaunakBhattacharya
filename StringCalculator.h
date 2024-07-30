#include <string>
#include <vector>

class StringCalculator {
public:
    int Add(const std::string& numbers);
private:
    std::vector<int> splitNumbers(const std::string& numbers, const std::string& delimiter);
    std::string getDelimiterAndNumbersPart(const std::string& numbers, std::string& delimiter);
    int calculateSum(const std::vector<int>& nums);
};
