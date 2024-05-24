
#include <iostream>
#include <cmath>

#include <windows.h>		// ������������ ���� � ���������� ������� Windows

#include "GL/gl.h"			// ������������ ����� ���������� OpenGL �
#include "GL/glu.h"			// ��������������� ��������� (��� �����
#include "GL/glaux.h"		// ����� � �������� ������� � ����������� GL)
#include <vector>

using namespace std;
// ********************************************************************************
//   ��������� � ���������� ����������
// ********************************************************************************

const double PI = 3.14159265359;
const int    WINDOW_WIDTH = 400;	// ������ ��������� ���� OpenGL
const int    WINDOW_HEIGHT = 300;	// � ������ (� ��������)

// ����������� ���������� ����� ������, ����� ����� ���� 
// ������� ����������-��������� �� ��� ����
class GraphicalObject;
class Hole;
class Wall;
class Ball;

// ���������� ����������, ��������� �������������� ������ ��������
bool   fBallMoved = false;		// ���� ������� ���� �� ������ ����������� ����
int	   saveRack = 0;			// ������� ������� �����

vector<GraphicalObject*> vOfObjects;  // ������ ��������

Ball* pCueBall = nullptr;	// ��������� �� ����� ��� (� ������ �� ���� ����)


// ********************************************************************************
//   ����������� �������
// ********************************************************************************

// ��������������� ����� "�������������"
class Rect {
public:
	// ������������� ��������
	int x1, y1, x2, y2;

public:
	// ������������
	Rect() : x1(0), y1(0), x2(0), y2(0) {}
	Rect(int nx1, int ny1, int nx2, int ny2) :
		x1(nx1), y1(ny1), x2(nx2), y2(ny2) {}

	// ������������� ��������� ��������������
	void SetRect(int left, int top, int right, int bottom)
	{
		x1 = left; y1 = top; x2 = right; y2 = bottom;
	}
	// �������� ��������������
	void OffsetRect(int dx, int dy)
	{
		x1 += dx; y1 += dy; x2 += dx; y2 += dy;
	}
	// ��������� ��������� ������ ��������������
	void CenterPoint(int& x, int& y) const
	{
		x = (x1 + x2) / 2; y = (y1 + y2) / 2;
	}
	// �������� �� ���������� ��������� ����� ��������������
	bool IsRectEmpty() const { return x1 == x2 && y1 == y2; }
	// ��������� ������ ��������������
	int Width() const { return x2 - x1 + 1; }
	// ��������� ������ ��������������
	int Height() const { return y2 - y1 + 1; }
	// ������� ��������� ����������� ������� � ��������������� another
	Rect IntersectRect(const Rect& another) const;
	// ������������ ��������� ��������������
	void NormalizeRect();
};


// ����� ������������ ������

class GraphicalObject {
	public:
		GraphicalObject(int left, int top, int right, int bottom);
		// ��������, ����������� ������������ �������
		virtual void Draw() const {}
		virtual void Update() {}
		virtual void HitBy(GraphicalObject* pObj) {}

		// �������-����� ��� ������� � ���������� ������
		Rect GetRegion() const					{ return region; }
		

	protected:
		Rect region;
	
};


// ����� "���������� ���"
class Ball: public GraphicalObject {
public:
	enum class Color
	{
		Blue,
		Red,
		Green,
		White
	};
	// ���� fc == true, �� ��� ��������� ���, �� �������� ��������� ����,
	// � �� ������������ ����� ������ (�������� color ��� ���� ������������).
	Ball(int x, int y, bool fc, Color color = Color::Blue);

	// ������ ����������� ������������ � �������� ������������ 
	// � ������� ��������� ����� delete 
	Ball(const Ball&) = delete;
	Ball& operator=(const Ball&) = delete;


	// ��������� ���� � ������� ���������
	void Draw() const;
	// ��������� ��������� ���� � �������������, ��� � ������� 
	// ����������� ��������� ������ ��������� ���������� �������
	void Update();
	// ��������� ���� � ���, ��� � ���� ����� ������ ���
	void HitBy(GraphicalObject* Obj);
	// ������ ���� ����� ���� OX � ������������ �� ������ ���� �� �����,
	// ��������� �� ������ ���� �� (dx, dy)
	double HitAngle(double dx, double dy) const;

	// �������-����� ��� ������� � ���������� ������
	void   SetEnergy(double v) { energy = v; }
	void   SetCenter(int newx, int newy);
	void   SetDirection(double newDir) { direction = newDir; };

	Rect   GetRegion() const { return region; }
	double GetEnergy() const { return energy; }
	void   GetCenter(int& x, int& y) const;
	double GetDirection() const { return direction; }
	bool   IsCue() const { return fCue; }

private:
	
	double direction;	// ����������� �������� ���� (���� � �������� 
						// ������������ ��� OX)
	double energy;		// ������� ����
	bool   fCue;		// ������� ������ ����

	Color color;		// ���� ����
};


// ����� "������ ����������� �����"
class Wall : public GraphicalObject {
public:
	Wall(int left, int top, int right, int bottom,
		double cf);

	// ��������� ������
	void Draw() const;
	// ��������� ������ � ���, ��� � ��� ����� ��� 
	void HitBy(GraphicalObject* Obj);


private:

	double convertFactor;	// ��������, �� �������� ���������� 
							// ����������� ���������� ����, �����
							// ���������� ���������� ���������
private:
	// ������ ����������� ������������ � ��������� ������������ 
	// ����������� ���������� � ������ private
	Wall(const Wall&);
	Wall& operator=(const Wall&);
};



// ����� "���� ����������� �����"  
class Hole: public GraphicalObject {
public:
	Hole(int x, int y);

	// ������ ����������� ������������ � �������� ������������ 
	// � ������� ��������� ����� delete
	Hole(const Hole&) = delete;
	Hole& operator=(const Hole&) = delete;

	// ��������� ����
	void Draw() const;
	// ��������� ���� � ���, ��� � ��� ����� ��� 
	void HitBy(GraphicalObject* pObj);

};



// ********************************************************************************
//   ���������� ������ CRect
// ********************************************************************************

void Rect::NormalizeRect()
{
	int nx1 = x1, ny1 = y1, nx2 = x2, ny2 = y2;
	x1 = min(nx1, nx2);
	y1 = min(ny1, ny2);
	x2 = max(nx1, nx2);
	y2 = max(ny1, ny2);
}


Rect Rect::IntersectRect(const Rect& another) const
{
	// ��������������� ����������: ����� ��������������� ��� ������� 
	// ����������� - ��� ����� �������������. �������� ��������������,
	// ��������, �����������������, �� ����������.
	Rect r1 = *this, r2 = another;
	r1.NormalizeRect();
	r2.NormalizeRect();

	// �������� �� ������� �����������
	if ((r1.x1 >= r2.x1 && r1.x1 <= r2.x2) ||
		(r1.x2 >= r2.x1 && r1.x2 <= r2.x2))
		if ((r1.y1 >= r2.y1 && r1.y1 <= r2.y2) ||
			(r1.y2 >= r2.y1 && r1.y2 <= r2.y2))
		{
			int ix1 = max(r1.x1, r2.x1);
			int iy1 = max(r1.y1, r2.y1);
			int ix2 = min(r1.x2, r2.x2);
			int iy2 = min(r1.y2, r2.y2);
			return Rect(ix1, iy1, ix2, iy2);
		}

	// ���� ����������� ���, �� ������������ ������ �������������
	return Rect(0, 0, 0, 0);
}

// ********************************************************************************
//   ���������� ������ GraphicalObject
// ********************************************************************************


GraphicalObject::GraphicalObject(int left, int top, int right, int bottom)
{
	region.SetRect(left, top, right, bottom);
}

// ********************************************************************************
//   ���������� ������ Wall
// ********************************************************************************

Wall::Wall(int left, int top, int right, int bottom,
	double cf) :
	GraphicalObject(left, top, right, bottom),
	convertFactor(cf)
{
}


void Wall::Draw() const
{
	// ������ �������� � ���� �������� ��������������
	glColor3ub(0, 255, 0);
	glRecti(region.x1, region.y1, region.x2, region.y2);
}


void Wall::HitBy(GraphicalObject* pObj)
{
	Ball* pBall = dynamic_cast<Ball*>(pObj);

	if (pBall) {
		// ���������� ��������� ���� �� ������
		pBall->SetDirection(convertFactor - pBall->GetDirection());
	}

}



// ********************************************************************************
//   ���������� ������ Hole
// ********************************************************************************

Hole::Hole(int x, int y):
	GraphicalObject(x - 5, y - 5, x + 5, y + 5)
{

}


void Hole::Draw() const
{
	// ���� �������� � ���� ������� �����, ���������� � ������� region
	glColor3ub(255, 255, 0);
	glPointSize(static_cast<float>(region.Width()));
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	int cx = 0, cy = 0;
	region.CenterPoint(cx, cy);
	glVertex2i(cx, cy);
	glEnd();
	glDisable(GL_POINT_SMOOTH);
}


void Hole::HitBy(GraphicalObject* pObj)
{
	Ball* pBall = dynamic_cast<Ball*>(pObj);

	if (pBall)
	{
		// ������� ���� ����������
		pBall->SetEnergy(0.0);
		// ����� ��� ����� ���������� � ��������� �������, � ����� ���� 
		// ��������� �� ����� � �������� � ������ ��� ������������ �����
		if (pBall->IsCue())
		{
			pBall->SetCenter(50, 108);
		}
		else
		{
			pBall->SetCenter(10 + saveRack * 15, 250);
			saveRack++; // ���������� ����������� �������� ������� �����
		}
	}
	
}



// ********************************************************************************
//   ���������� ������ Ball
// ********************************************************************************

Ball::Ball(int x, int y, bool fc, Color c) :
	GraphicalObject(x - 5, y - 5, x + 5, y + 5),
	fCue(fc)
{
	SetCenter(x, y);
	SetDirection(0);
	SetEnergy(0.0);

	// ���, � �������� ���������� ���� fCue, ������ ������������ ����� ������
	color = fc ? Color::White : c;
}


void Ball::Draw() const
{
	switch (color)
	{
		case Color::Blue: glColor3ub(0, 0, 255);      break;	// ����� ����
		case Color::Green: glColor3ub(0, 255, 0);     break;	// ������� ���� 
		case Color::Red: glColor3ub(255, 0, 0);       break;	// ������� ���� 
		case Color::White: glColor3ub(255, 255, 255); break;	// ����� ����
		default: glColor3ub(0, 0, 0);
	}

	glPointSize(static_cast<float>(region.Width()));
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	int cx = 0, cy = 0;
	region.CenterPoint(cx, cy);
	glVertex2i(cx, cy);
	glEnd();
	glDisable(GL_POINT_SMOOTH);
}


void Ball::SetCenter(int newx, int newy) 
{
	// ������� ������������ �������������� ��� ���� � ������� � ����� (newx, newy)
	region.SetRect(newx - 5, newy - 5, newx + 5, newy + 5);
}


void Ball::GetCenter(int& x, int& y) const
{
	region.CenterPoint(x, y);
}


void Ball::Update()
{
	// ��� �������� � ���� ������ ���� ��������� ������������ �������
	if (energy <= 0.5)
		return;

	fBallMoved = true;

	// �� ������ ���� ������� ���� ����������� �� ���� ������
	energy -= 0.05;

	// �������� ���� ����������� � ������ ������������ �����������
	// ������������ ������� �� ��������. ��������� 2.0 ������� ��� 
	// ����������� �����-����� ������������� �������� �����
	int dx = static_cast<int>(2.0 * sqrt(energy) * cos(direction));
	int dy = static_cast<int>(2.0 * sqrt(energy) * sin(direction));
	region.OffsetRect(dx, dy);

	// �������� �� ��������� � ����
	for (auto pObj : vOfObjects)
	{
		Rect is = region.IntersectRect(pObj->GetRegion());
		if (!is.IsRectEmpty() && pObj != this)
		{
			pObj->HitBy(this);
			break;
		}
	}

}

// ������ ���� ����� ���� OX � �������� (dx, dy)
// ������� ���������� �������� ���� �������� � ��������� (0,PI) ��� (-PI,0)
double Ball::HitAngle(double dx, double dy) const
{
	double na = 0.0;

	if (fabs(dx) < 0.05)
		na = PI / 2;
	else
		na = atan(fabs(dy / dx));

	if (dx < 0)
		na = PI - na;
	if (dy < 0)
		na = -na;

	return na;
}



void Ball::HitBy(GraphicalObject* pObj)
{

	Ball* pBall = dynamic_cast<Ball*>(pObj);
	if (pBall)
	{
		// ��������� ������� ���������� ���� �����
		pBall->SetEnergy(pBall->GetEnergy() / 2.0);
		// � ���������� �� � ����������� �������
		energy += pBall->GetEnergy();
	}
	

	// ������ ������ ����������� ��� �������� ����
	int cx1 = 0, cy1 = 0, cx2 = 0, cy2 = 0;
	GetCenter(cx1, cy1);
	pBall->GetCenter(cx2, cy2);
	SetDirection(HitAngle(cx1 - cx2, cy1 - cy2));

	// ����������� ����������� ���������� ����
	double da = pBall->GetDirection() - GetDirection();
	pBall->SetDirection(pBall->GetDirection() + da);
}


// ********************************************************************************
//   ���������� �������, �� ���������� ������� �� ������ �� �������
// ********************************************************************************

// ������� ��� ������������� ���������� ����������.
void CreateGlobals()
{
	saveRack = 0;	// ������� ������� �����
	
	// �������� ������
	vOfObjects.push_back(new Wall(10, 10, 300, 15, 0.0));
	vOfObjects.push_back(new Wall(10, 200, 300, 205, 0.0));
	vOfObjects.push_back(new Wall(10, 10, 15, 200, PI));
	vOfObjects.push_back(new Wall(300, 10, 305, 205, PI));
	
	// �������� ���
	vOfObjects.push_back(new Hole(15, 15));
	vOfObjects.push_back(new Hole(15, 200));
	vOfObjects.push_back(new Hole(300, 15));
	vOfObjects.push_back(new Hole(300, 200));
	vOfObjects.push_back(new Hole(157, 15));
	vOfObjects.push_back(new Hole(157, 200));


	// �������� �����. 
	// ������� ��������� ����� ���, � ����� 15 �����. � �������
	// ������ ����� ��� ������������� ���������.

	pCueBall = new Ball(50, 108, true);
	vOfObjects.push_back(pCueBall);

	int bCount = 0;
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= i; j++)
		{
			Ball::Color c = static_cast<Ball::Color>(bCount / 5);
			vOfObjects.push_back(new Ball(190 + i * 8, 100 + 16 * j - 8 * i, false, c));
			bCount++;
		}

}



// ********************************************************************************
//   ������� �������� ����� OpenGL
// ********************************************************************************

// ���������� ������� "������� ����� ������ ����".
// ��� ������� ��������� ���� ���� �� ������ ����. ���� �����
// ���������, ����������� ������� �� ��������� ��������� ����.
void CALLBACK MouseButtonDown(AUX_EVENTREC* event)
{
	// ����������� ��������� ��������� ���� � ������ ������� ���������, ��������� 
	// � ������ ����� ����� ���� (� ��������� event ��� �������� � ����� ������� 
	// ���������, ��������� � ����� ������� ����� ����)
	int mouse_x = event->data[0];
	int mouse_y = WINDOW_HEIGHT - event->data[1];

	// ������ ���� ���������� ��������� ��������� �������
	pCueBall->SetEnergy(20.0);
	// � ������������� ����������� �������� "�� ��������� ����"
	int cx = 0, cy = 0;
	pCueBall->GetCenter(cx, cy);
	pCueBall->SetDirection(pCueBall->HitAngle(mouse_x - cx, mouse_y - cy));

	// ���� ������� ���� �� ������ ����������� ����
	fBallMoved = true;
}


// ������� ��� ��������� �����: ����������� ����� � �����
void CALLBACK Display()
{
	// ������� ������ � ������ (�� ������������ ��� ��������� �����)
	glClear(GL_COLOR_BUFFER_BIT);

	// ��������� ������ �����
	for (const auto pObj : vOfObjects)
	{
		pObj->Draw();
	}
	auxSwapBuffers();
}


// ������� �������
void CALLBACK Idle()
{
	// ��������� ����� �����������, ������ ���� ���� ���� �� ���� ���������� ���
	if (!fBallMoved)
		return;

	// ���������� ��������� �����
	fBallMoved = false;
	for (auto pObj : vOfObjects)
	{
		pObj->Update();
	}

	Display();		// ����������� �����
	Sleep(25);		// �������� �� 25 ��, ����� ���� �� ��������� ������� ������
}



// ********************************************************************************
//   ������� ������� ���������
// ********************************************************************************

int main()
{
	CreateGlobals();

	// ��������� ������� ����� � OpenGL: �������� ����� RGBA, ������� �����������
	auxInitDisplayMode(AUX_DOUBLE | AUX_RGBA);

	// �������� ���� ��������������� ���������� Glaux ��� ������ ����������� OpenGL.
	// ������ ���� - WINDOW_WIDTH�WINDOW_HEIGHT ��������. ����� ������� ���� ����
	// �������� ��������� ������������ (10, 10).
	auxInitPosition(10, 10, WINDOW_WIDTH, WINDOW_HEIGHT);
	auxInitWindow(L"Billiard model");

	// ��������� ���������� OpenGL
	glClearColor(0.0, 0.0, 0.0, 0.0);		// ���� ������� ����������� (��������� ������)
	glShadeModel(GL_FLAT);					// ���������� ������ ������� ��������� (��� ��������� �������)

	// ����������� �������-����������� ������� - ��� ������ ����� ������� ����
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, MouseButtonDown);

	// ������� ������� � ������������ ����������, ����� ���� �� �������� ��������� 
	// �� ����������, ���� ���  �������. � �� ������� ����������� ��������. 
	auxIdleFunc(Idle);

	// ������� ������� ��������� ����. ��� ������� ����� ���������� ������
	// ���, ����� ����������� ������������ ���� �� ������ (��������, ����� 
	// ���� ����� ���������� �� ���� �����)
	auxMainLoop(Display);

	return 0;
}