#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "Creature.h"
#include "Enemies/Enemies.h"
#include "HUDLayer.h"

#include <vector>

USING_NS_CC;

class GameLayer: public cocos2d::Layer {
public:
    // auto-generated "static create()" method
    CREATE_FUNC(GameLayer);

    virtual bool init();

    int screenWidth, screenHeight;

    Player* player;
    const int RUN_SPEED = 5, RUN_ACCELERATION = 1, GRAVITY = 1, JUMP_SPEED = 18;
    const float RUN_FRICTION = 0.9;
    std::vector<Creature*> enemies;
    std::vector<Sprite*> tiles;

    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

    virtual void update(float dt);
    void updateCreature(Creature *s);
    Vec2 tilePosition(Sprite *s);
    char collide(Sprite *s1, Sprite *s2);

    bool cheat;

    TMXTiledMap *map;
    TMXLayer *layer;
    HUDLayer *hudLayer;
};

#endif // __GAME_LAYER_H__