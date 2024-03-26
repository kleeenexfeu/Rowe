#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "constants/pokemon.h"
#include "constants/species.h"
#include "sprite.h"
#include "constants/region_map_sections.h"
#include "constants/pokemon_config.h"
#include "constants/map_groups.h"

struct BoxPokemon
{
    u32 personality;
    u32 otId;
    u32 experience:24;
    u32 friendship:8;
    
    u16 species;
    u16 heldItem;
    
    u16 move1;
    u16 move2;
    u16 move3;
    u16 move4;

    u8 hpEV;
    u8 attackEV;
    u8 defenseEV;
    u8 speedEV;
    u8 spAttackEV;
    u8 spDefenseEV;
    
    u32 hpIV:5;
    u32 attackIV:5;
    u32 defenseIV:5;
    u32 speedIV:5;
    u32 spAttackIV:5;
    u32 spDefenseIV:5;
    u32 abilityNum:2;
    
    u16 customAbility:9;
    u16 hidden_nature:5;
    
    u8 customHp;
    u8 customAtk;
    u8 customDef;
    u8 customSpeed;
    u8 customSpAtk;
    u8 customSpDef;
    u8 customType1;
    u8 customType2;
    
    u16 formId:5;
    u16 pokeball:5; //31 balls
    u16 pokeballGen3:4;// For compatibility 
    u16 isEgg:1;
    u16 exiolite:1;

    u8 ppBonuses;
    
    u8 ppmove1;
    u8 ppmove2;
    u8 ppmove3;
    u8 ppmove4;
    u8 metLocation;
    u8 pokerus;
    u8 nickname[POKEMON_NAME_LENGTH];
    u8 otName[PLAYER_NAME_LENGTH];
    u8 markings;

    u8 cool;
    u8 beauty;
    u8 cute;
    u8 smart;
    u8 tough;

    u32 coolRibbon:3;
    u32 beautyRibbon:3; 
    u32 cuteRibbon:3; 
    u32 smartRibbon:3; 
    u32 toughRibbon:3;
    u32 championRibbon:1;
    u32 winningRibbon:1;
    u32 victoryRibbon:1;
    u32 artistRibbon:1;
    u32 effortRibbon:1;
    u32 metLevel:7;
    u32 otGender:1;
    u32 isTainerMon:1;
    u32 fillerAgain:3;
};

struct Pokemon
{
    struct BoxPokemon box;
    u16 status; // u16 probably enough, because only non-volatile statuses are stored here, rest is only for the BattleMons structure
    u16 hp;
    u16 maxHP;
    u8 level;
};

struct CompressedBattlemon
{
    /* 0x00 */ u16 species;
    /* 0x02 */ u16 heldItem:10;
    /* 0x02 */ u16 nature:5;
    /* 0x02 */ u16 exiolite:1;
    /* 0x04 */ u32 hpIV:5;
    /* 0x04 */ u32 attackIV:5;
    /* 0x04 */ u32 defenseIV:5;
    /* 0x04 */ u32 spAttackIV:5;
    /* 0x04 */ u32 spDefenseIV:5;
    /* 0x04 */ u32 speedIV:5;
    /* 0x04 */ u32 otGender:1;
    /* 0x04 */ u32 shinyness:1;
    /* 0x08 */ u8 hpEV;
    /* 0x09 */ u8 attackEV;
    /* 0x0A */ u8 defenseEV;
    /* 0x0B */ u8 speedEV;
    /* 0x0C */ u8 spAttackEV;
    /* 0x0D */ u8 spDefenseEV;
    /* 0x0E */ u8 level;
    /* 0x0F */ u32 moves1:10;
    /* 0x0F */ u32 moves2:10;
    /* 0x0F */ u32 moves3:10;
    /* 0x0F */ u32 abilityNum:2;
    /* 0x13 */ u16 moves4:10;
    /* 0x13 */ u16 pokeball:5;
    /* 0x13 */ u16 filler:1;
};

struct CompressedPlayerParty
{
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    struct CompressedBattlemon CompressedParty[PARTY_SIZE];
    u8 trainerGender:1;
    u8 trainerCostume:3;
    u8 redColor:4;
    u8 blueColor:4;
    u8 greenColor:4;
    u8 partySize:3;
    u8 title:5;
};

// Passwords pokemon will be messed up because of how the structure was changed
struct CompressedPokemon
{
    /* 0x00 */ u32 personality;
    /* 0x04 */ u32 otId;
    /* 0x08 */ u8 otName[PLAYER_NAME_LENGTH];

    u32 species:11;
    u32 customAbility:9;
    u32 heldItem:10;
    u32 exiolite:1;
    u32 isTrainerMon:1;

    u32 moves1:10;
    u32 moves2:10;
    u32 moves3:10;
    u32 abilityNum:2;

    u32 hpIV:5;
    u32 attackIV:5;
    u32 defenseIV:5;
    u32 spAttackIV:5;
    u32 spDefenseIV:5;
    u32 speedIV:5;
    u32 otGender:1;
    u32 filler:1;

    u32 level:7;
    u32 moves4:10;
    u32 pokeball:5;
    u32 nature:5;
    u32 formId:5;

    u8 hpEV;
    u8 attackEV;
    u8 defenseEV;
    u8 speedEV;

    u8 spAttackEV;
    u8 spDefenseEV;
    u8 customHp;
    u8 customAtk;

    u8 customDef;
    u8 customSpeed;
    u8 customSpAtk;
    u8 customSpDef;

    u8 customType1;
    u8 customType2;
};

// Flags for Get(Box)MonData / Set(Box)MonData
enum {
    MON_DATA_PERSONALITY,
    MON_DATA_OT_ID,
    MON_DATA_NICKNAME,
    MON_DATA_LANGUAGE,
    MON_DATA_SANITY_IS_BAD_EGG,
    MON_DATA_SANITY_HAS_SPECIES,
    MON_DATA_SANITY_IS_EGG,
    MON_DATA_OT_NAME,
    MON_DATA_MARKINGS,
    MON_DATA_SPECIES,
    MON_DATA_HELD_ITEM,
    MON_DATA_MOVE1,
    MON_DATA_MOVE2,
    MON_DATA_MOVE3,
    MON_DATA_MOVE4,
    MON_DATA_PP1,
    MON_DATA_PP2,
    MON_DATA_PP3,
    MON_DATA_PP4,
    MON_DATA_PP_BONUSES,
    MON_DATA_COOL,
    MON_DATA_BEAUTY,
    MON_DATA_CUTE,
    MON_DATA_EXP,
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPATK_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_FRIENDSHIP,
    MON_DATA_SMART,
    MON_DATA_POKERUS,
    MON_DATA_MET_LOCATION,
    MON_DATA_MET_LEVEL,
    MON_DATA_MET_GAME,
    MON_DATA_POKEBALL,
    MON_DATA_HP_IV,
    MON_DATA_ATK_IV,
    MON_DATA_DEF_IV,
    MON_DATA_SPEED_IV,
    MON_DATA_SPATK_IV,
    MON_DATA_SPDEF_IV,
    MON_DATA_IS_EGG,
    MON_DATA_ABILITY_NUM,
    MON_DATA_TOUGH,
    MON_DATA_SHEEN,
    MON_DATA_OT_GENDER,
    MON_DATA_COOL_RIBBON,
    MON_DATA_BEAUTY_RIBBON,
    MON_DATA_CUTE_RIBBON,
    MON_DATA_SMART_RIBBON,
    MON_DATA_TOUGH_RIBBON,
    MON_DATA_STATUS,
    MON_DATA_LEVEL,
    MON_DATA_HP,
    MON_DATA_MAX_HP,
    MON_DATA_ATK,
    MON_DATA_DEF,
    MON_DATA_SPEED,
    MON_DATA_SPATK,
    MON_DATA_SPDEF,
    MON_DATA_MAIL,
    MON_DATA_SPECIES2,
    MON_DATA_IVS,
    MON_DATA_CHAMPION_RIBBON,
    MON_DATA_WINNING_RIBBON,
    MON_DATA_VICTORY_RIBBON,
    MON_DATA_ARTIST_RIBBON,
    MON_DATA_EFFORT_RIBBON,
    MON_DATA_OBEDIENCE,
    MON_DATA_RIBBON_COUNT,
    MON_DATA_RIBBONS,
    MON_DATA_ATK2,
    MON_DATA_DEF2,
    MON_DATA_SPEED2,
    MON_DATA_SPATK2,
    MON_DATA_SPDEF2,
    MON_DATA_HIDDEN_NATURE,
    MON_DATA_CUSTOM_HP,
    MON_DATA_CUSTOM_ATK,
    MON_DATA_CUSTOM_DEF,
    MON_DATA_CUSTOM_SPEED,
    MON_DATA_CUSTOM_SPATK,
    MON_DATA_CUSTOM_SPDEF,
    MON_DATA_CUSTOM_ABILITY,
    MON_DATA_CUSTOM_TYPE1,
    MON_DATA_CUSTOM_TYPE2,
    MON_DATA_ABILITY,
    MON_DATA_TYPE1,
    MON_DATA_TYPE2,
    MON_DATA_KNOWN_MOVES,
    MON_DATA_EXIOLITE_ENABLED,
    MON_DATA_FORM_ID,
    MON_DATA_IS_TRAINER_MON, // in new game +, trainers mon' stats are calculated a little different
};

struct Unknown_806F160_Struct
{
    u32 field_0_0:4;
    u32 field_0_1:4;
    u32 field_1:8;
    u16 magic:8;
    u32 field_3_0:4;
    u32 field_3_1:4;
    void *bytes;
    u8 **byteArrays;
    struct SpriteTemplate *templates;
    struct SpriteFrameImage *frameImages;
};

struct BattlePokemon
{
    /*0x00*/ u16 species:11;
	/*0x01*/ u16 formId:5;
    /*0x02*/ u16 attack;
    /*0x04*/ u16 defense;
    /*0x06*/ u16 speed;
    /*0x08*/ u16 spAttack;
    /*0x0A*/ u16 spDefense;
    /*0x0C*/ u16 moves[MAX_MON_MOVES];
    /*0x14*/ u32 hpIV:5;
    /*0x14*/ u32 attackIV:5;
    /*0x15*/ u32 defenseIV:5;
    /*0x15*/ u32 speedIV:5;
    /*0x16*/ u32 spAttackIV:5;
    /*0x17*/ u32 spDefenseIV:5;
    /*0x17*/ u32 abilityNum:2;
    /*0x18*/ s8 statStages[NUM_BATTLE_STATS];
    /*0x20*/ u16 ability;
    /*0x22*/ u8 type1;
    /*0x23*/ u8 type2;
    /*0x24*/ u8 type3;
    /*0x25*/ u8 pp[MAX_MON_MOVES];
    /*0x29*/ u16 hp;
    /*0x2B*/ u8 level;
    /*0x2C*/ u8 friendship;
    /*0x2D*/ u16 maxHP;
    /*0x2F*/ u16 item;
    /*0x31*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x3C*/ u8 ppBonuses;
    /*0x3D*/ u8 otName[PLAYER_NAME_LENGTH + 1];
    /*0x45*/ u32 experience;
    /*0x49*/ u32 personality;
    /*0x4D*/ u32 status1;
    /*0x51*/ u32 status2;
    /*0x55*/ u32 otId;
};

struct BaseStats
{
 /* 0x00 */ u8 baseHP;
 /* 0x01 */ u8 baseAttack;
 /* 0x02 */ u8 baseDefense;
 /* 0x03 */ u8 baseSpeed;
 /* 0x04 */ u8 baseSpAttack;
 /* 0x05 */ u8 baseSpDefense;
 /* 0x06 */ u8 type1;
 /* 0x07 */ u8 type2;
 /* 0x08 */ u8 catchRate;
 /* 0x09 */ u16 expYield;
 /* 0x0A */ u16 evYield_HP:2;
 /* 0x0A */ u16 evYield_Attack:2;
 /* 0x0A */ u16 evYield_Defense:2;
 /* 0x0A */ u16 evYield_Speed:2;
 /* 0x0B */ u16 evYield_SpAttack:2;
 /* 0x0B */ u16 evYield_SpDefense:2;
 /* 0x0C */ u16 item1;
 /* 0x0E */ u16 item2;
 /* 0x10 */ u8 genderRatio;
 /* 0x11 */ u8 eggCycles;
 /* 0x12 */ u8 friendship;
 /* 0x13 */ u8 growthRate;
 /* 0x14 */ u8 eggGroup1;
 /* 0x15 */ u8 eggGroup2;
 /* 0x16 */ u16 abilities[2];
#ifdef POKEMON_EXPANSION
            u16 abilityHidden;
#endif
            u8 safariZoneFleeRate;
            u8 bodyColor : 7;
            u8 noFlip : 1;
 /* 0x1B */ u8 flags;
};

#include "constants/battle_config.h"
struct BattleMove
{
    u16 effect;
    u8 power;
    u8 type;
    u8 accuracy;
    u8 pp;
    u8 secondaryEffectChance;
    u8 target;
    s8 priority;
    u32 flags;
    u8 split;
    u8 argument;
};

enum{
    SIGNATURE_MOD_NONE,                //No modification
    SIGNATURE_MOD_OTHER,               //Varies depending on the move
    SIGNATURE_MOD_POWER,               //Changes the move power
    SIGNATURE_MOD_ACCURACY,            //Changes the move accuracy
    SIGNATURE_MOD_TYPE,                //Changes the move type
    SIGNATURE_MOD_EFFECT_CHANCE,       //Changes the move secondary effect chance
    SIGNATURE_MOD_DAMAGE_STAT,         //Changes the move damage stat, includes non-damaging stats
    SIGNATURE_MOD_PRIORITY,            //Changes the move priority with a condition
    SIGNATURE_MOD_PSS_CHANGE,          //Changes the move between Physical, Special and the highest stat
    SIGNATURE_MOD_SE_AGAINST_TYPE,     //Makes the move super effective against a type
    SIGNATURE_MOD_SECOND_TYPE,         //Gives the move a second type
    SIGNATURE_MOD_MODIFY_FIELD,        //Modifies the field to add hazards, screens, etc
    SIGNATURE_MOD_ATTACKER_STAT_UP,    //Sets the attacker stat up
    SIGNATURE_MOD_TARGET_STAT_DOWN,    //Sets the target stat down
    SIGNATURE_MOD_SECONDARY_EFFECT,    //Sets a secondary effect to the move
    SIGNATURE_MOD_CURE_WHEN_USED,      //Cures the user when the move is used                                       //Not Done Yet
    SIGNATURE_MOD_HEAL_WHEN_USED,      //Heals the status of the user when the move is used                         //Not Done Yet
    SIGNATURE_MOD_ADD_RECKOIL,         //Adds a Reckoil effect to the move                                          //Not Done Yet
    SIGNATURE_MOD_ADD_DRAIN,           //Adds a Drain effect to the move                                            //Not Done Yet
    SIGNATURE_MOD_DEFENSE_STAT,        //Changes the stat used for defense, includes non-defensive stats
    SIGNATURE_MOD_PENETRATING,         //Ignores the target defense stat changes if they are above the normal ones
    SIGNATURE_MOD_CRITICAL,            //Makes the move have high critical if you add a var of 0 and always critical if you add a var of 1 //Not Done Yet
};

enum{
    FIELD_EFFECT_NONE,              //No effect
    FIELD_OPPONET_SET_STEALTH_ROCK, //Sets Stealth Rock
    FIELD_OPPONET_SET_SPIKES,       //Sets a layer of Spikes
    FIELD_OPPONET_SET_TOXIC_SPIKES, //Sets a layer of Toxic Spikes
    FIELD_OPPONET_SET_STICKY_WEB,   //Sets Sticky Web
    FIELD_OPPONENT_REMOVE_SCREENS,  //Removes screens on the attacker side                      //Not Done Yet
    FIELD_SELF_REMOVE_HAZARDS,      //Removes the hazards on the attacker side                  //Not Done Yet
    FIELD_SELF_SET_TAILWIND,        //Sets Tailwind on your side
    FIELD_SELF_SET_REFLECT,         //Sets Reflect on your side                                 //Not Done Yet
    FIELD_SELF_SET_LIGHT_SCREEN,    //Sets Light Screen on your side                            //Not Done Yet
    FIELD_SELF_SET_AURORA_VEIL,     //Sets Aurora Veil on your side (if the weather is Hail)    //Not Done Yet
    FIELD_SET_TRICK_ROOM,           //Sets Trick Room on the field                              //Not Done Yet
    FIELD_SET_INVERSE_ROOM,         //Sets Inverse Room on the field                            //Not Done Yet
    FIELD_SET_WEATHER_SUN,          //Sets Sun on the field for 5 turns
    FIELD_SET_WEATHER_RAIN,         //Sets Rain on the field for 5 turns
    FIELD_SET_WEATHER_HAIL,         //Sets Hail on the field for 5 turns
    FIELD_SET_WEATHER_SANDSTORM,    //Sets Hail on the field for 5 turns
    FIELD_SET_TERRAIN_ELECTRIC,     //Sets Electric Terrain on the field for 5 turns
    FIELD_SET_TERRAIN_GRASS,        //Sets Grassy Terrain on the field for 5 turns
    FIELD_SET_TERRAIN_MISTY,        //Sets Misty Terrain on the field for 5 turns
    FIELD_SET_TERRAIN_PSYCHIC,      //Sets Psychic Terrain on the field for 5 turns
    FIELD_REMOVE_TERRAIN,           //Removes the terrain on the field                          //Not Done Yet
    FIELD_REMOVE_WEATHER,           //Removes the weather on the field                          //Not Done Yet
    FIELD_CHANGE_FIELD_SIDE,        //Court Change Effect                                       //Not Done Yet
};

enum{
    SIGNATURE_SECONDARY_EFFECT_NONE,                        //No secondary effect
    SIGNATURE_SECONDARY_EFFECT_POISON,                      //Poisons the target
    SIGNATURE_SECONDARY_EFFECT_TOXIC,                       //Badly poisons the target
    SIGNATURE_SECONDARY_EFFECT_PARALYSIS,                   //Paralyzes the target
    SIGNATURE_SECONDARY_EFFECT_BURN,                        //Burns the target
    SIGNATURE_SECONDARY_EFFECT_FREEZE,                      //Freezes the target
    SIGNATURE_SECONDARY_EFFECT_SLEEP,                       //Puts the target to sleep
    SIGNATURE_SECONDARY_EFFECT_CONFUSION,                   //Confuses the target
    SIGNATURE_SECONDARY_EFFECT_INFATUATION,                 //Infatuates the target
    SIGNATURE_SECONDARY_EFFECT_FLINCH,                      //Makes the target flinch
    SIGNATURE_SECONDARY_EFFECT_CURSE,                       //Curses the target
    SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,                  //Leech Seeds the target
    SIGNATURE_SECONDARY_EFFECT_REMOVE_STAT_CHANGES,         //Removes the stat changes of the target
    SIGNATURE_SECONDARY_EFFECT_REVERTS_STAT_CHANGES,        //Topsy-Turvy Effect                       //Not Done Yet
    SIGNATURE_SECONDARY_EFFECT_STEAL_POSITIVE_STAT_CHANGES, //Spectral Thief Effect                    //Not Done Yet
    SIGNATURE_SECONDARY_EFFECT_INFESTATION,                 //Infests the target                       //Not Done Yet
    SIGNATURE_SECONDARY_EFFECT_PERISH_SONG,                 //Perish song effect to the target         //Not Done Yet
    SIGNATURE_SECONDARY_EFFECT_TAUNT,                       //Taunt effect to the target
    SIGNATURE_SECONDARY_EFFECT_GIVE_THIRD_TYPE,             //Gives the Pokemon a third type
    SIGNATURE_SECONDARY_EFFECT_DISABLE,                     //Disable effect to the target             //Not Done Yet
};

enum{
    SIGNATURE_PRIORITY_ALWAYS,              //Always has priority
    SIGNATURE_PRIORITY_IN_CONDITIONS,       //Has priority in certain conditions
    SIGNATURE_PRIORITY_WHEN_BELOW_HEALTH,   //Has priority when the user is below a certain health
    SIGNATURE_PRIORITY_WHEN_ABOVE_HEALTH,   //Has priority when the user is above a certain health
};

enum{
    SIGNATURE_PRIORITY_CONDITION_WEATHER_ANY,       //Has priority in any weather
    SIGNATURE_PRIORITY_CONDITION_WEATHER_SUN,       //Has priority in Sun
    SIGNATURE_PRIORITY_CONDITION_WEATHER_RAIN,      //Has priority in Rain
    SIGNATURE_PRIORITY_CONDITION_WEATHER_SAND,      //Has priority in Sand
    SIGNATURE_PRIORITY_CONDITION_WEATHER_HAIL,      //Has priority in Hail
    SIGNATURE_PRIORITY_CONDITION_TERRAIN_ANY,       //Has priority in any terrain
    SIGNATURE_PRIORITY_CONDITION_TERRAIN_ELECTRIC,  //Has priority in Electric Terrain
    SIGNATURE_PRIORITY_CONDITION_TERRAIN_GRASS,     //Has priority in Grassy Terrain
    SIGNATURE_PRIORITY_CONDITION_TERRAIN_MISTY,     //Has priority in Misty Terrain
    SIGNATURE_PRIORITY_CONDITION_TERRAIN_PSYCHIC,   //Has priority in Psychic Terrain
    SIGNATURE_PRIORITY_CONDITION_INVERSE_ROOM,      //Has priority in Inverse Room
    SIGNATURE_PRIORITY_CONDITION_TRICK_ROOM,        //Has priority in Trick Room
};

#define SIGNATURE_MOVE_DESCRIPTION_TEXT_LENGTH 120

struct SignatureMove
{
    u16 move;
    bool8 differentDescription;
    const u8 description[SIGNATURE_MOVE_DESCRIPTION_TEXT_LENGTH];
    //First Effect
    u8  modification;
    u16 variable;
    u8  argument;
    u8  chance;
    // Second Effect
    u8  modification2;
    u16 variable2;
    u8  argument2;
    u8  chance2;
    // Third Effect
    u8  modification3;
    u16 variable3;
    u8  argument3;
    u8  chance3;
    // Fourth Effect
    u8  modification4;
    u16 variable4;
    u8  argument4;
    u8  chance4;
    // Fifth Effect
    u8  modification5;
    u16 variable5;
    u8  argument5;
    u8  chance5;
    // Sixth Effect
    u8  modification6;
    u16 variable6;
    u8  argument6;
    u8  chance6;
};

struct SpindaSpot
{
    u8 x, y;
    u16 image[16];
};

struct LevelUpMove
{
    u16 move;
    u16 level;
};

struct Evolution
{
    u16 method;
    u16 param;
    u16 targetSpecies;
};

struct SpeciesList
{
    u16 species;
};

extern u8 gPlayerPartyCount;
extern struct Pokemon gPlayerParty[PARTY_SIZE];
extern u8 gEnemyPartyCount;
extern struct Pokemon gEnemyParty[PARTY_SIZE];
extern struct SpriteTemplate gMultiuseSpriteTemplate;

extern const struct BattleMove gBattleMoves[];
extern const struct SignatureMove gSignatureMoveList[];
extern const u8 gFacilityClassToPicIndex[];
extern const u8 gFacilityClassToTrainerClass[];
extern const struct BaseStats gBaseStats[];
extern const struct BaseStats gVanillaBaseStats[];
extern const u8 *const gItemEffectTable[];
extern const struct Evolution gEvolutionTable[][EVOS_PER_MON];
extern const struct SpeciesList gFirstStageTable[POKEMON_FAMILIES];
extern const u32 gExperienceTables[][MAX_LEVEL + 1];
extern const struct LevelUpMove *const gLevelUpLearnsets[];
extern const u8 gPPUpGetMask[];
extern const u8 gPPUpSetMask[];
extern const u8 gPPUpAddMask[];
extern const u8 gStatStageRatios[MAX_STAT_STAGE + 1][2];
extern const u16 gLinkPlayerFacilityClasses[];
extern const struct SpriteTemplate gUnknown_08329D98[];
extern const s8 gNatureStatTable[][5];
extern const u16 gSpeciesToNationalPokedexNum[NUM_SPECIES];

void ZeroBoxMonData(struct BoxPokemon *boxMon);
void ZeroMonData(struct Pokemon *mon);
void ZeroPlayerPartyMons(void);
void ZeroEnemyPartyMons(void);
void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId, u8 formId);
void CreateBoxMon(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId, u8 formId);
void CreateMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 nature, u8 formId);
void CreateMonWithGenderNatureLetter(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 gender, u8 nature, u8 unownLetter, u8 formId);
void CreateMaleMon(struct Pokemon *mon, u16 species, u8 level, u8 formId);
void CreateMonWithIVsPersonality(struct Pokemon *mon, u16 species, u8 level, u32 ivs, u32 personality, u8 formId);
void CreateMonWithIVsOTID(struct Pokemon *mon, u16 species, u8 level, u8 *ivs, u32 otId, u8 formId);
void CreateMonWithEVSpread(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 evSpread, u8 formId);
void CreateBattleTowerMon(struct Pokemon *mon, struct BattleTowerPokemon *src);
void CreateBattleTowerMon2(struct Pokemon *mon, struct BattleTowerPokemon *src, bool8 lvl50);
void CreateApprenticeMon(struct Pokemon *mon, const struct Apprentice *src, u8 monId);
void CreateMonWithEVSpreadNatureOTID(struct Pokemon *mon, u16 species, u8 level, u8 nature, u8 fixedIV, u8 evSpread, u32 otId, u8 formId);
void sub_80686FC(struct Pokemon *mon, struct BattleTowerPokemon *dest);
void CreateObedientMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId, u8 formId);
bool8 sub_80688F8(u8 caseId, u8 battlerId);
u16 GetUnionRoomTrainerPic(void);
u16 GetUnionRoomTrainerClass(void);
void CreateObedientEnemyMon(void);
void CalculateMonStats(struct Pokemon *mon);
void BoxMonToMon(const struct BoxPokemon *src, struct Pokemon *dest);
u8 GetLevelFromMonExp(struct Pokemon *mon);
u8 GetLevelFromBoxMonExp(struct BoxPokemon *boxMon);
u16 GiveMoveToMon(struct Pokemon *mon, u16 move);
u16 GiveMoveToBattleMon(struct BattlePokemon *mon, u16 move);
void SetMonMoveSlot(struct Pokemon *mon, u16 move, u8 slot);
void SetBattleMonMoveSlot(struct BattlePokemon *mon, u16 move, u8 slot);
void GiveMonInitialMoveset(struct Pokemon *mon);
void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon);
u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove);
void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, u16 move);
void DeleteFirstMoveAndGiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move);

u8 CountAliveMonsInBattle(u8 caseId);
#define BATTLE_ALIVE_EXCEPT_ACTIVE  0
#define BATTLE_ALIVE_ATK_SIDE       1
#define BATTLE_ALIVE_DEF_SIDE       2

u8 GetDefaultMoveTarget(u8 battlerId);
u8 GetMonGender(struct Pokemon *mon);
u8 GetBoxMonGender(struct BoxPokemon *boxMon);
u8 GetGenderFromSpeciesAndPersonality(u16 species, u32 personality);
u32 GetUnownSpeciesId(u32 personality);
void SetMultiuseSpriteTemplateToPokemon(u16 speciesTag, u8 battlerPosition, u8 formId);
void SetMultiuseSpriteTemplateToTrainerBack(u16 trainerSpriteId, u8 battlerPosition);
void SetMultiuseSpriteTemplateToTrainerFront(u16 arg0, u8 battlerPosition);

// These are full type signatures for GetMonData() and GetBoxMonData(),
// but they are not used since some code erroneously omits the third arg.
// u32 GetMonData(struct Pokemon *mon, s32 field, u8 *data);
// u32 GetBoxMonData(struct BoxPokemon *boxMon, s32 field, u8 *data);
u32 GetMonData();
u32 GetBoxMonData();

// New functions coming with Dynamic Type, Abilities, Base Stats
struct Pokemon *GetBattlerPartyData(u8 battlerId);
u8 GetSpeciesBaseStat(struct Pokemon *mon, u8 statIndex);


void SetMonData(struct Pokemon *mon, s32 field, const void *dataArg);
void SetBoxMonData(struct BoxPokemon *boxMon, s32 field, const void *dataArg);
void CopyMon(void *dest, void *src, size_t size);
u8 GiveMonToPlayer(struct Pokemon *mon);
u8 SendMonToPC(struct Pokemon* mon);
u8 CalculatePlayerPartyCount(void);
u8 CalculateEnemyPartyCount(void);
u8 GetMonsStateToDoubles(void);
u8 GetMonsStateToDoubles_2(void);
u16 GetAbilityBySpecies(u16 species, u8 abilityNum, u8 formId);
u16 GetMonAbility(struct Pokemon *mon);
void CreateSecretBaseEnemyParty(struct SecretBase *secretBaseRecord);
u8 GetSecretBaseTrainerPicIndex(void);
u8 GetSecretBaseTrainerClass(void);
bool8 IsPlayerPartyAndPokemonStorageFull(void);
bool8 IsPokemonStorageFull(void);
void GetSpeciesName(u8 *name, u16 species);
u8 CalculatePPWithBonus(u16 move, u8 ppBonuses, u8 moveIndex);
void RemoveMonPPBonus(struct Pokemon *mon, u8 moveIndex);
void RemoveBattleMonPPBonus(struct BattlePokemon *mon, u8 moveIndex);
void PokemonToBattleMon(struct Pokemon *src, struct BattlePokemon *dst);
void CopyPlayerPartyMonToBattleData(u8 battlerId, u8 partyIndex);
bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex);
bool8 PokemonUseItemEffects(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex, u8 e);
bool8 HealStatusConditions(struct Pokemon *mon, u32 battlePartyId, u32 healMask, u8 battlerId);
u8 GetItemEffectParamOffset(u16 itemId, u8 effectByte, u8 effectBit);
u8 *UseStatIncreaseItem(u16 itemId);
//u8 GetNature(struct Pokemon *mon);
u8 GetNature(struct Pokemon *mon, bool32 checkHidden);
u8 GetNatureFromPersonality(u32 personality);
u16 GetEvolutionTargetSpecies(struct Pokemon *mon, u8 type, u16 evolutionItem, u16 tradePartnerSpecies, u8 *targetFormId);
u16 HoennPokedexNumToSpecies(u16 hoennNum);
u16 NationalPokedexNumToSpecies(u16 nationalNum);
u16 NationalToHoennOrder(u16 nationalNum);
u16 SpeciesToNationalPokedexNum(u16 species);
u16 SpeciesToHoennPokedexNum(u16 species);
u16 HoennToNationalOrder(u16 hoennNum);
void sub_806D544(u16 species, u32 personality, u8 *dest);
void DrawSpindaSpots(u16 species, u32 personality, u8 *dest, u8 a4);
void EvolutionRenameMon(struct Pokemon *mon, u16 oldSpecies, u16 newSpecies);
u8 GetPlayerFlankId(void);
u16 GetLinkTrainerFlankId(u8 id);
s32 GetBattlerMultiplayerId(u16 a1);
u8 GetTrainerEncounterMusicId(u16 trainerOpponentId);
u16 ModifyStatByNature(u8 nature, u16 n, u8 statIndex);
void AdjustFriendship(struct Pokemon *mon, u8 event);
void MonGainEVs(struct Pokemon *mon, u16 defeatedSpecies, u8 defeatedFormId);
u16 GetMonEVCount(struct Pokemon *mon);
void RandomlyGivePartyPokerus(struct Pokemon *party);
u8 CheckPartyPokerus(struct Pokemon *party, u8 selection);
u8 CheckPartyHasHadPokerus(struct Pokemon *party, u8 selection);
void UpdatePartyPokerusTime(u16 days);
void PartySpreadPokerus(struct Pokemon *party);
bool8 TryIncrementMonLevel(struct Pokemon *mon);
//TM Move Tutor ---------------------------------------------------
u8 GetNumberOfTMMoves(struct Pokemon *mon);
u32 CanMonLearnTMHM(struct Pokemon *mon, u8 tm);
u32 CanSpeciesLearnTMHM(u16 species, u8 tm);
u8 GetTMMovesPokemon(struct Pokemon *mon, u16 *Moves);
//Move Relearner Tutor --------------------------------------------
u8 GetMoveRelearnerMoves(struct Pokemon *mon, u16 *moves);
u8 GetLevelUpMovesBySpecies(u16 species, u16 *moves, u8 formId);
u8 GetNumberOfRelearnableMoves(struct Pokemon *mon);
//Egg Move Tutor --------------------------------------------------
u8 GetNumberOfEggMoves(struct Pokemon *mon);
u8 GetEggMoveTutorMoves(struct Pokemon *mon, u16 *moves);
//Normal Move Tutor --------------------------------------------------
u8 GetNumberOfTutorMoves(struct Pokemon *mon);
u8 GetMoveTutorMoves(struct Pokemon *mon, u16 *moves);
//-----------------------------------------------------------------
u16 SpeciesToPokedexNum(u16 species);
bool32 IsSpeciesInHoennDex(u16 species);
void ClearBattleMonForms(void);
u16 GetBattleBGM(void);
void PlayBattleBGM(void);
void PlayMapChosenOrBattleBGM(u16 songId);
void sub_806E694(u16 songId);
const u32 *GetMonFrontSpritePal(struct Pokemon *mon);
const u32 *GetMonSpritePalFromSpeciesAndPersonality(u16 species, u32 otId, u32 personality);
const struct CompressedSpritePalette *GetMonSpritePalStruct(struct Pokemon *mon);
const struct CompressedSpritePalette *GetMonSpritePalStructFromOtIdPersonality(u16 species, u32 otId , u32 personality);
bool32 IsHMMove2(u16 move);
bool8 IsMonSpriteNotFlipped(u16 species);
s8 GetMonFlavorRelation(struct Pokemon *mon, u8 flavor);
s8 GetFlavorRelationByPersonality(u32 personality, u8 flavor);
bool8 IsTradedMon(struct Pokemon *mon);
bool8 IsOtherTrainer(u32 otId, u8 *otName);
void MonRestorePP(struct Pokemon *mon);
void BoxMonRestorePP(struct BoxPokemon *boxMon);
void SetMonPreventsSwitchingString(void);
void SetWildMonHeldItem(void);
bool8 IsMonShiny(struct Pokemon *mon);
bool8 IsShinyOtIdPersonality(u32 otId, u32 personality);
const u8 *GetTrainerPartnerName(void);
void BattleAnimateFrontSprite(struct Sprite* sprite, u16 species, bool8 noCry, u8 arg3);
void DoMonFrontSpriteAnimation(struct Sprite* sprite, u16 species, bool8 noCry, u8 arg3);
void PokemonSummaryDoMonAnimation(struct Sprite* sprite, u16 species, bool8 oneFrame);
void StopPokemonAnimationDelayTask(void);
void BattleAnimateBackSprite(struct Sprite* sprite, u16 species);
u8 sub_806EF08(u8 arg0);
u8 sub_806EF84(u8 arg0, u8 arg1);
u16 sub_806EFF0(u16 arg0);
u16 FacilityClassToPicIndex(u16 facilityClass);
u16 PlayerGenderToFrontTrainerPicId(u8 playerGender);
void HandleSetPokedexFlag(u16 nationalNum, u8 caseId, u32 personality);
const u8 *GetTrainerClassNameFromId(u16 trainerId);
const u8 *GetTrainerNameFromId(u16 trainerId);
bool8 HasTwoFramesAnimation(u16 species);
struct Unknown_806F160_Struct *sub_806F2AC(u8 id, u8 arg1);
void sub_806F47C(u8 id);
u8 *sub_806F4F8(u8 id, u8 arg1);
u16 GetFormSpeciesId(u16 baseSpeciesId, u8 formId);
u8 GetFormIdFromFormSpeciesId(u16 formSpeciesId);
u16 GetBaseFormSpeciesId(u16 formSpeciesId);
void CreateShinyMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 nature);
u16 MonTryLearningNewMoveEvolution(struct Pokemon *mon, bool8 firstMove);
bool8 PartyMonHasType(struct Pokemon *mon, u8 type);
u16 GetRandomFirstStage(u16 basespecies);
u16 GetGrowthRate(u16 formSpeciesId);
u16 GetExioliteSpecies(u16 basespecies, u8 level);
u16 getBaseForm(u16 species);
void SetOutBreakPokemonFromCompanion(void);
void SetRoamerPokemonFromCompanion(void);
u8 RandomizePokemonType(u8 type, u32 personality, bool8 isSecondtype);
u16 RandomizePokemonAbility(u16 ability, u32 personality);
u8 GetThirdTypeFromPersonality(u32 personality, u16 type1, u16 type2);

#endif // GUARD_POKEMON_H
