#pragma once
#include "GameObject3D.h"
#include "Input.h"
#include "MathFunc.h"
#include "Collider.h"

class Enemy;

class Player
{
public:
	Player();
	~Player();
	//初期化
	void Initialize(ViewProjection* viewProjection, Matrix4* matProjection);
	//更新
	void Update();
	//描画
	void Draw();
	//移動
	void Move();
	//リセット
	void Reset();
	//ワールド座標を取得
	Vector3 GetWorldPosition();
	
	//Enemyのsetter
	void SetEnemy(Enemy* enemy);

	//半径を返す関数
	float GetRadius();
	//フラグを返す
	bool GetIsHit();
private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//オブジェクト
	GameObject3D* gameObject_ = nullptr;
	//当たり判定
	Collider* collider_ = nullptr;
	//敵
	Enemy* enemy_ = nullptr;
	//キー入力
	Input& input = Input::GetInstance();
	//当たったか
	bool isHit_ = false;
	//半径
	float radius_ = 1.0f;
};
