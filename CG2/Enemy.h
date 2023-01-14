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
	//������
	void Initialize(ViewProjection* viewProjection, Matrix4* matProjection);
	//�X�V
	void Update();
	//�`��
	void Draw();
	//�e����
	void Move();
	//player��setter
	void SetPlayer(Player* player) { player_ = player; }
	//���Z�b�g
	void Reset();
	
	//���[���h���W���擾
	Vector3 GetWorldPosition();
	//collider��setter
	void SetCollider(Collider* collider);
	//collider��getter
	Collider* GetCollider() { return collider_; };
	//��ʊO�ɍs������
	bool GetIsPassed() { return isPassed_; };
private:
	//���[���h�g�����X�t�H�[��
	WorldTransform worldTransform_;
	//�����蔻��
	Collider* collider_ = nullptr;
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
	//��ʊO�ɍs������
	bool isPassed_ = false;

	//���a
	float radius_ = 1.0f;
};

