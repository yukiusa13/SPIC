#pragma once

struct Rect
{
	float top;
	float under;
	float left;
	float right;
};
//OBJ�N���X
class OBJ
{
private:
	int state;
	//�O�t���[���̏�ԑJ�ڂ̕ۑ���
	int Previous_state;
	//�A�j���[�V�������֘A
	int animetimer;
	int chipcou;
	int chipx;
	int chipy;
	//int switching_time;
	//������
	void chip_reset();
	//�A�j���[�V�����^�C�}�[���������邽�߂̃t���O�Ԃ��֐�
	bool timer_init(int STATE);
public:
	OBJ();
	Rect rect;
	void set_state(int STATE);
	int get_state();
	VECTOR2 pos;
	bool exist;
    //�摜�f�[�^
    //�؂�ւ�����(�t���[���P��)
    //���A�c�̃`�b�v�̌�(x,y)
    //�`�b�v�̑���
    //�`�ʈʒu(x,y)
    //�X�P�[��(x,y)
    //�摜�̊J�n�ʒu(x,y)
    //1�`�b�v�̑傫��(x,y)
    //��_(x,y)
    //�p�x
    //�F(r,g,b,a)
	void anim(GameLib::Sprite* data,
		const int time,
		int NumX, int NumY,
		int max,
		float posx, float posy,
		float sclx, float scly,
		float dataposx, float dataposy,
		float sizex, float sizey,
		float StandardX = 0.0f, float StandardY = 0.0f,
		float rad = 0.0f,
		float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);
	//�摜�f�[�^
    //���[�V�����I����̏��
    //�؂�ւ�����(�t���[���P��)
    //���A�c�̃`�b�v�̌�(x,y)
    //�`�b�v�̑���
    //�`�ʈʒu(x,y)
    //�X�P�[��(x,y)
    //�摜�̊J�n�ʒu(x,y)
    //1�`�b�v�̑傫��(x,y)
    //��_(x,y)
    //�p�x
    //�F(r,g,b,a)
	void motion(GameLib::Sprite* data,
		int after,
		const int time,
		int NumX, int NumY,
		int max,
		float posx, float posy,
		float sclx, float scly,
		float dataposx, float dataposy,
		float sizex, float sizey,
		float StandardX = 0.0f, float StandardY = 0.0f,
		float rad = 0.0f,
		float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);
};

class VOLCANO :
	public OBJ
{
private:
	int timer;
	float fin_pos;
public:
	VOLCANO() { pos.x = 1920; }
	void init(float begin_posy,float fin_posx);
	void update();
	void draw();

};

#define judge (0)
static class JUDGE
{
public:

#if(judge)
	//�����蔻�����p�̕ϐ�
	//��`�̓����蔻��
	//float px_a,float py_a ->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̍���̍��W(X,Y)
	//int sx_a,int sy_a ->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̉��Əc�̒���(X,Y)
	//float px_a,float py_a ->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̍���̍��W(X,Y)
	//int sx_a,int sy_a ->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̉��Əc�̒���(X,Y)
	bool rect(float px_a, float py_a, int sx_a, int sy_a,
		float px_b, float py_b, int sx_b, int sy_b);
	bool rect(Rect a, Rect b);
#else
	////��`�̓����蔻��
	//�����蔻����s����`�̎l�_�̍��W(top,under,left,right)����RECT�\����
	//�����蔻����s�����W(x,y)����VECTOR2(pos)
	bool rect(float top, float under, float left, float right, float posx, float posy);
	bool rect(float top, float under, float left, float right, VECTOR2 pos);
	bool rect(Rect rect, VECTOR2 pos);
	bool rect(Rect rect, float posx, float posy);
#endif
	//�~�̓����蔻��
	//float px_a,folat py_a->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̒��S���W(X,Y)����VECTOR2(pos)
	//int r_a-> �����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̔��a
	//float px_b,folat py_b->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̒��S���W(X,Y)����VECTOR2(pos)
	//int r_b-> �����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̔��a
	bool circle(float px_a, float py_a, int r_a, float px_b, float py_b, int r_b);
	bool circle(VECTOR2 posa, int r_a, VECTOR2 posb, int r_b);
	bool circle(VECTOR2 posa, int r_a, float px_b, float py_b, int r_b);
	bool circle(float px_a, float py_a, int r_a, VECTOR2 posb, int r_b);

	//���[�U�[�Ƃ̓����蔻��
	//int xory ->�����W�̔��肩�����W�̔���̐ݒ�@(0->x,1->y)
	//float biginpos, float finfin ->����̏���(bigin)�ƏI���(fin)�̍��W
	//float judgepos, float laserwidth ->�����(���[�U�[�̒��S��)�ƕ�(��������烌�[�U�[��)
	bool laser(int xory, float biginpos, float finpos,
		        float judgepos, float laserwidth,
		        VECTOR2 pos, float objwidth);
}Judge;