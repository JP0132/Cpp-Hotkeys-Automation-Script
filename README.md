# C++ Hotkeys Automation Script

A script created using C++ using the Windows API to swift access to frequently used folders and application. Using MinGW to create a executable, which can then be used to automatically run the script upon computer boot-up. This script only works on Windows, currently only test on Windows 11 and 10.

- Using C++ with the Windows API.
- Employed C++ string manipulation techniques to handle file paths, and conversion of narrow string to wide strings.
- Implemented a hotkey registration method, allowing to add preferred key combinations for various actions.
- Added error handling mechanisms to manage runtime error, providing which hotkey caused the failure.
- Allow the script to run automatically upon computer boot-up.

# Requirements

- Install MinGW, and ensure it is added to the path.

# How to run it?

1. Clone the project.
2. In a terminal enter the directory as to where the file _hotkey.cpp_ is located.
3. In the terminal enter the following: _g++ hotkey.cpp -o hotkey.exe_. This will create an executable called _hotkey.exe_, change the name if need be.
4. To run it from the program, in the terminal enter: _./hotkey_. The message, Hotkey registered successfully! should appear if there are no errors.
5. To run the script automatically on startup:
   - Run this new command: _g++ -mwindows hotkey.cpp -o hotkey.exe_. This will allow the script to be executed as a application without the command prompt opening.
   - Create a shortcut of the hotkey executable.
   - Then using the keyboard shortcut _Win + R_
   - Enter _shell:startup_ in the dialog.
   - In the folder it opened, move the shortcut into the file.
