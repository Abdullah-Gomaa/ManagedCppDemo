#include "NativeTester.h"

#include <algorithm>
#include <numeric>
#include <iostream>

int32_t NativeTester::processInt(int32_t input)
{
    internalCounter += input;
    return input * 2;
}

double NativeTester::processDouble(double input)
{
    return input * 1.5;
}

bool NativeTester::toggleStatus(bool current)
{
    return !current;
}

std::string NativeTester::echoString(const std::string& text)
{
    return "Echo: " + text;
}

const char* NativeTester::getVersionString()
{
    return "NativeTester v1.0";
}

void NativeTester::modifyInPlace(int* val)
{
    if (val != nullptr)
    {
        *val += 10;
    }
}

void NativeTester::increment(int& val)
{
    ++val;
}

std::unique_ptr<int> NativeTester::createManagedInt(int initialValue)
{
    return std::make_unique<int>(initialValue);
}

std::vector<int> NativeTester::reverseVector(const std::vector<int>& data)
{
    std::vector<int> result = data;
    std::reverse(result.begin(), result.end());
    return result;
}

std::map<std::string, int> NativeTester::countOccurrences(const std::vector<std::string>& words)
{
    std::map<std::string, int> counts;

    for (const auto& word : words)
    {
        counts[word]++;
    }

    return counts;
}

void NativeTester::processMatrix(const std::vector<std::vector<float>>& matrix)
{
    for (const auto& row : matrix)
    {
        float sum = std::accumulate(row.begin(), row.end(), 0.0f);
        std::cout << "Row sum: " << sum << std::endl;
    }
}

std::pair<bool, std::string> NativeTester::complexTransaction(
    int id,
    const std::vector<double>& weights,
    const std::string& tag)
{
    if (weights.empty())
    {
        return { false, "Failed: weights are empty" };
    }

    double total = std::accumulate(weights.begin(), weights.end(), 0.0);

    std::string result =
        "ID=" + std::to_string(id) +
        ", Tag=" + tag +
        ", Total=" + std::to_string(total);

    return { true, result };
}