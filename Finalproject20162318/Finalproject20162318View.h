
// Finalproject20162318View.h: CFinalproject20162318View 클래스의 인터페이스
//

#pragma once


class CFinalproject20162318View : public CView
{
protected: // serialization에서만 만들어집니다.
	CFinalproject20162318View() noexcept;
	DECLARE_DYNCREATE(CFinalproject20162318View)

// 특성입니다.
public:
	CFinalproject20162318Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CFinalproject20162318View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_Ball;
	CPoint m_KingBomb, m_Bomb2, m_Bomb3, m_Bomb4, m_Bomb5, m_Bomb6;
	CPoint m_Ship;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int m_WinBottom;
	int m_WinRight;
	int m_xStep, m_xStep2, m_xStep3, m_xStep4, m_xStep5, m_xStep6, m_xStep7;
	int m_yStep, m_yStep2, m_yStep3, m_yStep4, m_yStep5, m_yStep6, m_yStep7;
	CPoint point, point2, point3, point4, point5, point6, point7;
	int m_count;
	int m_direction;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void RUTE();
};

#ifndef _DEBUG  // Finalproject20162318View.cpp의 디버그 버전
inline CFinalproject20162318Doc* CFinalproject20162318View::GetDocument() const
   { return reinterpret_cast<CFinalproject20162318Doc*>(m_pDocument); }
#endif

