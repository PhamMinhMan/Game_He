#pragma once
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

#define BACK_WIDTH 325
#define BACK_HEIGHT 248

#define GAME Game::getInstance()
#define SIMON Simon::getInstance()
#define GAMESTATUS GameStatus::getInstance()
#define CAMERA Camera::getInstance()
#define SWEPT_AABB SweptAABB::getInstance()

#define TIME 16
#define KEYBOARD Keyboard::getInstance()

#define GRAVITY -0.0004

enum COLLISION_FILTER
{
	CF_Ground,
	CF_Stair,
	CF_Enemy,
	CF_Item,
	CF_Gate,
	CF_Simon,
	CF_CandleLarge=6,
	CF_Panther=8,
	CF_ChangeStage,
	CF_ActiveVampireBat,
	CF_CandleSmall
};
enum ANIMATION_SIMON {
	AS_DANH =-1,
	AS_DI,
	AS_NGOI,
	AS_DUNG_DANH,
	AS_LUI,
	AS_VO_CUA,
	AS_XUONG,
	AS_LEN,
	AS_LEN_DANH,
	AS_CHET,
	AS_XUONG_DANH,
	AS_NHAY_DANH,
	AS_NHAY,
	AS_DUNG,
	AS_NGOI_DANH
};

enum DIRECTION
{
	Left = -1,
	Right = 1
};

//add
enum SPRITE_MANAGER
{
	SPR_ActiveVampireBat = -8,
	SPR_ChangeStage = -6,
	SPR_Gate1 = -5,
	SPR_Fake,
	SPR_CandleLarge = -3,
	SPR_Stair,
	SPR_Ground,
	SPR_Zombie,
	SPR_Panther,
	SPR_Medusa_Head,
	SPR_Merman,
	SPR_Red_Bat,
	SPR_Spear_Guard,
	SPR_Bone_Pillar,
	SPR_Blue_Bat,
	SPR_Ghost,
	SPR_Door,
	SPR_Vampire_Bat,
	SPR_CandleSmall,
	SPR_Medusa,
	SPR_SIMON,
	SPR_WHIP,
	SPR_HitEffect,
	SPR_COUNT
};
