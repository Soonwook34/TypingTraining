
// TypingTrainingView.cpp : CTypingTrainingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "TypingTraining.h"
#endif
#define IDD_TYPINGTRAINING_FORM IDD_MAIN

#include "TypingTrainingDoc.h"
#include "TypingTrainingView.h"
#include "Login.h"
#include "Short.h"
#include "Long.h"
#include "Game.h"
#include "Info.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTypingTrainingView

IMPLEMENT_DYNCREATE(CTypingTrainingView, CFormView)

BEGIN_MESSAGE_MAP(CTypingTrainingView, CFormView)
	ON_BN_CLICKED(IDC_GO_SHORT, &CTypingTrainingView::OnBnClickedGoShort)
	ON_BN_CLICKED(IDC_GO_LONG, &CTypingTrainingView::OnBnClickedGoLong)
	ON_BN_CLICKED(IDC_GO_GAME, &CTypingTrainingView::OnBnClickedGoGame)
	ON_BN_CLICKED(IDC_GO_STATIC, &CTypingTrainingView::OnBnClickedGoStatic)
END_MESSAGE_MAP()

// CTypingTrainingView ����/�Ҹ�

CTypingTrainingView::CTypingTrainingView()
	: CFormView(IDD_MAIN)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	mode = IDD_LOGIN;
	m_pLogin = NULL;
	m_pShort = NULL;
	m_pLong = NULL;
	m_pGame = NULL;
	m_pInfo = NULL;
}

CTypingTrainingView::~CTypingTrainingView()
{
}

void CTypingTrainingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GO_SHORT, m_goShort);
	DDX_Control(pDX, IDC_GO_LONG, m_goLong);
	DDX_Control(pDX, IDC_GO_GAME, m_goGame);
	DDX_Control(pDX, IDC_GO_STATIC, m_goStatic);
}

BOOL CTypingTrainingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CTypingTrainingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CTypingTrainingView ����

#ifdef _DEBUG
void CTypingTrainingView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTypingTrainingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTypingTrainingDoc* CTypingTrainingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTypingTrainingDoc)));
	return (CTypingTrainingDoc*)m_pDocument;
}
#endif //_DEBUG


// CTypingTrainingView �޽��� ó����


void CTypingTrainingView::OnDraw(CDC* pDC)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (mode != IDD_MAIN) {
		m_goShort.ShowWindow(SW_HIDE);
		m_goLong.ShowWindow(SW_HIDE);
		m_goGame.ShowWindow(SW_HIDE);
		m_goStatic.ShowWindow(SW_HIDE);
	}
	else {
		m_goShort.ShowWindow(SW_SHOW);
		m_goLong.ShowWindow(SW_SHOW);
		m_goGame.ShowWindow(SW_SHOW);
		m_goStatic.ShowWindow(SW_SHOW);
	}
	
	switch (mode) {
	case IDD_MAIN:
		break;
	case IDD_LOGIN:
		if(m_pLogin == NULL) {
			m_pLogin = new CLogin(this);
			m_pLogin->Create(IDD_LOGIN, this);
			m_pLogin->ShowWindow(SW_SHOW);
		}
		break;
	case IDD_SHORT:
		if (m_pShort == NULL) {
			m_pShort = new CShort(this);
			m_pShort->Create(IDD_SHORT, this);
			m_pShort->ShowWindow(SW_SHOW);
		}
		break;
	case IDD_LONG:
		if (m_pLong == NULL) {
			m_pLong = new CLong(this);
			m_pLong->Create(IDD_LONG, this);
			m_pLong->ShowWindow(SW_SHOW);
		}
		break;
	case IDD_GAME:
		if (m_pGame == NULL) {
			m_pGame = new CGame(this);
			m_pGame->Create(IDD_GAME, this);
			m_pGame->ShowWindow(SW_SHOW);
		}
		break;
	case IDD_STATIC:
		if (m_pInfo == NULL) {
			m_pInfo = new CInfo(this);
			m_pInfo->Create(IDD_STATIC, this);
			m_pInfo->ShowWindow(SW_SHOW);
		}
		break;
	}
}


void CTypingTrainingView::OnBnClickedGoShort()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	mode = IDD_SHORT;
	Invalidate();
}


void CTypingTrainingView::OnBnClickedGoLong()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	mode = IDD_LONG;
	Invalidate();
}


void CTypingTrainingView::OnBnClickedGoGame()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	mode = IDD_GAME;
	Invalidate();
}


void CTypingTrainingView::OnBnClickedGoStatic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	mode = IDD_STATIC;
	Invalidate();
}