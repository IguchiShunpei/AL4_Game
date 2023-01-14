#include "Player.h"
#include "Enemy.h"
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
	gameObject_->PreLoadModel("Resources/player/player.obj");
	gameObject_->PreLoadTexture(L"Resources/player/cross.png");
	gameObject_->SetMatProjection(matProjection);
	gameObject_->SetViewProjection(viewProjection);
	gameObject_->Initialize();
	gameObject_->worldTransform_.scale_ = { 2,2,2 };
	gameObject_->worldTransform_.translation_ = { 0,-5,0 };

	collider_ = new Collider();
	collider_->Initialize(&gameObject_->worldTransform_);
	collider_->SetRadius(radius_);
};

void Player::Update()
{
	Move();
	gameObject_->Update();
	//当たり判定
	collider_->Update();
};

void Player::Draw()
{
	gameObject_->Draw();
};

void Player::Move()
{
	Vector3 move = { 0,0,0 };
	const float kCharacterSpeed = 0.2f;

	//押した方向で移動量を変化
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

	//移動限界座標
	const float kMoveLimitX = 35.0f;
	const float kMoveLimitY = 19.3f;

	gameObject_->worldTransform_.rotation_ += move;
	gameObject_->worldTransform_.translation_ += move;
	//更新
	gameObject_->Update();
	//当たり判定
	collider_->Update();
	//範囲を超えない処理
	gameObject_->worldTransform_.translation_.x = max(gameObject_->worldTransform_.translation_.x, -kMoveLimitX);
	gameObject_->worldTransform_.translation_.x = min(gameObject_->worldTransform_.translation_.x, +kMoveLimitX);
	gameObject_->worldTransform_.translation_.y = max(gameObject_->worldTransform_.translation_.y, -kMoveLimitY);
	gameObject_->worldTransform_.translation_.y = min(gameObject_->worldTransform_.translation_.y, +kMoveLimitY);

	//敵との当たり判定
	if (collider_->CheckCollision(*enemy_->GetCollider()))
	{
		isHit_ = true;
	}
	else
	{
		isHit_ = false;
	}
}

void Player::Reset()
{
	gameObject_->worldTransform_.translation_ = { 0,-5,0 };
	isHit_ = false;
}

Vector3 Player::GetWorldPosition()
{
	//ワールド座標を入れるための変数
	Vector3 worldPos;

	//ワールド行列の平行移動成分を取得
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

void Player::SetEnemy(Enemy* enemy)
{
	enemy_ = enemy;
}

float Player::GetRadius()
{
	return radius_;
}

bool Player::GetIsHit()
{
	return isHit_;
}