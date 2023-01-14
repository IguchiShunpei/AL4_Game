#include "Player.h"
Player::Player()
{

}

Player::~Player()
{
	delete gameObject_;
}

void Player::Initialize(ViewProjection* viewProjection, Matrix4* matProjection)
{
	gameObject_ = new GameObject3D();
	gameObject_->SetMatProjection(matProjection);
	gameObject_->SetViewProjection(viewProjection);
	gameObject_->Initialize();
};

void Player::Update()
{
	Move();
	gameObject_->Update();
};

void Player::Draw()
{
	gameObject_->Draw();
};

void Player::Move()
{
	Vector3 move = { 0,0,0 };
	const float kCharacterSpeed = 0.5f;

	//�����������ňړ��ʂ�ω�
	if (input.PushKey(DIK_RIGHT))
	{
		move.x = kCharacterSpeed;
	}
	else if (input.PushKey(DIK_LEFT))
	{
		move.x = -kCharacterSpeed;
	}

	if (input.PushKey(DIK_UP))
	{
		move.y = kCharacterSpeed;
	}
	else if (input.PushKey(DIK_DOWN))
	{
		move.y = -kCharacterSpeed;
	}

	//�ړ����E���W
	const float kMoveLimitX = 35.0f;
	const float kMoveLimitY = 19.3f;

	gameObject_->worldTransform_.translation_ += move;

	//�͈͂𒴂��Ȃ�����
	gameObject_->worldTransform_.translation_.x = max(gameObject_->worldTransform_.translation_.x, -kMoveLimitX);
	gameObject_->worldTransform_.translation_.x = min(gameObject_->worldTransform_.translation_.x, +kMoveLimitX);
	gameObject_->worldTransform_.translation_.y = max(gameObject_->worldTransform_.translation_.y, -kMoveLimitY);
	gameObject_->worldTransform_.translation_.y = min(gameObject_->worldTransform_.translation_.y, +kMoveLimitY);
}

Vector3 Player::GetWorldPosition()
{
	//���[���h���W�����邽�߂̕ϐ�
	Vector3 worldPos;

	//���[���h�s��̕��s�ړ��������擾
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

float Player::GetRadius()
{
	return radius;
}
