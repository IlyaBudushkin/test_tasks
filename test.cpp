#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


   

struct point
{   
    double x;
    double y;
};
 struct point_length
 {
    double lenghtToCentre;
    int number;
 };

bool compare_points(point_length l,point_length l1)
{
    return (l.lenghtToCentre<l1.lenghtToCentre);
};




vector <point> pointers( vector <point> points,  int k,  int n)
    {
        vector <point_length> lengths;
        vector <point> p;
        for(int i = 0; i < n; i ++)
        {
            point_length l;

            double x_leng, y_leng;
            x_leng=points.at(i).x;
            y_leng=points.at(i).y;

            l.lenghtToCentre = sqrt(pow(x_leng,2)+pow(y_leng,2));
            l.number = i;

           lengths.push_back(l);
        }
        
        sort(lengths.begin(),lengths.end(),compare_points);
        for(int i = 0; i < k ;i ++)
        {
            p.push_back(points.at(lengths.at(i).number));
        }
        
        return p;
    };


int main()
{  
    vector <point> points,out;
    int n;
    cout << "Enter amount of elements" << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        point p;
        cout << i+1 << " Element: x="; 
        cin >> p.x;
        cout << " y=";
        cin >> p.y;
        points.push_back(p);
    }

    int k;
    cout << "Enter amount closest to the center elements" << endl;
    cin >> k;

    out=pointers(points,k,n);


    for(int i = 0; i < k; i++)
    {
        cout<< i+1 << " Closest element: x=" <<out.at(i).x;
        cout<< " y=" <<out.at(i).y << endl;
    }

    
    return 0;
};
