#include <vector>
#include <iostream>
using namespace std;


struct Point {
	int x;
	int y;
public:
	Point(int xx, int yy) : x(xx), y(yy) {}

	//t10
	bool operator == (Point p)
	{
		return ((x == p.x) && (y == p.y));
		
	}
	//plussaa pointin toiseen pointtiin, katsoo, ettei plussaus laita lukuja yli sadan. Oletin ettei plussata miinuslukuja,
	//mutta jos niitäkin plussattaisiin, lisäisin siihen myös samanlaisen alarajan kuin miinuksessa on
	void operator + (const Point& p)
	{
		if (this->x + p.x <= 100 && this->y + p.y <= 100)
		{
			this->x += p.x;
			this->y += p.y;
		}
		else
		{
			cout << "ainakin toinen luvuista olisi mennyt yli sadan" << endl;
		}
	}
	//samalla periaatteella kuin plussassa, katsotaan ettei luku mene alle 0
	void operator - (const Point& p)
	{
		if (this->x - p.x >= 0 && this -> y - p.y >= 0)
		{
			this->x -= p.x;
			this->y -= p.y;
		}
		else
		{
			cout << "ainakin toinen arvoista olisi mennyt alle nollan"<<endl;
		}
	}
    
};
//t9 tekee halutun määrän Pointteja ja palauttaa ne vectorissa
vector <Point> make_point(int lkm)
{
	int randomx;
	int randomy;
	vector<Point> pointit;

	for (int i = 0; i < lkm; i++)
	{

		randomx = rand() % 101;
		randomy = rand() % 101;
		pointit.push_back(Point(randomx, randomy));
	}
	return pointit;



}

void t9()
{
	//30 pointtia v vectoriin ja niiden tulostus
	vector<Point> v = make_point(30);
	int i = 0;
	for (Point p : v)
	{
		cout << "x=" << p.x << " y=" << p.y<<endl;
		
		i++;
	}
	cout << i << " Pointtia vectorissa";
}
//kokeilua plussauksien ja miinuksien kanssa
void t10()
{
	Point k = Point(1, 100);
	Point k1 = Point(1, 1);
	Point k2 = Point(1, 1);
	cout << "(" << k1.x << "," << k1.y << ")+(" << k.x << "," << k.y << ")= ";
	k1 + k;	
	cout <<"epaonnistuneen plussauksen jlk: "<< k1.x<<":"<<k1.y<<endl;

	cout << "(" << k1.x << "," << k1.y << ")-(" << k.x << "," << k.y << ")= ";
	k1 - k;
	cout <<"epaonnistuneen miinuksen jlk: "<< k1.x << ":" << k1.y << endl;

	cout << "(" << k1.x << "," << k1.y << ")+("<< k2.x << "," << k2.y << ")= ";
	k1 + k2;
	cout << k1.x << ":" << k1.y << endl;
	cout << "(" << k1.x << "," << k1.y << ")-(" << k2.x << "," << k2.y << ")= ";
	k1 - k2;
	cout << k1.x << ":" << k1.y << endl;
	//onko arvot yhtä suuret
	cout << "onko(" << k1.x << "," << k1.y << ") yhta suuri kuin (" << k2.x << "," << k2.y << ") =" << (k1 == k2)<<endl;
	k1 + k2;
	cout <<"onko(" <<k1.x<<","<<k1.y<<") yhta suuri kuin ("<<k2.x <<","<<k2.y << ") ="<<(k1 == k2);
	

}


