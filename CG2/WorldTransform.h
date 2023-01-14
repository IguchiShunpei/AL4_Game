#pragma once
#include "Vector3.h"
#include "Matrix4.h"
#include "MathFunc.h"

class WorldTransform {
public:
	//�����o�֐�
	void Initialize();

	//���[���h�ϊ��s��̍X�V
	void UpdateMatWorld();

	//�����o�ϐ�
	//�X�P�[��
	Vector3 scale_;
	//XYZ����]
	Vector3 rotation_;
	//���[�J�����W
	Vector3 translation_;
	//���[���h�ϊ��s��
	Matrix4 matWorld_;
	//�e�I�u�W�F�N�g�̃��[���h�ϊ��̃|�C���^
	WorldTransform* parent_ = nullptr;

};

