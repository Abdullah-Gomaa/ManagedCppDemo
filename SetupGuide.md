#  Setup Project Guide

1. Convert current C++/CLI project to DLL
2. Remove C++ `main.cpp`
3. Add C# Console App
4. Add project reference from C# to C++/CLI project
5. Paste the `Program.cs` above
6. Build solution
7. Set C# app as startup project
8. Run

----------------------------------------------------------------------------------

# Detailed Steps

# 1. How to set this up in your current Visual Studio solution

## Step A — keep current C++ project

Your current `ManagedCpp101` project stays as the wrapper project.

It should contain:

* native class
* managed wrapper

## Step B — remove C++ main

Remove `main.cpp` from build, or delete it.

If you keep a `main.cpp`, then that project is still trying to build an exe, which you no longer want.

---

# 2. Change the C++/CLI project to a Class Library

In the C++/CLI project:

### Project Properties

* **Configuration Properties > General**

  * **Configuration Type** = `Dynamic Library (.dll)`

* **Configuration Properties > General**

  * **Common Language Runtime Support** = `/clr`

### File-specific

For `NativeTester.cpp`:

* **C/C++ > General**

  * **Common Language Runtime Support** = `No Common Language Runtime Support`

For `ManagedTester.cpp`:

* keep `/clr`

This gives you:

* native implementation compiled natively
* wrapper compiled as managed C++/CLI
* final output = DLL usable by C#

---

# 3. Add a C# console app to the same solution

In Visual Studio:

* Right click **Solution**
* **Add**
* **New Project**
* choose **Console App (C#)**

Name it something like:

* `CsTesterApp`

---

# 4. Reference the C++/CLI project from C#

In the C# project:

* Right click **Dependencies** or **References**
* **Add Project Reference**
* check your `ManagedCpp101` project
* press OK

Now C# can use `ManagedTester`
