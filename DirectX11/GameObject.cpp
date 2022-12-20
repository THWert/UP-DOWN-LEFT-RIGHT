#include "framework.h"

GameObject::GameObject()
{
	position = Vector2(0.0f, 0.0f);
	scale = Vector2(1.0f, 1.0f);
	rotation = 0.0f;
	isAxis = false;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	S = Matrix::CreateScale(scale.x, scale.y, 1.0f);
	R = Matrix::CreateRotationZ(rotation);
	T = Matrix::CreateTranslation(position.x, position.y, 0.0f);

	W = S * R * T;
}

void GameObject::Render()
{
	if (isAxis)
	{
		//xÃà
		axis->position = position;
		axis->scale.x = scale.x;
		axis->rotation = rotation;
		axis->Update();
		axis->Render();

		//yÃà
		axis->scale.x = scale.y;
		axis->rotation = rotation + DIV2PI;
		axis->Update();
		axis->Render();
	}
}

ObLine* GameObject::axis = nullptr;

void GameObject::CreateStaticMember()
{
	axis = new ObLine();
}

void GameObject::DeleteStaticMember()
{
	delete axis;
}
