#include <bits/stdc++.h>
#include "Kirkpatrick.h"
#define E 0.0000001

using namespace std;

double Kirkpatrick::crossProduct( Point l, Point r) {
    return l.GetX()*r.GetY() - r.GetX()*l.GetY();
}

bool Kirkpatrick::comparePoints(const Point &p1, const Point &p2) {
	return ((p1.GetX()*p2.GetY() - p2.GetX()*p1.GetY() ) > 0) ;
} 


void Kirkpatrick::getExtremePoints(const std::vector<Point> & pointsArray) {
    _UL = pointsArray[0];
    _UR = pointsArray[0];
    _LL = pointsArray[0];  
    _LR = pointsArray[0];

    for (int i=1; i<pointsArray.size(); i++) {
        if(_UL.GetX() > pointsArray[i].GetX())
            _UL = pointsArray[i];
        else if(abs(_UL.GetX() - pointsArray[i].GetX()) < E)
            if(_UL.GetY() < pointsArray[i].GetY())
                _UL = pointsArray[i];

        if(_LL.GetX() > pointsArray[i].GetY())
            _LL = pointsArray[i];
        else if(abs(_LL.GetX() - pointsArray[i].GetX())<E)
            if(_LL.GetY() > pointsArray[i].GetY())
                _LL = pointsArray[i];

        if(_UR.GetX() < pointsArray[i].GetX())
            _UR = pointsArray[i];
        else if(abs(_UR.GetX() - pointsArray[i].GetX()<E))
            if(_UR.GetY() < pointsArray[i].GetY())
                _UR = pointsArray[i];

        if(_LR.GetX() < pointsArray[i].GetX())
            _LR = pointsArray[i];
        else if(abs(_LR.GetX() - pointsArray[i].GetX())<E)
            if(_LR.GetY() > pointsArray[i].GetY())
                _LR = pointsArray[i];
    }
}

void Kirkpatrick::findUpperSupportingLine( Point &pk, Point &pm, vector<Point> S, double alpha) {
    double max_intercept = S[0].GetY() - alpha*S[0].GetX();
    pk = S[0];
    pm = S[0];

    for(int i=0; i<S.size(); i++) {
        double curr_intercept = S[i].GetY() - alpha*S[1].GetX();

        if(curr_intercept > max_intercept) {
            max_intercept = curr_intercept;
            pk = pm = S[i];
        }

        if(abs(curr_intercept - max_intercept)<E) {
            pk = (S[i].GetX() < pk.GetX() ? S[i] : pk) ;
            pm = (S[i].GetX() > pm.GetX() ? S[i] : pm) ; 
        }
    }
}

void Kirkpatrick::upperBridge(Point &pl, Point &pr, vector<Point> S, double med) {
    //step 1 : initialize candidates
    vector<Point> candidate;

    //step 2: base case when only 2 points are there
    if(S.size()==2) {
        if(S[0].GetX() < S[1].GetX()) {
            pl = S[0];
            pr = S[1];
        } else {
            pl = S[1];
            pr = S[0];
        }
        return;
    }

    //step 3: Pair the points arbitarily & make lines
    vector<Line> lines;
    
    for(int i=0; (i+1)<S.size(); i+=2) {
        if(S[i].GetX() > S[i+1].GetX()) {
            swap(S[i], S[i+1]);
        } else if(abs(S[i].GetX() - S[i+1].GetX())<E) {
            Point x = (S[i].GetY() > S[i+1].GetY() ? S[i] : S[i+1]);
            candidate.push_back(x);
        }
        lines.push_back(Line(S[i], S[i+1]));
    }

    if(S.size()%2!=0) {
        candidate.push_back(S[S.size()-1]);
    }
    
    //step 4 : Find the slopes
    double slopes[lines.size()];
    for(int i=0;i<lines.size(); i++) {
        slopes[i] = lines[i].getSlope();
    }


    //step 5: Find the median of slopes
    double med_slope = median(slopes, lines.size());

    //step 6: Categorise the lines into small, equal, large
    vector<Line> SMALL;
    vector<Line> EQUAL;
    vector<Line> LARGE;

    for(int i=0; i<lines.size(); i++) {
        if(slopes[i] < med_slope) {
            SMALL.push_back(lines[i]);
        } else if(abs(slopes[i] - med_slope)<E) {
            EQUAL.push_back(lines[i]);
        } else {
            LARGE.push_back(lines[i]);
        }
    }

    //step 7: Find supporting line
     Point pk, pm;
     findUpperSupportingLine(pk, pm, S, med_slope);

    //step 8, 9, 10: when both are on different sides of median
    if( (pk.GetX() <= med || isequal(pk.GetX(), med) ) && pm.GetX() > med) {
        pl = pk; 
        pr = pm;
        return;   
    } else if(pm.GetX() <= med) {
        for(int i =0; i<SMALL.size(); i++) {
            candidate.push_back(SMALL[i].p1);
            candidate.push_back(SMALL[i].p2);
        }
        for(int i =0; i<EQUAL.size(); i++) {
            candidate.push_back(EQUAL[i].p2);
        }
        for(int i =0; i<LARGE.size(); i++) {
            candidate.push_back(LARGE[i].p2);
        } 

    } else if(pk.GetX() > med) {
        for(int i =0; i<SMALL.size(); i++) {
            candidate.push_back(SMALL[i].p1);
        }
        for(int i =0; i<EQUAL.size(); i++) {
            candidate.push_back(EQUAL[i].p1);
        }
        for(int i =0; i<LARGE.size(); i++) {
            candidate.push_back(LARGE[i].p2);
            candidate.push_back(LARGE[i].p1);
        } 

    }
    
    upperBridge(pl, pr, candidate, med);
}

vector<Point> Kirkpatrick::upperHull(Point pmin, Point pmax, vector<Point> P) {

    vector<Point> hullPoints;

    //step 1: base cases
    //base case 1
    if(pmin.isSame(pmax)) {
        hullPoints.push_back(pmin);
        return hullPoints;
    }

    //base case 2
    if(P.size() == 2) {
        if(P[0].GetX() < P[1].GetX()) {
            hullPoints.push_back(P[0]);
            hullPoints.push_back(P[1]);
        } else {
            hullPoints.push_back(P[1]);
            hullPoints.push_back(P[0]);
        }
        return hullPoints;
    }
    //step 2: finding the median
    double x_coor[P.size()];
    for(int i=0; i<P.size(); i++) {
        x_coor[i] = P[i].GetX();
    } 

    double med = median(x_coor, P.size());

    //step 3: Find upper bridge extreme points
    Point pl, pr;
    upperBridge(pl, pr, P, med);
    //step 4: Find PLeft & PRight
    vector<Point> PLeft, PRight;

    //making vectors
    Point v1(pmin, pl);
    Point v2(pr, pmax);

    for(int i=0; i<P.size(); i++) {
        if(P[i].isSame(pmin) || P[i].isSame(pmax) || P[i].isSame(pl) || P[i].isSame(pr) ) 
            continue;

        Point p1 (pl, P[i]);
        Point p2 (pmax, P[i]);

        if(crossProduct(v1, p1) > 0) PLeft.push_back(P[i]);
        if(crossProduct(v2, p2) > 0) PRight.push_back(P[i]);
    }

    PLeft.push_back(pl);
    if(!pl.isSame(pmin))
        PLeft.push_back(pmin);

    PRight.push_back(pr);
    if(!pr.isSame(pmax))
        PRight.push_back(pmax);

    //step 5: make upper hulls for left & right & merge them
    vector<Point> LUH, RUH;
    LUH = upperHull(pmin, pl, PLeft);
    cout << pr.GetX() << pr.GetY() << pmax.GetX() << pmax.GetY() << endl;
    RUH = upperHull(pr, pmax, PRight);

    for(int i =0; i<PRight.size(); i++)
        LUH.push_back(RUH[i]);

    return LUH;
}

void Kirkpatrick::findLowerSupportingLine( Point &pk, Point &pm, vector<Point> S, double alpha) {
        double min_intercept = S[0].GetY() - alpha*S[0].GetX();
        pk = S[0];
        pm = S[0];

        for(int i=0; i<S.size(); i++) {
            double curr_intercept = S[i].GetY() - alpha*S[1].GetX();

            if(curr_intercept < min_intercept) {
                min_intercept = curr_intercept;
                pk = pm = S[i];
            }

            if(abs(curr_intercept - min_intercept)<E) {
                pk = (S[i].GetX() < pk.GetX() ? S[i] : pk) ;
                pm = (S[i].GetX() > pm.GetX() ? S[i] : pm) ; 
            }
        }
}

void Kirkpatrick::lowerBridge(Point &pl, Point &pr, vector<Point> S, double med) {

    //step 1 : initialize candidates
    vector<Point> candidate;

    //step 2: base case when only 2 points are there
    if(S.size()==2) {
        if(S[0].GetX() < S[1].GetX()) {
            pl = S[0];
            pr = S[1];
        } else {
            pl = S[1];
            pr = S[0];
        }
        return;
    }

    //step 3: Pair the points arbitarily & make lines
    vector<Line> lines;
    for(int i=0; i+1<S.size(); i+=2) {
        if(S[i].GetX() > S[i+1].GetX()) {
            swap(S[i], S[i+1]);
        } else if(abs(S[i].GetX() - S[i+1].GetX())<E) {
            Point x = (S[i].GetY() < S[i+1].GetY() ? S[i] : S[i+1]);
            candidate.push_back(x);
        }
        lines.push_back(Line(S[i], S[i+1]));
    }

    if(S.size()%2!=0) {
       candidate.push_back(S[S.size()-1]);
    }
    //step 4 : Find the slopes
    double slopes[lines.size()];
    for(int i=0;i<lines.size(); i++) {
        slopes[i] = lines[i].getSlope();
    }

    //step 5: Find the median of slopes
    double med_slope = median(slopes, lines.size());

    //step 6: Categorise the lines into small, equal, large
    vector<Line> SMALL;
    vector<Line> EQUAL;
    vector<Line> LARGE;

    for(int i=0; i<lines.size(); i++) {
        if(slopes[i] < med_slope) {
            SMALL.push_back(lines[i]);
        } else if(abs(slopes[i] - med_slope)<E) {
            EQUAL.push_back(lines[i]);
        } else {
            LARGE.push_back(lines[i]);
        }
    }

    //step 7: Find supporting line
    Point pk, pm;
    findLowerSupportingLine(pk, pm, S, med_slope);

    //step 8, 9, 10: when both are on different sides of median
    if(pk.GetX() <= med && pm.GetX() > med) {
        pl = pk; 
        pr = pm;
        return;
    } else if(pm.GetX() <= med || isequal(pm.GetX(), med) ) {
        for(int i =0; i<SMALL.size(); i++) {
            candidate.push_back(SMALL[i].p2);
        }
        for(int i =0; i<EQUAL.size(); i++) {
            candidate.push_back(EQUAL[i].p2);
        }
        for(int i =0; i<LARGE.size(); i++) {
            candidate.push_back(LARGE[i].p1);            
            candidate.push_back(LARGE[i].p2);
        } 
    } else if(pk.GetX() > med) {
        for(int i =0; i<SMALL.size(); i++) {
            candidate.push_back(SMALL[i].p1);
            candidate.push_back(SMALL[i].p2);
        }
        for(int i =0; i<EQUAL.size(); i++) {
            candidate.push_back(EQUAL[i].p1);
        }
        for(int i =0; i<LARGE.size(); i++) {
            candidate.push_back(LARGE[i].p1);
        } 
    }
    lowerBridge(pl, pr, candidate, med);
}

vector<Point> Kirkpatrick::lowerHull(Point pmin, Point pmax, vector<Point> P) {
    vector<Point> hullPoints;

    //step 1: base cases
    //base case 1
    if(pmin.isSame(pmax)) {
        hullPoints.push_back(pmin);
        return hullPoints;
    }

    //base case 2
    if(P.size() == 2) {
        if(P[0].GetX() < P[1].GetX()) {
            hullPoints.push_back(P[0]);
            hullPoints.push_back(P[1]);
        } else {
            hullPoints.push_back(P[1]);
            hullPoints.push_back(P[0]);
        }
        return hullPoints;
    }

    //step 2: finding the median
    double x_coor[P.size()];
    for(int i=0; i<P.size(); i++) {
        x_coor[i] = P[i].GetX();
    } 
    double med = median(x_coor, P.size());

    if(P.size() == 3) {
        vector<Point> points;
        for(Point point : P) {
            if( point.GetX() > med || isequal(point.GetX(), med) ) points.push_back(point);
        }
        return points;
    }

    //step 3: Find upper bridge extreme points
    Point pl, pr;
    lowerBridge(pl, pr, P, med);

    //step 4: Find PLeft & PRight
    vector<Point> PLeft, PRight;

    //making vectors
    Point v1(pmin, pl);
    Point v2(pr, pmax);

    for(int i=0; i<P.size(); i++) {
        if(P[i].isSame(pmin) || P[i].isSame(pmax) || P[i].isSame(pl) || P[i].isSame(pr) ) 
            continue;

        Point p1 (pl, P[i]);
        Point p2 (pmax, P[i]);

        if(crossProduct(v1, p1) < 0) PLeft.push_back(P[i]);
        if(crossProduct(v2, p2) < 0) PRight.push_back(P[i]);
    }

    PLeft.push_back(pl);
    if(!pl.isSame(pmin))
        PLeft.push_back(pmin);

    PRight.push_back(pr);
    if(!pr.isSame(pmax))
        PRight.push_back(pmax);

    //step 5: make upper hulls for left & right & merge them
    vector<Point> LUH, RUH;
    LUH = lowerHull(pmin, pl, PLeft);
    RUH = lowerHull(pr, pmax, PRight);

    for(int i =0; i<PRight.size(); i++)
        LUH.push_back(RUH[i]);

    return LUH;
}

void Kirkpatrick::getConvexHull(const std::vector<Point> & pointsArray, std::vector<Point> & ConvexHull) {
    //step 1: find LL, LR, UL, UR   
    getExtremePoints(pointsArray);
    
    //step 2: make a vector of points for upper hull
    vector<Point> candidate;

    for(Point point : pointsArray) {
        if(!isequal(point.GetX(), _UL.GetX()) && !isequal(point.GetX(), _UR.GetX()) ) {
            candidate.push_back(point);
        }
    }

    candidate.push_back(_UL);
    candidate.push_back(_UR);
    //step 3: Get upper hull
    vector<Point> upper = upperHull(_UL, _UR, candidate);
 

    //step 2: make a vector of points for lower hull
    candidate.pop_back();
    candidate.pop_back();
    
    candidate.push_back(_LL);
    candidate.push_back(_LR);
    //step 3: Get lower hull
    vector<Point> lower = lowerHull(_LL, _LR, candidate);

    int start = lower.size()-1;
    if (upper.back().isSame(lower[start])  )
        start--;
     
     int end = 0;
    if (upper.front().isSame( lower[end] ) )
        end++;

    for(int i=start; i>=end; i--) {
        upper.push_back(lower[i]);
    }    
    
    sort(upper.begin(), upper.end(), comparePoints);
    upper.erase(std::unique( upper.begin(), upper.end() ), upper.end());
    ConvexHull = upper;

}

void Kirkpatrick::run() {
    getConvexHull(_pointsArray, _convexHull);
}