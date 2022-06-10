You could simply put the folder code into your IDE and run this program
OR you could run the code in your terminal:

1. Compile
(1) If your computer system is Windows:
    mingw32-make 
(2) If your computer system is macOS/Linux:
    make
(3) or you could compile as follows:
    g++ main.cpp player.cpp map.cpp -o result

2. Execute
(1) If your computer system is Windows:
./result

3. If you want to remove the .o files and recompile:
(1) If your computer system is Windows:
    del *.o
    del result.exe
(2) If your computer system is macOS/Linux:
    make clean