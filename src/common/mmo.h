// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef	_MMO_H_
#define	_MMO_H_

#include "cbasetypes.h"
#include "../common/db.h"
#include <time.h>

// server->client protocol version
//        0 - pre-?
//        1 - ?                    - 0x196
//        2 - ?                    - 0x78, 0x79
//        3 - ?                    - 0x1c8, 0x1c9, 0x1de
//        4 - ?                    - 0x1d7, 0x1d8, 0x1d9, 0x1da
//        5 - 2003-12-18aSakexe+   - 0x1ee, 0x1ef, 0x1f0, ?0x1c4, 0x1c5?
//        6 - 2004-03-02aSakexe+   - 0x1f4, 0x1f5
//        7 - 2005-04-11aSakexe+   - 0x229, 0x22a, 0x22b, 0x22c
// see conf/battle/client.conf for other version

#ifndef PACKETVER
	//#define PACKETVER 20130807
	#define PACKETVER 20120410
#endif

///Remove/Comment this line to disable sc_data saving. [Skotlex]
#define ENABLE_SC_SAVING
/** Remove/Comment this line to disable server-side hot-key saving support [Skotlex]
* Note that newer clients no longer save hotkeys in the registry! */
#define HOTKEY_SAVING

#if PACKETVER < 20090603
        // (27 = 9 skills x 3 bars)               (0x02b9,191)
        #define MAX_HOTKEYS 27
#elif PACKETVER < 20090617
        // (36 = 9 skills x 4 bars)               (0x07d9,254)
        #define MAX_HOTKEYS 36
#else
        // (38 = 9 skills x 4 bars & 2 Quickslots)(0x07d9,268)
        #define MAX_HOTKEYS 38
#endif

#define MAX_MAP_PER_SERVER 1500 /// Increased to allow creation of Instance Maps
#define MAX_INVENTORY 100 ///Maximum items in player inventory
/** Max number of characters per account. Note that changing this setting alone is not enough if the client is not hexed to support more characters as well.
* Max value tested was 265 */
#define MAX_CHARS 9 
/** Number of slots carded equipment can have. Never set to less than 4 as they are also used to keep the data of forged items/equipment. [Skotlex]
* Note: The client seems unable to receive data for more than 4 slots due to all related packets having a fixed size. */
#define MAX_SLOTS 4
#define MAX_AMOUNT 30000 ////Max amount of a single stacked item
#define MAX_ZENY 1000000000 ///Max zeny
#define MAX_BANK_ZENY SINT32_MAX ///Max zeny in Bank
#define MAX_FAME 1000000000 ///Max fame points
#define MAX_CART 100 ///Maximum item in cart
#define MAX_SKILL 5020 ///Maximum skill data
#define GLOBAL_REG_NUM 256 ///Max permanent character variables per char
#define ACCOUNT_REG_NUM 64 ///Max permanent local account variables per account
#define ACCOUNT_REG2_NUM 16 ///Max permanent global account variables per account
#define MAX_REG_NUM 256 ///Should hold the max of GLOBAL/ACCOUNT/ACCOUNT2 (needed for some arrays that hold all three)
#define DEFAULT_WALK_SPEED 150 ///Default walk speed
#define MIN_WALK_SPEED 0 ///Min walk speed
#define MAX_WALK_SPEED 1000 ///Max walk speed
#define MAX_STORAGE 600 ///Max number of storage slots a player can have, (up to ~850 tested)
#define MAX_GUILD_STORAGE 600 ///Max number of storage slots a guild
#define MAX_PARTY 12 ///Max party member
#define MAX_GUILD 16+10*6	///Increased max guild members +6 per 1 extension levels [Lupus]
#define MAX_GUILDPOSITION 20	///Increased max guild positions to accomodate for all members [Valaris] (removed) [PoW]
#define MAX_GUILDEXPULSION 32 ///Max Guild expulsion
#define MAX_GUILDALLIANCE 16 ///Max Guild alliance
#define MAX_GUILDSKILL	15 ///Increased max guild skills because of new skills [Sara-chan]
#define MAX_GUILDLEVEL 50 ///Max Guild level
#define MAX_GUARDIANS 8	///Local max per castle. If this value is increased, need to add more fields on MySQL `guild_castle` table [Skotlex]
#define MAX_QUEST_OBJECTIVES 3 ///Max quest objectives for a quest

// for produce
#define MIN_ATTRIBUTE 0
#define MAX_ATTRIBUTE 4
#define ATTRIBUTE_NORMAL 0
#define MIN_STAR 0
#define MAX_STAR 3

#define MAX_STATUS_TYPE 5

#define WEDDING_RING_M 2634
#define WEDDING_RING_F 2635

//For character names, title names, guilds, maps, etc.
//Includes null-terminator as it is the length of the array.
#define NAME_LENGTH (23 + 1)
//For item names, which tend to have much longer names.
#define ITEM_NAME_LENGTH 50
//For Map Names, which the client considers to be 16 in length including the .gat extension
#define MAP_NAME_LENGTH (11 + 1)
#define MAP_NAME_LENGTH_EXT (MAP_NAME_LENGTH + 4)
//Pincode Length
#define PINCODE_LENGTH 4

#define MAX_FRIENDS 40
#define MAX_MEMOPOINTS 3
#define MAX_SKILLCOOLDOWN 20

//Size of the fame list arrays.
#define MAX_FAME_LIST 10

//Limits to avoid ID collision with other game objects
#define START_ACCOUNT_NUM 2000000
#define END_ACCOUNT_NUM 100000000
#define START_CHAR_NUM 150000

//Guilds
#define MAX_GUILDMES1 60
#define MAX_GUILDMES2 120

//Base Homun skill.
#define HM_SKILLBASE 8001
#define MAX_HOMUNSKILL 43
#define MAX_HOMUNCULUS_CLASS	52	//[orn], Increased to 60 from 16 to allow new Homun-S.
#define HM_CLASS_BASE 6001
#define HM_CLASS_MAX (HM_CLASS_BASE+MAX_HOMUNCULUS_CLASS-1)

//Mail System
#define MAIL_MAX_INBOX 30
#define MAIL_TITLE_LENGTH 40
#define MAIL_BODY_LENGTH 200

//Mercenary System
#define MC_SKILLBASE 8201
#define MAX_MERCSKILL 40
#define MAX_MERCENARY_CLASS 61

//Elemental System
#define MAX_ELEMENTALSKILL 42
#define EL_SKILLBASE 8401
#define MAX_ELESKILLTREE 3
#define MAX_ELEMENTAL_CLASS 12
#define EL_CLASS_BASE 2114
#define EL_CLASS_MAX (EL_CLASS_BASE+MAX_ELEMENTAL_CLASS-1)

enum item_types {
	IT_HEALING = 0,
	IT_UNKNOWN, //1
	IT_USABLE,  //2
	IT_ETC,     //3
	IT_ARMOR,   //4
	IT_WEAPON,  //5
	IT_CARD,    //6
	IT_PETEGG,  //7
	IT_PETARMOR,//8
	IT_UNKNOWN2,//9
	IT_AMMO,    //10
	IT_DELAYCONSUME,//11
	IT_SHADOWGEAR,  //12
	IT_CASH = 18,
	IT_MAX
};

// Questlog states
enum quest_state {
	Q_INACTIVE, ///< Inactive quest (the user can toggle between active and inactive quests)
	Q_ACTIVE,   ///< Active quest
	Q_COMPLETE, ///< Completed quest
};

/// Questlog entry
struct quest {
	int quest_id;                    ///< Quest ID
	unsigned int time;               ///< Expiration time
	int count[MAX_QUEST_OBJECTIVES]; ///< Kill counters of each quest objective
	enum quest_state state;          ///< Current quest state
};

struct item {
	int id;
	short nameid;
	short amount;
	unsigned int equip; // location(s) where item is equipped (using enum equip_pos for bitmasking)
	char identify;
	char refine;
	char attribute;
	short card[MAX_SLOTS];
	unsigned int expire_time;
	char favorite, bound;
	uint64 unique_id;
};

struct point {
	unsigned short map;
	short x,y;
};

enum e_skill_flag
{
	SKILL_FLAG_PERMANENT,
	SKILL_FLAG_TEMPORARY,
	SKILL_FLAG_PLAGIARIZED,
	SKILL_FLAG_REPLACED_LV_0, // temporary skill overshadowing permanent skill of level 'N - SKILL_FLAG_REPLACED_LV_0',
	SKILL_FLAG_PERM_GRANTED, // permanent, granted through someway e.g. script
	SKILL_FLAG_TMP_COMBO, //@FIXME for homon combo atm
	//...
};

enum e_mmo_charstatus_opt {
	OPT_NONE        = 0x0,
	OPT_SHOW_EQUIP  = 0x1,
	OPT_ALLOW_PARTY = 0x2,
};

struct s_skill {
	unsigned short id;
	unsigned char lv;
	unsigned char flag; // see enum e_skill_flag
};

struct global_reg {
	char str[32];
	char value[256];
};

//Holds array of global registries, used by the char server and converter.
struct accreg {
	int account_id, char_id;
	int reg_num;
	struct global_reg reg[MAX_REG_NUM];
};

//For saving status changes across sessions. [Skotlex]
struct status_change_data {
	unsigned short type; //SC_type
	long val1, val2, val3, val4, tick; //Remaining duration.
};

#define MAX_BONUS_SCRIPT_LENGTH 1024
struct bonus_script_data {
	char script[MAX_BONUS_SCRIPT_LENGTH];
	long tick;
	char type;
	short flag, icon;
};

struct skill_cooldown_data {
	unsigned short skill_id;
	long tick;
};

struct storage_data {
	int storage_amount;
	struct item items[MAX_STORAGE];
};

struct guild_storage {
	int dirty;
	int guild_id;
	short storage_status;
	short storage_amount;
	struct item items[MAX_GUILD_STORAGE];
	unsigned short lock;
};

struct s_pet {
	int account_id;
	int char_id;
	int pet_id;
	short class_;
	short level;
	short egg_id;//pet egg id
	short equip;//pet equip name_id
	short intimate;//pet friendly
	short hungry;//pet hungry
	char name[NAME_LENGTH];
	char rename_flag;
	char incuvate;
};

struct s_homunculus {	//[orn]
	char name[NAME_LENGTH];
	int hom_id;
	int char_id;
	short class_;
	short prev_class;
	int hp,max_hp,sp,max_sp;
	unsigned int intimacy;	//[orn]
	short hunger;
	struct s_skill hskill[MAX_HOMUNSKILL]; //albator
	short skillpts;
	short level;
	unsigned int exp;
	short rename_flag;
	short vaporize; //albator
	int str ;
	int agi ;
	int vit ;
	int int_ ;
	int dex ;
	int luk ;

	char spiritball; //for homun S [lighta]
};

struct s_mercenary {
	int mercenary_id;
	int char_id;
	short class_;
	int hp, sp;
	unsigned int kill_count;
	unsigned int life_time;
};

struct s_elemental {
	int elemental_id;
	int char_id;
	short class_;
	int mode;
	int hp, sp, max_hp, max_sp, matk, atk, atk2;
	short hit, flee, amotion, def, mdef;
	int life_time;
};

struct s_friend {
	int account_id;
	int char_id;
	char name[NAME_LENGTH];
};

#ifdef HOTKEY_SAVING
struct hotkey {
	unsigned int id;
	unsigned short lv;
	unsigned char type; // 0: item, 1: skill
};
#endif

struct mmo_charstatus {
	int char_id;
	int account_id;
	int partner_id;
	int father;
	int mother;
	int child;

	unsigned int base_exp,job_exp;
	int zeny;
	int bank_vault;

	short class_;
	unsigned int status_point,skill_point;
	int hp,max_hp,sp,max_sp;
	unsigned int option;
	short manner; // Defines how many minutes a char will be muted, each negative point is equivalent to a minute.
	unsigned char karma;
	short hair,hair_color,clothes_color;
	int party_id,guild_id,pet_id,hom_id,mer_id,ele_id;
	int fame;

	// Mercenary Guilds Rank
	int arch_faith, arch_calls;
	int spear_faith, spear_calls;
	int sword_faith, sword_calls;

	short weapon; // enum weapon_type
	short shield; // view-id
	short head_top,head_mid,head_bottom;
	short robe;

	char name[NAME_LENGTH];
	unsigned int base_level,job_level;
	short str,agi,vit,int_,dex,luk;
	unsigned char slot,sex;

	uint32 mapip;
	uint16 mapport;

	struct point last_point,save_point,memo_point[MAX_MEMOPOINTS];
	struct item inventory[MAX_INVENTORY],cart[MAX_CART];
	struct storage_data storage;
	struct s_skill skill[MAX_SKILL];

	struct s_friend friends[MAX_FRIENDS]; //New friend system [Skotlex]
#ifdef HOTKEY_SAVING
	struct hotkey hotkeys[MAX_HOTKEYS];
#endif
	bool show_equip,allow_party;
	short rename;

	time_t delete_date;
	time_t unban_time;

	// Char server addon system
	unsigned int character_moves;

	bool cashshop_sent; // Whether the player has received the CashShop list
};

typedef enum mail_status {
	MAIL_NEW,
	MAIL_UNREAD,
	MAIL_READ,
} mail_status;

struct mail_message {
	int id;
	int send_id;
	char send_name[NAME_LENGTH];
	int dest_id;
	char dest_name[NAME_LENGTH];
	char title[MAIL_TITLE_LENGTH];
	char body[MAIL_BODY_LENGTH];

	mail_status status;
	time_t timestamp; // marks when the message was sent

	int zeny;
	struct item item;
};

struct mail_data {
	short amount;
	bool full;
	short unchecked, unread;
	struct mail_message msg[MAIL_MAX_INBOX];
};

struct auction_data {
	unsigned int auction_id;
	int seller_id;
	char seller_name[NAME_LENGTH];
	int buyer_id;
	char buyer_name[NAME_LENGTH];

	struct item item;
	// This data is required for searching, as itemdb is not read by char server
	char item_name[ITEM_NAME_LENGTH];
	short type;

	unsigned short hours;
	int price, buynow;
	time_t timestamp; // auction's end time
	int auction_end_timer;
};

struct registry {
	int global_num;
	struct global_reg global[GLOBAL_REG_NUM];
	int account_num;
	struct global_reg account[ACCOUNT_REG_NUM];
	int account2_num;
	struct global_reg account2[ACCOUNT_REG2_NUM];
};

struct party_member {
	int account_id;
	int char_id;
	char name[NAME_LENGTH];
	unsigned short class_;
	unsigned short map;
	unsigned short lv;
	unsigned leader : 1,
	         online : 1;
};

struct party {
	int party_id;
	char name[NAME_LENGTH];
	unsigned char count; //Count of online characters.
	unsigned exp : 1,
				item : 2; //&1: Party-Share (round-robin), &2: pickup style: shared.
	struct party_member member[MAX_PARTY];
};

struct map_session_data;
struct guild_member {
	int account_id, char_id;
	short hair,hair_color,gender,class_,lv;
	uint64 exp;
	int exp_payper;
	short online,position;
	char name[NAME_LENGTH];
	struct map_session_data *sd;
	unsigned char modified;
};

struct guild_position {
	char name[NAME_LENGTH];
	int mode;
	int exp_mode;
	unsigned char modified;
};

struct guild_alliance {
	int opposition;
	int guild_id;
	char name[NAME_LENGTH];
};

struct guild_expulsion {
	char name[NAME_LENGTH];
	char mes[40];
	int account_id;
};

struct guild_skill {
	int id,lv;
};

struct Channel;
struct guild {
	int guild_id;
	short guild_lv, connect_member, max_member, average_lv;
	uint64 exp;
	unsigned int next_exp;
	int skill_point;
	char name[NAME_LENGTH],master[NAME_LENGTH];
	struct guild_member member[MAX_GUILD];
	struct guild_position position[MAX_GUILDPOSITION];
	char mes1[MAX_GUILDMES1],mes2[MAX_GUILDMES2];
	int emblem_len,emblem_id;
	char emblem_data[2048];
	struct guild_alliance alliance[MAX_GUILDALLIANCE];
	struct guild_expulsion expulsion[MAX_GUILDEXPULSION];
	struct guild_skill skill[MAX_GUILDSKILL];
	struct Channel *channel;

	/* TODO: still used for something? */
	unsigned short save_flag; // for TXT saving
};

struct guild_castle {
	int castle_id;
	int mapindex;
	char castle_name[NAME_LENGTH];
	char castle_event[NAME_LENGTH];
	int guild_id;
	int economy;
	int defense;
	int triggerE;
	int triggerD;
	int nextTime;
	int payTime;
	int createTime;
	int visibleC;
	struct {
		unsigned visible : 1;
		int id; // object id
	} guardian[MAX_GUARDIANS];
	int* temp_guardians; // ids of temporary guardians (mobs)
	int temp_guardians_max;
};

struct fame_list {
	int id;
	int fame;
	char name[NAME_LENGTH];
};

enum { //Change Guild Infos
	GBI_EXP	=1,		// Guild Experience (EXP)
	GBI_GUILDLV,		// Guild level
	GBI_SKILLPOINT,		// Guild skillpoints
	GBI_SKILLLV,		// Guild skill_lv ?? seem unused
};

enum { //Change Member Infos
	GMI_POSITION	=0,
	GMI_EXP,
	GMI_HAIR,
	GMI_HAIR_COLOR,
	GMI_GENDER,
	GMI_CLASS,
	GMI_LEVEL,
};

enum e_guild_skill {
	GD_SKILLBASE=10000,
	GD_APPROVAL=10000,
	GD_KAFRACONTRACT=10001,
	GD_GUARDRESEARCH=10002,
	GD_GUARDUP=10003,
	GD_EXTENSION=10004,
	GD_GLORYGUILD=10005,
	GD_LEADERSHIP=10006,
	GD_GLORYWOUNDS=10007,
	GD_SOULCOLD=10008,
	GD_HAWKEYES=10009,
	GD_BATTLEORDER=10010,
	GD_REGENERATION=10011,
	GD_RESTORE=10012,
	GD_EMERGENCYCALL=10013,
	GD_DEVELOPMENT=10014,
	GD_ITEMEMERGENCYCALL=10015,
	GD_MAX,
};


//These mark the ID of the jobs, as expected by the client. [Skotlex]
enum {
	JOB_NOVICE,
	JOB_SWORDMAN,
	JOB_MAGE,
	JOB_ARCHER,
	JOB_ACOLYTE,
	JOB_MERCHANT,
	JOB_THIEF,
	JOB_KNIGHT,
	JOB_PRIEST,
	JOB_WIZARD,
	JOB_BLACKSMITH,
	JOB_HUNTER,
	JOB_ASSASSIN,
	JOB_KNIGHT2,
	JOB_CRUSADER,
	JOB_MONK,
	JOB_SAGE,
	JOB_ROGUE,
	JOB_ALCHEMIST,
	JOB_BARD,
	JOB_DANCER,
	JOB_CRUSADER2,
	JOB_WEDDING,
	JOB_SUPER_NOVICE,
	JOB_GUNSLINGER,
	JOB_NINJA,
	JOB_XMAS,
	JOB_SUMMER,
	JOB_HANBOK,
	JOB_OKTOBERFEST,
	JOB_MAX_BASIC,

	JOB_NOVICE_HIGH = 4001,
	JOB_SWORDMAN_HIGH,
	JOB_MAGE_HIGH,
	JOB_ARCHER_HIGH,
	JOB_ACOLYTE_HIGH,
	JOB_MERCHANT_HIGH,
	JOB_THIEF_HIGH,
	JOB_LORD_KNIGHT,
	JOB_HIGH_PRIEST,
	JOB_HIGH_WIZARD,
	JOB_WHITESMITH,
	JOB_SNIPER,
	JOB_ASSASSIN_CROSS,
	JOB_LORD_KNIGHT2,
	JOB_PALADIN,
	JOB_CHAMPION,
	JOB_PROFESSOR,
	JOB_STALKER,
	JOB_CREATOR,
	JOB_CLOWN,
	JOB_GYPSY,
	JOB_PALADIN2,

	JOB_BABY,
	JOB_BABY_SWORDMAN,
	JOB_BABY_MAGE,
	JOB_BABY_ARCHER,
	JOB_BABY_ACOLYTE,
	JOB_BABY_MERCHANT,
	JOB_BABY_THIEF,
	JOB_BABY_KNIGHT,
	JOB_BABY_PRIEST,
	JOB_BABY_WIZARD,
	JOB_BABY_BLACKSMITH,
	JOB_BABY_HUNTER,
	JOB_BABY_ASSASSIN,
	JOB_BABY_KNIGHT2,
	JOB_BABY_CRUSADER,
	JOB_BABY_MONK,
	JOB_BABY_SAGE,
	JOB_BABY_ROGUE,
	JOB_BABY_ALCHEMIST,
	JOB_BABY_BARD,
	JOB_BABY_DANCER,
	JOB_BABY_CRUSADER2,
	JOB_SUPER_BABY,

	JOB_TAEKWON,
	JOB_STAR_GLADIATOR,
	JOB_STAR_GLADIATOR2,
	JOB_SOUL_LINKER,

	JOB_GANGSI,
	JOB_DEATH_KNIGHT,
	JOB_DARK_COLLECTOR,

	JOB_RUNE_KNIGHT = 4054,
	JOB_WARLOCK,
	JOB_RANGER,
	JOB_ARCH_BISHOP,
	JOB_MECHANIC,
	JOB_GUILLOTINE_CROSS,

	JOB_RUNE_KNIGHT_T,
	JOB_WARLOCK_T,
	JOB_RANGER_T,
	JOB_ARCH_BISHOP_T,
	JOB_MECHANIC_T,
	JOB_GUILLOTINE_CROSS_T,

	JOB_ROYAL_GUARD,
	JOB_SORCERER,
	JOB_MINSTREL,
	JOB_WANDERER,
	JOB_SURA,
	JOB_GENETIC,
	JOB_SHADOW_CHASER,

	JOB_ROYAL_GUARD_T,
	JOB_SORCERER_T,
	JOB_MINSTREL_T,
	JOB_WANDERER_T,
	JOB_SURA_T,
	JOB_GENETIC_T,
	JOB_SHADOW_CHASER_T,

	JOB_RUNE_KNIGHT2,
	JOB_RUNE_KNIGHT_T2,
	JOB_ROYAL_GUARD2,
	JOB_ROYAL_GUARD_T2,
	JOB_RANGER2,
	JOB_RANGER_T2,
	JOB_MECHANIC2,
	JOB_MECHANIC_T2,

	JOB_BABY_RUNE = 4096,
	JOB_BABY_WARLOCK,
	JOB_BABY_RANGER,
	JOB_BABY_BISHOP,
	JOB_BABY_MECHANIC,
	JOB_BABY_CROSS,
	JOB_BABY_GUARD,
	JOB_BABY_SORCERER,
	JOB_BABY_MINSTREL,
	JOB_BABY_WANDERER,
	JOB_BABY_SURA,
	JOB_BABY_GENETIC,
	JOB_BABY_CHASER,

	JOB_BABY_RUNE2,
	JOB_BABY_GUARD2,
	JOB_BABY_RANGER2,
	JOB_BABY_MECHANIC2,

	JOB_SUPER_NOVICE_E = 4190,
	JOB_SUPER_BABY_E,

	JOB_KAGEROU = 4211,
	JOB_OBORO,

	JOB_REBELLION = 4215,

	JOB_MAX,
};

enum {
	SEX_FEMALE = 0,
	SEX_MALE,
	SEX_SERVER
};

// sanity checks...
#if MAX_ZENY > INT_MAX
#error MAX_ZENY is too big
#endif

#endif /* _MMO_H_ */
