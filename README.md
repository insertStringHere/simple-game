# simple-game
A simple roguelite game for windows written primarily in assembly.

# The Goals
Less than making a functional game, theres a few things I want to learn while doing this project.  
progression might be slow, and the game might never actually get finished at all. I'm going to keep all progress, from game and planning documentation to discovery prototypes, in this repository, so the project might get messier than it actually is.  
For the actual game, here are the desired components:
- A randomly generated world
- randomly generated enemies and loot
- dungeons existing within the world
- real-time gameplay, probably on a grid-based tile system
- perma-death

# The Technical Stuff
I want to make this game as low level and as contained as possible, preferably having only one executable file and nothing additional even after the game is run. As a result, this game will only be runnable on 64 bit windows.    
# The Learning Objectives 
Being a learning experience, here are the primary things I seek to learn better
with this project

[ ] Larger x86 assembly projects 
[ ] Packing resources into an executable to be called directly from ROM
[ ] A way to communicate with a graphics card (probably GDI+ or Direct2D, need more research)
[ ] Sound.
[ ] Planning a game engine from scratch and working to be minimal but efficient with qword memory
[ ] Creating a procedural worldgen algorithm
[ ] Implementing pathfinding 
[ ] Using the registry for save-data and an auto save system 
