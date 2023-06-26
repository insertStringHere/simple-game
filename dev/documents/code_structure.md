# Data structures
## Tile data
| Qword | Contents |
|-------|----------|
| 0 | <ul><li>Current memory offest - 4 bytes</li><li>Tile type - 2 bits</li><li>Biome - 6 bits</li><li><div>Flags - 1 byte</div><ul><li>Has dungeon - 1 bit</li><li>Has village - 1 bit</ul></li><li>Enemy mem offset - 2 bytes</li></ul> | 
| 1 | <ul><li>X position - 4 bytes</li><li>Y position - 4 bytes</li></ul> |
| 2 | <ul><li>Top tile - 2 bytes</li><li>Bottom tile - 2 bytes</li><li>Right tile - 2 bytes</li><li>Left tile - 2 bytes</li></ul> |
| 3 | Tile graphic pointer - 8 bytes |

32 bytes per * 256 tiles high * 256 tiles wide = 2,097,152 bytes  
**2MiB of tile data**

# Load-time operations

# Runtime loop
## Gameplay loop
Runs per game tick on a separate thread. Every game tick will consist of several steps:
1. [Retrieve current input states and load them into the input register](#retrieve-the-next-input-states)
2. [Handle player movement](#handle-player-movement)
3. [Refresh currently loaded map areas, freeing memory for removed tiles](#refresh-map)
4. [Spawn new enemies if possible](#spawn-enemies)
5. [Handle enemy movement](#handle-enemy-movement)
6. [Handle attack status and timers](#handle-timers-and-scheduled-tasks)
7. [Save the current information into the next unused frame in the frame buffer.](#build-frame)
8. [Set the next frame as ready](#set-frame-as-ready)

### Retrieve the next input states
### Handle player movement
### Refresh map
### Spawn enemies
### Handle enemy movement
### Handle attack status
### Handle timers and scheduled tasks
### Build frame
### Set frame as ready
Set the next frame as ready to be displayed.

## Graphics loop
Registered to the window on a 30hz timer, runs within the message loop on the main thread.