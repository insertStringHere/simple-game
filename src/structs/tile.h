typedef struct Tile Tile;

/**
 * Represents a single Tile on the world map. Contains information about itself, links to surrounding Tiles, and the entity currently located on it.
 * All memory is relative to the memory stores. 
*/
struct Tile {
    /* First qword - informational data  */
    unsigned int offset; ///< This Tile's offset within the Tile memory store
    union dword_two {
        struct flagData {
            unsigned char type: 2; ///< A flag for the type of Tile: floor/wall
            unsigned char biome: 6; ///< A flag for the type of biome
            unsigned char hasDungeon: 1; ///< A flag for whether or not this Tile has a dungeon
            unsigned char hasVillage: 1; ///< A flag for whether or not this Tile has a village
            unsigned char unusedFlags: 6; ///< The remainder of the Tile's flag byte, currently unused.
            unsigned short enemyOffset; ///< The Enemy's offset within the Entity memory store
        } flagData;
        unsigned int nextPointer; ///< Pointer to the next Tile in the free queue
    } d2; ///< A union for referencing the second dword of data. When in the free queue, this value becomes the offset to the next in the linked list.
          ///< When representing a tile, this dword represents flag data.
        
    /* Second qword - Tile position */
    int xPos; ///< The x position of the Tile on the world grid
    int yPos; ///< The y position of the Tile on the world grid
    
    /* Third qword - adjacent Tile pointers */
    unsigned short top; ///< A reference to the Tile directly above this one
    unsigned short bot; ///< A reference to the Tile directly below this one
    unsigned short left; ///< A reference to the Tile directly left of this one
    unsigned short right; ///< A reference to the Tile directly right of this one

    /* Fourth qword - graphics reference data */
    void* graphic; ///< A reference to the Tile's base image to reduce total number of lookups per frame. Only contains Tile graphic, not dungeon, village, or entity
}  __attribute__((packed));


