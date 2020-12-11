
// Finalproject20162318View.cpp: CFinalproject20162318View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Finalproject20162318.h"
#endif

#include "Finalproject20162318Doc.h"
#include "Finalproject20162318View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define BSIZE 20
#define WIDE 30
#define RADIUS 40
#define KINGRADIUS 55


// CFinalproject20162318View

IMPLEMENT_DYNCREATE(CFinalproject20162318View, CView)

BEGIN_MESSAGE_MAP(CFinalproject20162318View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CFinalproject20162318View 생성/소멸

CFinalproject20162318View::CFinalproject20162318View() noexcept
	:m_WinRight(0)
	,m_WinBottom(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_Ball.x = 710;
	m_Ball.y = 300;
	m_KingBomb.x = -50;
	m_KingBomb.y = -50;
	m_Bomb2.x = -60;
	m_Bomb2.y = -30;
	m_Bomb3.x = -300;
	m_Bomb3.y = -30;
	m_Bomb4.x = -600;
	m_Bomb4.y = -30;
	m_Bomb5.x = -900;
	m_Bomb5.y = -30;
	m_Bomb6.x = -1200;
	m_Bomb6.y = -30;
	m_xStep = 0;
	m_yStep = 0;
	m_xStep2 = 0;
	m_yStep2 = 0;
	m_xStep3 = 0;
	m_yStep3 = 0;
	m_xStep4 = 0;
	m_yStep4 = 0;
	m_xStep5 = 0;
	m_yStep5 = 0;
	m_xStep6 = 0;
	m_yStep6 = 0;
	m_xStep7 = 0;
	m_yStep7 = 0;
	m_Ship.x = -30;
	m_Ship.y = -30;
	m_count = 0;
	m_direction = 0;

}

CFinalproject20162318View::~CFinalproject20162318View()
{
}

BOOL CFinalproject20162318View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFinalproject20162318View 그리기

void CFinalproject20162318View::OnDraw(CDC* pDC)
{
	CFinalproject20162318Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CBitmap back;
	back.LoadBitmapW(IDB_BIT_BACK);
	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	mdc.SelectObject(&back);
	pDC->StretchBlt(0-m_count, 0, 1200, m_WinBottom, &mdc, 0, 0, 1200, 900, SRCCOPY);
	pDC->StretchBlt(1200-m_count, 0, 1200, m_WinBottom, &mdc, 0, 0, 1200, 900, SRCCOPY);

	CBitmap KingBomb, Bomb;
	CDC memdc;
	memdc.CreateCompatibleDC(pDC);
	KingBomb.LoadBitmapW(IDB_BIT_KB);
	Bomb.LoadBitmapW(IDB_BIT_BOMB);
	
	memdc.SelectObject(&KingBomb);
	pDC->BitBlt(m_KingBomb.x - KINGRADIUS, m_KingBomb.y - KINGRADIUS, 109, 109, &memdc, 0, 0, SRCCOPY);
	memdc.SelectObject(&Bomb);
	pDC->BitBlt(m_Bomb2.x - RADIUS, m_Bomb2.y - RADIUS, 80, 80, &memdc, 0, 0, SRCCOPY);
	pDC->BitBlt(m_Bomb3.x - RADIUS, m_Bomb3.y - RADIUS, 80, 80, &memdc, 0, 0, SRCCOPY);
	pDC->BitBlt(m_Bomb4.x - RADIUS, m_Bomb4.y - RADIUS, 80, 80, &memdc, 0, 0, SRCCOPY);
	pDC->BitBlt(m_Bomb5.x - RADIUS, m_Bomb5.y - RADIUS, 80, 80, &memdc, 0, 0, SRCCOPY);
	pDC->BitBlt(m_Bomb6.x - RADIUS, m_Bomb6.y - RADIUS, 80, 80, &memdc, 0, 0, SRCCOPY);

	CImage Ship, Man;
	Ship.Load(L"res/ship.png");
	Man.Load(L"res/man.png");
	Ship.Draw(*pDC, m_Ship.x - WIDE, m_Ship.y - WIDE);
	Man.Draw(*pDC, m_Ball.x - BSIZE, m_Ball.y - BSIZE);
	
	//pDC->Ellipse(m_Ball.x - BSIZE, m_Ball.y - BSIZE, m_Ball.x + BSIZE, m_Ball.y + BSIZE);
	//pDC->Ellipse(m_KingBomb.x - KINGRADIUS, m_KingBomb.y - KINGRADIUS, m_KingBomb.x + KINGRADIUS, m_KingBomb.y + KINGRADIUS);
	//pDC->Ellipse(m_Bomb2.x - RADIUS, m_Bomb2.y - RADIUS, m_Bomb2.x + RADIUS, m_Bomb2.y + RADIUS);
	//pDC->Ellipse(m_Bomb3.x - RADIUS, m_Bomb3.y - RADIUS, m_Bomb3.x + RADIUS, m_Bomb3.y + RADIUS);
	//pDC->Ellipse(m_Bomb4.x - RADIUS, m_Bomb4.y - RADIUS, m_Bomb4.x + RADIUS, m_Bomb4.y + RADIUS);
	//pDC->Ellipse(m_Bomb5.x - RADIUS, m_Bomb5.y - RADIUS, m_Bomb5.x + RADIUS, m_Bomb5.y + RADIUS);
	//pDC->Ellipse(m_Bomb6.x - RADIUS, m_Bomb6.y - RADIUS, m_Bomb6.x + RADIUS, m_Bomb6.y + RADIUS);
	//pDC->Ellipse(m_Ship.x - WIDE, m_Ship.y - WIDE, m_Ship.x + WIDE, m_Ship.y + WIDE);
}


// CFinalproject20162318View 인쇄

BOOL CFinalproject20162318View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFinalproject20162318View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFinalproject20162318View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CFinalproject20162318View 진단

#ifdef _DEBUG
void CFinalproject20162318View::AssertValid() const
{
	CView::AssertValid();
}

void CFinalproject20162318View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinalproject20162318Doc* CFinalproject20162318View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinalproject20162318Doc)));
	return (CFinalproject20162318Doc*)m_pDocument;
}
#endif //_DEBUG


// CFinalproject20162318View 메시지 처리기


void CFinalproject20162318View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{

	case VK_LEFT:
		m_Ball.x = m_Ball.x - 40;
			 
		break;

	case VK_RIGHT:
		m_Ball.x = m_Ball.x + 40;
		break;

	case VK_UP:
		m_Ball.y = m_Ball.y - 40;
		break;

	case VK_DOWN:
		m_Ball.y = m_Ball.y + 40;
		break;

	case 'S':
		point.x = rand() % m_WinRight;
		point.y = rand() % m_WinBottom;
		m_xStep = (point.x - m_KingBomb.x) / 10;
		m_yStep = (point.y - m_KingBomb.y) / 10;
		

		point2.x = rand() % m_WinRight;
		point2.y = rand() % m_WinBottom;
		m_xStep2 = (point2.x - m_Bomb2.x) / 10;
		m_yStep2 = (point2.y - m_Bomb2.y) / 10;
		

		point3.x = rand() % m_WinRight;
		point3.y = rand() % m_WinBottom;
		m_xStep3 = (point3.x - m_Bomb3.x) / 10;
		m_yStep3 = (point3.y - m_Bomb3.y) / 10;
	
		
		point4.x = rand() % m_WinRight;
		point4.y = rand() % m_WinBottom;
		m_xStep4 = (point4.x - m_Bomb4.x) / 10;
		m_yStep4 = (point4.y - m_Bomb4.y) / 10;
	

		point5.x = rand() % m_WinRight;
		point5.y = rand() % m_WinBottom;
		m_xStep5 = (point5.x - m_Bomb5.x) / 10;
		m_yStep5 = (point5.y - m_Bomb5.y) / 10;
	
		point6.x = rand() % m_WinRight;
		point6.y = rand() % m_WinBottom;
		m_xStep6 = (point6.x - m_Bomb6.x) / 10;
		m_yStep6 = (point6.y - m_Bomb6.y) / 10;
	

		point7.x = rand() % m_WinRight;
		point7.y = rand() % m_WinBottom;
		m_xStep7 = (point7.x - m_Ship.x) / 10;
		m_yStep7 = (point7.y - m_Ship.y) / 10;

		m_direction = 10;
		SetTimer(1, 100, NULL);
		
	}


	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CFinalproject20162318View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_WinBottom = cy;
	m_WinRight = cx;
}


void CFinalproject20162318View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_count = m_count + m_direction;
	if (m_count == 1200) {
		m_count = 0;
	}
	m_KingBomb.x += m_xStep;
	m_KingBomb.y += m_yStep;
	m_Bomb2.x += m_xStep2;
	m_Bomb2.y += m_yStep2;
	m_Bomb3.x += m_xStep3;
	m_Bomb3.y += m_yStep3;
	m_Bomb4.x += m_xStep4;
	m_Bomb4.y += m_yStep4;
	m_Bomb5.x += m_xStep5;
	m_Bomb5.y += m_yStep5;
	m_Bomb6.x += m_xStep6;
	m_Bomb6.y += m_yStep6;
	m_Ship.x += m_xStep7;
	m_Ship.y += m_yStep7;
	//대왕폭탄
	if ((m_KingBomb.y - KINGRADIUS) < 0 || (m_KingBomb.y + KINGRADIUS) > m_WinBottom)
	{
		if ((m_KingBomb.y - KINGRADIUS) < 0) {
			m_KingBomb.y = KINGRADIUS;
		}
		else if ((m_KingBomb.y + KINGRADIUS) > m_WinBottom) {
			m_KingBomb.y = m_WinBottom - KINGRADIUS;
		}
		m_yStep = m_yStep * (-1);
	}
	if ((m_KingBomb.x - KINGRADIUS) < 0 || (m_KingBomb.x + KINGRADIUS) > m_WinRight)
	{
		if ((m_KingBomb.x - KINGRADIUS) < 0) {
			m_KingBomb.x = KINGRADIUS;
		}
		else if ((m_KingBomb.x + KINGRADIUS) > m_WinRight) {
			m_KingBomb.x = m_WinRight - KINGRADIUS;
		}
		m_xStep = m_xStep * (-1);
	}
	//폭탄2
	if ((m_Bomb2.y - RADIUS) < 0 || (m_Bomb2.y + RADIUS) > m_WinBottom)
	{
		if ((m_Bomb2.y - RADIUS) < 0) {
			m_Bomb2.y = RADIUS;
		}
		else if ((m_Bomb2.y + RADIUS) > m_WinBottom) {
			m_Bomb2.y = m_WinBottom - RADIUS;
		}
		m_yStep2 = m_yStep2 * (-1);
	}
	if ((m_Bomb2.x - RADIUS) < 0 || (m_Bomb2.x + RADIUS) > m_WinRight)
	{
		if ((m_Bomb2.x - RADIUS) < 0) {
			m_Bomb2.x = RADIUS;
		}
		else if ((m_Bomb2.x + RADIUS) > m_WinRight) {
			m_Bomb2.x = m_WinRight - RADIUS;
		}
		m_xStep2 = m_xStep2 * (-1);
	}
	//폭탄3
	if ((m_Bomb3.y - RADIUS) < 0 || (m_Bomb3.y + RADIUS) > m_WinBottom)
	{
		if ((m_Bomb3.y - RADIUS) < 0) {
			m_Bomb3.y = RADIUS;
		}
		else if ((m_Bomb3.y + RADIUS) > m_WinBottom) {
			m_Bomb3.y = m_WinBottom - RADIUS;
		}
		m_yStep3 = m_yStep3 * (-1);
	}
	if ((m_Bomb3.x - RADIUS) < 0 || (m_Bomb3.x + RADIUS) > m_WinRight)
	{
		if ((m_Bomb3.x - RADIUS) < 0) {
			m_Bomb3.x = RADIUS;
		}
		else if ((m_Bomb3.x + RADIUS) > m_WinRight) {
			m_Bomb3.x = m_WinRight - RADIUS;
		}
		m_xStep3 = m_xStep3 * (-1);
	}
	//폭탄4
	if ((m_Bomb4.y - RADIUS) < 0 || (m_Bomb4.y + RADIUS) > m_WinBottom)
	{
		if ((m_Bomb4.y - RADIUS) < 0) {
			m_Bomb4.y = RADIUS;
		}
		else if ((m_Bomb4.y + RADIUS) > m_WinBottom) {
			m_Bomb4.y = m_WinBottom - RADIUS;
		}
		m_yStep4 = m_yStep4 * (-1);
	}
	if ((m_Bomb4.x - RADIUS) < 0 || (m_Bomb4.x + RADIUS) > m_WinRight)
	{
		if ((m_Bomb4.x - RADIUS) < 0) {
			m_Bomb4.x = RADIUS;
		}
		else if ((m_Bomb4.x + RADIUS) > m_WinRight) {
			m_Bomb4.x = m_WinRight - RADIUS;
		}
		m_xStep4 = m_xStep4 * (-1);
	}//폭탄5
	if ((m_Bomb5.y - RADIUS) < 0 || (m_Bomb5.y + RADIUS) > m_WinBottom)
	{
		if ((m_Bomb5.y - RADIUS) < 0) {
			m_Bomb5.y = RADIUS;
		}
		else if ((m_Bomb5.y + RADIUS) > m_WinBottom) {
			m_Bomb5.y = m_WinBottom - RADIUS;
		}
		m_yStep5 = m_yStep5 * (-1);
	}
	if ((m_Bomb5.x - RADIUS) < 0 || (m_Bomb5.x + RADIUS) > m_WinRight)
	{
		if ((m_Bomb5.x - RADIUS) < 0) {
			m_Bomb5.x = RADIUS;
		}
		else if ((m_Bomb5.x + RADIUS) > m_WinRight) {
			m_Bomb5.x = m_WinRight - RADIUS;
		}
		m_xStep5 = m_xStep5 * (-1);
	}//폭탄6
	if ((m_Bomb6.y - RADIUS) < 0 || (m_Bomb6.y + RADIUS) > m_WinBottom)
	{
		if ((m_Bomb6.y - RADIUS) < 0) {
			m_Bomb6.y = RADIUS;
		}
		else if ((m_Bomb6.y + RADIUS) > m_WinBottom) {
			m_Bomb6.y = m_WinBottom - RADIUS;
		}
		m_yStep6 = m_yStep6 * (-1);
	}
	if ((m_Bomb6.x - RADIUS) < 0 || (m_Bomb6.x + RADIUS) > m_WinRight)
	{
		if ((m_Bomb6.x - RADIUS) < 0) {
			m_Bomb6.x = RADIUS;
		}
		else if ((m_Bomb6.x + RADIUS) > m_WinRight) {
			m_Bomb6.x = m_WinRight - RADIUS;
		}
		m_xStep6 = m_xStep6 * (-1);
	}
	//쉽
	if ((m_Ship.y - RADIUS) < 0 || (m_Ship.y + RADIUS) > m_WinBottom)
	{
		if ((m_Ship.y - RADIUS) < 0) {
			m_Ship.y = RADIUS;
		}
		else if ((m_Ship.y + RADIUS) > m_WinBottom) {
			m_Ship.y = m_WinBottom - RADIUS;
		}
		m_yStep7 = m_yStep7 * (-1);
	}
	if ((m_Ship.x - RADIUS) < 0 || (m_Ship.x + RADIUS) > m_WinRight)
	{
		if ((m_Ship.x - RADIUS) < 0) {
			m_Ship.x = RADIUS;
		}
		else if ((m_Ship.x + RADIUS) > m_WinRight) {
			m_Ship.x = m_WinRight - RADIUS;
		}
		m_xStep7 = m_xStep7 * (-1);
	}
	
	if (m_Ball.x - BSIZE<0 || m_Ball.x + BSIZE>m_WinRight || m_Ball.y + BSIZE > m_WinBottom) {
		KillTimer(0);
		AfxMessageBox(_T("lose.."));
		return;
	}
	CRect rt(m_KingBomb.x - KINGRADIUS, m_KingBomb.y - KINGRADIUS, m_KingBomb.x + KINGRADIUS, m_KingBomb.y + KINGRADIUS);
	if (PtInRect(&rt, m_Ball)) {
		KillTimer(0);
		AfxMessageBox(_T("lose.."));
		return;
	}
	CRect rt2(m_Bomb2.x - RADIUS, m_Bomb2.y - RADIUS, m_Bomb2.x + RADIUS, m_Bomb2.y + RADIUS);
	if (PtInRect(&rt2, m_Ball)) {
		KillTimer(0);
		AfxMessageBox(_T("lose.."));
		return;
	}
	CRect rt3(m_Bomb3.x - RADIUS, m_Bomb3.y - RADIUS, m_Bomb3.x + RADIUS, m_Bomb3.y + RADIUS);
	if (PtInRect(&rt3, m_Ball)) {
		KillTimer(0);
		AfxMessageBox(_T("lose.."));
		return;
	}
	CRect rt4(m_Bomb4.x - RADIUS, m_Bomb4.y - RADIUS, m_Bomb4.x + RADIUS, m_Bomb4.y + RADIUS);
	if (PtInRect(&rt4, m_Ball)) {
		KillTimer(0);
		AfxMessageBox(_T("lose.."));
		return;
	}
	CRect rt5(m_Bomb5.x - RADIUS, m_Bomb5.y - RADIUS, m_Bomb5.x + RADIUS, m_Bomb5.y + RADIUS);
	if (PtInRect(&rt5, m_Ball)) {
		KillTimer(0);
		AfxMessageBox(_T("lose.."));
		return;
	}
	CRect rt6(m_Bomb6.x - RADIUS, m_Bomb6.y - RADIUS, m_Bomb6.x + RADIUS, m_Bomb6.y + RADIUS);
	if (PtInRect(&rt6, m_Ball)) {
		KillTimer(0);
		AfxMessageBox(_T("lose.."));
		return;
	}
	CRect BS(m_Ship.x - RADIUS, m_Ship.y - RADIUS, m_Ship.x + RADIUS, m_Ship.y + RADIUS);
	if (PtInRect(&BS, m_Ball)) {
		KillTimer(0);
		AfxMessageBox(_T("you win!!"));
		return;
	}

	Invalidate(0);
	CView::OnTimer(nIDEvent);
}



