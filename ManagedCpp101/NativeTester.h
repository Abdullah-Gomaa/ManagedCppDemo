#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <cstdint>
#include <utility>

class NativeTester
{
public:
    NativeTester() = default;
    ~NativeTester() = default;

    int32_t processInt(int32_t input);
    double processDouble(double input);
    bool toggleStatus(bool current);

    std::string echoString(const std::string& text);
    const char* getVersionString();

    void modifyInPlace(int* val);
    void increment(int& val);
    std::unique_ptr<int> createManagedInt(int initialValue);

    std::vector<int> reverseVector(const std::vector<int>& data);
    std::map<std::string, int> countOccurrences(const std::vector<std::string>& words);
    void processMatrix(const std::vector<std::vector<float>>& matrix);

    std::pair<bool, std::string> complexTransaction(
        int id,
        const std::vector<double>& weights,
        const std::string& tag
    );

private:
    int32_t internalCounter = 0;
};