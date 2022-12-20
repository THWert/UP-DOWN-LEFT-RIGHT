#include "framework.h"
#include "MainGame.h"

MainGame::~MainGame()
{
}

void MainGame::Init()
{
    //MemDc �޸𸮻��� dc�� �ϳ� �� �߰�
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //���� �ڵ�
    g_MemDC = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);

    rc.position.x = 400.0f;
    rc.position.y = 300.0f;
    rc.scale = Vector2(100.0f, 100.0f);
    rc.rotation = 0.0f;
    rc.isAxis = true;
}

void MainGame::Update()
{
    if (INPUT->KeyPress(VK_UP))
    {
        //rc.position += Vector2(cosf(DIV2PI * 3.0f), sinf(DIV2PI * 3.0f)) * 200.0f * DELTA;
        rc.position.x += cosf(rc.rotation + 270.0f * ToRadian) * 200.0f * DELTA;
        rc.position.y += sinf(rc.rotation + 270.0f * ToRadian) * 200.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_DOWN))
    {
        //rc.position += Vector2(cosf(DIV2PI), sinf(DIV2PI)) * 200.0f * DELTA;
        rc.position.x += cosf(rc.rotation + 90.0f * ToRadian) * 200.0f * DELTA;
        rc.position.y += sinf(rc.rotation + 90.0f * ToRadian) * 200.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_LEFT))
    {
        //rc.position += Vector2(cosf(PI), sinf(PI)) * 200.0f * DELTA;
        rc.position.x += cosf(rc.rotation + 180.0f * ToRadian) * 200.0f * DELTA;
        rc.position.y += sinf(rc.rotation + 180.0f * ToRadian) * 200.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_RIGHT))
    {
        //rc.position += Vector2(cosf(0), sinf(0)) * 200.0f * DELTA;
        rc.position.x += cosf(rc.rotation + 0.0f * ToRadian) * 200.0f * DELTA;
        rc.position.y += sinf(rc.rotation + 0.0f * ToRadian) * 200.0f * DELTA;
    }

    if (INPUT->KeyPress('5'))
    {
        rc.rotation += 60.0f * ToRadian * DELTA;
    }
    if (INPUT->KeyPress('6'))
    {
        rc.rotation -= 60.0f * ToRadian * DELTA;
    }

    rc.Update();


    //Ű�� ������ �� wm_paint �� �߻� ���Ѷ�
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> ��ȭ��
    g_hdc = BeginPaint(g_hwnd, &ps);

    //������ ���
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);
    string FPS = "FPS : " + to_string(TIMER->GetFPS());
    TextOutA(g_MemDC, 0, 0, FPS.c_str(), FPS.size());

    rc.Render();

    //��� ���� g_MemDC���� g_hdc��
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}