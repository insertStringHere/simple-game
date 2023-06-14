# Introduction
This is a high level outline of what I want to have in the game, a list of all requirements and components for the initial release that I'll go into implementation outlines for later. For now, this will work for creating a plan on what needs to be researched and what I can make without needing prototypes or experimentation.

# The Game
## Generalized description
The game will be a simple roguelite with the goal of delving into 8 dungeons and retrieving the gems at the center, and optionally the skills that also may or may not be located within the dungeons. Starting the game will either reload the old world or generate a new one if the old save doesn't exist, dying will create a new world, and collecting the 8th gem will give the player the option to generate a new world.

## Gameplay
Gameplay will be real-time, working with arrow keys, heavily inspired by zelda 1. Different weapons will have different swing speeds, ranges, and damage. The world will be split into multiple biomes, each spawning a set of enemies wanting to kill the player. 

## The world
The world will, as of now, consist of up to 15 biomes that can be generated deterministically from a seed as a function of the x,y coords of the space. The 16th biome will generate a dungeon where one of the gems can be taken

## The player

### Stats

### Abilities

### Weapons
The player will be able to equip one weapon item, each having a unique range and a random value for damage and speed calculated from 0-15 centered on a base stat.
Weapons can additionally have a boost to one of the player's other stats.

| Weapon Name | Attack range | Base damage | Base speed |
|-------------|--------------|-------------|------------|
| Sword | Directly in front  | 7 | 9 |
| Axe | Three tiles wide | 13 | 4 |
| Dagger | One tile in front | 3 | 14 |
| Hammer | five tiles wide in a U shape | 14 | 1 |  
| lance | two tiles out | 6 | 8 |

### Armor

### Items

## Enemies

### Pathfinding algorithm

### List
