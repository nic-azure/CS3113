#include "Level1.h"
#define LEVEL1_WIDTH 14
#define LEVEL1_HEIGHT 100
#define LEVEL1_ENEMY_COUNT 17
unsigned int level1_data[] =
{
 89, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 24,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0,
 89, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3,
 89, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0,
 89, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
 89, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3,
 89, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 3,
 89, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3,
 89, 0, 0, 3, 3, 3, 0, 0, 3, 0, 0, 0, 3, 3,
 89, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3,
 89, 3, 0, 0, 3, 0, 0, 3, 3, 3, 0, 0, 0, 3,
 89, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3,
 89, 0, 0, 3, 3, 3, 0, 0, 3, 0, 0, 0, 3, 3,
 89, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3,
 89, 3, 0, 0, 3, 0, 0, 3, 3, 3, 0, 0, 0, 3,
 89, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3,
 89, 0, 0, 3, 3, 3, 0, 0, 3, 0, 0, 0, 3, 3,
 89, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3,
 89, 3, 0, 0, 3, 0, 0, 3, 3, 3, 0, 0, 0, 3,
 89, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3,
 89, 0, 0, 3, 3, 3, 0, 0, 3, 0, 0, 0, 3, 3,
 89, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3,
 89, 3, 0, 0, 3, 0, 0, 3, 3, 3, 0, 0, 0, 3,
 89, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 3,
 89, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3,
 89, 0, 0, 0, 3, 3, 0, 3, 3, 3, 0, 0, 0, 3,
 89, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 2, 2, 0, 2, 0, 2, 2, 2, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
 89, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
 89, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0,
 89, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0,
 89, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0,
 89, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
 89, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
 89, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
 89, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
 89, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 89, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
 89, 90, 90, 90, 90, 90, 90, 90, 90, 0, 0, 0, 0, 0,
 89, 90, 90, 90, 90, 90, 90, 90, 90, 0, 0, 0, 0, 0,
 89, 90, 90, 90, 90, 90, 90, 90, 90, 0, 0, 0, 0, 0
};

void Level1::Initialize() {

    state.nextScene = -1;

    GLuint mapTextureID = Util::LoadTexture("sokoban_tilesheet.png");
    state.map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, level1_data, mapTextureID, 1.0f, 13, 8);


    state.player = new Entity();
    state.player->entityType = PLAYER;
    state.player->position = glm::vec3(0, 0, 0);
    state.player->movement = glm::vec3(0);
    state.player->acceleration = glm::vec3(0, -9.8f, 0);
    state.player->speed = 3.0f;
    state.player->height = 0.8f;
    state.player->width = 0.5f;
    state.player->textureID = Util::LoadTexture("sokoban_tilesheet.png");

    state.player->animRight = new int[3]{ 91, 92, 93 };
    state.player->animLeft = new int[3]{ 94, 95, 96 };
    state.player->animUp = new int[4]{ 2, 6, 10, 14 };
    state.player->animDown = new int[4]{ 0, 4, 8, 12 };

    state.player->animIndices = state.player->animRight;
    state.player->animFrames = 3;
    state.player->animIndex = 0;
    state.player->animTime = 0;
    state.player->animCols = 13;
    state.player->animRows = 8;

    state.player->jumpPower = 10.0f;


    state.enemies = new Entity[LEVEL1_ENEMY_COUNT];
    GLuint enemyTextureID = Util::LoadTexture("mike.png");

    state.enemies[0].entityType = ENEMY;
    state.enemies[0].textureID = enemyTextureID;
    state.enemies[0].position = glm::vec3(13, -82, 0);
    state.enemies[0].movement = glm::vec3(0, 0, 0);
    state.enemies[0].height = 0.8f;
    state.enemies[0].width = 0.4f;
    state.enemies[0].acceleration = glm::vec3(0, -9.8f, 0);
    state.enemies[0].speed = 1.0f;
    state.enemies[0].aiType = WAITANDGO;
    state.enemies[0].aiState = IDLE;
    //state.enemies[0].isActive = false;

    state.enemies[1].entityType = ENEMY;
    state.enemies[1].textureID = enemyTextureID;
    state.enemies[1].position = glm::vec3(8, -72, 0);
    state.enemies[1].height = 0.8f;
    state.enemies[1].width = 0.4f;
    state.enemies[1].acceleration = glm::vec3(0, -9.8f, 0);
    state.enemies[1].speed = 1.5f;
    state.enemies[1].aiType = WAITANDGO;
    state.enemies[1].aiState = IDLE;

    state.enemies[2].entityType = ENEMY;
    state.enemies[2].textureID = enemyTextureID;
    state.enemies[2].position = glm::vec3(5, -63, 0);
    state.enemies[2].height = 0.8f;
    state.enemies[2].width = 0.4f;
    state.enemies[2].acceleration = glm::vec3(0, 0, 0);
    state.enemies[2].speed = 3.0f;
    state.enemies[2].aiType = WALKER;
    state.enemies[2].aiState = WALKING;

    state.enemies[3].entityType = ENEMY;
    state.enemies[3].textureID = enemyTextureID;
    state.enemies[3].position = glm::vec3(1, -55, 0);
    state.enemies[3].height = 0.8f;
    state.enemies[3].width = 0.4f;
    state.enemies[3].acceleration = glm::vec3(0, 0, 0);
    state.enemies[3].speed = 3.0f;
    state.enemies[3].aiType = WALKER;
    state.enemies[3].aiState = WALKING;

    state.enemies[4].entityType = ENEMY;
    state.enemies[4].textureID = enemyTextureID;
    state.enemies[4].position = glm::vec3(6, -53, 0);
    state.enemies[4].height = 0.8f;
    state.enemies[4].width = 0.4f;
    state.enemies[4].acceleration = glm::vec3(0, 0, 0);
    state.enemies[4].speed = 3.0f;
    state.enemies[4].aiType = WALKER;
    state.enemies[4].aiState = WALKING;

    state.enemies[5].entityType = ENEMY;
    state.enemies[5].textureID = enemyTextureID;
    state.enemies[5].position = glm::vec3(11, -51, 0);
    state.enemies[5].height = 0.8f;
    state.enemies[5].width = 0.4f;
    state.enemies[5].acceleration = glm::vec3(0, 0, 0);
    state.enemies[5].speed = 3.0f;
    state.enemies[5].aiType = WALKER;
    state.enemies[5].aiState = WALKING;

    state.enemies[6].entityType = ENEMY;
    state.enemies[6].textureID = enemyTextureID;
    state.enemies[6].position = glm::vec3(1, -49, 0);
    state.enemies[6].height = 0.8f;
    state.enemies[6].width = 0.4f;
    state.enemies[6].acceleration = glm::vec3(0, 0, 0);
    state.enemies[6].speed = 3.0f;
    state.enemies[6].aiType = WALKER;
    state.enemies[6].aiState = WALKING;

    state.enemies[7].entityType = ENEMY;
    state.enemies[7].textureID = enemyTextureID;
    state.enemies[7].position = glm::vec3(6, -47, 0);
    state.enemies[7].height = 0.8f;
    state.enemies[7].width = 0.4f;
    state.enemies[7].acceleration = glm::vec3(0, 0, 0);
    state.enemies[7].speed = 3.0f;
    state.enemies[7].aiType = WALKER;
    state.enemies[7].aiState = WALKING;

    state.enemies[8].entityType = ENEMY;
    state.enemies[8].textureID = enemyTextureID;
    state.enemies[8].position = glm::vec3(11, -45, 0);
    state.enemies[8].height = 0.8f;
    state.enemies[8].width = 0.4f;
    state.enemies[8].acceleration = glm::vec3(0, 0, 0);
    state.enemies[8].speed = 3.0f;
    state.enemies[8].aiType = WALKER;
    state.enemies[8].aiState = WALKING;

    state.enemies[9].entityType = ENEMY;
    state.enemies[9].textureID = enemyTextureID;
    state.enemies[9].position = glm::vec3(1, -41, 0);
    state.enemies[9].height = 0.8f;
    state.enemies[9].width = 0.4f;
    state.enemies[9].acceleration = glm::vec3(0, 0, 0);
    state.enemies[9].speed = 3.0f;
    state.enemies[9].aiType = WALKER;
    state.enemies[9].aiState = WALKING;

    state.enemies[10].entityType = ENEMY;
    state.enemies[10].textureID = enemyTextureID;
    state.enemies[10].position = glm::vec3(1, -40, 0);
    state.enemies[10].height = 0.8f;
    state.enemies[10].width = 0.4f;
    state.enemies[10].acceleration = glm::vec3(0, 0, 0);
    state.enemies[10].speed = 3.0f;
    state.enemies[10].aiType = WALKER;
    state.enemies[10].aiState = WALKING;

    state.enemies[11].entityType = ENEMY;
    state.enemies[11].textureID = enemyTextureID;
    state.enemies[11].position = glm::vec3(6, -33, 0);
    state.enemies[11].height = 0.8f;
    state.enemies[11].width = 0.4f;
    state.enemies[11].acceleration = glm::vec3(0, 0, 0);
    state.enemies[11].speed = 3.0f;
    state.enemies[11].aiType = WALKER;
    state.enemies[11].aiState = RISING;

    state.enemies[12].entityType = ENEMY;
    state.enemies[12].textureID = enemyTextureID;
    state.enemies[12].position = glm::vec3(6, -28, 0);
    state.enemies[12].height = 0.8f;
    state.enemies[12].width = 0.4f;
    state.enemies[12].acceleration = glm::vec3(0, 0, 0);
    state.enemies[12].speed = 3.0f;
    state.enemies[12].aiType = WALKER;
    state.enemies[12].aiState = RISING;

    state.enemies[13].entityType = ENEMY;
    state.enemies[13].textureID = enemyTextureID;
    state.enemies[13].position = glm::vec3(6, -23, 0);
    state.enemies[13].height = 0.8f;
    state.enemies[13].width = 0.4f;
    state.enemies[13].acceleration = glm::vec3(0, 0, 0);
    state.enemies[13].speed = 3.0f;
    state.enemies[13].aiType = WALKER;
    state.enemies[13].aiState = RISING;

    state.enemies[14].entityType = ENEMY;
    state.enemies[14].textureID = enemyTextureID;
    state.enemies[14].position = glm::vec3(6, -18, 0);
    state.enemies[14].height = 0.8f;
    state.enemies[14].width = 0.4f;
    state.enemies[14].acceleration = glm::vec3(0, 0, 0);
    state.enemies[14].speed = 3.0f;
    state.enemies[14].aiType = WALKER;
    state.enemies[14].aiState = RISING;

    state.enemies[15].entityType = ENEMY;
    state.enemies[15].textureID = enemyTextureID;
    state.enemies[15].position = glm::vec3(10, -18, 0);
    state.enemies[15].height = 0.8f;
    state.enemies[15].width = 0.4f;
    state.enemies[15].acceleration = glm::vec3(0, 0, 0);
    state.enemies[15].speed = 5.0f;
    state.enemies[15].aiType = WALKER;
    state.enemies[15].aiState = RISING;

    state.enemies[16].entityType = ENEMY;
    state.enemies[16].textureID = enemyTextureID;
    state.enemies[16].position = glm::vec3(11, -18, 0);
    state.enemies[16].height = 0.8f;
    state.enemies[16].width = 0.4f;
    state.enemies[16].acceleration = glm::vec3(0, 0, 0);
    state.enemies[16].speed = 5.0f;
    state.enemies[16].aiType = WALKER;
    state.enemies[16].aiState = RISING;

    fonttextureID = Util::LoadTexture("font2.png");
}
void Level1::Update(float deltaTime) {

    if (state.player->position.x >= 13 && state.player->position.y >= 0) {
        return;
    }

    if (state.player->position.y < -100) {
        state.player->position = glm::vec3(1, -95, 0);
        lives--;
    }

    if (state.enemies[2].position.x > 15) {
        state.enemies[2].position = glm::vec3(5, -63, 0);
    }

    if (state.enemies[11].collidedTop) {
        state.enemies[11].position = glm::vec3(6, -32, 0);
    }

    if (state.enemies[12].collidedTop) {
        state.enemies[12].position = glm::vec3(6, -32, 0);
    }

    if (state.enemies[13].collidedTop) {
        state.enemies[13].position = glm::vec3(6, -32, 0);
    }

    if (state.enemies[14].collidedTop) {
        state.enemies[14].position = glm::vec3(6, -32, 0);
    }

    if (state.enemies[15].collidedTop) {
        state.enemies[15].position = glm::vec3(10, -33, 0);
    }

    if (state.enemies[16].collidedTop) {
        state.enemies[16].position = glm::vec3(11, -33, 0);
    }

    for (int i = 3; i < LEVEL1_ENEMY_COUNT; i++) {
        if (state.enemies[i].position.x > 15) {
            state.enemies[i].position.x = 1;
        }
    }



    

    if (lives == 0) {
        state.nextScene = 1;
        return;
    }
	state.player->Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.map);

    for (int i = 0; i < LEVEL1_ENEMY_COUNT; i++) {
        state.enemies[i].Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.map);
    }
    /*state.enemies[0].Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.map);
    state.enemies[1].Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.map);
    state.enemies[2].Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.map);
    state.enemies[3].Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.map);*/

    /*if (state.player->position.x >= 12) {
        state.nextScene = 1;
    }*/

    if (state.player->lastCollision == ENEMY) {
        //state.player->position = glm::vec3(5, 0, 0);
        //state.player->lastCollision = PLATFORM;
        lives--;
    }
}
void Level1::Render(ShaderProgram* program) {
	state.map->Render(program);
	state.player->Render(program);
    for (int i = 0; i < LEVEL1_ENEMY_COUNT; i++) {
        state.enemies[i].Render(program);
    }
    if (state.player->position.x >= 13 && state.player->position.y >= 0) {
        Util::DrawText(program, fonttextureID, "You Win!", 1, -0.5f, glm::vec3(13, 0, 0));
    }
}