#pragma once
class MainGame : public Scene
{
private:
	ObRect rc;

public:
	~MainGame() override;
	//�� �ʱ�ȭ
	virtual void Init() override;
	//�� ����
	virtual void Update() override;
	//�� ���
	virtual void Render() override;
};

