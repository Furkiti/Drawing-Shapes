#include <iostream>

using namespace std;


class Point {

public:
	
	//Variables
	int x, y;


	Point(int x=0, int y=0)
	{
		this->x = x;
		this->y = y;
	}

	Point& operator=(Point poi1)
	{
		this->x = poi1.x;
		this->y = poi1.y;

		return *this;
	}
	
	Point operator+(Point poi1)
	{
		Point temp;
		
		temp.x = this->x + poi1.x;
		temp.y = this->y + poi1.y;
		
		return temp;
	}
	
	friend ostream & operator << (ostream &out, const Point &poi1)
	{
    out << poi1.x << " ";
    out << poi1.y << endl;
    return out;
	}

	Point right(int n)
	{	
		x+=n;		
		return *this;
	}

	Point left(int n)
	{
		x-=n;
		return *this;
	}

	Point up(int n)
	{
		y-=n;
		return *this;
	}

	Point down(int n)
	{
		y+=n;	
		return *this;
	}


};


class Shape {


public:
	
	Point norw, nor, nore, wes, cen, east, souw, sou, soue;

	Point e()
	{
		return east;
	}

	Point w()
	{
		return wes;
	}

	Point n()
	{
		return nor;
	}

	Point s()
	{
		return sou;
	}

	Point ne()
	{
		return nore;
	}

	Point nw()
	{
		return norw;
	}

	Point se()
	{
		return soue;
	}


	Point sw()
	{
		return souw;
	}


	Point c()
	{
		return cen;
	}

};

class Rectangle :public Shape {

public:
	
	Rectangle(Point one, Point two)
	{
		norw = one;
		soue = two;

		imp();
	}

	void imp()
	{
		nore.x = soue.x;
		nore.y = norw.y;
		
		souw.x = norw.x;
		souw.y = soue.y;
		
		nor.x = (norw.x + nore.x)/2;
		nor.y = norw.y;
		
		east.x = nore.x;
		east.y = (nore.y + soue.y)/2;
		
		wes.x = norw.x;
		wes.y = (norw.y + souw.y)/2;
		
		sou.x = (souw.x + soue.x)/2;
		sou.y = souw.y;
		
		cen.x = (norw.x + nore.x)/2;
		cen.y = (norw.y + souw.y)/2;
		
	}

};

class Line :public Shape {

public:
	
	int flag=0;
	Point one, two;

	Line(Point one, Point two)
	{
		this->one = one;
		this->two = two;
	
		imp();
		
	}

	void imp()
	{
		if (one.x <= two.x && one.y >= two.y)
		{
			flag = 1;
			souw = one;
			nore = two;
			
			cen.x = (souw.x + nore.x)/2;
			cen.y = (souw.y + nore.y)/2;
			
			sou = souw;
			soue = souw;
			
			norw = nore;
			nor = nore;
			
		}

		else if(one.x <= two.x && one.y <= two.y)
		{
			flag = 2;
			soue = two;
			norw = one;
			
			cen.x = (soue.x + norw.x)/2;
			cen.y = (soue.y + norw.y)/2;
			
			nor = norw;
			nore = norw;
			
			sou = soue;
			souw = soue;
		
		}

		else if (one.x >= two.x && one.y >= two.y)
		{
			flag = 3;
			
			norw = two;
			soue = one;
			
			cen.x = (soue.x + norw.x)/2;
			cen.y = (soue.y + norw.y)/2;
			
			sou = soue;
			souw = soue;
			
			nor = norw;
			nore = norw;
		}
		else if (one.x >= two.x && one.y <= two.y)
		{
			flag = 4;
			
			nore = one;
			souw = two;
			
			cen.x = (souw.x + nore.x)/2;
			cen.y = (souw.y + nore.y)/2;
		
			norw = nore;
			nor = nore;
			
			sou =souw;
			soue = souw;
		}
	}

};

class Dot :public Shape
{
	public:
		
		Point dotp;
		
		Dot(Point p1){
			
			dotp = p1;
			
			imp();
			
		}
		
		void imp(){
			
			norw = dotp; 
			nor = dotp;
			nore = dotp; 
			wes = dotp; 
			cen = dotp; 
			east = dotp; 
			souw = dotp; 
			sou = dotp;
			soue = dotp;
	
		}

};

class DispWindow {

public:
	
	//Variables
	int x, y;

	char **ary;

	Point curr;
	
	//Constructor
	DispWindow(int n1, int m1)
	{

		x = n1;
		y = m1;

		this->ary = new char*[y];

		for (int i = 0; i < y; ++i)
		{
			ary[i] = new char[x];
		}
		
		//Fill the array
		for (int z = 0; z < y; z++)
		{
			for (int c = 0; c < x; c++)
			{
				ary[z][c] = ' ';
			}

		}

	}

	//Destructor
	~DispWindow()
	{

		for (int i = 0; i < y; ++i)
		{
			delete[] ary[i];
		}
		delete[] ary;
	}

	//Show the array
	void show()
	{
		int i, j;

		for (i = 0; i < y; i++)
		{
			for (j = 0; j < x; j++)
			{
				cout << ary[i][j];
			}
			cout << endl;
		}
				
	}
	
	Point current(){
		return curr;
	}


	void current(Point p)
	{
		curr.x = p.x;
		curr.y = p.y;
	}


	void draw(Rectangle rect)
	{
		int leftupx = rect.norw.x;
		int leftupy = rect.norw.y;

		int leftbottomx = rect.souw.x;
		int leftbottomy = rect.souw.y;
		
		int rightupx = rect.nore.x;
		int rightupy = rect.nore.y;

		int rightbottomx = rect.soue.x;
		int rightbottomy = rect.soue.y;
		
		
		current(rect.soue);
	
			
		for (;leftupx <= rightupx ; leftupx++)
		{
			if(leftupx < DispWindow::x && rightupy < DispWindow::y)
			ary[rightupy][leftupx] = '*';
		}
		
		for (;leftbottomx <= rightbottomx; rightbottomx--)
		{	
			if(rightbottomx<DispWindow::x && rightbottomy <DispWindow::y)
			ary[rightbottomy][rightbottomx] = '*';
		}
	
		for (; leftbottomy >= leftupy ; leftbottomy--)
		{
			if(leftbottomy<DispWindow::x && leftbottomx <DispWindow::y)
			ary[leftbottomy][leftbottomx] = '*';
				
		}

		for (; rightbottomy >= rightupy; rightbottomy--)
		{
			if(rightbottomy<DispWindow::x && rightupx<DispWindow::y)
			ary[rightbottomy][rightupx] = '*';
		}
		
	}
	
	
	void draw(Dot mydot){
		
		if(mydot.dotp.x < DispWindow::x && mydot.dotp.y < DispWindow::y){
			
			ary[mydot.dotp.y][mydot.dotp.x] = '*';
		} 
		
		current(mydot.dotp);
		//curr.x = mydot.dotp.x;
		//curr.y = mydot.dotp.y;
	}


	void draw(Line line)
	{	
		int myflag=0;
		if(line.flag == 1){
			
			
			int holdxs = line.souw.x;
			int holdxb = line.nore.x;
			
			int holdys = line.nore.y;
			int holdyb = line.souw.y;
			
			curr.x = holdxs;
			curr.y = holdys;
			
			
			if(holdxs == holdxb){
				
				for(;holdys <= holdyb;){
					
				if(curr.x < DispWindow::x && curr.y < DispWindow::y )	
				ary[holdys][holdxs] = '*';
			
				holdys++;
				
				myflag=1;	
			   }
			   curr.x = line.souw.x;
			   curr.y =line.nore.y;
		
			}
			
			else if(holdys == holdyb){
				
				for(;holdxs <= holdxb;){
					
				if(curr.x < DispWindow::x && curr.y < DispWindow::y )		
				ary[holdys][holdxs] = '*';
				
				holdxs++;
				
				myflag =2;
				
			   }
			   curr.x = line.nore.x;
				curr.y = line.nore.y;
		
			}
			
			else{
				
				for(;holdxs < holdxb , holdys < holdyb; holdxs++,holdys++){
				
				if(holdxs == holdxb)
				holdxs--;
				
				if(holdys == holdyb)
				holdys--;
				
				if(curr.x < DispWindow::x && curr.y < DispWindow::y )
				ary[holdys][holdxs] = '*';
				
			}
			
			}
			
			if(myflag == 0){
				
				
				if(curr.x < DispWindow::x)
				curr.x = holdxs;
			
				if(curr.y < DispWindow::y)
				curr.y =holdys;
			}
			
			
			
			
		}
		
		else if(line.flag == 2){
			
		
	
			int holdxs = line.norw.x;
			int holdxb = line.soue.x;
			
			int holdys = line.norw.y;
			int holdyb = line.soue.y;
		
			
			if(holdxs == holdxb){
				
				
				for(;holdys < holdyb;holdys++){
					if(curr.x < DispWindow::x && curr.y < DispWindow::y )
						ary[holdys][holdxs] = '*';
				
				}
				
			}
			
			else if(holdys == holdyb){
			
				for(;holdxs < holdxb;holdxs++){
					if(curr.x < DispWindow::x && curr.y < DispWindow::y )
						ary[holdys][holdxs] = '*';
				}
				
			}
			
			else{
				
				for(;holdxs < holdxb && holdys < holdyb ; holdxs++,holdys++){
					
					if(holdxs == holdxb)
					holdxs--;
				
					if(holdys == holdyb)
					holdys--;
					
					if(curr.x < DispWindow::x && curr.y < DispWindow::y )
						ary[holdys][holdxs] = '*';
			}
				
			}
			
			
			if(curr.x < DispWindow::x)
			curr.x = holdxs;
			
			if(curr.y < DispWindow::y)
			curr.y = holdys;
		
			
		}
		
		else if(line.flag == 3){
			
		
			int holdxs = line.norw.x;
			int holdxb = line.soue.x;
			
			int holdys = line.norw.y;
			int holdyb = line.soue.y;
			
			curr.x = holdxs;
			curr.y = holdys;
				
			if(holdxs == holdxb){
				
				for(;holdys < holdyb;holdys++){
					
					if(holdxs == holdxb)
					holdxs--;
				
					if(holdys == holdyb)
					holdys--;
					
					if(curr.x < DispWindow::x && curr.y < DispWindow::y )
						ary[holdys][holdxs] = '*';
				}
				
			}
			
			else if(holdys == holdyb){
				
				
				for(;holdxs < holdxb;holdxs++){
					if(curr.x < DispWindow::x && curr.y < DispWindow::y )
						ary[holdys][holdxs] = '*';
				}
						
			}
			
			else{
				
				
				if(holdxs == holdxb)
				holdxs--;
				
				if(holdys == holdyb)
				holdys--;
				
				for(;holdxs < holdxb && holdys < holdyb ; holdxs++,holdys++){
				ary[holdys][holdxs] = '*';
			}	
			
			}
			
			if(curr.x < DispWindow::x)
			curr.x = line.norw.x;
			
			if(curr.y < DispWindow::y)
			curr.y = line.norw.y;
			
			
		}
		
		else if(line.flag == 4){
				
		
			int holdxs = line.souw.x;
			int holdxb = line.nore.x;
			
			int holdys = line.nore.y;
			int holdyb = line.souw.y;
			
			curr.x = holdxs;
			curr.y = holdys;
			
			
			
		
			if(holdxs == holdxb){
				
				for(;holdys < holdyb;holdys++){
					
					if(curr.x < DispWindow::x && curr.y < DispWindow::y )
						ary[holdys][holdxs] = '*';
				}
				
			}
			
			else if(holdys == holdyb){
				
				
				for(;holdxs < holdxb;holdxs++){
					if(curr.x < DispWindow::x && curr.y < DispWindow::y )
						ary[holdys][holdxs] = '*';
				}
						
			}
			
			else{
			
				for(;holdxs < holdxb && holdys < holdyb ; holdxb--,holdys++){
				ary[holdys][holdxb] = '*';
			}
			}
					
		}
					
		}
	

};
