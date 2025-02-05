#include "modding.h"
#include "global.h"

extern u8 gPlayerFormItemRestrictions[PLAYER_FORM_MAX][114];

// Patches every form's restriction to allow for the use of normal masks
RECOMP_CALLBACK("*", recomp_after_play_init) void modify_item_restriction_table(PlayState* this) {
    for (int form = PLAYER_FORM_FIERCE_DEITY; form <= PLAYER_FORM_DEKU; form++) {
        for (int mask = ITEM_MASK_TRUTH; mask <= ITEM_MASK_GIANT; mask++) {
            gPlayerFormItemRestrictions[form][mask] = true;
        }
    }
}

// Apply selected mask across forms
RECOMP_HOOK("Player_Init") void after_player_init(Actor* thisx, PlayState* play) {
    Player* this = (Player*)thisx;
    
    // if statement fixes owl statue saved masks
    if (gSaveContext.save.equippedMask == PLAYER_MASK_NONE) {
        gSaveContext.save.equippedMask = this->currentMask;
    }
}