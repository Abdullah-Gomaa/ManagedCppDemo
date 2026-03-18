#pragma once

#pragma managed(push, off)
#include "NativeTester.h"
#pragma managed(pop)

public ref class ManagedTester
{
private:
    NativeTester* nativeObj;

public:
    ManagedTester();
    ~ManagedTester();
    !ManagedTester();

    int ProcessInt(int input);
    double ProcessDouble(double input);
    bool ToggleStatus(bool current);

    System::String^ EchoString(System::String^ text);
    System::String^ GetVersionString();

    void ModifyInPlace(int% val);
    void Increment(int% val);
    int CreateManagedInt(int initialValue);

    array<int>^ ReverseVector(array<int>^ data);

    System::Collections::Generic::Dictionary<System::String^, int>^
        CountOccurrences(array<System::String^>^ words);

    System::Tuple<bool, System::String^>^ ComplexTransaction(
        int id,
        array<double>^ weights,
        System::String^ tag
    );
};