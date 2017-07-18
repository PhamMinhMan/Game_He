#pragma once
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

#define BACK_WIDTH 325
#define BACK_HEIGHT 184

#define GAME Game::getInstance()
#define SIMON Simon::getInstance()
#define CAMERA Camera::getInstance()
#define SWEPT_AABB SweptAABB::getInstance()

#define TIME GameTime::getInstance()->deltaTime
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
	CF_CandleLarge,
	CF_CandleSmall,
	CF_Panther,
	CF_ChangeStage,
	CF_ActiveVampireBat
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
