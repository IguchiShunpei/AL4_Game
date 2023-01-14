#include "Ground.h"

Ground::Ground()
{
}

Ground::~Ground()
{
	delete gameObject_;
	for (int i = 0; i < 4;i++) {
		delete fence_[i];
	}
}

void Ground::Initialize(ViewProjection* viewProjection, Matrix4* matProjection)
{
	gameObject_ = new GameObject3D;
	gameObject_->PreLoadTexture(L"Resources/groundTestS.png");
	gameObject_->Initialize();
	gameObject_->SetViewProjection(viewProjection);
	gameObject_->SetMatProjection(matProjection);
	viewProjection_ = viewProjection;

	gameObject_->worldTransform.scale = { 150,1,150 };
	gameObject_->worldTransform.translation = { 0,-2,0 };
	gameObject_->Update();
	

	float fenceRad = 150.0f;
	for (int i = 0; i < fenceLen_; i++) {
		fence_[i] = new GameObject3D;
		fence_[i]->SetViewProjection(viewProjection);
		fence_[i]->SetMatProjection(matProjection);
		fence_[i]->PreLoadTexture(L"Resources/fence.png");
		fence_[i]->Initialize();

		
		fence_[i]->worldTransform.scale = { fenceRad,5,0.2};

		if (i == 0) {
			fence_[i]->worldTransform.translation = { 0,2,fenceRad };
			
		}
		else if (i == 1) {
			fence_[i]->worldTransform.translation = { 0,2,-fenceRad };
		}
		else if (i == 2) {
			fence_[i]->worldTransform.translation = { fenceRad,2,0 };
			fence_[i]->worldTransform.rotation = { 0,0.5 * MathFunc::PI,0 };
		}
		else if (i == 3) {
			fence_[i]->worldTransform.translation = { -fenceRad,2,0 };
			fence_[i]->worldTransform.rotation = { 0,-0.5*MathFunc::PI,0 };
		}
		fence_[i]->Update();
	}

}

void Ground::Update()
{
}

void Ground::Draw()
{
	gameObject_->Draw();
	for (int i = 0; i < fenceLen_; i++) {
		fence_[i]->Draw();
	}
}
