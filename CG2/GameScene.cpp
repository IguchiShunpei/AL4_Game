#include "GameScene.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

	delete player_;
	delete enemy_;
	delete title_;
	delete explanetion_;
	delete clear_;
	delete gameOver_;
}

void GameScene::Initialize(WinApp* winApp)
{

	//透視投影変換行列の計算
	matProjection_ = MathFunc::Utility::PerspectiveFovLH(
		MathFunc::Utility::Deg2Rad(45.0),
		(float)winApp->window_width / winApp->window_height,
		0.1f, 1000.0f
	);

	viewProjection_.Initialize();

	enemy_ = new Enemy();
	enemy_->Initialize(&viewProjection_, &matProjection_);

	player_ = new Player();
	player_->Initialize(&viewProjection_, &matProjection_);
	player_->SetEnemy(enemy_);

	Sprite::LoadTexture(1, L"Resources/title.png");
	Sprite::LoadTexture(2, L"Resources/explanation.png");
	Sprite::LoadTexture(3, L"Resources/clear.png");
	Sprite::LoadTexture(4, L"Resources/gameOver.png");
	Sprite::LoadTexture(5, L"Resources/space.png");

	title_ = Sprite::Create(1, { 0,0 });
	explanetion_ = Sprite::Create(2, { 0,0 });
	clear_ = Sprite::Create(3, { 0,0 });
	gameOver_ = Sprite::Create(4, { 0,0 });
	space_ = Sprite::Create(5, { 0,0 });
}

void GameScene::Update()
{

	viewProjection_.UpdateView();

	switch (scene_)
	{
		//タイトル
	case GameScene::Scene::Title:

		if (input_.TriggerKey(DIK_SPACE))
		{
			scene_ = GameScene::Scene::Explanation;
		}
		break;
		//操作説明画面
	case GameScene::Scene::Explanation:
		if (input_.TriggerKey(DIK_SPACE))
		{
			scene_ = GameScene::Scene::GameScene;
		}
		break;
		//ゲームシーン
	case GameScene::Scene::GameScene:

		player_->Update();
		enemy_->Update();
		if (player_->GetIsHit() == true)
		{
			scene_ = GameScene::Scene::GameOver;
		}
		else if (enemy_->GetIsPassed() == true)
		{
			scene_ = GameScene::Scene::Clear;
		}
		break;
		//ゲームオーバー
	case GameScene::Scene::GameOver:
		if (input_.TriggerKey(DIK_SPACE))
		{
			scene_ = GameScene::Scene::Title;
			player_->Reset();
			enemy_->Reset();
		}
		break;
		//クリア
	case GameScene::Scene::Clear:
		if (input_.TriggerKey(DIK_SPACE))
		{
			scene_ = GameScene::Scene::Title;
			player_->Reset();
			enemy_->Reset();
		}
		break;
	}
}

void GameScene::Draw()
{
	//3D描画
	switch (scene_)
	{
	case GameScene::Scene::Title:
		break;
	case GameScene::Scene::Explanation:
		break;
	case GameScene::Scene::GameScene:
		player_->Draw();
		enemy_->Draw();
		break;
	case GameScene::Scene::Clear:
		break;
	case GameScene::Scene::GameOver:
		break;
	}
	//スプライト描画
	Sprite::PreDraw(dx12base_.GetCmdList().Get());

	switch (scene_)
	{
	case GameScene::Scene::Title:

		title_->Draw();
		space_->Draw();

		break;
	case GameScene::Scene::Explanation:

		explanetion_->Draw();
		space_->Draw();
		break;

	case GameScene::Scene::GameScene:
		break;
	case GameScene::Scene::Clear:
		clear_->Draw();
		space_->Draw();
		break;
	case GameScene::Scene::GameOver:
		gameOver_->Draw();
		space_->Draw();
	}
	Sprite::PostDraw();
}

