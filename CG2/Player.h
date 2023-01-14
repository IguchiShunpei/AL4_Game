#pragma once
#include "GameObject3D.h"
#include "Input.h"
#include "MathFunc.h"

class Player
{
public:
	Player();
	~Player();
	//������
	void Initialize(ViewProjection* viewProjection, Matrix4* matProjection);
	//�X�V
	void Update();
	//�`��
	void Draw();
	//�ړ�
	void Move();

	//���[���h���W���擾
	Vector3 GetWorldPosition();
	
	//���a��Ԃ��֐�
	float GetRadius();
private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//�I�u�W�F�N�g
	GameObject3D* gameObject_ = nullptr;

	//�L�[����
	Input& input = Input::GetInstance();

	//���a
	float radius = 1.0f;
};
