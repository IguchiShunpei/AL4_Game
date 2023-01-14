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
	//������
	void Initialize(ViewProjection* viewProjection, Matrix4* matProjection);
	//�X�V
	void Update();
	//�`��
	void Draw();
	//�ړ�
	void Move();
	//���Z�b�g
	void Reset();
	//���[���h���W���擾
	Vector3 GetWorldPosition();
	
	//Enemy��setter
	void SetEnemy(Enemy* enemy);

	//���a��Ԃ��֐�
	float GetRadius();
	//�t���O��Ԃ�
	bool GetIsHit();
private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//�I�u�W�F�N�g
	GameObject3D* gameObject_ = nullptr;
	//�����蔻��
	Collider* collider_ = nullptr;
	//�G
	Enemy* enemy_ = nullptr;
	//�L�[����
	Input& input = Input::GetInstance();
	//����������
	bool isHit_ = false;
	//���a
	float radius_ = 1.0f;
};
