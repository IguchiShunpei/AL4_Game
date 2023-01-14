#pragma once
#include "GameObject3D.h"
#include "MathFunc.h"
#include "Vector3.h"

class Player;

class GameScene;


class Enemy
{
public:
	Enemy();
	~Enemy();
	//初期化
	void Initialize(ViewProjection* viewProjection, Matrix4* matProjection);
	//更新
	void Update();
	//描画
	void Draw();
	//弾発射
	void Fire();
	//playerのsetter
	void SetPlayer(Player* player) { player_ = player; }

	//ワールド座標を取得
	Vector3 GetWorldPosition();

private:
	//ワールドトランスフォーム
	WorldTransform worldTransform_;

	Vector3* vector3_ = nullptr;
	//オブジェクト
	GameObject3D* gameObject_ = nullptr;
	//ゲームシーン
	GameScene* gameScene_ = nullptr;
	//速度
	Vector3 velocity_ = { 0.0f,0.0f,0.1f };
	//打ち出すまでの時間
	float delayTimer = 0.0f;
	//自キャラ
	Player* player_ = nullptr;

	//半径
	float radius = 1.0f;
};

