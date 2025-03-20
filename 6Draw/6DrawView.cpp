
// 6DrawView.cpp: CMy6DrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "6Draw.h"
#endif

#include "6DrawDoc.h"
#include "6DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy6DrawView

IMPLEMENT_DYNCREATE(CMy6DrawView, CView)

BEGIN_MESSAGE_MAP(CMy6DrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_COMMAND(ID_CLIENT, &CMy6DrawView::OnClient)
	ON_COMMAND(ID_PEN, &CMy6DrawView::OnPen)
	ON_COMMAND(ID_BRUSH, &CMy6DrawView::OnBrush)
	ON_COMMAND(ID_FONT, &CMy6DrawView::OnFont)
	ON_COMMAND(ID_BITMAP, &CMy6DrawView::OnBitmap)
END_MESSAGE_MAP()

// CMy6DrawView 构造/析构

CMy6DrawView::CMy6DrawView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy6DrawView::~CMy6DrawView()
{
}

BOOL CMy6DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy6DrawView 绘图

void CMy6DrawView::OnDraw(CDC* /*pDC*/)
{
	CMy6DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy6DrawView 打印

BOOL CMy6DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy6DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy6DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy6DrawView 诊断

#ifdef _DEBUG
void CMy6DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMy6DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy6DrawDoc* CMy6DrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy6DrawDoc)));
	return (CMy6DrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy6DrawView 消息处理程序


void CMy6DrawView::OnPaint()
{
	CPaintDC dc(this); //::BeginPaint
//	dc.Rectangle( 100, 100, 300, 300 );//::Rectangle(...)
//	::Rectangle( dc.m_hDC, 100, 100, 300, 300 );
}


void CMy6DrawView::OnClient()
{
	CClientDC dc(this);
	dc.Ellipse(300, 300, 500, 500);
}


void CMy6DrawView::OnPen()
{
	CClientDC dc(this);
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));

	//	CPen* oldpen = dc.SelectObject( &pen );
	HGDIOBJ nOldPen = ::SelectObject(dc.m_hDC, pen.m_hObject);

	//	dc.Rectangle( 100, 100, 300, 300 );
	::Rectangle(dc.m_hDC, 100, 100, 300, 300);

	//	dc.SelectObject( oldpen );
	::SelectObject(dc.m_hDC, nOldPen);

	//	pen.DeleteObject( );
	::DeleteObject(pen.m_hObject);
}


void CMy6DrawView::OnBrush()
{
	CClientDC dc(this);
	CBrush brush(RGB(0, 255, 0));
	CBrush* oldbrush = dc.SelectObject(&brush);
	dc.Rectangle(100, 100, 300, 300);
	dc.SelectObject(oldbrush);
	brush.DeleteObject();
}


void CMy6DrawView::OnFont()
{
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(300, "黑体");//::CreateFont(..............)
	CFont* oldfont = dc.SelectObject(&font);
	dc.TextOut(100, 100, "hello");
	dc.SelectObject(oldfont);
	font.DeleteObject();
}


void CMy6DrawView::OnBitmap()
{
	//添加位图资源(操作资源无需写代码)

	//创建一个和当前DC,相匹配的内存DC
	CClientDC dc(this);
	CDC memdc;
	memdc.CreateCompatibleDC(&dc); //::CreateCompatibleDC
	//将位图的数据送给内存DC
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1); //::LoadBitmap


	CBitmap* oldbmp = memdc.SelectObject(&bmp);//::SelectObject
	//成像
	dc.BitBlt(100, 100, 48, 48, &memdc, 0, 0, SRCCOPY);//::BitBlt
	//将位图数据要回来
	memdc.SelectObject(oldbmp);//::SelectObject
	//销毁位图
	bmp.DeleteObject();//::DeleteObject
	//销毁内存DC
	memdc.DeleteDC();//::DeleteDC
}
