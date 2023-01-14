#pragma once
#include "Input.h"
#include "MathFunc.h"
#include "GameObject3D.h"

class Ground
{
	//コンストラクタ
public:
	Ground();
	~Ground();

public:
	void Initialize(ViewProjection* viewProjection, Matrix4* matProjection);

	void Update();

	void Draw();


	//メンバ変数
private:
	GameObject3D* gameObject_ = nullptr;	//地面
	const int fenceLen_ = 4;
	GameObject3D* fence_[4] = {};	//フェンス



	Input& input_ = Input::GetInstance();

	ViewProjection* viewProjection_ = nullptr;
};

