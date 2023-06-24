# Data structures

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