#if defined _pf2_included
	#endinput
#endif
#define _pf2_included

#if defined _tf2_included
	#error You cannot have both TF2 and PF2 includes included in your plugin
#endif

// We're overriding this shit

// These do nothing at the moment. PF2 does not have stunning.

//#define TF_STUNFLAG_SLOWDOWN        (1 << 0)    /**< activates slowdown modifier */
//#define TF_STUNFLAG_BONKSTUCK       (1 << 1)    /**< bonk sound, stuck */
//#define TF_STUNFLAG_LIMITMOVEMENT   (1 << 2)    /**< disable forward/backward movement */
//#define TF_STUNFLAG_CHEERSOUND      (1 << 3)    /**< cheering sound */
//#define TF_STUNFLAG_NOSOUNDOREFFECT (1 << 5)    /**< no sound or particle */
//#define TF_STUNFLAG_THIRDPERSON     (1 << 6)    /**< panic animation */
//#define TF_STUNFLAG_GHOSTEFFECT     (1 << 7)    /**< ghost particles */
//#define TF_STUNFLAG_SOUND           (1 << 8)    /**< sound */

//#define TF_STUNFLAGS_LOSERSTATE     TF_STUNFLAG_SLOWDOWN|TF_STUNFLAG_NOSOUNDOREFFECT|TF_STUNFLAG_THIRDPERSON
//#define TF_STUNFLAGS_GHOSTSCARE     TF_STUNFLAG_GHOSTEFFECT|TF_STUNFLAG_THIRDPERSON
//#define TF_STUNFLAGS_SMALLBONK      TF_STUNFLAG_THIRDPERSON|TF_STUNFLAG_SLOWDOWN
//#define TF_STUNFLAGS_NORMALBONK     TF_STUNFLAG_BONKSTUCK
//#define TF_STUNFLAGS_BIGBONK        TF_STUNFLAG_CHEERSOUND|TF_STUNFLAG_BONKSTUCK

enum TFClassType
{
	TFClass_Unknown = 0,
	TFClass_Scout,
	TFClass_Sniper,
	TFClass_Soldier,
	TFClass_Demoman,
	TFClass_Medic,
	TFClass_HeavyWeapons,
	TFClass_Pyro,
	TFClass_Spy,
	TFClass_Engineer,
	TFClass_Civilian	
};


enum TFTeam
{
	TFTeam_Unassigned = 0,
	TFTeam_Spectator = 1,
	TFTeam_Red = 2,
	TFTeam_Blue = 3,
	//TFTeam_Green,	
	//TFTeam_Yellow,

	TFTeam_COUNT
};

enum TFCond
{
	TFCond_Invalid = -1, // -1: invalid condition
	TFCond_Aiming = 0, // 0: Revving Minigun, Sniper Rifle. Gives zoomed/revved pose
	TFCond_Zoomed, // 1: Sniper Rifle zooming
	TFCond_Disguising, // 2: Disguise smoke
	TFCond_Disguised, // 3: Disguise
	TFCond_Cloaked, // 4: Cloak effect
	TFCond_Ubercharged, // 5: Invulnerability, removed when being healed or by another Uber effect
	TFCond_TeleportedGlow, // 6: Teleport trail effect
	TFCond_Taunting, // 7: Used for taunting, can remove to stop taunting
	TFCond_UberchargeFading, // 8: Invulnerability expiration effect
	TFCond_CloakFlicker, // 9: Cloak flickering effect
	TFCond_Teleporting, // 10: Used for teleporting, does nothing applying
	TFCond_CritBoost, // 11: Crit boost
	TFCond_CritBoost_First_Blood, // 12: Crit boost from first blood in Arena
	TFCond_CritBoost_Winning, // 13: Crit boost from winning a match
	TFCond_BlastJumping, // 14: Currently blast jumping
	TFCond_HealthBuff, // 15: Used for healing
	TFCond_Overhealed, // 16: Condition to determine if you're overhealed
	TFCond_ArmorBuff, // 17: Used for regenerating armor
	
	TFCond_Burning, // 18: Burning condition
	TFCond_Tranquilized, // 19: Tranquilized condition
	TFCond_Dizzy, // 20: Concussion grenade condition
	TFCond_Leg_Damaged, // 21: Caltrop condition
	TFCond_Infected, // 22: Medic syringe melee condition
	TFCond_Napalm_Burning, // 23: Napalm grenade burning condition
	TFCond_Armor_Melting, // 24: Gas grenade condition
	TFCond_Leg_Damaged_Gunshot, // 25: Sniper leg shot condition
	TFCond_Leg_Hallucinating, // 26: Gas Grenade condition
	
	TFCond_SpeedBoost, // 27: Speed boost condition
	
	TFCond_LAST // Last condition
};

const float TFCondDuration_Infinite = -1.0;

enum TFObjectType
{
	TFObject_CartDispenser = 0,
	TFObject_Dispenser = 0,
	TFObject_Teleporter = 1,
	TFObject_Sentry = 2,
	TFObject_Sapper = 3,
	TFObject_SRT = 4, // Spawnroom Turret
};

enum TFObjectMode
{
	TFObjectMode_None = 0,
	TFObjectMode_Entrance = 0,
	TFObjectMode_Exit = 1
};

#define TF_CONDFLAG_NONE            			0
#define TF_CONDFLAG_SLOWED          			(1 << 0)
#define TF_CONDFLAG_ZOOMED          			(1 << 1)
#define TF_CONDFLAG_DISGUISING      			(1 << 2)
#define TF_CONDFLAG_DISGUISED       			(1 << 3)
#define TF_CONDFLAG_CLOAKED         			(1 << 4)
#define TF_CONDFLAG_UBERCHARGED     			(1 << 5)
#define TF_CONDFLAG_TELEPORTGLOW    			(1 << 6)
#define TF_CONDFLAG_TAUNTING        			(1 << 7)
#define TF_CONDFLAG_UBERCHARGEFADE 			 	(1 << 8)
#define TF_CONDFLAG_CLOAKFLICKER    			(1 << 9)
#define TF_CONDFLAG_TELEPORTING     			(1 << 10)
#define TF_CONDFLAG_CRITBOOSTED    				(1 << 11)
#define TF_CONDFLAG_CRITBOOSTED_FIRST_BLOOD    	(1 << 12)
#define TF_CONDFLAG_CRITBOOSTED_WINNING         (1 << 13)
#define TF_CONDFLAG_BLAST_JUMPING           	(1 << 14)
#define TF_CONDFLAG_HEALTH_BUFF          		(1 << 15)
#define TF_CONDFLAG_HEALTH_OVERHEALED       	(1 << 16)
#define TF_CONDFLAG_ARMOR_BUFF        			(1 << 17)
#define TF_CONDFLAG_BURNING        				(1 << 18)
#define TF_CONDFLAG_TRANQUILIZED    			(1 << 19)
#define TF_CONDFLAG_DIZZY         				(1 << 20)
#define TF_CONDFLAG_LEG_DAMAGED          		(1 << 21)
#define TF_CONDFLAG_INFECTED      				(1 << 22)
#define TF_CONDFLAG_NAPALM_BURNING         		(1 << 23)
#define TF_CONDFLAG_ARMOR_MELTING       	 	(1 << 24)
#define TF_CONDFLAG_LEG_DAMAGED_GUNSHOT   		(1 << 25)
#define TF_CONDFLAG_HALLUCINATION          		(1 << 26)
#define TF_CONDFLAG_SPEED_BOOST        			(1 << 27)

#define TF_DEATHFLAG_KILLERDOMINATION   (1 << 0)
#define TF_DEATHFLAG_ASSISTERDOMINATION (1 << 1)
#define TF_DEATHFLAG_KILLERREVENGE      (1 << 2)
#define TF_DEATHFLAG_ASSISTERREVENGE    (1 << 3)
//#define TF_DEATHFLAG_FIRSTBLOOD         (1 << 4)
//#define TF_DEATHFLAG_DEADRINGER         (1 << 5)
//#define TF_DEATHFLAG_INTERRUPTED        (1 << 6)
//#define TF_DEATHFLAG_GIBBED             (1 << 7)
//#define TF_DEATHFLAG_PURGATORY          (1 << 8)
//#define TF_DEATHFLAG_MINIBOSS           (1 << 9)
//#define TF_DEATHFLAG_AUSTRALIUM         (1 << 10)

// Custom kill identifiers for the customkill property on the player_death event
enum {
	TF_DMG_CUSTOM_NONE = 0,
	TF_DMG_CUSTOM_HEADSHOT,
	TF_DMG_CUSTOM_BACKSTAB,
	TF_DMG_CUSTOM_BURNING,
	TF_DMG_CUSTOM_WRENCH_FIX,
	TF_DMG_CUSTOM_MINIGUN,
	TF_DMG_CUSTOM_SUICIDE,
	TF_DMG_CUSTOM_BUILDING_CARRIED,
	TF_DMG_CUSTOM_NAPALM_BURNING,
	TF_DMG_CUSTOM_DISPENSER_EXPLOSION,
	TF_DMG_CUSTOM_TELEPORTER_EXPLOSION,
	TF_DMG_CUSTOM_INFECTION,
	TF_DMG_CUSTOM_GRENADE_BONK,
	TF_DMG_CUSTOM_EMP_EXPLOSION,
	TF_DMG_CUSTOM_CALTROP,
	TF_DMG_CUSTOM_TAUNTATK_HADOUKEN,
	TF_DMG_CUSTOM_TAUNTATK_HIGH_NOON,
	TF_DMG_CUSTOM_TAUNTATK_FENCING,
	TF_DMG_CUSTOM_TELEFRAG,
};

// Weapon codes as used in some events, such as player_death
// (not to be confused with Item Definition Indexes)
enum {
	TF_WEAPON_NONE = 0,
	TF_WEAPON_BAT,
	TF_WEAPON_BOTTLE,
	TF_WEAPON_CLUB,
	TF_WEAPON_KNIFE,
	TF_WEAPON_SHOVEL,
	TF_WEAPON_WRENCH,
	TF_WEAPON_SHOTGUN_PRIMARY,
	TF_WEAPON_SHOTGUN_SOLDIER,
	TF_WEAPON_SHOTGUN_HWG,
	TF_WEAPON_SHOTGUN_PYRO,
	TF_WEAPON_SCATTERGUN,
	TF_WEAPON_SNIPERRIFLE,
	TF_WEAPON_MINIGUN,
	TF_WEAPON_SMG,
	TF_WEAPON_SYRINGEGUN_MEDIC,
	TF_WEAPON_TRANQ,
	TF_WEAPON_ROCKETLAUNCHER,
	TF_WEAPON_GRENADELAUNCHER,
	TF_WEAPON_PIPEBOMBLAUNCHER,
	TF_WEAPON_FLAMETHROWER,
	TF_WEAPON_GRENADE_NORMAL,
	TF_WEAPON_GRENADE_CONCUSSION,
	TF_WEAPON_GRENADE_NAIL,
	TF_WEAPON_GRENADE_MIRV,
	TF_WEAPON_GRENADE_MIRV_DEMOMAN,
	TF_WEAPON_GRENADE_NAPALM,
	TF_WEAPON_GRENADE_GAS,
	TF_WEAPON_GRENADE_EMP,
	TF_WEAPON_GRENADE_CALTROP,
	TF_WEAPON_GRENADE_PIPEBOMB,
	TF_WEAPON_GRENADE_HEAL,
	TF_WEAPON_PISTOL,
	TF_WEAPON_REVOLVER,
	TF_WEAPON_NAILGUN,
	TF_WEAPON_PDA,
	TF_WEAPON_PDA_ENGINEER_BUILD,
	TF_WEAPON_PDA_ENGINEER_DESTROY,
	TF_WEAPON_PDA_SPY,
	TF_WEAPON_BUILDER,
	TF_WEAPON_MEDIGUN,
	TF_WEAPON_GRENADE_MIRVBOMB,
	TF_WEAPON_FLAMETHROWER_ROCKET,
	TF_WEAPON_GRENADE_DEMOMAN,
	TF_WEAPON_SENTRY_BULLET,
	TF_WEAPON_SENTRY_ROCKET,
	TF_WEAPON_DISPENSER,
	TF_WEAPON_INVIS,
	TF_WEAPON_PIPE,
	TF_WEAPON_SMG_SCOUT,
	TF_WEAPON_SYRINGE,
	TF_WEAPON_BRANDINGIRON,
	TF_WEAPON_PISTOL_SPY,
	TF_WEAPON_SMG_MEDIC,
	TF_WEAPON_FLAG,
	TF_WEAPON_BLOWTORCH,
	TF_WEAPON_UMBRELLA,
	TF_WEAPON_CUBEMAP,
	TF_WEAPON_SHOTGUN_SCOUT,

	TF_WEAPON_COUNT
};

// TF2 Weapon Loadout Slots
enum
{
	TFWeaponSlot_Primary,
	TFWeaponSlot_Secondary,
	TFWeaponSlot_Melee,
	TFWeaponSlot_Grenade,
	TFWeaponSlot_Building,
	TFWeaponSlot_PDA,
	TFWeaponSlot_Item1,
	TFWeaponSlot_Item2,
	TFWeaponSlot_Item3,
	TFWeaponSlot_Item4
};

// Identifiers for the eventtype property on the teamplay_flag_event event
enum {
	TF_FLAGEVENT_PICKEDUP = 1,
	TF_FLAGEVENT_CAPTURED,
	TF_FLAGEVENT_DEFENDED,
	TF_FLAGEVENT_DROPPED,
	TF_FLAGEVENT_THROWN,
	TF_FLAGEVENT_RETURNED
};

enum TFResourceType
{
	TFResource_Ping,
	TFResource_Score,
	TFResource_Deaths,
	TFResource_TotalScore,
	TFResource_Captures,
	TFResource_Defenses,
	TFResource_Dominations,
	TFResource_Revenge,
	TFResource_BuildingsDestroyed,
	TFResource_Headshots,
	TFResource_Backstabs,
	TFResource_HealPoints,
	TFResource_Invulns,
	TFResource_Teleports,
	TFResource_ResupplyPoints,
	TFResource_KillAssists,
	TFResource_MaxHealth,
	TFResource_PlayerClass,
	//TFResource_ArmorRepaired,
	TFResource_COUNT
};

static const char TFResourceNames[TFResource_COUNT][] =
{
	"m_iPing",
	"m_iScore",
	"m_iDeaths",
	"m_iTotalScore",
	"m_iCaptures",
	"m_iDefenses",
	"m_iDominations",
	"m_iRevenge",
	"m_iBuildingsDestroyed",
	"m_iHeadshots",
	"m_iBackstabs",
	"m_iHealPoints",
	"m_iInvulns",
	"m_iTeleports",
	"m_iResupplyPoints",
	"m_iKillAssists",
	"m_iMaxHealth",
	"m_iPlayerClass",
	//"m_iMaxArmor"
};

/**
 * Gets a client's current team.
 *
 * @param client        Client index.
 * @return              Current TFTeam of client.
 * @error               Invalid client index.
 */
stock TFTeam TF2_GetClientTeam(int client)
{
	return view_as<TFTeam>(GetClientTeam(client));
}

/**
 * Changes a client's current team.
 *
 * @param client        Client index.
 * @param team          TFTeam team symbol.
 * @error               Invalid client index.
 */
stock void TF2_ChangeClientTeam(int client, TFTeam team)
{
    ChangeClientTeam(client, view_as<int>(team));
}

/**
 * Gets a client's current class.
 *
 * @param client        Player's index.
 * @return              Current TFClassType of player.
 * @error               Invalid client index.
 */
stock TFClassType TF2_GetPlayerClass(int client)
{
	return view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_iClass"));
}
stock TFClassType TF2_GetClass(const char[] classname)
{
	if (StrEqual(classname, "scout"))
		return TFClass_Scout;
	else if (StrEqual(classname, "soldier"))
		return TFClass_Soldier;
	else if (StrEqual(classname, "pyro"))
		return TFClass_Pyro;
	else if (StrEqual(classname, "demoman"))
		return TFClass_DemoMan;
	else if (StrEqual(classname, "heavyweapons"))
		return TFClass_Heavy;
	else if (StrEqual(classname, "engineer"))
		return TFClass_Engineer;
	else if (StrEqual(classname, "medic"))
		return TFClass_Medic;
	else if (StrEqual(classname, "spy"))
		return TFClass_Spy;
	else if (StrEqual(classname, "civilian"))
		return TFClass_Civilian;
	else
		return TFClass_Unknown;
}
/**
 * Sets a client's class.
 *
 * Note: If setting player class in a player spawn hook weapons should be set to false.
 *
 * @param client        Player's index.
 * @param classType     TFClassType class symbol.
 * @param weapons       This parameter is ignored.
 * @param persistent    If true, changes the player's desired class so the change stays after death.
 * @error               Invalid client index.
 */
stock void TF2_SetPlayerClass(int client, TFClassType classType, bool weapons=true, bool persistent=true)
{
	SetEntProp(client, Prop_Send, "m_iClass", view_as<int>(classType));

	if (persistent)
	{
		SetEntProp(client, Prop_Send, "m_iDesiredPlayerClass", view_as<int>(classType));
	}
}

/**
 * Retrieves client data from the resource entity
 *
 * @param client		Player's index.
 * @param type			ResourceType constant
 * @return				Value or -1 on failure.
 * @error				Invalid client index, client not in game or failed to find resource entity.
 * @deprecated          Use GetPlayerResourceEntity and GetEntProp instead.
 */
#pragma deprecated Use GetPlayerResourceEntity and GetEntProp instead
stock int TF2_GetPlayerResourceData(int client, TFResourceType type)
{
	if (!IsClientConnected(client))
	{
		return -1;
	}

	int offset = FindSendPropInfo("CTFPlayerResource", TFResourceNames[type]);

	if (offset < 1)
	{
		return -1;
	}

	int entity = TF2_GetResourceEntity();

	if (entity == -1)
	{
		return -1;
	}

	return GetEntData(entity, offset + (client*4));
}

/**
 * Sets client data in the resource entity
 *
 * Note: The game overwrites these values every frame, so changing them will have very little effect.
 *
 * @param client        Player's index.
 * @param type          ResourceType constant
 * @param value         Value to set.
 * @return              Value or -1 on failure.
 * @error               Invalid client index, client not in game or failed to find resource entity.
 * @deprecated          Use GetPlayerResourceEntity and SetEntProp instead.
 */
#pragma deprecated Use GetPlayerResourceEntity and SetEntProp instead
stock bool TF2_SetPlayerResourceData(int client, TFResourceType type, any value)
{
	if (!IsClientConnected(client))
	{
		return false;
	}

	int offset = FindSendPropInfo("CTFPlayerResource", TFResourceNames[type]);

	if (offset < 1)
	{
		return false;
	}

	int entity = TF2_GetResourceEntity();

	if (entity == -1)
	{
		return false;
	}

	SetEntData(entity, offset + (client*4), value);

	return true;
}

/**
 * Removes all weapons from a client's weapon slot
 *
 * @param client        Player's index.
 * @param slot          Slot index (0-5)
 * @error               Invalid client, invalid slot or lack of mod support
 */
stock void TF2_RemoveWeaponSlot(int client, int slot)
{
	int weaponIndex;
	while ((weaponIndex = GetPlayerWeaponSlot(client, slot)) != -1)
	{
		// bug #6206
		// papering over a valve bug where a weapon's extra wearables aren't properly removed from the weapon's owner
		int extraWearable = GetEntPropEnt(weaponIndex, Prop_Send, "m_hExtraWearable");
		if (extraWearable != -1)
		{
			RemoveEntity(extraWearable);
		}

//		extraWearable = GetEntPropEnt(weaponIndex, Prop_Send, "m_hExtraWearableViewModel");
//		if (extraWearable != -1)
//		{
//			TF2_RemoveWearable(client, extraWearable);
//		}
		RemovePlayerItem(client, weaponIndex);
		AcceptEntityInput(weaponIndex, "Kill");
	}
}

/**
 * Removes all weapons from a client
 *
 * @param client        Player's index.
 */
stock void TF2_RemoveAllWeapons(int client)
{
	for (int i = 0; i <= 5; i++)
	{
		TF2_RemoveWeaponSlot(client, i);
	}
}

/**
 * Gets a player's condition bits
 *
 * @param client        Player's index.
 * @return              Player's condition bits
 * @deprecated          Use TF2_IsPlayerInCondition instead.
 */
#pragma deprecated Use TF2_IsPlayerInCondition instead.
stock int TF2_GetPlayerConditionFlags(int client)
{
	return GetEntProp(client, Prop_Send, "m_nPlayerCond")|GetEntProp(client, Prop_Send, "_condition_bits");
}

/**
 * Check whether or not a condition is set on a player
 *
 * @param client        Player's index.
 * @param cond          TFCond constant
 * @return              True if set, false otherwise
 */
stock bool TF2_IsPlayerInCondition(int client, TFCond cond)
{
	// Conditions are stored across multiple netprops now, one for each 32-bit segment.
	int iCond = view_as<int>(cond);
	switch (iCond / 32)
	{
		// PF2 does not have 27+ conditions, so this is fine for now.
		case 0:
		{
			int bit = 1 << iCond;
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCond") & bit) == bit)
			{
				return true;
			}

			/*if ((GetEntProp(client, Prop_Send, "_condition_bits") & bit) == bit)
			{
				return true;
			}*/
		}
/*		case 1:
		{
			int bit = (1 << (iCond - 32));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx") & bit) == bit)
			{
				return true;
			}
		}
		case 2:
		{
			int bit = (1 << (iCond - 64));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx2") & bit) == bit)
			{
				return true;
			}
		}
		case 3:
		{
			int bit = (1 << (iCond - 96));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx3") & bit) == bit)
			{
				return true;
			}
		}*/
//		case 4:
//		{
//			int bit = (1 << (iCond - 128));
//			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx4") & bit) == bit)
//			{
//				return true;
//			}
//		}
		default:
		{
			ThrowError("Invalid TFCond value %d", iCond);
		}
	}

	return false;
}

/**
 * Gets an entity's object type.
 *
 * @param entity        Entity index.
 * @return              Current TFObjectType of entity.
 * @error               Invalid entity index.
 */
stock TFObjectType TF2_GetObjectType(int entity)
{
	int offset = GetEntSendPropOffs(entity, "m_iObjectType");

	if (offset <= 0)
	{
		ThrowError("Entity index %d is not an object", entity);
	}

	return view_as<TFObjectType>(GetEntData(entity, offset));
}

/**
 * Gets an entity's object mode.
 *
 * @param entity        Entity index.
 * @return              Current TFObjectMode of entity.
 * @error               Invalid entity index.
 */
stock TFObjectMode TF2_GetObjectMode(int entity)
{
	int offset = GetEntSendPropOffs(entity, "m_iObjectMode");

	if (offset <= 0)
	{
		ThrowError("Entity index %d is not an object", entity);
	}

	return view_as<TFObjectMode>(GetEntData(entity, offset));
}


native void TF2_IgnitePlayer(int client, int attacker);
native void TF2_RespawnPlayer(int client);
native void TF2_RegeneratePlayer(int client);
native void TF2_AddCondition(int client, TFCond cond, float dur = TFCondDuration_Infinite, int inflictor = 0);
native void TF2_RemoveCondition(int client, TFCond cond);
native void TF2_DisguisePlayer(int client, TFTeam team, TFClassType classType, int target = 0);
native void TF2_RemovePlayerDisguise(int client);
native void TF2_StunPlayer(int client, float duration, float slowdown = 0.0, int stunflags, int attacker = 0);

forward void TF2_OnConditionRemoved(int client, TFCond cond);
forward void TF2_OnConditionAdded(int client, TFCond cond, float dur/*, int inflictor*/);
forward Action TF2_CalcIsAttackCritical(int client, int weapon, char[] weaponname, bool &result);
//forward Action TF2_OnPlayerTeleport(int client, int teleporter, bool &result);
forward void TF2_OnWaitingForPlayersStart();
forward void TF2_OnWaitingForPlayersEnd();

public SharedPlugin __pl_pf2 =
{
	name = "pf2",
	file = "pf2.smx",
#if defined REQUIRE_PLUGIN
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_pf2_SetNTVOptional()
{
	MarkNativeAsOptional("TF2_IgnitePlayer");
	MarkNativeAsOptional("TF2_RespawnPlayer");
	MarkNativeAsOptional("TF2_RegeneratePlayer");
	MarkNativeAsOptional("TF2_AddCondition");
	MarkNativeAsOptional("TF2_RemoveCondition");
	MarkNativeAsOptional("TF2_DisguisePlayer");
	MarkNativeAsOptional("TF2_RemovePlayerDisguise");
	MarkNativeAsOptional("TF2_StunPlayer");
}
#endif
