#pragma once
#include<afxwin.h>
#include "Vector2.h"
#include <cmath>

enum  ElementType { NOTSET = 0, SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };
struct shape
{
	int Type;
	int OrgX;
	int OrgY;
	COLORREF   BorderColor;
	int BorderType;
	int BorderWidth;
	COLORREF  FillColor;
	int FillType;
	int Height;
	int Width;
	CString Str;
};

class CShape : public CObject
{
public:
	CShape();
	//virtual ~CShape()=0;
	virtual void Draw(CDC* pDC) = 0;//����
	virtual bool IsMatched(CPoint pnt) = 0;//���Ƿ�����ͼ���ڲ�
	virtual void Serialize(CArchive& ar) = 0;//���л��洢����������
	virtual void SetShapePos(int x,int y,int w,int h=0, CString s = L"")=0;
	virtual void SetPen(int w=0, int c=0, COLORREF cc=RGB(255,0,255)) = 0;
	virtual void SetBrush(int c = 0, COLORREF cc = RGB(0, 0, 0)) = 0;
	virtual shape GetShape();
protected:
	ElementType Type;//ͼԪ����
	int OrgX;//ԭ������
	int OrgY;
	COLORREF   BorderColor;//�߽���ɫ
	int BorderType;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	int BorderWidth;//�߽���
	COLORREF  FillColor;//�����ɫ
	int FillType;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
};

class CSquare : public CShape
{
public:
	CSquare();
	CSquare(int x, int y, int w);
	void Draw(CDC* pDC);//����������
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	virtual void SetShapePos(int x, int y, int w, int h, CString s);
	virtual void SetPen(int w, int c, COLORREF cc);
	virtual void SetBrush(int c, COLORREF cc );
	virtual shape GetShape();
private:
	int width;

	DECLARE_SERIAL(CSquare)//������CSquare֧�����л�
};

//����
class CRectangle : public CShape
{
private:
	int width, Height;
public:
	DECLARE_SERIAL(CRectangle)
	CRectangle();
	CRectangle(int x, int y, int w, int h);
	void Draw(CDC* pDC);//���Ƴ�����
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	virtual void SetShapePos(int x, int y, int w, int h, CString s);
	virtual void SetPen(int w, int c, COLORREF cc);
	virtual void SetBrush(int c, COLORREF cc);
	virtual shape GetShape();
};
//Բ��
class CCircle : public CShape
{
public:
	CCircle();
	CCircle(int x, int y, int R);
	void Draw(CDC* pDC);
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	virtual void SetShapePos(int x, int y, int w, int h, CString s);
	virtual void SetPen(int w, int c, COLORREF cc);
	virtual void SetBrush( int c, COLORREF cc);
	virtual shape GetShape();
private:
	int R;
	DECLARE_SERIAL(CCircle)//������CSquare֧�����л�
};
//��Բ��
class CEllipse : public CShape
{
public:
	CEllipse();
	CEllipse(int x, int y, int w, int h);
	void Draw(CDC* pDC);
	bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive& ar);
	virtual void SetShapePos(int x, int y, int w, int h, CString s);
	virtual void SetPen(int w, int c, COLORREF cc);
	virtual void SetBrush( int c, COLORREF cc);
	virtual shape GetShape();
private:
	int width, height;
	DECLARE_SERIAL(CEllipse)//������CSquare֧�����л�
};

//������
class CTriangle : public CShape
{
public:
	CTriangle();
	CTriangle(int x, int y, int w);
	void Draw(CDC* pDC);
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	virtual void SetShapePos(int x, int y, int w, int h, CString s);
	virtual void SetPen(int w, int c, COLORREF cc);
	virtual void SetBrush(int c, COLORREF cc);
	virtual shape GetShape();
private:
	int width;

	DECLARE_SERIAL(CTriangle)//������CSquare֧�����л�
};
//����
class CText : public CShape
{
public:
	CText();
	CText(int x, int y, int h, int a, const char* s);
	void Draw(CDC* pDC);
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	virtual void SetShapePos(int x, int y, int w, int h, CString s);
	virtual void SetPen(int w, int c, COLORREF cc);
	virtual void SetBrush( int c, COLORREF cc);
	virtual shape GetShape();
private:
	int height;
	int angle;
	CString str;
	CSize  size;
	DECLARE_SERIAL(CText)//������CSquare֧�����л�
};

