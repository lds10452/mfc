
// 6DrawView.h: CMy6DrawView 类的接口
//

#pragma once


class CMy6DrawView : public CView
{
protected: // 仅从序列化创建
	CMy6DrawView() noexcept;
	DECLARE_DYNCREATE(CMy6DrawView)

// 特性
public:
	CMy6DrawDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy6DrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnClient();
	afx_msg void OnPen();
	afx_msg void OnBrush();
	afx_msg void OnFont();
	afx_msg void OnBitmap();
};

#ifndef _DEBUG  // 6DrawView.cpp 中的调试版本
inline CMy6DrawDoc* CMy6DrawView::GetDocument() const
   { return reinterpret_cast<CMy6DrawDoc*>(m_pDocument); }
#endif

