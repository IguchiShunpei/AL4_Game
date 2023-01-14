#include "GameScene.h"

GameScene::GameScene() {

}

GameScene::~GameScene() {

	delete player_;
	delete enemy_;
}

void GameScene::Initialize(WinApp* winApp) {

	//透視投影変換行列の計算
	matProjection_ = MathFunc::Utility::PerspectiveFovLH(
		MathFunc::Utility::Deg2Rad(45.0) ,
		(float)winApp->window_width / winApp->window_height ,
		0.1f , 1000.0f
	);

	viewProjection_.Initialize();
	
	player_ = new Player();
	player_->Initialize(&viewProjection_, &matProjection_);

	enemy_ = new Enemy();
	enemy_->Initialize(&viewProjection_, &matProjection_);
}

void GameScene::Update() {

	viewProjection_.UpdateView();

	player_->Update();
	enemy_->Update();
}

void GameScene::Draw() {


	//3D描画
	//3D描画
	player_->Draw();
	enemy_->Draw();

	//スプライト描画
	Sprite::PreDraw(dx12base_.GetCmdList().Get());

	Sprite::PostDraw();

}
