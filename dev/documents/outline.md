# Introduction
This is a high level outline of what I want to have in the game, a list of all requirements and components for the initial release that I'll go into implementation outlines for later. For now, this will work for creating a plan on what needs to be researched and what I can make without needing prototypes or experimentation.

# The Game
## Generalized description
The game will be a simple roguelite with the goal of delving into 8 dungeons and retrieving the gems at the center, and optionally the skills that also may or may not be located within the dungeons. Starting the game will either reload the old world or generate a new one if the old save doesn't exist, dying will create a new world, and collecting the 8th gem will give the player the option to generate a new world.

## Gameplay
Gameplay will be real-time, working with arrow keys, heavily inspired by zelda 1. Different weapons will have different swing speeds, ranges, and damage. The world will be split into multiple biomes, each spawning a set of enemies wanting to kill the player. 

## The world
The world will, as of now, consist of up to 16 biomes that can be generated deterministically from a seed as a function of the x,y coords of the space. Each biome can generate a dungeon where one of the gems can be taken. Different biomes can have different hazards which will require the player to gain certain abilities first.

Possibly villages could be added in the future, with quests from villagers for better tools or guidance; not currently in scope.

Each biome will have two types of tiles: land and wall. Different wall tiles will have different abilities that could pass through them.

See the [graphics outline](./art_assets.md#tiles) for the tile graphics.

### Biomes
| Name | Hazard | Wall | Wall Pass Ability | Village? | Gem? |
|------|--------|------|-------------------|----------|------|
| Forest | None | Tree | None | Yes | Nature |
| Mountain | None | Mountain | Climbing | No | Earth |
| Swamp | None | Swamp | Passable | No | No |
| Lava flats | Fireproof | Lava lakes | None | No | Fire |
| Tundra | Cold Resistance | Ice Mountains | Climbing | No | Water |
| Ocean | None | Ocean | Water-walking | Yes | No |
| Cursed | Blessing | Ruins | None | No | Darkness |
| Meadow | None | None | None | Yes | No |
| Blessed Plains | Shadow Veil | None | None | No | Light |
| Graveyard | None | Graves | None | No | No |
| Desert | None | Sand Dunes | Passable | Yes | No |
| Sand-swept ruins | None | Ruins | None | No | Spirit |
| Wicked Spires | Magic Traction | Mountain Spires | None | No | Wind |  
 
### Dungeons
Dungeons are randomly generated using tile-based room-gen, stretching outwards from a starting point. They'll always have an ability room, alongside a gem room if one spawns for the biome. When the player already has the ability/gem, nothing will spawn.

## The player

### Stats
Player stats are impacted by the gear they have. Values will go from 0 to 255.

| Name | Impact | Default |
|------|--------|---------|
| Health | How much health the entity has, at 0 they will die. | 20 |
| Hunger | Food will contribute to natural regeneration of health, decaying slowly over time and quickly while replenishing health. Hitting zero will start causing the player damage when they try to heal | 20 |
| Strength | Raw attack bonus, adds a percent bonus to attack value | 0 |
| Dexterity | Chance to dodge an attack, modifies how quickly hunger depletes | 0 |
| Charisma | Affects shop prices and likelyhood of enemies aggroing | 0 |
| Luck | increase chance for beneficial drops | 0 | 

### Abilities
Abilities will be found somewhere in a dungeon, each dungeon having one random one for the players to unlock.  

| Name | Ability |
|------|---------|
| Climbing | Allows player to climb (walk on) mountain tiles |
| Fireproof | Allows player to walk in lava flats biome |
| Cold Resistence | Allows player to walk in Tundra biomes |
| Water-walking | Allows the player to walk on ocean water tiles |
| Blessing | Allows walking in cursed biomes |
| Shadow Veil | Allows walking in blessed biomes |
| Magic traction | Allows walking in windy biomes |
| Charge | Allows player to charge an attack - double the swing time for triple the damage |
| Dash | Allows a dash in any direction with a cooldown based on weapon swing time |
| Stealth movement | After not moving for a certain amount of time, player will become invisible to enemies |
| Parry/Block | A button input to counter a percent of enemy damage if timed right, or prevent damage to the player at the cost of food |

### Weapons
The player will be able to equip one weapon item, each having a unique range and a random value for damage and speed calculated from 0-15 centered on a base stat.
Weapons can additionally have a boost to one of the player's other stats.

See the [graphics outline](./art_assets.md#weapon-sprites-and-animations) for the weapon icons and animations.

| Weapon Name | Attack range | Base damage | Base speed |
|-------------|--------------|-------------|------------|
| Sword | One tile in front  | 7 | 9 |
| Axe | Three tiles wide | 13 | 4 |
| Dagger | One tile in front | 3 | 14 |
| Hammer | Five tiles wide in a U shape | 14 | 1 |  
| Lance | Two tiles out | 6 | 8 |
| Rapier | One tile in front | 4; ignores defense | 9 | 
| Bow | Up to 10 tiles in front or until hitting a wall | 6 | cannot be fired again until the last arrow despawns |

### Armor
Player armor will provide a defense bonus (damage reduction) from 1-16, with 16 being 75% damage reduction, alongside a bonus stat to one of the player's abilities.

### Charms
Players will have a slot for a charm which will add up to three bonus stats to the player.

### Items
Items will be one use items with a variety of potential effects. Only one stat boost can be active at a time. Items will occasionally be dropped by enemies.

See the [graphics outline](./art_assets.md#item-sprites) for the item sprites.

| Name | Effect |
|------|--------|
| Lesser Healing Potion | Restores 5 health on use |
| Greater Healing Potion | Restores 15 health on use |
| Ration | Restores 10 hunger on use | 
| Meal | Restores 20 hunger on use |
| Teleportation Scroll | Teleports the player to a random location |
| Dungeon Teleportation Scroll | Teleports the player to a random dungeon |
| Village Teleportation Scroll | Teleports the player to a random village |
| Strength Enhancement Potion | Increases player strength by 3 for one minute of game-time |
| Dexterity Enhancement Potion | Increases player dexterity by 3 for one minute of game-time |
| Charisma Enhancement Potion | Increases player charisma by 3 for one minute of game-time |
| Luck Enhancement Potion | Increases player luck by 3 for one minute of game-time |

## Enemies
Enemies will spawn randomly throughout the world, depending on the biome. Some will spawn in multiple biomes, some only in one, and some only in dungeons. All enemies will have an underlying set of ability stats, the same as the player. Different enemies will use different AI algorithms.

See the [graphics outline](./art_assets.md#entity-sprites) for the enemy sprites.

### AI algorithm

- Wanderer
	- Wanders randomly when not aggro on player
	- Does not aggro on player
- Seeker
	- Wanders randomly until player is within aggro range
	- Pathfinds to player when within range
	- Deals contact damage, waiting for a few seconds before resuming pursuit
- Spitter
	- Wanders randomly when not aggro on player
	- Pathfinds away from player to a distance smaller than aggro range
	- Fires a projectile, waiting for it to despawn to retreat again 
- Weapon
	- Patrols until player is within aggro range
	- Pathfinds to player when within range
	- Uses a randomly generated weapon, same as a player would use with the same rules.
- Advanced
	- Stands still until player is within aggro range
	- Pathfinds to player when within range
	- Uses a randomly generated weapon, same as a player would use with the same rules
	- Capable of retreating and using a randomly generated set of player active skills

### List

| Name | AI | Health | Strength | Dexterity | Biomes |
|------|----|--------|----------|-----------|--------|
| Lava Slime | Seeker | 8 | 3 | 0 | Lava Flats |
