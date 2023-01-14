#pragma once
#include "GameObject3D.h"
#include "MathFunc.h"
#include "Collider.h"

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
	void Move();
	//playerのsetter
	void SetPlayer(Player* player) { player_ = player; }
	//リセット
	void Reset();
	
	//ワールド座標を取得
	Vector3 GetWorldPosition();
	//colliderのsetter
	void SetCollider(Collider* collider);
	//colliderのgetter
	Collider* GetCollider() { return collider_; };
	//画面外に行ったか
	bool GetIsPassed() { return isPassed_; };
private:
	//ワールドトランスフォーム
	WorldTransform worldTransform_;
	//当たり判定
	Collider* collider_ = nullptr;
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
	//画面外に行ったか
	bool isPassed_ = false;

	//半径
	float radius_ = 1.0f;
};

