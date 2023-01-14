#pragma once
#include "GameObject3D.h"
#include "Input.h"
#include "MathFunc.h"

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

	//ワールド座標を取得
	Vector3 GetWorldPosition();
	
	//半径を返す関数
	float GetRadius();
private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//オブジェクト
	GameObject3D* gameObject_ = nullptr;

	//キー入力
	Input& input = Input::GetInstance();

	//半径
	float radius = 1.0f;
};
