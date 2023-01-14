#pragma once
#include <math.h>
#include <DirectXMath.h>
using namespace DirectX;

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"

namespace MathFunc {

	const float PI = 3.141592f;
	const float G = 2.0f;

	namespace Affine {
		//���[���h�ϊ��s���ݒ肷��֐�
		void SetMatScale(Matrix4& affineMat, Vector3 scale);				//�X�P�[�����O�s���ݒ肷��֐�
		void SetMatRotation(Matrix4& affineMat, Vector3 rotation);			//��]�s���ݒ肷��֐�
		void SetMatTranslation(Matrix4& affineMat, Vector3 translation);	//���s�ړ��s��̐ݒ������֐�

		//���[���h�ϊ��s��𐶐�����֐�
		Matrix4 CreateMatScale(Vector3 scale);				//�X�P�[�����O�s��𐶐�����֐�
		Matrix4 CreateMatRotation(Vector3 rotation);		//��]�s��𐶐�����֐�
		Matrix4 CreateMatTranslation(Vector3 translation);	//���s�ړ��s��̐���������֐�

	}

	namespace Utility {
		//XMMATRIX��Matrix4�ɕϊ�����֐�
		Matrix4 ConvertXMMATRIXtoMatrix4(XMMATRIX xmMatrix);

		//�r���[�s��𐶐�����֐�
		Matrix4 CreatMatView(Vector3 eye, Vector3 target, Vector3 up);

		//�x���@�̌ʓx�@�̊֐�
		float Deg2Rad(float Deg);	//�x���@���ʓx�@�ɕϊ�����֐�
		float Rad2Deg(float rad);	//�ʓx�@��x���@�ɕϊ�����֐�

		//�x�N�g���ƍs��̊|���Z������֐�
		Vector3 MulVector3AndMatrix4(Vector3 vec, Matrix4 mat);

		Matrix4 PerspectiveFovLH(float fovAngleY, float  aspectRatio, float  nearZ, float farZ);
	}

	namespace Ease {
		double In(double start, double end, double time, double max_time);

		double Out(double start, double end, double time, double max_time);

		double InOut(double start, double end, double time, double max_time);

		double In_Back(double start, double end, double time, double max_time);

		double Out_Back(double start, double end, double time, double max_time);

		double InOut_Back(double start, double end, double time, double max_time);

		double Out_Bounce(double start, double end, double time, double max_time);

		double In_Bounce(double start, double end, double time, double max_time);

		double InOut_Bounce(double start, double end, double time, double max_time);
	}

}