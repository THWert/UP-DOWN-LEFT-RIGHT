#pragma once
class ObLine; //���漱��

class GameObject
{
public:
	static ObLine* axis;

	Vector2 position; //����
	Vector2 scale; //ũ�Ⱚ
	float rotation; //ȸ����
	bool isAxis;

	Matrix S, R, T, W;

public:
	GameObject();
	virtual ~GameObject();

	//�����Լ�
	//�ڽ��� ������ �� ���̶�� ����� �� ���
	virtual void Update();
	virtual void Render();

	static void CreateStaticMember();
	static void DeleteStaticMember();
};

