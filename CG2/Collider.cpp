#include "Collider.h"

Collider::Collider() {

}

Collider::~Collider() {

}

void Collider::Initialize(WorldTransform* parent) {
	worldTransform_.initialize();
	worldTransform_.parent_ = parent;
}

void Collider::Update() {
	worldTransform_.UpdateMatWorld();
}

bool Collider::CheckCollision(Collider collider) {
	//プレイヤー
	float xMin = worldTransform_.matWorld_.m[3][0] - radius_;

	float xMax = worldTransform_.matWorld_.m[3][0] + radius_;

	float yMin = worldTransform_.matWorld_.m[3][1] - radius_;

	float yMax = worldTransform_.matWorld_.m[3][1] + radius_;

	float zMin = worldTransform_.matWorld_.m[3][2] - radius_;

	float zMax = worldTransform_.matWorld_.m[3][2] + radius_;

	//ステージ

	float cXMin = collider.worldTransform_.matWorld_.m[3][0] - collider.radius_;

	float cXMax = collider.worldTransform_.matWorld_.m[3][0] + collider.radius_;

	float cYMin = collider.worldTransform_.matWorld_.m[3][1] - collider.radius_;

	float cYMax = collider.worldTransform_.matWorld_.m[3][1] + collider.radius_;

	float cZMin = collider.worldTransform_.matWorld_.m[3][2] - collider.radius_;

	float cZMax = collider.worldTransform_.matWorld_.m[3][2] + collider.radius_;

	if ((xMin <= cXMax && xMax >= cXMin) && (yMin <= cYMax && yMax >= cYMin) && (zMin <= cZMax && zMax >= cZMin)) {
		return true;
	}
	return false;
}

void Collider::SetRadius(float radius)
{
	radius_ = radius;
}

Vector3 Collider::GetWorldPos()
{
	Vector3 v = {
		worldTransform_.matWorld_.m[3][0],
		worldTransform_.matWorld_.m[3][1] ,
		worldTransform_.matWorld_.m[3][2]
	};

	return v;
}
