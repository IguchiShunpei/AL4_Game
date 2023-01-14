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
	//������
	void Initialize(ViewProjection* viewProjection, Matrix4* matProjection);
	//�X�V
	void Update();
	//�`��
	void Draw();
	//�e����
	void Fire();
	//player��setter
	void SetPlayer(Player* player) { player_ = player; }

	//���[���h���W���擾
	Vector3 GetWorldPosition();

private:
	//���[���h�g�����X�t�H�[��
	WorldTransform worldTransform_;

	Vector3* vector3_ = nullptr;
	//�I�u�W�F�N�g
	GameObject3D* gameObject_ = nullptr;
	//�Q�[���V�[��
	GameScene* gameScene_ = nullptr;
	//���x
	Vector3 velocity_ = { 0.0f,0.0f,0.1f };
	//�ł��o���܂ł̎���
	float delayTimer = 0.0f;
	//���L����
	Player* player_ = nullptr;

	//���a
	float radius = 1.0f;
};

