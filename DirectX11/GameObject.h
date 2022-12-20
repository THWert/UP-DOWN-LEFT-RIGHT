#pragma once
class ObLine; //전방선언

class GameObject
{
public:
	static ObLine* axis;

	Vector2 position; //중점
	Vector2 scale; //크기값
	float rotation; //회전값
	bool isAxis;

	Matrix S, R, T, W;

public:
	GameObject();
	virtual ~GameObject();

	//가상함수
	//자식이 재정의 할 것이라고 예상될 때 사용
	virtual void Update();
	virtual void Render();

	static void CreateStaticMember();
	static void DeleteStaticMember();
};

