##Uruk-Store
This is a store application that built on top of apt,
This Application created for uruk distro, but feel free to use it on any distro.
#requirement 
1. gcc
2. build-essential 
3. cmake
4. gtk & gtkmm 3
5. apt
## How to run 

```bash
cmake .
make
sudo ./UrukStore
```
## Project Structure
Headers : The Headers  Of the Main Project
------- Base : The Headers Of The Base Classes
------- Component : The Headers of Classes That Hold Gtk Component like card etc ...
------- Pages : The Headers of the Classes That Work As Pages like Main Page , Setting, App Pages
_____________________________________________________________________________________________
Source : The Source File of The Main Project
------- Base :  The Base Classes
------- Component : Classes That Hold Gtk Component like card etc ...
------- Pages :  Classes That Work As Pages like Main Page , Setting, App Pages
_____________________________________________________________________________________________
Ui: The File That Used By Gtk Builder To Create the Graphical User Interface  
-------Assets: 
-------------Css : Hold The Css Files
-------------Icons: Hold The Icons
-------Pages: Hold The Glade Files
_____________________________________________________________________________________________
Packages: Hold The Source Of The Library Used By The Main Application
--------Apt : Hold The File of the Library That Used to Deal With Apt Get and it's Packages
--------Variety: Hold Library That Contain Variety of method to deal with file command line strings etc
