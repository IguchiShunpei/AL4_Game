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
	gameObject_->worldTransform_.scale_ = { 2,2,2 };
	gameObject_->worldTransform_.translation_ = { 0,0,150.0f };

	collider_ = new Collider();
	collider_->Initialize(&gameObject_->worldTransform_);
	collider_->SetRadius(radius_);
}

void Enemy::Update()
{
	//単位行列を設定
	gameObject_->worldTransform_.matWorld_.SetIdentityMatrix();
	Move();
	gameObject_->Update();
}

void Enemy::Draw()
{
	gameObject_->Draw();
}

void Enemy::Move()
{
	gameObject_->worldTransform_.rotation_ += {0, 0, 0.1f};
	gameObject_->worldTransform_.translation_ += {0, 0, -1.0f};
	if (gameObject_->worldTransform_.translation_.z <= -50)
	{
		isPassed_ = true;
	}
	else
	{
		false;
	}
}

void Enemy::Reset()
{
	gameObject_->worldTransform_.translation_ = { 0,0,100.0f };
	isPassed_ = false;
}

Vector3 Enemy::GetWorldPosition()
{
	//ワールド座標を入れるための変数
	Vector3 worldPos;

	//ワールド行列の平行移動成分を取得
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

void Enemy::SetCollider(Collider* collider)
{
	collider_ = collider;
}
