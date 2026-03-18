using System;
using System.Collections.Generic;

namespace CsTesterApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("We are C# .NET and using the C++/CLI wrapper!");

            ManagedTester tester = new ManagedTester();

            // 1) Primitive types
            int intResult = tester.ProcessInt(10);
            Console.WriteLine($"ProcessInt(10) = {intResult}");

            double doubleResult = tester.ProcessDouble(8.0);
            Console.WriteLine($"ProcessDouble(8.0) = {doubleResult}");

            bool toggled = tester.ToggleStatus(true);
            Console.WriteLine($"ToggleStatus(true) = {toggled}");

            Console.WriteLine();

            // 2) Strings
            string echoed = tester.EchoString("Hello from C# managed code");
            Console.WriteLine($"EchoString = {echoed}");

            string version = tester.GetVersionString();
            Console.WriteLine($"GetVersionString = {version}");

            Console.WriteLine();

            // 3) Ref-style methods
            int a = 5;
            Console.WriteLine($"Before ModifyInPlace: {a}");
            tester.ModifyInPlace(ref a);
            Console.WriteLine($"After ModifyInPlace:  {a}");

            int b = 20;
            Console.WriteLine($"Before Increment: {b}");
            tester.Increment(ref b);
            Console.WriteLine($"After Increment:  {b}");

            int managedInt = tester.CreateManagedInt(123);
            Console.WriteLine($"CreateManagedInt(123) = {managedInt}");

            Console.WriteLine();

            // 4) Reverse array
            int[] numbers = { 1, 2, 3, 4, 5 };
            int[] reversed = tester.ReverseVector(numbers);

            Console.Write("ReverseVector = ");
            foreach (int n in reversed)
            {
                Console.Write($"{n} ");
            }
            Console.WriteLine();
            Console.WriteLine();

            // 5) Count occurrences
            string[] words =
            {
                "apple", "banana", "apple", "orange", "banana", "apple"
            };

            Dictionary<string, int> counts = tester.CountOccurrences(words);

            Console.WriteLine("CountOccurrences:");
            foreach (KeyValuePair<string, int> kv in counts)
            {
                Console.WriteLine($"  {kv.Key} -> {kv.Value}");
            }

            Console.WriteLine();

            // 6) Complex transaction
            double[] weights = { 1.5, 2.25, 3.75 };
            Tuple<bool, string> txResult = tester.ComplexTransaction(42, weights, "SampleTag");

            Console.WriteLine($"ComplexTransaction success = {txResult.Item1}");
            Console.WriteLine($"ComplexTransaction message = {txResult.Item2}");

            Console.WriteLine();
            Console.WriteLine("Press Enter to exit...");
            Console.ReadLine();
        }
    }
}