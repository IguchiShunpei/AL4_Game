#pragma once
#include "Input.h"
#include "MathFunc.h"
#include "GameObject3D.h"

class Ground
{
	//�R���X�g���N�^
public:
	Ground();
	~Ground();

public:
	void Initialize(ViewProjection* viewProjection, Matrix4* matProjection);

	void Update();

	void Draw();


	//�����o�ϐ�
private:
	GameObject3D* gameObject_ = nullptr;	//�n��
	const int fenceLen_ = 4;
	GameObject3D* fence_[4] = {};	//�t�F���X



	Input& input_ = Input::GetInstance();

	ViewProjection* viewProjection_ = nullptr;
};

