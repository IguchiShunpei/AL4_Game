#include "Enemy.h"
#include "Player.h"
#include "GameScene.h"
Enemy::Enemy()
{

}

Enemy::~Enemy()
{
	delete gameObject_;
}

void Enemy::Initialize(ViewProjection* viewProjection, Matrix4* matProjection)
{
	gameObject_ = new GameObject3D();
	gameObject_->PreLoadModel("Resources/enemy/enemy.obj");
	gameObject_->PreLoadTexture(L"Resources/enemy/gold.png");
	gameObject_->SetMatProjection(matProjection);
	gameObject_->SetViewProjection(viewProjection);
	gameObject_->Initialize();
	//�����ʒu��ݒ�
	gameObject_->worldTransform_.translation_ = { 0,20,50 };

}

void Enemy::Update()
{
	//�P�ʍs���ݒ�
	gameObject_->worldTransform_.matWorld_.SetIdentityMatrix();
	Fire();
	gameObject_->Update();
}

void Enemy::Draw()
{
	gameObject_->Draw();
}

void Enemy::Fire()
{

}

Vector3 Enemy::GetWorldPosition()
{
	//���[���h���W�����邽�߂̕ϐ�
	Vector3 worldPos;

	//���[���h�s��̕��s�ړ��������擾
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}
