
/**
 * Status defaults for durations.
 *
 * "" for an entry means N/A, either because it is not shown in the
 * relevant place, or because it is shown in a more complicated way.
 * A "" for name_text indicates that the name is the same as the
 * short text.
 *
 * Examples:
 *
 * DUR_FORESTED has "" for the short_text entry, and therefore has no
 * entry on the "@:" line.
 *
 * DUR_QAZLAL_AC has "" for the light_text entry, and therefore has no
 * status light (instead showing the AC bonus by coloring the player's
 * AC blue).
 */
struct duration_def
{
    duration_type dur;
    bool expire;         ///< Whether to do automatic expiration colouring.
    int    light_colour; ///< Base colour for status light.
    const char *light_text; ///< Text for the status light.
    const char *short_text; //<! Text for @ line on the % screen and morgues.
                            //<! Usually an adjective.
    const char *name_text;  //<! Text used in wizmode &^D. If empty, use the
                            //<! short_text.
    const char *long_text;  ///< Text for the @ message.

    /// Return the name of the duration (name_text or short_text). */
    const char *name() const
    {
        return name_text[0] ? name_text : short_text;
    }
};

static const duration_def duration_data[] =
{
    { DUR_AGILITY,
      false, LIGHTBLUE, "Agi",
      "agile", "agility",
      "You are agile." },
    { DUR_ANTIMAGIC,
      true, RED, "-Mag",
      "antimagic", "",
      "You have trouble accessing your magic." },
    { DUR_BERSERK,
      true, BLUE, "Berserk",
      "berserking", "berserker",
      "You are possessed by a berserker rage." },
    { DUR_BREATH_WEAPON,
      false, YELLOW, "Breath",
      "short of breath", "breath weapon",
      "You are short of breath." },
    { DUR_BRILLIANCE,
      false, LIGHTBLUE, "Brill",
      "brilliant", "brilliance",
      "You are brilliant." },
    { DUR_CONF,
      false, RED, "Conf",
      "confused", "conf",
      "You are confused." },
    { DUR_CONFUSING_TOUCH,
      true, BLUE, "Touch",
      "confusing touch", "",
      "" },
    { DUR_CONTROL_TELEPORT,
      true, MAGENTA, "cTele",
      "controlling teleports", "control teleport",
      "You can control teleportations." },
    { DUR_CORONA,
      false, YELLOW, "Corona",
      "", "corona",
      "" },
    { DUR_DEATH_CHANNEL,
      true, MAGENTA, "DChan",
      "death channel", "",
      "You are channeling the dead." },
    { DUR_DIVINE_STAMINA,
      true, WHITE, "Vit",
      "vitalised", "divine stamina",
      "You are divinely vitalised." },
    { DUR_DIVINE_VIGOUR,
      false, 0, "",
      "divinely vigorous", "divine vigour",
      "You are imbued with divine vigour." },
    { DUR_EXHAUSTED,
      false, YELLOW, "Exh",
      "exhausted", "",
      "You are exhausted." },
    { DUR_FIRE_SHIELD,
      true, BLUE, "RoF",
      "immune to fire clouds", "fire shield",
      "" },
    { DUR_ICY_ARMOUR,
      true, 0, "",
      "icy armour", "",
      "You are protected by a layer of icy armour." },
    { DUR_LIQUID_FLAMES,
      false, RED, "Fire",
      "liquid flames", "",
      "You are covered in liquid flames." },
    { DUR_LOWERED_MR,
      false, RED, "-MR",
      "vulnerable", "lowered mr",
      "" },
    { DUR_MAGIC_SHIELD,
      false, 0, "",
      "shielded", "magic shield",
      "" },
    { DUR_MIGHT,
      false, LIGHTBLUE, "Might",
      "mighty", "might",
      "You are mighty." },
    { DUR_PARALYSIS,
      false, RED, "Para",
      "paralysed", "paralysis",
      "You are paralysed." },
    { DUR_PETRIFIED,
      false, RED, "Stone",
      "petrified", "",
      "You are petrified." },
    { DUR_PETRIFYING,
      true, LIGHTRED, "Petr",
      "petrifying", "",
      "You are turning to stone." },
    { DUR_RESISTANCE,
      true, BLUE, "Resist",
      "resistant", "resistance",
      "You resist elements." },
    { DUR_SLIMIFY,
      true, GREEN, "Slime",
      "slimy", "slimify",
      "" },
    { DUR_SLEEP,
      false, 0, "",
      "sleeping", "sleep",
      "You are sleeping." },
    { DUR_STONESKIN,
      false, 0, "",
      "stone skin", "stoneskin",
      "Your skin is tough as stone." },
    { DUR_SWIFTNESS,
      true, BLUE, "Swift",
      "swift", "swiftness",
      "You can move swiftly." },
    { DUR_TELEPATHY,
      false, LIGHTBLUE, "Emp",
      "empathic", "telepathy",
      "" },
    { DUR_TELEPORT,
      false, LIGHTBLUE, "Tele",
      "about to teleport", "teleport",
      "You are about to teleport." },
    { DUR_DEATHS_DOOR,
      true, LIGHTGREY, "DDoor",
      "death's door", "deaths door",
      "" },
    { DUR_PHASE_SHIFT,
      true, 0, "",
      "phasing", "phase shift",
      "You are out of phase with the material plane." },
    { DUR_QUAD_DAMAGE,
      true, BLUE, "Quad",
      "quad damage", "",
      "" },
    { DUR_SILENCE,
      true, MAGENTA, "Sil",
      "silence", "",
      "You radiate silence." },
    { DUR_STEALTH,
      false, BLUE, "Stealth",
      "especially stealthy", "stealth",
      "" },
    { DUR_AFRAID,
      true, RED, "Fear",
      "afraid", "",
      "You are terrified." },
    { DUR_MIRROR_DAMAGE,
      false, WHITE, "Mirror",
      "injury mirror", "mirror damage",
      "You mirror injuries." },
    { DUR_SCRYING,
      false, WHITE, "Scry",
      "scrying", "",
      "Your astral vision lets you see through walls." },
    { DUR_TORNADO,
      true, LIGHTGREY, "Tornado",
      "tornado", "",
      "You are in the eye of a mighty hurricane." },
    { DUR_LIQUEFYING,
      false, LIGHTBLUE, "Liquid",
      "liquefying", "",
      "The ground has become liquefied beneath your feet." },
    { DUR_HEROISM,
      false, LIGHTBLUE, "Hero",
      "heroism", "",
      "You possess the skills of a mighty hero." },
    { DUR_FINESSE,
      false, LIGHTBLUE, "Finesse",
      "finesse", "",
      "Your blows are lightning fast." },
    { DUR_LIFESAVING,
      true, LIGHTGREY, "Prot",
      "protection", "lifesaving",
      "You are calling for your life to be saved." },
    { DUR_DARKNESS,
      true, BLUE, "Dark",
      "darkness", "",
      "You emit darkness." },
    { DUR_SHROUD_OF_GOLUBRIA,
      true, BLUE, "Shroud",
      "shrouded", "",
      "You are protected by a distorting shroud." },
    { DUR_TORNADO_COOLDOWN,
      false, YELLOW, "Tornado",
      "", "tornado cooldown",
      "" },
    { DUR_DISJUNCTION,
      true, BLUE, "Disjoin",
      "disjoining", "disjunction",
      "You are disjoining your surroundings." },
    { DUR_SENTINEL_MARK,
      true, LIGHTRED, "Mark",
      "marked", "sentinel's mark",
      "A sentinel's mark is revealing your location to enemies." },
    { DUR_INFUSION,
      true, BLUE, "Infus",
      "infused", "",
      "Your attacks are magically infused." },
    { DUR_SONG_OF_SLAYING,
      true, BLUE, "Slay",
      "singing", "song of slaying",
      "Your melee attacks are strengthened by your song." },
    { DUR_FLAYED,
      true, RED, "Flay",
      "flayed", "",
      "You are covered in terrible wounds." },
    { DUR_WEAK,
      false, RED, "Weak",
      "weakened", "weak",
      "Your attacks are enfeebled." },
    { DUR_DIMENSION_ANCHOR,
      false, RED, "-Tele",
      "cannot translocate", "dimension anchor",
      "You are firmly anchored to this plane." },
    { DUR_TOXIC_RADIANCE,
      false, MAGENTA, "Toxic",
      "radiating poison", "toxic radiance",
      "You are radiating toxic energy." },
    { DUR_RECITE,
      false, WHITE, "Recite",
      "reciting", "",
      "You are reciting Zin's Axioms of Law." },
    { DUR_GRASPING_ROOTS,
      false, BROWN, "Roots",
      "grasped by roots", "grasping roots",
      "Your movement is impeded by grasping roots." },
    { DUR_FIRE_VULN,
      false, RED, "-rF",
      "fire vulnerable", "fire vulnerability",
      "You are more vulnerable to fire." },
    { DUR_BARBS,
      false, RED, "Barbs",
      "manticore barbs", "",
      "Manticore spikes are embedded in your body." },
    { DUR_POISON_VULN,
      false, RED, "-rP",
      "poison vulnerable", "poison vulnerability",
      "You are more vulnerable to poison." },
    { DUR_FROZEN,
      false, RED, "Frozen",
      "frozen", "",
      "You are partly encased in ice." },
    { DUR_SAP_MAGIC,
      false, RED, "Sap",
      "sap magic", "",
      "Casting spells hinders your spell success." },
    { DUR_PORTAL_PROJECTILE,
      false, LIGHTBLUE, "PProj",
      "portal projectile", "",
      "You are teleporting projectiles to their destination." },
    { DUR_FORESTED,
      false, GREEN, "Forest",
      "", "forested",
      "" },
    { DUR_DRAGON_CALL,
      false, WHITE, "Dragoncall",
      "dragon's call", "dragon call",
      "You are beckoning forth a horde of dragons." },
    { DUR_DRAGON_CALL_COOLDOWN,
      false, YELLOW, "Dragoncall",
      "", "dragon call cooldown",
      "" },
    { DUR_ABJURATION_AURA,
      false, BLUE, "Abj",
      "aura of abjuration", "",
      "You are abjuring all hostile summons around you." },
    { DUR_NO_POTIONS,
      false, RED, "-Potion",
      "no potions", "",
      "You cannot drink potions." },
    { DUR_QAZLAL_FIRE_RES,
      false, LIGHTBLUE, "rF+",
      "protected from fire", "qazlal fire resistance",
      "Qazlal is protecting you from fire." },
    { DUR_QAZLAL_COLD_RES,
      false, LIGHTBLUE, "rC+",
      "protected from cold", "qazlal cold resistance",
      "Qazlal is protecting you from cold." },
    { DUR_QAZLAL_ELEC_RES,
      false, LIGHTBLUE, "rElec+",
      "protected from electricity", "qazlal elec resistance",
      "Qazlal is protecting you from electricity." },
    { DUR_QAZLAL_AC,
      false, LIGHTBLUE, "",
      "protected from physical damage", "qazlal ac",
      "Qazlal is protecting you from physical damage." },
    { DUR_CORROSION,
      false, RED, "Corr",
      "corroded equipment", "corrosion",
      "Your equipment is corroded." },
    { DUR_FORTITUDE,
      false, LIGHTBLUE, "Fort",
      "immense fortitude", "",
      "You have immense fortitude and shrug off injury." },

    // The following are visible in wizmode only, or are handled
    // specially in the status lights and/or the % or @ screens.

    { DUR_INVIS, false, 0, "", "", "invis", "" },
    { DUR_SLOW, false, 0, "", "", "slow", "" },
    { DUR_MESMERISED, false, 0, "", "", "mesmerised", "" },
    { DUR_MESMERISE_IMMUNE, false, 0, "", "", "mesmerisation immunity", "" },
    { DUR_HASTE, false, 0, "", "", "haste", "" },
    { DUR_FLIGHT, false, 0, "", "", "flight", "" },
    { DUR_POISONING, false, 0, "", "", "poisoning", "" },
    { DUR_SURE_BLADE, false, 0, "", "", "sure blade", "" },
    { DUR_BUILDING_RAGE, false, 0, "", "", "building rage", "" },
    { DUR_PIETY_POOL, false, 0, "", "", "piety pool", "" },
    { DUR_DIVINE_SHIELD, false, 0, "", "", "divine shield", "" },
    { DUR_REGENERATION, false, 0, "", "", "regeneration", "" },
    { DUR_TRANSFORMATION, false, 0, "", "", "transformation", "" },
    { DUR_WEAPON_BRAND, false, 0, "", "", "weapon brand", "" },
    { DUR_DEMONIC_GUARDIAN, false, 0, "", "", "demonic guardian", "" },
    { DUR_POWERED_BY_DEATH, false, 0, "", "", "pbd", "" },
    { DUR_CONDENSATION_SHIELD, false, 0, "", "", "condensation shield", "" },
    { DUR_GOURMAND, false, 0, "", "", "gourmand", "" },
    { DUR_REPEL_STAIRS_MOVE, false, 0, "", "", "repel stairs move", "" },
    { DUR_REPEL_STAIRS_CLIMB, false, 0, "", "", "repel stairs climb", "" },
    { DUR_COLOUR_SMOKE_TRAIL, false, 0, "", "", "coloured smoke trail", "" },
    { DUR_TIME_STEP, false, 0, "", "", "time step", "" },
    { DUR_ICEMAIL_DEPLETED, false, 0, "", "", "icemail depleted", "" },
    { DUR_PARALYSIS_IMMUNITY, false, 0, "", "", "paralysis immunity", "" },
    { DUR_AMBROSIA, false, 0, "", "", "ambrosia", "" },
    { DUR_VEHUMET_GIFT, false, 0, "", "", "vehumet gift", "" },
    { DUR_SICKENING, false, 0, "", "", "sickening", "" },
    { DUR_WATER_HOLD, false, 0, "", "", "drowning", "" },
    { DUR_WATER_HOLD_IMMUNITY, false, 0, "", "", "drowning immunity", "" },
    { DUR_SLEEP_IMMUNITY, false, 0, "", "", "sleep immunity", "" },
    { DUR_ELIXIR_HEALTH, false, 0, "", "", "elixir health", "" },
    { DUR_ELIXIR_MAGIC, false, 0, "", "", "elixir magic", "" },
    { DUR_TROGS_HAND, false, 0, "", "", "trogs hand", "" },
    { DUR_MAGIC_SAPPED, false, 0, "", "", "magic sapped", "" },

#if TAG_MAJOR_VERSION == 34
    // And removed ones
    { DUR_REPEL_MISSILES, false, 0, "", "", "old repel missiles", "" },
    { DUR_DEFLECT_MISSILES, false, 0, "", "", "old deflect missiles", "" },
    { DUR_JELLY_PRAYER, false, 0, "", "", "old jelly prayer", "" },
    { DUR_CONTROLLED_FLIGHT, false, 0, "", "", "old controlled flight", "" },
    { DUR_SEE_INVISIBLE, false, 0, "", "", "old see invisible", "" },
    { DUR_INSULATION, false, 0, "", "", "old insulation", "" },
    { DUR_BARGAIN, false, 0, "", "", "old bargain", "" },
    { DUR_SLAYING, false, 0, "", "", "old slaying", "" },
    { DUR_MISLED, false, 0, "", "", "old misled", "" },
    { DUR_NAUSEA, false, 0, "", "", "old nausea", "" },
    { DUR_TEMP_MUTATIONS, false, 0, "", "", "old temporary mutations", "" },
    { DUR_BATTLESPHERE, false, 0, "", "", "old battlesphere", "" },
    { DUR_RETCHING, false, 0, "", "", "old retching", "" },
    { DUR_SPIRIT_HOWL, false, 0, "", "", "old spirit howl", "" },
    { DUR_SONG_OF_SHIELDING, false, 0, "", "", "old song of shielding", "" },
    { DUR_ANTENNAE_EXTEND, false, 0, "", "", "old antennae extend", "" },
#endif
};
