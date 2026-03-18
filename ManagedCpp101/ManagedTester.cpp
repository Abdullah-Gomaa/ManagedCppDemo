#include "ManagedTester.h"

#include <msclr/marshal_cppstd.h>
#include <vector>
#include <string>
#include <map>
#include <memory>

ManagedTester::ManagedTester()
{
    nativeObj = new NativeTester();
}

ManagedTester::~ManagedTester()
{
    this->!ManagedTester();
}

ManagedTester::!ManagedTester()
{
    if (nativeObj != nullptr)
    {
        delete nativeObj;
        nativeObj = nullptr;
    }
}

int ManagedTester::ProcessInt(int input)
{
    return nativeObj->processInt(input);
}

double ManagedTester::ProcessDouble(double input)
{
    return nativeObj->processDouble(input);
}

bool ManagedTester::ToggleStatus(bool current)
{
    return nativeObj->toggleStatus(current);
}

System::String^ ManagedTester::EchoString(System::String^ text)
{
    std::string nativeText = msclr::interop::marshal_as<std::string>(text);
    std::string result = nativeObj->echoString(nativeText);
    return gcnew System::String(result.c_str());
}

System::String^ ManagedTester::GetVersionString()
{
    const char* version = nativeObj->getVersionString();
    return gcnew System::String(version);
}

void ManagedTester::ModifyInPlace(int% val)
{
    int temp = val;
    nativeObj->modifyInPlace(&temp);
    val = temp;
}

void ManagedTester::Increment(int% val)
{
    int temp = val;
    nativeObj->increment(temp);
    val = temp;
}

int ManagedTester::CreateManagedInt(int initialValue)
{
    std::unique_ptr<int> ptr = nativeObj->createManagedInt(initialValue);
    return *ptr;
}

array<int>^ ManagedTester::ReverseVector(array<int>^ data)
{
    std::vector<int> nativeVec;

    for each (int item in data)
    {
        nativeVec.push_back(item);
    }

    std::vector<int> result = nativeObj->reverseVector(nativeVec);

    array<int>^ managedResult = gcnew array<int>(static_cast<int>(result.size()));

    for (int i = 0; i < static_cast<int>(result.size()); ++i)
    {
        managedResult[i] = result[i];
    }

    return managedResult;
}

System::Collections::Generic::Dictionary<System::String^, int>^
ManagedTester::CountOccurrences(array<System::String^>^ words)
{
    std::vector<std::string> nativeWords;

    for each (System::String ^ word in words)
    {
        nativeWords.push_back(msclr::interop::marshal_as<std::string>(word));
    }

    std::map<std::string, int> result = nativeObj->countOccurrences(nativeWords);

    System::Collections::Generic::Dictionary<System::String^, int>^ dict =
        gcnew System::Collections::Generic::Dictionary<System::String^, int>();

    for (const auto& kv : result)
    {
        dict->Add(gcnew System::String(kv.first.c_str()), kv.second);
    }

    return dict;
}

System::Tuple<bool, System::String^>^ ManagedTester::ComplexTransaction(
    int id,
    array<double>^ weights,
    System::String^ tag)
{
    std::vector<double> nativeWeights;

    for each (double w in weights)
    {
        nativeWeights.push_back(w);
    }

    std::string nativeTag = msclr::interop::marshal_as<std::string>(tag);

    std::pair<bool, std::string> result =
        nativeObj->complexTransaction(id, nativeWeights, nativeTag);

    return gcnew System::Tuple<bool, System::String^>(
        result.first,
        gcnew System::String(result.second.c_str())
    );
}