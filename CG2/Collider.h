#pragma once
#include "WorldTransform.h"
#include "MathFunc.h"

class Collider {
public:

	//�R���X�g���N�^
	Collider();

	//�f�X�g���N�^
	~Collider();

	//�����o�֐�
	void Initialize(WorldTransform* parent);

	void Update();

	bool CheckCollision(Collider collider);

	//�A�N�Z�b�T
	void SetRadius(float radius);
	Vector3 GetWorldPos();

	//�����o�ϐ�
private:
	WorldTransform worldTransform_;
	float radius_ = 1.0f;
};