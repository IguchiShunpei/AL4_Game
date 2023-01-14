#pragma once
#include "WorldTransform.h"
#include "MathFunc.h"

class Collider {
public:

	//コンストラクタ
	Collider();

	//デストラクタ
	~Collider();

	//メンバ関数
	void Initialize(WorldTransform* parent);

	void Update();

	bool CheckCollision(Collider collider);

	//アクセッサ
	void SetRadius(float radius);
	Vector3 GetWorldPos();

	//メンバ変数
private:
	WorldTransform worldTransform_;
	float radius_ = 1.0f;
};