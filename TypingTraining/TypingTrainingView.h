
// TypingTrainingView.h : CTypingTrainingView Ŭ������ �������̽�
//

#pragma once
#include "afxwin.h"
class CTypingTrainingDoc;
class CLogin;
class CShort;
class CLong;
class CGame;
class CInfo;

class CTypingTrainingView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CTypingTrainingView();
	DECLARE_DYNCREATE(CTypingTrainingView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TYPINGTRAINING_FORM };
#endif

// Ư���Դϴ�.
public:
	CTypingTrainingDoc* GetDocument() const;
	int mode;
	CLogin* m_pLogin;
	CShort* m_pShort;
	CLong* m_pLong;
	CGame* m_pGame;
	CInfo* m_pInfo;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CTypingTrainingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	CButton m_goShort;
	CButton m_goLong;
	CButton m_goGame;
	CButton m_goStatic;
	afx_msg void OnBnClickedGoShort();
	afx_msg void OnBnClickedGoLong();
	afx_msg void OnBnClickedGoGame();
	afx_msg void OnBnClickedGoStatic();
};

#ifndef _DEBUG  // TypingTrainingView.cpp�� ����� ����
inline CTypingTrainingDoc* CTypingTrainingView::GetDocument() const
   { return reinterpret_cast<CTypingTrainingDoc*>(m_pDocument); }
#endif
