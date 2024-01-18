PROGRAM AUTHOR: Mohamad (Momo) Radaideh 101292701
PURPOSE: Create a Server/Client project using Sockets.
SOURCE FILES: connect.c, defs.h, escape.c, flyer.c, hero.c, spectator.c, view.c (aswell as this README.txt file, and a makefile)
LAUNCH INSTRUCTIONS: 1. Open a terminal in this directory. Then run the following command: `make` Object files will be made
                     2. Then in terminal, enter `./a5` to run the server first.
                     3. In a seperate terminal in the same directory, run `./a5 127.0.0.1` to run client. (the ip address is to connect to same machine)
                     4. Watch program run.
                     Note: Server must be running before client or else client will never connect nor simulation will properly run.
                     5. After testing, use `make clean` to remove all object files.