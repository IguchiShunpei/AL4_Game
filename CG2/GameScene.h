#pragma once
#include "Input.h"
#include "DX12base.h"
#include"GameObject3D.h"
#include "WinApp.h"
#include "ViewProjection.h"

#include "Audio.h"
#include <xaudio2.h>
#pragma comment(lib,"xaudio2.lib")
#include "Sprite.h"

#include "Player.h"
#include "Enemy.h"

class GameScene {

public: // メンバ関数

	//コンストラクタ
	GameScene();

	/// デストラクタ
	~GameScene();

	//初期化
	void Initialize(WinApp* winApp);

	//毎フレーム処理
	void Update();

	//描画処理
	void Draw();

private: // メンバ変数
	WinApp* winApp_ = nullptr;
	DX12base& dx12base_ = DX12base::GetInstance();
	Input& input_ = Input::GetInstance();
	Matrix4 matProjection_ = {};
	SoundManager soundManager_;

	ViewProjection viewProjection_;

	//シーン
	enum class Scene
	{
		Title,
		Explanation,
		GameScene,
		Clear,
		GameOver,
	};

	Scene scene_ = Scene::Title;

	//プレイヤー
	Player* player_ = nullptr;
	//敵
	Enemy* enemy_ = nullptr;
	//画像
	Sprite* title_ = nullptr;
	Sprite* explanetion_ = nullptr;
	Sprite* clear_ = nullptr;
	Sprite* gameOver_ = nullptr;
	Sprite* space_ = nullptr;
};